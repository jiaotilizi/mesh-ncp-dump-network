#include "parser.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct commands commands = {
			    .network_keys = NULL,
			    .abort = 0,
			    .ota = 0,
			    .gpio = NULL,
	    .pa_mode = {
			.set = 0,
			.min = 0,
			.max = 1,
			.type = VALUE_TYPE_INTEGER,
			.name = "pa-mode",
			.help = "set pa-mode <pa>: 0 uses highest power PA, 1 next highest, etc.",
			},
	    .pa_input = {
			 .set = 0,
			 .min = 0,
			 .max = 1,
			 .type = VALUE_TYPE_PA_INPUT,
			 .name = "pa-input",
			 .help = "set pa-input <input>: 0, 1, VBAT or DCDC",
			 },
	    .tx_power = {
			 .set = 0,
			 .min = -32768,
			 .max = 32767,
			 .type = VALUE_TYPE_FLOAT,
			 .conversion = 10.0,
			 .name = "tx-power",
			 .help  = "set tx-power <dBm>: requested TX power in dBm, useful range -27 to 20",
			 },
	    .em2_debug = {
			  .set = 0,
			  .min = 0,
			  .max = 1,
			  .type = VALUE_TYPE_ENABLE,
			  .name = "em2-debug",
			  .help = "set em2-debug <enable>: 0, 1, disable or enable",
			  },
	    .connection_interval = {
				    .set = 0,
				    .min = 6,
				    .max = 3200,
				    .type = VALUE_TYPE_FLOAT,
				    .conversion = 0.8,
				    .name = "connection-interval",
				    .help = "set connection-interval <ms>: 7.5 to 4000",
				    },
	    .adv_interval = {
			     .set = 0,
			     .min = 0x20,
			     .max = 0xffff,
			     .type = VALUE_TYPE_FLOAT,
			     .conversion = 1.6,
			     .name = "adv-interval",
			     .help = "set adv-interval <ms>: 20 to 30000",
			     },
	    .adv_length = {
			   .set = 0,
			   .min = 0,
			   .max = 31,
			   .type = VALUE_TYPE_INTEGER,
			   .name = "adv-length",
			   .help = "set adv-length <payload-size>: 0 to 31",
			   },
	    .sleep_clock_accuracy = {
				     .set = 0,
				     .min = 0,
				     .max = 500,
				     .type = VALUE_TYPE_INTEGER,
				     .name = "sleep-clock-accuracy",
				     .help = "set sleep-clock-accuracy <ppm>",
				     },
	    .average_rssi = {
			     .set = 0,
			     .min = 623,
			     .max = 0x7fffffff,
			     .type = VALUE_TYPE_FLOAT,
			     .conversion = 32768,
			     .name = "average-rssi",
			     .help = "average-rssi <seconds>: duration to average RSSI over",
			     },
	    .rssi_channel = {
			     .set = 0,
			     .min = 0,
			     .max = 2,
			     .type = VALUE_TYPE_INTEGER,
			     .name = "rssi-channel",
			     .help = "set rssi-channel <index>: channel to measure average RSSI.  0-2",
			     },
	    .measurement_duration = {
				     .set = 0,
				     .min = 623,
				     .max = 0x7fffffff,
				     .type = VALUE_TYPE_FLOAT,
				     .conversion = 32768,
				     .name = "measurement duration",
				     .help = "",
				     },
	    .measurement_mode = {
				 .set = 0,
				 .min = 0,
				 .max = 0x7fffffff,
				 .type = VALUE_TYPE_MEASUREMENT_MODE,
				 .conversion = 32768,
				 .name = "measurement mode",
				 .help = "",
				 },
	    .random_lower = {
			     .set = 0,
			     .min = -300,
			     .max = 200,
			     .type = VALUE_TYPE_FLOAT,
			     .conversion = 10,
			     .name = "random-lower",
			     .help = "set random-lower <dBm>: lower bound for TX Power",
			     },
	    .random_upper = {
			     .set = 0,
			     .min = -300,
			     .max = 200,
			     .type = VALUE_TYPE_FLOAT,
			     .conversion = 10,
			     .name = "random-upper",
			     .help = "set random-upper <dBm>: upper bound for TX Power",
			     },
	    .random_count = {
			     .set = 0,
			     .min = -300,
			     .max = 200,
			     .type = VALUE_TYPE_FLOAT,
			     .conversion = 10,
			     .name = "random-count",
			     .help = "set random-count <count>: number of consecutive advertisements between TX power randomization",
			     },
	    .dtm_channel = {
			    .set = 0,
			    .min = 0,
			    .max = 39,
			    .type = VALUE_TYPE_INTEGER,
			    .name = "dtm-channel",
			    .help = "set dtm-channel <channel>: channel used for DTM TX and RX measurements, 0 to 39",
			    },
	    .test = {
		     .set = 0,
		     .min = 0,
		     .max = 0xffff,
		     .type = VALUE_TYPE_INTEGER,
		     .name = "test",
		     .help = "test feature",
		     },
};

