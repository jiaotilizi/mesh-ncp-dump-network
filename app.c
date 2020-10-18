/* standard library headers */
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

/* BG stack headers */
#include "bg_types.h"
#include "gecko_bglib.h"

/* Own header */
#include "app.h"
#include "dump.h"
#include "support.h"
#include "common.h"
#include "mesh_generic_model_capi_types.h"

#include "parser.tab.h"
#include <string.h>
#include "scanner.h"
#include "parser.h"

YY_BUFFER_STATE yy_scan_string ( const char *yy_str  );

int yyparse(void);

#define die(X) die_helper(X,__FILE__,__LINE__)
void die_helper(const char *message, char*file, int line) {
  fprintf(stderr,"%s:%d: %s\n",file,line,message);
  exit(1);
}

static char *hex(uint8 len, uint8_t *in) {
  static char out[4][256];
  static uint8 index;
  index &= 3;
  for(int i = 0; i < len; i++) sprintf(&out[index][i<<1],"%02x",in[i]);
  return &out[index++][0];
}

// App booted flag
static bool appBooted = false;
static struct {
  uint16 server, element, flags, vendor;
  uint8 tid, value, publish, health, scan;
  uint16 timeout;
  struct timeval start;
  uint8 *network_key, network_id, dcd_page, *device_uuid, *device_key;
} config = {
	    .server = 0,
	    .element = 0,
	    .flags = 0,
	    .tid = 0,
	    .value = 0,
	    .timeout = 0,
	    .publish = 0,
	    .health = 0,
	    .vendor = 0x02ff,
	    .network_key = NULL,
	    .device_uuid = NULL,
	    .device_key = NULL,
};

struct unprov_nodes {
  uint16 oob_capabilities;
  uint8 bearer;
  bd_addr address;
  uint8 address_type;
  uint8 uuid[16];
  struct unprov_nodes *next;
} *unprov_nodes = NULL;

void add_unprovisioned_node(struct gecko_msg_mesh_prov_unprov_beacon_evt_t *in) {
  if(in->uuid.len != 16) {
    printf("bad uuid data\n");
    return;
  }
  struct unprov_nodes *p = malloc(sizeof(struct unprov_nodes));
  p-> oob_capabilities = in->oob_capabilities;
  p->bearer = in->bearer;
  memcpy(&p->address.addr[0],&in->address.addr[0],6);
  p->address_type = in->address_type;
  memcpy(&p->uuid,&in->uuid.data[0],in->uuid.len);
  p->next = unprov_nodes;
  unprov_nodes = p;
}

int seen_unprovisioned_node(struct gecko_msg_mesh_prov_unprov_beacon_evt_t *in) {
  if(in->uuid.len != 16) return 0;
  for(struct unprov_nodes *p = unprov_nodes; p; p = p->next) {
    if(memcmp(&p->uuid,&in->uuid.data[0],16)) continue;
    if(p->bearer != in->bearer) continue;
    return 1;
  }
  return 0;
}

const char *render_binary(uint8*p) {
  static char buf[33];
  for(int i = 0; i < 16; i++) sprintf(&buf[i<<1],"%02x",p[i]);
  return buf;
}

void parse_binary(uint8*data,const char*arg) {
  char buf[3];
  int iv;
  buf[2] = 0;
  printf("arg: %s\n",arg);
  for(int i = 0; i < 16; i++) {
    memcpy(&buf,&arg[i<<1],2);
    printf("buf: %s\n",buf);
    sscanf(buf,"%x",&iv);
    printf("%02x",iv);
    data[i] = iv;
  }
}

const char *getAppOptions(void) {
  return "hp:us<server>e<element-index>t<tid>f<flags>v<value>c<vendor>w<wait-seconds>n<network-key>d<dcd-page>x<device-uuid>y<device-key>";
}

