/** \file algo/swstate/auto_generated/diagnostic/dnx_ingress_congestion_diagnostic.h
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
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __DNX_INGRESS_CONGESTION_DIAGNOSTIC_H__
#define __DNX_INGRESS_CONGESTION_DIAGNOSTIC_H__

#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <soc/dnxc/swstate/dnx_sw_state_size.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/types/dnx_ingress_congestion_types.h>
#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr_internal.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr_internal.h>
#include <bcm_int/dnx/cosq/cosq.h>
#include <bcm_int/dnx/cosq/ingress/ingress_congestion.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_ingr_congestion.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_port.h>
#include <soc/dnxc/swstate/types/sw_state_mutex.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
typedef enum {
    DNX_INGRESS_CONGESTION_DB_INFO,
    DNX_INGRESS_CONGESTION_DB_VOQ_RATE_CLASS_INFO,
    DNX_INGRESS_CONGESTION_DB_VOQ_RATE_CLASS_REF_COUNT_INFO,
    DNX_INGRESS_CONGESTION_DB_VOQ_RATE_CLASS_IS_CREATED_INFO,
    DNX_INGRESS_CONGESTION_DB_GUARANTEED_INFO,
    DNX_INGRESS_CONGESTION_DB_GUARANTEED_VOQ_GUARANTEED_INFO,
    DNX_INGRESS_CONGESTION_DB_GUARANTEED_VSQ_GUARANTEED_INFO,
    DNX_INGRESS_CONGESTION_DB_PORT_BASED_VSQ_INFO,
    DNX_INGRESS_CONGESTION_DB_PORT_BASED_VSQ_VSQ_E_MAPPING_INFO,
    DNX_INGRESS_CONGESTION_DB_PORT_BASED_VSQ_VSQ_E_MAPPING_SRC_PORT_INFO,
    DNX_INGRESS_CONGESTION_DB_PORT_BASED_VSQ_VSQ_F_MAPPING_INFO,
    DNX_INGRESS_CONGESTION_DB_PORT_BASED_VSQ_VSQ_F_MAPPING_SRC_PORT_INFO,
    DNX_INGRESS_CONGESTION_DB_PORT_BASED_VSQ_LOSSLESS_POOL_ID_INFO,
    DNX_INGRESS_CONGESTION_DB_PG_NUMQ_INFO,
    DNX_INGRESS_CONGESTION_DB_ALGO_RES_INFO,
    DNX_INGRESS_CONGESTION_DB_ALGO_RES_VSQE_ID_INFO,
    DNX_INGRESS_CONGESTION_DB_ALGO_RES_VSQF_ID_INFO,
    DNX_INGRESS_CONGESTION_DB_VSQ_RATE_CLASS_INFO,
    DNX_INGRESS_CONGESTION_DB_VSQ_RATE_CLASS_VSQ_RATE_CLS_A_C_INFO,
    DNX_INGRESS_CONGESTION_DB_VSQ_RATE_CLASS_VSQ_RATE_CLS_D_INFO,
    DNX_INGRESS_CONGESTION_DB_VSQ_RATE_CLASS_VSQ_RATE_CLS_SOURCE_PORT_INFO,
    DNX_INGRESS_CONGESTION_DB_VSQ_RATE_CLASS_VSQ_RATE_CLS_PG_INFO,
    DNX_INGRESS_CONGESTION_DB_VSQ_PG_TC_MAPPING_INFO,
    DNX_INGRESS_CONGESTION_DB_DRAM_THRESHOLDS_INFO,
    DNX_INGRESS_CONGESTION_DB_DRAM_THRESHOLDS_DRAM_BOUND_THRESHOLDS_INFO,
    DNX_INGRESS_CONGESTION_DB_DRAM_THRESHOLDS_DRAM_RECOVERY_FAIL_THRESHOLDS_INFO,
    DNX_INGRESS_CONGESTION_DB_DRAM_THRESHOLDS_DRAM_RECOVERY_THRESHOLD_INFO,
    DNX_INGRESS_CONGESTION_DB_FADT_TAIL_DROP_THRESHOLDS_INFO,
    DNX_INGRESS_CONGESTION_DB_FADT_TAIL_DROP_THRESHOLDS_RESOURCE_INFO,
    DNX_INGRESS_CONGESTION_DB_FADT_TAIL_DROP_THRESHOLDS_RESOURCE_DP_INFO,
    DNX_INGRESS_CONGESTION_DB_SYNC_MANAGER_INFO,
    DNX_INGRESS_CONGESTION_DB_SYNC_MANAGER_DRAM_BOUND_MUTEX_INFO,
    DNX_INGRESS_CONGESTION_DB_SYNC_MANAGER_FADT_MUTEX_INFO,
    DNX_INGRESS_CONGESTION_DB_SYNC_MANAGER_DRAM_IN_USE_INFO,
    DNX_INGRESS_CONGESTION_DB_INFO_NOF_ENTRIES
} sw_state_dnx_ingress_congestion_db_layout_e;


extern dnx_sw_state_diagnostic_info_t dnx_ingress_congestion_db_info[SOC_MAX_NUM_DEVICES][DNX_INGRESS_CONGESTION_DB_INFO_NOF_ENTRIES];

extern const char* dnx_ingress_congestion_db_layout_str[DNX_INGRESS_CONGESTION_DB_INFO_NOF_ENTRIES];
int dnx_ingress_congestion_db_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_voq_rate_class_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_voq_rate_class_ref_count_dump(
    int unit, int ref_count_idx_0, int ref_count_idx_1, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_voq_rate_class_is_created_dump(
    int unit, int is_created_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_guaranteed_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_guaranteed_voq_guaranteed_dump(
    int unit, int voq_guaranteed_idx_0, int voq_guaranteed_idx_1, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_guaranteed_vsq_guaranteed_dump(
    int unit, int vsq_guaranteed_idx_0, int vsq_guaranteed_idx_1, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_port_based_vsq_dump(
    int unit, int port_based_vsq_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_port_based_vsq_vsq_e_mapping_dump(
    int unit, int port_based_vsq_idx_0, int vsq_e_mapping_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_port_based_vsq_vsq_e_mapping_src_port_dump(
    int unit, int port_based_vsq_idx_0, int vsq_e_mapping_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_port_based_vsq_vsq_f_mapping_dump(
    int unit, int port_based_vsq_idx_0, int vsq_f_mapping_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_port_based_vsq_vsq_f_mapping_src_port_dump(
    int unit, int port_based_vsq_idx_0, int vsq_f_mapping_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_port_based_vsq_lossless_pool_id_dump(
    int unit, int port_based_vsq_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_pg_numq_dump(
    int unit, int pg_numq_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_algo_res_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_algo_res_vsqe_id_dump(
    int unit, int vsqe_id_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_algo_res_vsqf_id_dump(
    int unit, int vsqf_id_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_vsq_rate_class_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_vsq_rate_class_vsq_rate_cls_a_c_dump(
    int unit, int vsq_rate_cls_a_c_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_vsq_rate_class_vsq_rate_cls_d_dump(
    int unit, int vsq_rate_cls_d_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_vsq_rate_class_vsq_rate_cls_source_port_dump(
    int unit, int vsq_rate_cls_source_port_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_vsq_rate_class_vsq_rate_cls_pg_dump(
    int unit, int vsq_rate_cls_pg_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_vsq_pg_tc_mapping_dump(
    int unit, int vsq_pg_tc_mapping_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_dram_thresholds_dump(
    int unit, int dram_thresholds_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_dram_thresholds_dram_bound_thresholds_dump(
    int unit, int dram_thresholds_idx_0, int dram_bound_thresholds_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_dram_thresholds_dram_recovery_fail_thresholds_dump(
    int unit, int dram_thresholds_idx_0, int dram_recovery_fail_thresholds_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_dram_thresholds_dram_recovery_threshold_dump(
    int unit, int dram_thresholds_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_fadt_tail_drop_thresholds_dump(
    int unit, int fadt_tail_drop_thresholds_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_fadt_tail_drop_thresholds_resource_dump(
    int unit, int fadt_tail_drop_thresholds_idx_0, int resource_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_fadt_tail_drop_thresholds_resource_dp_dump(
    int unit, int fadt_tail_drop_thresholds_idx_0, int resource_idx_0, int dp_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_sync_manager_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_sync_manager_dram_bound_mutex_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_sync_manager_fadt_mutex_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_ingress_congestion_db_sync_manager_dram_in_use_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

#endif /* DNX_SW_STATE_DIAGNOSTIC */

#endif /* __DNX_INGRESS_CONGESTION_DIAGNOSTIC_H__ */
