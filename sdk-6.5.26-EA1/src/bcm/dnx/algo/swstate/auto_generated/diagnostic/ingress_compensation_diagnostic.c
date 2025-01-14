/** \file algo/swstate/auto_generated/diagnostic/ingress_compensation_diagnostic.c
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

#include <bcm_int/dnx/algo/swstate/auto_generated/diagnostic/ingress_compensation_diagnostic.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/layout/ingress_compensation_layout.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
/*
 * Global Variables
 */

extern dnx_ingress_compensation_db_t * dnx_ingress_compensation_db_data[SOC_MAX_NUM_DEVICES];
/*
 * FUNCTIONs
 */

/*
 *
 * dump function for the variable dnx_ingress_compensation_db
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
dnx_ingress_compensation_db_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_ingress_compensation_db_compensation_dump(unit, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable compensation
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
dnx_ingress_compensation_db_compensation_dump(int  unit,  int  compensation_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = compensation_idx_0, I0 = compensation_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_template_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "ingress_compensation compensation") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate ingress_compensation compensation\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_ingress_compensation_db/compensation.txt",
            "dnx_ingress_compensation_db[%d]->","((dnx_ingress_compensation_db_t*)sw_state_roots_array[%d][INGRESS_COMPENSATION_MODULE_ID])->","compensation[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_ingress_compensation_db_t*)sw_state_roots_array[unit][INGRESS_COMPENSATION_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_ingress_compensation_db_t*)sw_state_roots_array[unit][INGRESS_COMPENSATION_MODULE_ID])->compensation);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_INGRESS_COMPENSATION_DB__COMPENSATION,
                ((dnx_ingress_compensation_db_t*)sw_state_roots_array[unit][INGRESS_COMPENSATION_MODULE_ID])->compensation);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_ingress_compensation_db_t*)sw_state_roots_array[unit][INGRESS_COMPENSATION_MODULE_ID])->compensation
                , sizeof(*((dnx_ingress_compensation_db_t*)sw_state_roots_array[unit][INGRESS_COMPENSATION_MODULE_ID])->compensation), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_INGRESS_COMPENSATION_DB__COMPENSATION, ((dnx_ingress_compensation_db_t*)sw_state_roots_array[unit][INGRESS_COMPENSATION_MODULE_ID])->compensation))
        {
            LOG_CLI((BSL_META("dnx_ingress_compensation_db[]->((dnx_ingress_compensation_db_t*)sw_state_roots_array[][INGRESS_COMPENSATION_MODULE_ID])->compensation[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_INGRESS_COMPENSATION_DB__COMPENSATION, ((dnx_ingress_compensation_db_t*)sw_state_roots_array[unit][INGRESS_COMPENSATION_MODULE_ID])->compensation) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_ingress_compensation_db[%d]->","((dnx_ingress_compensation_db_t*)sw_state_roots_array[%d][INGRESS_COMPENSATION_MODULE_ID])->","compensation[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            DNX_ALGO_TEMP_MNGR_PRINT(
                unit,
                INGRESS_COMPENSATION_MODULE_ID,
                &((dnx_ingress_compensation_db_t*)sw_state_roots_array[unit][INGRESS_COMPENSATION_MODULE_ID])->compensation[i0],
                dnx_cosq_ingress_compensation_profile_print_cb);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 * Global Variables
 */

dnx_sw_state_diagnostic_info_t dnx_ingress_compensation_db_info[SOC_MAX_NUM_DEVICES][DNX_INGRESS_COMPENSATION_DB_INFO_NOF_ENTRIES];
const char* dnx_ingress_compensation_db_layout_str[DNX_INGRESS_COMPENSATION_DB_INFO_NOF_ENTRIES] = {
    "DNX_INGRESS_COMPENSATION_DB~",
    "DNX_INGRESS_COMPENSATION_DB~COMPENSATION~",
};
#endif /* DNX_SW_STATE_DIAGNOSTIC */
#undef BSL_LOG_MODULE