void appOption(int option, const char *arg) {
  int iv;
  switch(option) {
  case 'd':
    sscanf(arg,"%i",&iv);
    config.dcd_page = iv;
    break;
  case 's':
    sscanf(arg,"%i",&iv);
    config.server = iv;
    break;
  case 'e':
    sscanf(arg,"%i",&iv);
    config.element = iv;
    break;
  case 't':
    sscanf(arg,"%i",&iv);
    config.tid = iv;
    break;
  case 'v':
    sscanf(arg,"%i",&iv);
    config.value = iv;
    break;
  case 'f':
    sscanf(arg,"%i",&iv);
    config.flags = iv;
    break;
  case 'c':
    sscanf(arg,"%i",&iv);
    config.vendor = iv;
    break;
  case 'x':
    if(strlen(arg) != 32) {
      printf("bad device-uuid: %s\n",arg);
      exit(1);
    }
    config.device_uuid= malloc(16);
    parse_binary(config.device_uuid,arg);
    break;    
  case 'y':
    if(strlen(arg) != 32) {
      printf("bad device-key: %s\n",arg);
      exit(1);
    }
    config.device_key = malloc(16);
    parse_binary(config.device_key,arg);
    break;    
  case 'n':
    if(strlen(arg) != 32) {
      printf("bad network-key: %s\n",arg);
      exit(1);
    }
    config.network_key = malloc(16);
    parse_binary(config.network_key,arg);
    break;    
  case 'p':
    if(strlen(arg) != 32) {
      printf("uuid bad: %s\n",arg);
      exit(1);
    }
    unprov_nodes = malloc(sizeof(struct unprov_nodes));
    parse_binary(&unprov_nodes->uuid[0],arg);
    break;
  case 'h':
    config.health = 1;
    break;
  case 'u':
    config.scan = 1;
    break;
  case 'w':
    gettimeofday(&config.start,NULL);
    config.timeout = atoi(arg);
    break;
  default:
    fprintf(stderr,"Unhandled option '-%c'\n",option);
    exit(1);
  }
}

void appInit(int argc, char *const*argv, int index) {
  int arglen[argc];
  int len = 0;
  for(int i = index; i < argc; i++) {
    arglen[i] = strlen(argv[i]);
    len += arglen[i];
  }
  len += argc - index;
  char *buf = malloc(len);
  len = 0;
  for(int i = index; i < argc; i++) {
    len += sprintf(&buf[len],"%s%s",(i>1)?" ":"",argv[i]);
  }
  yy_scan_string(buf);
  int rc = yyparse();
  if(rc || commands.abort) exit(1);
}

void list_nodes(void) {
  for(struct unprov_nodes *p = unprov_nodes; p; p = p->next) {
    printf("UUID: %s\n",render_binary(&p->uuid[0]));
  }
}

struct model {
  uint16 vendor;
  uint16 id;
  uint16 num_bindings, num_subs;
  uint16 *bindings, *subs;
  uint8 no_sub_support;
};

struct element {
  uint16 loc;
  uint8 num_sig, num_vendor, num_models;
  struct model *models;
};

struct heartbeat_pub {
  uint16 destination_address, netkey_index, features;
  uint8 count_log, period_log, ttl;
};

struct node {
  uint16 address, cid, pid, vid, crpl, features;
  struct element *elements;
  uint8 num_elements, default_ttl, beacon, identity, friend,
    gatt_proxy, relay, transmit_count, retransmit_count;
  uint16 transmit_interval_ms, retransmit_interval_ms;
  struct heartbeat_pub heartbeat_pub;
  struct node *next;
} *nodes = NULL;

struct handle_reference {
  uint32 handle;
  struct node *node;
  uint8 element;
  uint16 index;
  struct handle_reference *next;
} *handle_references = NULL;

struct handle_reference *add_handle_reference(uint32 handle, struct node *node) {
  printf("add_handle_reference(uint32 handle: %d, struct node *node: .address:%04x)\n",handle,node->address);
  struct handle_reference *n = malloc(sizeof(struct handle_reference));
  n->handle = handle;
  n->node = node;
  n->next = handle_references;
  handle_references = n;
  return n;
}

struct handle_reference * add_handle_reference_model(uint32 handle, struct node *node, uint8 element, int index) {
  printf("add_handle_reference_model(element: %d, index: %d)\n",element,index);
  struct handle_reference *n = add_handle_reference(handle,node);
  n->element = element;
  n->index = index;
  return n;
}

struct handle_reference *find_handle_reference(const uint32 handle) {
  for(struct handle_reference *p = handle_references; p; p = p->next) {
    if(handle == p->handle) {
      return p;
    }
  }
  fprintf(stderr,"find_handle_reference(const uint32 handle: %d) did not find\n",handle);
  return NULL;
}

void add_node(uint16 address, uint8 num_elements, struct gecko_msg_mesh_config_client_get_dcd_rsp_t *resp) {
  if(resp->result) return;
  struct node *n = malloc(sizeof(struct node));
  n->address = address;
  n->num_elements = num_elements;
  n->elements = malloc(num_elements*sizeof(struct element));
  memset(n->elements,0,num_elements*sizeof(struct element));
  n->next = nodes;
  nodes = n;
  add_handle_reference(resp->handle,n);
}

