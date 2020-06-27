#ifndef DUMP_H_
#define DUMP_H_
#define DUMP
#include "bg_types.h"
#include "gecko_bglib.h"
#include <stdio.h>
extern void dump_event(struct gecko_cmd_packet *evt);
void dump_timestamp(int);
extern int dump_mode;
extern void dump_footer(void);
extern void dump_command_header(const char*);
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
static inline void dump_dfu_flash_set_address(struct gecko_msg_dfu_flash_set_address_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_dfu_flash_upload(struct gecko_msg_dfu_flash_upload_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_dfu_flash_upload_finish(struct gecko_msg_dfu_flash_upload_finish_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_hello(struct gecko_msg_system_hello_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_get_bt_address(struct gecko_msg_system_get_bt_address_rsp_t* resp) {
   printf("      bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",resp->address.addr[5-i]);
   printf("\n");
}
static inline void dump_system_set_bt_address(struct gecko_msg_system_set_bt_address_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_set_tx_power(struct gecko_msg_system_set_tx_power_rsp_t* resp) {
   printf("      int16 set_power: 0x%d\n",(int)resp->set_power);
}
static inline void dump_system_get_random_data(struct gecko_msg_system_get_random_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  data: %d:",(int)resp->data.len);
   for(int i = 0; i < resp->data.len; i++)
      printf("%s%02x",(i)?",":"{",resp->data.data[i]);
   printf("}\n");
}
static inline void dump_system_halt(struct gecko_msg_system_halt_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_set_device_name(struct gecko_msg_system_set_device_name_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_linklayer_configure(struct gecko_msg_system_linklayer_configure_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_get_counters(struct gecko_msg_system_get_counters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      tx_packets: 0x%04x\n",(int)resp->tx_packets);
   printf("      uint16      rx_packets: 0x%04x\n",(int)resp->rx_packets);
   printf("      uint16      crc_errors: 0x%04x\n",(int)resp->crc_errors);
   printf("      uint16      failures: 0x%04x\n",(int)resp->failures);
}
static inline void dump_system_data_buffer_write(struct gecko_msg_system_data_buffer_write_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_set_identity_address(struct gecko_msg_system_set_identity_address_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_data_buffer_clear(struct gecko_msg_system_data_buffer_clear_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_open(struct gecko_msg_le_gap_open_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       connection: 0x%02x\n",(int)resp->connection);
}
static inline void dump_le_gap_set_mode(struct gecko_msg_le_gap_set_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_discover(struct gecko_msg_le_gap_discover_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_end_procedure(struct gecko_msg_le_gap_end_procedure_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_adv_parameters(struct gecko_msg_le_gap_set_adv_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_conn_parameters(struct gecko_msg_le_gap_set_conn_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_scan_parameters(struct gecko_msg_le_gap_set_scan_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_adv_data(struct gecko_msg_le_gap_set_adv_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_adv_timeout(struct gecko_msg_le_gap_set_adv_timeout_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_conn_phy(struct gecko_msg_le_gap_set_conn_phy_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_bt5_set_mode(struct gecko_msg_le_gap_bt5_set_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_bt5_set_adv_parameters(struct gecko_msg_le_gap_bt5_set_adv_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_bt5_set_adv_data(struct gecko_msg_le_gap_bt5_set_adv_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_privacy_mode(struct gecko_msg_le_gap_set_privacy_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_advertise_timing(struct gecko_msg_le_gap_set_advertise_timing_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_advertise_channel_map(struct gecko_msg_le_gap_set_advertise_channel_map_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_advertise_report_scan_request(struct gecko_msg_le_gap_set_advertise_report_scan_request_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_advertise_phy(struct gecko_msg_le_gap_set_advertise_phy_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_advertise_configuration(struct gecko_msg_le_gap_set_advertise_configuration_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_clear_advertise_configuration(struct gecko_msg_le_gap_clear_advertise_configuration_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_start_advertising(struct gecko_msg_le_gap_start_advertising_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_stop_advertising(struct gecko_msg_le_gap_stop_advertising_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_discovery_timing(struct gecko_msg_le_gap_set_discovery_timing_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_discovery_type(struct gecko_msg_le_gap_set_discovery_type_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_start_discovery(struct gecko_msg_le_gap_start_discovery_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_data_channel_classification(struct gecko_msg_le_gap_set_data_channel_classification_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_connect(struct gecko_msg_le_gap_connect_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       connection: 0x%02x\n",(int)resp->connection);
}
static inline void dump_le_gap_set_advertise_tx_power(struct gecko_msg_le_gap_set_advertise_tx_power_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      int16 set_power: 0x%d\n",(int)resp->set_power);
}
static inline void dump_le_gap_set_discovery_extended_scan_response(struct gecko_msg_le_gap_set_discovery_extended_scan_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_start_periodic_advertising(struct gecko_msg_le_gap_start_periodic_advertising_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_stop_periodic_advertising(struct gecko_msg_le_gap_stop_periodic_advertising_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_long_advertising_data(struct gecko_msg_le_gap_set_long_advertising_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_enable_whitelisting(struct gecko_msg_le_gap_enable_whitelisting_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_conn_timing_parameters(struct gecko_msg_le_gap_set_conn_timing_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_advertise_random_address(struct gecko_msg_le_gap_set_advertise_random_address_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      bd_addr     address_out: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",resp->address_out.addr[5-i]);
   printf("\n");
}
static inline void dump_le_gap_clear_advertise_random_address(struct gecko_msg_le_gap_clear_advertise_random_address_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sync_open(struct gecko_msg_sync_open_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       sync: 0x%02x\n",(int)resp->sync);
}
static inline void dump_sync_close(struct gecko_msg_sync_close_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_set_parameters(struct gecko_msg_le_connection_set_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_get_rssi(struct gecko_msg_le_connection_get_rssi_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_disable_slave_latency(struct gecko_msg_le_connection_disable_slave_latency_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_set_phy(struct gecko_msg_le_connection_set_phy_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_close(struct gecko_msg_le_connection_close_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_set_timing_parameters(struct gecko_msg_le_connection_set_timing_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_read_channel_map(struct gecko_msg_le_connection_read_channel_map_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  channel_map: %d:",(int)resp->channel_map.len);
   for(int i = 0; i < resp->channel_map.len; i++)
      printf("%s%02x",(i)?",":"{",resp->channel_map.data[i]);
   printf("}\n");
}
static inline void dump_le_connection_set_preferred_phy(struct gecko_msg_le_connection_set_preferred_phy_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_set_max_mtu(struct gecko_msg_gatt_set_max_mtu_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      max_mtu: 0x%04x\n",(int)resp->max_mtu);
}
static inline void dump_gatt_discover_primary_services(struct gecko_msg_gatt_discover_primary_services_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_discover_primary_services_by_uuid(struct gecko_msg_gatt_discover_primary_services_by_uuid_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_discover_characteristics(struct gecko_msg_gatt_discover_characteristics_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_discover_characteristics_by_uuid(struct gecko_msg_gatt_discover_characteristics_by_uuid_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_set_characteristic_notification(struct gecko_msg_gatt_set_characteristic_notification_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_discover_descriptors(struct gecko_msg_gatt_discover_descriptors_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_read_characteristic_value(struct gecko_msg_gatt_read_characteristic_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_read_characteristic_value_by_uuid(struct gecko_msg_gatt_read_characteristic_value_by_uuid_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_write_characteristic_value(struct gecko_msg_gatt_write_characteristic_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_write_characteristic_value_without_response(struct gecko_msg_gatt_write_characteristic_value_without_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      sent_len: 0x%04x\n",(int)resp->sent_len);
}
static inline void dump_gatt_prepare_characteristic_value_write(struct gecko_msg_gatt_prepare_characteristic_value_write_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      sent_len: 0x%04x\n",(int)resp->sent_len);
}
static inline void dump_gatt_execute_characteristic_value_write(struct gecko_msg_gatt_execute_characteristic_value_write_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_send_characteristic_confirmation(struct gecko_msg_gatt_send_characteristic_confirmation_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_read_descriptor_value(struct gecko_msg_gatt_read_descriptor_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_write_descriptor_value(struct gecko_msg_gatt_write_descriptor_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_find_included_services(struct gecko_msg_gatt_find_included_services_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_read_multiple_characteristic_values(struct gecko_msg_gatt_read_multiple_characteristic_values_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_read_characteristic_value_from_offset(struct gecko_msg_gatt_read_characteristic_value_from_offset_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_prepare_characteristic_value_reliable_write(struct gecko_msg_gatt_prepare_characteristic_value_reliable_write_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      sent_len: 0x%04x\n",(int)resp->sent_len);
}
static inline void dump_gatt_server_read_attribute_value(struct gecko_msg_gatt_server_read_attribute_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  value: %d:",(int)resp->value.len);
   for(int i = 0; i < resp->value.len; i++)
      printf("%s%02x",(i)?",":"{",resp->value.data[i]);
   printf("}\n");
}
static inline void dump_gatt_server_read_attribute_type(struct gecko_msg_gatt_server_read_attribute_type_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  type: %d:",(int)resp->type.len);
   for(int i = 0; i < resp->type.len; i++)
      printf("%s%02x",(i)?",":"{",resp->type.data[i]);
   printf("}\n");
}
static inline void dump_gatt_server_write_attribute_value(struct gecko_msg_gatt_server_write_attribute_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_server_send_user_read_response(struct gecko_msg_gatt_server_send_user_read_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      sent_len: 0x%04x\n",(int)resp->sent_len);
}
static inline void dump_gatt_server_send_user_write_response(struct gecko_msg_gatt_server_send_user_write_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_server_send_characteristic_notification(struct gecko_msg_gatt_server_send_characteristic_notification_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      sent_len: 0x%04x\n",(int)resp->sent_len);
}
static inline void dump_gatt_server_find_attribute(struct gecko_msg_gatt_server_find_attribute_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      attribute: 0x%04x\n",(int)resp->attribute);
}
static inline void dump_gatt_server_set_capabilities(struct gecko_msg_gatt_server_set_capabilities_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_server_set_max_mtu(struct gecko_msg_gatt_server_set_max_mtu_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      max_mtu: 0x%04x\n",(int)resp->max_mtu);
}
static inline void dump_gatt_server_get_mtu(struct gecko_msg_gatt_server_get_mtu_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      mtu: 0x%04x\n",(int)resp->mtu);
}
static inline void dump_gatt_server_enable_capabilities(struct gecko_msg_gatt_server_enable_capabilities_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_server_disable_capabilities(struct gecko_msg_gatt_server_disable_capabilities_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_server_get_enabled_capabilities(struct gecko_msg_gatt_server_get_enabled_capabilities_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      caps: 0x%08x\n",(int)resp->caps);
}
static inline void dump_hardware_set_soft_timer(struct gecko_msg_hardware_set_soft_timer_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_hardware_get_time(struct gecko_msg_hardware_get_time_rsp_t* resp) {
   printf("      uint32      seconds: 0x%08x\n",(int)resp->seconds);
   printf("      uint16      ticks: 0x%04x\n",(int)resp->ticks);
}
static inline void dump_hardware_set_lazy_soft_timer(struct gecko_msg_hardware_set_lazy_soft_timer_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_flash_ps_erase_all(struct gecko_msg_flash_ps_erase_all_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_flash_ps_save(struct gecko_msg_flash_ps_save_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_flash_ps_load(struct gecko_msg_flash_ps_load_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  value: %d:",(int)resp->value.len);
   for(int i = 0; i < resp->value.len; i++)
      printf("%s%02x",(i)?",":"{",resp->value.data[i]);
   printf("}\n");
}
static inline void dump_flash_ps_erase(struct gecko_msg_flash_ps_erase_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_test_dtm_tx(struct gecko_msg_test_dtm_tx_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_test_dtm_rx(struct gecko_msg_test_dtm_rx_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_test_dtm_end(struct gecko_msg_test_dtm_end_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_set_bondable_mode(struct gecko_msg_sm_set_bondable_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_configure(struct gecko_msg_sm_configure_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_store_bonding_configuration(struct gecko_msg_sm_store_bonding_configuration_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_increase_security(struct gecko_msg_sm_increase_security_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_delete_bonding(struct gecko_msg_sm_delete_bonding_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_delete_bondings(struct gecko_msg_sm_delete_bondings_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_enter_passkey(struct gecko_msg_sm_enter_passkey_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_passkey_confirm(struct gecko_msg_sm_passkey_confirm_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_set_oob_data(struct gecko_msg_sm_set_oob_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_list_all_bondings(struct gecko_msg_sm_list_all_bondings_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_bonding_confirm(struct gecko_msg_sm_bonding_confirm_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_set_debug_mode(struct gecko_msg_sm_set_debug_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_set_passkey(struct gecko_msg_sm_set_passkey_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_use_sc_oob(struct gecko_msg_sm_use_sc_oob_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  oob_data: %d:",(int)resp->oob_data.len);
   for(int i = 0; i < resp->oob_data.len; i++)
      printf("%s%02x",(i)?",":"{",resp->oob_data.data[i]);
   printf("}\n");
}
static inline void dump_sm_set_sc_remote_oob_data(struct gecko_msg_sm_set_sc_remote_oob_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_add_to_whitelist(struct gecko_msg_sm_add_to_whitelist_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_set_minimum_key_size(struct gecko_msg_sm_set_minimum_key_size_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_configure(struct gecko_msg_homekit_configure_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_advertise(struct gecko_msg_homekit_advertise_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_delete_pairings(struct gecko_msg_homekit_delete_pairings_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_check_authcp(struct gecko_msg_homekit_check_authcp_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_get_pairing_id(struct gecko_msg_homekit_get_pairing_id_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  pairing_id: %d:",(int)resp->pairing_id.len);
   for(int i = 0; i < resp->pairing_id.len; i++)
      printf("%s%02x",(i)?",":"{",resp->pairing_id.data[i]);
   printf("}\n");
}
static inline void dump_homekit_send_write_response(struct gecko_msg_homekit_send_write_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_send_read_response(struct gecko_msg_homekit_send_read_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_gsn_action(struct gecko_msg_homekit_gsn_action_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_event_notification(struct gecko_msg_homekit_event_notification_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_broadcast_action(struct gecko_msg_homekit_broadcast_action_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_configure_product_data(struct gecko_msg_homekit_configure_product_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_init(struct gecko_msg_mesh_node_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_start_unprov_beaconing(struct gecko_msg_mesh_node_start_unprov_beaconing_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_stop_unprov_beaconing(struct gecko_msg_mesh_node_stop_unprov_beaconing_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_rssi(struct gecko_msg_mesh_node_rssi_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      int8        rssi: 0x%d\n",(int)resp->rssi);
}
static inline void dump_mesh_node_input_oob_request_rsp(struct gecko_msg_mesh_node_input_oob_request_rsp_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_get_uuid(struct gecko_msg_mesh_node_get_uuid_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  uuid: %d:",(int)resp->uuid.len);
   for(int i = 0; i < resp->uuid.len; i++)
      printf("%s%02x",(i)?",":"{",resp->uuid.data[i]);
   printf("}\n");
}
static inline void dump_mesh_node_set_provisioning_data(struct gecko_msg_mesh_node_set_provisioning_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_init_oob(struct gecko_msg_mesh_node_init_oob_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_set_ivrecovery_mode(struct gecko_msg_mesh_node_set_ivrecovery_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_get_ivrecovery_mode(struct gecko_msg_mesh_node_get_ivrecovery_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       mode: 0x%02x\n",(int)resp->mode);
}
static inline void dump_mesh_node_set_adv_event_filter(struct gecko_msg_mesh_node_set_adv_event_filter_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_get_statistics(struct gecko_msg_mesh_node_get_statistics_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  statistics: %d:",(int)resp->statistics.len);
   for(int i = 0; i < resp->statistics.len; i++)
      printf("%s%02x",(i)?",":"{",resp->statistics.data[i]);
   printf("}\n");
}
static inline void dump_mesh_node_clear_statistics(struct gecko_msg_mesh_node_clear_statistics_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_set_net_relay_delay(struct gecko_msg_mesh_node_set_net_relay_delay_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_get_net_relay_delay(struct gecko_msg_mesh_node_get_net_relay_delay_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       min: 0x%02x\n",(int)resp->min);
   printf("      uint8       max: 0x%02x\n",(int)resp->max);
}
static inline void dump_mesh_node_get_ivupdate_state(struct gecko_msg_mesh_node_get_ivupdate_state_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      ivindex: 0x%08x\n",(int)resp->ivindex);
   printf("      uint8       state: 0x%02x\n",(int)resp->state);
}
static inline void dump_mesh_node_request_ivupdate(struct gecko_msg_mesh_node_request_ivupdate_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_get_seq_remaining(struct gecko_msg_mesh_node_get_seq_remaining_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      count: 0x%08x\n",(int)resp->count);
}
static inline void dump_mesh_node_save_replay_protection_list(struct gecko_msg_mesh_node_save_replay_protection_list_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_set_uuid(struct gecko_msg_mesh_node_set_uuid_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_get_element_address(struct gecko_msg_mesh_node_get_element_address_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      address: 0x%04x\n",(int)resp->address);
}
static inline void dump_mesh_node_static_oob_request_rsp(struct gecko_msg_mesh_node_static_oob_request_rsp_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_reset(struct gecko_msg_mesh_node_reset_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_node_set_beacon_reporting(struct gecko_msg_mesh_node_set_beacon_reporting_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_init(struct gecko_msg_mesh_prov_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_scan_unprov_beacons(struct gecko_msg_mesh_prov_scan_unprov_beacons_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_provision_device(struct gecko_msg_mesh_prov_provision_device_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_create_network(struct gecko_msg_mesh_prov_create_network_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       network_id: 0x%02x\n",(int)resp->network_id);
}
static inline void dump_mesh_prov_get_dcd(struct gecko_msg_mesh_prov_get_dcd_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_get_config(struct gecko_msg_mesh_prov_get_config_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_set_config(struct gecko_msg_mesh_prov_set_config_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_create_appkey(struct gecko_msg_mesh_prov_create_appkey_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      appkey_index: 0x%04x\n",(int)resp->appkey_index);
   printf("      uint8array  key: %d:",(int)resp->key.len);
   for(int i = 0; i < resp->key.len; i++)
      printf("%s%02x",(i)?",":"{",resp->key.data[i]);
   printf("}\n");
}
static inline void dump_mesh_prov_oob_pkey_rsp(struct gecko_msg_mesh_prov_oob_pkey_rsp_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_oob_auth_rsp(struct gecko_msg_mesh_prov_oob_auth_rsp_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_set_oob_requirements(struct gecko_msg_mesh_prov_set_oob_requirements_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_key_refresh_start(struct gecko_msg_mesh_prov_key_refresh_start_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_get_key_refresh_blacklist(struct gecko_msg_mesh_prov_get_key_refresh_blacklist_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       status: 0x%02x\n",(int)resp->status);
}
static inline void dump_mesh_prov_set_key_refresh_blacklist(struct gecko_msg_mesh_prov_set_key_refresh_blacklist_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_appkey_add(struct gecko_msg_mesh_prov_appkey_add_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_appkey_delete(struct gecko_msg_mesh_prov_appkey_delete_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_app_bind(struct gecko_msg_mesh_prov_model_app_bind_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_app_unbind(struct gecko_msg_mesh_prov_model_app_unbind_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_app_get(struct gecko_msg_mesh_prov_model_app_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_sub_add(struct gecko_msg_mesh_prov_model_sub_add_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_pub_set(struct gecko_msg_mesh_prov_model_pub_set_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_provision_gatt_device(struct gecko_msg_mesh_prov_provision_gatt_device_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_ddb_get(struct gecko_msg_mesh_prov_ddb_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      aes_key_128 device_key: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",resp->device_key.data[i]);
   printf("\n");
   printf("      uint16      netkey_index: 0x%04x\n",(int)resp->netkey_index);
   printf("      uint16      address: 0x%04x\n",(int)resp->address);
   printf("      uint8       elements: 0x%02x\n",(int)resp->elements);
}
static inline void dump_mesh_prov_ddb_delete(struct gecko_msg_mesh_prov_ddb_delete_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_ddb_add(struct gecko_msg_mesh_prov_ddb_add_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_ddb_list_devices(struct gecko_msg_mesh_prov_ddb_list_devices_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      count: 0x%04x\n",(int)resp->count);
}
static inline void dump_mesh_prov_network_add(struct gecko_msg_mesh_prov_network_add_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_network_delete(struct gecko_msg_mesh_prov_network_delete_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_nettx_get(struct gecko_msg_mesh_prov_nettx_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_nettx_set(struct gecko_msg_mesh_prov_nettx_set_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_sub_del(struct gecko_msg_mesh_prov_model_sub_del_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_sub_add_va(struct gecko_msg_mesh_prov_model_sub_add_va_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_sub_del_va(struct gecko_msg_mesh_prov_model_sub_del_va_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_sub_set(struct gecko_msg_mesh_prov_model_sub_set_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_sub_set_va(struct gecko_msg_mesh_prov_model_sub_set_va_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_heartbeat_publication_get(struct gecko_msg_mesh_prov_heartbeat_publication_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_heartbeat_publication_set(struct gecko_msg_mesh_prov_heartbeat_publication_set_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_heartbeat_subscription_get(struct gecko_msg_mesh_prov_heartbeat_subscription_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_heartbeat_subscription_set(struct gecko_msg_mesh_prov_heartbeat_subscription_set_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_relay_get(struct gecko_msg_mesh_prov_relay_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_relay_set(struct gecko_msg_mesh_prov_relay_set_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_reset_node(struct gecko_msg_mesh_prov_reset_node_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_appkey_get(struct gecko_msg_mesh_prov_appkey_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_network_get(struct gecko_msg_mesh_prov_network_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_sub_clear(struct gecko_msg_mesh_prov_model_sub_clear_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_pub_get(struct gecko_msg_mesh_prov_model_pub_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_pub_set_va(struct gecko_msg_mesh_prov_model_pub_set_va_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_pub_set_cred(struct gecko_msg_mesh_prov_model_pub_set_cred_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_pub_set_va_cred(struct gecko_msg_mesh_prov_model_pub_set_va_cred_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_model_sub_get(struct gecko_msg_mesh_prov_model_sub_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_friend_timeout_get(struct gecko_msg_mesh_prov_friend_timeout_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_get_default_configuration_timeout(struct gecko_msg_mesh_prov_get_default_configuration_timeout_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      timeout: 0x%08x\n",(int)resp->timeout);
   printf("      uint32      lpn_timeout: 0x%08x\n",(int)resp->lpn_timeout);
}
static inline void dump_mesh_prov_set_default_configuration_timeout(struct gecko_msg_mesh_prov_set_default_configuration_timeout_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_provision_device_with_address(struct gecko_msg_mesh_prov_provision_device_with_address_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_provision_gatt_device_with_address(struct gecko_msg_mesh_prov_provision_gatt_device_with_address_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_initialize_network(struct gecko_msg_mesh_prov_initialize_network_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_get_key_refresh_appkey_blacklist(struct gecko_msg_mesh_prov_get_key_refresh_appkey_blacklist_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       status: 0x%02x\n",(int)resp->status);
}
static inline void dump_mesh_prov_set_key_refresh_appkey_blacklist(struct gecko_msg_mesh_prov_set_key_refresh_appkey_blacklist_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_stop_scan_unprov_beacons(struct gecko_msg_mesh_prov_stop_scan_unprov_beacons_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_ddb_update_netkey_index(struct gecko_msg_mesh_prov_ddb_update_netkey_index_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_key_refresh_suspend(struct gecko_msg_mesh_prov_key_refresh_suspend_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_key_refresh_resume(struct gecko_msg_mesh_prov_key_refresh_resume_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_get_key_refresh_phase(struct gecko_msg_mesh_prov_get_key_refresh_phase_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       phase: 0x%02x\n",(int)resp->phase);
}
static inline void dump_mesh_prov_key_refresh_start_from_phase(struct gecko_msg_mesh_prov_key_refresh_start_from_phase_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_prov_flush_key_refresh_state(struct gecko_msg_mesh_prov_flush_key_refresh_state_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_proxy_connect(struct gecko_msg_mesh_proxy_connect_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_proxy_disconnect(struct gecko_msg_mesh_proxy_disconnect_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_proxy_set_filter_type(struct gecko_msg_mesh_proxy_set_filter_type_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_proxy_allow(struct gecko_msg_mesh_proxy_allow_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_proxy_deny(struct gecko_msg_mesh_proxy_deny_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_vendor_model_send(struct gecko_msg_mesh_vendor_model_send_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_vendor_model_set_publication(struct gecko_msg_mesh_vendor_model_set_publication_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_vendor_model_clear_publication(struct gecko_msg_mesh_vendor_model_clear_publication_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_vendor_model_publish(struct gecko_msg_mesh_vendor_model_publish_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_vendor_model_init(struct gecko_msg_mesh_vendor_model_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_vendor_model_deinit(struct gecko_msg_mesh_vendor_model_deinit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_health_client_get(struct gecko_msg_mesh_health_client_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_health_client_clear(struct gecko_msg_mesh_health_client_clear_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_health_client_test(struct gecko_msg_mesh_health_client_test_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_health_client_get_period(struct gecko_msg_mesh_health_client_get_period_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_health_client_set_period(struct gecko_msg_mesh_health_client_set_period_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_health_client_get_attention(struct gecko_msg_mesh_health_client_get_attention_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_health_client_set_attention(struct gecko_msg_mesh_health_client_set_attention_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_health_server_set_fault(struct gecko_msg_mesh_health_server_set_fault_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_health_server_clear_fault(struct gecko_msg_mesh_health_server_clear_fault_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_health_server_test_response(struct gecko_msg_mesh_health_server_test_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_get(struct gecko_msg_mesh_generic_client_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_set(struct gecko_msg_mesh_generic_client_set_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_publish(struct gecko_msg_mesh_generic_client_publish_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_get_params(struct gecko_msg_mesh_generic_client_get_params_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init(struct gecko_msg_mesh_generic_client_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init_common(struct gecko_msg_mesh_generic_client_init_common_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init_on_off(struct gecko_msg_mesh_generic_client_init_on_off_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init_level(struct gecko_msg_mesh_generic_client_init_level_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init_default_transition_time(struct gecko_msg_mesh_generic_client_init_default_transition_time_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init_power_on_off(struct gecko_msg_mesh_generic_client_init_power_on_off_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init_power_level(struct gecko_msg_mesh_generic_client_init_power_level_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init_battery(struct gecko_msg_mesh_generic_client_init_battery_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init_location(struct gecko_msg_mesh_generic_client_init_location_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init_property(struct gecko_msg_mesh_generic_client_init_property_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init_lightness(struct gecko_msg_mesh_generic_client_init_lightness_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_client_init_ctl(struct gecko_msg_mesh_generic_client_init_ctl_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_response(struct gecko_msg_mesh_generic_server_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_update(struct gecko_msg_mesh_generic_server_update_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_publish(struct gecko_msg_mesh_generic_server_publish_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init(struct gecko_msg_mesh_generic_server_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init_common(struct gecko_msg_mesh_generic_server_init_common_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init_on_off(struct gecko_msg_mesh_generic_server_init_on_off_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init_level(struct gecko_msg_mesh_generic_server_init_level_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init_default_transition_time(struct gecko_msg_mesh_generic_server_init_default_transition_time_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init_power_on_off(struct gecko_msg_mesh_generic_server_init_power_on_off_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init_power_level(struct gecko_msg_mesh_generic_server_init_power_level_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init_battery(struct gecko_msg_mesh_generic_server_init_battery_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init_location(struct gecko_msg_mesh_generic_server_init_location_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init_property(struct gecko_msg_mesh_generic_server_init_property_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init_lightness(struct gecko_msg_mesh_generic_server_init_lightness_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_generic_server_init_ctl(struct gecko_msg_mesh_generic_server_init_ctl_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_coex_set_options(struct gecko_msg_coex_set_options_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_coex_get_counters(struct gecko_msg_coex_get_counters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  counters: %d:",(int)resp->counters.len);
   for(int i = 0; i < resp->counters.len; i++)
      printf("%s%02x",(i)?",":"{",resp->counters.data[i]);
   printf("}\n");
}
static inline void dump_coex_set_parameters(struct gecko_msg_coex_set_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_coex_set_directional_priority_pulse(struct gecko_msg_coex_set_directional_priority_pulse_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_get_nettx(struct gecko_msg_mesh_test_get_nettx_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       count: 0x%02x\n",(int)resp->count);
   printf("      uint8       interval: 0x%02x\n",(int)resp->interval);
}
static inline void dump_mesh_test_set_nettx(struct gecko_msg_mesh_test_set_nettx_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_get_relay(struct gecko_msg_mesh_test_get_relay_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       enabled: 0x%02x\n",(int)resp->enabled);
   printf("      uint8       count: 0x%02x\n",(int)resp->count);
   printf("      uint8       interval: 0x%02x\n",(int)resp->interval);
}
static inline void dump_mesh_test_set_relay(struct gecko_msg_mesh_test_set_relay_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_set_adv_scan_params(struct gecko_msg_mesh_test_set_adv_scan_params_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_set_ivupdate_test_mode(struct gecko_msg_mesh_test_set_ivupdate_test_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_get_ivupdate_test_mode(struct gecko_msg_mesh_test_get_ivupdate_test_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       mode: 0x%02x\n",(int)resp->mode);
}
static inline void dump_mesh_test_set_segment_send_delay(struct gecko_msg_mesh_test_set_segment_send_delay_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_set_ivupdate_state(struct gecko_msg_mesh_test_set_ivupdate_state_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_send_beacons(struct gecko_msg_mesh_test_send_beacons_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_bind_local_model_app(struct gecko_msg_mesh_test_bind_local_model_app_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_unbind_local_model_app(struct gecko_msg_mesh_test_unbind_local_model_app_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_add_local_model_sub(struct gecko_msg_mesh_test_add_local_model_sub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_del_local_model_sub(struct gecko_msg_mesh_test_del_local_model_sub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_add_local_model_sub_va(struct gecko_msg_mesh_test_add_local_model_sub_va_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_del_local_model_sub_va(struct gecko_msg_mesh_test_del_local_model_sub_va_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_get_local_model_sub(struct gecko_msg_mesh_test_get_local_model_sub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  addresses: %d:",(int)resp->addresses.len);
   for(int i = 0; i < resp->addresses.len; i++)
      printf("%s%02x",(i)?",":"{",resp->addresses.data[i]);
   printf("}\n");
}
static inline void dump_mesh_test_set_local_model_pub(struct gecko_msg_mesh_test_set_local_model_pub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_set_local_model_pub_va(struct gecko_msg_mesh_test_set_local_model_pub_va_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_get_local_model_pub(struct gecko_msg_mesh_test_get_local_model_pub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      appkey_index: 0x%04x\n",(int)resp->appkey_index);
   printf("      uint16      pub_address: 0x%04x\n",(int)resp->pub_address);
   printf("      uint8       ttl: 0x%02x\n",(int)resp->ttl);
   printf("      uint8       period: 0x%02x\n",(int)resp->period);
   printf("      uint8       retrans: 0x%02x\n",(int)resp->retrans);
   printf("      uint8       credentials: 0x%02x\n",(int)resp->credentials);
}
static inline void dump_mesh_test_set_local_heartbeat_subscription(struct gecko_msg_mesh_test_set_local_heartbeat_subscription_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_get_local_heartbeat_subscription(struct gecko_msg_mesh_test_get_local_heartbeat_subscription_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      count: 0x%04x\n",(int)resp->count);
   printf("      uint8       hop_min: 0x%02x\n",(int)resp->hop_min);
   printf("      uint8       hop_max: 0x%02x\n",(int)resp->hop_max);
}
static inline void dump_mesh_test_get_local_heartbeat_publication(struct gecko_msg_mesh_test_get_local_heartbeat_publication_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      publication_address: 0x%04x\n",(int)resp->publication_address);
   printf("      uint8       count: 0x%02x\n",(int)resp->count);
   printf("      uint8       period_log: 0x%02x\n",(int)resp->period_log);
   printf("      uint8       ttl: 0x%02x\n",(int)resp->ttl);
   printf("      uint16      features: 0x%04x\n",(int)resp->features);
   printf("      uint16      publication_netkey_index: 0x%04x\n",(int)resp->publication_netkey_index);
}
static inline void dump_mesh_test_set_local_heartbeat_publication(struct gecko_msg_mesh_test_set_local_heartbeat_publication_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_set_local_config(struct gecko_msg_mesh_test_set_local_config_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_get_local_config(struct gecko_msg_mesh_test_get_local_config_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  data: %d:",(int)resp->data.len);
   for(int i = 0; i < resp->data.len; i++)
      printf("%s%02x",(i)?",":"{",resp->data.data[i]);
   printf("}\n");
}
static inline void dump_mesh_test_add_local_key(struct gecko_msg_mesh_test_add_local_key_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_del_local_key(struct gecko_msg_mesh_test_del_local_key_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_update_local_key(struct gecko_msg_mesh_test_update_local_key_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_set_sar_config(struct gecko_msg_mesh_test_set_sar_config_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_get_element_seqnum(struct gecko_msg_mesh_test_get_element_seqnum_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      seqnum: 0x%08x\n",(int)resp->seqnum);
}
static inline void dump_mesh_test_set_adv_bearer_state(struct gecko_msg_mesh_test_set_adv_bearer_state_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_get_key_count(struct gecko_msg_mesh_test_get_key_count_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      count: 0x%08x\n",(int)resp->count);
}
static inline void dump_mesh_test_get_key(struct gecko_msg_mesh_test_get_key_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      id: 0x%04x\n",(int)resp->id);
   printf("      uint16      network: 0x%04x\n",(int)resp->network);
   printf("      aes_key_128 key: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",resp->key.data[i]);
   printf("\n");
}
static inline void dump_mesh_test_prov_get_device_key(struct gecko_msg_mesh_test_prov_get_device_key_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      aes_key_128 device_key: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",resp->device_key.data[i]);
   printf("\n");
}
static inline void dump_mesh_test_prov_prepare_key_refresh(struct gecko_msg_mesh_test_prov_prepare_key_refresh_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_cancel_segmented_tx(struct gecko_msg_mesh_test_cancel_segmented_tx_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_set_iv_index(struct gecko_msg_mesh_test_set_iv_index_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_set_element_seqnum(struct gecko_msg_mesh_test_set_element_seqnum_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_set_model_option(struct gecko_msg_mesh_test_set_model_option_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_test_get_local_model_app_bindings(struct gecko_msg_mesh_test_get_local_model_app_bindings_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  appkeys: %d:",(int)resp->appkeys.len);
   for(int i = 0; i < resp->appkeys.len; i++)
      printf("%s%02x",(i)?",":"{",resp->appkeys.data[i]);
   printf("}\n");
}
static inline void dump_mesh_lpn_init(struct gecko_msg_mesh_lpn_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lpn_deinit(struct gecko_msg_mesh_lpn_deinit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lpn_configure(struct gecko_msg_mesh_lpn_configure_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lpn_establish_friendship(struct gecko_msg_mesh_lpn_establish_friendship_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lpn_poll(struct gecko_msg_mesh_lpn_poll_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lpn_terminate_friendship(struct gecko_msg_mesh_lpn_terminate_friendship_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lpn_config(struct gecko_msg_mesh_lpn_config_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_friend_init(struct gecko_msg_mesh_friend_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_friend_deinit(struct gecko_msg_mesh_friend_deinit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_config_client_cancel_request(struct gecko_msg_mesh_config_client_cancel_request_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_config_client_get_request_status(struct gecko_msg_mesh_config_client_get_request_status_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      server_address: 0x%04x\n",(int)resp->server_address);
   printf("      uint16      opcode: 0x%04x\n",(int)resp->opcode);
   printf("      uint32      age: 0x%08x\n",(int)resp->age);
   printf("      uint32      remaining: 0x%08x\n",(int)resp->remaining);
   printf("      uint8       friend_acked: 0x%02x\n",(int)resp->friend_acked);
}
static inline void dump_mesh_config_client_get_default_timeout(struct gecko_msg_mesh_config_client_get_default_timeout_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      timeout_ms: 0x%08x\n",(int)resp->timeout_ms);
   printf("      uint32      lpn_timeout_ms: 0x%08x\n",(int)resp->lpn_timeout_ms);
}
static inline void dump_mesh_config_client_set_default_timeout(struct gecko_msg_mesh_config_client_set_default_timeout_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_config_client_add_netkey(struct gecko_msg_mesh_config_client_add_netkey_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_remove_netkey(struct gecko_msg_mesh_config_client_remove_netkey_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_list_netkeys(struct gecko_msg_mesh_config_client_list_netkeys_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_add_appkey(struct gecko_msg_mesh_config_client_add_appkey_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_remove_appkey(struct gecko_msg_mesh_config_client_remove_appkey_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_list_appkeys(struct gecko_msg_mesh_config_client_list_appkeys_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_bind_model(struct gecko_msg_mesh_config_client_bind_model_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_unbind_model(struct gecko_msg_mesh_config_client_unbind_model_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_list_bindings(struct gecko_msg_mesh_config_client_list_bindings_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_model_pub(struct gecko_msg_mesh_config_client_get_model_pub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_model_pub(struct gecko_msg_mesh_config_client_set_model_pub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_model_pub_va(struct gecko_msg_mesh_config_client_set_model_pub_va_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_add_model_sub(struct gecko_msg_mesh_config_client_add_model_sub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_add_model_sub_va(struct gecko_msg_mesh_config_client_add_model_sub_va_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_remove_model_sub(struct gecko_msg_mesh_config_client_remove_model_sub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_remove_model_sub_va(struct gecko_msg_mesh_config_client_remove_model_sub_va_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_model_sub(struct gecko_msg_mesh_config_client_set_model_sub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_model_sub_va(struct gecko_msg_mesh_config_client_set_model_sub_va_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_clear_model_sub(struct gecko_msg_mesh_config_client_clear_model_sub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_list_subs(struct gecko_msg_mesh_config_client_list_subs_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_heartbeat_pub(struct gecko_msg_mesh_config_client_get_heartbeat_pub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_heartbeat_pub(struct gecko_msg_mesh_config_client_set_heartbeat_pub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_heartbeat_sub(struct gecko_msg_mesh_config_client_get_heartbeat_sub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_heartbeat_sub(struct gecko_msg_mesh_config_client_set_heartbeat_sub_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_beacon(struct gecko_msg_mesh_config_client_get_beacon_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_beacon(struct gecko_msg_mesh_config_client_set_beacon_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_default_ttl(struct gecko_msg_mesh_config_client_get_default_ttl_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_default_ttl(struct gecko_msg_mesh_config_client_set_default_ttl_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_gatt_proxy(struct gecko_msg_mesh_config_client_get_gatt_proxy_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_gatt_proxy(struct gecko_msg_mesh_config_client_set_gatt_proxy_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_relay(struct gecko_msg_mesh_config_client_get_relay_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_relay(struct gecko_msg_mesh_config_client_set_relay_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_network_transmit(struct gecko_msg_mesh_config_client_get_network_transmit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_network_transmit(struct gecko_msg_mesh_config_client_set_network_transmit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_identity(struct gecko_msg_mesh_config_client_get_identity_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_identity(struct gecko_msg_mesh_config_client_set_identity_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_friend(struct gecko_msg_mesh_config_client_get_friend_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_set_friend(struct gecko_msg_mesh_config_client_set_friend_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_lpn_polltimeout(struct gecko_msg_mesh_config_client_get_lpn_polltimeout_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_get_dcd(struct gecko_msg_mesh_config_client_get_dcd_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_mesh_config_client_reset_node(struct gecko_msg_mesh_config_client_reset_node_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint32      handle: 0x%08x\n",(int)resp->handle);
}
static inline void dump_l2cap_coc_send_connection_request(struct gecko_msg_l2cap_coc_send_connection_request_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_l2cap_coc_send_connection_response(struct gecko_msg_l2cap_coc_send_connection_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_l2cap_coc_send_le_flow_control_credit(struct gecko_msg_l2cap_coc_send_le_flow_control_credit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_l2cap_coc_send_disconnection_request(struct gecko_msg_l2cap_coc_send_disconnection_request_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_l2cap_coc_send_data(struct gecko_msg_l2cap_coc_send_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_enable_cte_response(struct gecko_msg_cte_transmitter_enable_cte_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_disable_cte_response(struct gecko_msg_cte_transmitter_disable_cte_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_start_connectionless_cte(struct gecko_msg_cte_transmitter_start_connectionless_cte_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_stop_connectionless_cte(struct gecko_msg_cte_transmitter_stop_connectionless_cte_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_set_dtm_parameters(struct gecko_msg_cte_transmitter_set_dtm_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_clear_dtm_parameters(struct gecko_msg_cte_transmitter_clear_dtm_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_configure(struct gecko_msg_cte_receiver_configure_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_start_iq_sampling(struct gecko_msg_cte_receiver_start_iq_sampling_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_stop_iq_sampling(struct gecko_msg_cte_receiver_stop_iq_sampling_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_start_connectionless_iq_sampling(struct gecko_msg_cte_receiver_start_connectionless_iq_sampling_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_stop_connectionless_iq_sampling(struct gecko_msg_cte_receiver_stop_connectionless_iq_sampling_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_set_dtm_parameters(struct gecko_msg_cte_receiver_set_dtm_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_clear_dtm_parameters(struct gecko_msg_cte_receiver_clear_dtm_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_server_init(struct gecko_msg_mesh_sensor_server_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_server_deinit(struct gecko_msg_mesh_sensor_server_deinit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_server_send_descriptor_status(struct gecko_msg_mesh_sensor_server_send_descriptor_status_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_server_send_status(struct gecko_msg_mesh_sensor_server_send_status_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_server_send_column_status(struct gecko_msg_mesh_sensor_server_send_column_status_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_server_send_series_status(struct gecko_msg_mesh_sensor_server_send_series_status_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_setup_server_send_cadence_status(struct gecko_msg_mesh_sensor_setup_server_send_cadence_status_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_setup_server_send_settings_status(struct gecko_msg_mesh_sensor_setup_server_send_settings_status_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_setup_server_send_setting_status(struct gecko_msg_mesh_sensor_setup_server_send_setting_status_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_client_init(struct gecko_msg_mesh_sensor_client_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_client_deinit(struct gecko_msg_mesh_sensor_client_deinit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_client_get_descriptor(struct gecko_msg_mesh_sensor_client_get_descriptor_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_client_get(struct gecko_msg_mesh_sensor_client_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_client_get_column(struct gecko_msg_mesh_sensor_client_get_column_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_client_get_series(struct gecko_msg_mesh_sensor_client_get_series_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_client_get_cadence(struct gecko_msg_mesh_sensor_client_get_cadence_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_client_set_cadence(struct gecko_msg_mesh_sensor_client_set_cadence_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_client_get_settings(struct gecko_msg_mesh_sensor_client_get_settings_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_client_get_setting(struct gecko_msg_mesh_sensor_client_get_setting_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_sensor_client_set_setting(struct gecko_msg_mesh_sensor_client_set_setting_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_client_init(struct gecko_msg_mesh_lc_client_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_client_get_mode(struct gecko_msg_mesh_lc_client_get_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_client_set_mode(struct gecko_msg_mesh_lc_client_set_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_client_get_om(struct gecko_msg_mesh_lc_client_get_om_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_client_set_om(struct gecko_msg_mesh_lc_client_set_om_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_client_get_light_onoff(struct gecko_msg_mesh_lc_client_get_light_onoff_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_client_set_light_onoff(struct gecko_msg_mesh_lc_client_set_light_onoff_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_client_get_property(struct gecko_msg_mesh_lc_client_get_property_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_client_set_property(struct gecko_msg_mesh_lc_client_set_property_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_server_init(struct gecko_msg_mesh_lc_server_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_server_deinit(struct gecko_msg_mesh_lc_server_deinit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_server_update_mode(struct gecko_msg_mesh_lc_server_update_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_server_update_om(struct gecko_msg_mesh_lc_server_update_om_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_server_update_light_onoff(struct gecko_msg_mesh_lc_server_update_light_onoff_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_server_init_all_properties(struct gecko_msg_mesh_lc_server_init_all_properties_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_server_set_publish_mask(struct gecko_msg_mesh_lc_server_set_publish_mask_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_server_set_regulator_interval(struct gecko_msg_mesh_lc_server_set_regulator_interval_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_server_set_event_mask(struct gecko_msg_mesh_lc_server_set_event_mask_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_lc_server_get_lc_state(struct gecko_msg_mesh_lc_server_get_lc_state_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       state: 0x%02x\n",(int)resp->state);
   printf("      uint32      transition_time: 0x%08x\n",(int)resp->transition_time);
}
static inline void dump_mesh_lc_setup_server_update_property(struct gecko_msg_mesh_lc_setup_server_update_property_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_scene_client_init(struct gecko_msg_mesh_scene_client_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_scene_client_get(struct gecko_msg_mesh_scene_client_get_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_scene_client_get_register(struct gecko_msg_mesh_scene_client_get_register_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_scene_client_recall(struct gecko_msg_mesh_scene_client_recall_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_scene_client_store(struct gecko_msg_mesh_scene_client_store_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_scene_client_delete(struct gecko_msg_mesh_scene_client_delete_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_scene_server_init(struct gecko_msg_mesh_scene_server_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_scene_server_deinit(struct gecko_msg_mesh_scene_server_deinit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_scene_setup_server_init(struct gecko_msg_mesh_scene_setup_server_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_server_init(struct gecko_msg_mesh_time_server_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_server_deinit(struct gecko_msg_mesh_time_server_deinit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_server_get_time(struct gecko_msg_mesh_time_server_get_time_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       subsecond: 0x%02x\n",(int)resp->subsecond);
   printf("      uint8       uncertainty: 0x%02x\n",(int)resp->uncertainty);
   printf("      uint8       time_authority: 0x%02x\n",(int)resp->time_authority);
   printf("      int16 time_zone_offset: 0x%d\n",(int)resp->time_zone_offset);
   printf("      int32 tai_utc_delta: 0x%d\n",(int)resp->tai_utc_delta);
}
static inline void dump_mesh_time_server_set_time(struct gecko_msg_mesh_time_server_set_time_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_server_get_time_zone_offset_new(struct gecko_msg_mesh_time_server_get_time_zone_offset_new_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      int16 new_offset: 0x%d\n",(int)resp->new_offset);
}
static inline void dump_mesh_time_server_set_time_zone_offset_new(struct gecko_msg_mesh_time_server_set_time_zone_offset_new_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_server_get_tai_utc_delta_new(struct gecko_msg_mesh_time_server_get_tai_utc_delta_new_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      int32 new_delta: 0x%d\n",(int)resp->new_delta);
}
static inline void dump_mesh_time_server_set_tai_utc_delta_new(struct gecko_msg_mesh_time_server_set_tai_utc_delta_new_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_server_get_time_role(struct gecko_msg_mesh_time_server_get_time_role_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       time_role: 0x%02x\n",(int)resp->time_role);
}
static inline void dump_mesh_time_server_set_time_role(struct gecko_msg_mesh_time_server_set_time_role_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_server_get_datetime(struct gecko_msg_mesh_time_server_get_datetime_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      year: 0x%04x\n",(int)resp->year);
   printf("      uint8       month: 0x%02x\n",(int)resp->month);
   printf("      uint8       day: 0x%02x\n",(int)resp->day);
   printf("      uint8       hour: 0x%02x\n",(int)resp->hour);
   printf("      uint8       min: 0x%02x\n",(int)resp->min);
   printf("      uint8       sec: 0x%02x\n",(int)resp->sec);
   printf("      uint16      msec: 0x%04x\n",(int)resp->msec);
   printf("      uint16      timezone: 0x%04x\n",(int)resp->timezone);
   printf("      uint8       day_of_week: 0x%02x\n",(int)resp->day_of_week);
}
static inline void dump_mesh_time_client_init(struct gecko_msg_mesh_time_client_init_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_client_deinit(struct gecko_msg_mesh_time_client_deinit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_client_get_time(struct gecko_msg_mesh_time_client_get_time_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_client_set_time(struct gecko_msg_mesh_time_client_set_time_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_client_get_time_zone(struct gecko_msg_mesh_time_client_get_time_zone_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_client_set_time_zone(struct gecko_msg_mesh_time_client_set_time_zone_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_client_get_tai_utc_delta(struct gecko_msg_mesh_time_client_get_tai_utc_delta_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_client_set_tai_utc_delta(struct gecko_msg_mesh_time_client_set_tai_utc_delta_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_client_get_time_role(struct gecko_msg_mesh_time_client_get_time_role_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_mesh_time_client_set_time_role(struct gecko_msg_mesh_time_client_set_time_role_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_user_message_to_target(struct gecko_msg_user_message_to_target_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  data: %d:",(int)resp->data.len);
   for(int i = 0; i < resp->data.len; i++)
      printf("%s%02x",(i)?",":"{",resp->data.data[i]);
   printf("}\n");
}
static inline struct gecko_msg_dfu_flash_set_address_rsp_t* cmd_dfu_flash_set_address(uint32 address) {
  dump_command_header("dfu_flash_set_address");
  printf("  uint32 address: 0x%08x\n",(int)address);
  struct gecko_msg_dfu_flash_set_address_rsp_t* resp = gecko_cmd_dfu_flash_set_address(address);
  printf("    RETURNED\n");
  dump_dfu_flash_set_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_dfu_flash_upload_rsp_t* cmd_dfu_flash_upload(uint8 data_len, const uint8* data_data) {
  dump_command_header("dfu_flash_upload");
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_dfu_flash_upload_rsp_t* resp = gecko_cmd_dfu_flash_upload(data_len,data_data);
  printf("    RETURNED\n");
  dump_dfu_flash_upload(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_dfu_flash_upload_finish_rsp_t* cmd_dfu_flash_upload_finish() {
  dump_command_header("dfu_flash_upload_finish");
  struct gecko_msg_dfu_flash_upload_finish_rsp_t* resp = gecko_cmd_dfu_flash_upload_finish();
  printf("    RETURNED\n");
  dump_dfu_flash_upload_finish(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_hello_rsp_t* cmd_system_hello() {
  dump_command_header("system_hello");
  struct gecko_msg_system_hello_rsp_t* resp = gecko_cmd_system_hello();
  printf("    RETURNED\n");
  dump_system_hello(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_get_bt_address_rsp_t* cmd_system_get_bt_address() {
  dump_command_header("system_get_bt_address");
  struct gecko_msg_system_get_bt_address_rsp_t* resp = gecko_cmd_system_get_bt_address();
  printf("    RETURNED\n");
  dump_system_get_bt_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_set_bt_address_rsp_t* cmd_system_set_bt_address(bd_addr address) {
  dump_command_header("system_set_bt_address");
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  struct gecko_msg_system_set_bt_address_rsp_t* resp = gecko_cmd_system_set_bt_address(address);
  printf("    RETURNED\n");
  dump_system_set_bt_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_set_tx_power_rsp_t* cmd_system_set_tx_power(int16 power) {
  dump_command_header("system_set_tx_power");
  printf("  int16 power: 0x%04x\n",(int)power);
  struct gecko_msg_system_set_tx_power_rsp_t* resp = gecko_cmd_system_set_tx_power(power);
  printf("    RETURNED\n");
  dump_system_set_tx_power(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_get_random_data_rsp_t* cmd_system_get_random_data(uint8 length) {
  dump_command_header("system_get_random_data");
  printf("  uint8 length: 0x%02x\n",(int)length);
  struct gecko_msg_system_get_random_data_rsp_t* resp = gecko_cmd_system_get_random_data(length);
  printf("    RETURNED\n");
  dump_system_get_random_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_halt_rsp_t* cmd_system_halt(uint8 halt) {
  dump_command_header("system_halt");
  printf("  uint8 halt: 0x%02x\n",(int)halt);
  struct gecko_msg_system_halt_rsp_t* resp = gecko_cmd_system_halt(halt);
  printf("    RETURNED\n");
  dump_system_halt(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_set_device_name_rsp_t* cmd_system_set_device_name(uint8 type,uint8 name_len, const uint8* name_data) {
  dump_command_header("system_set_device_name");
  printf("  uint8 type: 0x%02x\n",(int)type);
  printf("  uint8 name_len: 0x%02x\n",(int)name_len);
  printf("  const uint8* name_data: 0x%p\n",name_data);
  struct gecko_msg_system_set_device_name_rsp_t* resp = gecko_cmd_system_set_device_name(type,name_len,name_data);
  printf("    RETURNED\n");
  dump_system_set_device_name(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_linklayer_configure_rsp_t* cmd_system_linklayer_configure(uint8 key,uint8 data_len, const uint8* data_data) {
  dump_command_header("system_linklayer_configure");
  printf("  uint8 key: 0x%02x\n",(int)key);
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_system_linklayer_configure_rsp_t* resp = gecko_cmd_system_linklayer_configure(key,data_len,data_data);
  printf("    RETURNED\n");
  dump_system_linklayer_configure(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_get_counters_rsp_t* cmd_system_get_counters(uint8 reset) {
  dump_command_header("system_get_counters");
  printf("  uint8 reset: 0x%02x\n",(int)reset);
  struct gecko_msg_system_get_counters_rsp_t* resp = gecko_cmd_system_get_counters(reset);
  printf("    RETURNED\n");
  dump_system_get_counters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_data_buffer_write_rsp_t* cmd_system_data_buffer_write(uint8 data_len, const uint8* data_data) {
  dump_command_header("system_data_buffer_write");
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_system_data_buffer_write_rsp_t* resp = gecko_cmd_system_data_buffer_write(data_len,data_data);
  printf("    RETURNED\n");
  dump_system_data_buffer_write(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_set_identity_address_rsp_t* cmd_system_set_identity_address(bd_addr address,uint8 type) {
  dump_command_header("system_set_identity_address");
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  printf("  uint8 type: 0x%02x\n",(int)type);
  struct gecko_msg_system_set_identity_address_rsp_t* resp = gecko_cmd_system_set_identity_address(address,type);
  printf("    RETURNED\n");
  dump_system_set_identity_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_data_buffer_clear_rsp_t* cmd_system_data_buffer_clear() {
  dump_command_header("system_data_buffer_clear");
  struct gecko_msg_system_data_buffer_clear_rsp_t* resp = gecko_cmd_system_data_buffer_clear();
  printf("    RETURNED\n");
  dump_system_data_buffer_clear(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_open_rsp_t* cmd_le_gap_open(bd_addr address,uint8 address_type) {
  dump_command_header("le_gap_open");
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  printf("  uint8 address_type: 0x%02x\n",(int)address_type);
  struct gecko_msg_le_gap_open_rsp_t* resp = gecko_cmd_le_gap_open(address,address_type);
  printf("    RETURNED\n");
  dump_le_gap_open(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_mode_rsp_t* cmd_le_gap_set_mode(uint8 discover,uint8 connect) {
  dump_command_header("le_gap_set_mode");
  printf("  uint8 discover: 0x%02x\n",(int)discover);
  printf("  uint8 connect: 0x%02x\n",(int)connect);
  struct gecko_msg_le_gap_set_mode_rsp_t* resp = gecko_cmd_le_gap_set_mode(discover,connect);
  printf("    RETURNED\n");
  dump_le_gap_set_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_discover_rsp_t* cmd_le_gap_discover(uint8 mode) {
  dump_command_header("le_gap_discover");
  printf("  uint8 mode: 0x%02x\n",(int)mode);
  struct gecko_msg_le_gap_discover_rsp_t* resp = gecko_cmd_le_gap_discover(mode);
  printf("    RETURNED\n");
  dump_le_gap_discover(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_end_procedure_rsp_t* cmd_le_gap_end_procedure() {
  dump_command_header("le_gap_end_procedure");
  struct gecko_msg_le_gap_end_procedure_rsp_t* resp = gecko_cmd_le_gap_end_procedure();
  printf("    RETURNED\n");
  dump_le_gap_end_procedure(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_adv_parameters_rsp_t* cmd_le_gap_set_adv_parameters(uint16 interval_min,uint16 interval_max,uint8 channel_map) {
  dump_command_header("le_gap_set_adv_parameters");
  printf("  uint16 interval_min: 0x%04x\n",(int)interval_min);
  printf("  uint16 interval_max: 0x%04x\n",(int)interval_max);
  printf("  uint8 channel_map: 0x%02x\n",(int)channel_map);
  struct gecko_msg_le_gap_set_adv_parameters_rsp_t* resp = gecko_cmd_le_gap_set_adv_parameters(interval_min,interval_max,channel_map);
  printf("    RETURNED\n");
  dump_le_gap_set_adv_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_conn_parameters_rsp_t* cmd_le_gap_set_conn_parameters(uint16 min_interval,uint16 max_interval,uint16 latency,uint16 timeout) {
  dump_command_header("le_gap_set_conn_parameters");
  printf("  uint16 min_interval: 0x%04x\n",(int)min_interval);
  printf("  uint16 max_interval: 0x%04x\n",(int)max_interval);
  printf("  uint16 latency: 0x%04x\n",(int)latency);
  printf("  uint16 timeout: 0x%04x\n",(int)timeout);
  struct gecko_msg_le_gap_set_conn_parameters_rsp_t* resp = gecko_cmd_le_gap_set_conn_parameters(min_interval,max_interval,latency,timeout);
  printf("    RETURNED\n");
  dump_le_gap_set_conn_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_scan_parameters_rsp_t* cmd_le_gap_set_scan_parameters(uint16 scan_interval,uint16 scan_window,uint8 active) {
  dump_command_header("le_gap_set_scan_parameters");
  printf("  uint16 scan_interval: 0x%04x\n",(int)scan_interval);
  printf("  uint16 scan_window: 0x%04x\n",(int)scan_window);
  printf("  uint8 active: 0x%02x\n",(int)active);
  struct gecko_msg_le_gap_set_scan_parameters_rsp_t* resp = gecko_cmd_le_gap_set_scan_parameters(scan_interval,scan_window,active);
  printf("    RETURNED\n");
  dump_le_gap_set_scan_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_adv_data_rsp_t* cmd_le_gap_set_adv_data(uint8 scan_rsp,uint8 adv_data_len, const uint8* adv_data_data) {
  dump_command_header("le_gap_set_adv_data");
  printf("  uint8 scan_rsp: 0x%02x\n",(int)scan_rsp);
  printf("  uint8 adv_data_len: 0x%02x\n",(int)adv_data_len);
  printf("  const uint8* adv_data_data: 0x%p\n",adv_data_data);
  struct gecko_msg_le_gap_set_adv_data_rsp_t* resp = gecko_cmd_le_gap_set_adv_data(scan_rsp,adv_data_len,adv_data_data);
  printf("    RETURNED\n");
  dump_le_gap_set_adv_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_adv_timeout_rsp_t* cmd_le_gap_set_adv_timeout(uint8 maxevents) {
  dump_command_header("le_gap_set_adv_timeout");
  printf("  uint8 maxevents: 0x%02x\n",(int)maxevents);
  struct gecko_msg_le_gap_set_adv_timeout_rsp_t* resp = gecko_cmd_le_gap_set_adv_timeout(maxevents);
  printf("    RETURNED\n");
  dump_le_gap_set_adv_timeout(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_conn_phy_rsp_t* cmd_le_gap_set_conn_phy(uint8 preferred_phy,uint8 accepted_phy) {
  dump_command_header("le_gap_set_conn_phy");
  printf("  uint8 preferred_phy: 0x%02x\n",(int)preferred_phy);
  printf("  uint8 accepted_phy: 0x%02x\n",(int)accepted_phy);
  struct gecko_msg_le_gap_set_conn_phy_rsp_t* resp = gecko_cmd_le_gap_set_conn_phy(preferred_phy,accepted_phy);
  printf("    RETURNED\n");
  dump_le_gap_set_conn_phy(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_bt5_set_mode_rsp_t* cmd_le_gap_bt5_set_mode(uint8 handle,uint8 discover,uint8 connect,uint16 maxevents,uint8 address_type) {
  dump_command_header("le_gap_bt5_set_mode");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 discover: 0x%02x\n",(int)discover);
  printf("  uint8 connect: 0x%02x\n",(int)connect);
  printf("  uint16 maxevents: 0x%04x\n",(int)maxevents);
  printf("  uint8 address_type: 0x%02x\n",(int)address_type);
  struct gecko_msg_le_gap_bt5_set_mode_rsp_t* resp = gecko_cmd_le_gap_bt5_set_mode(handle,discover,connect,maxevents,address_type);
  printf("    RETURNED\n");
  dump_le_gap_bt5_set_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_bt5_set_adv_parameters_rsp_t* cmd_le_gap_bt5_set_adv_parameters(uint8 handle,uint16 interval_min,uint16 interval_max,uint8 channel_map,uint8 report_scan) {
  dump_command_header("le_gap_bt5_set_adv_parameters");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint16 interval_min: 0x%04x\n",(int)interval_min);
  printf("  uint16 interval_max: 0x%04x\n",(int)interval_max);
  printf("  uint8 channel_map: 0x%02x\n",(int)channel_map);
  printf("  uint8 report_scan: 0x%02x\n",(int)report_scan);
  struct gecko_msg_le_gap_bt5_set_adv_parameters_rsp_t* resp = gecko_cmd_le_gap_bt5_set_adv_parameters(handle,interval_min,interval_max,channel_map,report_scan);
  printf("    RETURNED\n");
  dump_le_gap_bt5_set_adv_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_bt5_set_adv_data_rsp_t* cmd_le_gap_bt5_set_adv_data(uint8 handle,uint8 scan_rsp,uint8 adv_data_len, const uint8* adv_data_data) {
  dump_command_header("le_gap_bt5_set_adv_data");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 scan_rsp: 0x%02x\n",(int)scan_rsp);
  printf("  uint8 adv_data_len: 0x%02x\n",(int)adv_data_len);
  printf("  const uint8* adv_data_data: 0x%p\n",adv_data_data);
  struct gecko_msg_le_gap_bt5_set_adv_data_rsp_t* resp = gecko_cmd_le_gap_bt5_set_adv_data(handle,scan_rsp,adv_data_len,adv_data_data);
  printf("    RETURNED\n");
  dump_le_gap_bt5_set_adv_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_privacy_mode_rsp_t* cmd_le_gap_set_privacy_mode(uint8 privacy,uint8 interval) {
  dump_command_header("le_gap_set_privacy_mode");
  printf("  uint8 privacy: 0x%02x\n",(int)privacy);
  printf("  uint8 interval: 0x%02x\n",(int)interval);
  struct gecko_msg_le_gap_set_privacy_mode_rsp_t* resp = gecko_cmd_le_gap_set_privacy_mode(privacy,interval);
  printf("    RETURNED\n");
  dump_le_gap_set_privacy_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_timing_rsp_t* cmd_le_gap_set_advertise_timing(uint8 handle,uint32 interval_min,uint32 interval_max,uint16 duration,uint8 maxevents) {
  dump_command_header("le_gap_set_advertise_timing");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint32 interval_min: 0x%08x\n",(int)interval_min);
  printf("  uint32 interval_max: 0x%08x\n",(int)interval_max);
  printf("  uint16 duration: 0x%04x\n",(int)duration);
  printf("  uint8 maxevents: 0x%02x\n",(int)maxevents);
  struct gecko_msg_le_gap_set_advertise_timing_rsp_t* resp = gecko_cmd_le_gap_set_advertise_timing(handle,interval_min,interval_max,duration,maxevents);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_timing(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_channel_map_rsp_t* cmd_le_gap_set_advertise_channel_map(uint8 handle,uint8 channel_map) {
  dump_command_header("le_gap_set_advertise_channel_map");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 channel_map: 0x%02x\n",(int)channel_map);
  struct gecko_msg_le_gap_set_advertise_channel_map_rsp_t* resp = gecko_cmd_le_gap_set_advertise_channel_map(handle,channel_map);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_channel_map(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_report_scan_request_rsp_t* cmd_le_gap_set_advertise_report_scan_request(uint8 handle,uint8 report_scan_req) {
  dump_command_header("le_gap_set_advertise_report_scan_request");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 report_scan_req: 0x%02x\n",(int)report_scan_req);
  struct gecko_msg_le_gap_set_advertise_report_scan_request_rsp_t* resp = gecko_cmd_le_gap_set_advertise_report_scan_request(handle,report_scan_req);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_report_scan_request(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_phy_rsp_t* cmd_le_gap_set_advertise_phy(uint8 handle,uint8 primary_phy,uint8 secondary_phy) {
  dump_command_header("le_gap_set_advertise_phy");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 primary_phy: 0x%02x\n",(int)primary_phy);
  printf("  uint8 secondary_phy: 0x%02x\n",(int)secondary_phy);
  struct gecko_msg_le_gap_set_advertise_phy_rsp_t* resp = gecko_cmd_le_gap_set_advertise_phy(handle,primary_phy,secondary_phy);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_phy(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_configuration_rsp_t* cmd_le_gap_set_advertise_configuration(uint8 handle,uint32 configurations) {
  dump_command_header("le_gap_set_advertise_configuration");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint32 configurations: 0x%08x\n",(int)configurations);
  struct gecko_msg_le_gap_set_advertise_configuration_rsp_t* resp = gecko_cmd_le_gap_set_advertise_configuration(handle,configurations);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_configuration(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_clear_advertise_configuration_rsp_t* cmd_le_gap_clear_advertise_configuration(uint8 handle,uint32 configurations) {
  dump_command_header("le_gap_clear_advertise_configuration");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint32 configurations: 0x%08x\n",(int)configurations);
  struct gecko_msg_le_gap_clear_advertise_configuration_rsp_t* resp = gecko_cmd_le_gap_clear_advertise_configuration(handle,configurations);
  printf("    RETURNED\n");
  dump_le_gap_clear_advertise_configuration(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_start_advertising_rsp_t* cmd_le_gap_start_advertising(uint8 handle,uint8 discover,uint8 connect) {
  dump_command_header("le_gap_start_advertising");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 discover: 0x%02x\n",(int)discover);
  printf("  uint8 connect: 0x%02x\n",(int)connect);
  struct gecko_msg_le_gap_start_advertising_rsp_t* resp = gecko_cmd_le_gap_start_advertising(handle,discover,connect);
  printf("    RETURNED\n");
  dump_le_gap_start_advertising(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_stop_advertising_rsp_t* cmd_le_gap_stop_advertising(uint8 handle) {
  dump_command_header("le_gap_stop_advertising");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  struct gecko_msg_le_gap_stop_advertising_rsp_t* resp = gecko_cmd_le_gap_stop_advertising(handle);
  printf("    RETURNED\n");
  dump_le_gap_stop_advertising(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_discovery_timing_rsp_t* cmd_le_gap_set_discovery_timing(uint8 phys,uint16 scan_interval,uint16 scan_window) {
  dump_command_header("le_gap_set_discovery_timing");
  printf("  uint8 phys: 0x%02x\n",(int)phys);
  printf("  uint16 scan_interval: 0x%04x\n",(int)scan_interval);
  printf("  uint16 scan_window: 0x%04x\n",(int)scan_window);
  struct gecko_msg_le_gap_set_discovery_timing_rsp_t* resp = gecko_cmd_le_gap_set_discovery_timing(phys,scan_interval,scan_window);
  printf("    RETURNED\n");
  dump_le_gap_set_discovery_timing(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_discovery_type_rsp_t* cmd_le_gap_set_discovery_type(uint8 phys,uint8 scan_type) {
  dump_command_header("le_gap_set_discovery_type");
  printf("  uint8 phys: 0x%02x\n",(int)phys);
  printf("  uint8 scan_type: 0x%02x\n",(int)scan_type);
  struct gecko_msg_le_gap_set_discovery_type_rsp_t* resp = gecko_cmd_le_gap_set_discovery_type(phys,scan_type);
  printf("    RETURNED\n");
  dump_le_gap_set_discovery_type(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_start_discovery_rsp_t* cmd_le_gap_start_discovery(uint8 scanning_phy,uint8 mode) {
  dump_command_header("le_gap_start_discovery");
  printf("  uint8 scanning_phy: 0x%02x\n",(int)scanning_phy);
  printf("  uint8 mode: 0x%02x\n",(int)mode);
  struct gecko_msg_le_gap_start_discovery_rsp_t* resp = gecko_cmd_le_gap_start_discovery(scanning_phy,mode);
  printf("    RETURNED\n");
  dump_le_gap_start_discovery(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_data_channel_classification_rsp_t* cmd_le_gap_set_data_channel_classification(uint8 channel_map_len, const uint8* channel_map_data) {
  dump_command_header("le_gap_set_data_channel_classification");
  printf("  uint8 channel_map_len: 0x%02x\n",(int)channel_map_len);
  printf("  const uint8* channel_map_data: 0x%p\n",channel_map_data);
  struct gecko_msg_le_gap_set_data_channel_classification_rsp_t* resp = gecko_cmd_le_gap_set_data_channel_classification(channel_map_len,channel_map_data);
  printf("    RETURNED\n");
  dump_le_gap_set_data_channel_classification(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_connect_rsp_t* cmd_le_gap_connect(bd_addr address,uint8 address_type,uint8 initiating_phy) {
  dump_command_header("le_gap_connect");
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  printf("  uint8 address_type: 0x%02x\n",(int)address_type);
  printf("  uint8 initiating_phy: 0x%02x\n",(int)initiating_phy);
  struct gecko_msg_le_gap_connect_rsp_t* resp = gecko_cmd_le_gap_connect(address,address_type,initiating_phy);
  printf("    RETURNED\n");
  dump_le_gap_connect(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_tx_power_rsp_t* cmd_le_gap_set_advertise_tx_power(uint8 handle,int16 power) {
  dump_command_header("le_gap_set_advertise_tx_power");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  int16 power: 0x%04x\n",(int)power);
  struct gecko_msg_le_gap_set_advertise_tx_power_rsp_t* resp = gecko_cmd_le_gap_set_advertise_tx_power(handle,power);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_tx_power(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_discovery_extended_scan_response_rsp_t* cmd_le_gap_set_discovery_extended_scan_response(uint8 enable) {
  dump_command_header("le_gap_set_discovery_extended_scan_response");
  printf("  uint8 enable: 0x%02x\n",(int)enable);
  struct gecko_msg_le_gap_set_discovery_extended_scan_response_rsp_t* resp = gecko_cmd_le_gap_set_discovery_extended_scan_response(enable);
  printf("    RETURNED\n");
  dump_le_gap_set_discovery_extended_scan_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_start_periodic_advertising_rsp_t* cmd_le_gap_start_periodic_advertising(uint8 handle,uint16 interval_min,uint16 interval_max,uint32 flags) {
  dump_command_header("le_gap_start_periodic_advertising");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint16 interval_min: 0x%04x\n",(int)interval_min);
  printf("  uint16 interval_max: 0x%04x\n",(int)interval_max);
  printf("  uint32 flags: 0x%08x\n",(int)flags);
  struct gecko_msg_le_gap_start_periodic_advertising_rsp_t* resp = gecko_cmd_le_gap_start_periodic_advertising(handle,interval_min,interval_max,flags);
  printf("    RETURNED\n");
  dump_le_gap_start_periodic_advertising(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_stop_periodic_advertising_rsp_t* cmd_le_gap_stop_periodic_advertising(uint8 handle) {
  dump_command_header("le_gap_stop_periodic_advertising");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  struct gecko_msg_le_gap_stop_periodic_advertising_rsp_t* resp = gecko_cmd_le_gap_stop_periodic_advertising(handle);
  printf("    RETURNED\n");
  dump_le_gap_stop_periodic_advertising(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_long_advertising_data_rsp_t* cmd_le_gap_set_long_advertising_data(uint8 handle,uint8 packet_type) {
  dump_command_header("le_gap_set_long_advertising_data");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 packet_type: 0x%02x\n",(int)packet_type);
  struct gecko_msg_le_gap_set_long_advertising_data_rsp_t* resp = gecko_cmd_le_gap_set_long_advertising_data(handle,packet_type);
  printf("    RETURNED\n");
  dump_le_gap_set_long_advertising_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_enable_whitelisting_rsp_t* cmd_le_gap_enable_whitelisting(uint8 enable) {
  dump_command_header("le_gap_enable_whitelisting");
  printf("  uint8 enable: 0x%02x\n",(int)enable);
  struct gecko_msg_le_gap_enable_whitelisting_rsp_t* resp = gecko_cmd_le_gap_enable_whitelisting(enable);
  printf("    RETURNED\n");
  dump_le_gap_enable_whitelisting(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_conn_timing_parameters_rsp_t* cmd_le_gap_set_conn_timing_parameters(uint16 min_interval,uint16 max_interval,uint16 latency,uint16 timeout,uint16 min_ce_length,uint16 max_ce_length) {
  dump_command_header("le_gap_set_conn_timing_parameters");
  printf("  uint16 min_interval: 0x%04x\n",(int)min_interval);
  printf("  uint16 max_interval: 0x%04x\n",(int)max_interval);
  printf("  uint16 latency: 0x%04x\n",(int)latency);
  printf("  uint16 timeout: 0x%04x\n",(int)timeout);
  printf("  uint16 min_ce_length: 0x%04x\n",(int)min_ce_length);
  printf("  uint16 max_ce_length: 0x%04x\n",(int)max_ce_length);
  struct gecko_msg_le_gap_set_conn_timing_parameters_rsp_t* resp = gecko_cmd_le_gap_set_conn_timing_parameters(min_interval,max_interval,latency,timeout,min_ce_length,max_ce_length);
  printf("    RETURNED\n");
  dump_le_gap_set_conn_timing_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_random_address_rsp_t* cmd_le_gap_set_advertise_random_address(uint8 handle,uint8 addr_type,bd_addr address) {
  dump_command_header("le_gap_set_advertise_random_address");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 addr_type: 0x%02x\n",(int)addr_type);
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  struct gecko_msg_le_gap_set_advertise_random_address_rsp_t* resp = gecko_cmd_le_gap_set_advertise_random_address(handle,addr_type,address);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_random_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_clear_advertise_random_address_rsp_t* cmd_le_gap_clear_advertise_random_address(uint8 handle) {
  dump_command_header("le_gap_clear_advertise_random_address");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  struct gecko_msg_le_gap_clear_advertise_random_address_rsp_t* resp = gecko_cmd_le_gap_clear_advertise_random_address(handle);
  printf("    RETURNED\n");
  dump_le_gap_clear_advertise_random_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sync_open_rsp_t* cmd_sync_open(uint8 adv_sid,uint16 skip,uint16 timeout,bd_addr address,uint8 address_type) {
  dump_command_header("sync_open");
  printf("  uint8 adv_sid: 0x%02x\n",(int)adv_sid);
  printf("  uint16 skip: 0x%04x\n",(int)skip);
  printf("  uint16 timeout: 0x%04x\n",(int)timeout);
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  printf("  uint8 address_type: 0x%02x\n",(int)address_type);
  struct gecko_msg_sync_open_rsp_t* resp = gecko_cmd_sync_open(adv_sid,skip,timeout,address,address_type);
  printf("    RETURNED\n");
  dump_sync_open(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sync_close_rsp_t* cmd_sync_close(uint8 sync) {
  dump_command_header("sync_close");
  printf("  uint8 sync: 0x%02x\n",(int)sync);
  struct gecko_msg_sync_close_rsp_t* resp = gecko_cmd_sync_close(sync);
  printf("    RETURNED\n");
  dump_sync_close(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_set_parameters_rsp_t* cmd_le_connection_set_parameters(uint8 connection,uint16 min_interval,uint16 max_interval,uint16 latency,uint16 timeout) {
  dump_command_header("le_connection_set_parameters");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 min_interval: 0x%04x\n",(int)min_interval);
  printf("  uint16 max_interval: 0x%04x\n",(int)max_interval);
  printf("  uint16 latency: 0x%04x\n",(int)latency);
  printf("  uint16 timeout: 0x%04x\n",(int)timeout);
  struct gecko_msg_le_connection_set_parameters_rsp_t* resp = gecko_cmd_le_connection_set_parameters(connection,min_interval,max_interval,latency,timeout);
  printf("    RETURNED\n");
  dump_le_connection_set_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_get_rssi_rsp_t* cmd_le_connection_get_rssi(uint8 connection) {
  dump_command_header("le_connection_get_rssi");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_le_connection_get_rssi_rsp_t* resp = gecko_cmd_le_connection_get_rssi(connection);
  printf("    RETURNED\n");
  dump_le_connection_get_rssi(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_disable_slave_latency_rsp_t* cmd_le_connection_disable_slave_latency(uint8 connection,uint8 disable) {
  dump_command_header("le_connection_disable_slave_latency");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 disable: 0x%02x\n",(int)disable);
  struct gecko_msg_le_connection_disable_slave_latency_rsp_t* resp = gecko_cmd_le_connection_disable_slave_latency(connection,disable);
  printf("    RETURNED\n");
  dump_le_connection_disable_slave_latency(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_set_phy_rsp_t* cmd_le_connection_set_phy(uint8 connection,uint8 phy) {
  dump_command_header("le_connection_set_phy");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 phy: 0x%02x\n",(int)phy);
  struct gecko_msg_le_connection_set_phy_rsp_t* resp = gecko_cmd_le_connection_set_phy(connection,phy);
  printf("    RETURNED\n");
  dump_le_connection_set_phy(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_close_rsp_t* cmd_le_connection_close(uint8 connection) {
  dump_command_header("le_connection_close");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_le_connection_close_rsp_t* resp = gecko_cmd_le_connection_close(connection);
  printf("    RETURNED\n");
  dump_le_connection_close(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_set_timing_parameters_rsp_t* cmd_le_connection_set_timing_parameters(uint8 connection,uint16 min_interval,uint16 max_interval,uint16 latency,uint16 timeout,uint16 min_ce_length,uint16 max_ce_length) {
  dump_command_header("le_connection_set_timing_parameters");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 min_interval: 0x%04x\n",(int)min_interval);
  printf("  uint16 max_interval: 0x%04x\n",(int)max_interval);
  printf("  uint16 latency: 0x%04x\n",(int)latency);
  printf("  uint16 timeout: 0x%04x\n",(int)timeout);
  printf("  uint16 min_ce_length: 0x%04x\n",(int)min_ce_length);
  printf("  uint16 max_ce_length: 0x%04x\n",(int)max_ce_length);
  struct gecko_msg_le_connection_set_timing_parameters_rsp_t* resp = gecko_cmd_le_connection_set_timing_parameters(connection,min_interval,max_interval,latency,timeout,min_ce_length,max_ce_length);
  printf("    RETURNED\n");
  dump_le_connection_set_timing_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_read_channel_map_rsp_t* cmd_le_connection_read_channel_map(uint8 connection) {
  dump_command_header("le_connection_read_channel_map");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_le_connection_read_channel_map_rsp_t* resp = gecko_cmd_le_connection_read_channel_map(connection);
  printf("    RETURNED\n");
  dump_le_connection_read_channel_map(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_set_preferred_phy_rsp_t* cmd_le_connection_set_preferred_phy(uint8 connection,uint8 preferred_phy,uint8 accepted_phy) {
  dump_command_header("le_connection_set_preferred_phy");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 preferred_phy: 0x%02x\n",(int)preferred_phy);
  printf("  uint8 accepted_phy: 0x%02x\n",(int)accepted_phy);
  struct gecko_msg_le_connection_set_preferred_phy_rsp_t* resp = gecko_cmd_le_connection_set_preferred_phy(connection,preferred_phy,accepted_phy);
  printf("    RETURNED\n");
  dump_le_connection_set_preferred_phy(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_set_max_mtu_rsp_t* cmd_gatt_set_max_mtu(uint16 max_mtu) {
  dump_command_header("gatt_set_max_mtu");
  printf("  uint16 max_mtu: 0x%04x\n",(int)max_mtu);
  struct gecko_msg_gatt_set_max_mtu_rsp_t* resp = gecko_cmd_gatt_set_max_mtu(max_mtu);
  printf("    RETURNED\n");
  dump_gatt_set_max_mtu(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_discover_primary_services_rsp_t* cmd_gatt_discover_primary_services(uint8 connection) {
  dump_command_header("gatt_discover_primary_services");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_gatt_discover_primary_services_rsp_t* resp = gecko_cmd_gatt_discover_primary_services(connection);
  printf("    RETURNED\n");
  dump_gatt_discover_primary_services(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_discover_primary_services_by_uuid_rsp_t* cmd_gatt_discover_primary_services_by_uuid(uint8 connection,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("gatt_discover_primary_services_by_uuid");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_gatt_discover_primary_services_by_uuid_rsp_t* resp = gecko_cmd_gatt_discover_primary_services_by_uuid(connection,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_gatt_discover_primary_services_by_uuid(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_discover_characteristics_rsp_t* cmd_gatt_discover_characteristics(uint8 connection,uint32 service) {
  dump_command_header("gatt_discover_characteristics");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint32 service: 0x%08x\n",(int)service);
  struct gecko_msg_gatt_discover_characteristics_rsp_t* resp = gecko_cmd_gatt_discover_characteristics(connection,service);
  printf("    RETURNED\n");
  dump_gatt_discover_characteristics(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_discover_characteristics_by_uuid_rsp_t* cmd_gatt_discover_characteristics_by_uuid(uint8 connection,uint32 service,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("gatt_discover_characteristics_by_uuid");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint32 service: 0x%08x\n",(int)service);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_gatt_discover_characteristics_by_uuid_rsp_t* resp = gecko_cmd_gatt_discover_characteristics_by_uuid(connection,service,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_gatt_discover_characteristics_by_uuid(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_set_characteristic_notification_rsp_t* cmd_gatt_set_characteristic_notification(uint8 connection,uint16 characteristic,uint8 flags) {
  dump_command_header("gatt_set_characteristic_notification");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  struct gecko_msg_gatt_set_characteristic_notification_rsp_t* resp = gecko_cmd_gatt_set_characteristic_notification(connection,characteristic,flags);
  printf("    RETURNED\n");
  dump_gatt_set_characteristic_notification(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_discover_descriptors_rsp_t* cmd_gatt_discover_descriptors(uint8 connection,uint16 characteristic) {
  dump_command_header("gatt_discover_descriptors");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  struct gecko_msg_gatt_discover_descriptors_rsp_t* resp = gecko_cmd_gatt_discover_descriptors(connection,characteristic);
  printf("    RETURNED\n");
  dump_gatt_discover_descriptors(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_read_characteristic_value_rsp_t* cmd_gatt_read_characteristic_value(uint8 connection,uint16 characteristic) {
  dump_command_header("gatt_read_characteristic_value");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  struct gecko_msg_gatt_read_characteristic_value_rsp_t* resp = gecko_cmd_gatt_read_characteristic_value(connection,characteristic);
  printf("    RETURNED\n");
  dump_gatt_read_characteristic_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_read_characteristic_value_by_uuid_rsp_t* cmd_gatt_read_characteristic_value_by_uuid(uint8 connection,uint32 service,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("gatt_read_characteristic_value_by_uuid");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint32 service: 0x%08x\n",(int)service);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_gatt_read_characteristic_value_by_uuid_rsp_t* resp = gecko_cmd_gatt_read_characteristic_value_by_uuid(connection,service,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_gatt_read_characteristic_value_by_uuid(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_write_characteristic_value_rsp_t* cmd_gatt_write_characteristic_value(uint8 connection,uint16 characteristic,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_write_characteristic_value");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_write_characteristic_value_rsp_t* resp = gecko_cmd_gatt_write_characteristic_value(connection,characteristic,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_write_characteristic_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_write_characteristic_value_without_response_rsp_t* cmd_gatt_write_characteristic_value_without_response(uint8 connection,uint16 characteristic,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_write_characteristic_value_without_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_write_characteristic_value_without_response_rsp_t* resp = gecko_cmd_gatt_write_characteristic_value_without_response(connection,characteristic,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_write_characteristic_value_without_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_prepare_characteristic_value_write_rsp_t* cmd_gatt_prepare_characteristic_value_write(uint8 connection,uint16 characteristic,uint16 offset,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_prepare_characteristic_value_write");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint16 offset: 0x%04x\n",(int)offset);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_prepare_characteristic_value_write_rsp_t* resp = gecko_cmd_gatt_prepare_characteristic_value_write(connection,characteristic,offset,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_prepare_characteristic_value_write(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_execute_characteristic_value_write_rsp_t* cmd_gatt_execute_characteristic_value_write(uint8 connection,uint8 flags) {
  dump_command_header("gatt_execute_characteristic_value_write");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  struct gecko_msg_gatt_execute_characteristic_value_write_rsp_t* resp = gecko_cmd_gatt_execute_characteristic_value_write(connection,flags);
  printf("    RETURNED\n");
  dump_gatt_execute_characteristic_value_write(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_send_characteristic_confirmation_rsp_t* cmd_gatt_send_characteristic_confirmation(uint8 connection) {
  dump_command_header("gatt_send_characteristic_confirmation");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_gatt_send_characteristic_confirmation_rsp_t* resp = gecko_cmd_gatt_send_characteristic_confirmation(connection);
  printf("    RETURNED\n");
  dump_gatt_send_characteristic_confirmation(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_read_descriptor_value_rsp_t* cmd_gatt_read_descriptor_value(uint8 connection,uint16 descriptor) {
  dump_command_header("gatt_read_descriptor_value");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 descriptor: 0x%04x\n",(int)descriptor);
  struct gecko_msg_gatt_read_descriptor_value_rsp_t* resp = gecko_cmd_gatt_read_descriptor_value(connection,descriptor);
  printf("    RETURNED\n");
  dump_gatt_read_descriptor_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_write_descriptor_value_rsp_t* cmd_gatt_write_descriptor_value(uint8 connection,uint16 descriptor,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_write_descriptor_value");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 descriptor: 0x%04x\n",(int)descriptor);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_write_descriptor_value_rsp_t* resp = gecko_cmd_gatt_write_descriptor_value(connection,descriptor,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_write_descriptor_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_find_included_services_rsp_t* cmd_gatt_find_included_services(uint8 connection,uint32 service) {
  dump_command_header("gatt_find_included_services");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint32 service: 0x%08x\n",(int)service);
  struct gecko_msg_gatt_find_included_services_rsp_t* resp = gecko_cmd_gatt_find_included_services(connection,service);
  printf("    RETURNED\n");
  dump_gatt_find_included_services(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_read_multiple_characteristic_values_rsp_t* cmd_gatt_read_multiple_characteristic_values(uint8 connection,uint8 characteristic_list_len, const uint8* characteristic_list_data) {
  dump_command_header("gatt_read_multiple_characteristic_values");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 characteristic_list_len: 0x%02x\n",(int)characteristic_list_len);
  printf("  const uint8* characteristic_list_data: 0x%p\n",characteristic_list_data);
  struct gecko_msg_gatt_read_multiple_characteristic_values_rsp_t* resp = gecko_cmd_gatt_read_multiple_characteristic_values(connection,characteristic_list_len,characteristic_list_data);
  printf("    RETURNED\n");
  dump_gatt_read_multiple_characteristic_values(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_read_characteristic_value_from_offset_rsp_t* cmd_gatt_read_characteristic_value_from_offset(uint8 connection,uint16 characteristic,uint16 offset,uint16 maxlen) {
  dump_command_header("gatt_read_characteristic_value_from_offset");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint16 offset: 0x%04x\n",(int)offset);
  printf("  uint16 maxlen: 0x%04x\n",(int)maxlen);
  struct gecko_msg_gatt_read_characteristic_value_from_offset_rsp_t* resp = gecko_cmd_gatt_read_characteristic_value_from_offset(connection,characteristic,offset,maxlen);
  printf("    RETURNED\n");
  dump_gatt_read_characteristic_value_from_offset(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_prepare_characteristic_value_reliable_write_rsp_t* cmd_gatt_prepare_characteristic_value_reliable_write(uint8 connection,uint16 characteristic,uint16 offset,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_prepare_characteristic_value_reliable_write");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint16 offset: 0x%04x\n",(int)offset);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_prepare_characteristic_value_reliable_write_rsp_t* resp = gecko_cmd_gatt_prepare_characteristic_value_reliable_write(connection,characteristic,offset,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_prepare_characteristic_value_reliable_write(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_read_attribute_value_rsp_t* cmd_gatt_server_read_attribute_value(uint16 attribute,uint16 offset) {
  dump_command_header("gatt_server_read_attribute_value");
  printf("  uint16 attribute: 0x%04x\n",(int)attribute);
  printf("  uint16 offset: 0x%04x\n",(int)offset);
  struct gecko_msg_gatt_server_read_attribute_value_rsp_t* resp = gecko_cmd_gatt_server_read_attribute_value(attribute,offset);
  printf("    RETURNED\n");
  dump_gatt_server_read_attribute_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_read_attribute_type_rsp_t* cmd_gatt_server_read_attribute_type(uint16 attribute) {
  dump_command_header("gatt_server_read_attribute_type");
  printf("  uint16 attribute: 0x%04x\n",(int)attribute);
  struct gecko_msg_gatt_server_read_attribute_type_rsp_t* resp = gecko_cmd_gatt_server_read_attribute_type(attribute);
  printf("    RETURNED\n");
  dump_gatt_server_read_attribute_type(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_write_attribute_value_rsp_t* cmd_gatt_server_write_attribute_value(uint16 attribute,uint16 offset,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_server_write_attribute_value");
  printf("  uint16 attribute: 0x%04x\n",(int)attribute);
  printf("  uint16 offset: 0x%04x\n",(int)offset);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_server_write_attribute_value_rsp_t* resp = gecko_cmd_gatt_server_write_attribute_value(attribute,offset,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_server_write_attribute_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_send_user_read_response_rsp_t* cmd_gatt_server_send_user_read_response(uint8 connection,uint16 characteristic,uint8 att_errorcode,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_server_send_user_read_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 att_errorcode: 0x%02x\n",(int)att_errorcode);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_server_send_user_read_response_rsp_t* resp = gecko_cmd_gatt_server_send_user_read_response(connection,characteristic,att_errorcode,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_server_send_user_read_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_send_user_write_response_rsp_t* cmd_gatt_server_send_user_write_response(uint8 connection,uint16 characteristic,uint8 att_errorcode) {
  dump_command_header("gatt_server_send_user_write_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 att_errorcode: 0x%02x\n",(int)att_errorcode);
  struct gecko_msg_gatt_server_send_user_write_response_rsp_t* resp = gecko_cmd_gatt_server_send_user_write_response(connection,characteristic,att_errorcode);
  printf("    RETURNED\n");
  dump_gatt_server_send_user_write_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_send_characteristic_notification_rsp_t* cmd_gatt_server_send_characteristic_notification(uint8 connection,uint16 characteristic,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_server_send_characteristic_notification");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_server_send_characteristic_notification_rsp_t* resp = gecko_cmd_gatt_server_send_characteristic_notification(connection,characteristic,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_server_send_characteristic_notification(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_find_attribute_rsp_t* cmd_gatt_server_find_attribute(uint16 start,uint8 type_len, const uint8* type_data) {
  dump_command_header("gatt_server_find_attribute");
  printf("  uint16 start: 0x%04x\n",(int)start);
  printf("  uint8 type_len: 0x%02x\n",(int)type_len);
  printf("  const uint8* type_data: 0x%p\n",type_data);
  struct gecko_msg_gatt_server_find_attribute_rsp_t* resp = gecko_cmd_gatt_server_find_attribute(start,type_len,type_data);
  printf("    RETURNED\n");
  dump_gatt_server_find_attribute(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_set_capabilities_rsp_t* cmd_gatt_server_set_capabilities(uint32 caps,uint32 reserved) {
  dump_command_header("gatt_server_set_capabilities");
  printf("  uint32 caps: 0x%08x\n",(int)caps);
  printf("  uint32 reserved: 0x%08x\n",(int)reserved);
  struct gecko_msg_gatt_server_set_capabilities_rsp_t* resp = gecko_cmd_gatt_server_set_capabilities(caps,reserved);
  printf("    RETURNED\n");
  dump_gatt_server_set_capabilities(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_set_max_mtu_rsp_t* cmd_gatt_server_set_max_mtu(uint16 max_mtu) {
  dump_command_header("gatt_server_set_max_mtu");
  printf("  uint16 max_mtu: 0x%04x\n",(int)max_mtu);
  struct gecko_msg_gatt_server_set_max_mtu_rsp_t* resp = gecko_cmd_gatt_server_set_max_mtu(max_mtu);
  printf("    RETURNED\n");
  dump_gatt_server_set_max_mtu(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_get_mtu_rsp_t* cmd_gatt_server_get_mtu(uint8 connection) {
  dump_command_header("gatt_server_get_mtu");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_gatt_server_get_mtu_rsp_t* resp = gecko_cmd_gatt_server_get_mtu(connection);
  printf("    RETURNED\n");
  dump_gatt_server_get_mtu(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_enable_capabilities_rsp_t* cmd_gatt_server_enable_capabilities(uint32 caps) {
  dump_command_header("gatt_server_enable_capabilities");
  printf("  uint32 caps: 0x%08x\n",(int)caps);
  struct gecko_msg_gatt_server_enable_capabilities_rsp_t* resp = gecko_cmd_gatt_server_enable_capabilities(caps);
  printf("    RETURNED\n");
  dump_gatt_server_enable_capabilities(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_disable_capabilities_rsp_t* cmd_gatt_server_disable_capabilities(uint32 caps) {
  dump_command_header("gatt_server_disable_capabilities");
  printf("  uint32 caps: 0x%08x\n",(int)caps);
  struct gecko_msg_gatt_server_disable_capabilities_rsp_t* resp = gecko_cmd_gatt_server_disable_capabilities(caps);
  printf("    RETURNED\n");
  dump_gatt_server_disable_capabilities(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_get_enabled_capabilities_rsp_t* cmd_gatt_server_get_enabled_capabilities() {
  dump_command_header("gatt_server_get_enabled_capabilities");
  struct gecko_msg_gatt_server_get_enabled_capabilities_rsp_t* resp = gecko_cmd_gatt_server_get_enabled_capabilities();
  printf("    RETURNED\n");
  dump_gatt_server_get_enabled_capabilities(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_hardware_set_soft_timer_rsp_t* cmd_hardware_set_soft_timer(uint32 time,uint8 handle,uint8 single_shot) {
  dump_command_header("hardware_set_soft_timer");
  printf("  uint32 time: 0x%08x\n",(int)time);
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 single_shot: 0x%02x\n",(int)single_shot);
  struct gecko_msg_hardware_set_soft_timer_rsp_t* resp = gecko_cmd_hardware_set_soft_timer(time,handle,single_shot);
  printf("    RETURNED\n");
  dump_hardware_set_soft_timer(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_hardware_get_time_rsp_t* cmd_hardware_get_time() {
  dump_command_header("hardware_get_time");
  struct gecko_msg_hardware_get_time_rsp_t* resp = gecko_cmd_hardware_get_time();
  printf("    RETURNED\n");
  dump_hardware_get_time(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_hardware_set_lazy_soft_timer_rsp_t* cmd_hardware_set_lazy_soft_timer(uint32 time,uint32 slack,uint8 handle,uint8 single_shot) {
  dump_command_header("hardware_set_lazy_soft_timer");
  printf("  uint32 time: 0x%08x\n",(int)time);
  printf("  uint32 slack: 0x%08x\n",(int)slack);
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 single_shot: 0x%02x\n",(int)single_shot);
  struct gecko_msg_hardware_set_lazy_soft_timer_rsp_t* resp = gecko_cmd_hardware_set_lazy_soft_timer(time,slack,handle,single_shot);
  printf("    RETURNED\n");
  dump_hardware_set_lazy_soft_timer(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_flash_ps_erase_all_rsp_t* cmd_flash_ps_erase_all() {
  dump_command_header("flash_ps_erase_all");
  struct gecko_msg_flash_ps_erase_all_rsp_t* resp = gecko_cmd_flash_ps_erase_all();
  printf("    RETURNED\n");
  dump_flash_ps_erase_all(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_flash_ps_save_rsp_t* cmd_flash_ps_save(uint16 key,uint8 value_len, const uint8* value_data) {
  dump_command_header("flash_ps_save");
  printf("  uint16 key: 0x%04x\n",(int)key);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_flash_ps_save_rsp_t* resp = gecko_cmd_flash_ps_save(key,value_len,value_data);
  printf("    RETURNED\n");
  dump_flash_ps_save(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_flash_ps_load_rsp_t* cmd_flash_ps_load(uint16 key) {
  dump_command_header("flash_ps_load");
  printf("  uint16 key: 0x%04x\n",(int)key);
  struct gecko_msg_flash_ps_load_rsp_t* resp = gecko_cmd_flash_ps_load(key);
  printf("    RETURNED\n");
  dump_flash_ps_load(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_flash_ps_erase_rsp_t* cmd_flash_ps_erase(uint16 key) {
  dump_command_header("flash_ps_erase");
  printf("  uint16 key: 0x%04x\n",(int)key);
  struct gecko_msg_flash_ps_erase_rsp_t* resp = gecko_cmd_flash_ps_erase(key);
  printf("    RETURNED\n");
  dump_flash_ps_erase(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_test_dtm_tx_rsp_t* cmd_test_dtm_tx(uint8 packet_type,uint8 length,uint8 channel,uint8 phy) {
  dump_command_header("test_dtm_tx");
  printf("  uint8 packet_type: 0x%02x\n",(int)packet_type);
  printf("  uint8 length: 0x%02x\n",(int)length);
  printf("  uint8 channel: 0x%02x\n",(int)channel);
  printf("  uint8 phy: 0x%02x\n",(int)phy);
  struct gecko_msg_test_dtm_tx_rsp_t* resp = gecko_cmd_test_dtm_tx(packet_type,length,channel,phy);
  printf("    RETURNED\n");
  dump_test_dtm_tx(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_test_dtm_rx_rsp_t* cmd_test_dtm_rx(uint8 channel,uint8 phy) {
  dump_command_header("test_dtm_rx");
  printf("  uint8 channel: 0x%02x\n",(int)channel);
  printf("  uint8 phy: 0x%02x\n",(int)phy);
  struct gecko_msg_test_dtm_rx_rsp_t* resp = gecko_cmd_test_dtm_rx(channel,phy);
  printf("    RETURNED\n");
  dump_test_dtm_rx(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_test_dtm_end_rsp_t* cmd_test_dtm_end() {
  dump_command_header("test_dtm_end");
  struct gecko_msg_test_dtm_end_rsp_t* resp = gecko_cmd_test_dtm_end();
  printf("    RETURNED\n");
  dump_test_dtm_end(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_bondable_mode_rsp_t* cmd_sm_set_bondable_mode(uint8 bondable) {
  dump_command_header("sm_set_bondable_mode");
  printf("  uint8 bondable: 0x%02x\n",(int)bondable);
  struct gecko_msg_sm_set_bondable_mode_rsp_t* resp = gecko_cmd_sm_set_bondable_mode(bondable);
  printf("    RETURNED\n");
  dump_sm_set_bondable_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_configure_rsp_t* cmd_sm_configure(uint8 flags,uint8 io_capabilities) {
  dump_command_header("sm_configure");
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint8 io_capabilities: 0x%02x\n",(int)io_capabilities);
  struct gecko_msg_sm_configure_rsp_t* resp = gecko_cmd_sm_configure(flags,io_capabilities);
  printf("    RETURNED\n");
  dump_sm_configure(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_store_bonding_configuration_rsp_t* cmd_sm_store_bonding_configuration(uint8 max_bonding_count,uint8 policy_flags) {
  dump_command_header("sm_store_bonding_configuration");
  printf("  uint8 max_bonding_count: 0x%02x\n",(int)max_bonding_count);
  printf("  uint8 policy_flags: 0x%02x\n",(int)policy_flags);
  struct gecko_msg_sm_store_bonding_configuration_rsp_t* resp = gecko_cmd_sm_store_bonding_configuration(max_bonding_count,policy_flags);
  printf("    RETURNED\n");
  dump_sm_store_bonding_configuration(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_increase_security_rsp_t* cmd_sm_increase_security(uint8 connection) {
  dump_command_header("sm_increase_security");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_sm_increase_security_rsp_t* resp = gecko_cmd_sm_increase_security(connection);
  printf("    RETURNED\n");
  dump_sm_increase_security(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_delete_bonding_rsp_t* cmd_sm_delete_bonding(uint8 bonding) {
  dump_command_header("sm_delete_bonding");
  printf("  uint8 bonding: 0x%02x\n",(int)bonding);
  struct gecko_msg_sm_delete_bonding_rsp_t* resp = gecko_cmd_sm_delete_bonding(bonding);
  printf("    RETURNED\n");
  dump_sm_delete_bonding(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_delete_bondings_rsp_t* cmd_sm_delete_bondings() {
  dump_command_header("sm_delete_bondings");
  struct gecko_msg_sm_delete_bondings_rsp_t* resp = gecko_cmd_sm_delete_bondings();
  printf("    RETURNED\n");
  dump_sm_delete_bondings(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_enter_passkey_rsp_t* cmd_sm_enter_passkey(uint8 connection,int32 passkey) {
  dump_command_header("sm_enter_passkey");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  int32 passkey: 0x%04x\n",(int)passkey);
  struct gecko_msg_sm_enter_passkey_rsp_t* resp = gecko_cmd_sm_enter_passkey(connection,passkey);
  printf("    RETURNED\n");
  dump_sm_enter_passkey(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_passkey_confirm_rsp_t* cmd_sm_passkey_confirm(uint8 connection,uint8 confirm) {
  dump_command_header("sm_passkey_confirm");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 confirm: 0x%02x\n",(int)confirm);
  struct gecko_msg_sm_passkey_confirm_rsp_t* resp = gecko_cmd_sm_passkey_confirm(connection,confirm);
  printf("    RETURNED\n");
  dump_sm_passkey_confirm(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_oob_data_rsp_t* cmd_sm_set_oob_data(uint8 oob_data_len, const uint8* oob_data_data) {
  dump_command_header("sm_set_oob_data");
  printf("  uint8 oob_data_len: 0x%02x\n",(int)oob_data_len);
  printf("  const uint8* oob_data_data: 0x%p\n",oob_data_data);
  struct gecko_msg_sm_set_oob_data_rsp_t* resp = gecko_cmd_sm_set_oob_data(oob_data_len,oob_data_data);
  printf("    RETURNED\n");
  dump_sm_set_oob_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_list_all_bondings_rsp_t* cmd_sm_list_all_bondings() {
  dump_command_header("sm_list_all_bondings");
  struct gecko_msg_sm_list_all_bondings_rsp_t* resp = gecko_cmd_sm_list_all_bondings();
  printf("    RETURNED\n");
  dump_sm_list_all_bondings(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_bonding_confirm_rsp_t* cmd_sm_bonding_confirm(uint8 connection,uint8 confirm) {
  dump_command_header("sm_bonding_confirm");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 confirm: 0x%02x\n",(int)confirm);
  struct gecko_msg_sm_bonding_confirm_rsp_t* resp = gecko_cmd_sm_bonding_confirm(connection,confirm);
  printf("    RETURNED\n");
  dump_sm_bonding_confirm(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_debug_mode_rsp_t* cmd_sm_set_debug_mode() {
  dump_command_header("sm_set_debug_mode");
  struct gecko_msg_sm_set_debug_mode_rsp_t* resp = gecko_cmd_sm_set_debug_mode();
  printf("    RETURNED\n");
  dump_sm_set_debug_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_passkey_rsp_t* cmd_sm_set_passkey(int32 passkey) {
  dump_command_header("sm_set_passkey");
  printf("  int32 passkey: 0x%04x\n",(int)passkey);
  struct gecko_msg_sm_set_passkey_rsp_t* resp = gecko_cmd_sm_set_passkey(passkey);
  printf("    RETURNED\n");
  dump_sm_set_passkey(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_use_sc_oob_rsp_t* cmd_sm_use_sc_oob(uint8 enable) {
  dump_command_header("sm_use_sc_oob");
  printf("  uint8 enable: 0x%02x\n",(int)enable);
  struct gecko_msg_sm_use_sc_oob_rsp_t* resp = gecko_cmd_sm_use_sc_oob(enable);
  printf("    RETURNED\n");
  dump_sm_use_sc_oob(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_sc_remote_oob_data_rsp_t* cmd_sm_set_sc_remote_oob_data(uint8 oob_data_len, const uint8* oob_data_data) {
  dump_command_header("sm_set_sc_remote_oob_data");
  printf("  uint8 oob_data_len: 0x%02x\n",(int)oob_data_len);
  printf("  const uint8* oob_data_data: 0x%p\n",oob_data_data);
  struct gecko_msg_sm_set_sc_remote_oob_data_rsp_t* resp = gecko_cmd_sm_set_sc_remote_oob_data(oob_data_len,oob_data_data);
  printf("    RETURNED\n");
  dump_sm_set_sc_remote_oob_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_add_to_whitelist_rsp_t* cmd_sm_add_to_whitelist(bd_addr address,uint8 address_type) {
  dump_command_header("sm_add_to_whitelist");
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  printf("  uint8 address_type: 0x%02x\n",(int)address_type);
  struct gecko_msg_sm_add_to_whitelist_rsp_t* resp = gecko_cmd_sm_add_to_whitelist(address,address_type);
  printf("    RETURNED\n");
  dump_sm_add_to_whitelist(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_minimum_key_size_rsp_t* cmd_sm_set_minimum_key_size(uint8 minimum_key_size) {
  dump_command_header("sm_set_minimum_key_size");
  printf("  uint8 minimum_key_size: 0x%02x\n",(int)minimum_key_size);
  struct gecko_msg_sm_set_minimum_key_size_rsp_t* resp = gecko_cmd_sm_set_minimum_key_size(minimum_key_size);
  printf("    RETURNED\n");
  dump_sm_set_minimum_key_size(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_configure_rsp_t* cmd_homekit_configure(uint8 i2c_address,uint8 support_display,uint8 hap_attribute_features,uint16 category,uint8 configuration_number,uint16 fast_advert_interval,uint16 fast_advert_timeout,uint32 flag,uint16 broadcast_advert_timeout,uint8 model_name_len, const uint8* model_name_data) {
  dump_command_header("homekit_configure");
  printf("  uint8 i2c_address: 0x%02x\n",(int)i2c_address);
  printf("  uint8 support_display: 0x%02x\n",(int)support_display);
  printf("  uint8 hap_attribute_features: 0x%02x\n",(int)hap_attribute_features);
  printf("  uint16 category: 0x%04x\n",(int)category);
  printf("  uint8 configuration_number: 0x%02x\n",(int)configuration_number);
  printf("  uint16 fast_advert_interval: 0x%04x\n",(int)fast_advert_interval);
  printf("  uint16 fast_advert_timeout: 0x%04x\n",(int)fast_advert_timeout);
  printf("  uint32 flag: 0x%08x\n",(int)flag);
  printf("  uint16 broadcast_advert_timeout: 0x%04x\n",(int)broadcast_advert_timeout);
  printf("  uint8 model_name_len: 0x%02x\n",(int)model_name_len);
  printf("  const uint8* model_name_data: 0x%p\n",model_name_data);
  struct gecko_msg_homekit_configure_rsp_t* resp = gecko_cmd_homekit_configure(i2c_address,support_display,hap_attribute_features,category,configuration_number,fast_advert_interval,fast_advert_timeout,flag,broadcast_advert_timeout,model_name_len,model_name_data);
  printf("    RETURNED\n");
  dump_homekit_configure(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_advertise_rsp_t* cmd_homekit_advertise(uint8 enable,uint16 interval_min,uint16 interval_max,uint8 channel_map) {
  dump_command_header("homekit_advertise");
  printf("  uint8 enable: 0x%02x\n",(int)enable);
  printf("  uint16 interval_min: 0x%04x\n",(int)interval_min);
  printf("  uint16 interval_max: 0x%04x\n",(int)interval_max);
  printf("  uint8 channel_map: 0x%02x\n",(int)channel_map);
  struct gecko_msg_homekit_advertise_rsp_t* resp = gecko_cmd_homekit_advertise(enable,interval_min,interval_max,channel_map);
  printf("    RETURNED\n");
  dump_homekit_advertise(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_delete_pairings_rsp_t* cmd_homekit_delete_pairings() {
  dump_command_header("homekit_delete_pairings");
  struct gecko_msg_homekit_delete_pairings_rsp_t* resp = gecko_cmd_homekit_delete_pairings();
  printf("    RETURNED\n");
  dump_homekit_delete_pairings(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_check_authcp_rsp_t* cmd_homekit_check_authcp() {
  dump_command_header("homekit_check_authcp");
  struct gecko_msg_homekit_check_authcp_rsp_t* resp = gecko_cmd_homekit_check_authcp();
  printf("    RETURNED\n");
  dump_homekit_check_authcp(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_get_pairing_id_rsp_t* cmd_homekit_get_pairing_id(uint8 connection) {
  dump_command_header("homekit_get_pairing_id");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_homekit_get_pairing_id_rsp_t* resp = gecko_cmd_homekit_get_pairing_id(connection);
  printf("    RETURNED\n");
  dump_homekit_get_pairing_id(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_send_write_response_rsp_t* cmd_homekit_send_write_response(uint8 connection,uint16 characteristic,uint8 status_code) {
  dump_command_header("homekit_send_write_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 status_code: 0x%02x\n",(int)status_code);
  struct gecko_msg_homekit_send_write_response_rsp_t* resp = gecko_cmd_homekit_send_write_response(connection,characteristic,status_code);
  printf("    RETURNED\n");
  dump_homekit_send_write_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_send_read_response_rsp_t* cmd_homekit_send_read_response(uint8 connection,uint16 characteristic,uint8 status_code,uint16 attribute_size,uint8 value_len, const uint8* value_data) {
  dump_command_header("homekit_send_read_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 status_code: 0x%02x\n",(int)status_code);
  printf("  uint16 attribute_size: 0x%04x\n",(int)attribute_size);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_homekit_send_read_response_rsp_t* resp = gecko_cmd_homekit_send_read_response(connection,characteristic,status_code,attribute_size,value_len,value_data);
  printf("    RETURNED\n");
  dump_homekit_send_read_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_gsn_action_rsp_t* cmd_homekit_gsn_action(uint8 action) {
  dump_command_header("homekit_gsn_action");
  printf("  uint8 action: 0x%02x\n",(int)action);
  struct gecko_msg_homekit_gsn_action_rsp_t* resp = gecko_cmd_homekit_gsn_action(action);
  printf("    RETURNED\n");
  dump_homekit_gsn_action(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_event_notification_rsp_t* cmd_homekit_event_notification(uint8 connection,uint16 characteristic,uint8 change_originator,uint8 value_len, const uint8* value_data) {
  dump_command_header("homekit_event_notification");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 change_originator: 0x%02x\n",(int)change_originator);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_homekit_event_notification_rsp_t* resp = gecko_cmd_homekit_event_notification(connection,characteristic,change_originator,value_len,value_data);
  printf("    RETURNED\n");
  dump_homekit_event_notification(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_broadcast_action_rsp_t* cmd_homekit_broadcast_action(uint8 action,uint8 params_len, const uint8* params_data) {
  dump_command_header("homekit_broadcast_action");
  printf("  uint8 action: 0x%02x\n",(int)action);
  printf("  uint8 params_len: 0x%02x\n",(int)params_len);
  printf("  const uint8* params_data: 0x%p\n",params_data);
  struct gecko_msg_homekit_broadcast_action_rsp_t* resp = gecko_cmd_homekit_broadcast_action(action,params_len,params_data);
  printf("    RETURNED\n");
  dump_homekit_broadcast_action(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_configure_product_data_rsp_t* cmd_homekit_configure_product_data(uint8 product_data_len, const uint8* product_data_data) {
  dump_command_header("homekit_configure_product_data");
  printf("  uint8 product_data_len: 0x%02x\n",(int)product_data_len);
  printf("  const uint8* product_data_data: 0x%p\n",product_data_data);
  struct gecko_msg_homekit_configure_product_data_rsp_t* resp = gecko_cmd_homekit_configure_product_data(product_data_len,product_data_data);
  printf("    RETURNED\n");
  dump_homekit_configure_product_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_init_rsp_t* cmd_mesh_node_init() {
  dump_command_header("mesh_node_init");
  struct gecko_msg_mesh_node_init_rsp_t* resp = gecko_cmd_mesh_node_init();
  printf("    RETURNED\n");
  dump_mesh_node_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_start_unprov_beaconing_rsp_t* cmd_mesh_node_start_unprov_beaconing(uint8 bearer) {
  dump_command_header("mesh_node_start_unprov_beaconing");
  printf("  uint8 bearer: 0x%02x\n",(int)bearer);
  struct gecko_msg_mesh_node_start_unprov_beaconing_rsp_t* resp = gecko_cmd_mesh_node_start_unprov_beaconing(bearer);
  printf("    RETURNED\n");
  dump_mesh_node_start_unprov_beaconing(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_stop_unprov_beaconing_rsp_t* cmd_mesh_node_stop_unprov_beaconing() {
  dump_command_header("mesh_node_stop_unprov_beaconing");
  struct gecko_msg_mesh_node_stop_unprov_beaconing_rsp_t* resp = gecko_cmd_mesh_node_stop_unprov_beaconing();
  printf("    RETURNED\n");
  dump_mesh_node_stop_unprov_beaconing(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_rssi_rsp_t* cmd_mesh_node_rssi() {
  dump_command_header("mesh_node_rssi");
  struct gecko_msg_mesh_node_rssi_rsp_t* resp = gecko_cmd_mesh_node_rssi();
  printf("    RETURNED\n");
  dump_mesh_node_rssi(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_input_oob_request_rsp_rsp_t* cmd_mesh_node_input_oob_request_rsp(uint8 data_len, const uint8* data_data) {
  dump_command_header("mesh_node_input_oob_request_rsp");
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_mesh_node_input_oob_request_rsp_rsp_t* resp = gecko_cmd_mesh_node_input_oob_request_rsp(data_len,data_data);
  printf("    RETURNED\n");
  dump_mesh_node_input_oob_request_rsp(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_get_uuid_rsp_t* cmd_mesh_node_get_uuid() {
  dump_command_header("mesh_node_get_uuid");
  struct gecko_msg_mesh_node_get_uuid_rsp_t* resp = gecko_cmd_mesh_node_get_uuid();
  printf("    RETURNED\n");
  dump_mesh_node_get_uuid(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_set_provisioning_data_rsp_t* cmd_mesh_node_set_provisioning_data(aes_key_128 device_key,aes_key_128 network_key,uint16 netkey_index,uint32 iv_index,uint16 address,uint8 kr_in_progress) {
  dump_command_header("mesh_node_set_provisioning_data");
   printf("  aes_key_128 mesh_node_set_provisioning_data: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",device_key.data[i]);
   printf("\n");
   printf("  aes_key_128 mesh_node_set_provisioning_data: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",network_key.data[i]);
   printf("\n");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint32 iv_index: 0x%08x\n",(int)iv_index);
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint8 kr_in_progress: 0x%02x\n",(int)kr_in_progress);
  struct gecko_msg_mesh_node_set_provisioning_data_rsp_t* resp = gecko_cmd_mesh_node_set_provisioning_data(device_key,network_key,netkey_index,iv_index,address,kr_in_progress);
  printf("    RETURNED\n");
  dump_mesh_node_set_provisioning_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_init_oob_rsp_t* cmd_mesh_node_init_oob(uint8 public_key,uint8 auth_methods,uint16 output_actions,uint8 output_size,uint16 input_actions,uint8 input_size,uint16 oob_location) {
  dump_command_header("mesh_node_init_oob");
  printf("  uint8 public_key: 0x%02x\n",(int)public_key);
  printf("  uint8 auth_methods: 0x%02x\n",(int)auth_methods);
  printf("  uint16 output_actions: 0x%04x\n",(int)output_actions);
  printf("  uint8 output_size: 0x%02x\n",(int)output_size);
  printf("  uint16 input_actions: 0x%04x\n",(int)input_actions);
  printf("  uint8 input_size: 0x%02x\n",(int)input_size);
  printf("  uint16 oob_location: 0x%04x\n",(int)oob_location);
  struct gecko_msg_mesh_node_init_oob_rsp_t* resp = gecko_cmd_mesh_node_init_oob(public_key,auth_methods,output_actions,output_size,input_actions,input_size,oob_location);
  printf("    RETURNED\n");
  dump_mesh_node_init_oob(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_set_ivrecovery_mode_rsp_t* cmd_mesh_node_set_ivrecovery_mode(uint8 mode) {
  dump_command_header("mesh_node_set_ivrecovery_mode");
  printf("  uint8 mode: 0x%02x\n",(int)mode);
  struct gecko_msg_mesh_node_set_ivrecovery_mode_rsp_t* resp = gecko_cmd_mesh_node_set_ivrecovery_mode(mode);
  printf("    RETURNED\n");
  dump_mesh_node_set_ivrecovery_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_get_ivrecovery_mode_rsp_t* cmd_mesh_node_get_ivrecovery_mode() {
  dump_command_header("mesh_node_get_ivrecovery_mode");
  struct gecko_msg_mesh_node_get_ivrecovery_mode_rsp_t* resp = gecko_cmd_mesh_node_get_ivrecovery_mode();
  printf("    RETURNED\n");
  dump_mesh_node_get_ivrecovery_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_set_adv_event_filter_rsp_t* cmd_mesh_node_set_adv_event_filter(uint16 mask,uint8 gap_data_type_len, const uint8* gap_data_type_data) {
  dump_command_header("mesh_node_set_adv_event_filter");
  printf("  uint16 mask: 0x%04x\n",(int)mask);
  printf("  uint8 gap_data_type_len: 0x%02x\n",(int)gap_data_type_len);
  printf("  const uint8* gap_data_type_data: 0x%p\n",gap_data_type_data);
  struct gecko_msg_mesh_node_set_adv_event_filter_rsp_t* resp = gecko_cmd_mesh_node_set_adv_event_filter(mask,gap_data_type_len,gap_data_type_data);
  printf("    RETURNED\n");
  dump_mesh_node_set_adv_event_filter(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_get_statistics_rsp_t* cmd_mesh_node_get_statistics() {
  dump_command_header("mesh_node_get_statistics");
  struct gecko_msg_mesh_node_get_statistics_rsp_t* resp = gecko_cmd_mesh_node_get_statistics();
  printf("    RETURNED\n");
  dump_mesh_node_get_statistics(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_clear_statistics_rsp_t* cmd_mesh_node_clear_statistics() {
  dump_command_header("mesh_node_clear_statistics");
  struct gecko_msg_mesh_node_clear_statistics_rsp_t* resp = gecko_cmd_mesh_node_clear_statistics();
  printf("    RETURNED\n");
  dump_mesh_node_clear_statistics(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_set_net_relay_delay_rsp_t* cmd_mesh_node_set_net_relay_delay(uint8 min,uint8 max) {
  dump_command_header("mesh_node_set_net_relay_delay");
  printf("  uint8 min: 0x%02x\n",(int)min);
  printf("  uint8 max: 0x%02x\n",(int)max);
  struct gecko_msg_mesh_node_set_net_relay_delay_rsp_t* resp = gecko_cmd_mesh_node_set_net_relay_delay(min,max);
  printf("    RETURNED\n");
  dump_mesh_node_set_net_relay_delay(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_get_net_relay_delay_rsp_t* cmd_mesh_node_get_net_relay_delay() {
  dump_command_header("mesh_node_get_net_relay_delay");
  struct gecko_msg_mesh_node_get_net_relay_delay_rsp_t* resp = gecko_cmd_mesh_node_get_net_relay_delay();
  printf("    RETURNED\n");
  dump_mesh_node_get_net_relay_delay(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_get_ivupdate_state_rsp_t* cmd_mesh_node_get_ivupdate_state() {
  dump_command_header("mesh_node_get_ivupdate_state");
  struct gecko_msg_mesh_node_get_ivupdate_state_rsp_t* resp = gecko_cmd_mesh_node_get_ivupdate_state();
  printf("    RETURNED\n");
  dump_mesh_node_get_ivupdate_state(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_request_ivupdate_rsp_t* cmd_mesh_node_request_ivupdate() {
  dump_command_header("mesh_node_request_ivupdate");
  struct gecko_msg_mesh_node_request_ivupdate_rsp_t* resp = gecko_cmd_mesh_node_request_ivupdate();
  printf("    RETURNED\n");
  dump_mesh_node_request_ivupdate(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_get_seq_remaining_rsp_t* cmd_mesh_node_get_seq_remaining(uint16 elem_index) {
  dump_command_header("mesh_node_get_seq_remaining");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_node_get_seq_remaining_rsp_t* resp = gecko_cmd_mesh_node_get_seq_remaining(elem_index);
  printf("    RETURNED\n");
  dump_mesh_node_get_seq_remaining(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_save_replay_protection_list_rsp_t* cmd_mesh_node_save_replay_protection_list() {
  dump_command_header("mesh_node_save_replay_protection_list");
  struct gecko_msg_mesh_node_save_replay_protection_list_rsp_t* resp = gecko_cmd_mesh_node_save_replay_protection_list();
  printf("    RETURNED\n");
  dump_mesh_node_save_replay_protection_list(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_set_uuid_rsp_t* cmd_mesh_node_set_uuid(uuid_128 uuid) {
  dump_command_header("mesh_node_set_uuid");
   printf("  aes_key_128 mesh_node_set_uuid: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",uuid.data[i]);
   printf("\n");
  struct gecko_msg_mesh_node_set_uuid_rsp_t* resp = gecko_cmd_mesh_node_set_uuid(uuid);
  printf("    RETURNED\n");
  dump_mesh_node_set_uuid(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_get_element_address_rsp_t* cmd_mesh_node_get_element_address(uint16 elem_index) {
  dump_command_header("mesh_node_get_element_address");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_node_get_element_address_rsp_t* resp = gecko_cmd_mesh_node_get_element_address(elem_index);
  printf("    RETURNED\n");
  dump_mesh_node_get_element_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_static_oob_request_rsp_rsp_t* cmd_mesh_node_static_oob_request_rsp(uint8 data_len, const uint8* data_data) {
  dump_command_header("mesh_node_static_oob_request_rsp");
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_mesh_node_static_oob_request_rsp_rsp_t* resp = gecko_cmd_mesh_node_static_oob_request_rsp(data_len,data_data);
  printf("    RETURNED\n");
  dump_mesh_node_static_oob_request_rsp(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_reset_rsp_t* cmd_mesh_node_reset() {
  dump_command_header("mesh_node_reset");
  struct gecko_msg_mesh_node_reset_rsp_t* resp = gecko_cmd_mesh_node_reset();
  printf("    RETURNED\n");
  dump_mesh_node_reset(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_node_set_beacon_reporting_rsp_t* cmd_mesh_node_set_beacon_reporting(uint8 report) {
  dump_command_header("mesh_node_set_beacon_reporting");
  printf("  uint8 report: 0x%02x\n",(int)report);
  struct gecko_msg_mesh_node_set_beacon_reporting_rsp_t* resp = gecko_cmd_mesh_node_set_beacon_reporting(report);
  printf("    RETURNED\n");
  dump_mesh_node_set_beacon_reporting(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_init_rsp_t* cmd_mesh_prov_init() {
  dump_command_header("mesh_prov_init");
  struct gecko_msg_mesh_prov_init_rsp_t* resp = gecko_cmd_mesh_prov_init();
  printf("    RETURNED\n");
  dump_mesh_prov_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_scan_unprov_beacons_rsp_t* cmd_mesh_prov_scan_unprov_beacons() {
  dump_command_header("mesh_prov_scan_unprov_beacons");
  struct gecko_msg_mesh_prov_scan_unprov_beacons_rsp_t* resp = gecko_cmd_mesh_prov_scan_unprov_beacons();
  printf("    RETURNED\n");
  dump_mesh_prov_scan_unprov_beacons(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_provision_device_rsp_t* cmd_mesh_prov_provision_device(uint8 network_id,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("mesh_prov_provision_device");
  printf("  uint8 network_id: 0x%02x\n",(int)network_id);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_mesh_prov_provision_device_rsp_t* resp = gecko_cmd_mesh_prov_provision_device(network_id,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_mesh_prov_provision_device(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_create_network_rsp_t* cmd_mesh_prov_create_network(uint8 key_len, const uint8* key_data) {
  dump_command_header("mesh_prov_create_network");
  printf("  uint8 key_len: 0x%02x\n",(int)key_len);
  printf("  const uint8* key_data: 0x%p\n",key_data);
  struct gecko_msg_mesh_prov_create_network_rsp_t* resp = gecko_cmd_mesh_prov_create_network(key_len,key_data);
  printf("    RETURNED\n");
  dump_mesh_prov_create_network(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_get_dcd_rsp_t* cmd_mesh_prov_get_dcd(uint16 address,uint8 page) {
  dump_command_header("mesh_prov_get_dcd");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint8 page: 0x%02x\n",(int)page);
  struct gecko_msg_mesh_prov_get_dcd_rsp_t* resp = gecko_cmd_mesh_prov_get_dcd(address,page);
  printf("    RETURNED\n");
  dump_mesh_prov_get_dcd(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_get_config_rsp_t* cmd_mesh_prov_get_config(uint16 address,uint16 id,uint16 netkey_index) {
  dump_command_header("mesh_prov_get_config");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 id: 0x%04x\n",(int)id);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_get_config_rsp_t* resp = gecko_cmd_mesh_prov_get_config(address,id,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_get_config(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_set_config_rsp_t* cmd_mesh_prov_set_config(uint16 address,uint16 id,uint16 netkey_index,uint8 value_len, const uint8* value_data) {
  dump_command_header("mesh_prov_set_config");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 id: 0x%04x\n",(int)id);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_mesh_prov_set_config_rsp_t* resp = gecko_cmd_mesh_prov_set_config(address,id,netkey_index,value_len,value_data);
  printf("    RETURNED\n");
  dump_mesh_prov_set_config(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_create_appkey_rsp_t* cmd_mesh_prov_create_appkey(uint16 netkey_index,uint8 key_len, const uint8* key_data) {
  dump_command_header("mesh_prov_create_appkey");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint8 key_len: 0x%02x\n",(int)key_len);
  printf("  const uint8* key_data: 0x%p\n",key_data);
  struct gecko_msg_mesh_prov_create_appkey_rsp_t* resp = gecko_cmd_mesh_prov_create_appkey(netkey_index,key_len,key_data);
  printf("    RETURNED\n");
  dump_mesh_prov_create_appkey(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_oob_pkey_rsp_rsp_t* cmd_mesh_prov_oob_pkey_rsp(uint8 pkey_len, const uint8* pkey_data) {
  dump_command_header("mesh_prov_oob_pkey_rsp");
  printf("  uint8 pkey_len: 0x%02x\n",(int)pkey_len);
  printf("  const uint8* pkey_data: 0x%p\n",pkey_data);
  struct gecko_msg_mesh_prov_oob_pkey_rsp_rsp_t* resp = gecko_cmd_mesh_prov_oob_pkey_rsp(pkey_len,pkey_data);
  printf("    RETURNED\n");
  dump_mesh_prov_oob_pkey_rsp(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_oob_auth_rsp_rsp_t* cmd_mesh_prov_oob_auth_rsp(uint8 data_len, const uint8* data_data) {
  dump_command_header("mesh_prov_oob_auth_rsp");
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_mesh_prov_oob_auth_rsp_rsp_t* resp = gecko_cmd_mesh_prov_oob_auth_rsp(data_len,data_data);
  printf("    RETURNED\n");
  dump_mesh_prov_oob_auth_rsp(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_set_oob_requirements_rsp_t* cmd_mesh_prov_set_oob_requirements(uint8 public_key,uint8 auth_methods,uint16 output_actions,uint16 input_actions,uint8 min_size,uint8 max_size) {
  dump_command_header("mesh_prov_set_oob_requirements");
  printf("  uint8 public_key: 0x%02x\n",(int)public_key);
  printf("  uint8 auth_methods: 0x%02x\n",(int)auth_methods);
  printf("  uint16 output_actions: 0x%04x\n",(int)output_actions);
  printf("  uint16 input_actions: 0x%04x\n",(int)input_actions);
  printf("  uint8 min_size: 0x%02x\n",(int)min_size);
  printf("  uint8 max_size: 0x%02x\n",(int)max_size);
  struct gecko_msg_mesh_prov_set_oob_requirements_rsp_t* resp = gecko_cmd_mesh_prov_set_oob_requirements(public_key,auth_methods,output_actions,input_actions,min_size,max_size);
  printf("    RETURNED\n");
  dump_mesh_prov_set_oob_requirements(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_key_refresh_start_rsp_t* cmd_mesh_prov_key_refresh_start(uint16 netkey_index,uint8 num_appkeys,uint8 appkey_indices_len, const uint8* appkey_indices_data) {
  dump_command_header("mesh_prov_key_refresh_start");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint8 num_appkeys: 0x%02x\n",(int)num_appkeys);
  printf("  uint8 appkey_indices_len: 0x%02x\n",(int)appkey_indices_len);
  printf("  const uint8* appkey_indices_data: 0x%p\n",appkey_indices_data);
  struct gecko_msg_mesh_prov_key_refresh_start_rsp_t* resp = gecko_cmd_mesh_prov_key_refresh_start(netkey_index,num_appkeys,appkey_indices_len,appkey_indices_data);
  printf("    RETURNED\n");
  dump_mesh_prov_key_refresh_start(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_get_key_refresh_blacklist_rsp_t* cmd_mesh_prov_get_key_refresh_blacklist(uint16 key,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("mesh_prov_get_key_refresh_blacklist");
  printf("  uint16 key: 0x%04x\n",(int)key);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_mesh_prov_get_key_refresh_blacklist_rsp_t* resp = gecko_cmd_mesh_prov_get_key_refresh_blacklist(key,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_mesh_prov_get_key_refresh_blacklist(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_set_key_refresh_blacklist_rsp_t* cmd_mesh_prov_set_key_refresh_blacklist(uint16 key,uint8 status,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("mesh_prov_set_key_refresh_blacklist");
  printf("  uint16 key: 0x%04x\n",(int)key);
  printf("  uint8 status: 0x%02x\n",(int)status);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_mesh_prov_set_key_refresh_blacklist_rsp_t* resp = gecko_cmd_mesh_prov_set_key_refresh_blacklist(key,status,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_mesh_prov_set_key_refresh_blacklist(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_appkey_add_rsp_t* cmd_mesh_prov_appkey_add(uint16 address,uint16 netkey_index,uint16 appkey_index) {
  dump_command_header("mesh_prov_appkey_add");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_prov_appkey_add_rsp_t* resp = gecko_cmd_mesh_prov_appkey_add(address,netkey_index,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_appkey_add(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_appkey_delete_rsp_t* cmd_mesh_prov_appkey_delete(uint16 address,uint16 netkey_index,uint16 appkey_index) {
  dump_command_header("mesh_prov_appkey_delete");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_prov_appkey_delete_rsp_t* resp = gecko_cmd_mesh_prov_appkey_delete(address,netkey_index,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_appkey_delete(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_app_bind_rsp_t* cmd_mesh_prov_model_app_bind(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_prov_model_app_bind");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_prov_model_app_bind_rsp_t* resp = gecko_cmd_mesh_prov_model_app_bind(address,elem_address,netkey_index,appkey_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_prov_model_app_bind(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_app_unbind_rsp_t* cmd_mesh_prov_model_app_unbind(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_prov_model_app_unbind");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_prov_model_app_unbind_rsp_t* resp = gecko_cmd_mesh_prov_model_app_unbind(address,elem_address,netkey_index,appkey_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_prov_model_app_unbind(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_app_get_rsp_t* cmd_mesh_prov_model_app_get(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_prov_model_app_get");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_prov_model_app_get_rsp_t* resp = gecko_cmd_mesh_prov_model_app_get(address,elem_address,netkey_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_prov_model_app_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_sub_add_rsp_t* cmd_mesh_prov_model_sub_add(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 vendor_id,uint16 model_id,uint16 sub_address) {
  dump_command_header("mesh_prov_model_sub_add");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 sub_address: 0x%04x\n",(int)sub_address);
  struct gecko_msg_mesh_prov_model_sub_add_rsp_t* resp = gecko_cmd_mesh_prov_model_sub_add(address,elem_address,netkey_index,vendor_id,model_id,sub_address);
  printf("    RETURNED\n");
  dump_mesh_prov_model_sub_add(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_pub_set_rsp_t* cmd_mesh_prov_model_pub_set(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id,uint16 pub_address,uint8 ttl,uint8 period,uint8 retrans) {
  dump_command_header("mesh_prov_model_pub_set");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 pub_address: 0x%04x\n",(int)pub_address);
  printf("  uint8 ttl: 0x%02x\n",(int)ttl);
  printf("  uint8 period: 0x%02x\n",(int)period);
  printf("  uint8 retrans: 0x%02x\n",(int)retrans);
  struct gecko_msg_mesh_prov_model_pub_set_rsp_t* resp = gecko_cmd_mesh_prov_model_pub_set(address,elem_address,netkey_index,appkey_index,vendor_id,model_id,pub_address,ttl,period,retrans);
  printf("    RETURNED\n");
  dump_mesh_prov_model_pub_set(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_provision_gatt_device_rsp_t* cmd_mesh_prov_provision_gatt_device(uint8 network_id,uint8 connection,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("mesh_prov_provision_gatt_device");
  printf("  uint8 network_id: 0x%02x\n",(int)network_id);
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_mesh_prov_provision_gatt_device_rsp_t* resp = gecko_cmd_mesh_prov_provision_gatt_device(network_id,connection,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_mesh_prov_provision_gatt_device(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_ddb_get_rsp_t* cmd_mesh_prov_ddb_get(uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("mesh_prov_ddb_get");
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_mesh_prov_ddb_get_rsp_t* resp = gecko_cmd_mesh_prov_ddb_get(uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_mesh_prov_ddb_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_ddb_delete_rsp_t* cmd_mesh_prov_ddb_delete(uuid_128 uuid) {
  dump_command_header("mesh_prov_ddb_delete");
   printf("  aes_key_128 mesh_prov_ddb_delete: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",uuid.data[i]);
   printf("\n");
  struct gecko_msg_mesh_prov_ddb_delete_rsp_t* resp = gecko_cmd_mesh_prov_ddb_delete(uuid);
  printf("    RETURNED\n");
  dump_mesh_prov_ddb_delete(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_ddb_add_rsp_t* cmd_mesh_prov_ddb_add(uuid_128 uuid,aes_key_128 device_key,uint16 netkey_index,uint16 address,uint8 elements) {
  dump_command_header("mesh_prov_ddb_add");
   printf("  aes_key_128 mesh_prov_ddb_add: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",uuid.data[i]);
   printf("\n");
   printf("  aes_key_128 mesh_prov_ddb_add: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",device_key.data[i]);
   printf("\n");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint8 elements: 0x%02x\n",(int)elements);
  struct gecko_msg_mesh_prov_ddb_add_rsp_t* resp = gecko_cmd_mesh_prov_ddb_add(uuid,device_key,netkey_index,address,elements);
  printf("    RETURNED\n");
  dump_mesh_prov_ddb_add(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_ddb_list_devices_rsp_t* cmd_mesh_prov_ddb_list_devices() {
  dump_command_header("mesh_prov_ddb_list_devices");
  struct gecko_msg_mesh_prov_ddb_list_devices_rsp_t* resp = gecko_cmd_mesh_prov_ddb_list_devices();
  printf("    RETURNED\n");
  dump_mesh_prov_ddb_list_devices(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_network_add_rsp_t* cmd_mesh_prov_network_add(uint16 address,uint16 netkey_index) {
  dump_command_header("mesh_prov_network_add");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_network_add_rsp_t* resp = gecko_cmd_mesh_prov_network_add(address,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_network_add(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_network_delete_rsp_t* cmd_mesh_prov_network_delete(uint16 address,uint16 netkey_index) {
  dump_command_header("mesh_prov_network_delete");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_network_delete_rsp_t* resp = gecko_cmd_mesh_prov_network_delete(address,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_network_delete(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_nettx_get_rsp_t* cmd_mesh_prov_nettx_get(uint16 address) {
  dump_command_header("mesh_prov_nettx_get");
  printf("  uint16 address: 0x%04x\n",(int)address);
  struct gecko_msg_mesh_prov_nettx_get_rsp_t* resp = gecko_cmd_mesh_prov_nettx_get(address);
  printf("    RETURNED\n");
  dump_mesh_prov_nettx_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_nettx_set_rsp_t* cmd_mesh_prov_nettx_set(uint16 address,uint8 count,uint8 interval) {
  dump_command_header("mesh_prov_nettx_set");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint8 count: 0x%02x\n",(int)count);
  printf("  uint8 interval: 0x%02x\n",(int)interval);
  struct gecko_msg_mesh_prov_nettx_set_rsp_t* resp = gecko_cmd_mesh_prov_nettx_set(address,count,interval);
  printf("    RETURNED\n");
  dump_mesh_prov_nettx_set(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_sub_del_rsp_t* cmd_mesh_prov_model_sub_del(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 vendor_id,uint16 model_id,uint16 sub_address) {
  dump_command_header("mesh_prov_model_sub_del");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 sub_address: 0x%04x\n",(int)sub_address);
  struct gecko_msg_mesh_prov_model_sub_del_rsp_t* resp = gecko_cmd_mesh_prov_model_sub_del(address,elem_address,netkey_index,vendor_id,model_id,sub_address);
  printf("    RETURNED\n");
  dump_mesh_prov_model_sub_del(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_sub_add_va_rsp_t* cmd_mesh_prov_model_sub_add_va(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 vendor_id,uint16 model_id,uint8 sub_address_len, const uint8* sub_address_data) {
  dump_command_header("mesh_prov_model_sub_add_va");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint8 sub_address_len: 0x%02x\n",(int)sub_address_len);
  printf("  const uint8* sub_address_data: 0x%p\n",sub_address_data);
  struct gecko_msg_mesh_prov_model_sub_add_va_rsp_t* resp = gecko_cmd_mesh_prov_model_sub_add_va(address,elem_address,netkey_index,vendor_id,model_id,sub_address_len,sub_address_data);
  printf("    RETURNED\n");
  dump_mesh_prov_model_sub_add_va(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_sub_del_va_rsp_t* cmd_mesh_prov_model_sub_del_va(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 vendor_id,uint16 model_id,uint8 sub_address_len, const uint8* sub_address_data) {
  dump_command_header("mesh_prov_model_sub_del_va");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint8 sub_address_len: 0x%02x\n",(int)sub_address_len);
  printf("  const uint8* sub_address_data: 0x%p\n",sub_address_data);
  struct gecko_msg_mesh_prov_model_sub_del_va_rsp_t* resp = gecko_cmd_mesh_prov_model_sub_del_va(address,elem_address,netkey_index,vendor_id,model_id,sub_address_len,sub_address_data);
  printf("    RETURNED\n");
  dump_mesh_prov_model_sub_del_va(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_sub_set_rsp_t* cmd_mesh_prov_model_sub_set(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 vendor_id,uint16 model_id,uint16 sub_address) {
  dump_command_header("mesh_prov_model_sub_set");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 sub_address: 0x%04x\n",(int)sub_address);
  struct gecko_msg_mesh_prov_model_sub_set_rsp_t* resp = gecko_cmd_mesh_prov_model_sub_set(address,elem_address,netkey_index,vendor_id,model_id,sub_address);
  printf("    RETURNED\n");
  dump_mesh_prov_model_sub_set(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_sub_set_va_rsp_t* cmd_mesh_prov_model_sub_set_va(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 vendor_id,uint16 model_id,uint8 sub_address_len, const uint8* sub_address_data) {
  dump_command_header("mesh_prov_model_sub_set_va");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint8 sub_address_len: 0x%02x\n",(int)sub_address_len);
  printf("  const uint8* sub_address_data: 0x%p\n",sub_address_data);
  struct gecko_msg_mesh_prov_model_sub_set_va_rsp_t* resp = gecko_cmd_mesh_prov_model_sub_set_va(address,elem_address,netkey_index,vendor_id,model_id,sub_address_len,sub_address_data);
  printf("    RETURNED\n");
  dump_mesh_prov_model_sub_set_va(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_heartbeat_publication_get_rsp_t* cmd_mesh_prov_heartbeat_publication_get(uint16 address,uint16 netkey_index) {
  dump_command_header("mesh_prov_heartbeat_publication_get");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_heartbeat_publication_get_rsp_t* resp = gecko_cmd_mesh_prov_heartbeat_publication_get(address,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_heartbeat_publication_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_heartbeat_publication_set_rsp_t* cmd_mesh_prov_heartbeat_publication_set(uint16 address,uint16 netkey_index,uint16 publication_address,uint8 count_log,uint8 period_log,uint8 ttl,uint16 features,uint16 publication_netkey_index) {
  dump_command_header("mesh_prov_heartbeat_publication_set");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 publication_address: 0x%04x\n",(int)publication_address);
  printf("  uint8 count_log: 0x%02x\n",(int)count_log);
  printf("  uint8 period_log: 0x%02x\n",(int)period_log);
  printf("  uint8 ttl: 0x%02x\n",(int)ttl);
  printf("  uint16 features: 0x%04x\n",(int)features);
  printf("  uint16 publication_netkey_index: 0x%04x\n",(int)publication_netkey_index);
  struct gecko_msg_mesh_prov_heartbeat_publication_set_rsp_t* resp = gecko_cmd_mesh_prov_heartbeat_publication_set(address,netkey_index,publication_address,count_log,period_log,ttl,features,publication_netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_heartbeat_publication_set(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_heartbeat_subscription_get_rsp_t* cmd_mesh_prov_heartbeat_subscription_get(uint16 address,uint16 netkey_index) {
  dump_command_header("mesh_prov_heartbeat_subscription_get");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_heartbeat_subscription_get_rsp_t* resp = gecko_cmd_mesh_prov_heartbeat_subscription_get(address,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_heartbeat_subscription_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_heartbeat_subscription_set_rsp_t* cmd_mesh_prov_heartbeat_subscription_set(uint16 address,uint16 netkey_index,uint16 subscription_source,uint16 subscription_destination,uint8 period_log) {
  dump_command_header("mesh_prov_heartbeat_subscription_set");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 subscription_source: 0x%04x\n",(int)subscription_source);
  printf("  uint16 subscription_destination: 0x%04x\n",(int)subscription_destination);
  printf("  uint8 period_log: 0x%02x\n",(int)period_log);
  struct gecko_msg_mesh_prov_heartbeat_subscription_set_rsp_t* resp = gecko_cmd_mesh_prov_heartbeat_subscription_set(address,netkey_index,subscription_source,subscription_destination,period_log);
  printf("    RETURNED\n");
  dump_mesh_prov_heartbeat_subscription_set(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_relay_get_rsp_t* cmd_mesh_prov_relay_get(uint16 address,uint16 netkey_index) {
  dump_command_header("mesh_prov_relay_get");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_relay_get_rsp_t* resp = gecko_cmd_mesh_prov_relay_get(address,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_relay_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_relay_set_rsp_t* cmd_mesh_prov_relay_set(uint16 address,uint16 netkey_index,uint8 relay,uint8 count,uint8 interval) {
  dump_command_header("mesh_prov_relay_set");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint8 relay: 0x%02x\n",(int)relay);
  printf("  uint8 count: 0x%02x\n",(int)count);
  printf("  uint8 interval: 0x%02x\n",(int)interval);
  struct gecko_msg_mesh_prov_relay_set_rsp_t* resp = gecko_cmd_mesh_prov_relay_set(address,netkey_index,relay,count,interval);
  printf("    RETURNED\n");
  dump_mesh_prov_relay_set(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_reset_node_rsp_t* cmd_mesh_prov_reset_node(uint16 address,uint16 netkey_index) {
  dump_command_header("mesh_prov_reset_node");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_reset_node_rsp_t* resp = gecko_cmd_mesh_prov_reset_node(address,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_reset_node(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_appkey_get_rsp_t* cmd_mesh_prov_appkey_get(uint16 address,uint16 netkey_index) {
  dump_command_header("mesh_prov_appkey_get");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_appkey_get_rsp_t* resp = gecko_cmd_mesh_prov_appkey_get(address,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_appkey_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_network_get_rsp_t* cmd_mesh_prov_network_get(uint16 address) {
  dump_command_header("mesh_prov_network_get");
  printf("  uint16 address: 0x%04x\n",(int)address);
  struct gecko_msg_mesh_prov_network_get_rsp_t* resp = gecko_cmd_mesh_prov_network_get(address);
  printf("    RETURNED\n");
  dump_mesh_prov_network_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_sub_clear_rsp_t* cmd_mesh_prov_model_sub_clear(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_prov_model_sub_clear");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_prov_model_sub_clear_rsp_t* resp = gecko_cmd_mesh_prov_model_sub_clear(address,elem_address,netkey_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_prov_model_sub_clear(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_pub_get_rsp_t* cmd_mesh_prov_model_pub_get(uint16 address,uint16 elem_address,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_prov_model_pub_get");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_prov_model_pub_get_rsp_t* resp = gecko_cmd_mesh_prov_model_pub_get(address,elem_address,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_prov_model_pub_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_pub_set_va_rsp_t* cmd_mesh_prov_model_pub_set_va(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id,uint8 ttl,uint8 period,uint8 retrans,uint8 pub_address_len, const uint8* pub_address_data) {
  dump_command_header("mesh_prov_model_pub_set_va");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint8 ttl: 0x%02x\n",(int)ttl);
  printf("  uint8 period: 0x%02x\n",(int)period);
  printf("  uint8 retrans: 0x%02x\n",(int)retrans);
  printf("  uint8 pub_address_len: 0x%02x\n",(int)pub_address_len);
  printf("  const uint8* pub_address_data: 0x%p\n",pub_address_data);
  struct gecko_msg_mesh_prov_model_pub_set_va_rsp_t* resp = gecko_cmd_mesh_prov_model_pub_set_va(address,elem_address,netkey_index,appkey_index,vendor_id,model_id,ttl,period,retrans,pub_address_len,pub_address_data);
  printf("    RETURNED\n");
  dump_mesh_prov_model_pub_set_va(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_pub_set_cred_rsp_t* cmd_mesh_prov_model_pub_set_cred(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id,uint16 pub_address,uint8 ttl,uint8 period,uint8 retrans,uint8 credentials) {
  dump_command_header("mesh_prov_model_pub_set_cred");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 pub_address: 0x%04x\n",(int)pub_address);
  printf("  uint8 ttl: 0x%02x\n",(int)ttl);
  printf("  uint8 period: 0x%02x\n",(int)period);
  printf("  uint8 retrans: 0x%02x\n",(int)retrans);
  printf("  uint8 credentials: 0x%02x\n",(int)credentials);
  struct gecko_msg_mesh_prov_model_pub_set_cred_rsp_t* resp = gecko_cmd_mesh_prov_model_pub_set_cred(address,elem_address,netkey_index,appkey_index,vendor_id,model_id,pub_address,ttl,period,retrans,credentials);
  printf("    RETURNED\n");
  dump_mesh_prov_model_pub_set_cred(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_pub_set_va_cred_rsp_t* cmd_mesh_prov_model_pub_set_va_cred(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id,uint8 ttl,uint8 period,uint8 retrans,uint8 credentials,uint8 pub_address_len, const uint8* pub_address_data) {
  dump_command_header("mesh_prov_model_pub_set_va_cred");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint8 ttl: 0x%02x\n",(int)ttl);
  printf("  uint8 period: 0x%02x\n",(int)period);
  printf("  uint8 retrans: 0x%02x\n",(int)retrans);
  printf("  uint8 credentials: 0x%02x\n",(int)credentials);
  printf("  uint8 pub_address_len: 0x%02x\n",(int)pub_address_len);
  printf("  const uint8* pub_address_data: 0x%p\n",pub_address_data);
  struct gecko_msg_mesh_prov_model_pub_set_va_cred_rsp_t* resp = gecko_cmd_mesh_prov_model_pub_set_va_cred(address,elem_address,netkey_index,appkey_index,vendor_id,model_id,ttl,period,retrans,credentials,pub_address_len,pub_address_data);
  printf("    RETURNED\n");
  dump_mesh_prov_model_pub_set_va_cred(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_model_sub_get_rsp_t* cmd_mesh_prov_model_sub_get(uint16 address,uint16 elem_address,uint16 netkey_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_prov_model_sub_get");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 elem_address: 0x%04x\n",(int)elem_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_prov_model_sub_get_rsp_t* resp = gecko_cmd_mesh_prov_model_sub_get(address,elem_address,netkey_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_prov_model_sub_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_friend_timeout_get_rsp_t* cmd_mesh_prov_friend_timeout_get(uint16 address,uint16 netkey_index,uint16 lpn_address) {
  dump_command_header("mesh_prov_friend_timeout_get");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 lpn_address: 0x%04x\n",(int)lpn_address);
  struct gecko_msg_mesh_prov_friend_timeout_get_rsp_t* resp = gecko_cmd_mesh_prov_friend_timeout_get(address,netkey_index,lpn_address);
  printf("    RETURNED\n");
  dump_mesh_prov_friend_timeout_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_get_default_configuration_timeout_rsp_t* cmd_mesh_prov_get_default_configuration_timeout() {
  dump_command_header("mesh_prov_get_default_configuration_timeout");
  struct gecko_msg_mesh_prov_get_default_configuration_timeout_rsp_t* resp = gecko_cmd_mesh_prov_get_default_configuration_timeout();
  printf("    RETURNED\n");
  dump_mesh_prov_get_default_configuration_timeout(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_set_default_configuration_timeout_rsp_t* cmd_mesh_prov_set_default_configuration_timeout(uint32 timeout,uint32 lpn_timeout) {
  dump_command_header("mesh_prov_set_default_configuration_timeout");
  printf("  uint32 timeout: 0x%08x\n",(int)timeout);
  printf("  uint32 lpn_timeout: 0x%08x\n",(int)lpn_timeout);
  struct gecko_msg_mesh_prov_set_default_configuration_timeout_rsp_t* resp = gecko_cmd_mesh_prov_set_default_configuration_timeout(timeout,lpn_timeout);
  printf("    RETURNED\n");
  dump_mesh_prov_set_default_configuration_timeout(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_provision_device_with_address_rsp_t* cmd_mesh_prov_provision_device_with_address(uint8 network_id,uint16 address,uint8 elements,uint8 attention_timer,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("mesh_prov_provision_device_with_address");
  printf("  uint8 network_id: 0x%02x\n",(int)network_id);
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint8 elements: 0x%02x\n",(int)elements);
  printf("  uint8 attention_timer: 0x%02x\n",(int)attention_timer);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_mesh_prov_provision_device_with_address_rsp_t* resp = gecko_cmd_mesh_prov_provision_device_with_address(network_id,address,elements,attention_timer,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_mesh_prov_provision_device_with_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_provision_gatt_device_with_address_rsp_t* cmd_mesh_prov_provision_gatt_device_with_address(uint8 network_id,uint8 connection,uint16 address,uint8 elements,uint8 attention_timer,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("mesh_prov_provision_gatt_device_with_address");
  printf("  uint8 network_id: 0x%02x\n",(int)network_id);
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint8 elements: 0x%02x\n",(int)elements);
  printf("  uint8 attention_timer: 0x%02x\n",(int)attention_timer);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_mesh_prov_provision_gatt_device_with_address_rsp_t* resp = gecko_cmd_mesh_prov_provision_gatt_device_with_address(network_id,connection,address,elements,attention_timer,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_mesh_prov_provision_gatt_device_with_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_initialize_network_rsp_t* cmd_mesh_prov_initialize_network(uint16 address,uint32 ivi) {
  dump_command_header("mesh_prov_initialize_network");
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint32 ivi: 0x%08x\n",(int)ivi);
  struct gecko_msg_mesh_prov_initialize_network_rsp_t* resp = gecko_cmd_mesh_prov_initialize_network(address,ivi);
  printf("    RETURNED\n");
  dump_mesh_prov_initialize_network(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_get_key_refresh_appkey_blacklist_rsp_t* cmd_mesh_prov_get_key_refresh_appkey_blacklist(uint16 netkey_index,uint16 appkey_index,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("mesh_prov_get_key_refresh_appkey_blacklist");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_mesh_prov_get_key_refresh_appkey_blacklist_rsp_t* resp = gecko_cmd_mesh_prov_get_key_refresh_appkey_blacklist(netkey_index,appkey_index,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_mesh_prov_get_key_refresh_appkey_blacklist(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_set_key_refresh_appkey_blacklist_rsp_t* cmd_mesh_prov_set_key_refresh_appkey_blacklist(uint16 netkey_index,uint16 appkey_index,uint8 status,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("mesh_prov_set_key_refresh_appkey_blacklist");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 status: 0x%02x\n",(int)status);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_mesh_prov_set_key_refresh_appkey_blacklist_rsp_t* resp = gecko_cmd_mesh_prov_set_key_refresh_appkey_blacklist(netkey_index,appkey_index,status,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_mesh_prov_set_key_refresh_appkey_blacklist(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_stop_scan_unprov_beacons_rsp_t* cmd_mesh_prov_stop_scan_unprov_beacons() {
  dump_command_header("mesh_prov_stop_scan_unprov_beacons");
  struct gecko_msg_mesh_prov_stop_scan_unprov_beacons_rsp_t* resp = gecko_cmd_mesh_prov_stop_scan_unprov_beacons();
  printf("    RETURNED\n");
  dump_mesh_prov_stop_scan_unprov_beacons(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_ddb_update_netkey_index_rsp_t* cmd_mesh_prov_ddb_update_netkey_index(uuid_128 uuid,uint16 netkey_index) {
  dump_command_header("mesh_prov_ddb_update_netkey_index");
   printf("  aes_key_128 mesh_prov_ddb_update_netkey_index: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",uuid.data[i]);
   printf("\n");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_ddb_update_netkey_index_rsp_t* resp = gecko_cmd_mesh_prov_ddb_update_netkey_index(uuid,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_ddb_update_netkey_index(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_key_refresh_suspend_rsp_t* cmd_mesh_prov_key_refresh_suspend(uint16 netkey_index) {
  dump_command_header("mesh_prov_key_refresh_suspend");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_key_refresh_suspend_rsp_t* resp = gecko_cmd_mesh_prov_key_refresh_suspend(netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_key_refresh_suspend(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_key_refresh_resume_rsp_t* cmd_mesh_prov_key_refresh_resume(uint16 netkey_index) {
  dump_command_header("mesh_prov_key_refresh_resume");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_key_refresh_resume_rsp_t* resp = gecko_cmd_mesh_prov_key_refresh_resume(netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_key_refresh_resume(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_get_key_refresh_phase_rsp_t* cmd_mesh_prov_get_key_refresh_phase(uint16 netkey_index) {
  dump_command_header("mesh_prov_get_key_refresh_phase");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_get_key_refresh_phase_rsp_t* resp = gecko_cmd_mesh_prov_get_key_refresh_phase(netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_get_key_refresh_phase(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_key_refresh_start_from_phase_rsp_t* cmd_mesh_prov_key_refresh_start_from_phase(uint8 phase,uint16 netkey_index,uint8 num_appkeys,uint8 appkey_indices_len, const uint8* appkey_indices_data) {
  dump_command_header("mesh_prov_key_refresh_start_from_phase");
  printf("  uint8 phase: 0x%02x\n",(int)phase);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint8 num_appkeys: 0x%02x\n",(int)num_appkeys);
  printf("  uint8 appkey_indices_len: 0x%02x\n",(int)appkey_indices_len);
  printf("  const uint8* appkey_indices_data: 0x%p\n",appkey_indices_data);
  struct gecko_msg_mesh_prov_key_refresh_start_from_phase_rsp_t* resp = gecko_cmd_mesh_prov_key_refresh_start_from_phase(phase,netkey_index,num_appkeys,appkey_indices_len,appkey_indices_data);
  printf("    RETURNED\n");
  dump_mesh_prov_key_refresh_start_from_phase(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_prov_flush_key_refresh_state_rsp_t* cmd_mesh_prov_flush_key_refresh_state(uint16 netkey_index) {
  dump_command_header("mesh_prov_flush_key_refresh_state");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_prov_flush_key_refresh_state_rsp_t* resp = gecko_cmd_mesh_prov_flush_key_refresh_state(netkey_index);
  printf("    RETURNED\n");
  dump_mesh_prov_flush_key_refresh_state(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_proxy_connect_rsp_t* cmd_mesh_proxy_connect(uint8 connection) {
  dump_command_header("mesh_proxy_connect");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_mesh_proxy_connect_rsp_t* resp = gecko_cmd_mesh_proxy_connect(connection);
  printf("    RETURNED\n");
  dump_mesh_proxy_connect(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_proxy_disconnect_rsp_t* cmd_mesh_proxy_disconnect(uint32 handle) {
  dump_command_header("mesh_proxy_disconnect");
  printf("  uint32 handle: 0x%08x\n",(int)handle);
  struct gecko_msg_mesh_proxy_disconnect_rsp_t* resp = gecko_cmd_mesh_proxy_disconnect(handle);
  printf("    RETURNED\n");
  dump_mesh_proxy_disconnect(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_proxy_set_filter_type_rsp_t* cmd_mesh_proxy_set_filter_type(uint32 handle,uint8 type,uint16 key) {
  dump_command_header("mesh_proxy_set_filter_type");
  printf("  uint32 handle: 0x%08x\n",(int)handle);
  printf("  uint8 type: 0x%02x\n",(int)type);
  printf("  uint16 key: 0x%04x\n",(int)key);
  struct gecko_msg_mesh_proxy_set_filter_type_rsp_t* resp = gecko_cmd_mesh_proxy_set_filter_type(handle,type,key);
  printf("    RETURNED\n");
  dump_mesh_proxy_set_filter_type(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_proxy_allow_rsp_t* cmd_mesh_proxy_allow(uint32 handle,uint16 address,uint16 key) {
  dump_command_header("mesh_proxy_allow");
  printf("  uint32 handle: 0x%08x\n",(int)handle);
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 key: 0x%04x\n",(int)key);
  struct gecko_msg_mesh_proxy_allow_rsp_t* resp = gecko_cmd_mesh_proxy_allow(handle,address,key);
  printf("    RETURNED\n");
  dump_mesh_proxy_allow(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_proxy_deny_rsp_t* cmd_mesh_proxy_deny(uint32 handle,uint16 address,uint16 key) {
  dump_command_header("mesh_proxy_deny");
  printf("  uint32 handle: 0x%08x\n",(int)handle);
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 key: 0x%04x\n",(int)key);
  struct gecko_msg_mesh_proxy_deny_rsp_t* resp = gecko_cmd_mesh_proxy_deny(handle,address,key);
  printf("    RETURNED\n");
  dump_mesh_proxy_deny(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_vendor_model_send_rsp_t* cmd_mesh_vendor_model_send(uint16 elem_index,uint16 vendor_id,uint16 model_id,uint16 destination_address,int8 va_index,uint16 appkey_index,uint8 nonrelayed,uint8 opcode,uint8 final,uint8 payload_len, const uint8* payload_data) {
  dump_command_header("mesh_vendor_model_send");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 destination_address: 0x%04x\n",(int)destination_address);
  printf("  int8  va_index: 0x%02x\n",(int)va_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 nonrelayed: 0x%02x\n",(int)nonrelayed);
  printf("  uint8 opcode: 0x%02x\n",(int)opcode);
  printf("  uint8 final: 0x%02x\n",(int)final);
  printf("  uint8 payload_len: 0x%02x\n",(int)payload_len);
  printf("  const uint8* payload_data: 0x%p\n",payload_data);
  struct gecko_msg_mesh_vendor_model_send_rsp_t* resp = gecko_cmd_mesh_vendor_model_send(elem_index,vendor_id,model_id,destination_address,va_index,appkey_index,nonrelayed,opcode,final,payload_len,payload_data);
  printf("    RETURNED\n");
  dump_mesh_vendor_model_send(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_vendor_model_set_publication_rsp_t* cmd_mesh_vendor_model_set_publication(uint16 elem_index,uint16 vendor_id,uint16 model_id,uint8 opcode,uint8 final,uint8 payload_len, const uint8* payload_data) {
  dump_command_header("mesh_vendor_model_set_publication");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint8 opcode: 0x%02x\n",(int)opcode);
  printf("  uint8 final: 0x%02x\n",(int)final);
  printf("  uint8 payload_len: 0x%02x\n",(int)payload_len);
  printf("  const uint8* payload_data: 0x%p\n",payload_data);
  struct gecko_msg_mesh_vendor_model_set_publication_rsp_t* resp = gecko_cmd_mesh_vendor_model_set_publication(elem_index,vendor_id,model_id,opcode,final,payload_len,payload_data);
  printf("    RETURNED\n");
  dump_mesh_vendor_model_set_publication(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_vendor_model_clear_publication_rsp_t* cmd_mesh_vendor_model_clear_publication(uint16 elem_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_vendor_model_clear_publication");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_vendor_model_clear_publication_rsp_t* resp = gecko_cmd_mesh_vendor_model_clear_publication(elem_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_vendor_model_clear_publication(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_vendor_model_publish_rsp_t* cmd_mesh_vendor_model_publish(uint16 elem_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_vendor_model_publish");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_vendor_model_publish_rsp_t* resp = gecko_cmd_mesh_vendor_model_publish(elem_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_vendor_model_publish(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_vendor_model_init_rsp_t* cmd_mesh_vendor_model_init(uint16 elem_index,uint16 vendor_id,uint16 model_id,uint8 publish,uint8 opcodes_len, const uint8* opcodes_data) {
  dump_command_header("mesh_vendor_model_init");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint8 publish: 0x%02x\n",(int)publish);
  printf("  uint8 opcodes_len: 0x%02x\n",(int)opcodes_len);
  printf("  const uint8* opcodes_data: 0x%p\n",opcodes_data);
  struct gecko_msg_mesh_vendor_model_init_rsp_t* resp = gecko_cmd_mesh_vendor_model_init(elem_index,vendor_id,model_id,publish,opcodes_len,opcodes_data);
  printf("    RETURNED\n");
  dump_mesh_vendor_model_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_vendor_model_deinit_rsp_t* cmd_mesh_vendor_model_deinit(uint16 elem_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_vendor_model_deinit");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_vendor_model_deinit_rsp_t* resp = gecko_cmd_mesh_vendor_model_deinit(elem_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_vendor_model_deinit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_health_client_get_rsp_t* cmd_mesh_health_client_get(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint16 vendor_id) {
  dump_command_header("mesh_health_client_get");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  struct gecko_msg_mesh_health_client_get_rsp_t* resp = gecko_cmd_mesh_health_client_get(elem_index,server_address,appkey_index,vendor_id);
  printf("    RETURNED\n");
  dump_mesh_health_client_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_health_client_clear_rsp_t* cmd_mesh_health_client_clear(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint16 vendor_id,uint8 reliable) {
  dump_command_header("mesh_health_client_clear");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint8 reliable: 0x%02x\n",(int)reliable);
  struct gecko_msg_mesh_health_client_clear_rsp_t* resp = gecko_cmd_mesh_health_client_clear(elem_index,server_address,appkey_index,vendor_id,reliable);
  printf("    RETURNED\n");
  dump_mesh_health_client_clear(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_health_client_test_rsp_t* cmd_mesh_health_client_test(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 test_id,uint16 vendor_id,uint8 reliable) {
  dump_command_header("mesh_health_client_test");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 test_id: 0x%02x\n",(int)test_id);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint8 reliable: 0x%02x\n",(int)reliable);
  struct gecko_msg_mesh_health_client_test_rsp_t* resp = gecko_cmd_mesh_health_client_test(elem_index,server_address,appkey_index,test_id,vendor_id,reliable);
  printf("    RETURNED\n");
  dump_mesh_health_client_test(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_health_client_get_period_rsp_t* cmd_mesh_health_client_get_period(uint16 elem_index,uint16 server_address,uint16 appkey_index) {
  dump_command_header("mesh_health_client_get_period");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_health_client_get_period_rsp_t* resp = gecko_cmd_mesh_health_client_get_period(elem_index,server_address,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_health_client_get_period(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_health_client_set_period_rsp_t* cmd_mesh_health_client_set_period(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 period,uint8 reliable) {
  dump_command_header("mesh_health_client_set_period");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 period: 0x%02x\n",(int)period);
  printf("  uint8 reliable: 0x%02x\n",(int)reliable);
  struct gecko_msg_mesh_health_client_set_period_rsp_t* resp = gecko_cmd_mesh_health_client_set_period(elem_index,server_address,appkey_index,period,reliable);
  printf("    RETURNED\n");
  dump_mesh_health_client_set_period(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_health_client_get_attention_rsp_t* cmd_mesh_health_client_get_attention(uint16 elem_index,uint16 server_address,uint16 appkey_index) {
  dump_command_header("mesh_health_client_get_attention");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_health_client_get_attention_rsp_t* resp = gecko_cmd_mesh_health_client_get_attention(elem_index,server_address,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_health_client_get_attention(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_health_client_set_attention_rsp_t* cmd_mesh_health_client_set_attention(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 attention,uint8 reliable) {
  dump_command_header("mesh_health_client_set_attention");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 attention: 0x%02x\n",(int)attention);
  printf("  uint8 reliable: 0x%02x\n",(int)reliable);
  struct gecko_msg_mesh_health_client_set_attention_rsp_t* resp = gecko_cmd_mesh_health_client_set_attention(elem_index,server_address,appkey_index,attention,reliable);
  printf("    RETURNED\n");
  dump_mesh_health_client_set_attention(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_health_server_set_fault_rsp_t* cmd_mesh_health_server_set_fault(uint16 elem_index,uint8 id) {
  dump_command_header("mesh_health_server_set_fault");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint8 id: 0x%02x\n",(int)id);
  struct gecko_msg_mesh_health_server_set_fault_rsp_t* resp = gecko_cmd_mesh_health_server_set_fault(elem_index,id);
  printf("    RETURNED\n");
  dump_mesh_health_server_set_fault(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_health_server_clear_fault_rsp_t* cmd_mesh_health_server_clear_fault(uint16 elem_index,uint8 id) {
  dump_command_header("mesh_health_server_clear_fault");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint8 id: 0x%02x\n",(int)id);
  struct gecko_msg_mesh_health_server_clear_fault_rsp_t* resp = gecko_cmd_mesh_health_server_clear_fault(elem_index,id);
  printf("    RETURNED\n");
  dump_mesh_health_server_clear_fault(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_health_server_test_response_rsp_t* cmd_mesh_health_server_test_response(uint16 elem_index,uint16 client_address,uint16 appkey_index,uint16 vendor_id) {
  dump_command_header("mesh_health_server_test_response");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 client_address: 0x%04x\n",(int)client_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  struct gecko_msg_mesh_health_server_test_response_rsp_t* resp = gecko_cmd_mesh_health_server_test_response(elem_index,client_address,appkey_index,vendor_id);
  printf("    RETURNED\n");
  dump_mesh_health_server_test_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_get_rsp_t* cmd_mesh_generic_client_get(uint16 model_id,uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 type) {
  dump_command_header("mesh_generic_client_get");
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 type: 0x%02x\n",(int)type);
  struct gecko_msg_mesh_generic_client_get_rsp_t* resp = gecko_cmd_mesh_generic_client_get(model_id,elem_index,server_address,appkey_index,type);
  printf("    RETURNED\n");
  dump_mesh_generic_client_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_set_rsp_t* cmd_mesh_generic_client_set(uint16 model_id,uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 tid,uint32 transition,uint16 delay,uint16 flags,uint8 type,uint8 parameters_len, const uint8* parameters_data) {
  dump_command_header("mesh_generic_client_set");
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 tid: 0x%02x\n",(int)tid);
  printf("  uint32 transition: 0x%08x\n",(int)transition);
  printf("  uint16 delay: 0x%04x\n",(int)delay);
  printf("  uint16 flags: 0x%04x\n",(int)flags);
  printf("  uint8 type: 0x%02x\n",(int)type);
  printf("  uint8 parameters_len: 0x%02x\n",(int)parameters_len);
  printf("  const uint8* parameters_data: 0x%p\n",parameters_data);
  struct gecko_msg_mesh_generic_client_set_rsp_t* resp = gecko_cmd_mesh_generic_client_set(model_id,elem_index,server_address,appkey_index,tid,transition,delay,flags,type,parameters_len,parameters_data);
  printf("    RETURNED\n");
  dump_mesh_generic_client_set(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_publish_rsp_t* cmd_mesh_generic_client_publish(uint16 model_id,uint16 elem_index,uint8 tid,uint32 transition,uint16 delay,uint16 flags,uint8 type,uint8 parameters_len, const uint8* parameters_data) {
  dump_command_header("mesh_generic_client_publish");
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint8 tid: 0x%02x\n",(int)tid);
  printf("  uint32 transition: 0x%08x\n",(int)transition);
  printf("  uint16 delay: 0x%04x\n",(int)delay);
  printf("  uint16 flags: 0x%04x\n",(int)flags);
  printf("  uint8 type: 0x%02x\n",(int)type);
  printf("  uint8 parameters_len: 0x%02x\n",(int)parameters_len);
  printf("  const uint8* parameters_data: 0x%p\n",parameters_data);
  struct gecko_msg_mesh_generic_client_publish_rsp_t* resp = gecko_cmd_mesh_generic_client_publish(model_id,elem_index,tid,transition,delay,flags,type,parameters_len,parameters_data);
  printf("    RETURNED\n");
  dump_mesh_generic_client_publish(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_get_params_rsp_t* cmd_mesh_generic_client_get_params(uint16 model_id,uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 type,uint8 parameters_len, const uint8* parameters_data) {
  dump_command_header("mesh_generic_client_get_params");
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 type: 0x%02x\n",(int)type);
  printf("  uint8 parameters_len: 0x%02x\n",(int)parameters_len);
  printf("  const uint8* parameters_data: 0x%p\n",parameters_data);
  struct gecko_msg_mesh_generic_client_get_params_rsp_t* resp = gecko_cmd_mesh_generic_client_get_params(model_id,elem_index,server_address,appkey_index,type,parameters_len,parameters_data);
  printf("    RETURNED\n");
  dump_mesh_generic_client_get_params(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_rsp_t* cmd_mesh_generic_client_init() {
  dump_command_header("mesh_generic_client_init");
  struct gecko_msg_mesh_generic_client_init_rsp_t* resp = gecko_cmd_mesh_generic_client_init();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_common_rsp_t* cmd_mesh_generic_client_init_common() {
  dump_command_header("mesh_generic_client_init_common");
  struct gecko_msg_mesh_generic_client_init_common_rsp_t* resp = gecko_cmd_mesh_generic_client_init_common();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init_common(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_on_off_rsp_t* cmd_mesh_generic_client_init_on_off() {
  dump_command_header("mesh_generic_client_init_on_off");
  struct gecko_msg_mesh_generic_client_init_on_off_rsp_t* resp = gecko_cmd_mesh_generic_client_init_on_off();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init_on_off(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_level_rsp_t* cmd_mesh_generic_client_init_level() {
  dump_command_header("mesh_generic_client_init_level");
  struct gecko_msg_mesh_generic_client_init_level_rsp_t* resp = gecko_cmd_mesh_generic_client_init_level();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init_level(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_default_transition_time_rsp_t* cmd_mesh_generic_client_init_default_transition_time() {
  dump_command_header("mesh_generic_client_init_default_transition_time");
  struct gecko_msg_mesh_generic_client_init_default_transition_time_rsp_t* resp = gecko_cmd_mesh_generic_client_init_default_transition_time();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init_default_transition_time(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_power_on_off_rsp_t* cmd_mesh_generic_client_init_power_on_off() {
  dump_command_header("mesh_generic_client_init_power_on_off");
  struct gecko_msg_mesh_generic_client_init_power_on_off_rsp_t* resp = gecko_cmd_mesh_generic_client_init_power_on_off();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init_power_on_off(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_power_level_rsp_t* cmd_mesh_generic_client_init_power_level() {
  dump_command_header("mesh_generic_client_init_power_level");
  struct gecko_msg_mesh_generic_client_init_power_level_rsp_t* resp = gecko_cmd_mesh_generic_client_init_power_level();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init_power_level(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_battery_rsp_t* cmd_mesh_generic_client_init_battery() {
  dump_command_header("mesh_generic_client_init_battery");
  struct gecko_msg_mesh_generic_client_init_battery_rsp_t* resp = gecko_cmd_mesh_generic_client_init_battery();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init_battery(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_location_rsp_t* cmd_mesh_generic_client_init_location() {
  dump_command_header("mesh_generic_client_init_location");
  struct gecko_msg_mesh_generic_client_init_location_rsp_t* resp = gecko_cmd_mesh_generic_client_init_location();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init_location(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_property_rsp_t* cmd_mesh_generic_client_init_property() {
  dump_command_header("mesh_generic_client_init_property");
  struct gecko_msg_mesh_generic_client_init_property_rsp_t* resp = gecko_cmd_mesh_generic_client_init_property();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init_property(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_lightness_rsp_t* cmd_mesh_generic_client_init_lightness() {
  dump_command_header("mesh_generic_client_init_lightness");
  struct gecko_msg_mesh_generic_client_init_lightness_rsp_t* resp = gecko_cmd_mesh_generic_client_init_lightness();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init_lightness(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_client_init_ctl_rsp_t* cmd_mesh_generic_client_init_ctl() {
  dump_command_header("mesh_generic_client_init_ctl");
  struct gecko_msg_mesh_generic_client_init_ctl_rsp_t* resp = gecko_cmd_mesh_generic_client_init_ctl();
  printf("    RETURNED\n");
  dump_mesh_generic_client_init_ctl(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_response_rsp_t* cmd_mesh_generic_server_response(uint16 model_id,uint16 elem_index,uint16 client_address,uint16 appkey_index,uint32 remaining,uint16 flags,uint8 type,uint8 parameters_len, const uint8* parameters_data) {
  dump_command_header("mesh_generic_server_response");
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 client_address: 0x%04x\n",(int)client_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint32 remaining: 0x%08x\n",(int)remaining);
  printf("  uint16 flags: 0x%04x\n",(int)flags);
  printf("  uint8 type: 0x%02x\n",(int)type);
  printf("  uint8 parameters_len: 0x%02x\n",(int)parameters_len);
  printf("  const uint8* parameters_data: 0x%p\n",parameters_data);
  struct gecko_msg_mesh_generic_server_response_rsp_t* resp = gecko_cmd_mesh_generic_server_response(model_id,elem_index,client_address,appkey_index,remaining,flags,type,parameters_len,parameters_data);
  printf("    RETURNED\n");
  dump_mesh_generic_server_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_update_rsp_t* cmd_mesh_generic_server_update(uint16 model_id,uint16 elem_index,uint32 remaining,uint8 type,uint8 parameters_len, const uint8* parameters_data) {
  dump_command_header("mesh_generic_server_update");
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint32 remaining: 0x%08x\n",(int)remaining);
  printf("  uint8 type: 0x%02x\n",(int)type);
  printf("  uint8 parameters_len: 0x%02x\n",(int)parameters_len);
  printf("  const uint8* parameters_data: 0x%p\n",parameters_data);
  struct gecko_msg_mesh_generic_server_update_rsp_t* resp = gecko_cmd_mesh_generic_server_update(model_id,elem_index,remaining,type,parameters_len,parameters_data);
  printf("    RETURNED\n");
  dump_mesh_generic_server_update(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_publish_rsp_t* cmd_mesh_generic_server_publish(uint16 model_id,uint16 elem_index,uint8 type) {
  dump_command_header("mesh_generic_server_publish");
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint8 type: 0x%02x\n",(int)type);
  struct gecko_msg_mesh_generic_server_publish_rsp_t* resp = gecko_cmd_mesh_generic_server_publish(model_id,elem_index,type);
  printf("    RETURNED\n");
  dump_mesh_generic_server_publish(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_rsp_t* cmd_mesh_generic_server_init() {
  dump_command_header("mesh_generic_server_init");
  struct gecko_msg_mesh_generic_server_init_rsp_t* resp = gecko_cmd_mesh_generic_server_init();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_common_rsp_t* cmd_mesh_generic_server_init_common() {
  dump_command_header("mesh_generic_server_init_common");
  struct gecko_msg_mesh_generic_server_init_common_rsp_t* resp = gecko_cmd_mesh_generic_server_init_common();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init_common(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_on_off_rsp_t* cmd_mesh_generic_server_init_on_off() {
  dump_command_header("mesh_generic_server_init_on_off");
  struct gecko_msg_mesh_generic_server_init_on_off_rsp_t* resp = gecko_cmd_mesh_generic_server_init_on_off();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init_on_off(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_level_rsp_t* cmd_mesh_generic_server_init_level() {
  dump_command_header("mesh_generic_server_init_level");
  struct gecko_msg_mesh_generic_server_init_level_rsp_t* resp = gecko_cmd_mesh_generic_server_init_level();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init_level(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_default_transition_time_rsp_t* cmd_mesh_generic_server_init_default_transition_time() {
  dump_command_header("mesh_generic_server_init_default_transition_time");
  struct gecko_msg_mesh_generic_server_init_default_transition_time_rsp_t* resp = gecko_cmd_mesh_generic_server_init_default_transition_time();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init_default_transition_time(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_power_on_off_rsp_t* cmd_mesh_generic_server_init_power_on_off() {
  dump_command_header("mesh_generic_server_init_power_on_off");
  struct gecko_msg_mesh_generic_server_init_power_on_off_rsp_t* resp = gecko_cmd_mesh_generic_server_init_power_on_off();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init_power_on_off(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_power_level_rsp_t* cmd_mesh_generic_server_init_power_level() {
  dump_command_header("mesh_generic_server_init_power_level");
  struct gecko_msg_mesh_generic_server_init_power_level_rsp_t* resp = gecko_cmd_mesh_generic_server_init_power_level();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init_power_level(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_battery_rsp_t* cmd_mesh_generic_server_init_battery() {
  dump_command_header("mesh_generic_server_init_battery");
  struct gecko_msg_mesh_generic_server_init_battery_rsp_t* resp = gecko_cmd_mesh_generic_server_init_battery();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init_battery(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_location_rsp_t* cmd_mesh_generic_server_init_location() {
  dump_command_header("mesh_generic_server_init_location");
  struct gecko_msg_mesh_generic_server_init_location_rsp_t* resp = gecko_cmd_mesh_generic_server_init_location();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init_location(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_property_rsp_t* cmd_mesh_generic_server_init_property() {
  dump_command_header("mesh_generic_server_init_property");
  struct gecko_msg_mesh_generic_server_init_property_rsp_t* resp = gecko_cmd_mesh_generic_server_init_property();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init_property(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_lightness_rsp_t* cmd_mesh_generic_server_init_lightness() {
  dump_command_header("mesh_generic_server_init_lightness");
  struct gecko_msg_mesh_generic_server_init_lightness_rsp_t* resp = gecko_cmd_mesh_generic_server_init_lightness();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init_lightness(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_generic_server_init_ctl_rsp_t* cmd_mesh_generic_server_init_ctl() {
  dump_command_header("mesh_generic_server_init_ctl");
  struct gecko_msg_mesh_generic_server_init_ctl_rsp_t* resp = gecko_cmd_mesh_generic_server_init_ctl();
  printf("    RETURNED\n");
  dump_mesh_generic_server_init_ctl(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_coex_set_options_rsp_t* cmd_coex_set_options(uint32 mask,uint32 options) {
  dump_command_header("coex_set_options");
  printf("  uint32 mask: 0x%08x\n",(int)mask);
  printf("  uint32 options: 0x%08x\n",(int)options);
  struct gecko_msg_coex_set_options_rsp_t* resp = gecko_cmd_coex_set_options(mask,options);
  printf("    RETURNED\n");
  dump_coex_set_options(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_coex_get_counters_rsp_t* cmd_coex_get_counters(uint8 reset) {
  dump_command_header("coex_get_counters");
  printf("  uint8 reset: 0x%02x\n",(int)reset);
  struct gecko_msg_coex_get_counters_rsp_t* resp = gecko_cmd_coex_get_counters(reset);
  printf("    RETURNED\n");
  dump_coex_get_counters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_coex_set_parameters_rsp_t* cmd_coex_set_parameters(uint8 priority,uint8 request,uint8 pwm_period,uint8 pwm_dutycycle) {
  dump_command_header("coex_set_parameters");
  printf("  uint8 priority: 0x%02x\n",(int)priority);
  printf("  uint8 request: 0x%02x\n",(int)request);
  printf("  uint8 pwm_period: 0x%02x\n",(int)pwm_period);
  printf("  uint8 pwm_dutycycle: 0x%02x\n",(int)pwm_dutycycle);
  struct gecko_msg_coex_set_parameters_rsp_t* resp = gecko_cmd_coex_set_parameters(priority,request,pwm_period,pwm_dutycycle);
  printf("    RETURNED\n");
  dump_coex_set_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_coex_set_directional_priority_pulse_rsp_t* cmd_coex_set_directional_priority_pulse(uint8 pulse) {
  dump_command_header("coex_set_directional_priority_pulse");
  printf("  uint8 pulse: 0x%02x\n",(int)pulse);
  struct gecko_msg_coex_set_directional_priority_pulse_rsp_t* resp = gecko_cmd_coex_set_directional_priority_pulse(pulse);
  printf("    RETURNED\n");
  dump_coex_set_directional_priority_pulse(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_nettx_rsp_t* cmd_mesh_test_get_nettx() {
  dump_command_header("mesh_test_get_nettx");
  struct gecko_msg_mesh_test_get_nettx_rsp_t* resp = gecko_cmd_mesh_test_get_nettx();
  printf("    RETURNED\n");
  dump_mesh_test_get_nettx(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_nettx_rsp_t* cmd_mesh_test_set_nettx(uint8 count,uint8 interval) {
  dump_command_header("mesh_test_set_nettx");
  printf("  uint8 count: 0x%02x\n",(int)count);
  printf("  uint8 interval: 0x%02x\n",(int)interval);
  struct gecko_msg_mesh_test_set_nettx_rsp_t* resp = gecko_cmd_mesh_test_set_nettx(count,interval);
  printf("    RETURNED\n");
  dump_mesh_test_set_nettx(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_relay_rsp_t* cmd_mesh_test_get_relay() {
  dump_command_header("mesh_test_get_relay");
  struct gecko_msg_mesh_test_get_relay_rsp_t* resp = gecko_cmd_mesh_test_get_relay();
  printf("    RETURNED\n");
  dump_mesh_test_get_relay(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_relay_rsp_t* cmd_mesh_test_set_relay(uint8 enabled,uint8 count,uint8 interval) {
  dump_command_header("mesh_test_set_relay");
  printf("  uint8 enabled: 0x%02x\n",(int)enabled);
  printf("  uint8 count: 0x%02x\n",(int)count);
  printf("  uint8 interval: 0x%02x\n",(int)interval);
  struct gecko_msg_mesh_test_set_relay_rsp_t* resp = gecko_cmd_mesh_test_set_relay(enabled,count,interval);
  printf("    RETURNED\n");
  dump_mesh_test_set_relay(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_adv_scan_params_rsp_t* cmd_mesh_test_set_adv_scan_params(uint16 adv_interval_min,uint16 adv_interval_max,uint8 adv_repeat_packets,uint8 adv_use_random_address,uint8 adv_channel_map,uint16 scan_interval,uint16 scan_window) {
  dump_command_header("mesh_test_set_adv_scan_params");
  printf("  uint16 adv_interval_min: 0x%04x\n",(int)adv_interval_min);
  printf("  uint16 adv_interval_max: 0x%04x\n",(int)adv_interval_max);
  printf("  uint8 adv_repeat_packets: 0x%02x\n",(int)adv_repeat_packets);
  printf("  uint8 adv_use_random_address: 0x%02x\n",(int)adv_use_random_address);
  printf("  uint8 adv_channel_map: 0x%02x\n",(int)adv_channel_map);
  printf("  uint16 scan_interval: 0x%04x\n",(int)scan_interval);
  printf("  uint16 scan_window: 0x%04x\n",(int)scan_window);
  struct gecko_msg_mesh_test_set_adv_scan_params_rsp_t* resp = gecko_cmd_mesh_test_set_adv_scan_params(adv_interval_min,adv_interval_max,adv_repeat_packets,adv_use_random_address,adv_channel_map,scan_interval,scan_window);
  printf("    RETURNED\n");
  dump_mesh_test_set_adv_scan_params(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_ivupdate_test_mode_rsp_t* cmd_mesh_test_set_ivupdate_test_mode(uint8 mode) {
  dump_command_header("mesh_test_set_ivupdate_test_mode");
  printf("  uint8 mode: 0x%02x\n",(int)mode);
  struct gecko_msg_mesh_test_set_ivupdate_test_mode_rsp_t* resp = gecko_cmd_mesh_test_set_ivupdate_test_mode(mode);
  printf("    RETURNED\n");
  dump_mesh_test_set_ivupdate_test_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_ivupdate_test_mode_rsp_t* cmd_mesh_test_get_ivupdate_test_mode() {
  dump_command_header("mesh_test_get_ivupdate_test_mode");
  struct gecko_msg_mesh_test_get_ivupdate_test_mode_rsp_t* resp = gecko_cmd_mesh_test_get_ivupdate_test_mode();
  printf("    RETURNED\n");
  dump_mesh_test_get_ivupdate_test_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_segment_send_delay_rsp_t* cmd_mesh_test_set_segment_send_delay(uint8 delay) {
  dump_command_header("mesh_test_set_segment_send_delay");
  printf("  uint8 delay: 0x%02x\n",(int)delay);
  struct gecko_msg_mesh_test_set_segment_send_delay_rsp_t* resp = gecko_cmd_mesh_test_set_segment_send_delay(delay);
  printf("    RETURNED\n");
  dump_mesh_test_set_segment_send_delay(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_ivupdate_state_rsp_t* cmd_mesh_test_set_ivupdate_state(uint8 state) {
  dump_command_header("mesh_test_set_ivupdate_state");
  printf("  uint8 state: 0x%02x\n",(int)state);
  struct gecko_msg_mesh_test_set_ivupdate_state_rsp_t* resp = gecko_cmd_mesh_test_set_ivupdate_state(state);
  printf("    RETURNED\n");
  dump_mesh_test_set_ivupdate_state(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_send_beacons_rsp_t* cmd_mesh_test_send_beacons() {
  dump_command_header("mesh_test_send_beacons");
  struct gecko_msg_mesh_test_send_beacons_rsp_t* resp = gecko_cmd_mesh_test_send_beacons();
  printf("    RETURNED\n");
  dump_mesh_test_send_beacons(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_bind_local_model_app_rsp_t* cmd_mesh_test_bind_local_model_app(uint16 elem_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_test_bind_local_model_app");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_test_bind_local_model_app_rsp_t* resp = gecko_cmd_mesh_test_bind_local_model_app(elem_index,appkey_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_test_bind_local_model_app(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_unbind_local_model_app_rsp_t* cmd_mesh_test_unbind_local_model_app(uint16 elem_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_test_unbind_local_model_app");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_test_unbind_local_model_app_rsp_t* resp = gecko_cmd_mesh_test_unbind_local_model_app(elem_index,appkey_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_test_unbind_local_model_app(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_add_local_model_sub_rsp_t* cmd_mesh_test_add_local_model_sub(uint16 elem_index,uint16 vendor_id,uint16 model_id,uint16 sub_address) {
  dump_command_header("mesh_test_add_local_model_sub");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 sub_address: 0x%04x\n",(int)sub_address);
  struct gecko_msg_mesh_test_add_local_model_sub_rsp_t* resp = gecko_cmd_mesh_test_add_local_model_sub(elem_index,vendor_id,model_id,sub_address);
  printf("    RETURNED\n");
  dump_mesh_test_add_local_model_sub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_del_local_model_sub_rsp_t* cmd_mesh_test_del_local_model_sub(uint16 elem_index,uint16 vendor_id,uint16 model_id,uint16 sub_address) {
  dump_command_header("mesh_test_del_local_model_sub");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 sub_address: 0x%04x\n",(int)sub_address);
  struct gecko_msg_mesh_test_del_local_model_sub_rsp_t* resp = gecko_cmd_mesh_test_del_local_model_sub(elem_index,vendor_id,model_id,sub_address);
  printf("    RETURNED\n");
  dump_mesh_test_del_local_model_sub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_add_local_model_sub_va_rsp_t* cmd_mesh_test_add_local_model_sub_va(uint16 elem_index,uint16 vendor_id,uint16 model_id,uint8 sub_address_len, const uint8* sub_address_data) {
  dump_command_header("mesh_test_add_local_model_sub_va");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint8 sub_address_len: 0x%02x\n",(int)sub_address_len);
  printf("  const uint8* sub_address_data: 0x%p\n",sub_address_data);
  struct gecko_msg_mesh_test_add_local_model_sub_va_rsp_t* resp = gecko_cmd_mesh_test_add_local_model_sub_va(elem_index,vendor_id,model_id,sub_address_len,sub_address_data);
  printf("    RETURNED\n");
  dump_mesh_test_add_local_model_sub_va(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_del_local_model_sub_va_rsp_t* cmd_mesh_test_del_local_model_sub_va(uint16 elem_index,uint16 vendor_id,uint16 model_id,uint8 sub_address_len, const uint8* sub_address_data) {
  dump_command_header("mesh_test_del_local_model_sub_va");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint8 sub_address_len: 0x%02x\n",(int)sub_address_len);
  printf("  const uint8* sub_address_data: 0x%p\n",sub_address_data);
  struct gecko_msg_mesh_test_del_local_model_sub_va_rsp_t* resp = gecko_cmd_mesh_test_del_local_model_sub_va(elem_index,vendor_id,model_id,sub_address_len,sub_address_data);
  printf("    RETURNED\n");
  dump_mesh_test_del_local_model_sub_va(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_local_model_sub_rsp_t* cmd_mesh_test_get_local_model_sub(uint16 elem_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_test_get_local_model_sub");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_test_get_local_model_sub_rsp_t* resp = gecko_cmd_mesh_test_get_local_model_sub(elem_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_test_get_local_model_sub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_local_model_pub_rsp_t* cmd_mesh_test_set_local_model_pub(uint16 elem_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id,uint16 pub_address,uint8 ttl,uint8 period,uint8 retrans,uint8 credentials) {
  dump_command_header("mesh_test_set_local_model_pub");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 pub_address: 0x%04x\n",(int)pub_address);
  printf("  uint8 ttl: 0x%02x\n",(int)ttl);
  printf("  uint8 period: 0x%02x\n",(int)period);
  printf("  uint8 retrans: 0x%02x\n",(int)retrans);
  printf("  uint8 credentials: 0x%02x\n",(int)credentials);
  struct gecko_msg_mesh_test_set_local_model_pub_rsp_t* resp = gecko_cmd_mesh_test_set_local_model_pub(elem_index,appkey_index,vendor_id,model_id,pub_address,ttl,period,retrans,credentials);
  printf("    RETURNED\n");
  dump_mesh_test_set_local_model_pub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_local_model_pub_va_rsp_t* cmd_mesh_test_set_local_model_pub_va(uint16 elem_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id,uint8 ttl,uint8 period,uint8 retrans,uint8 credentials,uint8 pub_address_len, const uint8* pub_address_data) {
  dump_command_header("mesh_test_set_local_model_pub_va");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint8 ttl: 0x%02x\n",(int)ttl);
  printf("  uint8 period: 0x%02x\n",(int)period);
  printf("  uint8 retrans: 0x%02x\n",(int)retrans);
  printf("  uint8 credentials: 0x%02x\n",(int)credentials);
  printf("  uint8 pub_address_len: 0x%02x\n",(int)pub_address_len);
  printf("  const uint8* pub_address_data: 0x%p\n",pub_address_data);
  struct gecko_msg_mesh_test_set_local_model_pub_va_rsp_t* resp = gecko_cmd_mesh_test_set_local_model_pub_va(elem_index,appkey_index,vendor_id,model_id,ttl,period,retrans,credentials,pub_address_len,pub_address_data);
  printf("    RETURNED\n");
  dump_mesh_test_set_local_model_pub_va(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_local_model_pub_rsp_t* cmd_mesh_test_get_local_model_pub(uint16 elem_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_test_get_local_model_pub");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_test_get_local_model_pub_rsp_t* resp = gecko_cmd_mesh_test_get_local_model_pub(elem_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_test_get_local_model_pub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_local_heartbeat_subscription_rsp_t* cmd_mesh_test_set_local_heartbeat_subscription(uint16 subscription_source,uint16 subscription_destination,uint8 period_log) {
  dump_command_header("mesh_test_set_local_heartbeat_subscription");
  printf("  uint16 subscription_source: 0x%04x\n",(int)subscription_source);
  printf("  uint16 subscription_destination: 0x%04x\n",(int)subscription_destination);
  printf("  uint8 period_log: 0x%02x\n",(int)period_log);
  struct gecko_msg_mesh_test_set_local_heartbeat_subscription_rsp_t* resp = gecko_cmd_mesh_test_set_local_heartbeat_subscription(subscription_source,subscription_destination,period_log);
  printf("    RETURNED\n");
  dump_mesh_test_set_local_heartbeat_subscription(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_local_heartbeat_subscription_rsp_t* cmd_mesh_test_get_local_heartbeat_subscription() {
  dump_command_header("mesh_test_get_local_heartbeat_subscription");
  struct gecko_msg_mesh_test_get_local_heartbeat_subscription_rsp_t* resp = gecko_cmd_mesh_test_get_local_heartbeat_subscription();
  printf("    RETURNED\n");
  dump_mesh_test_get_local_heartbeat_subscription(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_local_heartbeat_publication_rsp_t* cmd_mesh_test_get_local_heartbeat_publication() {
  dump_command_header("mesh_test_get_local_heartbeat_publication");
  struct gecko_msg_mesh_test_get_local_heartbeat_publication_rsp_t* resp = gecko_cmd_mesh_test_get_local_heartbeat_publication();
  printf("    RETURNED\n");
  dump_mesh_test_get_local_heartbeat_publication(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_local_heartbeat_publication_rsp_t* cmd_mesh_test_set_local_heartbeat_publication(uint16 publication_address,uint8 count_log,uint8 period_log,uint8 ttl,uint16 features,uint16 publication_netkey_index) {
  dump_command_header("mesh_test_set_local_heartbeat_publication");
  printf("  uint16 publication_address: 0x%04x\n",(int)publication_address);
  printf("  uint8 count_log: 0x%02x\n",(int)count_log);
  printf("  uint8 period_log: 0x%02x\n",(int)period_log);
  printf("  uint8 ttl: 0x%02x\n",(int)ttl);
  printf("  uint16 features: 0x%04x\n",(int)features);
  printf("  uint16 publication_netkey_index: 0x%04x\n",(int)publication_netkey_index);
  struct gecko_msg_mesh_test_set_local_heartbeat_publication_rsp_t* resp = gecko_cmd_mesh_test_set_local_heartbeat_publication(publication_address,count_log,period_log,ttl,features,publication_netkey_index);
  printf("    RETURNED\n");
  dump_mesh_test_set_local_heartbeat_publication(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_local_config_rsp_t* cmd_mesh_test_set_local_config(uint16 id,uint16 netkey_index,uint8 value_len, const uint8* value_data) {
  dump_command_header("mesh_test_set_local_config");
  printf("  uint16 id: 0x%04x\n",(int)id);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_mesh_test_set_local_config_rsp_t* resp = gecko_cmd_mesh_test_set_local_config(id,netkey_index,value_len,value_data);
  printf("    RETURNED\n");
  dump_mesh_test_set_local_config(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_local_config_rsp_t* cmd_mesh_test_get_local_config(uint16 id,uint16 netkey_index) {
  dump_command_header("mesh_test_get_local_config");
  printf("  uint16 id: 0x%04x\n",(int)id);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_test_get_local_config_rsp_t* resp = gecko_cmd_mesh_test_get_local_config(id,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_test_get_local_config(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_add_local_key_rsp_t* cmd_mesh_test_add_local_key(uint8 key_type,aes_key_128 key,uint16 key_index,uint16 netkey_index) {
  dump_command_header("mesh_test_add_local_key");
  printf("  uint8 key_type: 0x%02x\n",(int)key_type);
   printf("  aes_key_128 mesh_test_add_local_key: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",key.data[i]);
   printf("\n");
  printf("  uint16 key_index: 0x%04x\n",(int)key_index);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_test_add_local_key_rsp_t* resp = gecko_cmd_mesh_test_add_local_key(key_type,key,key_index,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_test_add_local_key(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_del_local_key_rsp_t* cmd_mesh_test_del_local_key(uint8 key_type,uint16 key_index) {
  dump_command_header("mesh_test_del_local_key");
  printf("  uint8 key_type: 0x%02x\n",(int)key_type);
  printf("  uint16 key_index: 0x%04x\n",(int)key_index);
  struct gecko_msg_mesh_test_del_local_key_rsp_t* resp = gecko_cmd_mesh_test_del_local_key(key_type,key_index);
  printf("    RETURNED\n");
  dump_mesh_test_del_local_key(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_update_local_key_rsp_t* cmd_mesh_test_update_local_key(uint8 key_type,aes_key_128 key,uint16 key_index) {
  dump_command_header("mesh_test_update_local_key");
  printf("  uint8 key_type: 0x%02x\n",(int)key_type);
   printf("  aes_key_128 mesh_test_update_local_key: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",key.data[i]);
   printf("\n");
  printf("  uint16 key_index: 0x%04x\n",(int)key_index);
  struct gecko_msg_mesh_test_update_local_key_rsp_t* resp = gecko_cmd_mesh_test_update_local_key(key_type,key,key_index);
  printf("    RETURNED\n");
  dump_mesh_test_update_local_key(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_sar_config_rsp_t* cmd_mesh_test_set_sar_config(uint32 incomplete_timer_ms,uint32 pending_ack_base_ms,uint32 pending_ack_mul_ms,uint32 wait_for_ack_base_ms,uint32 wait_for_ack_mul_ms,uint8 max_send_rounds) {
  dump_command_header("mesh_test_set_sar_config");
  printf("  uint32 incomplete_timer_ms: 0x%08x\n",(int)incomplete_timer_ms);
  printf("  uint32 pending_ack_base_ms: 0x%08x\n",(int)pending_ack_base_ms);
  printf("  uint32 pending_ack_mul_ms: 0x%08x\n",(int)pending_ack_mul_ms);
  printf("  uint32 wait_for_ack_base_ms: 0x%08x\n",(int)wait_for_ack_base_ms);
  printf("  uint32 wait_for_ack_mul_ms: 0x%08x\n",(int)wait_for_ack_mul_ms);
  printf("  uint8 max_send_rounds: 0x%02x\n",(int)max_send_rounds);
  struct gecko_msg_mesh_test_set_sar_config_rsp_t* resp = gecko_cmd_mesh_test_set_sar_config(incomplete_timer_ms,pending_ack_base_ms,pending_ack_mul_ms,wait_for_ack_base_ms,wait_for_ack_mul_ms,max_send_rounds);
  printf("    RETURNED\n");
  dump_mesh_test_set_sar_config(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_element_seqnum_rsp_t* cmd_mesh_test_get_element_seqnum(uint16 elem_index) {
  dump_command_header("mesh_test_get_element_seqnum");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_test_get_element_seqnum_rsp_t* resp = gecko_cmd_mesh_test_get_element_seqnum(elem_index);
  printf("    RETURNED\n");
  dump_mesh_test_get_element_seqnum(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_adv_bearer_state_rsp_t* cmd_mesh_test_set_adv_bearer_state(uint8 state) {
  dump_command_header("mesh_test_set_adv_bearer_state");
  printf("  uint8 state: 0x%02x\n",(int)state);
  struct gecko_msg_mesh_test_set_adv_bearer_state_rsp_t* resp = gecko_cmd_mesh_test_set_adv_bearer_state(state);
  printf("    RETURNED\n");
  dump_mesh_test_set_adv_bearer_state(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_key_count_rsp_t* cmd_mesh_test_get_key_count(uint8 type) {
  dump_command_header("mesh_test_get_key_count");
  printf("  uint8 type: 0x%02x\n",(int)type);
  struct gecko_msg_mesh_test_get_key_count_rsp_t* resp = gecko_cmd_mesh_test_get_key_count(type);
  printf("    RETURNED\n");
  dump_mesh_test_get_key_count(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_key_rsp_t* cmd_mesh_test_get_key(uint8 type,uint32 index,uint8 current) {
  dump_command_header("mesh_test_get_key");
  printf("  uint8 type: 0x%02x\n",(int)type);
  printf("  uint32 index: 0x%08x\n",(int)index);
  printf("  uint8 current: 0x%02x\n",(int)current);
  struct gecko_msg_mesh_test_get_key_rsp_t* resp = gecko_cmd_mesh_test_get_key(type,index,current);
  printf("    RETURNED\n");
  dump_mesh_test_get_key(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_prov_get_device_key_rsp_t* cmd_mesh_test_prov_get_device_key(uint16 address) {
  dump_command_header("mesh_test_prov_get_device_key");
  printf("  uint16 address: 0x%04x\n",(int)address);
  struct gecko_msg_mesh_test_prov_get_device_key_rsp_t* resp = gecko_cmd_mesh_test_prov_get_device_key(address);
  printf("    RETURNED\n");
  dump_mesh_test_prov_get_device_key(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_prov_prepare_key_refresh_rsp_t* cmd_mesh_test_prov_prepare_key_refresh(aes_key_128 net_key,uint8 app_keys_len, const uint8* app_keys_data) {
  dump_command_header("mesh_test_prov_prepare_key_refresh");
   printf("  aes_key_128 mesh_test_prov_prepare_key_refresh: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",net_key.data[i]);
   printf("\n");
  printf("  uint8 app_keys_len: 0x%02x\n",(int)app_keys_len);
  printf("  const uint8* app_keys_data: 0x%p\n",app_keys_data);
  struct gecko_msg_mesh_test_prov_prepare_key_refresh_rsp_t* resp = gecko_cmd_mesh_test_prov_prepare_key_refresh(net_key,app_keys_len,app_keys_data);
  printf("    RETURNED\n");
  dump_mesh_test_prov_prepare_key_refresh(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_cancel_segmented_tx_rsp_t* cmd_mesh_test_cancel_segmented_tx(uint16 src_addr,uint16 dst_addr) {
  dump_command_header("mesh_test_cancel_segmented_tx");
  printf("  uint16 src_addr: 0x%04x\n",(int)src_addr);
  printf("  uint16 dst_addr: 0x%04x\n",(int)dst_addr);
  struct gecko_msg_mesh_test_cancel_segmented_tx_rsp_t* resp = gecko_cmd_mesh_test_cancel_segmented_tx(src_addr,dst_addr);
  printf("    RETURNED\n");
  dump_mesh_test_cancel_segmented_tx(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_iv_index_rsp_t* cmd_mesh_test_set_iv_index(uint32 iv_index) {
  dump_command_header("mesh_test_set_iv_index");
  printf("  uint32 iv_index: 0x%08x\n",(int)iv_index);
  struct gecko_msg_mesh_test_set_iv_index_rsp_t* resp = gecko_cmd_mesh_test_set_iv_index(iv_index);
  printf("    RETURNED\n");
  dump_mesh_test_set_iv_index(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_element_seqnum_rsp_t* cmd_mesh_test_set_element_seqnum(uint16 elem_index,uint32 seqnum) {
  dump_command_header("mesh_test_set_element_seqnum");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint32 seqnum: 0x%08x\n",(int)seqnum);
  struct gecko_msg_mesh_test_set_element_seqnum_rsp_t* resp = gecko_cmd_mesh_test_set_element_seqnum(elem_index,seqnum);
  printf("    RETURNED\n");
  dump_mesh_test_set_element_seqnum(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_set_model_option_rsp_t* cmd_mesh_test_set_model_option(uint16 elem_index,uint16 vendor_id,uint16 model_id,uint8 option,uint32 value) {
  dump_command_header("mesh_test_set_model_option");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint8 option: 0x%02x\n",(int)option);
  printf("  uint32 value: 0x%08x\n",(int)value);
  struct gecko_msg_mesh_test_set_model_option_rsp_t* resp = gecko_cmd_mesh_test_set_model_option(elem_index,vendor_id,model_id,option,value);
  printf("    RETURNED\n");
  dump_mesh_test_set_model_option(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_test_get_local_model_app_bindings_rsp_t* cmd_mesh_test_get_local_model_app_bindings(uint16 elem_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_test_get_local_model_app_bindings");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_test_get_local_model_app_bindings_rsp_t* resp = gecko_cmd_mesh_test_get_local_model_app_bindings(elem_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_test_get_local_model_app_bindings(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lpn_init_rsp_t* cmd_mesh_lpn_init() {
  dump_command_header("mesh_lpn_init");
  struct gecko_msg_mesh_lpn_init_rsp_t* resp = gecko_cmd_mesh_lpn_init();
  printf("    RETURNED\n");
  dump_mesh_lpn_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lpn_deinit_rsp_t* cmd_mesh_lpn_deinit() {
  dump_command_header("mesh_lpn_deinit");
  struct gecko_msg_mesh_lpn_deinit_rsp_t* resp = gecko_cmd_mesh_lpn_deinit();
  printf("    RETURNED\n");
  dump_mesh_lpn_deinit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lpn_configure_rsp_t* cmd_mesh_lpn_configure(uint8 queue_length,uint32 poll_timeout) {
  dump_command_header("mesh_lpn_configure");
  printf("  uint8 queue_length: 0x%02x\n",(int)queue_length);
  printf("  uint32 poll_timeout: 0x%08x\n",(int)poll_timeout);
  struct gecko_msg_mesh_lpn_configure_rsp_t* resp = gecko_cmd_mesh_lpn_configure(queue_length,poll_timeout);
  printf("    RETURNED\n");
  dump_mesh_lpn_configure(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lpn_establish_friendship_rsp_t* cmd_mesh_lpn_establish_friendship(uint16 netkey_index) {
  dump_command_header("mesh_lpn_establish_friendship");
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_lpn_establish_friendship_rsp_t* resp = gecko_cmd_mesh_lpn_establish_friendship(netkey_index);
  printf("    RETURNED\n");
  dump_mesh_lpn_establish_friendship(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lpn_poll_rsp_t* cmd_mesh_lpn_poll() {
  dump_command_header("mesh_lpn_poll");
  struct gecko_msg_mesh_lpn_poll_rsp_t* resp = gecko_cmd_mesh_lpn_poll();
  printf("    RETURNED\n");
  dump_mesh_lpn_poll(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lpn_terminate_friendship_rsp_t* cmd_mesh_lpn_terminate_friendship() {
  dump_command_header("mesh_lpn_terminate_friendship");
  struct gecko_msg_mesh_lpn_terminate_friendship_rsp_t* resp = gecko_cmd_mesh_lpn_terminate_friendship();
  printf("    RETURNED\n");
  dump_mesh_lpn_terminate_friendship(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lpn_config_rsp_t* cmd_mesh_lpn_config(uint8 setting_id,uint32 value) {
  dump_command_header("mesh_lpn_config");
  printf("  uint8 setting_id: 0x%02x\n",(int)setting_id);
  printf("  uint32 value: 0x%08x\n",(int)value);
  struct gecko_msg_mesh_lpn_config_rsp_t* resp = gecko_cmd_mesh_lpn_config(setting_id,value);
  printf("    RETURNED\n");
  dump_mesh_lpn_config(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_friend_init_rsp_t* cmd_mesh_friend_init() {
  dump_command_header("mesh_friend_init");
  struct gecko_msg_mesh_friend_init_rsp_t* resp = gecko_cmd_mesh_friend_init();
  printf("    RETURNED\n");
  dump_mesh_friend_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_friend_deinit_rsp_t* cmd_mesh_friend_deinit() {
  dump_command_header("mesh_friend_deinit");
  struct gecko_msg_mesh_friend_deinit_rsp_t* resp = gecko_cmd_mesh_friend_deinit();
  printf("    RETURNED\n");
  dump_mesh_friend_deinit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_cancel_request_rsp_t* cmd_mesh_config_client_cancel_request(uint32 handle) {
  dump_command_header("mesh_config_client_cancel_request");
  printf("  uint32 handle: 0x%08x\n",(int)handle);
  struct gecko_msg_mesh_config_client_cancel_request_rsp_t* resp = gecko_cmd_mesh_config_client_cancel_request(handle);
  printf("    RETURNED\n");
  dump_mesh_config_client_cancel_request(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_request_status_rsp_t* cmd_mesh_config_client_get_request_status(uint32 handle) {
  dump_command_header("mesh_config_client_get_request_status");
  printf("  uint32 handle: 0x%08x\n",(int)handle);
  struct gecko_msg_mesh_config_client_get_request_status_rsp_t* resp = gecko_cmd_mesh_config_client_get_request_status(handle);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_request_status(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_default_timeout_rsp_t* cmd_mesh_config_client_get_default_timeout() {
  dump_command_header("mesh_config_client_get_default_timeout");
  struct gecko_msg_mesh_config_client_get_default_timeout_rsp_t* resp = gecko_cmd_mesh_config_client_get_default_timeout();
  printf("    RETURNED\n");
  dump_mesh_config_client_get_default_timeout(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_default_timeout_rsp_t* cmd_mesh_config_client_set_default_timeout(uint32 timeout_ms,uint32 lpn_timeout_ms) {
  dump_command_header("mesh_config_client_set_default_timeout");
  printf("  uint32 timeout_ms: 0x%08x\n",(int)timeout_ms);
  printf("  uint32 lpn_timeout_ms: 0x%08x\n",(int)lpn_timeout_ms);
  struct gecko_msg_mesh_config_client_set_default_timeout_rsp_t* resp = gecko_cmd_mesh_config_client_set_default_timeout(timeout_ms,lpn_timeout_ms);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_default_timeout(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_add_netkey_rsp_t* cmd_mesh_config_client_add_netkey(uint16 enc_netkey_index,uint16 server_address,uint16 netkey_index) {
  dump_command_header("mesh_config_client_add_netkey");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_config_client_add_netkey_rsp_t* resp = gecko_cmd_mesh_config_client_add_netkey(enc_netkey_index,server_address,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_config_client_add_netkey(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_remove_netkey_rsp_t* cmd_mesh_config_client_remove_netkey(uint16 enc_netkey_index,uint16 server_address,uint16 netkey_index) {
  dump_command_header("mesh_config_client_remove_netkey");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_config_client_remove_netkey_rsp_t* resp = gecko_cmd_mesh_config_client_remove_netkey(enc_netkey_index,server_address,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_config_client_remove_netkey(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_list_netkeys_rsp_t* cmd_mesh_config_client_list_netkeys(uint16 enc_netkey_index,uint16 server_address) {
  dump_command_header("mesh_config_client_list_netkeys");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  struct gecko_msg_mesh_config_client_list_netkeys_rsp_t* resp = gecko_cmd_mesh_config_client_list_netkeys(enc_netkey_index,server_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_list_netkeys(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_add_appkey_rsp_t* cmd_mesh_config_client_add_appkey(uint16 enc_netkey_index,uint16 server_address,uint16 appkey_index,uint16 netkey_index) {
  dump_command_header("mesh_config_client_add_appkey");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_config_client_add_appkey_rsp_t* resp = gecko_cmd_mesh_config_client_add_appkey(enc_netkey_index,server_address,appkey_index,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_config_client_add_appkey(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_remove_appkey_rsp_t* cmd_mesh_config_client_remove_appkey(uint16 enc_netkey_index,uint16 server_address,uint16 appkey_index,uint16 netkey_index) {
  dump_command_header("mesh_config_client_remove_appkey");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_config_client_remove_appkey_rsp_t* resp = gecko_cmd_mesh_config_client_remove_appkey(enc_netkey_index,server_address,appkey_index,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_config_client_remove_appkey(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_list_appkeys_rsp_t* cmd_mesh_config_client_list_appkeys(uint16 enc_netkey_index,uint16 server_address,uint16 netkey_index) {
  dump_command_header("mesh_config_client_list_appkeys");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_config_client_list_appkeys_rsp_t* resp = gecko_cmd_mesh_config_client_list_appkeys(enc_netkey_index,server_address,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_config_client_list_appkeys(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_bind_model_rsp_t* cmd_mesh_config_client_bind_model(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_config_client_bind_model");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_config_client_bind_model_rsp_t* resp = gecko_cmd_mesh_config_client_bind_model(enc_netkey_index,server_address,element_index,appkey_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_config_client_bind_model(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_unbind_model_rsp_t* cmd_mesh_config_client_unbind_model(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 appkey_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_config_client_unbind_model");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_config_client_unbind_model_rsp_t* resp = gecko_cmd_mesh_config_client_unbind_model(enc_netkey_index,server_address,element_index,appkey_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_config_client_unbind_model(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_list_bindings_rsp_t* cmd_mesh_config_client_list_bindings(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_config_client_list_bindings");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_config_client_list_bindings_rsp_t* resp = gecko_cmd_mesh_config_client_list_bindings(enc_netkey_index,server_address,element_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_config_client_list_bindings(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_model_pub_rsp_t* cmd_mesh_config_client_get_model_pub(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_config_client_get_model_pub");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_config_client_get_model_pub_rsp_t* resp = gecko_cmd_mesh_config_client_get_model_pub(enc_netkey_index,server_address,element_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_model_pub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_model_pub_rsp_t* cmd_mesh_config_client_set_model_pub(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id,uint16 address,uint16 appkey_index,uint8 credentials,uint8 ttl,uint32 period_ms,uint8 retransmit_count,uint16 retransmit_interval_ms) {
  dump_command_header("mesh_config_client_set_model_pub");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 address: 0x%04x\n",(int)address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 credentials: 0x%02x\n",(int)credentials);
  printf("  uint8 ttl: 0x%02x\n",(int)ttl);
  printf("  uint32 period_ms: 0x%08x\n",(int)period_ms);
  printf("  uint8 retransmit_count: 0x%02x\n",(int)retransmit_count);
  printf("  uint16 retransmit_interval_ms: 0x%04x\n",(int)retransmit_interval_ms);
  struct gecko_msg_mesh_config_client_set_model_pub_rsp_t* resp = gecko_cmd_mesh_config_client_set_model_pub(enc_netkey_index,server_address,element_index,vendor_id,model_id,address,appkey_index,credentials,ttl,period_ms,retransmit_count,retransmit_interval_ms);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_model_pub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_model_pub_va_rsp_t* cmd_mesh_config_client_set_model_pub_va(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id,uuid_128 address,uint16 appkey_index,uint8 credentials,uint8 ttl,uint32 period_ms,uint8 retransmit_count,uint16 retransmit_interval_ms) {
  dump_command_header("mesh_config_client_set_model_pub_va");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
   printf("  aes_key_128 mesh_config_client_set_model_pub_va: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",address.data[i]);
   printf("\n");
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 credentials: 0x%02x\n",(int)credentials);
  printf("  uint8 ttl: 0x%02x\n",(int)ttl);
  printf("  uint32 period_ms: 0x%08x\n",(int)period_ms);
  printf("  uint8 retransmit_count: 0x%02x\n",(int)retransmit_count);
  printf("  uint16 retransmit_interval_ms: 0x%04x\n",(int)retransmit_interval_ms);
  struct gecko_msg_mesh_config_client_set_model_pub_va_rsp_t* resp = gecko_cmd_mesh_config_client_set_model_pub_va(enc_netkey_index,server_address,element_index,vendor_id,model_id,address,appkey_index,credentials,ttl,period_ms,retransmit_count,retransmit_interval_ms);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_model_pub_va(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_add_model_sub_rsp_t* cmd_mesh_config_client_add_model_sub(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id,uint16 sub_address) {
  dump_command_header("mesh_config_client_add_model_sub");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 sub_address: 0x%04x\n",(int)sub_address);
  struct gecko_msg_mesh_config_client_add_model_sub_rsp_t* resp = gecko_cmd_mesh_config_client_add_model_sub(enc_netkey_index,server_address,element_index,vendor_id,model_id,sub_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_add_model_sub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_add_model_sub_va_rsp_t* cmd_mesh_config_client_add_model_sub_va(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id,uuid_128 sub_address) {
  dump_command_header("mesh_config_client_add_model_sub_va");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
   printf("  aes_key_128 mesh_config_client_add_model_sub_va: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",sub_address.data[i]);
   printf("\n");
  struct gecko_msg_mesh_config_client_add_model_sub_va_rsp_t* resp = gecko_cmd_mesh_config_client_add_model_sub_va(enc_netkey_index,server_address,element_index,vendor_id,model_id,sub_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_add_model_sub_va(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_remove_model_sub_rsp_t* cmd_mesh_config_client_remove_model_sub(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id,uint16 sub_address) {
  dump_command_header("mesh_config_client_remove_model_sub");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 sub_address: 0x%04x\n",(int)sub_address);
  struct gecko_msg_mesh_config_client_remove_model_sub_rsp_t* resp = gecko_cmd_mesh_config_client_remove_model_sub(enc_netkey_index,server_address,element_index,vendor_id,model_id,sub_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_remove_model_sub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_remove_model_sub_va_rsp_t* cmd_mesh_config_client_remove_model_sub_va(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id,uuid_128 sub_address) {
  dump_command_header("mesh_config_client_remove_model_sub_va");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
   printf("  aes_key_128 mesh_config_client_remove_model_sub_va: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",sub_address.data[i]);
   printf("\n");
  struct gecko_msg_mesh_config_client_remove_model_sub_va_rsp_t* resp = gecko_cmd_mesh_config_client_remove_model_sub_va(enc_netkey_index,server_address,element_index,vendor_id,model_id,sub_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_remove_model_sub_va(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_model_sub_rsp_t* cmd_mesh_config_client_set_model_sub(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id,uint16 sub_address) {
  dump_command_header("mesh_config_client_set_model_sub");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  printf("  uint16 sub_address: 0x%04x\n",(int)sub_address);
  struct gecko_msg_mesh_config_client_set_model_sub_rsp_t* resp = gecko_cmd_mesh_config_client_set_model_sub(enc_netkey_index,server_address,element_index,vendor_id,model_id,sub_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_model_sub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_model_sub_va_rsp_t* cmd_mesh_config_client_set_model_sub_va(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id,uuid_128 sub_address) {
  dump_command_header("mesh_config_client_set_model_sub_va");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
   printf("  aes_key_128 mesh_config_client_set_model_sub_va: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",sub_address.data[i]);
   printf("\n");
  struct gecko_msg_mesh_config_client_set_model_sub_va_rsp_t* resp = gecko_cmd_mesh_config_client_set_model_sub_va(enc_netkey_index,server_address,element_index,vendor_id,model_id,sub_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_model_sub_va(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_clear_model_sub_rsp_t* cmd_mesh_config_client_clear_model_sub(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_config_client_clear_model_sub");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_config_client_clear_model_sub_rsp_t* resp = gecko_cmd_mesh_config_client_clear_model_sub(enc_netkey_index,server_address,element_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_config_client_clear_model_sub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_list_subs_rsp_t* cmd_mesh_config_client_list_subs(uint16 enc_netkey_index,uint16 server_address,uint8 element_index,uint16 vendor_id,uint16 model_id) {
  dump_command_header("mesh_config_client_list_subs");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 element_index: 0x%02x\n",(int)element_index);
  printf("  uint16 vendor_id: 0x%04x\n",(int)vendor_id);
  printf("  uint16 model_id: 0x%04x\n",(int)model_id);
  struct gecko_msg_mesh_config_client_list_subs_rsp_t* resp = gecko_cmd_mesh_config_client_list_subs(enc_netkey_index,server_address,element_index,vendor_id,model_id);
  printf("    RETURNED\n");
  dump_mesh_config_client_list_subs(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_heartbeat_pub_rsp_t* cmd_mesh_config_client_get_heartbeat_pub(uint16 enc_netkey_index,uint16 server_address) {
  dump_command_header("mesh_config_client_get_heartbeat_pub");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  struct gecko_msg_mesh_config_client_get_heartbeat_pub_rsp_t* resp = gecko_cmd_mesh_config_client_get_heartbeat_pub(enc_netkey_index,server_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_heartbeat_pub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_heartbeat_pub_rsp_t* cmd_mesh_config_client_set_heartbeat_pub(uint16 enc_netkey_index,uint16 server_address,uint16 destination_address,uint16 netkey_index,uint8 count_log,uint8 period_log,uint8 ttl,uint16 features) {
  dump_command_header("mesh_config_client_set_heartbeat_pub");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 destination_address: 0x%04x\n",(int)destination_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint8 count_log: 0x%02x\n",(int)count_log);
  printf("  uint8 period_log: 0x%02x\n",(int)period_log);
  printf("  uint8 ttl: 0x%02x\n",(int)ttl);
  printf("  uint16 features: 0x%04x\n",(int)features);
  struct gecko_msg_mesh_config_client_set_heartbeat_pub_rsp_t* resp = gecko_cmd_mesh_config_client_set_heartbeat_pub(enc_netkey_index,server_address,destination_address,netkey_index,count_log,period_log,ttl,features);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_heartbeat_pub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_heartbeat_sub_rsp_t* cmd_mesh_config_client_get_heartbeat_sub(uint16 enc_netkey_index,uint16 server_address) {
  dump_command_header("mesh_config_client_get_heartbeat_sub");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  struct gecko_msg_mesh_config_client_get_heartbeat_sub_rsp_t* resp = gecko_cmd_mesh_config_client_get_heartbeat_sub(enc_netkey_index,server_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_heartbeat_sub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_heartbeat_sub_rsp_t* cmd_mesh_config_client_set_heartbeat_sub(uint16 enc_netkey_index,uint16 server_address,uint16 source_address,uint16 destination_address,uint8 period_log) {
  dump_command_header("mesh_config_client_set_heartbeat_sub");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 source_address: 0x%04x\n",(int)source_address);
  printf("  uint16 destination_address: 0x%04x\n",(int)destination_address);
  printf("  uint8 period_log: 0x%02x\n",(int)period_log);
  struct gecko_msg_mesh_config_client_set_heartbeat_sub_rsp_t* resp = gecko_cmd_mesh_config_client_set_heartbeat_sub(enc_netkey_index,server_address,source_address,destination_address,period_log);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_heartbeat_sub(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_beacon_rsp_t* cmd_mesh_config_client_get_beacon(uint16 enc_netkey_index,uint16 server_address) {
  dump_command_header("mesh_config_client_get_beacon");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  struct gecko_msg_mesh_config_client_get_beacon_rsp_t* resp = gecko_cmd_mesh_config_client_get_beacon(enc_netkey_index,server_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_beacon(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_beacon_rsp_t* cmd_mesh_config_client_set_beacon(uint16 enc_netkey_index,uint16 server_address,uint8 value) {
  dump_command_header("mesh_config_client_set_beacon");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 value: 0x%02x\n",(int)value);
  struct gecko_msg_mesh_config_client_set_beacon_rsp_t* resp = gecko_cmd_mesh_config_client_set_beacon(enc_netkey_index,server_address,value);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_beacon(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_default_ttl_rsp_t* cmd_mesh_config_client_get_default_ttl(uint16 enc_netkey_index,uint16 server_address) {
  dump_command_header("mesh_config_client_get_default_ttl");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  struct gecko_msg_mesh_config_client_get_default_ttl_rsp_t* resp = gecko_cmd_mesh_config_client_get_default_ttl(enc_netkey_index,server_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_default_ttl(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_default_ttl_rsp_t* cmd_mesh_config_client_set_default_ttl(uint16 enc_netkey_index,uint16 server_address,uint8 value) {
  dump_command_header("mesh_config_client_set_default_ttl");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 value: 0x%02x\n",(int)value);
  struct gecko_msg_mesh_config_client_set_default_ttl_rsp_t* resp = gecko_cmd_mesh_config_client_set_default_ttl(enc_netkey_index,server_address,value);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_default_ttl(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_gatt_proxy_rsp_t* cmd_mesh_config_client_get_gatt_proxy(uint16 enc_netkey_index,uint16 server_address) {
  dump_command_header("mesh_config_client_get_gatt_proxy");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  struct gecko_msg_mesh_config_client_get_gatt_proxy_rsp_t* resp = gecko_cmd_mesh_config_client_get_gatt_proxy(enc_netkey_index,server_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_gatt_proxy(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_gatt_proxy_rsp_t* cmd_mesh_config_client_set_gatt_proxy(uint16 enc_netkey_index,uint16 server_address,uint8 value) {
  dump_command_header("mesh_config_client_set_gatt_proxy");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 value: 0x%02x\n",(int)value);
  struct gecko_msg_mesh_config_client_set_gatt_proxy_rsp_t* resp = gecko_cmd_mesh_config_client_set_gatt_proxy(enc_netkey_index,server_address,value);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_gatt_proxy(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_relay_rsp_t* cmd_mesh_config_client_get_relay(uint16 enc_netkey_index,uint16 server_address) {
  dump_command_header("mesh_config_client_get_relay");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  struct gecko_msg_mesh_config_client_get_relay_rsp_t* resp = gecko_cmd_mesh_config_client_get_relay(enc_netkey_index,server_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_relay(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_relay_rsp_t* cmd_mesh_config_client_set_relay(uint16 enc_netkey_index,uint16 server_address,uint8 value,uint8 retransmit_count,uint16 retransmit_interval_ms) {
  dump_command_header("mesh_config_client_set_relay");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 value: 0x%02x\n",(int)value);
  printf("  uint8 retransmit_count: 0x%02x\n",(int)retransmit_count);
  printf("  uint16 retransmit_interval_ms: 0x%04x\n",(int)retransmit_interval_ms);
  struct gecko_msg_mesh_config_client_set_relay_rsp_t* resp = gecko_cmd_mesh_config_client_set_relay(enc_netkey_index,server_address,value,retransmit_count,retransmit_interval_ms);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_relay(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_network_transmit_rsp_t* cmd_mesh_config_client_get_network_transmit(uint16 enc_netkey_index,uint16 server_address) {
  dump_command_header("mesh_config_client_get_network_transmit");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  struct gecko_msg_mesh_config_client_get_network_transmit_rsp_t* resp = gecko_cmd_mesh_config_client_get_network_transmit(enc_netkey_index,server_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_network_transmit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_network_transmit_rsp_t* cmd_mesh_config_client_set_network_transmit(uint16 enc_netkey_index,uint16 server_address,uint8 transmit_count,uint16 transmit_interval_ms) {
  dump_command_header("mesh_config_client_set_network_transmit");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 transmit_count: 0x%02x\n",(int)transmit_count);
  printf("  uint16 transmit_interval_ms: 0x%04x\n",(int)transmit_interval_ms);
  struct gecko_msg_mesh_config_client_set_network_transmit_rsp_t* resp = gecko_cmd_mesh_config_client_set_network_transmit(enc_netkey_index,server_address,transmit_count,transmit_interval_ms);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_network_transmit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_identity_rsp_t* cmd_mesh_config_client_get_identity(uint16 enc_netkey_index,uint16 server_address,uint16 netkey_index) {
  dump_command_header("mesh_config_client_get_identity");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  struct gecko_msg_mesh_config_client_get_identity_rsp_t* resp = gecko_cmd_mesh_config_client_get_identity(enc_netkey_index,server_address,netkey_index);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_identity(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_identity_rsp_t* cmd_mesh_config_client_set_identity(uint16 enc_netkey_index,uint16 server_address,uint16 netkey_index,uint8 value) {
  dump_command_header("mesh_config_client_set_identity");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 netkey_index: 0x%04x\n",(int)netkey_index);
  printf("  uint8 value: 0x%02x\n",(int)value);
  struct gecko_msg_mesh_config_client_set_identity_rsp_t* resp = gecko_cmd_mesh_config_client_set_identity(enc_netkey_index,server_address,netkey_index,value);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_identity(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_friend_rsp_t* cmd_mesh_config_client_get_friend(uint16 enc_netkey_index,uint16 server_address) {
  dump_command_header("mesh_config_client_get_friend");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  struct gecko_msg_mesh_config_client_get_friend_rsp_t* resp = gecko_cmd_mesh_config_client_get_friend(enc_netkey_index,server_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_friend(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_set_friend_rsp_t* cmd_mesh_config_client_set_friend(uint16 enc_netkey_index,uint16 server_address,uint8 value) {
  dump_command_header("mesh_config_client_set_friend");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 value: 0x%02x\n",(int)value);
  struct gecko_msg_mesh_config_client_set_friend_rsp_t* resp = gecko_cmd_mesh_config_client_set_friend(enc_netkey_index,server_address,value);
  printf("    RETURNED\n");
  dump_mesh_config_client_set_friend(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_lpn_polltimeout_rsp_t* cmd_mesh_config_client_get_lpn_polltimeout(uint16 enc_netkey_index,uint16 server_address,uint16 lpn_address) {
  dump_command_header("mesh_config_client_get_lpn_polltimeout");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 lpn_address: 0x%04x\n",(int)lpn_address);
  struct gecko_msg_mesh_config_client_get_lpn_polltimeout_rsp_t* resp = gecko_cmd_mesh_config_client_get_lpn_polltimeout(enc_netkey_index,server_address,lpn_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_lpn_polltimeout(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_get_dcd_rsp_t* cmd_mesh_config_client_get_dcd(uint16 enc_netkey_index,uint16 server_address,uint8 page) {
  dump_command_header("mesh_config_client_get_dcd");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint8 page: 0x%02x\n",(int)page);
  struct gecko_msg_mesh_config_client_get_dcd_rsp_t* resp = gecko_cmd_mesh_config_client_get_dcd(enc_netkey_index,server_address,page);
  printf("    RETURNED\n");
  dump_mesh_config_client_get_dcd(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_config_client_reset_node_rsp_t* cmd_mesh_config_client_reset_node(uint16 enc_netkey_index,uint16 server_address) {
  dump_command_header("mesh_config_client_reset_node");
  printf("  uint16 enc_netkey_index: 0x%04x\n",(int)enc_netkey_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  struct gecko_msg_mesh_config_client_reset_node_rsp_t* resp = gecko_cmd_mesh_config_client_reset_node(enc_netkey_index,server_address);
  printf("    RETURNED\n");
  dump_mesh_config_client_reset_node(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_l2cap_coc_send_connection_request_rsp_t* cmd_l2cap_coc_send_connection_request(uint8 connection,uint16 le_psm,uint16 mtu,uint16 mps,uint16 initial_credit) {
  dump_command_header("l2cap_coc_send_connection_request");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 le_psm: 0x%04x\n",(int)le_psm);
  printf("  uint16 mtu: 0x%04x\n",(int)mtu);
  printf("  uint16 mps: 0x%04x\n",(int)mps);
  printf("  uint16 initial_credit: 0x%04x\n",(int)initial_credit);
  struct gecko_msg_l2cap_coc_send_connection_request_rsp_t* resp = gecko_cmd_l2cap_coc_send_connection_request(connection,le_psm,mtu,mps,initial_credit);
  printf("    RETURNED\n");
  dump_l2cap_coc_send_connection_request(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_l2cap_coc_send_connection_response_rsp_t* cmd_l2cap_coc_send_connection_response(uint8 connection,uint16 cid,uint16 mtu,uint16 mps,uint16 initial_credit,uint16 result) {
  dump_command_header("l2cap_coc_send_connection_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 cid: 0x%04x\n",(int)cid);
  printf("  uint16 mtu: 0x%04x\n",(int)mtu);
  printf("  uint16 mps: 0x%04x\n",(int)mps);
  printf("  uint16 initial_credit: 0x%04x\n",(int)initial_credit);
  printf("  uint16 result: 0x%04x\n",(int)result);
  struct gecko_msg_l2cap_coc_send_connection_response_rsp_t* resp = gecko_cmd_l2cap_coc_send_connection_response(connection,cid,mtu,mps,initial_credit,result);
  printf("    RETURNED\n");
  dump_l2cap_coc_send_connection_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_l2cap_coc_send_le_flow_control_credit_rsp_t* cmd_l2cap_coc_send_le_flow_control_credit(uint8 connection,uint16 cid,uint16 credits) {
  dump_command_header("l2cap_coc_send_le_flow_control_credit");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 cid: 0x%04x\n",(int)cid);
  printf("  uint16 credits: 0x%04x\n",(int)credits);
  struct gecko_msg_l2cap_coc_send_le_flow_control_credit_rsp_t* resp = gecko_cmd_l2cap_coc_send_le_flow_control_credit(connection,cid,credits);
  printf("    RETURNED\n");
  dump_l2cap_coc_send_le_flow_control_credit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_l2cap_coc_send_disconnection_request_rsp_t* cmd_l2cap_coc_send_disconnection_request(uint8 connection,uint16 cid) {
  dump_command_header("l2cap_coc_send_disconnection_request");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 cid: 0x%04x\n",(int)cid);
  struct gecko_msg_l2cap_coc_send_disconnection_request_rsp_t* resp = gecko_cmd_l2cap_coc_send_disconnection_request(connection,cid);
  printf("    RETURNED\n");
  dump_l2cap_coc_send_disconnection_request(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_l2cap_coc_send_data_rsp_t* cmd_l2cap_coc_send_data(uint8 connection,uint16 cid,uint8 data_len, const uint8* data_data) {
  dump_command_header("l2cap_coc_send_data");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 cid: 0x%04x\n",(int)cid);
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_l2cap_coc_send_data_rsp_t* resp = gecko_cmd_l2cap_coc_send_data(connection,cid,data_len,data_data);
  printf("    RETURNED\n");
  dump_l2cap_coc_send_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_enable_cte_response_rsp_t* cmd_cte_transmitter_enable_cte_response(uint8 connection,uint8 cte_types,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_transmitter_enable_cte_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 cte_types: 0x%02x\n",(int)cte_types);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_transmitter_enable_cte_response_rsp_t* resp = gecko_cmd_cte_transmitter_enable_cte_response(connection,cte_types,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_transmitter_enable_cte_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_disable_cte_response_rsp_t* cmd_cte_transmitter_disable_cte_response(uint8 connection) {
  dump_command_header("cte_transmitter_disable_cte_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_cte_transmitter_disable_cte_response_rsp_t* resp = gecko_cmd_cte_transmitter_disable_cte_response(connection);
  printf("    RETURNED\n");
  dump_cte_transmitter_disable_cte_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_start_connectionless_cte_rsp_t* cmd_cte_transmitter_start_connectionless_cte(uint8 adv,uint8 cte_length,uint8 cte_type,uint8 cte_count,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_transmitter_start_connectionless_cte");
  printf("  uint8 adv: 0x%02x\n",(int)adv);
  printf("  uint8 cte_length: 0x%02x\n",(int)cte_length);
  printf("  uint8 cte_type: 0x%02x\n",(int)cte_type);
  printf("  uint8 cte_count: 0x%02x\n",(int)cte_count);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_transmitter_start_connectionless_cte_rsp_t* resp = gecko_cmd_cte_transmitter_start_connectionless_cte(adv,cte_length,cte_type,cte_count,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_transmitter_start_connectionless_cte(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_stop_connectionless_cte_rsp_t* cmd_cte_transmitter_stop_connectionless_cte(uint8 adv) {
  dump_command_header("cte_transmitter_stop_connectionless_cte");
  printf("  uint8 adv: 0x%02x\n",(int)adv);
  struct gecko_msg_cte_transmitter_stop_connectionless_cte_rsp_t* resp = gecko_cmd_cte_transmitter_stop_connectionless_cte(adv);
  printf("    RETURNED\n");
  dump_cte_transmitter_stop_connectionless_cte(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_set_dtm_parameters_rsp_t* cmd_cte_transmitter_set_dtm_parameters(uint8 cte_length,uint8 cte_type,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_transmitter_set_dtm_parameters");
  printf("  uint8 cte_length: 0x%02x\n",(int)cte_length);
  printf("  uint8 cte_type: 0x%02x\n",(int)cte_type);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_transmitter_set_dtm_parameters_rsp_t* resp = gecko_cmd_cte_transmitter_set_dtm_parameters(cte_length,cte_type,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_transmitter_set_dtm_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_clear_dtm_parameters_rsp_t* cmd_cte_transmitter_clear_dtm_parameters() {
  dump_command_header("cte_transmitter_clear_dtm_parameters");
  struct gecko_msg_cte_transmitter_clear_dtm_parameters_rsp_t* resp = gecko_cmd_cte_transmitter_clear_dtm_parameters();
  printf("    RETURNED\n");
  dump_cte_transmitter_clear_dtm_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_configure_rsp_t* cmd_cte_receiver_configure(uint8 flags) {
  dump_command_header("cte_receiver_configure");
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  struct gecko_msg_cte_receiver_configure_rsp_t* resp = gecko_cmd_cte_receiver_configure(flags);
  printf("    RETURNED\n");
  dump_cte_receiver_configure(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_start_iq_sampling_rsp_t* cmd_cte_receiver_start_iq_sampling(uint8 connection,uint16 interval,uint8 cte_length,uint8 cte_type,uint8 slot_durations,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_receiver_start_iq_sampling");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 interval: 0x%04x\n",(int)interval);
  printf("  uint8 cte_length: 0x%02x\n",(int)cte_length);
  printf("  uint8 cte_type: 0x%02x\n",(int)cte_type);
  printf("  uint8 slot_durations: 0x%02x\n",(int)slot_durations);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_receiver_start_iq_sampling_rsp_t* resp = gecko_cmd_cte_receiver_start_iq_sampling(connection,interval,cte_length,cte_type,slot_durations,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_receiver_start_iq_sampling(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_stop_iq_sampling_rsp_t* cmd_cte_receiver_stop_iq_sampling(uint8 connection) {
  dump_command_header("cte_receiver_stop_iq_sampling");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_cte_receiver_stop_iq_sampling_rsp_t* resp = gecko_cmd_cte_receiver_stop_iq_sampling(connection);
  printf("    RETURNED\n");
  dump_cte_receiver_stop_iq_sampling(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_start_connectionless_iq_sampling_rsp_t* cmd_cte_receiver_start_connectionless_iq_sampling(uint8 sync,uint8 slot_durations,uint8 cte_count,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_receiver_start_connectionless_iq_sampling");
  printf("  uint8 sync: 0x%02x\n",(int)sync);
  printf("  uint8 slot_durations: 0x%02x\n",(int)slot_durations);
  printf("  uint8 cte_count: 0x%02x\n",(int)cte_count);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_receiver_start_connectionless_iq_sampling_rsp_t* resp = gecko_cmd_cte_receiver_start_connectionless_iq_sampling(sync,slot_durations,cte_count,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_receiver_start_connectionless_iq_sampling(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_stop_connectionless_iq_sampling_rsp_t* cmd_cte_receiver_stop_connectionless_iq_sampling(uint8 sync) {
  dump_command_header("cte_receiver_stop_connectionless_iq_sampling");
  printf("  uint8 sync: 0x%02x\n",(int)sync);
  struct gecko_msg_cte_receiver_stop_connectionless_iq_sampling_rsp_t* resp = gecko_cmd_cte_receiver_stop_connectionless_iq_sampling(sync);
  printf("    RETURNED\n");
  dump_cte_receiver_stop_connectionless_iq_sampling(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_set_dtm_parameters_rsp_t* cmd_cte_receiver_set_dtm_parameters(uint8 cte_length,uint8 cte_type,uint8 slot_durations,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_receiver_set_dtm_parameters");
  printf("  uint8 cte_length: 0x%02x\n",(int)cte_length);
  printf("  uint8 cte_type: 0x%02x\n",(int)cte_type);
  printf("  uint8 slot_durations: 0x%02x\n",(int)slot_durations);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_receiver_set_dtm_parameters_rsp_t* resp = gecko_cmd_cte_receiver_set_dtm_parameters(cte_length,cte_type,slot_durations,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_receiver_set_dtm_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_clear_dtm_parameters_rsp_t* cmd_cte_receiver_clear_dtm_parameters() {
  dump_command_header("cte_receiver_clear_dtm_parameters");
  struct gecko_msg_cte_receiver_clear_dtm_parameters_rsp_t* resp = gecko_cmd_cte_receiver_clear_dtm_parameters();
  printf("    RETURNED\n");
  dump_cte_receiver_clear_dtm_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_server_init_rsp_t* cmd_mesh_sensor_server_init(uint16 elem_index,uint8 descriptors_len, const uint8* descriptors_data) {
  dump_command_header("mesh_sensor_server_init");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint8 descriptors_len: 0x%02x\n",(int)descriptors_len);
  printf("  const uint8* descriptors_data: 0x%p\n",descriptors_data);
  struct gecko_msg_mesh_sensor_server_init_rsp_t* resp = gecko_cmd_mesh_sensor_server_init(elem_index,descriptors_len,descriptors_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_server_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_server_deinit_rsp_t* cmd_mesh_sensor_server_deinit(uint16 elem_index) {
  dump_command_header("mesh_sensor_server_deinit");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_sensor_server_deinit_rsp_t* resp = gecko_cmd_mesh_sensor_server_deinit(elem_index);
  printf("    RETURNED\n");
  dump_mesh_sensor_server_deinit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_server_send_descriptor_status_rsp_t* cmd_mesh_sensor_server_send_descriptor_status(uint16 elem_index,uint16 client_address,uint16 appkey_index,uint8 flags,uint8 descriptors_len, const uint8* descriptors_data) {
  dump_command_header("mesh_sensor_server_send_descriptor_status");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 client_address: 0x%04x\n",(int)client_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint8 descriptors_len: 0x%02x\n",(int)descriptors_len);
  printf("  const uint8* descriptors_data: 0x%p\n",descriptors_data);
  struct gecko_msg_mesh_sensor_server_send_descriptor_status_rsp_t* resp = gecko_cmd_mesh_sensor_server_send_descriptor_status(elem_index,client_address,appkey_index,flags,descriptors_len,descriptors_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_server_send_descriptor_status(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_server_send_status_rsp_t* cmd_mesh_sensor_server_send_status(uint16 elem_index,uint16 client_address,uint16 appkey_index,uint8 flags,uint8 sensor_data_len, const uint8* sensor_data_data) {
  dump_command_header("mesh_sensor_server_send_status");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 client_address: 0x%04x\n",(int)client_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint8 sensor_data_len: 0x%02x\n",(int)sensor_data_len);
  printf("  const uint8* sensor_data_data: 0x%p\n",sensor_data_data);
  struct gecko_msg_mesh_sensor_server_send_status_rsp_t* resp = gecko_cmd_mesh_sensor_server_send_status(elem_index,client_address,appkey_index,flags,sensor_data_len,sensor_data_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_server_send_status(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_server_send_column_status_rsp_t* cmd_mesh_sensor_server_send_column_status(uint16 elem_index,uint16 client_address,uint16 appkey_index,uint8 flags,uint16 property_id,uint8 sensor_data_len, const uint8* sensor_data_data) {
  dump_command_header("mesh_sensor_server_send_column_status");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 client_address: 0x%04x\n",(int)client_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint8 sensor_data_len: 0x%02x\n",(int)sensor_data_len);
  printf("  const uint8* sensor_data_data: 0x%p\n",sensor_data_data);
  struct gecko_msg_mesh_sensor_server_send_column_status_rsp_t* resp = gecko_cmd_mesh_sensor_server_send_column_status(elem_index,client_address,appkey_index,flags,property_id,sensor_data_len,sensor_data_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_server_send_column_status(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_server_send_series_status_rsp_t* cmd_mesh_sensor_server_send_series_status(uint16 elem_index,uint16 client_address,uint16 appkey_index,uint8 flags,uint16 property_id,uint8 sensor_data_len, const uint8* sensor_data_data) {
  dump_command_header("mesh_sensor_server_send_series_status");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 client_address: 0x%04x\n",(int)client_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint8 sensor_data_len: 0x%02x\n",(int)sensor_data_len);
  printf("  const uint8* sensor_data_data: 0x%p\n",sensor_data_data);
  struct gecko_msg_mesh_sensor_server_send_series_status_rsp_t* resp = gecko_cmd_mesh_sensor_server_send_series_status(elem_index,client_address,appkey_index,flags,property_id,sensor_data_len,sensor_data_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_server_send_series_status(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_setup_server_send_cadence_status_rsp_t* cmd_mesh_sensor_setup_server_send_cadence_status(uint16 elem_index,uint16 client_address,uint16 appkey_index,uint8 flags,uint16 property_id,uint8 params_len, const uint8* params_data) {
  dump_command_header("mesh_sensor_setup_server_send_cadence_status");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 client_address: 0x%04x\n",(int)client_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint8 params_len: 0x%02x\n",(int)params_len);
  printf("  const uint8* params_data: 0x%p\n",params_data);
  struct gecko_msg_mesh_sensor_setup_server_send_cadence_status_rsp_t* resp = gecko_cmd_mesh_sensor_setup_server_send_cadence_status(elem_index,client_address,appkey_index,flags,property_id,params_len,params_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_setup_server_send_cadence_status(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_setup_server_send_settings_status_rsp_t* cmd_mesh_sensor_setup_server_send_settings_status(uint16 elem_index,uint16 client_address,uint16 appkey_index,uint8 flags,uint16 property_id,uint8 setting_ids_len, const uint8* setting_ids_data) {
  dump_command_header("mesh_sensor_setup_server_send_settings_status");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 client_address: 0x%04x\n",(int)client_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint8 setting_ids_len: 0x%02x\n",(int)setting_ids_len);
  printf("  const uint8* setting_ids_data: 0x%p\n",setting_ids_data);
  struct gecko_msg_mesh_sensor_setup_server_send_settings_status_rsp_t* resp = gecko_cmd_mesh_sensor_setup_server_send_settings_status(elem_index,client_address,appkey_index,flags,property_id,setting_ids_len,setting_ids_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_setup_server_send_settings_status(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_setup_server_send_setting_status_rsp_t* cmd_mesh_sensor_setup_server_send_setting_status(uint16 elem_index,uint16 client_address,uint16 appkey_index,uint8 flags,uint16 property_id,uint16 setting_id,uint8 raw_value_len, const uint8* raw_value_data) {
  dump_command_header("mesh_sensor_setup_server_send_setting_status");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 client_address: 0x%04x\n",(int)client_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint16 setting_id: 0x%04x\n",(int)setting_id);
  printf("  uint8 raw_value_len: 0x%02x\n",(int)raw_value_len);
  printf("  const uint8* raw_value_data: 0x%p\n",raw_value_data);
  struct gecko_msg_mesh_sensor_setup_server_send_setting_status_rsp_t* resp = gecko_cmd_mesh_sensor_setup_server_send_setting_status(elem_index,client_address,appkey_index,flags,property_id,setting_id,raw_value_len,raw_value_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_setup_server_send_setting_status(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_client_init_rsp_t* cmd_mesh_sensor_client_init() {
  dump_command_header("mesh_sensor_client_init");
  struct gecko_msg_mesh_sensor_client_init_rsp_t* resp = gecko_cmd_mesh_sensor_client_init();
  printf("    RETURNED\n");
  dump_mesh_sensor_client_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_client_deinit_rsp_t* cmd_mesh_sensor_client_deinit() {
  dump_command_header("mesh_sensor_client_deinit");
  struct gecko_msg_mesh_sensor_client_deinit_rsp_t* resp = gecko_cmd_mesh_sensor_client_deinit();
  printf("    RETURNED\n");
  dump_mesh_sensor_client_deinit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_client_get_descriptor_rsp_t* cmd_mesh_sensor_client_get_descriptor(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 property_id) {
  dump_command_header("mesh_sensor_client_get_descriptor");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  struct gecko_msg_mesh_sensor_client_get_descriptor_rsp_t* resp = gecko_cmd_mesh_sensor_client_get_descriptor(elem_index,server_address,appkey_index,flags,property_id);
  printf("    RETURNED\n");
  dump_mesh_sensor_client_get_descriptor(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_client_get_rsp_t* cmd_mesh_sensor_client_get(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 property_id) {
  dump_command_header("mesh_sensor_client_get");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  struct gecko_msg_mesh_sensor_client_get_rsp_t* resp = gecko_cmd_mesh_sensor_client_get(elem_index,server_address,appkey_index,flags,property_id);
  printf("    RETURNED\n");
  dump_mesh_sensor_client_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_client_get_column_rsp_t* cmd_mesh_sensor_client_get_column(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 property_id,uint8 column_id_len, const uint8* column_id_data) {
  dump_command_header("mesh_sensor_client_get_column");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint8 column_id_len: 0x%02x\n",(int)column_id_len);
  printf("  const uint8* column_id_data: 0x%p\n",column_id_data);
  struct gecko_msg_mesh_sensor_client_get_column_rsp_t* resp = gecko_cmd_mesh_sensor_client_get_column(elem_index,server_address,appkey_index,flags,property_id,column_id_len,column_id_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_client_get_column(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_client_get_series_rsp_t* cmd_mesh_sensor_client_get_series(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 property_id,uint8 column_ids_len, const uint8* column_ids_data) {
  dump_command_header("mesh_sensor_client_get_series");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint8 column_ids_len: 0x%02x\n",(int)column_ids_len);
  printf("  const uint8* column_ids_data: 0x%p\n",column_ids_data);
  struct gecko_msg_mesh_sensor_client_get_series_rsp_t* resp = gecko_cmd_mesh_sensor_client_get_series(elem_index,server_address,appkey_index,flags,property_id,column_ids_len,column_ids_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_client_get_series(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_client_get_cadence_rsp_t* cmd_mesh_sensor_client_get_cadence(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 property_id) {
  dump_command_header("mesh_sensor_client_get_cadence");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  struct gecko_msg_mesh_sensor_client_get_cadence_rsp_t* resp = gecko_cmd_mesh_sensor_client_get_cadence(elem_index,server_address,appkey_index,flags,property_id);
  printf("    RETURNED\n");
  dump_mesh_sensor_client_get_cadence(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_client_set_cadence_rsp_t* cmd_mesh_sensor_client_set_cadence(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 property_id,uint8 params_len, const uint8* params_data) {
  dump_command_header("mesh_sensor_client_set_cadence");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint8 params_len: 0x%02x\n",(int)params_len);
  printf("  const uint8* params_data: 0x%p\n",params_data);
  struct gecko_msg_mesh_sensor_client_set_cadence_rsp_t* resp = gecko_cmd_mesh_sensor_client_set_cadence(elem_index,server_address,appkey_index,flags,property_id,params_len,params_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_client_set_cadence(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_client_get_settings_rsp_t* cmd_mesh_sensor_client_get_settings(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 property_id) {
  dump_command_header("mesh_sensor_client_get_settings");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  struct gecko_msg_mesh_sensor_client_get_settings_rsp_t* resp = gecko_cmd_mesh_sensor_client_get_settings(elem_index,server_address,appkey_index,flags,property_id);
  printf("    RETURNED\n");
  dump_mesh_sensor_client_get_settings(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_client_get_setting_rsp_t* cmd_mesh_sensor_client_get_setting(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 property_id,uint16 setting_id) {
  dump_command_header("mesh_sensor_client_get_setting");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint16 setting_id: 0x%04x\n",(int)setting_id);
  struct gecko_msg_mesh_sensor_client_get_setting_rsp_t* resp = gecko_cmd_mesh_sensor_client_get_setting(elem_index,server_address,appkey_index,flags,property_id,setting_id);
  printf("    RETURNED\n");
  dump_mesh_sensor_client_get_setting(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_sensor_client_set_setting_rsp_t* cmd_mesh_sensor_client_set_setting(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 property_id,uint16 setting_id,uint8 raw_value_len, const uint8* raw_value_data) {
  dump_command_header("mesh_sensor_client_set_setting");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint16 setting_id: 0x%04x\n",(int)setting_id);
  printf("  uint8 raw_value_len: 0x%02x\n",(int)raw_value_len);
  printf("  const uint8* raw_value_data: 0x%p\n",raw_value_data);
  struct gecko_msg_mesh_sensor_client_set_setting_rsp_t* resp = gecko_cmd_mesh_sensor_client_set_setting(elem_index,server_address,appkey_index,flags,property_id,setting_id,raw_value_len,raw_value_data);
  printf("    RETURNED\n");
  dump_mesh_sensor_client_set_setting(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_client_init_rsp_t* cmd_mesh_lc_client_init(uint16 elem_index) {
  dump_command_header("mesh_lc_client_init");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_lc_client_init_rsp_t* resp = gecko_cmd_mesh_lc_client_init(elem_index);
  printf("    RETURNED\n");
  dump_mesh_lc_client_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_client_get_mode_rsp_t* cmd_mesh_lc_client_get_mode(uint16 elem_index,uint16 server_address,uint16 appkey_index) {
  dump_command_header("mesh_lc_client_get_mode");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_lc_client_get_mode_rsp_t* resp = gecko_cmd_mesh_lc_client_get_mode(elem_index,server_address,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_lc_client_get_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_client_set_mode_rsp_t* cmd_mesh_lc_client_set_mode(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint8 mode) {
  dump_command_header("mesh_lc_client_set_mode");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint8 mode: 0x%02x\n",(int)mode);
  struct gecko_msg_mesh_lc_client_set_mode_rsp_t* resp = gecko_cmd_mesh_lc_client_set_mode(elem_index,server_address,appkey_index,flags,mode);
  printf("    RETURNED\n");
  dump_mesh_lc_client_set_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_client_get_om_rsp_t* cmd_mesh_lc_client_get_om(uint16 elem_index,uint16 server_address,uint16 appkey_index) {
  dump_command_header("mesh_lc_client_get_om");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_lc_client_get_om_rsp_t* resp = gecko_cmd_mesh_lc_client_get_om(elem_index,server_address,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_lc_client_get_om(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_client_set_om_rsp_t* cmd_mesh_lc_client_set_om(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint8 mode) {
  dump_command_header("mesh_lc_client_set_om");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint8 mode: 0x%02x\n",(int)mode);
  struct gecko_msg_mesh_lc_client_set_om_rsp_t* resp = gecko_cmd_mesh_lc_client_set_om(elem_index,server_address,appkey_index,flags,mode);
  printf("    RETURNED\n");
  dump_mesh_lc_client_set_om(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_client_get_light_onoff_rsp_t* cmd_mesh_lc_client_get_light_onoff(uint16 elem_index,uint16 server_address,uint16 appkey_index) {
  dump_command_header("mesh_lc_client_get_light_onoff");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_lc_client_get_light_onoff_rsp_t* resp = gecko_cmd_mesh_lc_client_get_light_onoff(elem_index,server_address,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_lc_client_get_light_onoff(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_client_set_light_onoff_rsp_t* cmd_mesh_lc_client_set_light_onoff(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint8 target_state,uint8 tid,uint32 transition_time,uint16 message_delay) {
  dump_command_header("mesh_lc_client_set_light_onoff");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint8 target_state: 0x%02x\n",(int)target_state);
  printf("  uint8 tid: 0x%02x\n",(int)tid);
  printf("  uint32 transition_time: 0x%08x\n",(int)transition_time);
  printf("  uint16 message_delay: 0x%04x\n",(int)message_delay);
  struct gecko_msg_mesh_lc_client_set_light_onoff_rsp_t* resp = gecko_cmd_mesh_lc_client_set_light_onoff(elem_index,server_address,appkey_index,flags,target_state,tid,transition_time,message_delay);
  printf("    RETURNED\n");
  dump_mesh_lc_client_set_light_onoff(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_client_get_property_rsp_t* cmd_mesh_lc_client_get_property(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint16 property_id) {
  dump_command_header("mesh_lc_client_get_property");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  struct gecko_msg_mesh_lc_client_get_property_rsp_t* resp = gecko_cmd_mesh_lc_client_get_property(elem_index,server_address,appkey_index,property_id);
  printf("    RETURNED\n");
  dump_mesh_lc_client_get_property(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_client_set_property_rsp_t* cmd_mesh_lc_client_set_property(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 property_id,uint8 params_len, const uint8* params_data) {
  dump_command_header("mesh_lc_client_set_property");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint8 params_len: 0x%02x\n",(int)params_len);
  printf("  const uint8* params_data: 0x%p\n",params_data);
  struct gecko_msg_mesh_lc_client_set_property_rsp_t* resp = gecko_cmd_mesh_lc_client_set_property(elem_index,server_address,appkey_index,flags,property_id,params_len,params_data);
  printf("    RETURNED\n");
  dump_mesh_lc_client_set_property(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_server_init_rsp_t* cmd_mesh_lc_server_init(uint16 elem_index) {
  dump_command_header("mesh_lc_server_init");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_lc_server_init_rsp_t* resp = gecko_cmd_mesh_lc_server_init(elem_index);
  printf("    RETURNED\n");
  dump_mesh_lc_server_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_server_deinit_rsp_t* cmd_mesh_lc_server_deinit(uint16 elem_index) {
  dump_command_header("mesh_lc_server_deinit");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_lc_server_deinit_rsp_t* resp = gecko_cmd_mesh_lc_server_deinit(elem_index);
  printf("    RETURNED\n");
  dump_mesh_lc_server_deinit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_server_update_mode_rsp_t* cmd_mesh_lc_server_update_mode(uint16 elem_index,uint8 mode) {
  dump_command_header("mesh_lc_server_update_mode");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint8 mode: 0x%02x\n",(int)mode);
  struct gecko_msg_mesh_lc_server_update_mode_rsp_t* resp = gecko_cmd_mesh_lc_server_update_mode(elem_index,mode);
  printf("    RETURNED\n");
  dump_mesh_lc_server_update_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_server_update_om_rsp_t* cmd_mesh_lc_server_update_om(uint16 elem_index,uint8 om) {
  dump_command_header("mesh_lc_server_update_om");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint8 om: 0x%02x\n",(int)om);
  struct gecko_msg_mesh_lc_server_update_om_rsp_t* resp = gecko_cmd_mesh_lc_server_update_om(elem_index,om);
  printf("    RETURNED\n");
  dump_mesh_lc_server_update_om(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_server_update_light_onoff_rsp_t* cmd_mesh_lc_server_update_light_onoff(uint16 elem_index,uint8 light_onoff,uint32 transition_time_ms) {
  dump_command_header("mesh_lc_server_update_light_onoff");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint8 light_onoff: 0x%02x\n",(int)light_onoff);
  printf("  uint32 transition_time_ms: 0x%08x\n",(int)transition_time_ms);
  struct gecko_msg_mesh_lc_server_update_light_onoff_rsp_t* resp = gecko_cmd_mesh_lc_server_update_light_onoff(elem_index,light_onoff,transition_time_ms);
  printf("    RETURNED\n");
  dump_mesh_lc_server_update_light_onoff(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_server_init_all_properties_rsp_t* cmd_mesh_lc_server_init_all_properties(uint16 elem_index) {
  dump_command_header("mesh_lc_server_init_all_properties");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_lc_server_init_all_properties_rsp_t* resp = gecko_cmd_mesh_lc_server_init_all_properties(elem_index);
  printf("    RETURNED\n");
  dump_mesh_lc_server_init_all_properties(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_server_set_publish_mask_rsp_t* cmd_mesh_lc_server_set_publish_mask(uint16 elem_index,uint16 status_type,uint8 value) {
  dump_command_header("mesh_lc_server_set_publish_mask");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 status_type: 0x%04x\n",(int)status_type);
  printf("  uint8 value: 0x%02x\n",(int)value);
  struct gecko_msg_mesh_lc_server_set_publish_mask_rsp_t* resp = gecko_cmd_mesh_lc_server_set_publish_mask(elem_index,status_type,value);
  printf("    RETURNED\n");
  dump_mesh_lc_server_set_publish_mask(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_server_set_regulator_interval_rsp_t* cmd_mesh_lc_server_set_regulator_interval(uint16 elem_index,uint8 value) {
  dump_command_header("mesh_lc_server_set_regulator_interval");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint8 value: 0x%02x\n",(int)value);
  struct gecko_msg_mesh_lc_server_set_regulator_interval_rsp_t* resp = gecko_cmd_mesh_lc_server_set_regulator_interval(elem_index,value);
  printf("    RETURNED\n");
  dump_mesh_lc_server_set_regulator_interval(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_server_set_event_mask_rsp_t* cmd_mesh_lc_server_set_event_mask(uint16 elem_index,uint16 event_type,uint8 value) {
  dump_command_header("mesh_lc_server_set_event_mask");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 event_type: 0x%04x\n",(int)event_type);
  printf("  uint8 value: 0x%02x\n",(int)value);
  struct gecko_msg_mesh_lc_server_set_event_mask_rsp_t* resp = gecko_cmd_mesh_lc_server_set_event_mask(elem_index,event_type,value);
  printf("    RETURNED\n");
  dump_mesh_lc_server_set_event_mask(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_server_get_lc_state_rsp_t* cmd_mesh_lc_server_get_lc_state(uint16 elem_index) {
  dump_command_header("mesh_lc_server_get_lc_state");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_lc_server_get_lc_state_rsp_t* resp = gecko_cmd_mesh_lc_server_get_lc_state(elem_index);
  printf("    RETURNED\n");
  dump_mesh_lc_server_get_lc_state(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_lc_setup_server_update_property_rsp_t* cmd_mesh_lc_setup_server_update_property(uint16 elem_index,uint16 property_id,uint8 params_len, const uint8* params_data) {
  dump_command_header("mesh_lc_setup_server_update_property");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 property_id: 0x%04x\n",(int)property_id);
  printf("  uint8 params_len: 0x%02x\n",(int)params_len);
  printf("  const uint8* params_data: 0x%p\n",params_data);
  struct gecko_msg_mesh_lc_setup_server_update_property_rsp_t* resp = gecko_cmd_mesh_lc_setup_server_update_property(elem_index,property_id,params_len,params_data);
  printf("    RETURNED\n");
  dump_mesh_lc_setup_server_update_property(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_scene_client_init_rsp_t* cmd_mesh_scene_client_init(uint16 elem_index) {
  dump_command_header("mesh_scene_client_init");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_scene_client_init_rsp_t* resp = gecko_cmd_mesh_scene_client_init(elem_index);
  printf("    RETURNED\n");
  dump_mesh_scene_client_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_scene_client_get_rsp_t* cmd_mesh_scene_client_get(uint16 elem_index,uint16 server_address,uint16 appkey_index) {
  dump_command_header("mesh_scene_client_get");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_scene_client_get_rsp_t* resp = gecko_cmd_mesh_scene_client_get(elem_index,server_address,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_scene_client_get(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_scene_client_get_register_rsp_t* cmd_mesh_scene_client_get_register(uint16 elem_index,uint16 server_address,uint16 appkey_index) {
  dump_command_header("mesh_scene_client_get_register");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_scene_client_get_register_rsp_t* resp = gecko_cmd_mesh_scene_client_get_register(elem_index,server_address,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_scene_client_get_register(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_scene_client_recall_rsp_t* cmd_mesh_scene_client_recall(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 selected_scene,uint8 tid,uint32 transition_time,uint32 delay) {
  dump_command_header("mesh_scene_client_recall");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 selected_scene: 0x%04x\n",(int)selected_scene);
  printf("  uint8 tid: 0x%02x\n",(int)tid);
  printf("  uint32 transition_time: 0x%08x\n",(int)transition_time);
  printf("  uint32 delay: 0x%08x\n",(int)delay);
  struct gecko_msg_mesh_scene_client_recall_rsp_t* resp = gecko_cmd_mesh_scene_client_recall(elem_index,server_address,appkey_index,flags,selected_scene,tid,transition_time,delay);
  printf("    RETURNED\n");
  dump_mesh_scene_client_recall(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_scene_client_store_rsp_t* cmd_mesh_scene_client_store(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 selected_scene) {
  dump_command_header("mesh_scene_client_store");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 selected_scene: 0x%04x\n",(int)selected_scene);
  struct gecko_msg_mesh_scene_client_store_rsp_t* resp = gecko_cmd_mesh_scene_client_store(elem_index,server_address,appkey_index,flags,selected_scene);
  printf("    RETURNED\n");
  dump_mesh_scene_client_store(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_scene_client_delete_rsp_t* cmd_mesh_scene_client_delete(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 flags,uint16 selected_scene) {
  dump_command_header("mesh_scene_client_delete");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint16 selected_scene: 0x%04x\n",(int)selected_scene);
  struct gecko_msg_mesh_scene_client_delete_rsp_t* resp = gecko_cmd_mesh_scene_client_delete(elem_index,server_address,appkey_index,flags,selected_scene);
  printf("    RETURNED\n");
  dump_mesh_scene_client_delete(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_scene_server_init_rsp_t* cmd_mesh_scene_server_init(uint16 elem_index) {
  dump_command_header("mesh_scene_server_init");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_scene_server_init_rsp_t* resp = gecko_cmd_mesh_scene_server_init(elem_index);
  printf("    RETURNED\n");
  dump_mesh_scene_server_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_scene_server_deinit_rsp_t* cmd_mesh_scene_server_deinit(uint16 elem_index) {
  dump_command_header("mesh_scene_server_deinit");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_scene_server_deinit_rsp_t* resp = gecko_cmd_mesh_scene_server_deinit(elem_index);
  printf("    RETURNED\n");
  dump_mesh_scene_server_deinit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_scene_setup_server_init_rsp_t* cmd_mesh_scene_setup_server_init(uint16 elem_index) {
  dump_command_header("mesh_scene_setup_server_init");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_scene_setup_server_init_rsp_t* resp = gecko_cmd_mesh_scene_setup_server_init(elem_index);
  printf("    RETURNED\n");
  dump_mesh_scene_setup_server_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_server_init_rsp_t* cmd_mesh_time_server_init(uint16 elem_index) {
  dump_command_header("mesh_time_server_init");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_time_server_init_rsp_t* resp = gecko_cmd_mesh_time_server_init(elem_index);
  printf("    RETURNED\n");
  dump_mesh_time_server_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_server_deinit_rsp_t* cmd_mesh_time_server_deinit(uint16 elem_index) {
  dump_command_header("mesh_time_server_deinit");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_time_server_deinit_rsp_t* resp = gecko_cmd_mesh_time_server_deinit(elem_index);
  printf("    RETURNED\n");
  dump_mesh_time_server_deinit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_server_get_time_rsp_t* cmd_mesh_time_server_get_time(uint16 elem_index) {
  dump_command_header("mesh_time_server_get_time");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_time_server_get_time_rsp_t* resp = gecko_cmd_mesh_time_server_get_time(elem_index);
  printf("    RETURNED\n");
  dump_mesh_time_server_get_time(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_server_set_time_rsp_t* cmd_mesh_time_server_set_time(uint16 elem_index,uint64 tai_seconds,uint8 subsecond,uint8 uncertainty,uint8 time_authority,int16 time_zone_offset,int32 tai_utc_delta) {
  dump_command_header("mesh_time_server_set_time");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint64 tai_seconds: 0x%08x%08x\n",((int*)&tai_seconds)[1],((int*)&tai_seconds)[0]);
  printf("  uint8 subsecond: 0x%02x\n",(int)subsecond);
  printf("  uint8 uncertainty: 0x%02x\n",(int)uncertainty);
  printf("  uint8 time_authority: 0x%02x\n",(int)time_authority);
  printf("  int16 time_zone_offset: 0x%04x\n",(int)time_zone_offset);
  printf("  int32 tai_utc_delta: 0x%04x\n",(int)tai_utc_delta);
  struct gecko_msg_mesh_time_server_set_time_rsp_t* resp = gecko_cmd_mesh_time_server_set_time(elem_index,tai_seconds,subsecond,uncertainty,time_authority,time_zone_offset,tai_utc_delta);
  printf("    RETURNED\n");
  dump_mesh_time_server_set_time(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_server_get_time_zone_offset_new_rsp_t* cmd_mesh_time_server_get_time_zone_offset_new(uint16 elem_index) {
  dump_command_header("mesh_time_server_get_time_zone_offset_new");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_time_server_get_time_zone_offset_new_rsp_t* resp = gecko_cmd_mesh_time_server_get_time_zone_offset_new(elem_index);
  printf("    RETURNED\n");
  dump_mesh_time_server_get_time_zone_offset_new(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_server_set_time_zone_offset_new_rsp_t* cmd_mesh_time_server_set_time_zone_offset_new(uint16 elem_index,int16 new_offset,uint64 tai_of_zone_change) {
  dump_command_header("mesh_time_server_set_time_zone_offset_new");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  int16 new_offset: 0x%04x\n",(int)new_offset);
  printf("  uint64 tai_of_zone_change: 0x%08x%08x\n",((int*)&tai_of_zone_change)[1],((int*)&tai_of_zone_change)[0]);
  struct gecko_msg_mesh_time_server_set_time_zone_offset_new_rsp_t* resp = gecko_cmd_mesh_time_server_set_time_zone_offset_new(elem_index,new_offset,tai_of_zone_change);
  printf("    RETURNED\n");
  dump_mesh_time_server_set_time_zone_offset_new(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_server_get_tai_utc_delta_new_rsp_t* cmd_mesh_time_server_get_tai_utc_delta_new(uint16 elem_index) {
  dump_command_header("mesh_time_server_get_tai_utc_delta_new");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_time_server_get_tai_utc_delta_new_rsp_t* resp = gecko_cmd_mesh_time_server_get_tai_utc_delta_new(elem_index);
  printf("    RETURNED\n");
  dump_mesh_time_server_get_tai_utc_delta_new(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_server_set_tai_utc_delta_new_rsp_t* cmd_mesh_time_server_set_tai_utc_delta_new(uint16 elem_index,int32 new_delta,uint64 tai_of_delta_change) {
  dump_command_header("mesh_time_server_set_tai_utc_delta_new");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  int32 new_delta: 0x%04x\n",(int)new_delta);
  printf("  uint64 tai_of_delta_change: 0x%08x%08x\n",((int*)&tai_of_delta_change)[1],((int*)&tai_of_delta_change)[0]);
  struct gecko_msg_mesh_time_server_set_tai_utc_delta_new_rsp_t* resp = gecko_cmd_mesh_time_server_set_tai_utc_delta_new(elem_index,new_delta,tai_of_delta_change);
  printf("    RETURNED\n");
  dump_mesh_time_server_set_tai_utc_delta_new(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_server_get_time_role_rsp_t* cmd_mesh_time_server_get_time_role(uint16 elem_index) {
  dump_command_header("mesh_time_server_get_time_role");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_time_server_get_time_role_rsp_t* resp = gecko_cmd_mesh_time_server_get_time_role(elem_index);
  printf("    RETURNED\n");
  dump_mesh_time_server_get_time_role(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_server_set_time_role_rsp_t* cmd_mesh_time_server_set_time_role(uint16 elem_index,uint8 time_role) {
  dump_command_header("mesh_time_server_set_time_role");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint8 time_role: 0x%02x\n",(int)time_role);
  struct gecko_msg_mesh_time_server_set_time_role_rsp_t* resp = gecko_cmd_mesh_time_server_set_time_role(elem_index,time_role);
  printf("    RETURNED\n");
  dump_mesh_time_server_set_time_role(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_server_get_datetime_rsp_t* cmd_mesh_time_server_get_datetime(uint16 elem_index) {
  dump_command_header("mesh_time_server_get_datetime");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_time_server_get_datetime_rsp_t* resp = gecko_cmd_mesh_time_server_get_datetime(elem_index);
  printf("    RETURNED\n");
  dump_mesh_time_server_get_datetime(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_client_init_rsp_t* cmd_mesh_time_client_init(uint16 elem_index) {
  dump_command_header("mesh_time_client_init");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_time_client_init_rsp_t* resp = gecko_cmd_mesh_time_client_init(elem_index);
  printf("    RETURNED\n");
  dump_mesh_time_client_init(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_client_deinit_rsp_t* cmd_mesh_time_client_deinit(uint16 elem_index) {
  dump_command_header("mesh_time_client_deinit");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  struct gecko_msg_mesh_time_client_deinit_rsp_t* resp = gecko_cmd_mesh_time_client_deinit(elem_index);
  printf("    RETURNED\n");
  dump_mesh_time_client_deinit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_client_get_time_rsp_t* cmd_mesh_time_client_get_time(uint16 elem_index,uint16 server_address,uint16 appkey_index) {
  dump_command_header("mesh_time_client_get_time");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_time_client_get_time_rsp_t* resp = gecko_cmd_mesh_time_client_get_time(elem_index,server_address,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_time_client_get_time(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_client_set_time_rsp_t* cmd_mesh_time_client_set_time(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint64 tai_seconds,uint8 subsecond,uint8 uncertainty,uint8 time_authority,int32 tai_utc_delta,int16 time_zone_offset) {
  dump_command_header("mesh_time_client_set_time");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint64 tai_seconds: 0x%08x%08x\n",((int*)&tai_seconds)[1],((int*)&tai_seconds)[0]);
  printf("  uint8 subsecond: 0x%02x\n",(int)subsecond);
  printf("  uint8 uncertainty: 0x%02x\n",(int)uncertainty);
  printf("  uint8 time_authority: 0x%02x\n",(int)time_authority);
  printf("  int32 tai_utc_delta: 0x%04x\n",(int)tai_utc_delta);
  printf("  int16 time_zone_offset: 0x%04x\n",(int)time_zone_offset);
  struct gecko_msg_mesh_time_client_set_time_rsp_t* resp = gecko_cmd_mesh_time_client_set_time(elem_index,server_address,appkey_index,tai_seconds,subsecond,uncertainty,time_authority,tai_utc_delta,time_zone_offset);
  printf("    RETURNED\n");
  dump_mesh_time_client_set_time(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_client_get_time_zone_rsp_t* cmd_mesh_time_client_get_time_zone(uint16 elem_index,uint16 server_address,uint16 appkey_index) {
  dump_command_header("mesh_time_client_get_time_zone");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_time_client_get_time_zone_rsp_t* resp = gecko_cmd_mesh_time_client_get_time_zone(elem_index,server_address,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_time_client_get_time_zone(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_client_set_time_zone_rsp_t* cmd_mesh_time_client_set_time_zone(uint16 elem_index,uint16 server_address,uint16 appkey_index,int16 time_zone_offset_new,uint64 tai_of_zone_change) {
  dump_command_header("mesh_time_client_set_time_zone");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  int16 time_zone_offset_new: 0x%04x\n",(int)time_zone_offset_new);
  printf("  uint64 tai_of_zone_change: 0x%08x%08x\n",((int*)&tai_of_zone_change)[1],((int*)&tai_of_zone_change)[0]);
  struct gecko_msg_mesh_time_client_set_time_zone_rsp_t* resp = gecko_cmd_mesh_time_client_set_time_zone(elem_index,server_address,appkey_index,time_zone_offset_new,tai_of_zone_change);
  printf("    RETURNED\n");
  dump_mesh_time_client_set_time_zone(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_client_get_tai_utc_delta_rsp_t* cmd_mesh_time_client_get_tai_utc_delta(uint16 elem_index,uint16 server_address,uint16 appkey_index) {
  dump_command_header("mesh_time_client_get_tai_utc_delta");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_time_client_get_tai_utc_delta_rsp_t* resp = gecko_cmd_mesh_time_client_get_tai_utc_delta(elem_index,server_address,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_time_client_get_tai_utc_delta(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_client_set_tai_utc_delta_rsp_t* cmd_mesh_time_client_set_tai_utc_delta(uint16 elem_index,uint16 server_address,uint16 appkey_index,int32 tai_utc_delta_new,uint64 tai_of_delta_change) {
  dump_command_header("mesh_time_client_set_tai_utc_delta");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  int32 tai_utc_delta_new: 0x%04x\n",(int)tai_utc_delta_new);
  printf("  uint64 tai_of_delta_change: 0x%08x%08x\n",((int*)&tai_of_delta_change)[1],((int*)&tai_of_delta_change)[0]);
  struct gecko_msg_mesh_time_client_set_tai_utc_delta_rsp_t* resp = gecko_cmd_mesh_time_client_set_tai_utc_delta(elem_index,server_address,appkey_index,tai_utc_delta_new,tai_of_delta_change);
  printf("    RETURNED\n");
  dump_mesh_time_client_set_tai_utc_delta(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_client_get_time_role_rsp_t* cmd_mesh_time_client_get_time_role(uint16 elem_index,uint16 server_address,uint16 appkey_index) {
  dump_command_header("mesh_time_client_get_time_role");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  struct gecko_msg_mesh_time_client_get_time_role_rsp_t* resp = gecko_cmd_mesh_time_client_get_time_role(elem_index,server_address,appkey_index);
  printf("    RETURNED\n");
  dump_mesh_time_client_get_time_role(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_mesh_time_client_set_time_role_rsp_t* cmd_mesh_time_client_set_time_role(uint16 elem_index,uint16 server_address,uint16 appkey_index,uint8 time_role) {
  dump_command_header("mesh_time_client_set_time_role");
  printf("  uint16 elem_index: 0x%04x\n",(int)elem_index);
  printf("  uint16 server_address: 0x%04x\n",(int)server_address);
  printf("  uint16 appkey_index: 0x%04x\n",(int)appkey_index);
  printf("  uint8 time_role: 0x%02x\n",(int)time_role);
  struct gecko_msg_mesh_time_client_set_time_role_rsp_t* resp = gecko_cmd_mesh_time_client_set_time_role(elem_index,server_address,appkey_index,time_role);
  printf("    RETURNED\n");
  dump_mesh_time_client_set_time_role(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_user_message_to_target_rsp_t* cmd_user_message_to_target(uint8 data_len, const uint8* data_data) {
  dump_command_header("user_message_to_target");
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_user_message_to_target_rsp_t* resp = gecko_cmd_user_message_to_target(data_len,data_data);
  printf("    RETURNED\n");
  dump_user_message_to_target(resp);
  dump_footer();
  return resp;
}
#define gecko_cmd_dfu_flash_set_address cmd_dfu_flash_set_address
#define gecko_cmd_dfu_flash_upload cmd_dfu_flash_upload
#define gecko_cmd_dfu_flash_upload_finish cmd_dfu_flash_upload_finish
#define gecko_cmd_system_hello cmd_system_hello
#define gecko_cmd_system_get_bt_address cmd_system_get_bt_address
#define gecko_cmd_system_set_bt_address cmd_system_set_bt_address
#define gecko_cmd_system_set_tx_power cmd_system_set_tx_power
#define gecko_cmd_system_get_random_data cmd_system_get_random_data
#define gecko_cmd_system_halt cmd_system_halt
#define gecko_cmd_system_set_device_name cmd_system_set_device_name
#define gecko_cmd_system_linklayer_configure cmd_system_linklayer_configure
#define gecko_cmd_system_get_counters cmd_system_get_counters
#define gecko_cmd_system_data_buffer_write cmd_system_data_buffer_write
#define gecko_cmd_system_set_identity_address cmd_system_set_identity_address
#define gecko_cmd_system_data_buffer_clear cmd_system_data_buffer_clear
#define gecko_cmd_le_gap_open cmd_le_gap_open
#define gecko_cmd_le_gap_set_mode cmd_le_gap_set_mode
#define gecko_cmd_le_gap_discover cmd_le_gap_discover
#define gecko_cmd_le_gap_end_procedure cmd_le_gap_end_procedure
#define gecko_cmd_le_gap_set_adv_parameters cmd_le_gap_set_adv_parameters
#define gecko_cmd_le_gap_set_conn_parameters cmd_le_gap_set_conn_parameters
#define gecko_cmd_le_gap_set_scan_parameters cmd_le_gap_set_scan_parameters
#define gecko_cmd_le_gap_set_adv_data cmd_le_gap_set_adv_data
#define gecko_cmd_le_gap_set_adv_timeout cmd_le_gap_set_adv_timeout
#define gecko_cmd_le_gap_set_conn_phy cmd_le_gap_set_conn_phy
#define gecko_cmd_le_gap_bt5_set_mode cmd_le_gap_bt5_set_mode
#define gecko_cmd_le_gap_bt5_set_adv_parameters cmd_le_gap_bt5_set_adv_parameters
#define gecko_cmd_le_gap_bt5_set_adv_data cmd_le_gap_bt5_set_adv_data
#define gecko_cmd_le_gap_set_privacy_mode cmd_le_gap_set_privacy_mode
#define gecko_cmd_le_gap_set_advertise_timing cmd_le_gap_set_advertise_timing
#define gecko_cmd_le_gap_set_advertise_channel_map cmd_le_gap_set_advertise_channel_map
#define gecko_cmd_le_gap_set_advertise_report_scan_request cmd_le_gap_set_advertise_report_scan_request
#define gecko_cmd_le_gap_set_advertise_phy cmd_le_gap_set_advertise_phy
#define gecko_cmd_le_gap_set_advertise_configuration cmd_le_gap_set_advertise_configuration
#define gecko_cmd_le_gap_clear_advertise_configuration cmd_le_gap_clear_advertise_configuration
#define gecko_cmd_le_gap_start_advertising cmd_le_gap_start_advertising
#define gecko_cmd_le_gap_stop_advertising cmd_le_gap_stop_advertising
#define gecko_cmd_le_gap_set_discovery_timing cmd_le_gap_set_discovery_timing
#define gecko_cmd_le_gap_set_discovery_type cmd_le_gap_set_discovery_type
#define gecko_cmd_le_gap_start_discovery cmd_le_gap_start_discovery
#define gecko_cmd_le_gap_set_data_channel_classification cmd_le_gap_set_data_channel_classification
#define gecko_cmd_le_gap_connect cmd_le_gap_connect
#define gecko_cmd_le_gap_set_advertise_tx_power cmd_le_gap_set_advertise_tx_power
#define gecko_cmd_le_gap_set_discovery_extended_scan_response cmd_le_gap_set_discovery_extended_scan_response
#define gecko_cmd_le_gap_start_periodic_advertising cmd_le_gap_start_periodic_advertising
#define gecko_cmd_le_gap_stop_periodic_advertising cmd_le_gap_stop_periodic_advertising
#define gecko_cmd_le_gap_set_long_advertising_data cmd_le_gap_set_long_advertising_data
#define gecko_cmd_le_gap_enable_whitelisting cmd_le_gap_enable_whitelisting
#define gecko_cmd_le_gap_set_conn_timing_parameters cmd_le_gap_set_conn_timing_parameters
#define gecko_cmd_le_gap_set_advertise_random_address cmd_le_gap_set_advertise_random_address
#define gecko_cmd_le_gap_clear_advertise_random_address cmd_le_gap_clear_advertise_random_address
#define gecko_cmd_sync_open cmd_sync_open
#define gecko_cmd_sync_close cmd_sync_close
#define gecko_cmd_le_connection_set_parameters cmd_le_connection_set_parameters
#define gecko_cmd_le_connection_get_rssi cmd_le_connection_get_rssi
#define gecko_cmd_le_connection_disable_slave_latency cmd_le_connection_disable_slave_latency
#define gecko_cmd_le_connection_set_phy cmd_le_connection_set_phy
#define gecko_cmd_le_connection_close cmd_le_connection_close
#define gecko_cmd_le_connection_set_timing_parameters cmd_le_connection_set_timing_parameters
#define gecko_cmd_le_connection_read_channel_map cmd_le_connection_read_channel_map
#define gecko_cmd_le_connection_set_preferred_phy cmd_le_connection_set_preferred_phy
#define gecko_cmd_gatt_set_max_mtu cmd_gatt_set_max_mtu
#define gecko_cmd_gatt_discover_primary_services cmd_gatt_discover_primary_services
#define gecko_cmd_gatt_discover_primary_services_by_uuid cmd_gatt_discover_primary_services_by_uuid
#define gecko_cmd_gatt_discover_characteristics cmd_gatt_discover_characteristics
#define gecko_cmd_gatt_discover_characteristics_by_uuid cmd_gatt_discover_characteristics_by_uuid
#define gecko_cmd_gatt_set_characteristic_notification cmd_gatt_set_characteristic_notification
#define gecko_cmd_gatt_discover_descriptors cmd_gatt_discover_descriptors
#define gecko_cmd_gatt_read_characteristic_value cmd_gatt_read_characteristic_value
#define gecko_cmd_gatt_read_characteristic_value_by_uuid cmd_gatt_read_characteristic_value_by_uuid
#define gecko_cmd_gatt_write_characteristic_value cmd_gatt_write_characteristic_value
#define gecko_cmd_gatt_write_characteristic_value_without_response cmd_gatt_write_characteristic_value_without_response
#define gecko_cmd_gatt_prepare_characteristic_value_write cmd_gatt_prepare_characteristic_value_write
#define gecko_cmd_gatt_execute_characteristic_value_write cmd_gatt_execute_characteristic_value_write
#define gecko_cmd_gatt_send_characteristic_confirmation cmd_gatt_send_characteristic_confirmation
#define gecko_cmd_gatt_read_descriptor_value cmd_gatt_read_descriptor_value
#define gecko_cmd_gatt_write_descriptor_value cmd_gatt_write_descriptor_value
#define gecko_cmd_gatt_find_included_services cmd_gatt_find_included_services
#define gecko_cmd_gatt_read_multiple_characteristic_values cmd_gatt_read_multiple_characteristic_values
#define gecko_cmd_gatt_read_characteristic_value_from_offset cmd_gatt_read_characteristic_value_from_offset
#define gecko_cmd_gatt_prepare_characteristic_value_reliable_write cmd_gatt_prepare_characteristic_value_reliable_write
#define gecko_cmd_gatt_server_read_attribute_value cmd_gatt_server_read_attribute_value
#define gecko_cmd_gatt_server_read_attribute_type cmd_gatt_server_read_attribute_type
#define gecko_cmd_gatt_server_write_attribute_value cmd_gatt_server_write_attribute_value
#define gecko_cmd_gatt_server_send_user_read_response cmd_gatt_server_send_user_read_response
#define gecko_cmd_gatt_server_send_user_write_response cmd_gatt_server_send_user_write_response
#define gecko_cmd_gatt_server_send_characteristic_notification cmd_gatt_server_send_characteristic_notification
#define gecko_cmd_gatt_server_find_attribute cmd_gatt_server_find_attribute
#define gecko_cmd_gatt_server_set_capabilities cmd_gatt_server_set_capabilities
#define gecko_cmd_gatt_server_set_max_mtu cmd_gatt_server_set_max_mtu
#define gecko_cmd_gatt_server_get_mtu cmd_gatt_server_get_mtu
#define gecko_cmd_gatt_server_enable_capabilities cmd_gatt_server_enable_capabilities
#define gecko_cmd_gatt_server_disable_capabilities cmd_gatt_server_disable_capabilities
#define gecko_cmd_gatt_server_get_enabled_capabilities cmd_gatt_server_get_enabled_capabilities
#define gecko_cmd_hardware_set_soft_timer cmd_hardware_set_soft_timer
#define gecko_cmd_hardware_get_time cmd_hardware_get_time
#define gecko_cmd_hardware_set_lazy_soft_timer cmd_hardware_set_lazy_soft_timer
#define gecko_cmd_flash_ps_erase_all cmd_flash_ps_erase_all
#define gecko_cmd_flash_ps_save cmd_flash_ps_save
#define gecko_cmd_flash_ps_load cmd_flash_ps_load
#define gecko_cmd_flash_ps_erase cmd_flash_ps_erase
#define gecko_cmd_test_dtm_tx cmd_test_dtm_tx
#define gecko_cmd_test_dtm_rx cmd_test_dtm_rx
#define gecko_cmd_test_dtm_end cmd_test_dtm_end
#define gecko_cmd_sm_set_bondable_mode cmd_sm_set_bondable_mode
#define gecko_cmd_sm_configure cmd_sm_configure
#define gecko_cmd_sm_store_bonding_configuration cmd_sm_store_bonding_configuration
#define gecko_cmd_sm_increase_security cmd_sm_increase_security
#define gecko_cmd_sm_delete_bonding cmd_sm_delete_bonding
#define gecko_cmd_sm_delete_bondings cmd_sm_delete_bondings
#define gecko_cmd_sm_enter_passkey cmd_sm_enter_passkey
#define gecko_cmd_sm_passkey_confirm cmd_sm_passkey_confirm
#define gecko_cmd_sm_set_oob_data cmd_sm_set_oob_data
#define gecko_cmd_sm_list_all_bondings cmd_sm_list_all_bondings
#define gecko_cmd_sm_bonding_confirm cmd_sm_bonding_confirm
#define gecko_cmd_sm_set_debug_mode cmd_sm_set_debug_mode
#define gecko_cmd_sm_set_passkey cmd_sm_set_passkey
#define gecko_cmd_sm_use_sc_oob cmd_sm_use_sc_oob
#define gecko_cmd_sm_set_sc_remote_oob_data cmd_sm_set_sc_remote_oob_data
#define gecko_cmd_sm_add_to_whitelist cmd_sm_add_to_whitelist
#define gecko_cmd_sm_set_minimum_key_size cmd_sm_set_minimum_key_size
#define gecko_cmd_homekit_configure cmd_homekit_configure
#define gecko_cmd_homekit_advertise cmd_homekit_advertise
#define gecko_cmd_homekit_delete_pairings cmd_homekit_delete_pairings
#define gecko_cmd_homekit_check_authcp cmd_homekit_check_authcp
#define gecko_cmd_homekit_get_pairing_id cmd_homekit_get_pairing_id
#define gecko_cmd_homekit_send_write_response cmd_homekit_send_write_response
#define gecko_cmd_homekit_send_read_response cmd_homekit_send_read_response
#define gecko_cmd_homekit_gsn_action cmd_homekit_gsn_action
#define gecko_cmd_homekit_event_notification cmd_homekit_event_notification
#define gecko_cmd_homekit_broadcast_action cmd_homekit_broadcast_action
#define gecko_cmd_homekit_configure_product_data cmd_homekit_configure_product_data
#define gecko_cmd_mesh_node_init cmd_mesh_node_init
#define gecko_cmd_mesh_node_start_unprov_beaconing cmd_mesh_node_start_unprov_beaconing
#define gecko_cmd_mesh_node_stop_unprov_beaconing cmd_mesh_node_stop_unprov_beaconing
#define gecko_cmd_mesh_node_rssi cmd_mesh_node_rssi
#define gecko_cmd_mesh_node_input_oob_request_rsp cmd_mesh_node_input_oob_request_rsp
#define gecko_cmd_mesh_node_get_uuid cmd_mesh_node_get_uuid
#define gecko_cmd_mesh_node_set_provisioning_data cmd_mesh_node_set_provisioning_data
#define gecko_cmd_mesh_node_init_oob cmd_mesh_node_init_oob
#define gecko_cmd_mesh_node_set_ivrecovery_mode cmd_mesh_node_set_ivrecovery_mode
#define gecko_cmd_mesh_node_get_ivrecovery_mode cmd_mesh_node_get_ivrecovery_mode
#define gecko_cmd_mesh_node_set_adv_event_filter cmd_mesh_node_set_adv_event_filter
#define gecko_cmd_mesh_node_get_statistics cmd_mesh_node_get_statistics
#define gecko_cmd_mesh_node_clear_statistics cmd_mesh_node_clear_statistics
#define gecko_cmd_mesh_node_set_net_relay_delay cmd_mesh_node_set_net_relay_delay
#define gecko_cmd_mesh_node_get_net_relay_delay cmd_mesh_node_get_net_relay_delay
#define gecko_cmd_mesh_node_get_ivupdate_state cmd_mesh_node_get_ivupdate_state
#define gecko_cmd_mesh_node_request_ivupdate cmd_mesh_node_request_ivupdate
#define gecko_cmd_mesh_node_get_seq_remaining cmd_mesh_node_get_seq_remaining
#define gecko_cmd_mesh_node_save_replay_protection_list cmd_mesh_node_save_replay_protection_list
#define gecko_cmd_mesh_node_set_uuid cmd_mesh_node_set_uuid
#define gecko_cmd_mesh_node_get_element_address cmd_mesh_node_get_element_address
#define gecko_cmd_mesh_node_static_oob_request_rsp cmd_mesh_node_static_oob_request_rsp
#define gecko_cmd_mesh_node_reset cmd_mesh_node_reset
#define gecko_cmd_mesh_node_set_beacon_reporting cmd_mesh_node_set_beacon_reporting
#define gecko_cmd_mesh_prov_init cmd_mesh_prov_init
#define gecko_cmd_mesh_prov_scan_unprov_beacons cmd_mesh_prov_scan_unprov_beacons
#define gecko_cmd_mesh_prov_provision_device cmd_mesh_prov_provision_device
#define gecko_cmd_mesh_prov_create_network cmd_mesh_prov_create_network
#define gecko_cmd_mesh_prov_get_dcd cmd_mesh_prov_get_dcd
#define gecko_cmd_mesh_prov_get_config cmd_mesh_prov_get_config
#define gecko_cmd_mesh_prov_set_config cmd_mesh_prov_set_config
#define gecko_cmd_mesh_prov_create_appkey cmd_mesh_prov_create_appkey
#define gecko_cmd_mesh_prov_oob_pkey_rsp cmd_mesh_prov_oob_pkey_rsp
#define gecko_cmd_mesh_prov_oob_auth_rsp cmd_mesh_prov_oob_auth_rsp
#define gecko_cmd_mesh_prov_set_oob_requirements cmd_mesh_prov_set_oob_requirements
#define gecko_cmd_mesh_prov_key_refresh_start cmd_mesh_prov_key_refresh_start
#define gecko_cmd_mesh_prov_get_key_refresh_blacklist cmd_mesh_prov_get_key_refresh_blacklist
#define gecko_cmd_mesh_prov_set_key_refresh_blacklist cmd_mesh_prov_set_key_refresh_blacklist
#define gecko_cmd_mesh_prov_appkey_add cmd_mesh_prov_appkey_add
#define gecko_cmd_mesh_prov_appkey_delete cmd_mesh_prov_appkey_delete
#define gecko_cmd_mesh_prov_model_app_bind cmd_mesh_prov_model_app_bind
#define gecko_cmd_mesh_prov_model_app_unbind cmd_mesh_prov_model_app_unbind
#define gecko_cmd_mesh_prov_model_app_get cmd_mesh_prov_model_app_get
#define gecko_cmd_mesh_prov_model_sub_add cmd_mesh_prov_model_sub_add
#define gecko_cmd_mesh_prov_model_pub_set cmd_mesh_prov_model_pub_set
#define gecko_cmd_mesh_prov_provision_gatt_device cmd_mesh_prov_provision_gatt_device
#define gecko_cmd_mesh_prov_ddb_get cmd_mesh_prov_ddb_get
#define gecko_cmd_mesh_prov_ddb_delete cmd_mesh_prov_ddb_delete
#define gecko_cmd_mesh_prov_ddb_add cmd_mesh_prov_ddb_add
#define gecko_cmd_mesh_prov_ddb_list_devices cmd_mesh_prov_ddb_list_devices
#define gecko_cmd_mesh_prov_network_add cmd_mesh_prov_network_add
#define gecko_cmd_mesh_prov_network_delete cmd_mesh_prov_network_delete
#define gecko_cmd_mesh_prov_nettx_get cmd_mesh_prov_nettx_get
#define gecko_cmd_mesh_prov_nettx_set cmd_mesh_prov_nettx_set
#define gecko_cmd_mesh_prov_model_sub_del cmd_mesh_prov_model_sub_del
#define gecko_cmd_mesh_prov_model_sub_add_va cmd_mesh_prov_model_sub_add_va
#define gecko_cmd_mesh_prov_model_sub_del_va cmd_mesh_prov_model_sub_del_va
#define gecko_cmd_mesh_prov_model_sub_set cmd_mesh_prov_model_sub_set
#define gecko_cmd_mesh_prov_model_sub_set_va cmd_mesh_prov_model_sub_set_va
#define gecko_cmd_mesh_prov_heartbeat_publication_get cmd_mesh_prov_heartbeat_publication_get
#define gecko_cmd_mesh_prov_heartbeat_publication_set cmd_mesh_prov_heartbeat_publication_set
#define gecko_cmd_mesh_prov_heartbeat_subscription_get cmd_mesh_prov_heartbeat_subscription_get
#define gecko_cmd_mesh_prov_heartbeat_subscription_set cmd_mesh_prov_heartbeat_subscription_set
#define gecko_cmd_mesh_prov_relay_get cmd_mesh_prov_relay_get
#define gecko_cmd_mesh_prov_relay_set cmd_mesh_prov_relay_set
#define gecko_cmd_mesh_prov_reset_node cmd_mesh_prov_reset_node
#define gecko_cmd_mesh_prov_appkey_get cmd_mesh_prov_appkey_get
#define gecko_cmd_mesh_prov_network_get cmd_mesh_prov_network_get
#define gecko_cmd_mesh_prov_model_sub_clear cmd_mesh_prov_model_sub_clear
#define gecko_cmd_mesh_prov_model_pub_get cmd_mesh_prov_model_pub_get
#define gecko_cmd_mesh_prov_model_pub_set_va cmd_mesh_prov_model_pub_set_va
#define gecko_cmd_mesh_prov_model_pub_set_cred cmd_mesh_prov_model_pub_set_cred
#define gecko_cmd_mesh_prov_model_pub_set_va_cred cmd_mesh_prov_model_pub_set_va_cred
#define gecko_cmd_mesh_prov_model_sub_get cmd_mesh_prov_model_sub_get
#define gecko_cmd_mesh_prov_friend_timeout_get cmd_mesh_prov_friend_timeout_get
#define gecko_cmd_mesh_prov_get_default_configuration_timeout cmd_mesh_prov_get_default_configuration_timeout
#define gecko_cmd_mesh_prov_set_default_configuration_timeout cmd_mesh_prov_set_default_configuration_timeout
#define gecko_cmd_mesh_prov_provision_device_with_address cmd_mesh_prov_provision_device_with_address
#define gecko_cmd_mesh_prov_provision_gatt_device_with_address cmd_mesh_prov_provision_gatt_device_with_address
#define gecko_cmd_mesh_prov_initialize_network cmd_mesh_prov_initialize_network
#define gecko_cmd_mesh_prov_get_key_refresh_appkey_blacklist cmd_mesh_prov_get_key_refresh_appkey_blacklist
#define gecko_cmd_mesh_prov_set_key_refresh_appkey_blacklist cmd_mesh_prov_set_key_refresh_appkey_blacklist
#define gecko_cmd_mesh_prov_stop_scan_unprov_beacons cmd_mesh_prov_stop_scan_unprov_beacons
#define gecko_cmd_mesh_prov_ddb_update_netkey_index cmd_mesh_prov_ddb_update_netkey_index
#define gecko_cmd_mesh_prov_key_refresh_suspend cmd_mesh_prov_key_refresh_suspend
#define gecko_cmd_mesh_prov_key_refresh_resume cmd_mesh_prov_key_refresh_resume
#define gecko_cmd_mesh_prov_get_key_refresh_phase cmd_mesh_prov_get_key_refresh_phase
#define gecko_cmd_mesh_prov_key_refresh_start_from_phase cmd_mesh_prov_key_refresh_start_from_phase
#define gecko_cmd_mesh_prov_flush_key_refresh_state cmd_mesh_prov_flush_key_refresh_state
#define gecko_cmd_mesh_proxy_connect cmd_mesh_proxy_connect
#define gecko_cmd_mesh_proxy_disconnect cmd_mesh_proxy_disconnect
#define gecko_cmd_mesh_proxy_set_filter_type cmd_mesh_proxy_set_filter_type
#define gecko_cmd_mesh_proxy_allow cmd_mesh_proxy_allow
#define gecko_cmd_mesh_proxy_deny cmd_mesh_proxy_deny
#define gecko_cmd_mesh_vendor_model_send cmd_mesh_vendor_model_send
#define gecko_cmd_mesh_vendor_model_set_publication cmd_mesh_vendor_model_set_publication
#define gecko_cmd_mesh_vendor_model_clear_publication cmd_mesh_vendor_model_clear_publication
#define gecko_cmd_mesh_vendor_model_publish cmd_mesh_vendor_model_publish
#define gecko_cmd_mesh_vendor_model_init cmd_mesh_vendor_model_init
#define gecko_cmd_mesh_vendor_model_deinit cmd_mesh_vendor_model_deinit
#define gecko_cmd_mesh_health_client_get cmd_mesh_health_client_get
#define gecko_cmd_mesh_health_client_clear cmd_mesh_health_client_clear
#define gecko_cmd_mesh_health_client_test cmd_mesh_health_client_test
#define gecko_cmd_mesh_health_client_get_period cmd_mesh_health_client_get_period
#define gecko_cmd_mesh_health_client_set_period cmd_mesh_health_client_set_period
#define gecko_cmd_mesh_health_client_get_attention cmd_mesh_health_client_get_attention
#define gecko_cmd_mesh_health_client_set_attention cmd_mesh_health_client_set_attention
#define gecko_cmd_mesh_health_server_set_fault cmd_mesh_health_server_set_fault
#define gecko_cmd_mesh_health_server_clear_fault cmd_mesh_health_server_clear_fault
#define gecko_cmd_mesh_health_server_test_response cmd_mesh_health_server_test_response
#define gecko_cmd_mesh_generic_client_get cmd_mesh_generic_client_get
#define gecko_cmd_mesh_generic_client_set cmd_mesh_generic_client_set
#define gecko_cmd_mesh_generic_client_publish cmd_mesh_generic_client_publish
#define gecko_cmd_mesh_generic_client_get_params cmd_mesh_generic_client_get_params
#define gecko_cmd_mesh_generic_client_init cmd_mesh_generic_client_init
#define gecko_cmd_mesh_generic_client_init_common cmd_mesh_generic_client_init_common
#define gecko_cmd_mesh_generic_client_init_on_off cmd_mesh_generic_client_init_on_off
#define gecko_cmd_mesh_generic_client_init_level cmd_mesh_generic_client_init_level
#define gecko_cmd_mesh_generic_client_init_default_transition_time cmd_mesh_generic_client_init_default_transition_time
#define gecko_cmd_mesh_generic_client_init_power_on_off cmd_mesh_generic_client_init_power_on_off
#define gecko_cmd_mesh_generic_client_init_power_level cmd_mesh_generic_client_init_power_level
#define gecko_cmd_mesh_generic_client_init_battery cmd_mesh_generic_client_init_battery
#define gecko_cmd_mesh_generic_client_init_location cmd_mesh_generic_client_init_location
#define gecko_cmd_mesh_generic_client_init_property cmd_mesh_generic_client_init_property
#define gecko_cmd_mesh_generic_client_init_lightness cmd_mesh_generic_client_init_lightness
#define gecko_cmd_mesh_generic_client_init_ctl cmd_mesh_generic_client_init_ctl
#define gecko_cmd_mesh_generic_server_response cmd_mesh_generic_server_response
#define gecko_cmd_mesh_generic_server_update cmd_mesh_generic_server_update
#define gecko_cmd_mesh_generic_server_publish cmd_mesh_generic_server_publish
#define gecko_cmd_mesh_generic_server_init cmd_mesh_generic_server_init
#define gecko_cmd_mesh_generic_server_init_common cmd_mesh_generic_server_init_common
#define gecko_cmd_mesh_generic_server_init_on_off cmd_mesh_generic_server_init_on_off
#define gecko_cmd_mesh_generic_server_init_level cmd_mesh_generic_server_init_level
#define gecko_cmd_mesh_generic_server_init_default_transition_time cmd_mesh_generic_server_init_default_transition_time
#define gecko_cmd_mesh_generic_server_init_power_on_off cmd_mesh_generic_server_init_power_on_off
#define gecko_cmd_mesh_generic_server_init_power_level cmd_mesh_generic_server_init_power_level
#define gecko_cmd_mesh_generic_server_init_battery cmd_mesh_generic_server_init_battery
#define gecko_cmd_mesh_generic_server_init_location cmd_mesh_generic_server_init_location
#define gecko_cmd_mesh_generic_server_init_property cmd_mesh_generic_server_init_property
#define gecko_cmd_mesh_generic_server_init_lightness cmd_mesh_generic_server_init_lightness
#define gecko_cmd_mesh_generic_server_init_ctl cmd_mesh_generic_server_init_ctl
#define gecko_cmd_coex_set_options cmd_coex_set_options
#define gecko_cmd_coex_get_counters cmd_coex_get_counters
#define gecko_cmd_coex_set_parameters cmd_coex_set_parameters
#define gecko_cmd_coex_set_directional_priority_pulse cmd_coex_set_directional_priority_pulse
#define gecko_cmd_mesh_test_get_nettx cmd_mesh_test_get_nettx
#define gecko_cmd_mesh_test_set_nettx cmd_mesh_test_set_nettx
#define gecko_cmd_mesh_test_get_relay cmd_mesh_test_get_relay
#define gecko_cmd_mesh_test_set_relay cmd_mesh_test_set_relay
#define gecko_cmd_mesh_test_set_adv_scan_params cmd_mesh_test_set_adv_scan_params
#define gecko_cmd_mesh_test_set_ivupdate_test_mode cmd_mesh_test_set_ivupdate_test_mode
#define gecko_cmd_mesh_test_get_ivupdate_test_mode cmd_mesh_test_get_ivupdate_test_mode
#define gecko_cmd_mesh_test_set_segment_send_delay cmd_mesh_test_set_segment_send_delay
#define gecko_cmd_mesh_test_set_ivupdate_state cmd_mesh_test_set_ivupdate_state
#define gecko_cmd_mesh_test_send_beacons cmd_mesh_test_send_beacons
#define gecko_cmd_mesh_test_bind_local_model_app cmd_mesh_test_bind_local_model_app
#define gecko_cmd_mesh_test_unbind_local_model_app cmd_mesh_test_unbind_local_model_app
#define gecko_cmd_mesh_test_add_local_model_sub cmd_mesh_test_add_local_model_sub
#define gecko_cmd_mesh_test_del_local_model_sub cmd_mesh_test_del_local_model_sub
#define gecko_cmd_mesh_test_add_local_model_sub_va cmd_mesh_test_add_local_model_sub_va
#define gecko_cmd_mesh_test_del_local_model_sub_va cmd_mesh_test_del_local_model_sub_va
#define gecko_cmd_mesh_test_get_local_model_sub cmd_mesh_test_get_local_model_sub
#define gecko_cmd_mesh_test_set_local_model_pub cmd_mesh_test_set_local_model_pub
#define gecko_cmd_mesh_test_set_local_model_pub_va cmd_mesh_test_set_local_model_pub_va
#define gecko_cmd_mesh_test_get_local_model_pub cmd_mesh_test_get_local_model_pub
#define gecko_cmd_mesh_test_set_local_heartbeat_subscription cmd_mesh_test_set_local_heartbeat_subscription
#define gecko_cmd_mesh_test_get_local_heartbeat_subscription cmd_mesh_test_get_local_heartbeat_subscription
#define gecko_cmd_mesh_test_get_local_heartbeat_publication cmd_mesh_test_get_local_heartbeat_publication
#define gecko_cmd_mesh_test_set_local_heartbeat_publication cmd_mesh_test_set_local_heartbeat_publication
#define gecko_cmd_mesh_test_set_local_config cmd_mesh_test_set_local_config
#define gecko_cmd_mesh_test_get_local_config cmd_mesh_test_get_local_config
#define gecko_cmd_mesh_test_add_local_key cmd_mesh_test_add_local_key
#define gecko_cmd_mesh_test_del_local_key cmd_mesh_test_del_local_key
#define gecko_cmd_mesh_test_update_local_key cmd_mesh_test_update_local_key
#define gecko_cmd_mesh_test_set_sar_config cmd_mesh_test_set_sar_config
#define gecko_cmd_mesh_test_get_element_seqnum cmd_mesh_test_get_element_seqnum
#define gecko_cmd_mesh_test_set_adv_bearer_state cmd_mesh_test_set_adv_bearer_state
#define gecko_cmd_mesh_test_get_key_count cmd_mesh_test_get_key_count
#define gecko_cmd_mesh_test_get_key cmd_mesh_test_get_key
#define gecko_cmd_mesh_test_prov_get_device_key cmd_mesh_test_prov_get_device_key
#define gecko_cmd_mesh_test_prov_prepare_key_refresh cmd_mesh_test_prov_prepare_key_refresh
#define gecko_cmd_mesh_test_cancel_segmented_tx cmd_mesh_test_cancel_segmented_tx
#define gecko_cmd_mesh_test_set_iv_index cmd_mesh_test_set_iv_index
#define gecko_cmd_mesh_test_set_element_seqnum cmd_mesh_test_set_element_seqnum
#define gecko_cmd_mesh_test_set_model_option cmd_mesh_test_set_model_option
#define gecko_cmd_mesh_test_get_local_model_app_bindings cmd_mesh_test_get_local_model_app_bindings
#define gecko_cmd_mesh_lpn_init cmd_mesh_lpn_init
#define gecko_cmd_mesh_lpn_deinit cmd_mesh_lpn_deinit
#define gecko_cmd_mesh_lpn_configure cmd_mesh_lpn_configure
#define gecko_cmd_mesh_lpn_establish_friendship cmd_mesh_lpn_establish_friendship
#define gecko_cmd_mesh_lpn_poll cmd_mesh_lpn_poll
#define gecko_cmd_mesh_lpn_terminate_friendship cmd_mesh_lpn_terminate_friendship
#define gecko_cmd_mesh_lpn_config cmd_mesh_lpn_config
#define gecko_cmd_mesh_friend_init cmd_mesh_friend_init
#define gecko_cmd_mesh_friend_deinit cmd_mesh_friend_deinit
#define gecko_cmd_mesh_config_client_cancel_request cmd_mesh_config_client_cancel_request
#define gecko_cmd_mesh_config_client_get_request_status cmd_mesh_config_client_get_request_status
#define gecko_cmd_mesh_config_client_get_default_timeout cmd_mesh_config_client_get_default_timeout
#define gecko_cmd_mesh_config_client_set_default_timeout cmd_mesh_config_client_set_default_timeout
#define gecko_cmd_mesh_config_client_add_netkey cmd_mesh_config_client_add_netkey
#define gecko_cmd_mesh_config_client_remove_netkey cmd_mesh_config_client_remove_netkey
#define gecko_cmd_mesh_config_client_list_netkeys cmd_mesh_config_client_list_netkeys
#define gecko_cmd_mesh_config_client_add_appkey cmd_mesh_config_client_add_appkey
#define gecko_cmd_mesh_config_client_remove_appkey cmd_mesh_config_client_remove_appkey
#define gecko_cmd_mesh_config_client_list_appkeys cmd_mesh_config_client_list_appkeys
#define gecko_cmd_mesh_config_client_bind_model cmd_mesh_config_client_bind_model
#define gecko_cmd_mesh_config_client_unbind_model cmd_mesh_config_client_unbind_model
#define gecko_cmd_mesh_config_client_list_bindings cmd_mesh_config_client_list_bindings
#define gecko_cmd_mesh_config_client_get_model_pub cmd_mesh_config_client_get_model_pub
#define gecko_cmd_mesh_config_client_set_model_pub cmd_mesh_config_client_set_model_pub
#define gecko_cmd_mesh_config_client_set_model_pub_va cmd_mesh_config_client_set_model_pub_va
#define gecko_cmd_mesh_config_client_add_model_sub cmd_mesh_config_client_add_model_sub
#define gecko_cmd_mesh_config_client_add_model_sub_va cmd_mesh_config_client_add_model_sub_va
#define gecko_cmd_mesh_config_client_remove_model_sub cmd_mesh_config_client_remove_model_sub
#define gecko_cmd_mesh_config_client_remove_model_sub_va cmd_mesh_config_client_remove_model_sub_va
#define gecko_cmd_mesh_config_client_set_model_sub cmd_mesh_config_client_set_model_sub
#define gecko_cmd_mesh_config_client_set_model_sub_va cmd_mesh_config_client_set_model_sub_va
#define gecko_cmd_mesh_config_client_clear_model_sub cmd_mesh_config_client_clear_model_sub
#define gecko_cmd_mesh_config_client_list_subs cmd_mesh_config_client_list_subs
#define gecko_cmd_mesh_config_client_get_heartbeat_pub cmd_mesh_config_client_get_heartbeat_pub
#define gecko_cmd_mesh_config_client_set_heartbeat_pub cmd_mesh_config_client_set_heartbeat_pub
#define gecko_cmd_mesh_config_client_get_heartbeat_sub cmd_mesh_config_client_get_heartbeat_sub
#define gecko_cmd_mesh_config_client_set_heartbeat_sub cmd_mesh_config_client_set_heartbeat_sub
#define gecko_cmd_mesh_config_client_get_beacon cmd_mesh_config_client_get_beacon
#define gecko_cmd_mesh_config_client_set_beacon cmd_mesh_config_client_set_beacon
#define gecko_cmd_mesh_config_client_get_default_ttl cmd_mesh_config_client_get_default_ttl
#define gecko_cmd_mesh_config_client_set_default_ttl cmd_mesh_config_client_set_default_ttl
#define gecko_cmd_mesh_config_client_get_gatt_proxy cmd_mesh_config_client_get_gatt_proxy
#define gecko_cmd_mesh_config_client_set_gatt_proxy cmd_mesh_config_client_set_gatt_proxy
#define gecko_cmd_mesh_config_client_get_relay cmd_mesh_config_client_get_relay
#define gecko_cmd_mesh_config_client_set_relay cmd_mesh_config_client_set_relay
#define gecko_cmd_mesh_config_client_get_network_transmit cmd_mesh_config_client_get_network_transmit
#define gecko_cmd_mesh_config_client_set_network_transmit cmd_mesh_config_client_set_network_transmit
#define gecko_cmd_mesh_config_client_get_identity cmd_mesh_config_client_get_identity
#define gecko_cmd_mesh_config_client_set_identity cmd_mesh_config_client_set_identity
#define gecko_cmd_mesh_config_client_get_friend cmd_mesh_config_client_get_friend
#define gecko_cmd_mesh_config_client_set_friend cmd_mesh_config_client_set_friend
#define gecko_cmd_mesh_config_client_get_lpn_polltimeout cmd_mesh_config_client_get_lpn_polltimeout
#define gecko_cmd_mesh_config_client_get_dcd cmd_mesh_config_client_get_dcd
#define gecko_cmd_mesh_config_client_reset_node cmd_mesh_config_client_reset_node
#define gecko_cmd_l2cap_coc_send_connection_request cmd_l2cap_coc_send_connection_request
#define gecko_cmd_l2cap_coc_send_connection_response cmd_l2cap_coc_send_connection_response
#define gecko_cmd_l2cap_coc_send_le_flow_control_credit cmd_l2cap_coc_send_le_flow_control_credit
#define gecko_cmd_l2cap_coc_send_disconnection_request cmd_l2cap_coc_send_disconnection_request
#define gecko_cmd_l2cap_coc_send_data cmd_l2cap_coc_send_data
#define gecko_cmd_cte_transmitter_enable_cte_response cmd_cte_transmitter_enable_cte_response
#define gecko_cmd_cte_transmitter_disable_cte_response cmd_cte_transmitter_disable_cte_response
#define gecko_cmd_cte_transmitter_start_connectionless_cte cmd_cte_transmitter_start_connectionless_cte
#define gecko_cmd_cte_transmitter_stop_connectionless_cte cmd_cte_transmitter_stop_connectionless_cte
#define gecko_cmd_cte_transmitter_set_dtm_parameters cmd_cte_transmitter_set_dtm_parameters
#define gecko_cmd_cte_transmitter_clear_dtm_parameters cmd_cte_transmitter_clear_dtm_parameters
#define gecko_cmd_cte_receiver_configure cmd_cte_receiver_configure
#define gecko_cmd_cte_receiver_start_iq_sampling cmd_cte_receiver_start_iq_sampling
#define gecko_cmd_cte_receiver_stop_iq_sampling cmd_cte_receiver_stop_iq_sampling
#define gecko_cmd_cte_receiver_start_connectionless_iq_sampling cmd_cte_receiver_start_connectionless_iq_sampling
#define gecko_cmd_cte_receiver_stop_connectionless_iq_sampling cmd_cte_receiver_stop_connectionless_iq_sampling
#define gecko_cmd_cte_receiver_set_dtm_parameters cmd_cte_receiver_set_dtm_parameters
#define gecko_cmd_cte_receiver_clear_dtm_parameters cmd_cte_receiver_clear_dtm_parameters
#define gecko_cmd_mesh_sensor_server_init cmd_mesh_sensor_server_init
#define gecko_cmd_mesh_sensor_server_deinit cmd_mesh_sensor_server_deinit
#define gecko_cmd_mesh_sensor_server_send_descriptor_status cmd_mesh_sensor_server_send_descriptor_status
#define gecko_cmd_mesh_sensor_server_send_status cmd_mesh_sensor_server_send_status
#define gecko_cmd_mesh_sensor_server_send_column_status cmd_mesh_sensor_server_send_column_status
#define gecko_cmd_mesh_sensor_server_send_series_status cmd_mesh_sensor_server_send_series_status
#define gecko_cmd_mesh_sensor_setup_server_send_cadence_status cmd_mesh_sensor_setup_server_send_cadence_status
#define gecko_cmd_mesh_sensor_setup_server_send_settings_status cmd_mesh_sensor_setup_server_send_settings_status
#define gecko_cmd_mesh_sensor_setup_server_send_setting_status cmd_mesh_sensor_setup_server_send_setting_status
#define gecko_cmd_mesh_sensor_client_init cmd_mesh_sensor_client_init
#define gecko_cmd_mesh_sensor_client_deinit cmd_mesh_sensor_client_deinit
#define gecko_cmd_mesh_sensor_client_get_descriptor cmd_mesh_sensor_client_get_descriptor
#define gecko_cmd_mesh_sensor_client_get cmd_mesh_sensor_client_get
#define gecko_cmd_mesh_sensor_client_get_column cmd_mesh_sensor_client_get_column
#define gecko_cmd_mesh_sensor_client_get_series cmd_mesh_sensor_client_get_series
#define gecko_cmd_mesh_sensor_client_get_cadence cmd_mesh_sensor_client_get_cadence
#define gecko_cmd_mesh_sensor_client_set_cadence cmd_mesh_sensor_client_set_cadence
#define gecko_cmd_mesh_sensor_client_get_settings cmd_mesh_sensor_client_get_settings
#define gecko_cmd_mesh_sensor_client_get_setting cmd_mesh_sensor_client_get_setting
#define gecko_cmd_mesh_sensor_client_set_setting cmd_mesh_sensor_client_set_setting
#define gecko_cmd_mesh_lc_client_init cmd_mesh_lc_client_init
#define gecko_cmd_mesh_lc_client_get_mode cmd_mesh_lc_client_get_mode
#define gecko_cmd_mesh_lc_client_set_mode cmd_mesh_lc_client_set_mode
#define gecko_cmd_mesh_lc_client_get_om cmd_mesh_lc_client_get_om
#define gecko_cmd_mesh_lc_client_set_om cmd_mesh_lc_client_set_om
#define gecko_cmd_mesh_lc_client_get_light_onoff cmd_mesh_lc_client_get_light_onoff
#define gecko_cmd_mesh_lc_client_set_light_onoff cmd_mesh_lc_client_set_light_onoff
#define gecko_cmd_mesh_lc_client_get_property cmd_mesh_lc_client_get_property
#define gecko_cmd_mesh_lc_client_set_property cmd_mesh_lc_client_set_property
#define gecko_cmd_mesh_lc_server_init cmd_mesh_lc_server_init
#define gecko_cmd_mesh_lc_server_deinit cmd_mesh_lc_server_deinit
#define gecko_cmd_mesh_lc_server_update_mode cmd_mesh_lc_server_update_mode
#define gecko_cmd_mesh_lc_server_update_om cmd_mesh_lc_server_update_om
#define gecko_cmd_mesh_lc_server_update_light_onoff cmd_mesh_lc_server_update_light_onoff
#define gecko_cmd_mesh_lc_server_init_all_properties cmd_mesh_lc_server_init_all_properties
#define gecko_cmd_mesh_lc_server_set_publish_mask cmd_mesh_lc_server_set_publish_mask
#define gecko_cmd_mesh_lc_server_set_regulator_interval cmd_mesh_lc_server_set_regulator_interval
#define gecko_cmd_mesh_lc_server_set_event_mask cmd_mesh_lc_server_set_event_mask
#define gecko_cmd_mesh_lc_server_get_lc_state cmd_mesh_lc_server_get_lc_state
#define gecko_cmd_mesh_lc_setup_server_update_property cmd_mesh_lc_setup_server_update_property
#define gecko_cmd_mesh_scene_client_init cmd_mesh_scene_client_init
#define gecko_cmd_mesh_scene_client_get cmd_mesh_scene_client_get
#define gecko_cmd_mesh_scene_client_get_register cmd_mesh_scene_client_get_register
#define gecko_cmd_mesh_scene_client_recall cmd_mesh_scene_client_recall
#define gecko_cmd_mesh_scene_client_store cmd_mesh_scene_client_store
#define gecko_cmd_mesh_scene_client_delete cmd_mesh_scene_client_delete
#define gecko_cmd_mesh_scene_server_init cmd_mesh_scene_server_init
#define gecko_cmd_mesh_scene_server_deinit cmd_mesh_scene_server_deinit
#define gecko_cmd_mesh_scene_setup_server_init cmd_mesh_scene_setup_server_init
#define gecko_cmd_mesh_time_server_init cmd_mesh_time_server_init
#define gecko_cmd_mesh_time_server_deinit cmd_mesh_time_server_deinit
#define gecko_cmd_mesh_time_server_get_time cmd_mesh_time_server_get_time
#define gecko_cmd_mesh_time_server_set_time cmd_mesh_time_server_set_time
#define gecko_cmd_mesh_time_server_get_time_zone_offset_new cmd_mesh_time_server_get_time_zone_offset_new
#define gecko_cmd_mesh_time_server_set_time_zone_offset_new cmd_mesh_time_server_set_time_zone_offset_new
#define gecko_cmd_mesh_time_server_get_tai_utc_delta_new cmd_mesh_time_server_get_tai_utc_delta_new
#define gecko_cmd_mesh_time_server_set_tai_utc_delta_new cmd_mesh_time_server_set_tai_utc_delta_new
#define gecko_cmd_mesh_time_server_get_time_role cmd_mesh_time_server_get_time_role
#define gecko_cmd_mesh_time_server_set_time_role cmd_mesh_time_server_set_time_role
#define gecko_cmd_mesh_time_server_get_datetime cmd_mesh_time_server_get_datetime
#define gecko_cmd_mesh_time_client_init cmd_mesh_time_client_init
#define gecko_cmd_mesh_time_client_deinit cmd_mesh_time_client_deinit
#define gecko_cmd_mesh_time_client_get_time cmd_mesh_time_client_get_time
#define gecko_cmd_mesh_time_client_set_time cmd_mesh_time_client_set_time
#define gecko_cmd_mesh_time_client_get_time_zone cmd_mesh_time_client_get_time_zone
#define gecko_cmd_mesh_time_client_set_time_zone cmd_mesh_time_client_set_time_zone
#define gecko_cmd_mesh_time_client_get_tai_utc_delta cmd_mesh_time_client_get_tai_utc_delta
#define gecko_cmd_mesh_time_client_set_tai_utc_delta cmd_mesh_time_client_set_tai_utc_delta
#define gecko_cmd_mesh_time_client_get_time_role cmd_mesh_time_client_get_time_role
#define gecko_cmd_mesh_time_client_set_time_role cmd_mesh_time_client_set_time_role
#define gecko_cmd_user_message_to_target cmd_user_message_to_target

#endif
