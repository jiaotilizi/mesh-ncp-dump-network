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
  
struct commands {
  struct network_keys *network_keys;
  struct {
    uint8_t factory_reset, show, list_unprovisioned;
  } get;
  struct parameter pa_mode, pa_input, tx_power, em2_debug, sleep_clock_accuracy,
    connection_interval, adv_interval, adv_length,
    measurement_mode, measurement_duration, average_rssi, rssi_channel,
    random_lower, random_upper, random_count, dtm_channel, test;
  uint8_t abort, ota;
  struct gpio_element *gpio;
};

extern struct commands commands;
void add_network_key(uint8_t *key);
