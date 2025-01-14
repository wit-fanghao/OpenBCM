/** \file src/bcm/dnx/gtimer/gtimer_access.c
 * 
 *  This file contains the implementation of gtimer.
 * 
 */

/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_COUNTER

/*
 * Include files.
 * {
 */
#include <soc/sand/shrextend/shrextend_debug.h>
#include <soc/dnx/dbal/dbal.h>
#include <bcm_int/dnx/cmn/dnxcmn.h>

#ifdef BCM_ACCESS_SUPPORT
#include <bcm_int/dnx/gtimer/gtimer_access.h>
#include <soc/access/auto_generated/common_enum.h>

/*
 * }
 */

/*
 * DEFINEs
 * {
 */

/*
 * }
 */

/*
 * MACROs
 * {
 */

/*
 * }
 */

/**
 * \brief - map between block type to dbal table
 *
 * \param [in] unit - unit number
 * \param [in] block_type - block type to map
 * \param [out] dbal_table - resulted dbal table
 *
 * \return
 * *  shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_gtimer_access_dbal_table_get(
    int unit,
    access_block_id_t block_type,
    int *dbal_table)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(dbal_table, _SHR_E_PARAM, "dbal_table");

    switch (block_type)
    {
        case BLOCK_ESB:
        {
            *dbal_table = DBAL_TABLE_ESB_GTIMER_CONTROL;
            break;
        }
        case BLOCK_BDM:
        {
            *dbal_table = DBAL_TABLE_BDM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_CFC:
        {
            *dbal_table = DBAL_TABLE_CFC_GTIMER_CONTROL;
            break;
        }
        case BLOCK_CGM:
        {
            *dbal_table = DBAL_TABLE_CGM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_CRPS:
        {
            *dbal_table = DBAL_TABLE_CRPS_GTIMER_CONTROL;
            break;
        }
        case BLOCK_DDHA:
        {
            *dbal_table = DBAL_TABLE_DDHA_GTIMER_CONTROL;
            break;
        }
        case BLOCK_DDHB:
        {
            *dbal_table = DBAL_TABLE_DDHB_GTIMER_CONTROL;
            break;
        }
        case BLOCK_DDP:
        {
            *dbal_table = DBAL_TABLE_DDP_GTIMER_CONTROL;
            break;
        }
        case BLOCK_DQM:
        {
            *dbal_table = DBAL_TABLE_DQM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_ECGM:
        {
            *dbal_table = DBAL_TABLE_ECGM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_EDB:
        {
            *dbal_table = DBAL_TABLE_EDB_GTIMER_CONTROL;
            break;
        }
        case BLOCK_EPNI:
        {
            *dbal_table = DBAL_TABLE_EPNI_GTIMER_CONTROL;
            break;
        }
        case BLOCK_EPRE:
        {
            *dbal_table = DBAL_TABLE_EPRE_GTIMER_CONTROL;
            break;
        }
        case BLOCK_EPS:
        {
            *dbal_table = DBAL_TABLE_EPS_GTIMER_CONTROL;
            break;
        }
        case BLOCK_ERPP:
        {
            *dbal_table = DBAL_TABLE_ERPP_GTIMER_CONTROL;
            break;
        }
        case BLOCK_ETPPA:
        {
            *dbal_table = DBAL_TABLE_ETPPA_GTIMER_CONTROL;
            break;
        }
        case BLOCK_ETPPB:
        {
            *dbal_table = DBAL_TABLE_ETPPB_GTIMER_CONTROL;
            break;
        }
        case BLOCK_ETPPC:
        {
            *dbal_table = DBAL_TABLE_ETPPC_GTIMER_CONTROL;
            break;
        }
        case BLOCK_EVNT:
        {
            *dbal_table = DBAL_TABLE_EVNT_GTIMER_CONTROL;
            break;
        }
        case BLOCK_FCR:
        {
            *dbal_table = DBAL_TABLE_FCR_GTIMER_CONTROL;
            break;
        }
        case BLOCK_FCT:
        {
            *dbal_table = DBAL_TABLE_FCT_GTIMER_CONTROL;
            break;
        }
        case BLOCK_FDA:
        {
            *dbal_table = DBAL_TABLE_FDA_GTIMER_CONTROL;
            break;
        }
        case BLOCK_FDR:
        {
            *dbal_table = DBAL_TABLE_FDR_GTIMER_CONTROL;
            break;
        }
        case BLOCK_FDT:
        {
            *dbal_table = DBAL_TABLE_FDT_GTIMER_CONTROL;
            break;
        }
        case BLOCK_FDTL:
        {
            *dbal_table = DBAL_TABLE_FDTL_GTIMER_CONTROL;
            break;
        }
        case BLOCK_FQP:
        {
            *dbal_table = DBAL_TABLE_FQP_GTIMER_CONTROL;
            break;
        }
        case BLOCK_HBC:
        {
            *dbal_table = DBAL_TABLE_HBC_GTIMER_CONTROL;
            break;
        }
        case BLOCK_ILE:
        {
            *dbal_table = DBAL_TABLE_ILE_GTIMER_CONTROL;
            break;
        }
        case BLOCK_IPPA:
        {
            *dbal_table = DBAL_TABLE_IPPA_GTIMER_CONTROL;
            break;
        }
        case BLOCK_IPPB:
        {
            *dbal_table = DBAL_TABLE_IPPB_GTIMER_CONTROL;
            break;
        }
        case BLOCK_IPPC:
        {
            *dbal_table = DBAL_TABLE_IPPC_GTIMER_CONTROL;
            break;
        }
        case BLOCK_IPPD:
        {
            *dbal_table = DBAL_TABLE_IPPD_GTIMER_CONTROL;
            break;
        }
        case BLOCK_IPPE:
        {
            *dbal_table = DBAL_TABLE_IPPE_GTIMER_CONTROL;
            break;
        }
        case BLOCK_IPPF:
        {
            *dbal_table = DBAL_TABLE_IPPF_GTIMER_CONTROL;
            break;
        }
        case BLOCK_IPS:
        {
            *dbal_table = DBAL_TABLE_IPS_GTIMER_CONTROL;
            break;
        }
        case BLOCK_IPT:
        {
            *dbal_table = DBAL_TABLE_IPT_GTIMER_CONTROL;
            break;
        }
        case BLOCK_IQM:
        {
            *dbal_table = DBAL_TABLE_IQM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_IRE:
        {
            *dbal_table = DBAL_TABLE_IRE_GTIMER_CONTROL;
            break;
        }
        case BLOCK_ITPP:
        {
            *dbal_table = DBAL_TABLE_ITPP_GTIMER_CONTROL;
            break;
        }
        case BLOCK_ITPPD:
        {
            *dbal_table = DBAL_TABLE_ITPPD_GTIMER_CONTROL;
            break;
        }
        case BLOCK_KAPS:
        {
            *dbal_table = DBAL_TABLE_KAPS_GTIMER_CONTROL;
            break;
        }
        case BLOCK_MACT:
        {
            *dbal_table = DBAL_TABLE_MACT_GTIMER_CONTROL;
            break;
        }
        case BLOCK_MCP:
        {
            *dbal_table = DBAL_TABLE_MCP_GTIMER_CONTROL;
            break;
        }
        case BLOCK_MDB:
        {
            *dbal_table = DBAL_TABLE_MDB_GTIMER_CONTROL;
            break;
        }
        case BLOCK_MESH_TOPOLOGY:
        {
            *dbal_table = DBAL_TABLE_MESH_TOPOLOGY_GTIMER_CONTROL;
            break;
        }
        case BLOCK_MRPS:
        {
            *dbal_table = DBAL_TABLE_MRPS_GTIMER_CONTROL;
            break;
        }
        case BLOCK_MTM:
        {
            *dbal_table = DBAL_TABLE_MTM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_NMG:
        {
            *dbal_table = DBAL_TABLE_NMG_GTIMER_CONTROL;
            break;
        }
        case BLOCK_OAMP:
        {
            *dbal_table = DBAL_TABLE_OAMP_GTIMER_CONTROL;
            break;
        }
        case BLOCK_OCB:
        {
            *dbal_table = DBAL_TABLE_OCB_GTIMER_CONTROL;
            break;
        }
        case BLOCK_OLP:
        {
            *dbal_table = DBAL_TABLE_OLP_GTIMER_CONTROL;
            break;
        }
        case BLOCK_PDM:
        {
            *dbal_table = DBAL_TABLE_PDM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_PEM:
        {
            *dbal_table = DBAL_TABLE_PEM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_PQP:
        {
            *dbal_table = DBAL_TABLE_PQP_GTIMER_CONTROL;
            break;
        }
        case BLOCK_RQP:
        {
            *dbal_table = DBAL_TABLE_RQP_GTIMER_CONTROL;
            break;
        }
        case BLOCK_RTP:
        {
            *dbal_table = DBAL_TABLE_RTP_GTIMER_CONTROL;
            break;
        }
        case BLOCK_SCH:
        {
            *dbal_table = DBAL_TABLE_SCH_GTIMER_CONTROL;
            break;
        }
        case BLOCK_SIF:
        {
            *dbal_table = DBAL_TABLE_SIF_GTIMER_CONTROL;
            break;
        }
        case BLOCK_SPB:
        {
            *dbal_table = DBAL_TABLE_SPB_GTIMER_CONTROL;
            break;
        }
        case BLOCK_SQM:
        {
            *dbal_table = DBAL_TABLE_SQM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_TCAM:
        {
            *dbal_table = DBAL_TABLE_TCAM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_TDU:
        {
            *dbal_table = DBAL_TABLE_TDU_GTIMER_CONTROL;
            break;
        }
        case BLOCK_ECI:
        {
            *dbal_table = DBAL_TABLE_ECI_GTIMER_CONTROL;
            break;
        }
        case BLOCK_DCC:
        {
            *dbal_table = DBAL_TABLE_DCC_GTIMER_CONTROL;
            break;
        }
        case BLOCK_CDB:
        {
            *dbal_table = DBAL_TABLE_CDB_GTIMER_CONTROL;
            break;
        }
        case BLOCK_CDBM:
        {
            *dbal_table = DBAL_TABLE_CDBM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_CDPM:
        {
            *dbal_table = DBAL_TABLE_CDPM_GTIMER_CONTROL;
            break;
        }
        case BLOCK_MSS:
        {
            *dbal_table = DBAL_TABLE_MSS_GTIMER_CONTROL;
            break;
        }
        case BLOCK_MSD:
        {
            *dbal_table = DBAL_TABLE_MSD_GTIMER_CONTROL;
            break;
        }
        case BLOCK_OCBM:
        {
            *dbal_table = DBAL_TABLE_OCBM_GTIMER_CONTROL;
            break;
        }
        default:
        {
            *dbal_table = DBAL_TABLE_EMPTY;
            break;
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - check if gtimer table has a key field
 *
 * \param [in] unit - unit number
 * \param [in] dbal_table - dbal table
 * \param [out] table_has_key - indication is the given table has a key field
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_gtimer_access_table_has_key(
    int unit,
    int dbal_table,
    uint8 *table_has_key)
{
    int rv;
    dbal_table_field_info_t field_info;
    SHR_FUNC_INIT_VARS(unit);

    /** get gtimer table key field info */
    rv = dbal_tables_field_info_get_no_err(unit, dbal_table, DBAL_FIELD_BLOCK_INDEX, TRUE, 0, 0, &field_info);
    SHR_IF_ERR_EXIT_EXCEPT_IF(rv, _SHR_E_NOT_FOUND);
    if (rv == _SHR_E_NONE)
    {
        /** if no errors were returned - it means that key field was found */
        *table_has_key = TRUE;
    }
    else
    {
        /** else NOT_FOUND error was returned - it means that key field was not found */
        *table_has_key = FALSE;
    }

