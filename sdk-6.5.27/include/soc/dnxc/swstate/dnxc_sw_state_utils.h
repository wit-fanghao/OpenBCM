/*
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNXC_SW_STATE_UTILS_H
#define _DNXC_SW_STATE_UTILS_H
#define BYTES_TO_MBS(bytes)  bytes/1048576
#define BYTES_TO_MBS_CARRY(bytes)  bytes%1048576
#define BYTES_TO_KBS(bytes) bytes/1024
#define BYTES_TO_KBS_CARRY(bytes) bytes%1024

#include <bcm/types.h>
#include <soc/types.h>

uint8 sw_state_is_flag_on(
    uint32 flags,
    uint32 flag);

uint8 sw_state_is_syncing(
    int unit);

int sw_state_is_warm_boot(
    int unit);

int sw_state_is_detaching(
    int unit);

int sw_state_is_done_init(
    int unit);

uint8 dnxc_sw_state_alloc_during_sync_set(
    int unit,
    uint8 flag);

uint8 dnxc_sw_state_alloc_during_test_set(
    int unit,
    uint8 flag);

uint8 dnxc_sw_state_alloc_during_test_get(
    int unit);

void dnxc_sw_state_is_warmboot_supported_set(
    int unit,
    uint8 value);

uint8 dnxc_sw_state_is_warmboot_supported_get(
    int unit);

uint8 dnxc_sw_state_is_auto_sync_supported_get(
    int unit);

int dnxc_sw_state_skip_alloc_mode_set(
    int unit,
    uint8 on_off);

int dnxc_sw_state_skip_alloc_mode_get(
    int unit,
    uint8 *on_off);

#if defined(DNX_SW_STATE_DIAGNOSTIC)
uint8 is_prefix(
    const char *pre,
    const char *str);

#endif
#endif
