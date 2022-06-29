/** \file dnx/swstate/auto_generated/diagnostic/algo_lif_profile_commandline.h
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

#ifndef __DNX_ALGO_LIF_PROFILE_COMMANDLINE_H__
#define __DNX_ALGO_LIF_PROFILE_COMMANDLINE_H__

#include <appl/diag/sand/diag_sand_framework.h>
#include <appl/diag/sand/diag_sand_utils.h>
#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/types/algo_lif_profile_types.h>
#include <bcm_int/dnx/algo/lif_mngr/algo_in_lif_profile.h>
#include <bcm_int/dnx/algo/lif_mngr/algo_out_lif_profile.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr_internal.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
shr_error_e sh_dnx_swstate_algo_lif_profile_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_dump_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_dump_man;
shr_error_e sh_dnx_swstate_algo_lif_profile_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_size_get_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_size_get_man;
extern sh_sand_cmd_t sh_dnx_swstate_algo_lif_profile_cmds[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_man;
extern const char cmd_dnx_swstate_algo_lif_profile_desc[];

extern sh_sand_cmd_t sh_dnx_swstate_algo_lif_profile_in_lif_profile_l3_enablers_cmds[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_profile_l3_enablers_man;
extern const char cmd_dnx_swstate_algo_lif_profile_in_lif_profile_l3_enablers_desc[];
shr_error_e sh_dnx_swstate_algo_lif_profile_in_lif_profile_l3_enablers_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_in_lif_profile_l3_enablers_dump_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_profile_l3_enablers_dump_man;


shr_error_e sh_dnx_swstate_algo_lif_profile_in_lif_profile_l3_enablers_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_in_lif_profile_l3_enablers_size_get_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_profile_l3_enablers_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_algo_lif_profile_in_lif_lb_profile_disablers_flags_cmds[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_lb_profile_disablers_flags_man;
extern const char cmd_dnx_swstate_algo_lif_profile_in_lif_lb_profile_disablers_flags_desc[];
shr_error_e sh_dnx_swstate_algo_lif_profile_in_lif_lb_profile_disablers_flags_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_in_lif_lb_profile_disablers_flags_dump_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_lb_profile_disablers_flags_dump_man;


shr_error_e sh_dnx_swstate_algo_lif_profile_in_lif_lb_profile_disablers_flags_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_in_lif_lb_profile_disablers_flags_size_get_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_lb_profile_disablers_flags_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_algo_lif_profile_in_lif_profile_cmds[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_profile_man;
extern const char cmd_dnx_swstate_algo_lif_profile_in_lif_profile_desc[];
shr_error_e sh_dnx_swstate_algo_lif_profile_in_lif_profile_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_in_lif_profile_dump_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_profile_dump_man;


shr_error_e sh_dnx_swstate_algo_lif_profile_in_lif_profile_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_in_lif_profile_size_get_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_profile_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_algo_lif_profile_eth_rif_profile_cmds[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_eth_rif_profile_man;
extern const char cmd_dnx_swstate_algo_lif_profile_eth_rif_profile_desc[];
shr_error_e sh_dnx_swstate_algo_lif_profile_eth_rif_profile_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_eth_rif_profile_dump_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_eth_rif_profile_dump_man;


shr_error_e sh_dnx_swstate_algo_lif_profile_eth_rif_profile_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_eth_rif_profile_size_get_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_eth_rif_profile_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_algo_lif_profile_in_lif_da_not_found_destination_cmds[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_da_not_found_destination_man;
extern const char cmd_dnx_swstate_algo_lif_profile_in_lif_da_not_found_destination_desc[];
shr_error_e sh_dnx_swstate_algo_lif_profile_in_lif_da_not_found_destination_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_in_lif_da_not_found_destination_dump_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_da_not_found_destination_dump_man;


shr_error_e sh_dnx_swstate_algo_lif_profile_in_lif_da_not_found_destination_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_in_lif_da_not_found_destination_size_get_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_in_lif_da_not_found_destination_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_algo_lif_profile_etpp_out_lif_profile_cmds[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_etpp_out_lif_profile_man;
extern const char cmd_dnx_swstate_algo_lif_profile_etpp_out_lif_profile_desc[];
shr_error_e sh_dnx_swstate_algo_lif_profile_etpp_out_lif_profile_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_etpp_out_lif_profile_dump_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_etpp_out_lif_profile_dump_man;


shr_error_e sh_dnx_swstate_algo_lif_profile_etpp_out_lif_profile_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_etpp_out_lif_profile_size_get_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_etpp_out_lif_profile_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_algo_lif_profile_erpp_out_lif_profile_cmds[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_erpp_out_lif_profile_man;
extern const char cmd_dnx_swstate_algo_lif_profile_erpp_out_lif_profile_desc[];
shr_error_e sh_dnx_swstate_algo_lif_profile_erpp_out_lif_profile_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_erpp_out_lif_profile_dump_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_erpp_out_lif_profile_dump_man;


shr_error_e sh_dnx_swstate_algo_lif_profile_erpp_out_lif_profile_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_algo_lif_profile_erpp_out_lif_profile_size_get_options[];
extern sh_sand_man_t dnx_swstate_algo_lif_profile_erpp_out_lif_profile_size_get_man;


#endif /* DNX_SW_STATE_DIAGNOSTIC */

#endif /* __DNX_ALGO_LIF_PROFILE_COMMANDLINE_H__ */