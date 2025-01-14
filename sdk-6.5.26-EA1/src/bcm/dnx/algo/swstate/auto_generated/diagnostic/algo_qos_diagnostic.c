/** \file algo/swstate/auto_generated/diagnostic/algo_qos_diagnostic.c
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

#include <bcm_int/dnx/algo/swstate/auto_generated/diagnostic/algo_qos_diagnostic.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/layout/algo_qos_layout.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
/*
 * Global Variables
 */

extern algo_qos_sw_state_t * algo_qos_db_data[SOC_MAX_NUM_DEVICES];
/*
 * FUNCTIONs
 */

/*
 *
 * dump function for the variable algo_qos_db
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(algo_qos_db_ingress_qos_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_ingress_qos_ecn_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_ingress_qos_phb_opcode_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_ingress_qos_remark_opcode_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_ingress_qos_ecn_opcode_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_ingress_qos_policer_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_ingress_qos_vlan_pcp_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_egress_qos_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_egress_qos_opcode_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_egress_qos_mpls_php_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_egress_qos_php_opcode_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_egress_qos_policer_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_egress_qos_oam_pcp_map_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_qos_egress_ttl_pipe_profile_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_qos_ingress_propagation_profile_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_qos_egress_network_qos_profile_dump(unit, filters));
    SHR_IF_ERR_EXIT(algo_qos_db_egress_cos_profile_dump(unit, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable ingress_qos
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_ingress_qos_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos ingress_qos") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos ingress_qos\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/ingress_qos.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->ingress_qos);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable ingress_qos_ecn
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_ingress_qos_ecn_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos ingress_qos_ecn") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos ingress_qos_ecn\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/ingress_qos_ecn.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_ecn: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_ecn: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->ingress_qos_ecn);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable ingress_qos_phb_opcode
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_ingress_qos_phb_opcode_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos ingress_qos_phb_opcode") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos ingress_qos_phb_opcode\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/ingress_qos_phb_opcode.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_phb_opcode: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_phb_opcode: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->ingress_qos_phb_opcode);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable ingress_qos_remark_opcode
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_ingress_qos_remark_opcode_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos ingress_qos_remark_opcode") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos ingress_qos_remark_opcode\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/ingress_qos_remark_opcode.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_remark_opcode: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_remark_opcode: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->ingress_qos_remark_opcode);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable ingress_qos_ecn_opcode
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_ingress_qos_ecn_opcode_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos ingress_qos_ecn_opcode") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos ingress_qos_ecn_opcode\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/ingress_qos_ecn_opcode.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_ecn_opcode: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_ecn_opcode: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->ingress_qos_ecn_opcode);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable ingress_qos_policer
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_ingress_qos_policer_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos ingress_qos_policer") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos ingress_qos_policer\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/ingress_qos_policer.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_policer: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_policer: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->ingress_qos_policer);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable ingress_qos_vlan_pcp
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_ingress_qos_vlan_pcp_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos ingress_qos_vlan_pcp") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos ingress_qos_vlan_pcp\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/ingress_qos_vlan_pcp.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_vlan_pcp: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","ingress_qos_vlan_pcp: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->ingress_qos_vlan_pcp);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable egress_qos
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_egress_qos_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos egress_qos") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos egress_qos\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/egress_qos.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->egress_qos);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable egress_qos_opcode
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_egress_qos_opcode_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos egress_qos_opcode") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos egress_qos_opcode\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/egress_qos_opcode.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos_opcode: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos_opcode: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->egress_qos_opcode);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable egress_qos_mpls_php
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_egress_qos_mpls_php_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos egress_qos_mpls_php") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos egress_qos_mpls_php\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/egress_qos_mpls_php.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos_mpls_php: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos_mpls_php: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->egress_qos_mpls_php);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable egress_qos_php_opcode
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_egress_qos_php_opcode_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos egress_qos_php_opcode") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos egress_qos_php_opcode\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/egress_qos_php_opcode.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos_php_opcode: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos_php_opcode: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->egress_qos_php_opcode);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable egress_qos_policer
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_egress_qos_policer_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos egress_qos_policer") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos egress_qos_policer\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/egress_qos_policer.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos_policer: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos_policer: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->egress_qos_policer);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable egress_qos_oam_pcp_map
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_egress_qos_oam_pcp_map_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos egress_qos_oam_pcp_map") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos egress_qos_oam_pcp_map\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/egress_qos_oam_pcp_map.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos_oam_pcp_map: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_qos_oam_pcp_map: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->egress_qos_oam_pcp_map);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable qos_egress_ttl_pipe_profile
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_qos_egress_ttl_pipe_profile_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_template_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos qos_egress_ttl_pipe_profile") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos qos_egress_ttl_pipe_profile\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/qos_egress_ttl_pipe_profile.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","qos_egress_ttl_pipe_profile: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","qos_egress_ttl_pipe_profile: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_TEMP_MNGR_PRINT(
            unit,
            ALGO_QOS_MODULE_ID,
            &((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->qos_egress_ttl_pipe_profile,
            dnx_algo_qos_egress_ttl_pipe_profile_template_print_cb);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable qos_ingress_propagation_profile
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_qos_ingress_propagation_profile_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_template_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos qos_ingress_propagation_profile") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos qos_ingress_propagation_profile\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/qos_ingress_propagation_profile.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","qos_ingress_propagation_profile: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","qos_ingress_propagation_profile: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_TEMP_MNGR_PRINT(
            unit,
            ALGO_QOS_MODULE_ID,
            &((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->qos_ingress_propagation_profile,
            dnx_algo_qos_propagation_profile_template_print_cb);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable qos_egress_network_qos_profile
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_qos_egress_network_qos_profile_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_template_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos qos_egress_network_qos_profile") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos qos_egress_network_qos_profile\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/qos_egress_network_qos_profile.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","qos_egress_network_qos_profile: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","qos_egress_network_qos_profile: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_TEMP_MNGR_PRINT(
            unit,
            ALGO_QOS_MODULE_ID,
            &((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->qos_egress_network_qos_profile,
            dnx_algo_qos_egress_network_qos_profile_template_print_cb);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable egress_cos_profile
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
algo_qos_db_egress_cos_profile_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_res_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "algo_qos egress_cos_profile") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate algo_qos egress_cos_profile\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "algo_qos_db/egress_cos_profile.txt",
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_cos_profile: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "algo_qos_db[%d]->","((algo_qos_sw_state_t*)sw_state_roots_array[%d][ALGO_QOS_MODULE_ID])->","egress_cos_profile: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        DNX_ALGO_RES_MNGR_PRINT(
            ALGO_QOS_MODULE_ID,
            ((algo_qos_sw_state_t*)sw_state_roots_array[unit][ALGO_QOS_MODULE_ID])->egress_cos_profile);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 * Global Variables
 */