exit:
    SHR_FUNC_EXIT;
}

/** see header file */
shr_error_e
dnx_gtimer_access_block_type_is_supported(
    int unit,
    access_block_id_t block_type,
    int *is_supported)
{
    int dbal_table;

    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(is_supported, _SHR_E_PARAM, "is_supported");

    SHR_IF_ERR_EXIT(dnx_gtimer_access_dbal_table_get(unit, block_type, &dbal_table));
    *is_supported = (dbal_table != DBAL_TABLE_EMPTY);

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - same as dnx_gtimer_dbal_table_get, but returns an error if dbal table is not found.
 *
 * \param [in] unit - unit number
 * \param [in] block_type - block type to map
 * \param [out] dbal_table - resulted dbal table
 *
 * \return
 * *  shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_gtimer_access_dbal_table_get_with_error(
    int unit,
    access_block_id_t block_type,
    int *dbal_table)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(dbal_table, _SHR_E_PARAM, "dbal_table");

    SHR_IF_ERR_EXIT(dnx_gtimer_access_dbal_table_get(unit, block_type, dbal_table));
    if (dbal_table == DBAL_TABLE_EMPTY)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "block type 0x%x is not mapped to a matching DBAL table\n", block_type);
    }

exit:
    SHR_FUNC_EXIT;
}

