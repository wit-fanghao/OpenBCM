
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __DBAL_LAYOUT_H__
#define __DBAL_LAYOUT_H__

#include <include/soc/dnxc/swstate/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int dbal_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_DBAL_DB = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(DBAL_MODULE_ID, 0),
    DNX_SW_STATE_DBAL_DB__FIRST,
    DNX_SW_STATE_DBAL_DB__FIRST_SUB = DNX_SW_STATE_DBAL_DB__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__SW_TABLES,
    DNX_SW_STATE_DBAL_DB__MDB_ACCESS,
    DNX_SW_STATE_DBAL_DB__MDB_PHY_TABLES,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES,
    DNX_SW_STATE_DBAL_DB__DBAL_FIELDS,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES,
    DNX_SW_STATE_DBAL_DB__HW_ENT_DIRECT_MAP_HASH_TBL,
    DNX_SW_STATE_DBAL_DB__HW_ENT_GROUPS_MAP_HASH_TBL,
    DNX_SW_STATE_DBAL_DB__FIELD_NAMES_OVERRIDE_LOCATIONS,
    DNX_SW_STATE_DBAL_DB__FIELD_NAMES_OVERRIDE_STRINGS,
    DNX_SW_STATE_DBAL_DB__LAST,
    DNX_SW_STATE_DBAL_DB__LAST_SUB = DNX_SW_STATE_DBAL_DB__LAST - 1,
    DNX_SW_STATE_DBAL_DB__SW_TABLES__FIRST,
    DNX_SW_STATE_DBAL_DB__SW_TABLES__FIRST_SUB = DNX_SW_STATE_DBAL_DB__SW_TABLES__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__SW_TABLES__TABLE_TYPE,
    DNX_SW_STATE_DBAL_DB__SW_TABLES__ENTRIES,
    DNX_SW_STATE_DBAL_DB__SW_TABLES__HASH_TABLE,
    DNX_SW_STATE_DBAL_DB__SW_TABLES__LAST,
    DNX_SW_STATE_DBAL_DB__SW_TABLES__LAST_SUB = DNX_SW_STATE_DBAL_DB__SW_TABLES__LAST - 1,
    DNX_SW_STATE_DBAL_DB__MDB_ACCESS__FIRST,
    DNX_SW_STATE_DBAL_DB__MDB_ACCESS__FIRST_SUB = DNX_SW_STATE_DBAL_DB__MDB_ACCESS__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__MDB_ACCESS__SKIP_READ_FROM_SHADOW,
    DNX_SW_STATE_DBAL_DB__MDB_ACCESS__LAST,
    DNX_SW_STATE_DBAL_DB__MDB_ACCESS__LAST_SUB = DNX_SW_STATE_DBAL_DB__MDB_ACCESS__LAST - 1,
    DNX_SW_STATE_DBAL_DB__MDB_PHY_TABLES__FIRST,
    DNX_SW_STATE_DBAL_DB__MDB_PHY_TABLES__FIRST_SUB = DNX_SW_STATE_DBAL_DB__MDB_PHY_TABLES__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__MDB_PHY_TABLES__NOF_ENTRIES,
    DNX_SW_STATE_DBAL_DB__MDB_PHY_TABLES__LAST,
    DNX_SW_STATE_DBAL_DB__MDB_PHY_TABLES__LAST_SUB = DNX_SW_STATE_DBAL_DB__MDB_PHY_TABLES__LAST - 1,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__FIRST,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__FIRST_SUB = DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__TABLE_STATUS,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__NOF_SET_OPERATIONS,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__NOF_GET_OPERATIONS,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__NOF_ENTRIES,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__TCAM_HANDLER_ID,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__INDICATIONS_BM,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__ITERATOR_OPTIMIZED,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__LAST,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__LAST_SUB = DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__LAST - 1,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__ITERATOR_OPTIMIZED__FIRST,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__ITERATOR_OPTIMIZED__FIRST_SUB = DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__ITERATOR_OPTIMIZED__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__ITERATOR_OPTIMIZED__BITMAP,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__ITERATOR_OPTIMIZED__LAST,
    DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__ITERATOR_OPTIMIZED__LAST_SUB = DNX_SW_STATE_DBAL_DB__TABLES_PROPERTIES__ITERATOR_OPTIMIZED__LAST - 1,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__FIRST,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__FIRST_SUB = DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__TABLE_ID,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__TABLE_NAME,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__LABELS,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__DATA,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__KEY_INFO_DATA,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__MULTI_RES_INFO_DATA,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__RES_INFO_DATA,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__ACCESS_INFO,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__LAST,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__LAST_SUB = DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_TABLES__LAST - 1,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__FIRST,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__FIRST_SUB = DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__TABLE_ID,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__TABLE_NAME,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__LABELS,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__DATA,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__KEY_INFO_DATA,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__MULTI_RES_INFO_DATA,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__RES_INFO_DATA,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__ACCESS_INFO,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__LAST,
    DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__LAST_SUB = DNX_SW_STATE_DBAL_DB__DBAL_DYNAMIC_XML_TABLES__LAST - 1,
    DNX_SW_STATE_DBAL_DB__DBAL_FIELDS__FIRST,
    DNX_SW_STATE_DBAL_DB__DBAL_FIELDS__FIRST_SUB = DNX_SW_STATE_DBAL_DB__DBAL_FIELDS__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__DBAL_FIELDS__FIELD_TYPE,
    DNX_SW_STATE_DBAL_DB__DBAL_FIELDS__FIELD_NAME,
    DNX_SW_STATE_DBAL_DB__DBAL_FIELDS__LAST,
    DNX_SW_STATE_DBAL_DB__DBAL_FIELDS__LAST_SUB = DNX_SW_STATE_DBAL_DB__DBAL_FIELDS__LAST - 1,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__FIRST,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__FIRST_SUB = DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__MULTI_RES_INFO_STATUS,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__MULTI_RES_INFO_DATA_SEP,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__LAST,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__LAST_SUB = DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__LAST - 1,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__MULTI_RES_INFO_DATA_SEP__FIRST,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__MULTI_RES_INFO_DATA_SEP__FIRST_SUB = DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__MULTI_RES_INFO_DATA_SEP__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__MULTI_RES_INFO_DATA_SEP__MULTI_RES_INFO_DATA,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__MULTI_RES_INFO_DATA_SEP__RES_INFO_DATA,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__MULTI_RES_INFO_DATA_SEP__LAST,
    DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__MULTI_RES_INFO_DATA_SEP__LAST_SUB = DNX_SW_STATE_DBAL_DB__DBAL_PPMC_TABLE_RES_TYPES__MULTI_RES_INFO_DATA_SEP__LAST - 1,
    DNX_SW_STATE_DBAL_DB__FIELD_NAMES_OVERRIDE_STRINGS__FIRST,
    DNX_SW_STATE_DBAL_DB__FIELD_NAMES_OVERRIDE_STRINGS__FIRST_SUB = DNX_SW_STATE_DBAL_DB__FIELD_NAMES_OVERRIDE_STRINGS__FIRST - 1,
    DNX_SW_STATE_DBAL_DB__FIELD_NAMES_OVERRIDE_STRINGS__STRING,
    DNX_SW_STATE_DBAL_DB__FIELD_NAMES_OVERRIDE_STRINGS__LAST,
    DNX_SW_STATE_DBAL_DB__FIELD_NAMES_OVERRIDE_STRINGS__LAST_SUB = DNX_SW_STATE_DBAL_DB__FIELD_NAMES_OVERRIDE_STRINGS__LAST - 1,
    
    DNX_SW_STATE_DBAL_DB_NOF_PARAMS,
} dnxc_sw_state_layout_dbal_node_id_e;

#endif 