char *model_name(uint16 id) {
  switch(id) {
  case 0x0000:
    return "Configuration Server";
  case 0x0001:
    return "Configuration Client";
  case 0x0002:
    return "Health Server";
  case 0x0003:
    return "Health Client";
  case 0x1000:
    return "Generic OnOff Server";
  case 0x1001:
    return "Generic OnOff Client";
  case 0x1002:
    return "Generic Level Server";
  case 0x1003:
    return "Generic Level Client";
  case 0x1004:
    return "Generic Time Server";
  case 0x1005:
    return "Generic Time Client";
  case 0x1006:
    return "Generic Power OnOff Server";
  case 0x1007:
    return "Generic Power OnOff Setup Server";
  case 0x1008:
    return "Generic Power OnOff Client";
  case 0x1009:
    return "Generic Power Level Server";
  case 0x100a:
    return "Generic Power Level Setup Server";
  case 0x100b:
    return "Generic Power Level Client";
  case 0x100c:
    return "Generic Battery Server";
  case 0x100d:
    return "Generic Battery Client";
  case 0x100e:
    return "Generic Location Server";
  case 0x100f:
    return "Generic Location Setup Server";
  case 0x1010:
    return "Generic Location Client";
  case 0x1011:
    return "Generic Admin Property Server";
  case 0x1012:
    return "Generic Manufacturer Property Server";
  case 0x1013:
    return "Generic User Property Server";
  case 0x1014:
    return "Generic Client Property Server";
  case 0x1015:
    return "Generic Property Client";
  case 0x1203:
    return "Scene Server";
  case 0x1204:
    return "Scene Setup Server";
  case 0x1300:
    return "Light Lightness Server";
  case 0x1301:
    return "Light Lightness Setup Server";
  case 0x1303:
    return "Light Lightness Setup Server";
  case 0x1304:
    return "Light CTL Setup Server";
  case 0x1306:
    return "Light CTL Temperature Server";
  case 0x130f:
    return "Light LC Server";
  case 0x1310:
    return "Light LC Setup Server";
  }
  return "unknown";
}

const char *feature_str(uint8 value) {
  static char buf[64];
  switch(value) {
  case 0: return "disabled";
  case 1: return "enabled";
  case 2: return "not supported";
  }
  sprintf(buf,"ILLEGAL VALUE %d",value);
  return buf;
}

void show_node(struct node *node) {
  printf("Node:\n\tAddress: %04x\n",node->address);
  printf("\tCID: %04x\n",node->cid);
  printf("\tPID: %04x\n",node->pid);
  printf("\tVID: %04x\n",node->vid);
  printf("\tCRPL: %04x\n",node->crpl);
  printf("\tFeatures:%s%s%s%s\n",
	 (node->features&1)?" Relay":"",
	 (node->features&2)?" Proxy":"",
	 (node->features&4)?" Friend":"",
	 (node->features&8)?" Low-power":"");
  printf("\tDefault TTL: %d\n",node->default_ttl);
  printf("\tNode is%s broadcasting secure network beacons\n",(node->beacon)?"":" not");
  printf("\tNode identity advertising is %s\n",feature_str(node->identity));
  printf("\tFriend feature is %s\n",feature_str(node->friend));
  printf("\tGATT proxy feature is %s\n",feature_str(node->gatt_proxy));
  printf("\tRelay feature is %s",feature_str(node->relay));
  if(1==node->relay) {
    printf(", Retransmit count: %d", node->retransmit_count);
    if(node->retransmit_count > 1) printf("interval: %d ms",10*node->retransmit_interval_ms);
  }
  printf("\n");
  printf("\tNetwork transmit count: %d",node->transmit_count);
    if(node->transmit_count > 1) printf("interval: %d ms",10*node->transmit_interval_ms);
  printf("\n");
  for(int i = 0; i < node->num_elements; i++) {
    printf("\tElement %d, loc: %d:\n",i,node->elements[i].loc);
    for(int j = 0; j < node->elements[i].num_models; j++) {
      struct model *m = &node->elements[i].models[j];
      if(0xffff == m->vendor) {
	printf("\t\tSIG model %04x %s:",m->id,model_name(m->id));
      } else {
	printf("\t\tVendor %04x model %04x\n",m->vendor,m->id);
      }
      if(m->num_bindings) {
	printf(", bound to appkey %s",(m->num_bindings == 1)?"index":"indices");
	for(int j = 0; j < m->num_bindings; j++) printf(" %d",m->bindings[j]);
      }
      if(m->num_subs) {
	printf(", subscribed to address%s",(m->num_subs == 1)?"":"es");
	for(int j = 0; j < m->num_subs; j++) printf(" %04x",m->subs[j]);
      }
      if(m->no_sub_support) printf(" no subs support");
      printf("\n");
    }
  }
}

