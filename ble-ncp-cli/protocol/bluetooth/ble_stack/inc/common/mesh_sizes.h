#ifndef _MESH_SIZES_H
#define _MESH_SIZES_H
/******************************************************************************
 *
 * @file   mesh_sizes.h
 * @brief  BLE Mesh memory configuration sizes
 *
 *  Autogenerated file, do not edit
 *
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
// *INDENT-OFF*

#ifdef __cplusplus
extern "C" {
#endif

#include "mesh_app_memory_config.h"

#define MESH_MEMSIZE_ELEMENT                        10
#define MESH_MEMSIZE_MODEL_BASE                     68
#define MESH_MEMSIZE_MODEL_PER_APP_BINDING          2
#define MESH_MEMSIZE_MODEL_PER_SUBSCRIPTION         3
#define MESH_MEMSIZE_NETKEY                         110
#define MESH_MEMSIZE_APPKEY                         38
#define MESH_MEMSIZE_DEVKEY                         37
#define MESH_MEMSIZE_FRIENDSHIP                     78
#define MESH_MEMSIZE_FRIEND_QUEUE_ENTRY             28
#define MESH_MEMSIZE_FRIEND_CACHE_ENTRY             191
#define MESH_MEMSIZE_FRIEND_TIMERS                  32
#define MESH_MEMSIZE_FRIEND_SUBS_LIST_ENTRY         2
#define MESH_MEMSIZE_NET_CACHE_ENTRY                8
#define MESH_MEMSIZE_RPL_ENTRY                      16
#define MESH_MEMSIZE_SEG_SEND                       72
#define MESH_MEMSIZE_SEG_RECV                       56
#define MESH_MEMSIZE_VA                             17
#define MESH_MEMSIZE_PROV_SESSION                   576
#define MESH_MEMSIZE_PROV_BEARER                    40
#define MESH_MEMSIZE_PB_ADV                         21
#define MESH_MEMSIZE_GATT_CONNECTION                40
#define MESH_MEMSIZE_GATT_TXQ_ENTRY                 28
#define MESH_MEMSIZE_MESH_BEARER                    6
#define MESH_MEMSIZE_FOUNDATION_CMD                 64
#define MESH_MEMSIZE_PRV_DDB_ENTRY_BASE             42
#define MESH_MEMSIZE_PRV_DDB_ENTRY_PER_NODE_NETKEY  4
#define MESH_MEMSIZE_PRV_DDB_ENTRY_PER_NODE_APPKEY  8
#define MESH_MEMSIZE_LC_CLIENT                      4
#define MESH_MEMSIZE_LC_SERVER                      368
#define MESH_MEMSIZE_LC_SETUPSERVER                 8
#define MESH_MEMSIZE_SCENE_CLIENT                   4
#define MESH_MEMSIZE_SCENE_SERVER                   368
#define MESH_MEMSIZE_SCENE_SETUP_SERVER             8

#define BTMESH_HEAP_SIZE \
  (MESH_MEMSIZE_MESH_BEARER + \
  MESH_CFG_MAX_ELEMENTS * MESH_MEMSIZE_ELEMENT + \
  MESH_CFG_MAX_MODELS * (MESH_MEMSIZE_MODEL_BASE + \
                      MESH_CFG_MAX_APP_BINDS * MESH_MEMSIZE_MODEL_PER_APP_BINDING + \
                      MESH_CFG_MAX_SUBSCRIPTIONS * MESH_MEMSIZE_MODEL_PER_SUBSCRIPTION) + \
  MESH_CFG_MAX_NETKEYS * MESH_MEMSIZE_NETKEY + \
  MESH_CFG_MAX_APPKEYS * MESH_MEMSIZE_APPKEY + \
  1 * MESH_MEMSIZE_DEVKEY + \
  MESH_CFG_MAX_FRIENDSHIPS * MESH_MEMSIZE_FRIENDSHIP + \
  MESH_CFG_NET_CACHE_SIZE * MESH_MEMSIZE_NET_CACHE_ENTRY + \
  MESH_CFG_RPL_SIZE * MESH_MEMSIZE_RPL_ENTRY + \
  MESH_CFG_MAX_SEND_SEGS * MESH_MEMSIZE_SEG_SEND + \
  MESH_CFG_MAX_RECV_SEGS * MESH_MEMSIZE_SEG_RECV + \
  MESH_CFG_MAX_VAS * MESH_MEMSIZE_VA + \
  MESH_CFG_MAX_PROV_SESSIONS * (MESH_MEMSIZE_PROV_SESSION + MESH_MEMSIZE_PB_ADV) + \
  MESH_CFG_MAX_PROV_BEARERS * MESH_MEMSIZE_PROV_BEARER + \
  MESH_CFG_MAX_GATT_CONNECTIONS * (MESH_MEMSIZE_GATT_CONNECTION + MESH_MEMSIZE_MESH_BEARER) + \
  MESH_CFG_GATT_TXQ_SIZE * MESH_MEMSIZE_GATT_TXQ_ENTRY + \
  MESH_CFG_MAX_PROVISIONED_DEVICES * (MESH_MEMSIZE_PRV_DDB_ENTRY_BASE + \
                                       MESH_CFG_MAX_PROVISIONED_DEVICE_NETKEYS * MESH_MEMSIZE_PRV_DDB_ENTRY_PER_NODE_NETKEY + \
                                       MESH_CFG_MAX_PROVISIONED_DEVICE_APPKEYS * MESH_MEMSIZE_PRV_DDB_ENTRY_PER_NODE_APPKEY) + \
  MESH_CFG_MAX_FOUNDATION_CLIENT_CMDS * MESH_MEMSIZE_FOUNDATION_CMD + \
  MESH_MEMSIZE_LC_CLIENT + MESH_MEMSIZE_LC_SERVER + MESH_MEMSIZE_LC_SERVER +\
  MESH_MEMSIZE_SCENE_CLIENT + MESH_MEMSIZE_SCENE_SERVER + MESH_MEMSIZE_SCENE_SETUP_SERVER +\
  MESH_CFG_FRIEND_MAX_SUBS_LIST * MESH_MEMSIZE_FRIEND_SUBS_LIST_ENTRY * MESH_CFG_MAX_FRIENDSHIPS + \
  MESH_MEMSIZE_FRIEND_TIMERS * MESH_CFG_MAX_FRIENDSHIPS +\
  MESH_CFG_FRIEND_MAX_TOTAL_CACHE * MESH_MEMSIZE_FRIEND_QUEUE_ENTRY +\
  MESH_CFG_FRIEND_MAX_TOTAL_CACHE * MESH_MEMSIZE_FRIEND_CACHE_ENTRY)

#ifdef __cplusplus
}
#endif
// *INDENT-ON*
#endif
