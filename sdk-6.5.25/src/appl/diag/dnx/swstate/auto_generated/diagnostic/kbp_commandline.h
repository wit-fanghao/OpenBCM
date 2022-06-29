/** \file dnx/swstate/auto_generated/diagnostic/kbp_commandline.h
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

#ifndef __DNX_KBP_COMMANDLINE_H__
#define __DNX_KBP_COMMANDLINE_H__

#ifdef BCM_DNX_SUPPORT
#if defined(INCLUDE_KBP)
#include <appl/diag/sand/diag_sand_framework.h>
#include <appl/diag/sand/diag_sand_utils.h>
#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <soc/dnx/swstate/auto_generated/types/kbp_types.h>
#include <soc/kbp/alg_kbp/include/ad.h>
#include <soc/kbp/alg_kbp/include/db.h>
#include <soc/kbp/alg_kbp/include/instruction.h>
#include <soc/kbp/alg_kbp/include/kbp_hb.h>
#include <soc/kbp/alg_kbp/include/key.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
shr_error_e sh_dnx_swstate_kbp_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_dump_man;
shr_error_e sh_dnx_swstate_kbp_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_size_get_man;
extern sh_sand_cmd_t sh_dnx_swstate_kbp_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_man;
extern const char cmd_dnx_swstate_kbp_desc[];

extern sh_sand_cmd_t sh_dnx_swstate_kbp_fwd_caching_enabled_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_fwd_caching_enabled_man;
extern const char cmd_dnx_swstate_kbp_fwd_caching_enabled_desc[];
shr_error_e sh_dnx_swstate_kbp_fwd_caching_enabled_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_fwd_caching_enabled_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_fwd_caching_enabled_dump_man;


shr_error_e sh_dnx_swstate_kbp_fwd_caching_enabled_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_fwd_caching_enabled_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_fwd_caching_enabled_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_is_device_locked_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_is_device_locked_man;
extern const char cmd_dnx_swstate_kbp_is_device_locked_desc[];
shr_error_e sh_dnx_swstate_kbp_is_device_locked_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_is_device_locked_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_is_device_locked_dump_man;


shr_error_e sh_dnx_swstate_kbp_is_device_locked_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_is_device_locked_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_is_device_locked_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_db_handles_info_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_man;
extern const char cmd_dnx_swstate_kbp_db_handles_info_desc[];
shr_error_e sh_dnx_swstate_kbp_db_handles_info_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_dump_man;


shr_error_e sh_dnx_swstate_kbp_db_handles_info_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_db_handles_info_caching_bmp_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_caching_bmp_man;
extern const char cmd_dnx_swstate_kbp_db_handles_info_caching_bmp_desc[];
shr_error_e sh_dnx_swstate_kbp_db_handles_info_caching_bmp_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_caching_bmp_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_caching_bmp_dump_man;


shr_error_e sh_dnx_swstate_kbp_db_handles_info_caching_bmp_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_caching_bmp_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_caching_bmp_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_db_handles_info_caching_enabled_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_caching_enabled_man;
extern const char cmd_dnx_swstate_kbp_db_handles_info_caching_enabled_desc[];
shr_error_e sh_dnx_swstate_kbp_db_handles_info_caching_enabled_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_caching_enabled_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_caching_enabled_dump_man;


shr_error_e sh_dnx_swstate_kbp_db_handles_info_caching_enabled_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_caching_enabled_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_caching_enabled_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_db_handles_info_db_p_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_db_p_man;
extern const char cmd_dnx_swstate_kbp_db_handles_info_db_p_desc[];
shr_error_e sh_dnx_swstate_kbp_db_handles_info_db_p_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_db_p_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_db_p_dump_man;


shr_error_e sh_dnx_swstate_kbp_db_handles_info_db_p_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_db_p_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_db_p_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_db_handles_info_ad_db_zero_size_p_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_ad_db_zero_size_p_man;
extern const char cmd_dnx_swstate_kbp_db_handles_info_ad_db_zero_size_p_desc[];
shr_error_e sh_dnx_swstate_kbp_db_handles_info_ad_db_zero_size_p_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_ad_db_zero_size_p_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_ad_db_zero_size_p_dump_man;


shr_error_e sh_dnx_swstate_kbp_db_handles_info_ad_db_zero_size_p_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_ad_db_zero_size_p_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_ad_db_zero_size_p_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_db_handles_info_ad_entry_zero_size_p_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_ad_entry_zero_size_p_man;
extern const char cmd_dnx_swstate_kbp_db_handles_info_ad_entry_zero_size_p_desc[];
shr_error_e sh_dnx_swstate_kbp_db_handles_info_ad_entry_zero_size_p_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_ad_entry_zero_size_p_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_ad_entry_zero_size_p_dump_man;


shr_error_e sh_dnx_swstate_kbp_db_handles_info_ad_entry_zero_size_p_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_ad_entry_zero_size_p_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_ad_entry_zero_size_p_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_db_handles_info_ad_db_p_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_ad_db_p_man;
extern const char cmd_dnx_swstate_kbp_db_handles_info_ad_db_p_desc[];
shr_error_e sh_dnx_swstate_kbp_db_handles_info_ad_db_p_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_ad_db_p_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_ad_db_p_dump_man;


shr_error_e sh_dnx_swstate_kbp_db_handles_info_ad_db_p_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_ad_db_p_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_ad_db_p_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_db_handles_info_opt_result_size_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_opt_result_size_man;
extern const char cmd_dnx_swstate_kbp_db_handles_info_opt_result_size_desc[];
shr_error_e sh_dnx_swstate_kbp_db_handles_info_opt_result_size_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_opt_result_size_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_opt_result_size_dump_man;


shr_error_e sh_dnx_swstate_kbp_db_handles_info_opt_result_size_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_opt_result_size_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_opt_result_size_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_db_handles_info_large_opt_result_size_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_large_opt_result_size_man;
extern const char cmd_dnx_swstate_kbp_db_handles_info_large_opt_result_size_desc[];
shr_error_e sh_dnx_swstate_kbp_db_handles_info_large_opt_result_size_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_large_opt_result_size_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_large_opt_result_size_dump_man;


shr_error_e sh_dnx_swstate_kbp_db_handles_info_large_opt_result_size_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_large_opt_result_size_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_large_opt_result_size_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_db_handles_info_cloned_db_id_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_cloned_db_id_man;
extern const char cmd_dnx_swstate_kbp_db_handles_info_cloned_db_id_desc[];
shr_error_e sh_dnx_swstate_kbp_db_handles_info_cloned_db_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_cloned_db_id_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_cloned_db_id_dump_man;


shr_error_e sh_dnx_swstate_kbp_db_handles_info_cloned_db_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_cloned_db_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_cloned_db_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_db_handles_info_associated_dbal_table_id_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_associated_dbal_table_id_man;
extern const char cmd_dnx_swstate_kbp_db_handles_info_associated_dbal_table_id_desc[];
shr_error_e sh_dnx_swstate_kbp_db_handles_info_associated_dbal_table_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_associated_dbal_table_id_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_associated_dbal_table_id_dump_man;


shr_error_e sh_dnx_swstate_kbp_db_handles_info_associated_dbal_table_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_db_handles_info_associated_dbal_table_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_db_handles_info_associated_dbal_table_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_instruction_info_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_instruction_info_man;
extern const char cmd_dnx_swstate_kbp_instruction_info_desc[];
shr_error_e sh_dnx_swstate_kbp_instruction_info_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_instruction_info_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_instruction_info_dump_man;


shr_error_e sh_dnx_swstate_kbp_instruction_info_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_instruction_info_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_instruction_info_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_kbp_instruction_info_inst_p_cmds[];
extern sh_sand_man_t dnx_swstate_kbp_instruction_info_inst_p_man;
extern const char cmd_dnx_swstate_kbp_instruction_info_inst_p_desc[];
shr_error_e sh_dnx_swstate_kbp_instruction_info_inst_p_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_instruction_info_inst_p_dump_options[];
extern sh_sand_man_t dnx_swstate_kbp_instruction_info_inst_p_dump_man;


shr_error_e sh_dnx_swstate_kbp_instruction_info_inst_p_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_kbp_instruction_info_inst_p_size_get_options[];
extern sh_sand_man_t dnx_swstate_kbp_instruction_info_inst_p_size_get_man;


#endif /* DNX_SW_STATE_DIAGNOSTIC */
#endif /* defined(INCLUDE_KBP)*/ 
#endif /* BCM_DNX_SUPPORT*/ 

#endif /* __DNX_KBP_COMMANDLINE_H__ */