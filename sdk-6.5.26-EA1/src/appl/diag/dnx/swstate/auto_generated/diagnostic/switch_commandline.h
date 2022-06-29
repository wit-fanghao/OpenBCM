/** \file dnx/swstate/auto_generated/diagnostic/switch_commandline.h
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

#ifndef __DNX_SWITCH_COMMANDLINE_H__
#define __DNX_SWITCH_COMMANDLINE_H__

#include <appl/diag/sand/diag_sand_framework.h>
#include <appl/diag/sand/diag_sand_utils.h>
#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <soc/dnx/swstate/auto_generated/types/switch_types.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
shr_error_e sh_dnx_swstate_switch_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_dump_options[];
extern sh_sand_man_t dnx_swstate_switch_dump_man;
shr_error_e sh_dnx_swstate_switch_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_size_get_options[];
extern sh_sand_man_t dnx_swstate_switch_size_get_man;
extern sh_sand_cmd_t sh_dnx_swstate_switch_cmds[];
extern sh_sand_man_t dnx_swstate_switch_man;
extern const char cmd_dnx_swstate_switch_desc[];

extern sh_sand_cmd_t sh_dnx_swstate_switch_module_verification_cmds[];
extern sh_sand_man_t dnx_swstate_switch_module_verification_man;
extern const char cmd_dnx_swstate_switch_module_verification_desc[];
shr_error_e sh_dnx_swstate_switch_module_verification_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_module_verification_dump_options[];
extern sh_sand_man_t dnx_swstate_switch_module_verification_dump_man;


shr_error_e sh_dnx_swstate_switch_module_verification_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_module_verification_size_get_options[];
extern sh_sand_man_t dnx_swstate_switch_module_verification_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_switch_module_error_recovery_cmds[];
extern sh_sand_man_t dnx_swstate_switch_module_error_recovery_man;
extern const char cmd_dnx_swstate_switch_module_error_recovery_desc[];
shr_error_e sh_dnx_swstate_switch_module_error_recovery_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_module_error_recovery_dump_options[];
extern sh_sand_man_t dnx_swstate_switch_module_error_recovery_dump_man;


shr_error_e sh_dnx_swstate_switch_module_error_recovery_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_module_error_recovery_size_get_options[];
extern sh_sand_man_t dnx_swstate_switch_module_error_recovery_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_switch_l3mcastl2_ipv4_fwd_type_cmds[];
extern sh_sand_man_t dnx_swstate_switch_l3mcastl2_ipv4_fwd_type_man;
extern const char cmd_dnx_swstate_switch_l3mcastl2_ipv4_fwd_type_desc[];
shr_error_e sh_dnx_swstate_switch_l3mcastl2_ipv4_fwd_type_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_l3mcastl2_ipv4_fwd_type_dump_options[];
extern sh_sand_man_t dnx_swstate_switch_l3mcastl2_ipv4_fwd_type_dump_man;


shr_error_e sh_dnx_swstate_switch_l3mcastl2_ipv4_fwd_type_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_l3mcastl2_ipv4_fwd_type_size_get_options[];
extern sh_sand_man_t dnx_swstate_switch_l3mcastl2_ipv4_fwd_type_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_switch_l3mcastl2_ipv6_fwd_type_cmds[];
extern sh_sand_man_t dnx_swstate_switch_l3mcastl2_ipv6_fwd_type_man;
extern const char cmd_dnx_swstate_switch_l3mcastl2_ipv6_fwd_type_desc[];
shr_error_e sh_dnx_swstate_switch_l3mcastl2_ipv6_fwd_type_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_l3mcastl2_ipv6_fwd_type_dump_options[];
extern sh_sand_man_t dnx_swstate_switch_l3mcastl2_ipv6_fwd_type_dump_man;


shr_error_e sh_dnx_swstate_switch_l3mcastl2_ipv6_fwd_type_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_l3mcastl2_ipv6_fwd_type_size_get_options[];
extern sh_sand_man_t dnx_swstate_switch_l3mcastl2_ipv6_fwd_type_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_switch_header_enablers_hashing_cmds[];
extern sh_sand_man_t dnx_swstate_switch_header_enablers_hashing_man;
extern const char cmd_dnx_swstate_switch_header_enablers_hashing_desc[];
shr_error_e sh_dnx_swstate_switch_header_enablers_hashing_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_header_enablers_hashing_dump_options[];
extern sh_sand_man_t dnx_swstate_switch_header_enablers_hashing_dump_man;


shr_error_e sh_dnx_swstate_switch_header_enablers_hashing_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_header_enablers_hashing_size_get_options[];
extern sh_sand_man_t dnx_swstate_switch_header_enablers_hashing_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_switch_tunnel_route_disabled_cmds[];
extern sh_sand_man_t dnx_swstate_switch_tunnel_route_disabled_man;
extern const char cmd_dnx_swstate_switch_tunnel_route_disabled_desc[];
shr_error_e sh_dnx_swstate_switch_tunnel_route_disabled_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_tunnel_route_disabled_dump_options[];
extern sh_sand_man_t dnx_swstate_switch_tunnel_route_disabled_dump_man;


shr_error_e sh_dnx_swstate_switch_tunnel_route_disabled_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_tunnel_route_disabled_size_get_options[];
extern sh_sand_man_t dnx_swstate_switch_tunnel_route_disabled_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_switch_per_port_special_label_termination_disabled_cmds[];
extern sh_sand_man_t dnx_swstate_switch_per_port_special_label_termination_disabled_man;
extern const char cmd_dnx_swstate_switch_per_port_special_label_termination_disabled_desc[];
shr_error_e sh_dnx_swstate_switch_per_port_special_label_termination_disabled_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_per_port_special_label_termination_disabled_dump_options[];
extern sh_sand_man_t dnx_swstate_switch_per_port_special_label_termination_disabled_dump_man;


shr_error_e sh_dnx_swstate_switch_per_port_special_label_termination_disabled_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_switch_per_port_special_label_termination_disabled_size_get_options[];
extern sh_sand_man_t dnx_swstate_switch_per_port_special_label_termination_disabled_size_get_man;


#endif /* DNX_SW_STATE_DIAGNOSTIC */

#endif /* __DNX_SWITCH_COMMANDLINE_H__ */