void show_dcd(uint8 page, uint8 len, uint8*data, uint32 handle) {
  struct __attribute__((__packed__)) dcd0 {
    uint16 cid,pid,vid,crpl,features;
  } *pd;
  struct __attribute__((__packed__)) elements {
    uint16 loc;
    uint8 nums, numv;
    uint16 sigs[];
  } *pe;
  uint8 num_elements = 0;
  struct node *n = find_handle_reference(handle)->node;
  switch(page) {
  case 0:
    pd = (struct dcd0*)data;
    n->cid = pd->cid;
    n->pid = pd->pid;
    n->vid = pd->vid;
    n->crpl = pd->crpl;
    n->features = pd->features;
    for(
	pe = (struct elements*)(data + sizeof(struct dcd0));
	pe < (struct elements*)(data+len);
	pe = (struct elements*)((void*)pe + 4 + 2*pe->nums + 4*pe->numv)
	) {
      if(num_elements == n->num_elements) {
	fprintf(stderr,"Error, too many elements reported, initialized as %d elements",n->num_elements);
	exit(1);
      }
      n->elements[num_elements].loc = pe->loc;
      n->elements[num_elements].num_sig = pe->nums;
      n->elements[num_elements].num_vendor = pe->numv;
      n->elements[num_elements].num_models = pe->nums + pe->numv;
      n->elements[num_elements].models = malloc((pe->nums+pe->numv)*sizeof(struct model));
      printf("\tLoc: %04x\n",pe->loc);
      printf("\t%d SIG Model IDs\n",pe->nums);
      printf("\t%d Vendor Model IDs\n",pe->numv);
      printf("\t\tSIG Models:");
      for(int i = 0; i < pe->nums; i++) {
	uint16 id = ((uint16*)&pe->sigs[0])[i];
	printf(" %04x",id);
	n->elements[num_elements].models[i].vendor = 0xffff;
	n->elements[num_elements].models[i].id = id;
	n->elements[num_elements].models[i].num_bindings = 0;
	n->elements[num_elements].models[i].bindings = NULL;
      }
      printf("\n");
      num_elements++;
    }
    break;
  default:
    printf("DCD Page %d not handled\n",page);
    break;
  }
  return;
}

void register_list_netkeys(struct node *n,struct gecko_msg_mesh_config_client_list_netkeys_rsp_t *resp) {
  if(resp->result) {
    return;
  }
  add_handle_reference(resp->handle, n);
}

void register_list_appkeys(struct node *n, struct gecko_msg_mesh_config_client_list_appkeys_rsp_t *resp) {
  if(resp->result) {
    return;
  }
  add_handle_reference(resp->handle, n);
}

void register_list_bindings(struct node *n, uint8 element, uint8 index,
			    struct gecko_msg_mesh_config_client_list_bindings_rsp_t *resp) {
  if(resp->result) {
    return;
  }
  add_handle_reference_model(resp->handle, n, element, index);
}
			    
void register_list_subs(struct node *n, uint8 element, uint8 index,
			struct gecko_msg_mesh_config_client_list_subs_rsp_t *resp) {
  if(resp->result) {
    return;
  }
  add_handle_reference_model(resp->handle, n, element, index);
}

void get_default_ttl(struct node *node) {
  struct gecko_msg_mesh_config_client_get_default_ttl_rsp_t *resp;
  resp = gecko_cmd_mesh_config_client_get_default_ttl(0, node->address);
  if(resp->result) die("gecko_cmd_mesh_config_client_get_default_ttl");
  add_handle_reference(resp->handle,node);
}

void get_beacon(struct node *node) {
  struct gecko_msg_mesh_config_client_get_beacon_rsp_t *resp;
  resp= gecko_cmd_mesh_config_client_get_beacon(0, node->address);
  if(resp->result) die(__PRETTY_FUNCTION__);
  add_handle_reference(resp->handle,node);
}

void get_identity(struct node *node) {
  struct gecko_msg_mesh_config_client_get_identity_rsp_t *resp;
  resp = gecko_cmd_mesh_config_client_get_identity(0, node->address, 0);
  if(resp->result) die(__PRETTY_FUNCTION__);
  add_handle_reference(resp->handle,node);
}

void get_friend(struct node *node) {
  struct gecko_msg_mesh_config_client_get_friend_rsp_t *resp;
  resp = gecko_cmd_mesh_config_client_get_friend(0, node->address);
  if(resp->result) die(__PRETTY_FUNCTION__);
  add_handle_reference(resp->handle,node);
}

void get_gatt_proxy(struct node *node) {
  struct gecko_msg_mesh_config_client_get_gatt_proxy_rsp_t *resp;
  resp = gecko_cmd_mesh_config_client_get_gatt_proxy(0, node->address);
  if(resp->result) die(__PRETTY_FUNCTION__);
  add_handle_reference(resp->handle,node);
}