int yyerror(const char *msg) {
  fprintf(stderr,"Wrong! (%s)\n",msg);
  return 0;
}

int set_parameter(struct parameter *parameter, struct value *value) {
  int integer;
  //printf("Setting %s to (%d / %lf) ... ",parameter->name,value->integer,value->fp);
  switch(parameter->type) {
  case VALUE_TYPE_INTEGER:
    switch(value->type) {
    case VALUE_TYPE_INTEGER:
      parameter->value = value->integer;
      break;
    case VALUE_TYPE_FLOAT:
      integer = value->fp;
      if(integer == value->fp) {
	parameter->value = integer;
	break;
      }
    default:
      fprintf(stderr,"%s value should be integer\n",parameter->name);
      return 1;
    }
    break;
  case VALUE_TYPE_FLOAT:
    switch(value->type) {
    case VALUE_TYPE_INTEGER:
      parameter->value = round(parameter->conversion * value->integer);
      break;
    case VALUE_TYPE_FLOAT:
      parameter->value = round(parameter->conversion * value->fp);
      break;
    default:
      fprintf(stderr,"%s value should be floating-point\n",parameter->name);
      return 1;
    }
    break;
  case VALUE_TYPE_ENABLE:
    switch(value->type) {
    case VALUE_TYPE_INTEGER:
    case VALUE_TYPE_ENABLE:
      parameter->value = value->integer;
      break;
    default:
      fprintf(stderr,"%s value should be one of: 0, 1, enable, disable\n",parameter->name);
      return 1;
    }
  case VALUE_TYPE_PA_INPUT:
    switch(value->type) {
    case VALUE_TYPE_INTEGER:
    case VALUE_TYPE_PA_INPUT:
      parameter->value = value->integer;
      break;
    default:
      fprintf(stderr,"%s value should be one of: 0, 1, VBAT, DCDC\n",parameter->name);
      return 1;
    }
  case VALUE_TYPE_MEASUREMENT_MODE:
    switch(value->type) {
    case VALUE_TYPE_MEASUREMENT_MODE:
      parameter->value = value->integer;
      break;
    default:
      fprintf(stderr,"%s value should be one of: connected, em1, em3, em3, em4h, em4s random\n",parameter->name);
      return 1;
    }
  }
  //printf("= 0x%x\n",parameter->value);
  if(parameter->value > parameter->max) {
    fprintf(stderr,"%s value too high\n",parameter->name);
    return 1;
  }
  if(parameter->value < parameter->min) {
    fprintf(stderr,"%s value too low\n",parameter->name);
    return 1;
  }
  parameter->set = 1;
  return 0;
}

struct value *create_integer(int value) {
  struct value *rc = malloc(sizeof(struct value));
  rc->type = VALUE_TYPE_INTEGER;
  rc->integer = value;
  return rc;
}

struct value *create_float(double value) {
  struct value *rc = malloc(sizeof(struct value));
  rc->type = VALUE_TYPE_FLOAT;
  rc->fp = value;
  return rc;
}

void set_mode_and_attach(struct gpio_element *list, uint8_t mode) {
  for(struct gpio_element *ptr = list; ptr; ptr = ptr->next) {
    ptr->mode = mode;
  }
  if(!commands.gpio) {
    commands.gpio = list;
    return;
  }
  for(struct gpio_element *ptr = commands.gpio; ptr; ptr = ptr->next) {
    if(ptr->next) continue;
    ptr->next = list;
    return;
  }
}

void add_network_key(uint8_t *key) {
  struct network_keys *n = malloc(sizeof(struct network_keys));
  n->key = (aes_key_128 *)key;
  n->next = NULL;
  struct network_keys **p = &commands.network_keys;
  while(1) {
    if(!*p) {
      *p = n;
      return;
    }
    p = &(*p)->next;
  }
}
