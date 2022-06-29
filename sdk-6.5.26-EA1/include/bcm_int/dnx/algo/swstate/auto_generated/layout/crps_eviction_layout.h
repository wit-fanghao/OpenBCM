/** \file algo/swstate/auto_generated/layout/crps_eviction_layout.h
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

#ifndef __CRPS_EVICTION_LAYOUT_H__
#define __CRPS_EVICTION_LAYOUT_H__

#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int crps_eviction_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(CRPS_EVICTION_MODULE_ID, 0),
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__CACHE_LOCK,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__FIFO_LOCK,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__FIFO_CHANNELS,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__FIFO_RESULTS,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__BG_THREAD_DATA,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__FIFO_RESULTS__NOF_COUNTERS,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__FIFO_RESULTS__CNT_RESULT,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__FIFO_RESULTS__CNT_RESULT__CNT1,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__FIFO_RESULTS__CNT_RESULT__CNT2,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__FIFO_RESULTS__CNT_RESULT__COUNTER_ENTRY,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__FIFO_RESULTS__CNT_RESULT__ENGINE_ID,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__FIFO_RESULTS__CNT_RESULT__CORE_ID,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__FIFO_RESULTS__CNT_RESULT__FORMAT,
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB__BG_THREAD_DATA__CRPS_EVICTION_THREAD_HANDLER,
    /*
     * Use DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX macro to get the number of parameters
     */
    DNX_SW_STATE_DNX_CRPS_EVICTION_DB_NOF_PARAMS,
} dnxc_sw_state_layout_crps_eviction_node_id_e;

#endif /* __CRPS_EVICTION_LAYOUT_H__ */