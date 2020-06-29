/* parser for BG Control NCP */

%{
  #include <stdio.h>
  #include <stdint.h>
  #include "parser.h"
  
  int yylex(void);
  void yyerror(const char *);

  int set_parameter(struct parameter *parameter, struct value *value);
  struct value *create_integer(int value);
  struct value *create_float(double value);
  void set_mode_and_attach(struct gpio_element *list, uint8_t mode);

%}

%union {
  struct value *value;
  struct gpio_element *gpio;
  double fp;
  int integer, unicast_address;
  uint8_t *get, *value_128;
  struct parameter *set;
}
%token HELP
%token FACTORY_RESET SHOW INITIALIZE_NETWORK  LIST CREATE NETWORK UNPROVISIONED ADD NODE
%token CONNECTED EM1 EM2 EM3 EM4H EM4S
%token AVERAGE_RSSI RSSI_CHANNEL TEST
%token OTA MEASURE MEASUREMENT_MODE UNKNOWN
%token RANDOM RANDOM_LOWER RANDOM_UPPER RANDOM_COUNT DTM_CHANNEL
%token DCDC EMU GPIO POWER_SETTINGS PA_INPUT_VBAT PA_INPUT_DCDC
%token PA_MODE PA_INPUT TX_POWER EM2_DEBUG CONNECTION_INTERVAL ADV_INTERVAL ADV_LENGTH SLEEP_CLOCK_ACCURACY
%token COMMA ASSIGN
%token GPIO_DISABLED GPIO_INPUT GPIO_INPUTPULL GPIO_INPUTPULLFILTER GPIO_PUSHPULL
%token GPIO_WIREOR GPIO_WIREDAND GPIO_WIREDANDFILTER GPIO_WIREDANDPULLUP GPIO_WIREDANDPULLUPFILTER
%token <integer> INT
%token <fp> FLOAT
%token <value_128> VALUE_128
%token <gpio> GPIO_PIN GPIO_PIN_ASSIGNMENT 
%token ENABLE DISABLE
%nterm <unicast_address> unicast_address
%nterm <integer> command
%nterm <get> peripheral
%nterm <value> value gpio_pin_value
%nterm <gpio> gpio_pin_assignment gpio_pin_list_element gpio_pin_list
%nterm <set> parameter

%start line

%%

line :
  /* empty */
  | command line
  ;

command :
FACTORY_RESET { commands.get.factory_reset = 1; }
| INITIALIZE_NETWORK unicast_address INT { commands.provisioner_address = $2; commands.ivi = $3; }
| SHOW { commands.get.show = 1; }
| CREATE NETWORK VALUE_128 { add_network_key($3); }
| CREATE help { printf("create <key> <aes-key-128>: key can be network\n"); }
| CREATE NETWORK help { printf("create network <aes-key-128>\n"); }
| ADD NODE VALUE_128 VALUE_128 unicast_address INT { add_ddb_node($3,$4,$5,$6); }
| LIST UNPROVISIONED { commands.get.list_unprovisioned = 1; }
| AVERAGE_RSSI value { if(set_parameter(&commands.average_rssi,$2)) commands.abort = 1; free($2); }
| MEASURE value value {
  if(set_parameter(&commands.measurement_mode,$2)) commands.abort = 1; free($2);
  if(set_parameter(&commands.measurement_duration,$3)) commands.abort = 1; free($3);
}
| MEASURE help { printf("measure <mode> <duration>:\n"
			"\tmode: connected em1 em2 em3 em4h em4s random\n"
			"\tduration: time in seconds to remain in specified mode before\n"
			"\t\tadvertising as bg-control peripheral\n"); }
| help { printf("Commands:\n"
		"\tfactory-reset\n"
		"\tinitialize-network <unicast-address> <ivi>\n"
		"\tshow\n"
		"\tcreate network <network-key>\n"
		"\tlist unprovisioned\n"
		"\tadd node <uuid-128> <aes-key-128> <unicast-address> <elements>\n"
		"  Specify 'help' as peripheral or parameter to get list of supported names\n"); }
