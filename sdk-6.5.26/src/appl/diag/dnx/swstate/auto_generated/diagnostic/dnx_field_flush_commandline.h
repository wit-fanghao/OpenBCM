/** \file dnx/swstate/auto_generated/diagnostic/dnx_field_flush_commandline.h
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

#ifndef __DNX_FIELD_FLUSH_COMMANDLINE_H__
#define __DNX_FIELD_FLUSH_COMMANDLINE_H__

#include <appl/diag/sand/diag_sand_framework.h>
#include <appl/diag/sand/diag_sand_utils.h>
#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <soc/dnx/swstate/auto_generated/types/dnx_field_flush_types.h>
#include <soc/dnx/swstate/auto_generated/types/dnx_field_types.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
shr_error_e sh_dnx_swstate_dnx_field_flush_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_field_flush_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_field_flush_dump_man;
shr_error_e sh_dnx_swstate_dnx_field_flush_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_field_flush_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_field_flush_size_get_man;
extern sh_sand_cmd_t sh_dnx_swstate_dnx_field_flush_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_field_flush_man;
extern const char cmd_dnx_swstate_dnx_field_flush_desc[];

extern sh_sand_cmd_t sh_dnx_swstate_dnx_field_flush_flush_profile_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_field_flush_flush_profile_man;
extern const char cmd_dnx_swstate_dnx_field_flush_flush_profile_desc[];
shr_error_e sh_dnx_swstate_dnx_field_flush_flush_profile_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_field_flush_flush_profile_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_field_flush_flush_profile_dump_man;


shr_error_e sh_dnx_swstate_dnx_field_flush_flush_profile_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_field_flush_flush_profile_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_field_flush_flush_profile_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_field_flush_flush_profile_mapped_fg_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_field_flush_flush_profile_mapped_fg_man;
extern const char cmd_dnx_swstate_dnx_field_flush_flush_profile_mapped_fg_desc[];
shr_error_e sh_dnx_swstate_dnx_field_flush_flush_profile_mapped_fg_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_field_flush_flush_profile_mapped_fg_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_field_flush_flush_profile_mapped_fg_dump_man;


shr_error_e sh_dnx_swstate_dnx_field_flush_flush_profile_mapped_fg_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_field_flush_flush_profile_mapped_fg_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_field_flush_flush_profile_mapped_fg_size_get_man;


#endif /* DNX_SW_STATE_DIAGNOSTIC */

#endif /* __DNX_FIELD_FLUSH_COMMANDLINE_H__ */