void get_relay(struct node *node) {
  struct gecko_msg_mesh_config_client_get_relay_rsp_t *resp;
  resp = gecko_cmd_mesh_config_client_get_relay(0, node->address);
  if(resp->result) die(__PRETTY_FUNCTION__);
  add_handle_reference(resp->handle,node);
}

void get_network_transmit(struct node *node) {
  struct gecko_msg_mesh_config_client_get_network_transmit_rsp_t *resp;
  resp = gecko_cmd_mesh_config_client_get_network_transmit(0, node->address);
  if(resp->result) die(__PRETTY_FUNCTION__);
  add_handle_reference(resp->handle,node);
}

void get_heartbeat_pub(struct node *node) {
  struct gecko_msg_mesh_config_client_get_heartbeat_pub_rsp_t *resp;
  resp = gecko_cmd_mesh_config_client_get_heartbeat_pub(0, node->address);
  if(resp->result) die(__PRETTY_FUNCTION__);
  add_handle_reference(resp->handle,node);
}

void got_default_ttl(struct handle_reference *hr, uint8 default_ttl) {
  hr->node->default_ttl = default_ttl;
  get_beacon(hr->node);
}

void got_beacon(struct handle_reference *hr, uint8 beacon) {
  hr->node->beacon = beacon;
  get_identity(hr->node);
}

void got_identity(struct handle_reference *hr, uint8 identity) {
  hr->node->identity = identity;
  get_friend(hr->node);
}

void got_friend(struct handle_reference *hr, uint8 friend) {
  hr->node->friend = friend;
  get_gatt_proxy(hr->node);
}

void got_gatt_proxy(struct handle_reference *hr, uint8 gatt_proxy) {
  hr->node->gatt_proxy = gatt_proxy;
  get_relay(hr->node);
}

void got_relay(struct handle_reference *hr, uint8 relay, uint8 retransmit_count, uint16 retransmit_interval_ms) {
  hr->node->relay = relay;
  hr->node->retransmit_count = retransmit_count;
  hr->node->retransmit_interval_ms = retransmit_interval_ms;
  get_network_transmit(hr->node);
}

void got_network_transmit(struct handle_reference *hr, uint8 transmit_count, uint16 transmit_interval_ms) {
  hr->node->transmit_count = transmit_count;
  hr->node->transmit_interval_ms = transmit_interval_ms;
  get_heartbeat_pub(hr->node);
}

void got_heartbeat_pub(struct handle_reference *hr,
		       uint16 destination_address,
		       uint16 netkey_index,
		       uint8 count_log,
		       uint8 period_log,
		       uint8 ttl,
		       uint16 features) {
  hr->node->heartbeat_pub.destination_address = destination_address;
  hr->node->heartbeat_pub.netkey_index = netkey_index;
  hr->node->heartbeat_pub.count_log = count_log;
  hr->node->heartbeat_pub.period_log = period_log;
  hr->node->heartbeat_pub.ttl = ttl;
  hr->node->heartbeat_pub.features = features;
  //get_heartbeat_sub(hr->node);
}

int update_reference(struct handle_reference *hr) {
  printf("update_reference: element: %d (%d), index: %d (%d)\n",hr->element,hr->node->num_elements,hr->index,hr->node->elements[hr->element].num_models);
  hr->index++;
  while(hr->element < hr->node->num_elements) {
    if(hr->index < hr->node->elements[hr->element].num_models) return 0;
    hr->element++;
    hr->index = 0;
  }
  printf("update_reference fails\n");
  return 1;
}

struct model *get_model(const struct handle_reference *hr) {
  if(hr->element >= hr->node->num_elements) die("bad element");
  if(hr->index >= hr->node->elements[hr->element].num_models) die("bad model index");
  return &hr->node->elements[hr->element].models[hr->index];
}

void got_bindings(struct gecko_msg_mesh_config_client_bindings_list_evt_t *evt) {
  const struct handle_reference *hr = find_handle_reference(evt->handle);
  struct model *model = get_model(hr);
  if(model->num_bindings || model->bindings) die("Binding already set\n");
  model->num_bindings = evt->appkey_indices.len >> 1;
  model->bindings = malloc(evt->appkey_indices.len);
  memcpy(model->bindings,&evt->appkey_indices.data[0],evt->appkey_indices.len);
}

