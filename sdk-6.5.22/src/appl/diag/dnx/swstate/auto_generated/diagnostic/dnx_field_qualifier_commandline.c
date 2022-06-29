/** \file dnx/swstate/auto_generated/diagnostic/dnx_field_qualifier_commandline.c
 *
 * sw state functions definitions
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
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

#include <soc/dnx/swstate/auto_generated/diagnostic/dnx_field_qualifier_diagnostic.h>
#include "dnx_field_qualifier_commandline.h"
#include <soc/dnx/swstate/auto_generated/access/dnx_field_qualifier_access.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
sh_sand_cmd_t sh_dnx_swstate_dnx_field_qualifier_cmds[] = {
    {"info", NULL, sh_dnx_swstate_dnx_field_qualifier_info_cmds, NULL, &dnx_swstate_dnx_field_qualifier_info_man},
    {"dump", sh_dnx_swstate_dnx_field_qualifier_dump_cmd, NULL, dnx_swstate_dnx_field_qualifier_dump_options, &dnx_swstate_dnx_field_qualifier_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_qualifier_size_get_cmd, NULL, dnx_swstate_dnx_field_qualifier_size_get_options, &dnx_swstate_dnx_field_qualifier_size_get_man},
    {"diagnostic_operation_counters", sh_dnx_swstate_dnx_field_qualifier_diagnostic_operation_counters_cmd, NULL, dnx_swstate_dnx_field_qualifier_diagnostic_operation_counters_options, &dnx_swstate_dnx_field_qualifier_diagnostic_operation_counters_man},
    {NULL}
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    uint8 is_init;
    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    dnx_field_qual_sw_db.is_init(unit, &is_init);
    if (is_init) {
        SHR_IF_ERR_EXIT(dnx_field_qual_sw_db_dump(unit, filters));
        if (!filters.nocontent)
        {
            dnx_sw_state_dump_detach_file(unit);
        }
    }
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_dump_options[] = {
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_dump_man = {
    "swstate dnx_field_qualifier dump",
    "print the module's content",
    "swstate dnx_field_qualifier dump",
    "swstate dnx_field_qualifier dump nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    uint32 size = 0;
    SHR_FUNC_INIT_VARS(unit);

    size = dnx_sw_state_info_size_get(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~", 0);
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_size_get_man = {
    "swstate dnx_field_qualifier size_get",
    "print the module's size",
    "swstate dnx_field_qualifier size_get",
    "swstate dnx_field_qualifier size_get",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_diagnostic_operation_counters_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{


    SHR_FUNC_INIT_VARS(unit);

    dnx_sw_state_diagnostic_operation_counters_print(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~");
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_diagnostic_operation_counters_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_diagnostic_operation_counters_man = {
    "swstate dnx_field_qualifier diagnostic_operation_counters",
    "print the module's diagnostic operation counters",
    "swstate dnx_field_qualifier diagnostic_operation_counters",
    "swstate dnx_field_qualifier diagnostic_operation_counters",
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_man = {
    cmd_dnx_swstate_dnx_field_qualifier_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_qualifier_desc[] = "swstate dnx_field_qualifier commands";



sh_sand_cmd_t sh_dnx_swstate_dnx_field_qualifier_info_cmds[] = {
    {"valid", NULL, sh_dnx_swstate_dnx_field_qualifier_info_valid_cmds, NULL, &dnx_swstate_dnx_field_qualifier_info_valid_man},
    {"field_id", NULL, sh_dnx_swstate_dnx_field_qualifier_info_field_id_cmds, NULL, &dnx_swstate_dnx_field_qualifier_info_field_id_man},
    {"size", NULL, sh_dnx_swstate_dnx_field_qualifier_info_size_cmds, NULL, &dnx_swstate_dnx_field_qualifier_info_size_man},
    {"bcm_id", NULL, sh_dnx_swstate_dnx_field_qualifier_info_bcm_id_cmds, NULL, &dnx_swstate_dnx_field_qualifier_info_bcm_id_man},
    {"ref_count", NULL, sh_dnx_swstate_dnx_field_qualifier_info_ref_count_cmds, NULL, &dnx_swstate_dnx_field_qualifier_info_ref_count_man},
    {"flags", NULL, sh_dnx_swstate_dnx_field_qualifier_info_flags_cmds, NULL, &dnx_swstate_dnx_field_qualifier_info_flags_man},
    {"dump", sh_dnx_swstate_dnx_field_qualifier_info_dump_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_dump_options, &dnx_swstate_dnx_field_qualifier_info_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_qualifier_info_size_get_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_size_get_options, &dnx_swstate_dnx_field_qualifier_info_size_get_man},
    {"diagnostic_operation_counters", sh_dnx_swstate_dnx_field_qualifier_info_diagnostic_operation_counters_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_diagnostic_operation_counters_options, &dnx_swstate_dnx_field_qualifier_info_diagnostic_operation_counters_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_man = {
    cmd_dnx_swstate_dnx_field_qualifier_info_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_qualifier_info_desc[] = "dnx_field_qual_sw_db info commands";


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("info_idx_0", info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_qual_sw_db_info_dump(unit, info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_dump_options[] = {
    {"info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_qual_sw_db info dump [,info_idx_0=<int>]\n",
    "dnx_field_qual_sw_db info dump info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~", sizeof(((dnx_field_qual_sw_db_t*)sw_state_roots_array[unit][DNX_FIELD_QUALIFIER_MODULE_ID])->info));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_qual_sw_db info size_get",
    "dnx_field_qual_sw_db info size_get",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_diagnostic_operation_counters_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    SHR_FUNC_INIT_VARS(unit);


    dnx_sw_state_diagnostic_operation_counters_print(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~");
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_diagnostic_operation_counters_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_diagnostic_operation_counters_man = {
    "swstate diagnostic_operation_counters",
    "print the diagnostic operation counters",
    "dnx_field_qual_sw_db info diagnostic_operation_counters",
    "dnx_field_qual_sw_db info diagnostic_operation_counters",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_qualifier_info_valid_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_field_qualifier_info_valid_dump_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_valid_dump_options, &dnx_swstate_dnx_field_qualifier_info_valid_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_qualifier_info_valid_size_get_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_valid_size_get_options, &dnx_swstate_dnx_field_qualifier_info_valid_size_get_man},
    {"diagnostic_operation_counters", sh_dnx_swstate_dnx_field_qualifier_info_valid_diagnostic_operation_counters_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_valid_diagnostic_operation_counters_options, &dnx_swstate_dnx_field_qualifier_info_valid_diagnostic_operation_counters_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_valid_man = {
    cmd_dnx_swstate_dnx_field_qualifier_info_valid_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_qualifier_info_valid_desc[] = "dnx_field_qual_sw_db info valid commands";


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_valid_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("info_idx_0", info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_qual_sw_db_info_valid_dump(unit, info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_valid_dump_options[] = {
    {"info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_valid_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_qual_sw_db info valid dump [,info_idx_0=<int>]\n",
    "dnx_field_qual_sw_db info valid dump info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_valid_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~VALID~", sizeof(((dnx_field_qual_sw_db_t*)sw_state_roots_array[unit][DNX_FIELD_QUALIFIER_MODULE_ID])->info[0].valid));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_valid_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_valid_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_qual_sw_db info valid size_get",
    "dnx_field_qual_sw_db info valid size_get",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_valid_diagnostic_operation_counters_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    SHR_FUNC_INIT_VARS(unit);


    dnx_sw_state_diagnostic_operation_counters_print(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~VALID~");
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_valid_diagnostic_operation_counters_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_valid_diagnostic_operation_counters_man = {
    "swstate diagnostic_operation_counters",
    "print the diagnostic operation counters",
    "dnx_field_qual_sw_db info valid diagnostic_operation_counters",
    "dnx_field_qual_sw_db info valid diagnostic_operation_counters",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_qualifier_info_field_id_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_field_qualifier_info_field_id_dump_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_field_id_dump_options, &dnx_swstate_dnx_field_qualifier_info_field_id_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_qualifier_info_field_id_size_get_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_field_id_size_get_options, &dnx_swstate_dnx_field_qualifier_info_field_id_size_get_man},
    {"diagnostic_operation_counters", sh_dnx_swstate_dnx_field_qualifier_info_field_id_diagnostic_operation_counters_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_field_id_diagnostic_operation_counters_options, &dnx_swstate_dnx_field_qualifier_info_field_id_diagnostic_operation_counters_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_field_id_man = {
    cmd_dnx_swstate_dnx_field_qualifier_info_field_id_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_qualifier_info_field_id_desc[] = "dnx_field_qual_sw_db info field_id commands";


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_field_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("info_idx_0", info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_qual_sw_db_info_field_id_dump(unit, info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_field_id_dump_options[] = {
    {"info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_field_id_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_qual_sw_db info field_id dump [,info_idx_0=<int>]\n",
    "dnx_field_qual_sw_db info field_id dump info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_field_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~FIELD_ID~", sizeof(((dnx_field_qual_sw_db_t*)sw_state_roots_array[unit][DNX_FIELD_QUALIFIER_MODULE_ID])->info[0].field_id));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_field_id_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_field_id_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_qual_sw_db info field_id size_get",
    "dnx_field_qual_sw_db info field_id size_get",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_field_id_diagnostic_operation_counters_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    SHR_FUNC_INIT_VARS(unit);


    dnx_sw_state_diagnostic_operation_counters_print(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~FIELD_ID~");
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_field_id_diagnostic_operation_counters_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_field_id_diagnostic_operation_counters_man = {
    "swstate diagnostic_operation_counters",
    "print the diagnostic operation counters",
    "dnx_field_qual_sw_db info field_id diagnostic_operation_counters",
    "dnx_field_qual_sw_db info field_id diagnostic_operation_counters",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_qualifier_info_size_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_field_qualifier_info_size_dump_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_size_dump_options, &dnx_swstate_dnx_field_qualifier_info_size_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_qualifier_info_size_size_get_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_size_size_get_options, &dnx_swstate_dnx_field_qualifier_info_size_size_get_man},
    {"diagnostic_operation_counters", sh_dnx_swstate_dnx_field_qualifier_info_size_diagnostic_operation_counters_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_size_diagnostic_operation_counters_options, &dnx_swstate_dnx_field_qualifier_info_size_diagnostic_operation_counters_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_size_man = {
    cmd_dnx_swstate_dnx_field_qualifier_info_size_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_qualifier_info_size_desc[] = "dnx_field_qual_sw_db info size commands";


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_size_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("info_idx_0", info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_qual_sw_db_info_size_dump(unit, info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_size_dump_options[] = {
    {"info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_size_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_qual_sw_db info size dump [,info_idx_0=<int>]\n",
    "dnx_field_qual_sw_db info size dump info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_size_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~SIZE~", sizeof(((dnx_field_qual_sw_db_t*)sw_state_roots_array[unit][DNX_FIELD_QUALIFIER_MODULE_ID])->info[0].size));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_size_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_size_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_qual_sw_db info size size_get",
    "dnx_field_qual_sw_db info size size_get",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_size_diagnostic_operation_counters_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    SHR_FUNC_INIT_VARS(unit);


    dnx_sw_state_diagnostic_operation_counters_print(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~SIZE~");
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_size_diagnostic_operation_counters_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_size_diagnostic_operation_counters_man = {
    "swstate diagnostic_operation_counters",
    "print the diagnostic operation counters",
    "dnx_field_qual_sw_db info size diagnostic_operation_counters",
    "dnx_field_qual_sw_db info size diagnostic_operation_counters",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_qualifier_info_bcm_id_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_field_qualifier_info_bcm_id_dump_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_bcm_id_dump_options, &dnx_swstate_dnx_field_qualifier_info_bcm_id_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_qualifier_info_bcm_id_size_get_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_bcm_id_size_get_options, &dnx_swstate_dnx_field_qualifier_info_bcm_id_size_get_man},
    {"diagnostic_operation_counters", sh_dnx_swstate_dnx_field_qualifier_info_bcm_id_diagnostic_operation_counters_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_bcm_id_diagnostic_operation_counters_options, &dnx_swstate_dnx_field_qualifier_info_bcm_id_diagnostic_operation_counters_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_bcm_id_man = {
    cmd_dnx_swstate_dnx_field_qualifier_info_bcm_id_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_qualifier_info_bcm_id_desc[] = "dnx_field_qual_sw_db info bcm_id commands";


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_bcm_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("info_idx_0", info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_qual_sw_db_info_bcm_id_dump(unit, info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_bcm_id_dump_options[] = {
    {"info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_bcm_id_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_qual_sw_db info bcm_id dump [,info_idx_0=<int>]\n",
    "dnx_field_qual_sw_db info bcm_id dump info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_bcm_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~BCM_ID~", sizeof(((dnx_field_qual_sw_db_t*)sw_state_roots_array[unit][DNX_FIELD_QUALIFIER_MODULE_ID])->info[0].bcm_id));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_bcm_id_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_bcm_id_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_qual_sw_db info bcm_id size_get",
    "dnx_field_qual_sw_db info bcm_id size_get",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_bcm_id_diagnostic_operation_counters_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    SHR_FUNC_INIT_VARS(unit);


    dnx_sw_state_diagnostic_operation_counters_print(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~BCM_ID~");
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_bcm_id_diagnostic_operation_counters_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_bcm_id_diagnostic_operation_counters_man = {
    "swstate diagnostic_operation_counters",
    "print the diagnostic operation counters",
    "dnx_field_qual_sw_db info bcm_id diagnostic_operation_counters",
    "dnx_field_qual_sw_db info bcm_id diagnostic_operation_counters",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_qualifier_info_ref_count_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_field_qualifier_info_ref_count_dump_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_ref_count_dump_options, &dnx_swstate_dnx_field_qualifier_info_ref_count_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_qualifier_info_ref_count_size_get_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_ref_count_size_get_options, &dnx_swstate_dnx_field_qualifier_info_ref_count_size_get_man},
    {"diagnostic_operation_counters", sh_dnx_swstate_dnx_field_qualifier_info_ref_count_diagnostic_operation_counters_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_ref_count_diagnostic_operation_counters_options, &dnx_swstate_dnx_field_qualifier_info_ref_count_diagnostic_operation_counters_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_ref_count_man = {
    cmd_dnx_swstate_dnx_field_qualifier_info_ref_count_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_qualifier_info_ref_count_desc[] = "dnx_field_qual_sw_db info ref_count commands";


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_ref_count_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("info_idx_0", info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_qual_sw_db_info_ref_count_dump(unit, info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_ref_count_dump_options[] = {
    {"info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_ref_count_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_qual_sw_db info ref_count dump [,info_idx_0=<int>]\n",
    "dnx_field_qual_sw_db info ref_count dump info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_ref_count_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~REF_COUNT~", sizeof(((dnx_field_qual_sw_db_t*)sw_state_roots_array[unit][DNX_FIELD_QUALIFIER_MODULE_ID])->info[0].ref_count));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_ref_count_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_ref_count_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_qual_sw_db info ref_count size_get",
    "dnx_field_qual_sw_db info ref_count size_get",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_ref_count_diagnostic_operation_counters_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    SHR_FUNC_INIT_VARS(unit);


    dnx_sw_state_diagnostic_operation_counters_print(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~REF_COUNT~");
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_ref_count_diagnostic_operation_counters_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_ref_count_diagnostic_operation_counters_man = {
    "swstate diagnostic_operation_counters",
    "print the diagnostic operation counters",
    "dnx_field_qual_sw_db info ref_count diagnostic_operation_counters",
    "dnx_field_qual_sw_db info ref_count diagnostic_operation_counters",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_field_qualifier_info_flags_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_field_qualifier_info_flags_dump_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_flags_dump_options, &dnx_swstate_dnx_field_qualifier_info_flags_dump_man},
    {"size_get", sh_dnx_swstate_dnx_field_qualifier_info_flags_size_get_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_flags_size_get_options, &dnx_swstate_dnx_field_qualifier_info_flags_size_get_man},
    {"diagnostic_operation_counters", sh_dnx_swstate_dnx_field_qualifier_info_flags_diagnostic_operation_counters_cmd, NULL, dnx_swstate_dnx_field_qualifier_info_flags_diagnostic_operation_counters_options, &dnx_swstate_dnx_field_qualifier_info_flags_diagnostic_operation_counters_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_flags_man = {
    cmd_dnx_swstate_dnx_field_qualifier_info_flags_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_field_qualifier_info_flags_desc[] = "dnx_field_qual_sw_db info flags commands";


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_flags_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    int  info_idx_0 = 0;

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_INT32("info_idx_0", info_idx_0);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_field_qual_sw_db_info_flags_dump(unit, info_idx_0, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_flags_dump_options[] = {
    {"info_idx_0", SAL_FIELD_TYPE_INT32, "index", NULL},
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_flags_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_field_qual_sw_db info flags dump [,info_idx_0=<int>]\n",
    "dnx_field_qual_sw_db info flags dump info_idx_0=0 nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_flags_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~FLAGS~", sizeof(((dnx_field_qual_sw_db_t*)sw_state_roots_array[unit][DNX_FIELD_QUALIFIER_MODULE_ID])->info[0].flags));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_flags_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_flags_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_field_qual_sw_db info flags size_get",
    "dnx_field_qual_sw_db info flags size_get",
};


shr_error_e sh_dnx_swstate_dnx_field_qualifier_info_flags_diagnostic_operation_counters_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    SHR_FUNC_INIT_VARS(unit);


    dnx_sw_state_diagnostic_operation_counters_print(dnx_field_qual_sw_db_info[unit], dnx_field_qual_sw_db_layout_str, DNX_FIELD_QUAL_SW_DB_INFO_NOF_ENTRIES, "DNX_FIELD_QUAL_SW_DB~INFO~FLAGS~");
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_field_qualifier_info_flags_diagnostic_operation_counters_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_field_qualifier_info_flags_diagnostic_operation_counters_man = {
    "swstate diagnostic_operation_counters",
    "print the diagnostic operation counters",
    "dnx_field_qual_sw_db info flags diagnostic_operation_counters",
    "dnx_field_qual_sw_db info flags diagnostic_operation_counters",
};


#endif /* DNX_SW_STATE_DIAGNOSTIC */
#undef BSL_LOG_MODULE