dnx_sw_state_diagnostic_info_t algo_qos_db_info[SOC_MAX_NUM_DEVICES][ALGO_QOS_DB_INFO_NOF_ENTRIES];
const char* algo_qos_db_layout_str[ALGO_QOS_DB_INFO_NOF_ENTRIES] = {
    "ALGO_QOS_DB~",
    "ALGO_QOS_DB~INGRESS_QOS~",
    "ALGO_QOS_DB~INGRESS_QOS_ECN~",
    "ALGO_QOS_DB~INGRESS_QOS_PHB_OPCODE~",
    "ALGO_QOS_DB~INGRESS_QOS_REMARK_OPCODE~",
    "ALGO_QOS_DB~INGRESS_QOS_ECN_OPCODE~",
    "ALGO_QOS_DB~INGRESS_QOS_POLICER~",
    "ALGO_QOS_DB~INGRESS_QOS_VLAN_PCP~",
    "ALGO_QOS_DB~EGRESS_QOS~",
    "ALGO_QOS_DB~EGRESS_QOS_OPCODE~",
    "ALGO_QOS_DB~EGRESS_QOS_MPLS_PHP~",
    "ALGO_QOS_DB~EGRESS_QOS_PHP_OPCODE~",
    "ALGO_QOS_DB~EGRESS_QOS_POLICER~",
    "ALGO_QOS_DB~EGRESS_QOS_OAM_PCP_MAP~",
    "ALGO_QOS_DB~QOS_EGRESS_TTL_PIPE_PROFILE~",
    "ALGO_QOS_DB~QOS_INGRESS_PROPAGATION_PROFILE~",
    "ALGO_QOS_DB~QOS_EGRESS_NETWORK_QOS_PROFILE~",
    "ALGO_QOS_DB~EGRESS_COS_PROFILE~",
};
#endif /* DNX_SW_STATE_DIAGNOSTIC */
#undef BSL_LOG_MODULE