void got_subs(struct gecko_msg_mesh_config_client_subs_list_evt_t *evt) {
  const struct handle_reference *hr = find_handle_reference(evt->handle);
  struct model *model = get_model(hr);
  if(model->num_subs || model->subs) die("Binding already set\n");
  model->num_subs = evt->addresses.len >> 1;
  model->subs = malloc(evt->addresses.len);
  memcpy(model->subs,&evt->addresses.data[0],evt->addresses.len);
}

void do_next(uint32 id, uint16 result, uint32 handle) {
  struct handle_reference *hr = find_handle_reference(handle);
  struct node *n = hr->node;

  switch(result) {
  case 0:
    break;
  case 0x0e08: // Model does not support subscription
    get_model(hr)->no_sub_support = 1;
    break;
  case 0x0e02: // ??
    break;
  default:
    printf("Bad result %04x\n",result);
    exit(1);
  }

  switch (id) {
  case gecko_evt_mesh_config_client_dcd_data_end_id:
    //gecko_cmd_mesh_config_client_add_appkey(0, config.server, 0, 0);
    register_list_netkeys(n,gecko_cmd_mesh_config_client_list_netkeys(0, n->address));
    break;
  case gecko_evt_mesh_config_client_netkey_list_end_id:
    register_list_appkeys(n,gecko_cmd_mesh_config_client_list_appkeys(0, n->address, 0));
    break;
  case gecko_evt_mesh_config_client_appkey_list_end_id:
    register_list_bindings(n,
			   0, // element
			   0, //index
			   gecko_cmd_mesh_config_client_list_bindings(0,
								      n->address,
								      0, // element
								      n->elements[0].models[0].vendor,
								      n->elements[0].models[0].id));
    break;
  case gecko_evt_mesh_config_client_bindings_list_end_id:
    if(!update_reference(hr)) {
      register_list_bindings(n,
			     hr->element,
			     hr->index,
			     gecko_cmd_mesh_config_client_list_bindings(0,
									n->address,
									hr->element,
									n->elements[hr->element].models[hr->index].vendor,
									n->elements[hr->element].models[hr->index].id));
    } else {
      register_list_subs(n,
			 0, // element
			 0, // index
			 gecko_cmd_mesh_config_client_list_subs(0,
								n->address,
								0,
								n->elements[0].models[0].vendor,
								n->elements[0].models[0].id));
    }
    break;
  case gecko_evt_mesh_config_client_subs_list_end_id:
    if(!update_reference(hr)) {
      register_list_subs(n,
			 hr->element,
			 hr->index,
			 gecko_cmd_mesh_config_client_list_subs(0,
								n->address,
								hr->element,
								n->elements[hr->element].models[hr->index].vendor,
								n->elements[hr->element].models[hr->index].id));
    } else {
      get_default_ttl(n);
    }
    break;
  //gecko_cmd_mesh_config_client_list_subs(0, config.server, 0, 0xffff, 0x1000); 
  }
}

void process_bindings(void) {
  struct gecko_msg_mesh_config_client_bind_model_rsp_t *resp;
  struct binding *b = commands.bindings;
  commands.bindings = b->next;
  resp = gecko_cmd_mesh_config_client_bind_model(0, b->server_address, b->element_index, b->appkey_index, b->vendor_id, b->model_id);
}


uint16 my_address = 0;

/***********************************************************************************************//**
 *  \brief  Event handler function.
 *  \param[in] evt Event pointer.
 **************************************************************************************************/
