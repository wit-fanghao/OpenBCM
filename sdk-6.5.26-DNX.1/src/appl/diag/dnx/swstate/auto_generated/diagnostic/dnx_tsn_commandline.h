/** \file dnx/swstate/auto_generated/diagnostic/dnx_tsn_commandline.h
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

#ifndef __DNX_TSN_COMMANDLINE_H__
#define __DNX_TSN_COMMANDLINE_H__

#include <appl/diag/sand/diag_sand_framework.h>
#include <appl/diag/sand/diag_sand_utils.h>
#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/types/dnx_tsn_types.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr_internal.h>
#include <include/bcm/cosq.h>
#include <include/bcm/tsn.h>
#include <include/shared/shr_thread_manager.h>
#include <include/soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <include/soc/dnx/dnx_data/auto_generated/dnx_data_tsn.h>
#include <soc/dnxc/swstate/callbacks/sw_state_ll_callbacks.h>
#include <soc/dnxc/swstate/types/sw_state_linked_list.h>
#include <soc/dnxc/swstate/types/sw_state_mutex.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
shr_error_e sh_dnx_swstate_dnx_tsn_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_dump_man;
shr_error_e sh_dnx_swstate_dnx_tsn_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_size_get_man;
extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_man;
extern const char cmd_dnx_swstate_dnx_tsn_desc[];

extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_taf_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_man;
extern const char cmd_dnx_swstate_dnx_tsn_taf_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_taf_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_taf_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_taf_gate_alloc_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_gate_alloc_man;
extern const char cmd_dnx_swstate_dnx_tsn_taf_gate_alloc_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_taf_gate_alloc_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_gate_alloc_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_gate_alloc_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_taf_gate_alloc_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_gate_alloc_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_gate_alloc_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_taf_pid_alloc_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_pid_alloc_man;
extern const char cmd_dnx_swstate_dnx_tsn_taf_pid_alloc_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_taf_pid_alloc_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_pid_alloc_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_pid_alloc_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_taf_pid_alloc_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_pid_alloc_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_pid_alloc_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_man;
extern const char cmd_dnx_swstate_dnx_tsn_taf_taf_profiles_data_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_state_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_state_man;
extern const char cmd_dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_state_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_state_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_state_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_state_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_state_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_state_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_state_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_data_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_data_man;
extern const char cmd_dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_data_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_data_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_data_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_data_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_data_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_data_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_profile_data_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_config_change_time_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_config_change_time_man;
extern const char cmd_dnx_swstate_dnx_tsn_taf_taf_profiles_data_config_change_time_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_config_change_time_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_config_change_time_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_config_change_time_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_taf_taf_profiles_data_config_change_time_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_config_change_time_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_taf_taf_profiles_data_config_change_time_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tas_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_man;
extern const char cmd_dnx_swstate_dnx_tsn_tas_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tas_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tas_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tas_gate_alloc_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_gate_alloc_man;
extern const char cmd_dnx_swstate_dnx_tsn_tas_gate_alloc_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tas_gate_alloc_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_gate_alloc_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_gate_alloc_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tas_gate_alloc_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_gate_alloc_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_gate_alloc_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tas_pid_alloc_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_pid_alloc_man;
extern const char cmd_dnx_swstate_dnx_tsn_tas_pid_alloc_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tas_pid_alloc_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_pid_alloc_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_pid_alloc_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tas_pid_alloc_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_pid_alloc_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_pid_alloc_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tas_egq_if_to_gate_mapping_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_egq_if_to_gate_mapping_man;
extern const char cmd_dnx_swstate_dnx_tsn_tas_egq_if_to_gate_mapping_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tas_egq_if_to_gate_mapping_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_egq_if_to_gate_mapping_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_egq_if_to_gate_mapping_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tas_egq_if_to_gate_mapping_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_egq_if_to_gate_mapping_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_egq_if_to_gate_mapping_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_man;
extern const char cmd_dnx_swstate_dnx_tsn_tas_tas_profiles_data_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_state_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_state_man;
extern const char cmd_dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_state_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_state_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_state_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_state_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_state_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_state_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_state_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_data_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_data_man;
extern const char cmd_dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_data_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_data_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_data_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_data_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_data_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_data_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_profile_data_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_config_change_time_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_config_change_time_man;
extern const char cmd_dnx_swstate_dnx_tsn_tas_tas_profiles_data_config_change_time_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_config_change_time_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_config_change_time_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_config_change_time_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_config_change_time_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_config_change_time_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_config_change_time_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_port_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_port_man;
extern const char cmd_dnx_swstate_dnx_tsn_tas_tas_profiles_data_port_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_port_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_port_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_port_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tas_tas_profiles_data_port_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_port_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tas_tas_profiles_data_port_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_cqf_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_man;
extern const char cmd_dnx_swstate_dnx_tsn_cqf_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_cqf_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_cqf_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_cqf_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_cqf_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_cqf_gate_alloc_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_gate_alloc_man;
extern const char cmd_dnx_swstate_dnx_tsn_cqf_gate_alloc_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_cqf_gate_alloc_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_cqf_gate_alloc_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_gate_alloc_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_cqf_gate_alloc_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_cqf_gate_alloc_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_gate_alloc_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_cqf_tsn_egr_if_to_gate_mapping_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_tsn_egr_if_to_gate_mapping_man;
extern const char cmd_dnx_swstate_dnx_tsn_cqf_tsn_egr_if_to_gate_mapping_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_cqf_tsn_egr_if_to_gate_mapping_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_cqf_tsn_egr_if_to_gate_mapping_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_tsn_egr_if_to_gate_mapping_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_cqf_tsn_egr_if_to_gate_mapping_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_cqf_tsn_egr_if_to_gate_mapping_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_tsn_egr_if_to_gate_mapping_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_cqf_ptp_base_time_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_ptp_base_time_man;
extern const char cmd_dnx_swstate_dnx_tsn_cqf_ptp_base_time_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_cqf_ptp_base_time_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_cqf_ptp_base_time_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_ptp_base_time_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_cqf_ptp_base_time_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_cqf_ptp_base_time_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_cqf_ptp_base_time_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tsn_thread_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_man;
extern const char cmd_dnx_swstate_dnx_tsn_tsn_thread_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tsn_thread_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tsn_thread_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tsn_thread_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tsn_thread_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tsn_thread_tsn_thread_handler_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_tsn_thread_handler_man;
extern const char cmd_dnx_swstate_dnx_tsn_tsn_thread_tsn_thread_handler_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tsn_thread_tsn_thread_handler_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tsn_thread_tsn_thread_handler_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_tsn_thread_handler_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tsn_thread_tsn_thread_handler_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tsn_thread_tsn_thread_handler_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_tsn_thread_handler_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tsn_thread_pending_list_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_pending_list_man;
extern const char cmd_dnx_swstate_dnx_tsn_tsn_thread_pending_list_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tsn_thread_pending_list_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tsn_thread_pending_list_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_pending_list_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tsn_thread_pending_list_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tsn_thread_pending_list_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_pending_list_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_tsn_tsn_thread_mutex_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_mutex_man;
extern const char cmd_dnx_swstate_dnx_tsn_tsn_thread_mutex_desc[];
shr_error_e sh_dnx_swstate_dnx_tsn_tsn_thread_mutex_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tsn_thread_mutex_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_mutex_dump_man;


shr_error_e sh_dnx_swstate_dnx_tsn_tsn_thread_mutex_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_tsn_tsn_thread_mutex_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_tsn_tsn_thread_mutex_size_get_man;


#endif /* DNX_SW_STATE_DIAGNOSTIC */

#endif /* __DNX_TSN_COMMANDLINE_H__ */