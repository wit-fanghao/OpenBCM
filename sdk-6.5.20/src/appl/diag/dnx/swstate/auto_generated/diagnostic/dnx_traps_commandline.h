/** \file dnx/swstate/auto_generated/diagnostic/dnx_traps_commandline.h
 *
 * sw state functions declarations
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#ifndef __DNX_TRAPS_COMMANDLINE_H__
#define __DNX_TRAPS_COMMANDLINE_H__

#include <appl/diag/sand/diag_sand_framework.h>
#include <appl/diag/sand/diag_sand_utils.h>
#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <soc/dnx/swstate/auto_generated/types/dnx_traps_types.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
shr_error_e sh_dnx_swstate_dnx_traps_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_traps_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_traps_dump_man;
shr_error_e sh_dnx_swstate_dnx_traps_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_traps_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_traps_size_get_man;
shr_error_e sh_dnx_swstate_dnx_traps_diagnostic_operation_counters_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_traps_diagnostic_operation_counters_options[];
extern sh_sand_man_t dnx_swstate_dnx_traps_diagnostic_operation_counters_man;
extern sh_sand_cmd_t sh_dnx_swstate_dnx_traps_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_traps_man;
extern const char cmd_dnx_swstate_dnx_traps_desc[];

extern sh_sand_cmd_t sh_dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_man;
extern const char cmd_dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_desc[];
shr_error_e sh_dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_dump_man;


shr_error_e sh_dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_size_get_man;


shr_error_e sh_dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_diagnostic_operation_counters_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_diagnostic_operation_counters_options[];
extern sh_sand_man_t dnx_swstate_dnx_traps_etpp_keep_fabric_headers_profile_diagnostic_operation_counters_man;


#endif /* DNX_SW_STATE_DIAGNOSTIC */

#endif /* __DNX_TRAPS_COMMANDLINE_H__ */