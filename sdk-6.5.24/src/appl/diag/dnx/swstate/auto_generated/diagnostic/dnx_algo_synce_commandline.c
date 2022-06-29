/** \file dnx/swstate/auto_generated/diagnostic/dnx_algo_synce_commandline.c
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

#include <soc/dnx/swstate/auto_generated/diagnostic/dnx_algo_synce_diagnostic.h>
#include "dnx_algo_synce_commandline.h"
#include <soc/dnx/swstate/auto_generated/access/dnx_algo_synce_access.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
sh_sand_cmd_t sh_dnx_swstate_dnx_algo_synce_cmds[] = {
    {"fabric_synce_status", NULL, sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_cmds, NULL, &dnx_swstate_dnx_algo_synce_fabric_synce_status_man},
    {"dump", sh_dnx_swstate_dnx_algo_synce_dump_cmd, NULL, dnx_swstate_dnx_algo_synce_dump_options, &dnx_swstate_dnx_algo_synce_dump_man},
    {"size_get", sh_dnx_swstate_dnx_algo_synce_size_get_cmd, NULL, dnx_swstate_dnx_algo_synce_size_get_options, &dnx_swstate_dnx_algo_synce_size_get_man},
    {NULL}
};


shr_error_e sh_dnx_swstate_dnx_algo_synce_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    uint8 is_init;
    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    dnx_algo_synce_db.is_init(unit, &is_init);
    if (is_init) {
        SHR_IF_ERR_EXIT(dnx_algo_synce_db_dump(unit, filters));
        if (!filters.nocontent)
        {
            dnx_sw_state_dump_detach_file(unit);
        }
    }
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_algo_synce_dump_options[] = {
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_dump_man = {
    "swstate dnx_algo_synce dump",
    "print the module's content",
    "swstate dnx_algo_synce dump",
    "swstate dnx_algo_synce dump nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_algo_synce_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    uint32 size = 0;
    SHR_FUNC_INIT_VARS(unit);

    size = dnx_sw_state_info_size_get(dnx_algo_synce_db_info[unit], dnx_algo_synce_db_layout_str, DNX_ALGO_SYNCE_DB_INFO_NOF_ENTRIES, "DNX_ALGO_SYNCE_DB~", 0);
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_algo_synce_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_size_get_man = {
    "swstate dnx_algo_synce size_get",
    "print the module's size",
    "swstate dnx_algo_synce size_get",
    "swstate dnx_algo_synce size_get",
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_man = {
    cmd_dnx_swstate_dnx_algo_synce_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_algo_synce_desc[] = "swstate dnx_algo_synce commands";



sh_sand_cmd_t sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_cmds[] = {
    {"master_synce_enabled", NULL, sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_cmds, NULL, &dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_man},
    {"slave_synce_enabled", NULL, sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_cmds, NULL, &dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_man},
    {"dump", sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_dump_cmd, NULL, dnx_swstate_dnx_algo_synce_fabric_synce_status_dump_options, &dnx_swstate_dnx_algo_synce_fabric_synce_status_dump_man},
    {"size_get", sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_size_get_cmd, NULL, dnx_swstate_dnx_algo_synce_fabric_synce_status_size_get_options, &dnx_swstate_dnx_algo_synce_fabric_synce_status_size_get_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_fabric_synce_status_man = {
    cmd_dnx_swstate_dnx_algo_synce_fabric_synce_status_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_algo_synce_fabric_synce_status_desc[] = "dnx_algo_synce_db fabric_synce_status commands";


shr_error_e sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);


    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_algo_synce_db_fabric_synce_status_dump(unit, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_algo_synce_fabric_synce_status_dump_options[] = {
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_fabric_synce_status_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_algo_synce_db fabric_synce_status dump []\n",
    "dnx_algo_synce_db fabric_synce_status dump nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_algo_synce_db_info[unit], dnx_algo_synce_db_layout_str, DNX_ALGO_SYNCE_DB_INFO_NOF_ENTRIES, "DNX_ALGO_SYNCE_DB~FABRIC_SYNCE_STATUS~", sizeof(((dnx_algo_synce_db_t*)sw_state_roots_array[unit][DNX_ALGO_SYNCE_MODULE_ID])->fabric_synce_status));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_algo_synce_fabric_synce_status_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_fabric_synce_status_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_algo_synce_db fabric_synce_status size_get",
    "dnx_algo_synce_db fabric_synce_status size_get",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_dump_cmd, NULL, dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_dump_options, &dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_dump_man},
    {"size_get", sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_size_get_cmd, NULL, dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_size_get_options, &dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_size_get_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_man = {
    cmd_dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_desc[] = "dnx_algo_synce_db fabric_synce_status master_synce_enabled commands";


shr_error_e sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);


    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_algo_synce_db_fabric_synce_status_master_synce_enabled_dump(unit, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_dump_options[] = {
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_algo_synce_db fabric_synce_status master_synce_enabled dump []\n",
    "dnx_algo_synce_db fabric_synce_status master_synce_enabled dump nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_algo_synce_db_info[unit], dnx_algo_synce_db_layout_str, DNX_ALGO_SYNCE_DB_INFO_NOF_ENTRIES, "DNX_ALGO_SYNCE_DB~FABRIC_SYNCE_STATUS~MASTER_SYNCE_ENABLED~", sizeof(((dnx_algo_synce_db_t*)sw_state_roots_array[unit][DNX_ALGO_SYNCE_MODULE_ID])->fabric_synce_status.master_synce_enabled));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_fabric_synce_status_master_synce_enabled_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_algo_synce_db fabric_synce_status master_synce_enabled size_get",
    "dnx_algo_synce_db fabric_synce_status master_synce_enabled size_get",
};



sh_sand_cmd_t sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_cmds[] = {
    {"dump", sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_dump_cmd, NULL, dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_dump_options, &dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_dump_man},
    {"size_get", sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_size_get_cmd, NULL, dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_size_get_options, &dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_size_get_man},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_man = {
    cmd_dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_desc,
    NULL,
    NULL,
    NULL,
};


const char cmd_dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_desc[] = "dnx_algo_synce_db fabric_synce_status slave_synce_enabled commands";


shr_error_e sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{

    dnx_sw_state_dump_filters_t filters;

    SHR_FUNC_INIT_VARS(unit);


    SH_SAND_GET_BOOL("nocontent", filters.nocontent);
    SH_SAND_GET_STR("typefilter", filters.typefilter);
    SH_SAND_GET_STR("namefilter", filters.namefilter);

    SHR_IF_ERR_EXIT(dnx_algo_synce_db_fabric_synce_status_slave_synce_enabled_dump(unit, filters));

    if (!filters.nocontent)
    {
        dnx_sw_state_dump_detach_file(unit);

    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_dump_options[] = {
    {"nocontent",      SAL_FIELD_TYPE_BOOL, "Decision if to perform content dump or to print the access tree.",  "false"},
    {"typefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable type.",         ""},
    {"namefilter",     SAL_FIELD_TYPE_STR,  "Filter for the variable name.",         ""},
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_dump_man = {
    "swstate dump",
    "print the variable value",
    "dnx_algo_synce_db fabric_synce_status slave_synce_enabled dump []\n",
    "dnx_algo_synce_db fabric_synce_status slave_synce_enabled dump nocontent=false typefilter="" namefilter="" ",
};


shr_error_e sh_dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control)
{
    uint32 size = 0;

    SHR_FUNC_INIT_VARS(unit);


    size = dnx_sw_state_info_size_get(dnx_algo_synce_db_info[unit], dnx_algo_synce_db_layout_str, DNX_ALGO_SYNCE_DB_INFO_NOF_ENTRIES, "DNX_ALGO_SYNCE_DB~FABRIC_SYNCE_STATUS~SLAVE_SYNCE_ENABLED~", sizeof(((dnx_algo_synce_db_t*)sw_state_roots_array[unit][DNX_ALGO_SYNCE_MODULE_ID])->fabric_synce_status.slave_synce_enabled));
    dnx_sw_state_size_print(size);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}



sh_sand_option_t dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_size_get_options[] = {
    {NULL}
};


sh_sand_man_t dnx_swstate_dnx_algo_synce_fabric_synce_status_slave_synce_enabled_size_get_man = {
    "swstate size_get",
    "print the variable size",
    "dnx_algo_synce_db fabric_synce_status slave_synce_enabled size_get",
    "dnx_algo_synce_db fabric_synce_status slave_synce_enabled size_get",
};


#endif /* DNX_SW_STATE_DIAGNOSTIC */
#undef BSL_LOG_MODULE