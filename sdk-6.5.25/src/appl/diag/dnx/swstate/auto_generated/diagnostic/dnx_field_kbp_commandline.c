/** \file dnx/swstate/auto_generated/diagnostic/dnx_field_kbp_commandline.c
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
 * Copyright 2007-2021 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#ifdef BCM_DNX_SUPPORT
#if defined(INCLUDE_KBP)
#include <soc/dnx/swstate/auto_generated/diagnostic/dnx_field_kbp_diagnostic.h>
#include "dnx_field_kbp_commandline.h"
#include <soc/dnx/swstate/auto_generated/access/dnx_field_kbp_access.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
sh_sand_cmd_t sh_dnx_swstate_dnx_field_kbp_cmds[] = {
    {"opcode_info", NULL, sh_dnx_swstate_dnx_field_kbp_opcode_info_cmds, NULL, &dnx_swstate_dnx_field_kbp_opcode_info_man},
    {"dump", sh_dnx_swstate_dnx_field_kbp_dump_cmd, NULL, dnx_swstate_dnx_field_kbp_dump_options, &dnx_swstate_dnx_field_kbp_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_kbp_size_get_cmd, NULL, dnx_swstate_dnx_field_kbp_size_get_options, &dnx_swstate_dnx_field_kbp_size_get_man},
    {NULL}
};


shr_error_e sh_dnx_swstate_dnx_field_kbp_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    uint8 is_init;
    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    dnx_field_kbp_sw.is_init(unit, &is_init);
    if (is_init) {
        SHR_IF_ERR_EXIT(dnx_field_kbp_sw_dump(unit, filters));
        if (!filters.nocontent)
        {
            dnx_sw_state_dump_detach_file(unit);
        }
    }
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_dump_options[] = {
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_dump_man = {
    "swstate dnx_field_kbp dump",
    "print the module's content",
    "swstate dnx_field_kbp dump",
    "swstate dnx_field_kbp dump nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_kbp_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    uint32 size = 0;
    SHR_FUNC_INIT_VARS(unit);

    size = dnx_sw_state_info_size_get(dnx_field_kbp_sw_info[unit], dnx_field_kbp_sw_layout_str, DNX_FIELD_KBP_SW_INFO_NOF_ENTRIES, "DNX_FIELD_KBP_SW~", 0);
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_size_get_man = {
    "swstate dnx_field_kbp size_get",
    "print the module's size",
    "swstate dnx_field_kbp size_get",
    "swstate dnx_field_kbp size_get",
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_man = {
    cmd_dnx_swstate_dnx_field_kbp_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_kbp_desc[] = "swstate dnx_field_kbp commands";



sh_sand_cmd_t sh_dnx_swstate_dnx_field_kbp_opcode_info_cmds[] = {
    {"master_key_info", NULL, sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_cmds, NULL, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_man},
    {"is_valid", NULL, sh_dnx_swstate_dnx_field_kbp_opcode_info_is_valid_cmds, NULL, &dnx_swstate_dnx_field_kbp_opcode_info_is_valid_man},
    {"dump", sh_dnx_swstate_dnx_field_kbp_opcode_info_dump_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_dump_options, &dnx_swstate_dnx_field_kbp_opcode_info_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_kbp_opcode_info_size_get_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_size_get_options, &dnx_swstate_dnx_field_kbp_opcode_info_size_get_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_man = {
    cmd_dnx_swstate_dnx_field_kbp_opcode_info_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_kbp_opcode_info_desc[] = "dnx_field_kbp_sw opcode_info commands";


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  opcode_info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("opcode_info_idx_0", opcode_info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_kbp_sw_opcode_info_dump(unit, opcode_info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_dump_options[] = {
    {"opcode_info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_kbp_sw opcode_info dump [,opcode_info_idx_0=<int>]\n",
    "dnx_field_kbp_sw opcode_info dump opcode_info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_kbp_sw_info[unit], dnx_field_kbp_sw_layout_str, DNX_FIELD_KBP_SW_INFO_NOF_ENTRIES, "DNX_FIELD_KBP_SW~OPCODE_INFO~", 0);
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_kbp_sw opcode_info size_get",
    "dnx_field_kbp_sw opcode_info size_get",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_cmds[] = {
    {"segment_info", NULL, sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_cmds, NULL, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_man},
    {"nof_fwd_segments", NULL, sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_cmds, NULL, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_man},
    {"dump", sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_dump_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_dump_options, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_size_get_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_size_get_options, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_size_get_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_man = {
    cmd_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_desc[] = "dnx_field_kbp_sw opcode_info master_key_info commands";


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  opcode_info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("opcode_info_idx_0", opcode_info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_kbp_sw_opcode_info_master_key_info_dump(unit, opcode_info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_dump_options[] = {
    {"opcode_info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_kbp_sw opcode_info master_key_info dump [,opcode_info_idx_0=<int>]\n",
    "dnx_field_kbp_sw opcode_info master_key_info dump opcode_info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_kbp_sw_info[unit], dnx_field_kbp_sw_layout_str, DNX_FIELD_KBP_SW_INFO_NOF_ENTRIES, "DNX_FIELD_KBP_SW~OPCODE_INFO~MASTER_KEY_INFO~", sizeof(((dnx_field_kbp_sw_t*)sw_state_roots_array[unit][DNX_FIELD_KBP_MODULE_ID])->opcode_info[0].master_key_info));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_kbp_sw opcode_info master_key_info size_get",
    "dnx_field_kbp_sw opcode_info master_key_info size_get",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_cmds[] = {
    {"qual_idx", NULL, sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_cmds, NULL, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_man},
    {"fg_id", NULL, sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_cmds, NULL, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_man},
    {"dump", sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_dump_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_dump_options, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_size_get_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_size_get_options, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_size_get_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_man = {
    cmd_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_desc[] = "dnx_field_kbp_sw opcode_info master_key_info segment_info commands";


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  opcode_info_idx_0 = 0;
    int  segment_info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("opcode_info_idx_0", opcode_info_idx_0);
    SH_SAND_GET_INT32("segment_info_idx_0", segment_info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_kbp_sw_opcode_info_master_key_info_segment_info_dump(unit, opcode_info_idx_0, segment_info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_dump_options[] = {
    {"opcode_info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"segment_info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info dump [,opcode_info_idx_0=<int>,segment_info_idx_0=<int>]\n",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info dump opcode_info_idx_0=0 segment_info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_kbp_sw_info[unit], dnx_field_kbp_sw_layout_str, DNX_FIELD_KBP_SW_INFO_NOF_ENTRIES, "DNX_FIELD_KBP_SW~OPCODE_INFO~MASTER_KEY_INFO~SEGMENT_INFO~", sizeof(((dnx_field_kbp_sw_t*)sw_state_roots_array[unit][DNX_FIELD_KBP_MODULE_ID])->opcode_info[0].master_key_info.segment_info));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info size_get",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info size_get",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_dump_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_dump_options, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_size_get_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_size_get_options, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_size_get_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_man = {
    cmd_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_desc[] = "dnx_field_kbp_sw opcode_info master_key_info segment_info qual_idx commands";


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  opcode_info_idx_0 = 0;
    int  segment_info_idx_0 = 0;
    int  qual_idx_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("opcode_info_idx_0", opcode_info_idx_0);
    SH_SAND_GET_INT32("segment_info_idx_0", segment_info_idx_0);
    SH_SAND_GET_INT32("qual_idx_idx_0", qual_idx_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_kbp_sw_opcode_info_master_key_info_segment_info_qual_idx_dump(unit, opcode_info_idx_0, segment_info_idx_0, qual_idx_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_dump_options[] = {
    {"opcode_info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"segment_info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"qual_idx_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info qual_idx dump [,opcode_info_idx_0=<int>,segment_info_idx_0=<int>,qual_idx_idx_0=<int>]\n",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info qual_idx dump opcode_info_idx_0=0 segment_info_idx_0=0 qual_idx_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_kbp_sw_info[unit], dnx_field_kbp_sw_layout_str, DNX_FIELD_KBP_SW_INFO_NOF_ENTRIES, "DNX_FIELD_KBP_SW~OPCODE_INFO~MASTER_KEY_INFO~SEGMENT_INFO~QUAL_IDX~", sizeof(((dnx_field_kbp_sw_t*)sw_state_roots_array[unit][DNX_FIELD_KBP_MODULE_ID])->opcode_info[0].master_key_info.segment_info[0].qual_idx));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_qual_idx_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info qual_idx size_get",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info qual_idx size_get",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_dump_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_dump_options, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_size_get_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_size_get_options, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_size_get_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_man = {
    cmd_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_desc[] = "dnx_field_kbp_sw opcode_info master_key_info segment_info fg_id commands";


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  opcode_info_idx_0 = 0;
    int  segment_info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("opcode_info_idx_0", opcode_info_idx_0);
    SH_SAND_GET_INT32("segment_info_idx_0", segment_info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_kbp_sw_opcode_info_master_key_info_segment_info_fg_id_dump(unit, opcode_info_idx_0, segment_info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_dump_options[] = {
    {"opcode_info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"segment_info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info fg_id dump [,opcode_info_idx_0=<int>,segment_info_idx_0=<int>]\n",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info fg_id dump opcode_info_idx_0=0 segment_info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_kbp_sw_info[unit], dnx_field_kbp_sw_layout_str, DNX_FIELD_KBP_SW_INFO_NOF_ENTRIES, "DNX_FIELD_KBP_SW~OPCODE_INFO~MASTER_KEY_INFO~SEGMENT_INFO~FG_ID~", sizeof(((dnx_field_kbp_sw_t*)sw_state_roots_array[unit][DNX_FIELD_KBP_MODULE_ID])->opcode_info[0].master_key_info.segment_info[0].fg_id));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_segment_info_fg_id_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info fg_id size_get",
    "dnx_field_kbp_sw opcode_info master_key_info segment_info fg_id size_get",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_dump_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_dump_options, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_size_get_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_size_get_options, &dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_size_get_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_man = {
    cmd_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_desc[] = "dnx_field_kbp_sw opcode_info master_key_info nof_fwd_segments commands";


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  opcode_info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("opcode_info_idx_0", opcode_info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_kbp_sw_opcode_info_master_key_info_nof_fwd_segments_dump(unit, opcode_info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_dump_options[] = {
    {"opcode_info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_kbp_sw opcode_info master_key_info nof_fwd_segments dump [,opcode_info_idx_0=<int>]\n",
    "dnx_field_kbp_sw opcode_info master_key_info nof_fwd_segments dump opcode_info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_kbp_sw_info[unit], dnx_field_kbp_sw_layout_str, DNX_FIELD_KBP_SW_INFO_NOF_ENTRIES, "DNX_FIELD_KBP_SW~OPCODE_INFO~MASTER_KEY_INFO~NOF_FWD_SEGMENTS~", sizeof(((dnx_field_kbp_sw_t*)sw_state_roots_array[unit][DNX_FIELD_KBP_MODULE_ID])->opcode_info[0].master_key_info.nof_fwd_segments));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_master_key_info_nof_fwd_segments_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_kbp_sw opcode_info master_key_info nof_fwd_segments size_get",
    "dnx_field_kbp_sw opcode_info master_key_info nof_fwd_segments size_get",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_kbp_opcode_info_is_valid_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_field_kbp_opcode_info_is_valid_dump_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_is_valid_dump_options, &dnx_swstate_dnx_field_kbp_opcode_info_is_valid_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_kbp_opcode_info_is_valid_size_get_cmd, NULL, dnx_swstate_dnx_field_kbp_opcode_info_is_valid_size_get_options, &dnx_swstate_dnx_field_kbp_opcode_info_is_valid_size_get_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_is_valid_man = {
    cmd_dnx_swstate_dnx_field_kbp_opcode_info_is_valid_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_kbp_opcode_info_is_valid_desc[] = "dnx_field_kbp_sw opcode_info is_valid commands";


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_is_valid_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  opcode_info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("opcode_info_idx_0", opcode_info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_kbp_sw_opcode_info_is_valid_dump(unit, opcode_info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_is_valid_dump_options[] = {
    {"opcode_info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_is_valid_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_kbp_sw opcode_info is_valid dump [,opcode_info_idx_0=<int>]\n",
    "dnx_field_kbp_sw opcode_info is_valid dump opcode_info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_kbp_opcode_info_is_valid_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_kbp_sw_info[unit], dnx_field_kbp_sw_layout_str, DNX_FIELD_KBP_SW_INFO_NOF_ENTRIES, "DNX_FIELD_KBP_SW~OPCODE_INFO~IS_VALID~", sizeof(((dnx_field_kbp_sw_t*)sw_state_roots_array[unit][DNX_FIELD_KBP_MODULE_ID])->opcode_info[0].is_valid));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_kbp_opcode_info_is_valid_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_kbp_opcode_info_is_valid_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_kbp_sw opcode_info is_valid size_get",
    "dnx_field_kbp_sw opcode_info is_valid size_get",
};


#endif /* DNX_SW_STATE_DIAGNOSTIC */
#endif /* defined(INCLUDE_KBP)*/ 
#endif /* BCM_DNX_SUPPORT*/ 
#undef BSL_LOG_MODULE