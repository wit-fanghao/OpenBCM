/** \file algo/swstate/auto_generated/diagnostic/algo_tdm_diagnostic.c
 *
 * sw state functions definitions
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

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <bcm_int/dnx/algo/swstate/auto_generated/diagnostic/algo_tdm_diagnostic.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/layout/algo_tdm_layout.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
/*
 * Global Variables
 */

extern algo_tdm_sw_state_t * algo_tdm_db_data[SOC_MAX_NUM_DEVICES];
/*
 * FUNCTIONs
 */

/*
 *
 * dump function for the variable algo_tdm_db
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_tdm_db_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(algo_tdm_db_ingress_context_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_tdm_db_link_mask_dump(unit, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable ingress_context
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_tdm_db_ingress_context_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_tdm ingress_context") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_tdm ingress_context\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_tdm_db/ingress_context.txt",
            "algo_tdm_db[%d]->","((algo_tdm_sw_state_t*)sw_state_roots_array[%d][ALGO_TDM_MODULE_ID])->","ingress_context: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_tdm_sw_state_t*)sw_state_roots_array[unit][ALGO_TDM_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_tdm_db[%d]->","((algo_tdm_sw_state_t*)sw_state_roots_array[%d][ALGO_TDM_MODULE_ID])->","ingress_context: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_TDM_MODULE_ID,
            ((algo_tdm_sw_state_t*)sw_state_roots_array[unit][ALGO_TDM_MODULE_ID])->ingress_context);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable link_mask
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_tdm_db_link_mask_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_template_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_tdm link_mask") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_tdm link_mask\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_tdm_db/link_mask.txt",
            "algo_tdm_db[%d]->","((algo_tdm_sw_state_t*)sw_state_roots_array[%d][ALGO_TDM_MODULE_ID])->","link_mask: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_tdm_sw_state_t*)sw_state_roots_array[unit][ALGO_TDM_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_tdm_db[%d]->","((algo_tdm_sw_state_t*)sw_state_roots_array[%d][ALGO_TDM_MODULE_ID])->","link_mask: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_TEMP_MNGR_PRINT(
            unit,
            ALGO_TDM_MODULE_ID,
            &((algo_tdm_sw_state_t*)sw_state_roots_array[unit][ALGO_TDM_MODULE_ID])->link_mask,
            dnx_tdm_link_mask_print_cb);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 * Global Variables
 */

dnx_sw_state_diagnostic_info_t algo_tdm_db_info[SOC_MAX_NUM_DEVICES][ALGO_TDM_DB_INFO_NOF_ENTRIES];
const char* algo_tdm_db_layout_str[ALGO_TDM_DB_INFO_NOF_ENTRIES] = {
    "ALGO_TDM_DB~",
    "ALGO_TDM_DB~INGRESS_CONTEXT~",
    "ALGO_TDM_DB~LINK_MASK~",
};
#endif /* DNX_SW_STATE_DIAGNOSTIC */
#undef BSL_LOG_MODULE