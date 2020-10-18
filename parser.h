#include <stdint.h>
#include "bg_types.h"

enum value_types { VALUE_TYPE_INTEGER, VALUE_TYPE_FLOAT, VALUE_TYPE_ENABLE,
		   VALUE_TYPE_PA_INPUT, VALUE_TYPE_MEASUREMENT_MODE };

  struct value {
    enum value_types type;
    double fp;
    int integer;
  };

struct parameter {
  uint8_t set;
  int32_t value;
  int32_t min, max;
  double conversion;
  enum value_types type;
  const char *help, *name;
};

struct gpio_element {
  int port, pin, mode, value;
  struct gpio_element *next;
};

struct network_keys {
  aes_key_128 *key;
  struct network_keys *next;
};

struct ddb_node {
  uuid_128 *uuid;
  aes_key_128 *key;
  uint16_t address;
  uint8_t elements;
  struct ddb_node *next;
};

struct binding {
  uint16_t server_address, appkey_index, vendor_id, model_id;
  uint8_t element_index;
  struct binding *next;
};

struct provision {
  uuid_128 *uuid;
  uint8_t network_id;
  struct provision *next;
};

struct get_devkey {
  uint16_t address;
};

struct commands {
  struct network_keys *network_keys;
  struct ddb_node *ddb_nodes;
  struct binding *bindings;
  struct provision *provisions;
  struct get_devkey *get_devkey;
  struct {
    uint8_t factory_reset, show, list_unprovisioned;
  } get;
  uint16_t provisioner_address;
  uint32_t ivi;
  struct parameter pa_mode, pa_input, tx_power, em2_debug, sleep_clock_accuracy,
    connection_interval, adv_interval, adv_length,
    measurement_mode, measurement_duration, average_rssi, rssi_channel,
    random_lower, random_upper, random_count, dtm_channel, test;
  uint8_t abort, ota;
  struct gpio_element *gpio;
};

extern struct commands commands;
void add_network_key(uint8_t *key);
void validate_unicast_address(int v);
void add_ddb_node(uint8_t *uuid, uint8_t *key, uint16_t address, uint8_t elements);
void add_provision(uuid_128 *uuid, uint8_t network_id);
void add_get_devkey(uint16_t address);
