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

void add_node(struct gecko_msg_mesh_prov_unprov_beacon_evt_t *in) {
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

int seen_unprov_node(struct gecko_msg_mesh_prov_unprov_beacon_evt_t *in) {
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

void appInit(void) {
  if(!config.server) {
    config.publish = 1;
  }
}

void list_nodes(void) {
  for(struct unprov_nodes *p = unprov_nodes; p; p = p->next) {
    printf("UUID: %s\n",render_binary(&p->uuid[0]));
  }
}

void show_dcd(uint8 page, uint8 len, uint8*data) {
  struct __attribute__((__packed__)) dcd0 {
    uint16 cid,pid,vid,crpl,features;
  } *pd;
  struct __attribute__((__packed__)) elements {
    uint16 loc;
    uint8 nums, numv;
    uint16 sigs[];
  } *pe;
  
  switch(page) {
  case 0:
    pd = (struct dcd0*)data;
    printf("DCD Page 0:\n");
    printf("\tCID: %04x\n",pd->cid);
    printf("\tPID: %04x\n",pd->pid);
    printf("\tVID: %04x\n",pd->vid);
    printf("\tCRPL: %04x\n",pd->crpl);
    printf("\tFeatures:%s%s%s%s\n",
	   (pd->features&1)?" Relay":"",
	   (pd->features&2)?" Proxy":"",
	   (pd->features&4)?" Friend":"",
	   (pd->features&8)?" Low-power":"");
    for(pe = data + sizeof(struct dcd0); pe < data+len; pe += 4 + 2*pe->nums + 4*pe->numv) {
      printf("\tLoc: %04x\n",pe->loc);
      printf("\t%d SIG Model IDs\n",pe->nums);
      printf("\t%d Vendor Model IDs\n",pe->numv);
      printf("\t\tSIG Models:");
      for(int i = 0; i < pe->nums; i++) {
	printf(" %04x",((uint16*)&pe->sigs[0])[i]);
      }
    }
    break;
  default:
    printf("DCD Page %d not handled\n",page);
    break;
  }
  return;
}
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
	if(config.scan) list_nodes();
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
    //    if(unprov_nodes || config.server) {
      gecko_cmd_mesh_prov_init();
      //} else {
      //gecko_cmd_mesh_node_init();
      //}
    break;
#undef ED

  case gecko_evt_mesh_prov_initialized_id:
    if(config.network_key) {
      config.network_id = gecko_cmd_mesh_prov_create_network((config.network_key)?16:0,config.network_key)->network_id;
      exit(0);
    }
    if(config.device_uuid) {
      gecko_cmd_mesh_prov_ddb_add(*(uuid_128*)config.device_uuid, *(aes_key_128*)config.device_key, 0, config.server, 4);
      exit(0);
    }
    //gecko_cmd_mesh_prov_provision_device(config.network_id, 16,&unprov_nodes->uuid[0]);
    //gecko_cmd_mesh_prov_create_appkey(0, 0, NULL);
    if(config.scan) {
      gecko_cmd_mesh_prov_scan_unprov_beacons();
    } else if (config.server) {
      gecko_cmd_mesh_config_client_get_dcd(0, config.server, config.dcd_page);      
    } else {
      gecko_cmd_mesh_prov_ddb_list_devices();
    }
    break;

  case gecko_evt_mesh_config_client_dcd_data_end_id:
    //gecko_cmd_mesh_config_client_add_appkey(0, config.server, 0, 0);
    gecko_cmd_mesh_config_client_list_netkeys(0, config.server);
    break;

  case gecko_evt_mesh_config_client_netkey_list_end_id:
    gecko_cmd_mesh_config_client_list_appkeys(0, config.server, 0);
    break;

  case gecko_evt_mesh_config_client_appkey_list_end_id:
    gecko_cmd_mesh_config_client_list_bindings(0, config.server, 0, 0xffff, 0x1000);
    break;
    
  case gecko_evt_mesh_config_client_bindings_list_end_id:
    gecko_cmd_mesh_config_client_list_subs(0, config.server, 0, 0xffff, 0x1000);
    break;
    
  case gecko_evt_mesh_config_client_appkey_status_id:
    gecko_cmd_mesh_config_client_bind_model(0, config.server, 0, 0, 0xffff, 0x1000);
    break;
    
  case gecko_evt_mesh_config_client_dcd_data_id:
#define ED evt->data.evt_mesh_config_client_dcd_data
    show_dcd(ED.page,ED.data.len,&ED.data.data[0]);
    break;
#undef ED
    
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
    if(seen_unprov_node(&ED)) break;
    add_node(&ED);
    break;
#undef ED
    
  default:
    break;
  }
}
