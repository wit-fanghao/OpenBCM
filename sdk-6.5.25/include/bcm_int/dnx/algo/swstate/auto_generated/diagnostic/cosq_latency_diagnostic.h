/** \file algo/swstate/auto_generated/diagnostic/cosq_latency_diagnostic.h
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

#ifndef __DNX_COSQ_LATENCY_DIAGNOSTIC_H__
#define __DNX_COSQ_LATENCY_DIAGNOSTIC_H__

#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <soc/dnxc/swstate/dnx_sw_state_size.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/types/cosq_latency_types.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr_internal.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr_internal.h>
#include <bcm_int/dnx/cosq/latency/cosq_latency.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
typedef enum {
    DNX_COSQ_LATENCY_DB_INFO,
    DNX_COSQ_LATENCY_DB_INGRESS_LATENCY_RES_INFO,
    DNX_COSQ_LATENCY_DB_END_TO_END_LATENCY_RES_INFO,
    DNX_COSQ_LATENCY_DB_QUEUE_TEMPLATE_INFO,
    DNX_COSQ_LATENCY_DB_PROBABILITY_CONVERT_INFO,
    DNX_COSQ_LATENCY_DB_PROBABILITY_CONVERT_EXPONENT_B_INFO,
    DNX_COSQ_LATENCY_DB_PROBABILITY_CONVERT_COEFFICIENT_A_INFO,
    DNX_COSQ_LATENCY_DB_INFO_NOF_ENTRIES
} sw_state_dnx_cosq_latency_db_layout_e;


extern dnx_sw_state_diagnostic_info_t dnx_cosq_latency_db_info[SOC_MAX_NUM_DEVICES][DNX_COSQ_LATENCY_DB_INFO_NOF_ENTRIES];

extern const char* dnx_cosq_latency_db_layout_str[DNX_COSQ_LATENCY_DB_INFO_NOF_ENTRIES];
int dnx_cosq_latency_db_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_cosq_latency_db_ingress_latency_res_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_cosq_latency_db_end_to_end_latency_res_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_cosq_latency_db_queue_template_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_cosq_latency_db_probability_convert_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_cosq_latency_db_probability_convert_exponent_b_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_cosq_latency_db_probability_convert_coefficient_a_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

#endif /* DNX_SW_STATE_DIAGNOSTIC */

#endif /* __DNX_COSQ_LATENCY_DIAGNOSTIC_H__ */