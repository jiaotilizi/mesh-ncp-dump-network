/* BG stack headers */
#include "bg_types.h"
#include "gecko_bglib.h"
#include <stdio.h>
int dump_mode = 0;
void dump_timestamp(int onoff) {
  if(onoff) dump_mode |= 1; else dump_mode &= ~1u;
}
#undef gecko_cmd_hardware_get_time
void dump_event_header(const char*str) {
  printf("\n\033[36m");
  printf("EVENT %s\n",str);
}
void dump_command_header(const char*str) {
  printf("\n\033[31m");
  printf("COMMAND %s\n",str);
}
void dump_footer(void) {
 if(1&dump_mode) return; else printf("\n\033[0m");
}
void dump_event(struct gecko_cmd_packet *evt) {
  switch(BGLIB_MSG_ID(evt->header)) {
  case gecko_evt_dfu_boot_id:
    dump_event_header("dfu_boot");
   printf("  uint32      version: 0x%08x\n",(int)evt->data.evt_dfu_boot.version);
    break;
  case gecko_evt_dfu_boot_failure_id:
    dump_event_header("dfu_boot_failure");
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_dfu_boot_failure.reason);
    break;
  case gecko_evt_system_boot_id:
    dump_event_header("system_boot");
   printf("  uint16      major: 0x%04x\n",(int)evt->data.evt_system_boot.major);
   printf("  uint16      minor: 0x%04x\n",(int)evt->data.evt_system_boot.minor);
   printf("  uint16      patch: 0x%04x\n",(int)evt->data.evt_system_boot.patch);
   printf("  uint16      build: 0x%04x\n",(int)evt->data.evt_system_boot.build);
   printf("  uint32      bootloader: 0x%08x\n",(int)evt->data.evt_system_boot.bootloader);
   printf("  uint16      hw: 0x%04x\n",(int)evt->data.evt_system_boot.hw);
   printf("  uint32      hash: 0x%08x\n",(int)evt->data.evt_system_boot.hash);
    break;
  case gecko_evt_system_external_signal_id:
    dump_event_header("system_external_signal");
   printf("  uint32      extsignals: 0x%08x\n",(int)evt->data.evt_system_external_signal.extsignals);
    break;
  case gecko_evt_system_hardware_error_id:
    dump_event_header("system_hardware_error");
   printf("  uint16      status: 0x%04x\n",(int)evt->data.evt_system_hardware_error.status);
    break;
  case gecko_evt_system_error_id:
    dump_event_header("system_error");
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_system_error.reason);
   printf("  uint8array  data: %d:",(int)evt->data.evt_system_error.data.len);
   for(int i = 0; i < evt->data.evt_system_error.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_system_error.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_le_gap_scan_response_id:
    dump_event_header("le_gap_scan_response");
   printf("  int8        rssi: 0x%d\n",(int)evt->data.evt_le_gap_scan_response.rssi);
   printf("  uint8       packet_type: 0x%02x\n",(int)evt->data.evt_le_gap_scan_response.packet_type);
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_le_gap_scan_response.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_le_gap_scan_response.address_type);
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_le_gap_scan_response.bonding);
   printf("  uint8array  data: %d:",(int)evt->data.evt_le_gap_scan_response.data.len);
   for(int i = 0; i < evt->data.evt_le_gap_scan_response.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_le_gap_scan_response.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_le_gap_adv_timeout_id:
    dump_event_header("le_gap_adv_timeout");
   printf("  uint8       handle: 0x%02x\n",(int)evt->data.evt_le_gap_adv_timeout.handle);
    break;
  case gecko_evt_le_gap_scan_request_id:
    dump_event_header("le_gap_scan_request");
   printf("  uint8       handle: 0x%02x\n",(int)evt->data.evt_le_gap_scan_request.handle);
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_le_gap_scan_request.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_le_gap_scan_request.address_type);
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_le_gap_scan_request.bonding);
    break;
  case gecko_evt_le_gap_extended_scan_response_id:
    dump_event_header("le_gap_extended_scan_response");
   printf("  uint8       packet_type: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.packet_type);
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_le_gap_extended_scan_response.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.address_type);
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.bonding);
   printf("  uint8       primary_phy: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.primary_phy);
   printf("  uint8       secondary_phy: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.secondary_phy);
   printf("  uint8       adv_sid: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.adv_sid);
   printf("  int8        tx_power: 0x%d\n",(int)evt->data.evt_le_gap_extended_scan_response.tx_power);
   printf("  int8        rssi: 0x%d\n",(int)evt->data.evt_le_gap_extended_scan_response.rssi);
   printf("  uint8       channel: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.channel);
   printf("  uint16      periodic_interval: 0x%04x\n",(int)evt->data.evt_le_gap_extended_scan_response.periodic_interval);
   printf("  uint8array  data: %d:",(int)evt->data.evt_le_gap_extended_scan_response.data.len);
   for(int i = 0; i < evt->data.evt_le_gap_extended_scan_response.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_le_gap_extended_scan_response.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_le_gap_periodic_advertising_status_id:
    dump_event_header("le_gap_periodic_advertising_status");
   printf("  uint8       sid: 0x%02x\n",(int)evt->data.evt_le_gap_periodic_advertising_status.sid);
   printf("  uint32      status: 0x%08x\n",(int)evt->data.evt_le_gap_periodic_advertising_status.status);
    break;
  case gecko_evt_sync_opened_id:
    dump_event_header("sync_opened");
   printf("  uint8       sync: 0x%02x\n",(int)evt->data.evt_sync_opened.sync);
   printf("  uint8       adv_sid: 0x%02x\n",(int)evt->data.evt_sync_opened.adv_sid);
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_sync_opened.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_sync_opened.address_type);
   printf("  uint8       adv_phy: 0x%02x\n",(int)evt->data.evt_sync_opened.adv_phy);
   printf("  uint16      adv_interval: 0x%04x\n",(int)evt->data.evt_sync_opened.adv_interval);
   printf("  uint16      clock_accuracy: 0x%04x\n",(int)evt->data.evt_sync_opened.clock_accuracy);
    break;
  case gecko_evt_sync_closed_id:
    dump_event_header("sync_closed");
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_sync_closed.reason);
   printf("  uint8       sync: 0x%02x\n",(int)evt->data.evt_sync_closed.sync);
    break;
  case gecko_evt_sync_data_id:
    dump_event_header("sync_data");
   printf("  uint8       sync: 0x%02x\n",(int)evt->data.evt_sync_data.sync);
   printf("  int8        tx_power: 0x%d\n",(int)evt->data.evt_sync_data.tx_power);
   printf("  int8        rssi: 0x%d\n",(int)evt->data.evt_sync_data.rssi);
   printf("  uint8       data_status: 0x%02x\n",(int)evt->data.evt_sync_data.data_status);
   printf("  uint8array  data: %d:",(int)evt->data.evt_sync_data.data.len);
   for(int i = 0; i < evt->data.evt_sync_data.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_sync_data.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_le_connection_opened_id:
    dump_event_header("le_connection_opened");
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_le_connection_opened.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_le_connection_opened.address_type);
   printf("  uint8       master: 0x%02x\n",(int)evt->data.evt_le_connection_opened.master);
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_le_connection_opened.connection);
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_le_connection_opened.bonding);
   printf("  uint8       advertiser: 0x%02x\n",(int)evt->data.evt_le_connection_opened.advertiser);
    break;
  case gecko_evt_le_connection_closed_id:
    dump_event_header("le_connection_closed");
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_le_connection_closed.reason);
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_le_connection_closed.connection);
    break;
  case gecko_evt_le_connection_parameters_id:
    dump_event_header("le_connection_parameters");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_le_connection_parameters.connection);
   printf("  uint16      interval: 0x%04x\n",(int)evt->data.evt_le_connection_parameters.interval);
   printf("  uint16      latency: 0x%04x\n",(int)evt->data.evt_le_connection_parameters.latency);
   printf("  uint16      timeout: 0x%04x\n",(int)evt->data.evt_le_connection_parameters.timeout);
   printf("  uint8       security_mode: 0x%02x\n",(int)evt->data.evt_le_connection_parameters.security_mode);
   printf("  uint16      txsize: 0x%04x\n",(int)evt->data.evt_le_connection_parameters.txsize);
    break;
  case gecko_evt_le_connection_rssi_id:
    dump_event_header("le_connection_rssi");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_le_connection_rssi.connection);
   printf("  uint8       status: 0x%02x\n",(int)evt->data.evt_le_connection_rssi.status);
   printf("  int8        rssi: 0x%d\n",(int)evt->data.evt_le_connection_rssi.rssi);
    break;
  case gecko_evt_le_connection_phy_status_id:
    dump_event_header("le_connection_phy_status");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_le_connection_phy_status.connection);
   printf("  uint8       phy: 0x%02x\n",(int)evt->data.evt_le_connection_phy_status.phy);
    break;
  case gecko_evt_gatt_mtu_exchanged_id:
    dump_event_header("gatt_mtu_exchanged");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_mtu_exchanged.connection);
   printf("  uint16      mtu: 0x%04x\n",(int)evt->data.evt_gatt_mtu_exchanged.mtu);
    break;
  case gecko_evt_gatt_service_id:
    dump_event_header("gatt_service");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_service.connection);
   printf("  uint32      service: 0x%08x\n",(int)evt->data.evt_gatt_service.service);
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_gatt_service.uuid.len);
   for(int i = 0; i < evt->data.evt_gatt_service.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_service.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_characteristic_id:
    dump_event_header("gatt_characteristic");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_characteristic.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_gatt_characteristic.characteristic);
   printf("  uint8       properties: 0x%02x\n",(int)evt->data.evt_gatt_characteristic.properties);
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_gatt_characteristic.uuid.len);
   for(int i = 0; i < evt->data.evt_gatt_characteristic.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_characteristic.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_descriptor_id:
    dump_event_header("gatt_descriptor");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_descriptor.connection);
   printf("  uint16      descriptor: 0x%04x\n",(int)evt->data.evt_gatt_descriptor.descriptor);
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_gatt_descriptor.uuid.len);
   for(int i = 0; i < evt->data.evt_gatt_descriptor.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_descriptor.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_characteristic_value_id:
    dump_event_header("gatt_characteristic_value");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_characteristic_value.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_gatt_characteristic_value.characteristic);
   printf("  uint8       att_opcode: 0x%02x\n",(int)evt->data.evt_gatt_characteristic_value.att_opcode);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_gatt_characteristic_value.offset);
   printf("  uint8array  value: %d:",(int)evt->data.evt_gatt_characteristic_value.value.len);
   for(int i = 0; i < evt->data.evt_gatt_characteristic_value.value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_characteristic_value.value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_descriptor_value_id:
    dump_event_header("gatt_descriptor_value");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_descriptor_value.connection);
   printf("  uint16      descriptor: 0x%04x\n",(int)evt->data.evt_gatt_descriptor_value.descriptor);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_gatt_descriptor_value.offset);
   printf("  uint8array  value: %d:",(int)evt->data.evt_gatt_descriptor_value.value.len);
   for(int i = 0; i < evt->data.evt_gatt_descriptor_value.value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_descriptor_value.value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_procedure_completed_id:
    dump_event_header("gatt_procedure_completed");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_procedure_completed.connection);
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_gatt_procedure_completed.result);
    break;
  case gecko_evt_gatt_server_attribute_value_id:
    dump_event_header("gatt_server_attribute_value");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_server_attribute_value.connection);
   printf("  uint16      attribute: 0x%04x\n",(int)evt->data.evt_gatt_server_attribute_value.attribute);
   printf("  uint8       att_opcode: 0x%02x\n",(int)evt->data.evt_gatt_server_attribute_value.att_opcode);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_gatt_server_attribute_value.offset);
   printf("  uint8array  value: %d:",(int)evt->data.evt_gatt_server_attribute_value.value.len);
   for(int i = 0; i < evt->data.evt_gatt_server_attribute_value.value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_server_attribute_value.value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_server_user_read_request_id:
    dump_event_header("gatt_server_user_read_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_server_user_read_request.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_gatt_server_user_read_request.characteristic);
   printf("  uint8       att_opcode: 0x%02x\n",(int)evt->data.evt_gatt_server_user_read_request.att_opcode);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_gatt_server_user_read_request.offset);
    break;
  case gecko_evt_gatt_server_user_write_request_id:
    dump_event_header("gatt_server_user_write_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_server_user_write_request.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_gatt_server_user_write_request.characteristic);
   printf("  uint8       att_opcode: 0x%02x\n",(int)evt->data.evt_gatt_server_user_write_request.att_opcode);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_gatt_server_user_write_request.offset);
   printf("  uint8array  value: %d:",(int)evt->data.evt_gatt_server_user_write_request.value.len);
   for(int i = 0; i < evt->data.evt_gatt_server_user_write_request.value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_server_user_write_request.value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_server_characteristic_status_id:
    dump_event_header("gatt_server_characteristic_status");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_server_characteristic_status.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_gatt_server_characteristic_status.characteristic);
   printf("  uint8       status_flags: 0x%02x\n",(int)evt->data.evt_gatt_server_characteristic_status.status_flags);
   printf("  uint16      client_config_flags: 0x%04x\n",(int)evt->data.evt_gatt_server_characteristic_status.client_config_flags);
    break;
  case gecko_evt_gatt_server_execute_write_completed_id:
    dump_event_header("gatt_server_execute_write_completed");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_server_execute_write_completed.connection);
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_gatt_server_execute_write_completed.result);
    break;
  case gecko_evt_hardware_soft_timer_id:
    dump_event_header("hardware_soft_timer");
   printf("  uint8       handle: 0x%02x\n",(int)evt->data.evt_hardware_soft_timer.handle);
    break;
  case gecko_evt_test_dtm_completed_id:
    dump_event_header("test_dtm_completed");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_test_dtm_completed.result);
   printf("  uint16      number_of_packets: 0x%04x\n",(int)evt->data.evt_test_dtm_completed.number_of_packets);
    break;
  case gecko_evt_sm_passkey_display_id:
    dump_event_header("sm_passkey_display");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_passkey_display.connection);
   printf("  uint32      passkey: 0x%08x\n",(int)evt->data.evt_sm_passkey_display.passkey);
    break;
  case gecko_evt_sm_passkey_request_id:
    dump_event_header("sm_passkey_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_passkey_request.connection);
    break;
  case gecko_evt_sm_confirm_passkey_id:
    dump_event_header("sm_confirm_passkey");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_confirm_passkey.connection);
   printf("  uint32      passkey: 0x%08x\n",(int)evt->data.evt_sm_confirm_passkey.passkey);
    break;
  case gecko_evt_sm_bonded_id:
    dump_event_header("sm_bonded");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_bonded.connection);
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_sm_bonded.bonding);
    break;
  case gecko_evt_sm_bonding_failed_id:
    dump_event_header("sm_bonding_failed");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_bonding_failed.connection);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_sm_bonding_failed.reason);
    break;
  case gecko_evt_sm_list_bonding_entry_id:
    dump_event_header("sm_list_bonding_entry");
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_sm_list_bonding_entry.bonding);
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_sm_list_bonding_entry.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_sm_list_bonding_entry.address_type);
    break;
  case gecko_evt_sm_confirm_bonding_id:
    dump_event_header("sm_confirm_bonding");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_confirm_bonding.connection);
   printf("  int8        bonding_handle: 0x%d\n",(int)evt->data.evt_sm_confirm_bonding.bonding_handle);
    break;
  case gecko_evt_homekit_setupcode_display_id:
    dump_event_header("homekit_setupcode_display");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_setupcode_display.connection);
   printf("  uint8array  setupcode: %d:",(int)evt->data.evt_homekit_setupcode_display.setupcode.len);
   for(int i = 0; i < evt->data.evt_homekit_setupcode_display.setupcode.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_homekit_setupcode_display.setupcode.data[i]);
   printf("}\n");
    break;
  case gecko_evt_homekit_paired_id:
    dump_event_header("homekit_paired");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_paired.connection);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_homekit_paired.reason);
    break;
  case gecko_evt_homekit_pair_verified_id:
    dump_event_header("homekit_pair_verified");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_pair_verified.connection);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_homekit_pair_verified.reason);
    break;
  case gecko_evt_homekit_connection_opened_id:
    dump_event_header("homekit_connection_opened");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_connection_opened.connection);
    break;
  case gecko_evt_homekit_connection_closed_id:
    dump_event_header("homekit_connection_closed");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_connection_closed.connection);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_homekit_connection_closed.reason);
    break;
  case gecko_evt_homekit_identify_id:
    dump_event_header("homekit_identify");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_identify.connection);
    break;
  case gecko_evt_homekit_write_request_id:
    dump_event_header("homekit_write_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_write_request.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_homekit_write_request.characteristic);
   printf("  uint16      chr_value_size: 0x%04x\n",(int)evt->data.evt_homekit_write_request.chr_value_size);
   printf("  uint16      authorization_size: 0x%04x\n",(int)evt->data.evt_homekit_write_request.authorization_size);
   printf("  uint16      value_offset: 0x%04x\n",(int)evt->data.evt_homekit_write_request.value_offset);
   printf("  uint8array  value: %d:",(int)evt->data.evt_homekit_write_request.value.len);
   for(int i = 0; i < evt->data.evt_homekit_write_request.value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_homekit_write_request.value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_homekit_read_request_id:
    dump_event_header("homekit_read_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_read_request.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_homekit_read_request.characteristic);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_homekit_read_request.offset);
    break;
  case gecko_evt_homekit_disconnection_required_id:
    dump_event_header("homekit_disconnection_required");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_disconnection_required.connection);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_homekit_disconnection_required.reason);
    break;
  case gecko_evt_homekit_pairing_removed_id:
    dump_event_header("homekit_pairing_removed");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_pairing_removed.connection);
   printf("  uint16      remaining_pairings: 0x%04x\n",(int)evt->data.evt_homekit_pairing_removed.remaining_pairings);
   printf("  uint8array  pairing_id: %d:",(int)evt->data.evt_homekit_pairing_removed.pairing_id.len);
   for(int i = 0; i < evt->data.evt_homekit_pairing_removed.pairing_id.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_homekit_pairing_removed.pairing_id.data[i]);
   printf("}\n");
    break;
  case gecko_evt_homekit_setuppayload_display_id:
    dump_event_header("homekit_setuppayload_display");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_setuppayload_display.connection);
   printf("  uint8array  setuppayload: %d:",(int)evt->data.evt_homekit_setuppayload_display.setuppayload.len);
   for(int i = 0; i < evt->data.evt_homekit_setuppayload_display.setuppayload.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_homekit_setuppayload_display.setuppayload.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_node_initialized_id:
    dump_event_header("mesh_node_initialized");
   printf("  uint8       provisioned: 0x%02x\n",(int)evt->data.evt_mesh_node_initialized.provisioned);
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_node_initialized.address);
   printf("  uint32      ivi: 0x%08x\n",(int)evt->data.evt_mesh_node_initialized.ivi);
    break;
  case gecko_evt_mesh_node_provisioned_id:
    dump_event_header("mesh_node_provisioned");
   printf("  uint32      iv_index: 0x%08x\n",(int)evt->data.evt_mesh_node_provisioned.iv_index);
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_node_provisioned.address);
    break;
  case gecko_evt_mesh_node_config_get_id:
    dump_event_header("mesh_node_config_get");
   printf("  uint16      id: 0x%04x\n",(int)evt->data.evt_mesh_node_config_get.id);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_node_config_get.netkey_index);
    break;
  case gecko_evt_mesh_node_config_set_id:
    dump_event_header("mesh_node_config_set");
   printf("  uint16      id: 0x%04x\n",(int)evt->data.evt_mesh_node_config_set.id);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_node_config_set.netkey_index);
   printf("  uint8array  value: %d:",(int)evt->data.evt_mesh_node_config_set.value.len);
   for(int i = 0; i < evt->data.evt_mesh_node_config_set.value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_node_config_set.value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_node_display_output_oob_id:
    dump_event_header("mesh_node_display_output_oob");
   printf("  uint8       output_action: 0x%02x\n",(int)evt->data.evt_mesh_node_display_output_oob.output_action);
   printf("  uint8       output_size: 0x%02x\n",(int)evt->data.evt_mesh_node_display_output_oob.output_size);
   printf("  uint8array  data: %d:",(int)evt->data.evt_mesh_node_display_output_oob.data.len);
   for(int i = 0; i < evt->data.evt_mesh_node_display_output_oob.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_node_display_output_oob.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_node_input_oob_request_id:
    dump_event_header("mesh_node_input_oob_request");
   printf("  uint8       input_action: 0x%02x\n",(int)evt->data.evt_mesh_node_input_oob_request.input_action);
   printf("  uint8       input_size: 0x%02x\n",(int)evt->data.evt_mesh_node_input_oob_request.input_size);
    break;
  case gecko_evt_mesh_node_provisioning_started_id:
    dump_event_header("mesh_node_provisioning_started");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_node_provisioning_started.result);
    break;
  case gecko_evt_mesh_node_provisioning_failed_id:
    dump_event_header("mesh_node_provisioning_failed");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_node_provisioning_failed.result);
    break;
  case gecko_evt_mesh_node_key_added_id:
    dump_event_header("mesh_node_key_added");
   printf("  uint8       type: 0x%02x\n",(int)evt->data.evt_mesh_node_key_added.type);
   printf("  uint16      index: 0x%04x\n",(int)evt->data.evt_mesh_node_key_added.index);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_node_key_added.netkey_index);
    break;
  case gecko_evt_mesh_node_model_config_changed_id:
    dump_event_header("mesh_node_model_config_changed");
   printf("  uint8       mesh_node_config_state: 0x%02x\n",(int)evt->data.evt_mesh_node_model_config_changed.mesh_node_config_state);
   printf("  uint16      element_address: 0x%04x\n",(int)evt->data.evt_mesh_node_model_config_changed.element_address);
   printf("  uint16      vendor_id: 0x%04x\n",(int)evt->data.evt_mesh_node_model_config_changed.vendor_id);
   printf("  uint16      model_id: 0x%04x\n",(int)evt->data.evt_mesh_node_model_config_changed.model_id);
    break;
  case gecko_evt_mesh_node_ivrecovery_needed_id:
    dump_event_header("mesh_node_ivrecovery_needed");
   printf("  uint32      node_ivindex: 0x%08x\n",(int)evt->data.evt_mesh_node_ivrecovery_needed.node_ivindex);
   printf("  uint32      network_ivindex: 0x%08x\n",(int)evt->data.evt_mesh_node_ivrecovery_needed.network_ivindex);
    break;
  case gecko_evt_mesh_node_changed_ivupdate_state_id:
    dump_event_header("mesh_node_changed_ivupdate_state");
   printf("  uint32      ivindex: 0x%08x\n",(int)evt->data.evt_mesh_node_changed_ivupdate_state.ivindex);
   printf("  uint8       state: 0x%02x\n",(int)evt->data.evt_mesh_node_changed_ivupdate_state.state);
    break;
  case gecko_evt_mesh_node_key_removed_id:
    dump_event_header("mesh_node_key_removed");
   printf("  uint8       type: 0x%02x\n",(int)evt->data.evt_mesh_node_key_removed.type);
   printf("  uint16      index: 0x%04x\n",(int)evt->data.evt_mesh_node_key_removed.index);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_node_key_removed.netkey_index);
    break;
  case gecko_evt_mesh_node_key_updated_id:
    dump_event_header("mesh_node_key_updated");
   printf("  uint8       type: 0x%02x\n",(int)evt->data.evt_mesh_node_key_updated.type);
   printf("  uint16      index: 0x%04x\n",(int)evt->data.evt_mesh_node_key_updated.index);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_node_key_updated.netkey_index);
    break;
  case gecko_evt_mesh_node_heartbeat_id:
    dump_event_header("mesh_node_heartbeat");
   printf("  uint16      src_addr: 0x%04x\n",(int)evt->data.evt_mesh_node_heartbeat.src_addr);
   printf("  uint16      dst_addr: 0x%04x\n",(int)evt->data.evt_mesh_node_heartbeat.dst_addr);
   printf("  uint8       hops: 0x%02x\n",(int)evt->data.evt_mesh_node_heartbeat.hops);
    break;
  case gecko_evt_mesh_node_heartbeat_start_id:
    dump_event_header("mesh_node_heartbeat_start");
   printf("  uint16      src_addr: 0x%04x\n",(int)evt->data.evt_mesh_node_heartbeat_start.src_addr);
   printf("  uint16      dst_addr: 0x%04x\n",(int)evt->data.evt_mesh_node_heartbeat_start.dst_addr);
   printf("  uint32      period: 0x%08x\n",(int)evt->data.evt_mesh_node_heartbeat_start.period);
    break;
  case gecko_evt_mesh_node_heartbeat_stop_id:
    dump_event_header("mesh_node_heartbeat_stop");
   printf("  uint16      src_addr: 0x%04x\n",(int)evt->data.evt_mesh_node_heartbeat_stop.src_addr);
   printf("  uint16      dst_addr: 0x%04x\n",(int)evt->data.evt_mesh_node_heartbeat_stop.dst_addr);
    break;
  case gecko_evt_mesh_node_beacon_received_id:
    dump_event_header("mesh_node_beacon_received");
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_node_beacon_received.netkey_index);
   printf("  uint8       key_refresh: 0x%02x\n",(int)evt->data.evt_mesh_node_beacon_received.key_refresh);
   printf("  uint8       iv_update: 0x%02x\n",(int)evt->data.evt_mesh_node_beacon_received.iv_update);
   printf("  uint32      ivindex: 0x%08x\n",(int)evt->data.evt_mesh_node_beacon_received.ivindex);
    break;
  case gecko_evt_mesh_prov_initialized_id:
    dump_event_header("mesh_prov_initialized");
   printf("  uint8       networks: 0x%02x\n",(int)evt->data.evt_mesh_prov_initialized.networks);
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_initialized.address);
   printf("  uint32      ivi: 0x%08x\n",(int)evt->data.evt_mesh_prov_initialized.ivi);
    break;
  case gecko_evt_mesh_prov_provisioning_failed_id:
    dump_event_header("mesh_prov_provisioning_failed");
   printf("  uint8       reason: 0x%02x\n",(int)evt->data.evt_mesh_prov_provisioning_failed.reason);
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_mesh_prov_provisioning_failed.uuid.len);
   for(int i = 0; i < evt->data.evt_mesh_prov_provisioning_failed.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_prov_provisioning_failed.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_prov_device_provisioned_id:
    dump_event_header("mesh_prov_device_provisioned");
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_device_provisioned.address);
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_mesh_prov_device_provisioned.uuid.len);
   for(int i = 0; i < evt->data.evt_mesh_prov_device_provisioned.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_prov_device_provisioned.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_prov_unprov_beacon_id:
    dump_event_header("mesh_prov_unprov_beacon");
   printf("  uint16      oob_capabilities: 0x%04x\n",(int)evt->data.evt_mesh_prov_unprov_beacon.oob_capabilities);
   printf("  uint32      uri_hash: 0x%08x\n",(int)evt->data.evt_mesh_prov_unprov_beacon.uri_hash);
   printf("  uint8       bearer: 0x%02x\n",(int)evt->data.evt_mesh_prov_unprov_beacon.bearer);
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_mesh_prov_unprov_beacon.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_mesh_prov_unprov_beacon.address_type);
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_mesh_prov_unprov_beacon.uuid.len);
   for(int i = 0; i < evt->data.evt_mesh_prov_unprov_beacon.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_prov_unprov_beacon.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_prov_dcd_status_id:
    dump_event_header("mesh_prov_dcd_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_prov_dcd_status.result);
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_dcd_status.address);
   printf("  uint16      cid: 0x%04x\n",(int)evt->data.evt_mesh_prov_dcd_status.cid);
   printf("  uint16      pid: 0x%04x\n",(int)evt->data.evt_mesh_prov_dcd_status.pid);
   printf("  uint16      vid: 0x%04x\n",(int)evt->data.evt_mesh_prov_dcd_status.vid);
   printf("  uint16      crpl: 0x%04x\n",(int)evt->data.evt_mesh_prov_dcd_status.crpl);
   printf("  uint16      features: 0x%04x\n",(int)evt->data.evt_mesh_prov_dcd_status.features);
   printf("  uint8       elements: 0x%02x\n",(int)evt->data.evt_mesh_prov_dcd_status.elements);
   printf("  uint8       models: 0x%02x\n",(int)evt->data.evt_mesh_prov_dcd_status.models);
   printf("  uint8array  element_data: %d:",(int)evt->data.evt_mesh_prov_dcd_status.element_data.len);
   for(int i = 0; i < evt->data.evt_mesh_prov_dcd_status.element_data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_prov_dcd_status.element_data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_prov_config_status_id:
    dump_event_header("mesh_prov_config_status");
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_config_status.address);
   printf("  uint16      id: 0x%04x\n",(int)evt->data.evt_mesh_prov_config_status.id);
   printf("  uint8       status: 0x%02x\n",(int)evt->data.evt_mesh_prov_config_status.status);
   printf("  uint8array  data: %d:",(int)evt->data.evt_mesh_prov_config_status.data.len);
   for(int i = 0; i < evt->data.evt_mesh_prov_config_status.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_prov_config_status.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_prov_oob_pkey_request_id:
    dump_event_header("mesh_prov_oob_pkey_request");
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_mesh_prov_oob_pkey_request.uuid.len);
   for(int i = 0; i < evt->data.evt_mesh_prov_oob_pkey_request.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_prov_oob_pkey_request.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_prov_oob_auth_request_id:
    dump_event_header("mesh_prov_oob_auth_request");
   printf("  uint8       output: 0x%02x\n",(int)evt->data.evt_mesh_prov_oob_auth_request.output);
   printf("  uint8       output_action: 0x%02x\n",(int)evt->data.evt_mesh_prov_oob_auth_request.output_action);
   printf("  uint8       output_size: 0x%02x\n",(int)evt->data.evt_mesh_prov_oob_auth_request.output_size);
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_mesh_prov_oob_auth_request.uuid.len);
   for(int i = 0; i < evt->data.evt_mesh_prov_oob_auth_request.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_prov_oob_auth_request.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_prov_oob_display_input_id:
    dump_event_header("mesh_prov_oob_display_input");
   printf("  uint8       input_action: 0x%02x\n",(int)evt->data.evt_mesh_prov_oob_display_input.input_action);
   printf("  uint8       input_size: 0x%02x\n",(int)evt->data.evt_mesh_prov_oob_display_input.input_size);
   printf("  uint8array  data: %d:",(int)evt->data.evt_mesh_prov_oob_display_input.data.len);
   for(int i = 0; i < evt->data.evt_mesh_prov_oob_display_input.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_prov_oob_display_input.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_prov_ddb_list_id:
    dump_event_header("mesh_prov_ddb_list");
   printf("  aes_key_128 uuid: ");
   for(int i = 0; i < 16; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_prov_ddb_list.uuid.data[i]);
   printf("\n");
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_ddb_list.address);
   printf("  uint8       elements: 0x%02x\n",(int)evt->data.evt_mesh_prov_ddb_list.elements);
    break;
  case gecko_evt_mesh_prov_heartbeat_publication_status_id:
    dump_event_header("mesh_prov_heartbeat_publication_status");
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_heartbeat_publication_status.address);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_prov_heartbeat_publication_status.netkey_index);
   printf("  uint16      publication_address: 0x%04x\n",(int)evt->data.evt_mesh_prov_heartbeat_publication_status.publication_address);
   printf("  uint8       count_log: 0x%02x\n",(int)evt->data.evt_mesh_prov_heartbeat_publication_status.count_log);
   printf("  uint8       period_log: 0x%02x\n",(int)evt->data.evt_mesh_prov_heartbeat_publication_status.period_log);
   printf("  uint8       ttl: 0x%02x\n",(int)evt->data.evt_mesh_prov_heartbeat_publication_status.ttl);
   printf("  uint16      features: 0x%04x\n",(int)evt->data.evt_mesh_prov_heartbeat_publication_status.features);
   printf("  uint16      publication_netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_prov_heartbeat_publication_status.publication_netkey_index);
    break;
  case gecko_evt_mesh_prov_heartbeat_subscription_status_id:
    dump_event_header("mesh_prov_heartbeat_subscription_status");
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_heartbeat_subscription_status.address);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_prov_heartbeat_subscription_status.netkey_index);
   printf("  uint16      subscription_source: 0x%04x\n",(int)evt->data.evt_mesh_prov_heartbeat_subscription_status.subscription_source);
   printf("  uint16      subscription_destination: 0x%04x\n",(int)evt->data.evt_mesh_prov_heartbeat_subscription_status.subscription_destination);
   printf("  uint8       period_log: 0x%02x\n",(int)evt->data.evt_mesh_prov_heartbeat_subscription_status.period_log);
   printf("  uint8       count_log: 0x%02x\n",(int)evt->data.evt_mesh_prov_heartbeat_subscription_status.count_log);
   printf("  uint8       min_hops: 0x%02x\n",(int)evt->data.evt_mesh_prov_heartbeat_subscription_status.min_hops);
   printf("  uint8       max_hops: 0x%02x\n",(int)evt->data.evt_mesh_prov_heartbeat_subscription_status.max_hops);
    break;
  case gecko_evt_mesh_prov_relay_status_id:
    dump_event_header("mesh_prov_relay_status");
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_relay_status.address);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_prov_relay_status.netkey_index);
   printf("  uint8       value: 0x%02x\n",(int)evt->data.evt_mesh_prov_relay_status.value);
   printf("  uint8       count: 0x%02x\n",(int)evt->data.evt_mesh_prov_relay_status.count);
   printf("  uint8       interval: 0x%02x\n",(int)evt->data.evt_mesh_prov_relay_status.interval);
    break;
  case gecko_evt_mesh_prov_uri_id:
    dump_event_header("mesh_prov_uri");
   printf("  uint32      hash: 0x%08x\n",(int)evt->data.evt_mesh_prov_uri.hash);
   printf("  uint8array  data: %d:",(int)evt->data.evt_mesh_prov_uri.data.len);
   for(int i = 0; i < evt->data.evt_mesh_prov_uri.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_prov_uri.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_prov_node_reset_id:
    dump_event_header("mesh_prov_node_reset");
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_node_reset.address);
    break;
  case gecko_evt_mesh_prov_appkey_list_id:
    dump_event_header("mesh_prov_appkey_list");
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_appkey_list.address);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_prov_appkey_list.netkey_index);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_prov_appkey_list.appkey_index);
    break;
  case gecko_evt_mesh_prov_appkey_list_end_id:
    dump_event_header("mesh_prov_appkey_list_end");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_prov_appkey_list_end.result);
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_appkey_list_end.address);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_prov_appkey_list_end.netkey_index);
    break;
  case gecko_evt_mesh_prov_network_list_id:
    dump_event_header("mesh_prov_network_list");
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_network_list.address);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_prov_network_list.netkey_index);
    break;
  case gecko_evt_mesh_prov_network_list_end_id:
    dump_event_header("mesh_prov_network_list_end");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_prov_network_list_end.result);
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_network_list_end.address);
    break;
  case gecko_evt_mesh_prov_model_pub_status_id:
    dump_event_header("mesh_prov_model_pub_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_pub_status.result);
   printf("  uint16      elem_address: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_pub_status.elem_address);
   printf("  uint16      vendor_id: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_pub_status.vendor_id);
   printf("  uint16      model_id: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_pub_status.model_id);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_pub_status.appkey_index);
   printf("  uint16      pub_address: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_pub_status.pub_address);
   printf("  uint8       ttl: 0x%02x\n",(int)evt->data.evt_mesh_prov_model_pub_status.ttl);
   printf("  uint8       period: 0x%02x\n",(int)evt->data.evt_mesh_prov_model_pub_status.period);
   printf("  uint8       retrans: 0x%02x\n",(int)evt->data.evt_mesh_prov_model_pub_status.retrans);
   printf("  uint8       credentials: 0x%02x\n",(int)evt->data.evt_mesh_prov_model_pub_status.credentials);
    break;
  case gecko_evt_mesh_prov_key_refresh_phase_update_id:
    dump_event_header("mesh_prov_key_refresh_phase_update");
   printf("  uint16      key: 0x%04x\n",(int)evt->data.evt_mesh_prov_key_refresh_phase_update.key);
   printf("  uint8       phase: 0x%02x\n",(int)evt->data.evt_mesh_prov_key_refresh_phase_update.phase);
    break;
  case gecko_evt_mesh_prov_key_refresh_node_update_id:
    dump_event_header("mesh_prov_key_refresh_node_update");
   printf("  uint16      key: 0x%04x\n",(int)evt->data.evt_mesh_prov_key_refresh_node_update.key);
   printf("  uint8       phase: 0x%02x\n",(int)evt->data.evt_mesh_prov_key_refresh_node_update.phase);
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_mesh_prov_key_refresh_node_update.uuid.len);
   for(int i = 0; i < evt->data.evt_mesh_prov_key_refresh_node_update.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_prov_key_refresh_node_update.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_prov_key_refresh_complete_id:
    dump_event_header("mesh_prov_key_refresh_complete");
   printf("  uint16      key: 0x%04x\n",(int)evt->data.evt_mesh_prov_key_refresh_complete.key);
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_prov_key_refresh_complete.result);
    break;
  case gecko_evt_mesh_prov_model_sub_addr_id:
    dump_event_header("mesh_prov_model_sub_addr");
   printf("  uint16      elem_address: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_sub_addr.elem_address);
   printf("  uint16      vendor_id: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_sub_addr.vendor_id);
   printf("  uint16      model_id: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_sub_addr.model_id);
   printf("  uint16      sub_addr: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_sub_addr.sub_addr);
    break;
  case gecko_evt_mesh_prov_model_sub_addr_end_id:
    dump_event_header("mesh_prov_model_sub_addr_end");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_sub_addr_end.result);
   printf("  uint16      elem_address: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_sub_addr_end.elem_address);
   printf("  uint16      vendor_id: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_sub_addr_end.vendor_id);
   printf("  uint16      model_id: 0x%04x\n",(int)evt->data.evt_mesh_prov_model_sub_addr_end.model_id);
    break;
  case gecko_evt_mesh_prov_friend_timeout_status_id:
    dump_event_header("mesh_prov_friend_timeout_status");
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_prov_friend_timeout_status.address);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_prov_friend_timeout_status.netkey_index);
   printf("  uint32      timeout: 0x%08x\n",(int)evt->data.evt_mesh_prov_friend_timeout_status.timeout);
    break;
  case gecko_evt_mesh_proxy_connected_id:
    dump_event_header("mesh_proxy_connected");
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_proxy_connected.handle);
    break;
  case gecko_evt_mesh_proxy_disconnected_id:
    dump_event_header("mesh_proxy_disconnected");
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_proxy_disconnected.handle);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_mesh_proxy_disconnected.reason);
    break;
  case gecko_evt_mesh_proxy_filter_status_id:
    dump_event_header("mesh_proxy_filter_status");
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_proxy_filter_status.handle);
   printf("  uint8       type: 0x%02x\n",(int)evt->data.evt_mesh_proxy_filter_status.type);
   printf("  uint16      count: 0x%04x\n",(int)evt->data.evt_mesh_proxy_filter_status.count);
    break;
  case gecko_evt_mesh_vendor_model_receive_id:
    dump_event_header("mesh_vendor_model_receive");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_vendor_model_receive.elem_index);
   printf("  uint16      vendor_id: 0x%04x\n",(int)evt->data.evt_mesh_vendor_model_receive.vendor_id);
   printf("  uint16      model_id: 0x%04x\n",(int)evt->data.evt_mesh_vendor_model_receive.model_id);
   printf("  uint16      source_address: 0x%04x\n",(int)evt->data.evt_mesh_vendor_model_receive.source_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_vendor_model_receive.destination_address);
   printf("  int8        va_index: 0x%d\n",(int)evt->data.evt_mesh_vendor_model_receive.va_index);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_vendor_model_receive.appkey_index);
   printf("  uint8       nonrelayed: 0x%02x\n",(int)evt->data.evt_mesh_vendor_model_receive.nonrelayed);
   printf("  uint8       opcode: 0x%02x\n",(int)evt->data.evt_mesh_vendor_model_receive.opcode);
   printf("  uint8       final: 0x%02x\n",(int)evt->data.evt_mesh_vendor_model_receive.final);
   printf("  uint8array  payload: %d:",(int)evt->data.evt_mesh_vendor_model_receive.payload.len);
   for(int i = 0; i < evt->data.evt_mesh_vendor_model_receive.payload.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_vendor_model_receive.payload.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_health_client_server_status_id:
    dump_event_header("mesh_health_client_server_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status.result);
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status.server_address);
   printf("  uint8       current: 0x%02x\n",(int)evt->data.evt_mesh_health_client_server_status.current);
   printf("  uint8       test_id: 0x%02x\n",(int)evt->data.evt_mesh_health_client_server_status.test_id);
   printf("  uint16      vendor_id: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status.vendor_id);
   printf("  uint8array  faults: %d:",(int)evt->data.evt_mesh_health_client_server_status.faults.len);
   for(int i = 0; i < evt->data.evt_mesh_health_client_server_status.faults.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_health_client_server_status.faults.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_health_client_server_status_period_id:
    dump_event_header("mesh_health_client_server_status_period");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status_period.result);
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status_period.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status_period.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status_period.server_address);
   printf("  uint8       period: 0x%02x\n",(int)evt->data.evt_mesh_health_client_server_status_period.period);
    break;
  case gecko_evt_mesh_health_client_server_status_attention_id:
    dump_event_header("mesh_health_client_server_status_attention");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status_attention.result);
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status_attention.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status_attention.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_health_client_server_status_attention.server_address);
   printf("  uint8       attention: 0x%02x\n",(int)evt->data.evt_mesh_health_client_server_status_attention.attention);
    break;
  case gecko_evt_mesh_health_server_attention_id:
    dump_event_header("mesh_health_server_attention");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_health_server_attention.elem_index);
   printf("  uint8       timer: 0x%02x\n",(int)evt->data.evt_mesh_health_server_attention.timer);
    break;
  case gecko_evt_mesh_health_server_test_request_id:
    dump_event_header("mesh_health_server_test_request");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_health_server_test_request.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_health_server_test_request.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_health_server_test_request.server_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_health_server_test_request.appkey_index);
   printf("  uint8       test_id: 0x%02x\n",(int)evt->data.evt_mesh_health_server_test_request.test_id);
   printf("  uint16      vendor_id: 0x%04x\n",(int)evt->data.evt_mesh_health_server_test_request.vendor_id);
   printf("  uint8       response_required: 0x%02x\n",(int)evt->data.evt_mesh_health_server_test_request.response_required);
    break;
  case gecko_evt_mesh_generic_client_server_status_id:
    dump_event_header("mesh_generic_client_server_status");
   printf("  uint16      model_id: 0x%04x\n",(int)evt->data.evt_mesh_generic_client_server_status.model_id);
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_generic_client_server_status.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_generic_client_server_status.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_generic_client_server_status.server_address);
   printf("  uint32      remaining: 0x%08x\n",(int)evt->data.evt_mesh_generic_client_server_status.remaining);
   printf("  uint16      flags: 0x%04x\n",(int)evt->data.evt_mesh_generic_client_server_status.flags);
   printf("  uint8       type: 0x%02x\n",(int)evt->data.evt_mesh_generic_client_server_status.type);
   printf("  uint8array  parameters: %d:",(int)evt->data.evt_mesh_generic_client_server_status.parameters.len);
   for(int i = 0; i < evt->data.evt_mesh_generic_client_server_status.parameters.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_generic_client_server_status.parameters.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_generic_server_client_request_id:
    dump_event_header("mesh_generic_server_client_request");
   printf("  uint16      model_id: 0x%04x\n",(int)evt->data.evt_mesh_generic_server_client_request.model_id);
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_generic_server_client_request.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_generic_server_client_request.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_generic_server_client_request.server_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_generic_server_client_request.appkey_index);
   printf("  uint32      transition: 0x%08x\n",(int)evt->data.evt_mesh_generic_server_client_request.transition);
   printf("  uint16      delay: 0x%04x\n",(int)evt->data.evt_mesh_generic_server_client_request.delay);
   printf("  uint16      flags: 0x%04x\n",(int)evt->data.evt_mesh_generic_server_client_request.flags);
   printf("  uint8       type: 0x%02x\n",(int)evt->data.evt_mesh_generic_server_client_request.type);
   printf("  uint8array  parameters: %d:",(int)evt->data.evt_mesh_generic_server_client_request.parameters.len);
   for(int i = 0; i < evt->data.evt_mesh_generic_server_client_request.parameters.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_generic_server_client_request.parameters.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_generic_server_state_changed_id:
    dump_event_header("mesh_generic_server_state_changed");
   printf("  uint16      model_id: 0x%04x\n",(int)evt->data.evt_mesh_generic_server_state_changed.model_id);
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_generic_server_state_changed.elem_index);
   printf("  uint32      remaining: 0x%08x\n",(int)evt->data.evt_mesh_generic_server_state_changed.remaining);
   printf("  uint8       type: 0x%02x\n",(int)evt->data.evt_mesh_generic_server_state_changed.type);
   printf("  uint8array  parameters: %d:",(int)evt->data.evt_mesh_generic_server_state_changed.parameters.len);
   for(int i = 0; i < evt->data.evt_mesh_generic_server_state_changed.parameters.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_generic_server_state_changed.parameters.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_generic_server_state_recall_id:
    dump_event_header("mesh_generic_server_state_recall");
   printf("  uint16      model_id: 0x%04x\n",(int)evt->data.evt_mesh_generic_server_state_recall.model_id);
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_generic_server_state_recall.elem_index);
   printf("  uint32      transition_time: 0x%08x\n",(int)evt->data.evt_mesh_generic_server_state_recall.transition_time);
   printf("  uint8       type: 0x%02x\n",(int)evt->data.evt_mesh_generic_server_state_recall.type);
   printf("  uint8array  parameters: %d:",(int)evt->data.evt_mesh_generic_server_state_recall.parameters.len);
   for(int i = 0; i < evt->data.evt_mesh_generic_server_state_recall.parameters.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_generic_server_state_recall.parameters.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_test_local_heartbeat_subscription_complete_id:
    dump_event_header("mesh_test_local_heartbeat_subscription_complete");
   printf("  uint16      count: 0x%04x\n",(int)evt->data.evt_mesh_test_local_heartbeat_subscription_complete.count);
   printf("  uint8       hop_min: 0x%02x\n",(int)evt->data.evt_mesh_test_local_heartbeat_subscription_complete.hop_min);
   printf("  uint8       hop_max: 0x%02x\n",(int)evt->data.evt_mesh_test_local_heartbeat_subscription_complete.hop_max);
    break;
  case gecko_evt_mesh_lpn_friendship_established_id:
    dump_event_header("mesh_lpn_friendship_established");
   printf("  uint16      friend_address: 0x%04x\n",(int)evt->data.evt_mesh_lpn_friendship_established.friend_address);
    break;
  case gecko_evt_mesh_lpn_friendship_failed_id:
    dump_event_header("mesh_lpn_friendship_failed");
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_mesh_lpn_friendship_failed.reason);
    break;
  case gecko_evt_mesh_lpn_friendship_terminated_id:
    dump_event_header("mesh_lpn_friendship_terminated");
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_mesh_lpn_friendship_terminated.reason);
    break;
  case gecko_evt_mesh_friend_friendship_established_id:
    dump_event_header("mesh_friend_friendship_established");
   printf("  uint16      lpn_address: 0x%04x\n",(int)evt->data.evt_mesh_friend_friendship_established.lpn_address);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_friend_friendship_established.netkey_index);
    break;
  case gecko_evt_mesh_friend_friendship_terminated_id:
    dump_event_header("mesh_friend_friendship_terminated");
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_mesh_friend_friendship_terminated.reason);
   printf("  uint16      lpn_address: 0x%04x\n",(int)evt->data.evt_mesh_friend_friendship_terminated.lpn_address);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_friend_friendship_terminated.netkey_index);
    break;
  case gecko_evt_mesh_config_client_request_modified_id:
    dump_event_header("mesh_config_client_request_modified");
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_request_modified.handle);
    break;
  case gecko_evt_mesh_config_client_netkey_status_id:
    dump_event_header("mesh_config_client_netkey_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_netkey_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_netkey_status.handle);
    break;
  case gecko_evt_mesh_config_client_netkey_list_id:
    dump_event_header("mesh_config_client_netkey_list");
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_netkey_list.handle);
   printf("  uint8array  netkey_indices: %d:",(int)evt->data.evt_mesh_config_client_netkey_list.netkey_indices.len);
   for(int i = 0; i < evt->data.evt_mesh_config_client_netkey_list.netkey_indices.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_config_client_netkey_list.netkey_indices.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_config_client_netkey_list_end_id:
    dump_event_header("mesh_config_client_netkey_list_end");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_netkey_list_end.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_netkey_list_end.handle);
    break;
  case gecko_evt_mesh_config_client_appkey_status_id:
    dump_event_header("mesh_config_client_appkey_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_appkey_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_appkey_status.handle);
    break;
  case gecko_evt_mesh_config_client_appkey_list_id:
    dump_event_header("mesh_config_client_appkey_list");
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_appkey_list.handle);
   printf("  uint8array  appkey_indices: %d:",(int)evt->data.evt_mesh_config_client_appkey_list.appkey_indices.len);
   for(int i = 0; i < evt->data.evt_mesh_config_client_appkey_list.appkey_indices.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_config_client_appkey_list.appkey_indices.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_config_client_appkey_list_end_id:
    dump_event_header("mesh_config_client_appkey_list_end");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_appkey_list_end.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_appkey_list_end.handle);
    break;
  case gecko_evt_mesh_config_client_binding_status_id:
    dump_event_header("mesh_config_client_binding_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_binding_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_binding_status.handle);
    break;
  case gecko_evt_mesh_config_client_bindings_list_id:
    dump_event_header("mesh_config_client_bindings_list");
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_bindings_list.handle);
   printf("  uint8array  appkey_indices: %d:",(int)evt->data.evt_mesh_config_client_bindings_list.appkey_indices.len);
   for(int i = 0; i < evt->data.evt_mesh_config_client_bindings_list.appkey_indices.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_config_client_bindings_list.appkey_indices.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_config_client_bindings_list_end_id:
    dump_event_header("mesh_config_client_bindings_list_end");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_bindings_list_end.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_bindings_list_end.handle);
    break;
  case gecko_evt_mesh_config_client_model_pub_status_id:
    dump_event_header("mesh_config_client_model_pub_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_model_pub_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_model_pub_status.handle);
   printf("  uint16      address: 0x%04x\n",(int)evt->data.evt_mesh_config_client_model_pub_status.address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_config_client_model_pub_status.appkey_index);
   printf("  uint8       credentials: 0x%02x\n",(int)evt->data.evt_mesh_config_client_model_pub_status.credentials);
   printf("  uint8       ttl: 0x%02x\n",(int)evt->data.evt_mesh_config_client_model_pub_status.ttl);
   printf("  uint32      period_ms: 0x%08x\n",(int)evt->data.evt_mesh_config_client_model_pub_status.period_ms);
   printf("  uint8       retransmit_count: 0x%02x\n",(int)evt->data.evt_mesh_config_client_model_pub_status.retransmit_count);
   printf("  uint16      retransmit_interval_ms: 0x%04x\n",(int)evt->data.evt_mesh_config_client_model_pub_status.retransmit_interval_ms);
    break;
  case gecko_evt_mesh_config_client_model_sub_status_id:
    dump_event_header("mesh_config_client_model_sub_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_model_sub_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_model_sub_status.handle);
    break;
  case gecko_evt_mesh_config_client_subs_list_id:
    dump_event_header("mesh_config_client_subs_list");
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_subs_list.handle);
   printf("  uint8array  addresses: %d:",(int)evt->data.evt_mesh_config_client_subs_list.addresses.len);
   for(int i = 0; i < evt->data.evt_mesh_config_client_subs_list.addresses.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_config_client_subs_list.addresses.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_config_client_subs_list_end_id:
    dump_event_header("mesh_config_client_subs_list_end");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_subs_list_end.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_subs_list_end.handle);
    break;
  case gecko_evt_mesh_config_client_heartbeat_pub_status_id:
    dump_event_header("mesh_config_client_heartbeat_pub_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_heartbeat_pub_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_heartbeat_pub_status.handle);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_config_client_heartbeat_pub_status.destination_address);
   printf("  uint16      netkey_index: 0x%04x\n",(int)evt->data.evt_mesh_config_client_heartbeat_pub_status.netkey_index);
   printf("  uint8       count_log: 0x%02x\n",(int)evt->data.evt_mesh_config_client_heartbeat_pub_status.count_log);
   printf("  uint8       period_log: 0x%02x\n",(int)evt->data.evt_mesh_config_client_heartbeat_pub_status.period_log);
   printf("  uint8       ttl: 0x%02x\n",(int)evt->data.evt_mesh_config_client_heartbeat_pub_status.ttl);
   printf("  uint16      features: 0x%04x\n",(int)evt->data.evt_mesh_config_client_heartbeat_pub_status.features);
    break;
  case gecko_evt_mesh_config_client_heartbeat_sub_status_id:
    dump_event_header("mesh_config_client_heartbeat_sub_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_heartbeat_sub_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_heartbeat_sub_status.handle);
   printf("  uint16      source_address: 0x%04x\n",(int)evt->data.evt_mesh_config_client_heartbeat_sub_status.source_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_config_client_heartbeat_sub_status.destination_address);
   printf("  uint8       period_log: 0x%02x\n",(int)evt->data.evt_mesh_config_client_heartbeat_sub_status.period_log);
   printf("  uint8       count_log: 0x%02x\n",(int)evt->data.evt_mesh_config_client_heartbeat_sub_status.count_log);
   printf("  uint8       min_hops: 0x%02x\n",(int)evt->data.evt_mesh_config_client_heartbeat_sub_status.min_hops);
   printf("  uint8       max_hops: 0x%02x\n",(int)evt->data.evt_mesh_config_client_heartbeat_sub_status.max_hops);
    break;
  case gecko_evt_mesh_config_client_beacon_status_id:
    dump_event_header("mesh_config_client_beacon_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_beacon_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_beacon_status.handle);
   printf("  uint8       value: 0x%02x\n",(int)evt->data.evt_mesh_config_client_beacon_status.value);
    break;
  case gecko_evt_mesh_config_client_default_ttl_status_id:
    dump_event_header("mesh_config_client_default_ttl_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_default_ttl_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_default_ttl_status.handle);
   printf("  uint8       value: 0x%02x\n",(int)evt->data.evt_mesh_config_client_default_ttl_status.value);
    break;
  case gecko_evt_mesh_config_client_gatt_proxy_status_id:
    dump_event_header("mesh_config_client_gatt_proxy_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_gatt_proxy_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_gatt_proxy_status.handle);
   printf("  uint8       value: 0x%02x\n",(int)evt->data.evt_mesh_config_client_gatt_proxy_status.value);
    break;
  case gecko_evt_mesh_config_client_relay_status_id:
    dump_event_header("mesh_config_client_relay_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_relay_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_relay_status.handle);
   printf("  uint8       relay: 0x%02x\n",(int)evt->data.evt_mesh_config_client_relay_status.relay);
   printf("  uint8       retransmit_count: 0x%02x\n",(int)evt->data.evt_mesh_config_client_relay_status.retransmit_count);
   printf("  uint16      retransmit_interval_ms: 0x%04x\n",(int)evt->data.evt_mesh_config_client_relay_status.retransmit_interval_ms);
    break;
  case gecko_evt_mesh_config_client_network_transmit_status_id:
    dump_event_header("mesh_config_client_network_transmit_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_network_transmit_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_network_transmit_status.handle);
   printf("  uint8       transmit_count: 0x%02x\n",(int)evt->data.evt_mesh_config_client_network_transmit_status.transmit_count);
   printf("  uint16      transmit_interval_ms: 0x%04x\n",(int)evt->data.evt_mesh_config_client_network_transmit_status.transmit_interval_ms);
    break;
  case gecko_evt_mesh_config_client_identity_status_id:
    dump_event_header("mesh_config_client_identity_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_identity_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_identity_status.handle);
   printf("  uint8       value: 0x%02x\n",(int)evt->data.evt_mesh_config_client_identity_status.value);
    break;
  case gecko_evt_mesh_config_client_friend_status_id:
    dump_event_header("mesh_config_client_friend_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_friend_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_friend_status.handle);
   printf("  uint8       value: 0x%02x\n",(int)evt->data.evt_mesh_config_client_friend_status.value);
    break;
  case gecko_evt_mesh_config_client_lpn_polltimeout_status_id:
    dump_event_header("mesh_config_client_lpn_polltimeout_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_lpn_polltimeout_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_lpn_polltimeout_status.handle);
   printf("  uint32      poll_timeout_ms: 0x%08x\n",(int)evt->data.evt_mesh_config_client_lpn_polltimeout_status.poll_timeout_ms);
    break;
  case gecko_evt_mesh_config_client_dcd_data_id:
    dump_event_header("mesh_config_client_dcd_data");
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_dcd_data.handle);
   printf("  uint8       page: 0x%02x\n",(int)evt->data.evt_mesh_config_client_dcd_data.page);
   printf("  uint8array  data: %d:",(int)evt->data.evt_mesh_config_client_dcd_data.data.len);
   for(int i = 0; i < evt->data.evt_mesh_config_client_dcd_data.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_config_client_dcd_data.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_config_client_dcd_data_end_id:
    dump_event_header("mesh_config_client_dcd_data_end");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_dcd_data_end.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_dcd_data_end.handle);
    break;
  case gecko_evt_mesh_config_client_reset_status_id:
    dump_event_header("mesh_config_client_reset_status");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_mesh_config_client_reset_status.result);
   printf("  uint32      handle: 0x%08x\n",(int)evt->data.evt_mesh_config_client_reset_status.handle);
    break;
  case gecko_evt_l2cap_coc_connection_request_id:
    dump_event_header("l2cap_coc_connection_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_coc_connection_request.connection);
   printf("  uint16      le_psm: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_request.le_psm);
   printf("  uint16      source_cid: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_request.source_cid);
   printf("  uint16      mtu: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_request.mtu);
   printf("  uint16      mps: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_request.mps);
   printf("  uint16      initial_credit: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_request.initial_credit);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_l2cap_coc_connection_request.flags);
   printf("  uint8       encryption_key_size: 0x%02x\n",(int)evt->data.evt_l2cap_coc_connection_request.encryption_key_size);
    break;
  case gecko_evt_l2cap_coc_connection_response_id:
    dump_event_header("l2cap_coc_connection_response");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_coc_connection_response.connection);
   printf("  uint16      destination_cid: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_response.destination_cid);
   printf("  uint16      mtu: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_response.mtu);
   printf("  uint16      mps: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_response.mps);
   printf("  uint16      initial_credit: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_response.initial_credit);
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_response.result);
    break;
  case gecko_evt_l2cap_coc_le_flow_control_credit_id:
    dump_event_header("l2cap_coc_le_flow_control_credit");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_coc_le_flow_control_credit.connection);
   printf("  uint16      cid: 0x%04x\n",(int)evt->data.evt_l2cap_coc_le_flow_control_credit.cid);
   printf("  uint16      credits: 0x%04x\n",(int)evt->data.evt_l2cap_coc_le_flow_control_credit.credits);
    break;
  case gecko_evt_l2cap_coc_channel_disconnected_id:
    dump_event_header("l2cap_coc_channel_disconnected");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_coc_channel_disconnected.connection);
   printf("  uint16      cid: 0x%04x\n",(int)evt->data.evt_l2cap_coc_channel_disconnected.cid);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_l2cap_coc_channel_disconnected.reason);
    break;
  case gecko_evt_l2cap_coc_data_id:
    dump_event_header("l2cap_coc_data");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_coc_data.connection);
   printf("  uint16      cid: 0x%04x\n",(int)evt->data.evt_l2cap_coc_data.cid);
   printf("  uint8array  data: %d:",(int)evt->data.evt_l2cap_coc_data.data.len);
   for(int i = 0; i < evt->data.evt_l2cap_coc_data.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_l2cap_coc_data.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_l2cap_command_rejected_id:
    dump_event_header("l2cap_command_rejected");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_command_rejected.connection);
   printf("  uint8       code: 0x%02x\n",(int)evt->data.evt_l2cap_command_rejected.code);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_l2cap_command_rejected.reason);
    break;
  case gecko_evt_cte_receiver_iq_report_id:
    dump_event_header("cte_receiver_iq_report");
   printf("  uint16      status: 0x%04x\n",(int)evt->data.evt_cte_receiver_iq_report.status);
   printf("  uint8       packet_type: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.packet_type);
   printf("  uint8       handle: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.handle);
   printf("  uint8       phy: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.phy);
   printf("  uint8       channel: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.channel);
   printf("  int8        rssi: 0x%d\n",(int)evt->data.evt_cte_receiver_iq_report.rssi);
   printf("  uint8       rssi_antenna_id: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.rssi_antenna_id);
   printf("  uint8       cte_type: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.cte_type);
   printf("  uint8       slot_durations: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.slot_durations);
   printf("  uint16      event_counter: 0x%04x\n",(int)evt->data.evt_cte_receiver_iq_report.event_counter);
   printf("  uint8       completeness: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.completeness);
   printf("  uint8array  samples: %d:",(int)evt->data.evt_cte_receiver_iq_report.samples.len);
   for(int i = 0; i < evt->data.evt_cte_receiver_iq_report.samples.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_cte_receiver_iq_report.samples.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_server_get_request_id:
    dump_event_header("mesh_sensor_server_get_request");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_request.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_request.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_request.server_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_request.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_server_get_request.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_request.property_id);
    break;
  case gecko_evt_mesh_sensor_server_get_column_request_id:
    dump_event_header("mesh_sensor_server_get_column_request");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_column_request.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_column_request.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_column_request.server_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_column_request.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_server_get_column_request.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_column_request.property_id);
   printf("  uint8array  column_ids: %d:",(int)evt->data.evt_mesh_sensor_server_get_column_request.column_ids.len);
   for(int i = 0; i < evt->data.evt_mesh_sensor_server_get_column_request.column_ids.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_sensor_server_get_column_request.column_ids.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_server_get_series_request_id:
    dump_event_header("mesh_sensor_server_get_series_request");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_series_request.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_series_request.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_series_request.server_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_series_request.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_server_get_series_request.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_get_series_request.property_id);
   printf("  uint8array  column_ids: %d:",(int)evt->data.evt_mesh_sensor_server_get_series_request.column_ids.len);
   for(int i = 0; i < evt->data.evt_mesh_sensor_server_get_series_request.column_ids.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_sensor_server_get_series_request.column_ids.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_server_publish_id:
    dump_event_header("mesh_sensor_server_publish");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_server_publish.elem_index);
   printf("  uint32      period_ms: 0x%08x\n",(int)evt->data.evt_mesh_sensor_server_publish.period_ms);
    break;
  case gecko_evt_mesh_sensor_setup_server_get_cadence_request_id:
    dump_event_header("mesh_sensor_setup_server_get_cadence_request");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_cadence_request.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_cadence_request.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_cadence_request.server_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_cadence_request.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_cadence_request.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_cadence_request.property_id);
    break;
  case gecko_evt_mesh_sensor_setup_server_set_cadence_request_id:
    dump_event_header("mesh_sensor_setup_server_set_cadence_request");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_cadence_request.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_cadence_request.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_cadence_request.server_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_cadence_request.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_cadence_request.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_cadence_request.property_id);
   printf("  uint8       period_divisor: 0x%02x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_cadence_request.period_divisor);
   printf("  uint8       trigger_type: 0x%02x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_cadence_request.trigger_type);
   printf("  uint8array  params: %d:",(int)evt->data.evt_mesh_sensor_setup_server_set_cadence_request.params.len);
   for(int i = 0; i < evt->data.evt_mesh_sensor_setup_server_set_cadence_request.params.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_sensor_setup_server_set_cadence_request.params.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_setup_server_get_settings_request_id:
    dump_event_header("mesh_sensor_setup_server_get_settings_request");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_settings_request.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_settings_request.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_settings_request.server_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_settings_request.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_settings_request.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_settings_request.property_id);
    break;
  case gecko_evt_mesh_sensor_setup_server_get_setting_request_id:
    dump_event_header("mesh_sensor_setup_server_get_setting_request");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_setting_request.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_setting_request.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_setting_request.server_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_setting_request.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_setting_request.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_setting_request.property_id);
   printf("  uint16      setting_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_get_setting_request.setting_id);
    break;
  case gecko_evt_mesh_sensor_setup_server_set_setting_request_id:
    dump_event_header("mesh_sensor_setup_server_set_setting_request");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_setting_request.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_setting_request.client_address);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_setting_request.server_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_setting_request.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_setting_request.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_setting_request.property_id);
   printf("  uint16      setting_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_set_setting_request.setting_id);
   printf("  uint8array  raw_value: %d:",(int)evt->data.evt_mesh_sensor_setup_server_set_setting_request.raw_value.len);
   for(int i = 0; i < evt->data.evt_mesh_sensor_setup_server_set_setting_request.raw_value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_sensor_setup_server_set_setting_request.raw_value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_setup_server_publish_id:
    dump_event_header("mesh_sensor_setup_server_publish");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_setup_server_publish.elem_index);
   printf("  uint32      period_ms: 0x%08x\n",(int)evt->data.evt_mesh_sensor_setup_server_publish.period_ms);
    break;
  case gecko_evt_mesh_sensor_client_descriptor_status_id:
    dump_event_header("mesh_sensor_client_descriptor_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_descriptor_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_descriptor_status.server_address);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_descriptor_status.client_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_descriptor_status.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_client_descriptor_status.flags);
   printf("  uint8array  descriptors: %d:",(int)evt->data.evt_mesh_sensor_client_descriptor_status.descriptors.len);
   for(int i = 0; i < evt->data.evt_mesh_sensor_client_descriptor_status.descriptors.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_sensor_client_descriptor_status.descriptors.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_client_cadence_status_id:
    dump_event_header("mesh_sensor_client_cadence_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_cadence_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_cadence_status.server_address);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_cadence_status.client_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_cadence_status.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_client_cadence_status.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_cadence_status.property_id);
   printf("  uint8array  params: %d:",(int)evt->data.evt_mesh_sensor_client_cadence_status.params.len);
   for(int i = 0; i < evt->data.evt_mesh_sensor_client_cadence_status.params.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_sensor_client_cadence_status.params.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_client_settings_status_id:
    dump_event_header("mesh_sensor_client_settings_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_settings_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_settings_status.server_address);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_settings_status.client_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_settings_status.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_client_settings_status.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_settings_status.property_id);
   printf("  uint8array  setting_ids: %d:",(int)evt->data.evt_mesh_sensor_client_settings_status.setting_ids.len);
   for(int i = 0; i < evt->data.evt_mesh_sensor_client_settings_status.setting_ids.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_sensor_client_settings_status.setting_ids.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_client_setting_status_id:
    dump_event_header("mesh_sensor_client_setting_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_setting_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_setting_status.server_address);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_setting_status.client_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_setting_status.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_client_setting_status.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_setting_status.property_id);
   printf("  uint16      setting_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_setting_status.setting_id);
   printf("  uint8array  raw_value: %d:",(int)evt->data.evt_mesh_sensor_client_setting_status.raw_value.len);
   for(int i = 0; i < evt->data.evt_mesh_sensor_client_setting_status.raw_value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_sensor_client_setting_status.raw_value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_client_status_id:
    dump_event_header("mesh_sensor_client_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_status.server_address);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_status.client_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_status.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_client_status.flags);
   printf("  uint8array  sensor_data: %d:",(int)evt->data.evt_mesh_sensor_client_status.sensor_data.len);
   for(int i = 0; i < evt->data.evt_mesh_sensor_client_status.sensor_data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_sensor_client_status.sensor_data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_client_column_status_id:
    dump_event_header("mesh_sensor_client_column_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_column_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_column_status.server_address);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_column_status.client_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_column_status.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_client_column_status.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_column_status.property_id);
   printf("  uint8array  sensor_data: %d:",(int)evt->data.evt_mesh_sensor_client_column_status.sensor_data.len);
   for(int i = 0; i < evt->data.evt_mesh_sensor_client_column_status.sensor_data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_sensor_client_column_status.sensor_data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_client_series_status_id:
    dump_event_header("mesh_sensor_client_series_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_series_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_series_status.server_address);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_series_status.client_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_series_status.appkey_index);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_mesh_sensor_client_series_status.flags);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_series_status.property_id);
   printf("  uint8array  sensor_data: %d:",(int)evt->data.evt_mesh_sensor_client_series_status.sensor_data.len);
   for(int i = 0; i < evt->data.evt_mesh_sensor_client_series_status.sensor_data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_sensor_client_series_status.sensor_data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_sensor_client_publish_id:
    dump_event_header("mesh_sensor_client_publish");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_sensor_client_publish.elem_index);
   printf("  uint32      period_ms: 0x%08x\n",(int)evt->data.evt_mesh_sensor_client_publish.period_ms);
    break;
  case gecko_evt_mesh_lc_client_mode_status_id:
    dump_event_header("mesh_lc_client_mode_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_mode_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_mode_status.server_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_mode_status.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_mode_status.appkey_index);
   printf("  uint8       mode_status_value: 0x%02x\n",(int)evt->data.evt_mesh_lc_client_mode_status.mode_status_value);
    break;
  case gecko_evt_mesh_lc_client_om_status_id:
    dump_event_header("mesh_lc_client_om_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_om_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_om_status.server_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_om_status.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_om_status.appkey_index);
   printf("  uint8       om_status_value: 0x%02x\n",(int)evt->data.evt_mesh_lc_client_om_status.om_status_value);
    break;
  case gecko_evt_mesh_lc_client_light_onoff_status_id:
    dump_event_header("mesh_lc_client_light_onoff_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_light_onoff_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_light_onoff_status.server_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_light_onoff_status.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_light_onoff_status.appkey_index);
   printf("  uint8       present_light_onoff: 0x%02x\n",(int)evt->data.evt_mesh_lc_client_light_onoff_status.present_light_onoff);
   printf("  uint8       target_light_onoff: 0x%02x\n",(int)evt->data.evt_mesh_lc_client_light_onoff_status.target_light_onoff);
   printf("  uint32      remaining_time: 0x%08x\n",(int)evt->data.evt_mesh_lc_client_light_onoff_status.remaining_time);
    break;
  case gecko_evt_mesh_lc_client_property_status_id:
    dump_event_header("mesh_lc_client_property_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_property_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_property_status.server_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_property_status.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_property_status.appkey_index);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_lc_client_property_status.property_id);
   printf("  uint8array  property_value: %d:",(int)evt->data.evt_mesh_lc_client_property_status.property_value.len);
   for(int i = 0; i < evt->data.evt_mesh_lc_client_property_status.property_value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_lc_client_property_status.property_value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_lc_server_mode_updated_id:
    dump_event_header("mesh_lc_server_mode_updated");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_mode_updated.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_mode_updated.client_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_mode_updated.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_mode_updated.appkey_index);
   printf("  uint8       mode_value: 0x%02x\n",(int)evt->data.evt_mesh_lc_server_mode_updated.mode_value);
   printf("  uint8       manual_override: 0x%02x\n",(int)evt->data.evt_mesh_lc_server_mode_updated.manual_override);
    break;
  case gecko_evt_mesh_lc_server_om_updated_id:
    dump_event_header("mesh_lc_server_om_updated");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_om_updated.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_om_updated.client_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_om_updated.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_om_updated.appkey_index);
   printf("  uint8       om_value: 0x%02x\n",(int)evt->data.evt_mesh_lc_server_om_updated.om_value);
    break;
  case gecko_evt_mesh_lc_server_light_onoff_updated_id:
    dump_event_header("mesh_lc_server_light_onoff_updated");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_light_onoff_updated.elem_index);
   printf("  uint16      source_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_light_onoff_updated.source_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_light_onoff_updated.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_light_onoff_updated.appkey_index);
   printf("  uint8       onoff_state: 0x%02x\n",(int)evt->data.evt_mesh_lc_server_light_onoff_updated.onoff_state);
   printf("  uint32      onoff_trans_time: 0x%08x\n",(int)evt->data.evt_mesh_lc_server_light_onoff_updated.onoff_trans_time);
    break;
  case gecko_evt_mesh_lc_server_occupancy_updated_id:
    dump_event_header("mesh_lc_server_occupancy_updated");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_occupancy_updated.elem_index);
   printf("  uint16      source_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_occupancy_updated.source_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_occupancy_updated.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_occupancy_updated.appkey_index);
   printf("  uint8       occupancy_value: 0x%02x\n",(int)evt->data.evt_mesh_lc_server_occupancy_updated.occupancy_value);
    break;
  case gecko_evt_mesh_lc_server_ambient_lux_level_updated_id:
    dump_event_header("mesh_lc_server_ambient_lux_level_updated");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_ambient_lux_level_updated.elem_index);
   printf("  uint16      source_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_ambient_lux_level_updated.source_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_ambient_lux_level_updated.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_ambient_lux_level_updated.appkey_index);
   printf("  uint32      ambient_lux_level_value: 0x%08x\n",(int)evt->data.evt_mesh_lc_server_ambient_lux_level_updated.ambient_lux_level_value);
    break;
  case gecko_evt_mesh_lc_server_linear_output_updated_id:
    dump_event_header("mesh_lc_server_linear_output_updated");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_linear_output_updated.elem_index);
   printf("  uint16      linear_output_value: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_linear_output_updated.linear_output_value);
    break;
  case gecko_evt_mesh_lc_server_state_updated_id:
    dump_event_header("mesh_lc_server_state_updated");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_state_updated.elem_index);
   printf("  uint8       state: 0x%02x\n",(int)evt->data.evt_mesh_lc_server_state_updated.state);
   printf("  uint32      transition_time: 0x%08x\n",(int)evt->data.evt_mesh_lc_server_state_updated.transition_time);
    break;
  case gecko_evt_mesh_lc_server_regulator_debug_info_id:
    dump_event_header("mesh_lc_server_regulator_debug_info");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_regulator_debug_info.elem_index);
   printf("  uint16      i: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_regulator_debug_info.i);
   printf("  uint16      l: 0x%04x\n",(int)evt->data.evt_mesh_lc_server_regulator_debug_info.l);
    break;
  case gecko_evt_mesh_lc_setup_server_set_property_id:
    dump_event_header("mesh_lc_setup_server_set_property");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_setup_server_set_property.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_setup_server_set_property.client_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_lc_setup_server_set_property.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_lc_setup_server_set_property.appkey_index);
   printf("  uint16      property_id: 0x%04x\n",(int)evt->data.evt_mesh_lc_setup_server_set_property.property_id);
   printf("  uint8array  property_value: %d:",(int)evt->data.evt_mesh_lc_setup_server_set_property.property_value.len);
   for(int i = 0; i < evt->data.evt_mesh_lc_setup_server_set_property.property_value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_mesh_lc_setup_server_set_property.property_value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_scene_client_status_id:
    dump_event_header("mesh_scene_client_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_client_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_client_status.server_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_client_status.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_client_status.appkey_index);
   printf("  uint8       status: 0x%02x\n",(int)evt->data.evt_mesh_scene_client_status.status);
   printf("  uint16      current_scene: 0x%04x\n",(int)evt->data.evt_mesh_scene_client_status.current_scene);
   printf("  uint16      target_scene: 0x%04x\n",(int)evt->data.evt_mesh_scene_client_status.target_scene);
   printf("  uint32      remaining_time: 0x%08x\n",(int)evt->data.evt_mesh_scene_client_status.remaining_time);
    break;
  case gecko_evt_mesh_scene_client_register_status_id:
    dump_event_header("mesh_scene_client_register_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_client_register_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_client_register_status.server_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_client_register_status.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_client_register_status.appkey_index);
   printf("  uint8       status: 0x%02x\n",(int)evt->data.evt_mesh_scene_client_register_status.status);
   printf("  uint16      current_scene: 0x%04x\n",(int)evt->data.evt_mesh_scene_client_register_status.current_scene);
   printf("  uint16array scenes: %d:",(int)evt->data.evt_mesh_scene_client_register_status.scenes.len);
   for(int i = 0; i < evt->data.evt_mesh_scene_client_register_status.scenes.len; i++)
      printf("%s%04x",(i)?",":"{",evt->data.evt_mesh_scene_client_register_status.scenes.data[i]);
   printf("}\n");
    break;
  case gecko_evt_mesh_scene_server_get_id:
    dump_event_header("mesh_scene_server_get");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_get.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_get.client_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_get.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_get.appkey_index);
    break;
  case gecko_evt_mesh_scene_server_register_get_id:
    dump_event_header("mesh_scene_server_register_get");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_register_get.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_register_get.client_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_register_get.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_register_get.appkey_index);
    break;
  case gecko_evt_mesh_scene_server_recall_id:
    dump_event_header("mesh_scene_server_recall");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_recall.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_recall.client_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_recall.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_recall.appkey_index);
   printf("  uint16      selected_scene: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_recall.selected_scene);
   printf("  uint32      transition_time: 0x%08x\n",(int)evt->data.evt_mesh_scene_server_recall.transition_time);
    break;
  case gecko_evt_mesh_scene_server_publish_id:
    dump_event_header("mesh_scene_server_publish");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_server_publish.elem_index);
   printf("  uint32      period_ms: 0x%08x\n",(int)evt->data.evt_mesh_scene_server_publish.period_ms);
    break;
  case gecko_evt_mesh_scene_setup_server_store_id:
    dump_event_header("mesh_scene_setup_server_store");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_setup_server_store.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_setup_server_store.client_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_setup_server_store.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_setup_server_store.appkey_index);
   printf("  uint16      scene_id: 0x%04x\n",(int)evt->data.evt_mesh_scene_setup_server_store.scene_id);
    break;
  case gecko_evt_mesh_scene_setup_server_delete_id:
    dump_event_header("mesh_scene_setup_server_delete");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_setup_server_delete.elem_index);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_setup_server_delete.client_address);
   printf("  uint16      destination_address: 0x%04x\n",(int)evt->data.evt_mesh_scene_setup_server_delete.destination_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_setup_server_delete.appkey_index);
   printf("  uint16      scene_id: 0x%04x\n",(int)evt->data.evt_mesh_scene_setup_server_delete.scene_id);
    break;
  case gecko_evt_mesh_scene_setup_server_publish_id:
    dump_event_header("mesh_scene_setup_server_publish");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_scene_setup_server_publish.elem_index);
   printf("  uint32      period_ms: 0x%08x\n",(int)evt->data.evt_mesh_scene_setup_server_publish.period_ms);
    break;
  case gecko_evt_mesh_time_server_time_updated_id:
    dump_event_header("mesh_time_server_time_updated");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_time_server_time_updated.elem_index);
   printf("  uint8       subsecond: 0x%02x\n",(int)evt->data.evt_mesh_time_server_time_updated.subsecond);
   printf("  uint8       uncertainty: 0x%02x\n",(int)evt->data.evt_mesh_time_server_time_updated.uncertainty);
   printf("  uint8       time_authority: 0x%02x\n",(int)evt->data.evt_mesh_time_server_time_updated.time_authority);
   printf("  int32 tai_utc_delta: 0x%d\n",(int)evt->data.evt_mesh_time_server_time_updated.tai_utc_delta);
   printf("  int16 time_zone_offset: 0x%d\n",(int)evt->data.evt_mesh_time_server_time_updated.time_zone_offset);
    break;
  case gecko_evt_mesh_time_server_time_zone_offset_updated_id:
    dump_event_header("mesh_time_server_time_zone_offset_updated");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_time_server_time_zone_offset_updated.elem_index);
   printf("  int16 time_zone_offset_current: 0x%d\n",(int)evt->data.evt_mesh_time_server_time_zone_offset_updated.time_zone_offset_current);
   printf("  int16 time_zone_offset_new: 0x%d\n",(int)evt->data.evt_mesh_time_server_time_zone_offset_updated.time_zone_offset_new);
    break;
  case gecko_evt_mesh_time_server_tai_utc_delta_updated_id:
    dump_event_header("mesh_time_server_tai_utc_delta_updated");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_time_server_tai_utc_delta_updated.elem_index);
   printf("  int32 tai_utc_delta_current: 0x%d\n",(int)evt->data.evt_mesh_time_server_tai_utc_delta_updated.tai_utc_delta_current);
   printf("  int32 tai_utc_delta_new: 0x%d\n",(int)evt->data.evt_mesh_time_server_tai_utc_delta_updated.tai_utc_delta_new);
    break;
  case gecko_evt_mesh_time_server_time_role_updated_id:
    dump_event_header("mesh_time_server_time_role_updated");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_time_server_time_role_updated.elem_index);
   printf("  uint8       time_role: 0x%02x\n",(int)evt->data.evt_mesh_time_server_time_role_updated.time_role);
    break;
  case gecko_evt_mesh_time_client_time_status_id:
    dump_event_header("mesh_time_client_time_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_status.server_address);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_status.client_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_status.appkey_index);
   printf("  uint8       subsecond: 0x%02x\n",(int)evt->data.evt_mesh_time_client_time_status.subsecond);
   printf("  uint8       uncertainty: 0x%02x\n",(int)evt->data.evt_mesh_time_client_time_status.uncertainty);
   printf("  uint8       time_authority: 0x%02x\n",(int)evt->data.evt_mesh_time_client_time_status.time_authority);
   printf("  int32 tai_utc_delta: 0x%d\n",(int)evt->data.evt_mesh_time_client_time_status.tai_utc_delta);
   printf("  int16 time_zone_offset: 0x%d\n",(int)evt->data.evt_mesh_time_client_time_status.time_zone_offset);
    break;
  case gecko_evt_mesh_time_client_time_zone_status_id:
    dump_event_header("mesh_time_client_time_zone_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_zone_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_zone_status.server_address);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_zone_status.client_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_zone_status.appkey_index);
   printf("  int16 time_zone_offset_current: 0x%d\n",(int)evt->data.evt_mesh_time_client_time_zone_status.time_zone_offset_current);
   printf("  int16 time_zone_offset_new: 0x%d\n",(int)evt->data.evt_mesh_time_client_time_zone_status.time_zone_offset_new);
    break;
  case gecko_evt_mesh_time_client_tai_utc_delta_status_id:
    dump_event_header("mesh_time_client_tai_utc_delta_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_time_client_tai_utc_delta_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_time_client_tai_utc_delta_status.server_address);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_time_client_tai_utc_delta_status.client_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_time_client_tai_utc_delta_status.appkey_index);
   printf("  int32 tai_utc_delta_current: 0x%d\n",(int)evt->data.evt_mesh_time_client_tai_utc_delta_status.tai_utc_delta_current);
   printf("  int32 tai_utc_delta_new: 0x%d\n",(int)evt->data.evt_mesh_time_client_tai_utc_delta_status.tai_utc_delta_new);
    break;
  case gecko_evt_mesh_time_client_time_role_status_id:
    dump_event_header("mesh_time_client_time_role_status");
   printf("  uint16      elem_index: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_role_status.elem_index);
   printf("  uint16      server_address: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_role_status.server_address);
   printf("  uint16      client_address: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_role_status.client_address);
   printf("  uint16      appkey_index: 0x%04x\n",(int)evt->data.evt_mesh_time_client_time_role_status.appkey_index);
   printf("  uint8       time_role: 0x%02x\n",(int)evt->data.evt_mesh_time_client_time_role_status.time_role);
    break;
  case gecko_evt_user_message_to_host_id:
    dump_event_header("user_message_to_host");
   printf("  uint8array  data: %d:",(int)evt->data.evt_user_message_to_host.data.len);
   for(int i = 0; i < evt->data.evt_user_message_to_host.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_user_message_to_host.data.data[i]);
   printf("}\n");
    break;
  }
  dump_footer();
}
