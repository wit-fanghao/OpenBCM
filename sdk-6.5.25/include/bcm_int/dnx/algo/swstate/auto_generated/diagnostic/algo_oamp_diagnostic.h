/** \file algo/swstate/auto_generated/diagnostic/algo_oamp_diagnostic.h
 *
 * sw state functions declarations
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2021 Broadcom Inc. All rights reserved.
 */

#ifndef __DNX_ALGO_OAMP_DIAGNOSTIC_H__
#define __DNX_ALGO_OAMP_DIAGNOSTIC_H__

#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <soc/dnxc/swstate/dnx_sw_state_size.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/types/algo_oamp_types.h>
#include <bcm_int/dnx/algo/oamp/algo_oamp.h>
#include <bcm_int/dnx/algo/oamp/algo_oamp_v1.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr_internal.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr_internal.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
typedef enum {
    ALGO_OAMP_DB_INFO,
#ifdef BCM_DNX2_SUPPORT
    ALGO_OAMP_DB_OAMP_2B_MAID_FULL_MEP_ID_INFO,
#endif /*BCM_DNX2_SUPPORT*/
#ifdef BCM_DNX2_SUPPORT
    ALGO_OAMP_DB_OAMP_2B_MAID_SHORT_MEP_ID_INFO,
#endif /*BCM_DNX2_SUPPORT*/
#ifdef BCM_DNX2_SUPPORT
    ALGO_OAMP_DB_OAMP_ICC_MAID_FULL_MEP_ID_INFO,
#endif /*BCM_DNX2_SUPPORT*/
#ifdef BCM_DNX2_SUPPORT
    ALGO_OAMP_DB_OAMP_ICC_MAID_SHORT_MEP_ID_INFO,
#endif /*BCM_DNX2_SUPPORT*/
#ifdef BCM_DNX2_SUPPORT
    ALGO_OAMP_DB_OAMP_EXTRA_MEP_ID_INFO,
#endif /*BCM_DNX2_SUPPORT*/
#ifdef BCM_DNX2_SUPPORT
    ALGO_OAMP_DB_NOF_OAMP_FULL_TUPLES_MEP_ID_BANKS_INFO,
#endif /*BCM_DNX2_SUPPORT*/
#ifdef BCM_DNX2_SUPPORT
    ALGO_OAMP_DB_OAMP_FULL_TUPLES_MEP_ID_INFO,
#endif /*BCM_DNX2_SUPPORT*/
#ifdef BCM_DNX2_SUPPORT
    ALGO_OAMP_DB_OAMP_V1_MEP_DB_ENTRY_INFO,
#endif /*BCM_DNX2_SUPPORT*/
#ifdef BCM_DNX2_SUPPORT
    ALGO_OAMP_DB_OAMP_V1_GENERIC_MEMORY_ENTRY_INFO,
#endif /*BCM_DNX2_SUPPORT*/
#ifdef BCM_DNX2_SUPPORT
    ALGO_OAMP_DB_OAMP_V1_PP_PORT_2_SYS_PORT_INFO,
#endif /*BCM_DNX2_SUPPORT*/
    ALGO_OAMP_DB_OAMP_PUNT_GOOD_PROFILE_INFO,
    ALGO_OAMP_DB_INFO_NOF_ENTRIES
} sw_state_algo_oamp_db_layout_e;


extern dnx_sw_state_diagnostic_info_t algo_oamp_db_info[SOC_MAX_NUM_DEVICES][ALGO_OAMP_DB_INFO_NOF_ENTRIES];

extern const char* algo_oamp_db_layout_str[ALGO_OAMP_DB_INFO_NOF_ENTRIES];
int algo_oamp_db_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

#ifdef BCM_DNX2_SUPPORT
int algo_oamp_db_oamp_2b_maid_full_mep_id_dump(
    int unit, dnx_sw_state_dump_filters_t filters);
#endif /*BCM_DNX2_SUPPORT*/

#ifdef BCM_DNX2_SUPPORT
int algo_oamp_db_oamp_2b_maid_short_mep_id_dump(
    int unit, dnx_sw_state_dump_filters_t filters);
#endif /*BCM_DNX2_SUPPORT*/

#ifdef BCM_DNX2_SUPPORT
int algo_oamp_db_oamp_icc_maid_full_mep_id_dump(
    int unit, dnx_sw_state_dump_filters_t filters);
#endif /*BCM_DNX2_SUPPORT*/

#ifdef BCM_DNX2_SUPPORT
int algo_oamp_db_oamp_icc_maid_short_mep_id_dump(
    int unit, dnx_sw_state_dump_filters_t filters);
#endif /*BCM_DNX2_SUPPORT*/

#ifdef BCM_DNX2_SUPPORT
int algo_oamp_db_oamp_extra_mep_id_dump(
    int unit, dnx_sw_state_dump_filters_t filters);
#endif /*BCM_DNX2_SUPPORT*/

#ifdef BCM_DNX2_SUPPORT
int algo_oamp_db_nof_oamp_full_tuples_mep_id_banks_dump(
    int unit, dnx_sw_state_dump_filters_t filters);
#endif /*BCM_DNX2_SUPPORT*/

#ifdef BCM_DNX2_SUPPORT
int algo_oamp_db_oamp_full_tuples_mep_id_dump(
    int unit, int oamp_full_tuples_mep_id_idx_0, dnx_sw_state_dump_filters_t filters);
#endif /*BCM_DNX2_SUPPORT*/

#ifdef BCM_DNX2_SUPPORT
int algo_oamp_db_oamp_v1_mep_db_entry_dump(
    int unit, dnx_sw_state_dump_filters_t filters);
#endif /*BCM_DNX2_SUPPORT*/

#ifdef BCM_DNX2_SUPPORT
int algo_oamp_db_oamp_v1_generic_memory_entry_dump(
    int unit, dnx_sw_state_dump_filters_t filters);
#endif /*BCM_DNX2_SUPPORT*/

#ifdef BCM_DNX2_SUPPORT
int algo_oamp_db_oamp_v1_pp_port_2_sys_port_dump(
    int unit, dnx_sw_state_dump_filters_t filters);
#endif /*BCM_DNX2_SUPPORT*/

int algo_oamp_db_oamp_punt_good_profile_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

#endif /* DNX_SW_STATE_DIAGNOSTIC */

#endif /* __DNX_ALGO_OAMP_DIAGNOSTIC_H__ */