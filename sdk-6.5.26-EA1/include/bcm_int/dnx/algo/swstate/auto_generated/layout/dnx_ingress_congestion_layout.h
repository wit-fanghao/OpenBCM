/** \file algo/swstate/auto_generated/layout/dnx_ingress_congestion_layout.h
 *
 * sw state layout enum
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

#ifndef __DNX_INGRESS_CONGESTION_LAYOUT_H__
#define __DNX_INGRESS_CONGESTION_LAYOUT_H__

#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int dnx_ingress_congestion_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(DNX_INGRESS_CONGESTION_MODULE_ID, 0),
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__VOQ_RATE_CLASS,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__GUARANTEED,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__PORT_BASED_VSQ,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__PG_NUMQ,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__ALGO_RES,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__VSQ_RATE_CLASS,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__VSQ_PG_TC_MAPPING,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__DRAM_THRESHOLDS,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__FADT_TAIL_DROP_THRESHOLDS,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__SYNC_MANAGER,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__VOQ_RATE_CLASS__REF_COUNT,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__VOQ_RATE_CLASS__IS_CREATED,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__GUARANTEED__VOQ_GUARANTEED,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__GUARANTEED__VSQ_GUARANTEED,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__PORT_BASED_VSQ__VSQ_E_MAPPING,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__PORT_BASED_VSQ__VSQ_F_MAPPING,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__PORT_BASED_VSQ__LOSSLESS_POOL_ID,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__PORT_BASED_VSQ__VSQ_E_MAPPING__SRC_PORT,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__PORT_BASED_VSQ__VSQ_F_MAPPING__SRC_PORT,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__ALGO_RES__VSQE_ID,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__ALGO_RES__VSQF_ID,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__VSQ_RATE_CLASS__VSQ_RATE_CLS_A_C,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__VSQ_RATE_CLASS__VSQ_RATE_CLS_D,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__VSQ_RATE_CLASS__VSQ_RATE_CLS_SOURCE_PORT,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__VSQ_RATE_CLASS__VSQ_RATE_CLS_PG,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__DRAM_THRESHOLDS__DRAM_BOUND_THRESHOLDS,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__DRAM_THRESHOLDS__DRAM_RECOVERY_FAIL_THRESHOLDS,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__DRAM_THRESHOLDS__DRAM_RECOVERY_THRESHOLD,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__FADT_TAIL_DROP_THRESHOLDS__RESOURCE,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__FADT_TAIL_DROP_THRESHOLDS__RESOURCE__DP,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__SYNC_MANAGER__DRAM_BOUND_MUTEX,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__SYNC_MANAGER__FADT_MUTEX,
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB__SYNC_MANAGER__DRAM_IN_USE,
    /*
     * Use DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX macro to get the number of parameters
     */
    DNX_SW_STATE_DNX_INGRESS_CONGESTION_DB_NOF_PARAMS,
} dnxc_sw_state_layout_dnx_ingress_congestion_node_id_e;

#endif /* __DNX_INGRESS_CONGESTION_LAYOUT_H__ */