| GPIO_DISABLED gpio_pin_list { set_mode_and_attach($2,0); }
| GPIO_PUSHPULL gpio_pin_list { set_mode_and_attach($2,4); }
;

unicast_address :
INT { validate_unicast_address($1); $$ = $1; }
;

peripheral :
DCDC { $$ = &commands.get.dcdc; }
| EMU { $$ = &commands.get.emu; }
| GPIO { $$ = &commands.get.gpio; }
| POWER_SETTINGS { $$ = &commands.get.power_settings; }
| help { printf("Peripherals: DCDC EMU GPIO\n"); $$ = NULL; }
;

parameter :
PA_MODE { $$ = &commands.pa_mode; }
| PA_INPUT { $$ = &commands.pa_input; }
| TX_POWER { $$ = &commands.tx_power; }
| EM2_DEBUG { $$ = &commands.em2_debug; }
| CONNECTION_INTERVAL { $$ = &commands.connection_interval; }
| ADV_INTERVAL { $$ = &commands.adv_interval; }
| ADV_LENGTH { $$ = &commands.adv_length; }
| SLEEP_CLOCK_ACCURACY { $$ = &commands.sleep_clock_accuracy; }
| RSSI_CHANNEL { $$ = &commands.rssi_channel; }
| RANDOM_LOWER { $$ = &commands.random_lower; }
| RANDOM_UPPER { $$ = &commands.random_upper; }
| RANDOM_COUNT { $$ = &commands.random_count; }
| DTM_CHANNEL { $$ = &commands.dtm_channel; }
;

value :
INT { $$ = create_integer($1); }
| FLOAT { $$ = create_float($1); }
| DISABLE { $$ = create_integer(0); $$->type = VALUE_TYPE_ENABLE; }
| ENABLE { $$ = create_integer(1); $$->type = VALUE_TYPE_ENABLE; }
| PA_INPUT_VBAT { $$ = create_integer(0); $$->type = VALUE_TYPE_PA_INPUT; }
| PA_INPUT_DCDC { $$ = create_integer(1); $$->type = VALUE_TYPE_PA_INPUT; }
| CONNECTED { $$ = create_integer(CONNECTED); $$->type = VALUE_TYPE_MEASUREMENT_MODE; }
| EM1 { $$ = create_integer(EM1); $$->type = VALUE_TYPE_MEASUREMENT_MODE; }
| EM2 { $$ = create_integer(EM2); $$->type = VALUE_TYPE_MEASUREMENT_MODE; }
| EM3 { $$ = create_integer(EM3); $$->type = VALUE_TYPE_MEASUREMENT_MODE; }
| EM4H { $$ = create_integer(EM4H); $$->type = VALUE_TYPE_MEASUREMENT_MODE; }
| EM4S { $$ = create_integer(EM4S); $$->type = VALUE_TYPE_MEASUREMENT_MODE; }
| RANDOM { $$ = create_integer(RANDOM); $$->type = VALUE_TYPE_MEASUREMENT_MODE; }
| TEST { $$ = create_integer(TEST); $$->type = VALUE_TYPE_MEASUREMENT_MODE; }
;

gpio_pin_list :
gpio_pin_list_element { $$ = $1; $$->next = NULL; }
| gpio_pin_list_element COMMA gpio_pin_list { $$ = $1; $1->next = $3; }
;

gpio_pin_list_element :
GPIO_PIN { $$ = $1; }
| gpio_pin_assignment { $$ = $1; }
;

gpio_pin_assignment :
GPIO_PIN ASSIGN gpio_pin_value { $$ = $1; $$->value = $3->integer; free($3); }

gpio_pin_value :
INT { $$ = create_integer($1); }
;

help :
HELP { commands.abort = 1; }
;

%%