/** see header file */
shr_error_e
dnx_gtimer_access_set(
    int unit,
    uint32 period,
    access_block_id_t block_type,
    int instance)
{
    int dbal_table;
    uint8 table_has_key;
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    /** get dbal table according to block type */
    SHR_IF_ERR_EXIT(dnx_gtimer_access_dbal_table_get_with_error(unit, block_type, &dbal_table));

    /** configure gtimer */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, dbal_table, &entry_handle_id));
    SHR_IF_ERR_EXIT(dnx_gtimer_access_table_has_key(unit, dbal_table, &table_has_key));
    if (table_has_key)
    {
        /** if the table has a key field configure it according to input */
        if (instance == -1)
        {
            dbal_entry_key_field32_range_set(unit, entry_handle_id, DBAL_FIELD_BLOCK_INDEX, DBAL_RANGE_ALL,
                                             DBAL_RANGE_ALL);
        }
        else
        {
            dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_BLOCK_INDEX, instance);
        }
    }
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_GTIMER_CYCLE, INST_SINGLE, period);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_GTIMER_ENABLE, INST_SINGLE, 1);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_GTIMER_RESET_ON_TRIGGER, INST_SINGLE, 1);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    /** trigger gtimer */
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_GTIMER_TRIGGER, INST_SINGLE, 1);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/** see header file */
shr_error_e
dnx_gtimer_access_get(
    int unit,
    access_block_id_t block_type,
    int instance,
    int *is_enabled)
{
    int dbal_table;
    uint8 table_has_key;
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    /** get dbal table according to block type */
    SHR_IF_ERR_EXIT(dnx_gtimer_access_dbal_table_get_with_error(unit, block_type, &dbal_table));

    /** set table handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, dbal_table, &entry_handle_id));
    /**  check if table has key */
    SHR_IF_ERR_EXIT(dnx_gtimer_access_table_has_key(unit, dbal_table, &table_has_key));
    if (table_has_key)
    {
        /** if the table has a key field configure it according to input */
        if (instance == -1)
        {
            dbal_entry_key_field32_range_set(unit, entry_handle_id, DBAL_FIELD_BLOCK_INDEX, DBAL_RANGE_ALL,
                                             DBAL_RANGE_ALL);
        }
        else
        {
            dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_BLOCK_INDEX, instance);
        }
    }

    /** Get gtimer enable status */
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_GTIMER_ENABLE, INST_SINGLE, (uint32 *) is_enabled);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/** see header file */
shr_error_e
dnx_gtimer_access_wait(
    int unit,
    access_block_id_t block_type,
    int instance)
{
    int dbal_table;
    uint8 table_has_key;
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /** get dbal table according to block type */
    SHR_IF_ERR_EXIT(dnx_gtimer_access_dbal_table_get_with_error(unit, block_type, &dbal_table));

    /** set table handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, dbal_table, &entry_handle_id));
    /**  check if table has key */
    SHR_IF_ERR_EXIT(dnx_gtimer_access_table_has_key(unit, dbal_table, &table_has_key));
    if (instance == -1)
    {
        if (table_has_key)
        {
            int max_block_index;
            /** check how many blocks of provided type */
            SHR_IF_ERR_EXIT(dbal_tables_field_max_value_get
                            (unit, dbal_table, DBAL_FIELD_BLOCK_INDEX, TRUE, 0, 0, &max_block_index));
            for (int block_index = 0; block_index <= max_block_index; ++block_index)
            {
                /** poll for done bit in each block */
                dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_BLOCK_INDEX, block_index);
                SHR_IF_ERR_EXIT(dnxcmn_polling(unit, 1000000, 1000000, entry_handle_id, DBAL_FIELD_GTIMER_TRIGGER, 0));
            }

        }
        else
        {
            /** poll for done bit */
            SHR_IF_ERR_EXIT(dnxcmn_polling(unit, 1000000, 1000000, entry_handle_id, DBAL_FIELD_GTIMER_TRIGGER, 0));
        }

    }
    else
    {
        /** poll for done bit in input block */
        if (table_has_key)
        {
            dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_BLOCK_INDEX, instance);
        }
        SHR_IF_ERR_EXIT(dnxcmn_polling(unit, 1000000, 1000000, entry_handle_id, DBAL_FIELD_GTIMER_TRIGGER, 0));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/** see header file */
shr_error_e
dnx_gtimer_access_clear(
    int unit,
    access_block_id_t block_type,
    int instance)
{
    int dbal_table;
    uint8 table_has_key;
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /** get dbal table according to block type */
    SHR_IF_ERR_EXIT(dnx_gtimer_access_dbal_table_get_with_error(unit, block_type, &dbal_table));

    /** set table handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, dbal_table, &entry_handle_id));
    /**  check if table has key */
    SHR_IF_ERR_EXIT(dnx_gtimer_access_table_has_key(unit, dbal_table, &table_has_key));
    if (table_has_key)
    {
        if (instance == -1)
        {
            dbal_entry_key_field32_range_set(unit, entry_handle_id, DBAL_FIELD_BLOCK_INDEX, DBAL_RANGE_ALL,
                                             DBAL_RANGE_ALL);
        }
        else
        {
            dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_BLOCK_INDEX, instance);
        }
    }
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_GTIMER_ENABLE, INST_SINGLE, 0);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

#endif