void appHandleEvents(struct gecko_cmd_packet *evt)
{
  if (NULL == evt) {
    if(config.timeout) {
      struct timeval now, delta;
      gettimeofday(&now,NULL);
      timersub(&now,&config.start,&delta);
      if(delta.tv_sec > config.timeout) {
	gecko_cmd_dfu_reset(0);
	if(commands.get.list_unprovisioned) list_nodes();
	else {
	  for(struct node *node = nodes; node; node = node->next) {
	    show_node(node);
	  }
	}
	exit(0);
      }
    }
    return;
  }
#define DEBUG
  // Do not handle any events until system is booted up properly.
  if ((BGLIB_MSG_ID(evt->header) != gecko_evt_system_boot_id)
      && !appBooted) {
#if defined(DEBUG)
    printf("Event: 0x%04x\n", BGLIB_MSG_ID(evt->header));
#endif
    millisleep(50);
    return;
  }

  /* Handle events */
#ifdef DUMP
  switch (BGLIB_MSG_ID(evt->header)) {
  case gecko_evt_mesh_prov_unprov_beacon_id:
  case gecko_evt_le_gap_adv_timeout_id:
    break;
  default:
    dump_event(evt);
  }
#endif
  switch (BGLIB_MSG_ID(evt->header)) {
  case gecko_evt_system_boot_id: /*********************************************************************************** system_boot **/
#define ED evt->data.evt_system_boot
    appBooted = true;
    printf("Boot\n");
    //    if(unprov_nodes || config.server) {
      gecko_cmd_mesh_prov_init();
      //} else {
      //gecko_cmd_mesh_node_init();
      //}
    break;
#undef ED

  case gecko_evt_mesh_prov_initialized_id:
#define ED evt->data.evt_mesh_prov_initialized
    my_address = ED.address;
#undef ED
    if(commands.get_devkey) {
      struct gecko_msg_mesh_test_prov_get_device_key_rsp_t *resp;
      resp = gecko_cmd_mesh_test_prov_get_device_key(commands.get_devkey->address);
      if(resp->result) exit(1);
      printf("address: %04x, devkey: %s\n",commands.get_devkey->address,hex(16,&resp->device_key));
      exit(0);
    }
    if(commands.get.factory_reset) {
      gecko_cmd_flash_ps_erase_all();
      commands.get.factory_reset = 0;
      gecko_cmd_dfu_reset(0);
      break;
    }
    if(commands.bindings) {
      process_bindings();
    }
    //   break;
    if(commands.provisioner_address) {
      gecko_cmd_mesh_prov_initialize_network(commands.provisioner_address,commands.ivi);
      commands.provisioner_address = 0;
      gecko_cmd_dfu_reset(0);
      break;
    }
    if(commands.network_keys) {
      for(struct network_keys *p = commands.network_keys; p; p = p->next) {
	config.network_id = gecko_cmd_mesh_prov_create_network((p->key)?16:0,(uint8*)(p->key))->network_id;
      }
      commands.network_keys = NULL;
      gecko_cmd_dfu_reset(0);
      break;
    }
    if(commands.ddb_nodes) {
      for(struct ddb_node *p = commands.ddb_nodes; p; p = p->next) {
	gecko_cmd_mesh_prov_ddb_add(*(uuid_128*)p->uuid, *(aes_key_128*)p->key, 0, p->address, p->elements);
      }
      commands.ddb_nodes = NULL;
      gecko_cmd_dfu_reset(0);
      break;
    }
    if(commands.provisions) {
      struct provision *p = commands.provisions;
      commands.provisions = p->next;
      gecko_cmd_mesh_prov_provision_device(p->network_id, 16, p->uuid);
      free(p->uuid);
      free(p);
      break;
    }
    //gecko_cmd_mesh_prov_create_appkey(0, 0, NULL);
    if(commands.get.list_unprovisioned) {
      gecko_cmd_mesh_prov_scan_unprov_beacons();
    } else if (config.server) {
      gecko_cmd_mesh_config_client_get_dcd(0, config.server, config.dcd_page);      
    } else {
      gecko_cmd_mesh_prov_ddb_list_devices();
    }
    break;

  case gecko_evt_mesh_prov_ddb_list_id:
#define ED evt->data.evt_mesh_prov_ddb_list
    if(ED.address == my_address) break; // avoid timeout
    //if(ED.address != 0x2002) break;
    add_node(ED.address,ED.elements,gecko_cmd_mesh_config_client_get_dcd(0, ED.address, 0));      
    break;
#undef ED
    
  case gecko_evt_mesh_config_client_dcd_data_id:
#define ED evt->data.evt_mesh_config_client_dcd_data
    show_dcd(ED.page,ED.data.len,&ED.data.data[0],ED.handle);
    break;
#undef ED
    
  case gecko_evt_mesh_config_client_dcd_data_end_id:
#define ED evt->data.evt_mesh_config_client_dcd_data_end
    do_next(BGLIB_MSG_ID(evt->header),ED.result,ED.handle);
    break;
#undef ED
    
  case gecko_evt_mesh_config_client_netkey_list_end_id:
#define ED evt->data.evt_mesh_config_client_netkey_list_end
    do_next(BGLIB_MSG_ID(evt->header),ED.result,ED.handle);
    break;
#undef ED

  case gecko_evt_mesh_config_client_appkey_list_end_id:
#define ED evt->data.evt_mesh_config_client_appkey_list_end
    do_next(BGLIB_MSG_ID(evt->header),ED.result,ED.handle);
    break;
#undef ED
    
  case gecko_evt_mesh_config_client_bindings_list_id:
#define ED evt->data.evt_mesh_config_client_bindings_list
    got_bindings(&ED);
    break;
#undef ED

  case gecko_evt_mesh_config_client_bindings_list_end_id:
#define ED evt->data.evt_mesh_config_client_bindings_list_end
    do_next(BGLIB_MSG_ID(evt->header),ED.result,ED.handle);
    break;
#undef ED

  case gecko_evt_mesh_config_client_subs_list_id:
#define ED evt->data.evt_mesh_config_client_subs_list
    got_subs(&ED);
    break;
#undef ED

  case gecko_evt_mesh_config_client_subs_list_end_id:
#define ED evt->data.evt_mesh_config_client_subs_list_end
    do_next(BGLIB_MSG_ID(evt->header),ED.result,ED.handle);
    break;
#undef ED

  case gecko_evt_mesh_config_client_default_ttl_status_id:
#define ED evt->data.evt_mesh_config_client_default_ttl_status
    if(!ED.result) got_default_ttl(find_handle_reference(ED.handle),ED.value);
    break;
#undef ED

  case gecko_evt_mesh_config_client_beacon_status_id:
#define ED evt->data.evt_mesh_config_client_beacon_status
    if(!ED.result) got_beacon(find_handle_reference(ED.handle),ED.value);    
    break;
#undef ED

  case gecko_evt_mesh_config_client_identity_status_id:
#define ED evt->data.evt_mesh_config_client_identity_status
    if(!ED.result) got_identity(find_handle_reference(ED.handle),ED.value);    
    break;
#undef ED

  case gecko_evt_mesh_config_client_friend_status_id:
#define ED evt->data.evt_mesh_config_client_friend_status
    if(!ED.result) got_friend(find_handle_reference(ED.handle),ED.value);    
    break;
#undef ED

  case gecko_evt_mesh_config_client_gatt_proxy_status_id:
#define ED evt->data.evt_mesh_config_client_gatt_proxy_status
    if(!ED.result) got_gatt_proxy(find_handle_reference(ED.handle),ED.value);
    break;
#undef ED
    
  case gecko_evt_mesh_config_client_relay_status_id:
#define ED evt->data.evt_mesh_config_client_relay_status
    if(!ED.result) got_relay(find_handle_reference(ED.handle),
			     ED.relay,
			     ED.retransmit_count,
			     ED.retransmit_interval_ms);
    break;
#undef ED
    
  case gecko_evt_mesh_config_client_network_transmit_status_id:
#define ED evt->data.evt_mesh_config_client_network_transmit_status
    if(!ED.result) got_network_transmit(find_handle_reference(ED.handle),
					ED.transmit_count,
					ED.transmit_interval_ms);
    break;
#undef ED

  case gecko_evt_mesh_config_client_heartbeat_pub_status_id:
#define ED evt->data.evt_mesh_config_client_heartbeat_pub_status
    if(!ED.result) got_heartbeat_pub(find_handle_reference(ED.handle),
				     ED.destination_address,
				     ED.netkey_index,
				     ED.count_log,
				     ED.period_log,
				     ED.ttl,
				     ED.features);
    break;
#undef ED
    
  case gecko_evt_mesh_config_client_appkey_status_id:
    gecko_cmd_mesh_config_client_bind_model(0, config.server, 0, 0, 0xffff, 0x1000);
    break;
    
  case gecko_evt_mesh_node_initialized_id:
#define ED evt->data.evt_mesh_node_initialized
    if(ED.provisioned) {
      printf("Provisioned, initiating on/off server\n");
      gecko_cmd_mesh_generic_client_init_on_off();
      gecko_cmd_mesh_generic_client_init_common();
      gecko_cmd_mesh_test_get_key(0,0,1);
      if(config.health) {
	//gecko_cmd_mesh_health_client_get(0,config.server,0,0x02ff);
    	gecko_cmd_mesh_health_client_test(config.element,config.server,0,0,config.vendor,1);	
      } else {
	if(config.publish) gecko_cmd_mesh_generic_client_publish(MESH_GENERIC_ON_OFF_CLIENT_MODEL_ID,
								 config.element,
								 config.tid,
								 0,0, // transition & delay times
								 config.flags,
								 mesh_generic_request_on_off,
								 1,&config.value);
	else gecko_cmd_mesh_generic_client_set(MESH_GENERIC_ON_OFF_CLIENT_MODEL_ID,
					       config.element,
					       config.server,
					       0, //appkey index
					       config.tid,
					       0,0, // transition & delay times
					       config.flags,
					       mesh_generic_request_on_off,
					       1,&config.value);
      }
    } else {
      gecko_cmd_mesh_node_start_unprov_beaconing(0x3);
    }
    break;
#undef ED

  case gecko_evt_mesh_prov_unprov_beacon_id:
#define ED evt->data.evt_mesh_prov_unprov_beacon
    if(seen_unprovisioned_node(&ED)) break;
    add_unprovisioned_node(&ED);
    break;
#undef ED
    
  default:
    break;
  }
}
