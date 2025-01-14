
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_OAM

#include <soc/sand/shrextend/shrextend_debug.h>
#include <soc/memory.h>
#include <soc/feature.h>
#include <soc/types.h>
#include <soc/register.h>
#include <soc/dnxc/drv_dnxc_utils.h>
#include <bcm/bfd.h>

#include <src/bcm/dnx/oam/oam_oamp.h>
#include <src/bcm/dnx/oam/bfd_oamp.h>
#ifdef BCM_DNX2_SUPPORT
#include <src/bcm/dnx/oam/oamp_v1/oamp_v1_pe.h>
#include <src/bcm/dnx/oam/oamp_v1/oamp_v1_pe_infra.h>
#endif
#include <src/bcm/dnx/oam/oam_oamp_crc.h>
#include <soc/dnx/dbal/dbal.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_headers.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_oam.h>
#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>
#include <bcm_int/dnx/mpls/mpls.h>
#include <bcm_int/dnx/bfd/bfd.h>
#include <include/bcm/vlan.h>
#include <include/bcm_int/dnx/switch/switch_tpid.h>
#include <include/soc/dnx/dnx_data/auto_generated/dnx_data_oam.h>
#include <bcm_int/dnx/algo/oamp/algo_oamp.h>
#include <bcm_int/dnx/algo/bfd/algo_bfd.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/access/algo_oam_access.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/access/algo_oamp_access.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/access/algo_bfd_access.h>
#include <include/bcm/switch.h>
#include <include/soc/dnx/intr/auto_generated/jr2/jr2_intr.h>
#include <soc/dnx/mdb.h>
#include <src/bcm/dnx/bfd/bfd_internal.h>
#include <soc/dnx/dnx_fifodma.h>
#include <soc/intr_cmicx.h>
#include <bcm_int/dnx/auto_generated/dnx_switch_dispatch.h>
#include <include/soc/dnx/swstate/auto_generated/access/dnx_fifodma_access.h>

#ifdef BCM_DNX2_SUPPORT

#include <src/bcm/dnx/oam/oamp_v1/bfd_oamp_v1.h>
#include <src/bcm/dnx/oam/oamp_v1/oam_oamp_v1.h>

#endif

#define DEFAULT_MEP_TYPE_MASK 0
#define DEFAULT_GACH_SEL_MASK SAL_UPTO_BIT(1)
#define DEFAULT_GACH_CHAN_MASK SAL_UPTO_BIT(16)
#define DEFAULT_TRAP_CODE_MASK 0

#define NOF_CLS_TRAP_TABLE_ENTRIES SAL_UPTO_BIT(5)

#define DNX_OAM_GET_RDI_GEN_METHOD_FIELD_FROM_MEP_PROFILE(rdi_method, is_rdi_from_rx, is_rdi_from_scanner) \
    do {\
        is_rdi_from_rx = ((rdi_method & 0x2)==0x2);\
        is_rdi_from_scanner = (rdi_method & 0x1);\
    } while (0)

#define _DNX_OAM_GET_OAMP_PENDING_EVENT_BY_DEVICE(unit) dnx_data_oam.oamp.intr_oamp_pending_event_get(unit)

#define _DNX_OAM_GET_OAMP_STAT_PENDING_EVENT_BY_DEVICE(unit) dnx_data_oam.oamp.intr_oamp_stat_pending_event_get(unit)

void
dnx_oam_oamp_statistics_enable(
    int unit,
    uint32 flags,
    dnx_oam_mep_profile_t * mep_profile_data)
{

    mep_profile_data->mep_id_shift = 0;
    mep_profile_data->opcode_mask = FALSE;
    mep_profile_data->opcode_tx_statistics_enable = FALSE;
    mep_profile_data->opcode_rx_statistics_enable = FALSE;

    if (_SHR_IS_FLAG_SET(flags, BCM_OAM_ENDPOINT_FLAGS2_TX_STATISTICS)
        || _SHR_IS_FLAG_SET(flags, BCM_BFD_ENDPOINT_FLAGS2_TX_STATISTICS))
    {
        mep_profile_data->opcode_tx_statistics_enable = TRUE;
    }

    if (_SHR_IS_FLAG_SET(flags, BCM_OAM_ENDPOINT_FLAGS2_RX_STATISTICS)
        || _SHR_IS_FLAG_SET(flags, BCM_BFD_ENDPOINT_FLAGS2_RX_STATISTICS))
    {
        mep_profile_data->opcode_rx_statistics_enable = TRUE;
    }

    if (_SHR_IS_FLAG_SET(flags, BCM_OAM_ENDPOINT_FLAGS2_PER_OPCODE_STATISTICS))
    {
        mep_profile_data->opcode_mask = TRUE;
        mep_profile_data->mep_id_shift = 3;
    }

}

static dbal_result_type_t
dnx_oam_oamp_rmep_type_get(
    int unit,
    uint32 rmep_idx,
    uint32 is_oam)
{
    uint32 self_contained_threshold;

    self_contained_threshold = dnx_data_oam.oamp.oamp_rmep_full_entry_threshold_get(unit);

    if (rmep_idx < self_contained_threshold)
    {
        return is_oam ? DBAL_RESULT_TYPE_OAMP_RMEP_DB_OAM_OFFLOADED : DBAL_RESULT_TYPE_OAMP_RMEP_DB_BFD_OFFLOADED;
    }
    else
    {
        return is_oam ? DBAL_RESULT_TYPE_OAMP_RMEP_DB_OAM_SELF_CONTAINED :
            DBAL_RESULT_TYPE_OAMP_RMEP_DB_BFD_SELF_CONTAINED;
    }
}

void
dnx_oam_oamp_period_to_lifetime(
    int unit,
    uint32 period_us,
    uint32 *lifetime,
    uint32 *lifetime_units)
{
    uint32 rmep_scan_nof_clocks;
    uint32 rmep_scan_us;

    rmep_scan_nof_clocks =
        (dnx_data_oam.oamp.rmep_max_self_contained_get(unit) * dnx_data_oam.oamp.rmep_pair_sys_clocks_get(unit)) / 2;

    rmep_scan_us = rmep_scan_nof_clocks * 1000 / dnx_data_device.general.core_clock_khz_get(unit);

    if ((period_us / rmep_scan_us) <= 0x3FF)
    {
        *lifetime_units = DBAL_ENUM_FVAL_LIFETIME_UNITS_SCAN_PERIOD_1;
        *lifetime = ((period_us / rmep_scan_us) < 1) ? 1 : (period_us / rmep_scan_us);
    }
    else if (((period_us / 100) / rmep_scan_us) <= 0x3FF)
    {
        *lifetime_units = DBAL_ENUM_FVAL_LIFETIME_UNITS_SCAN_PERIOD_100;
        *lifetime = (((period_us / 100) / rmep_scan_us) < 1) ? 1 : ((period_us / 100) / rmep_scan_us);
    }
    else
    {
        *lifetime_units = DBAL_ENUM_FVAL_LIFETIME_UNITS_SCAN_PERIOD_10000;
        *lifetime =
            (((((period_us / 1000))) / (rmep_scan_us * 10)) < 1) ? 1 : ((((period_us / 1000))) / (rmep_scan_us * 10));
    }
}

void
dnx_oam_oamp_lifetime_to_period(
    int unit,
    uint32 lifetime,
    uint32 lifetime_units,
    uint32 *period_us)
{
    uint32 rmep_scan_nof_clocks;
    uint32 rmep_scan_us;

    rmep_scan_nof_clocks =
        (dnx_data_oam.oamp.rmep_max_self_contained_get(unit) * dnx_data_oam.oamp.rmep_pair_sys_clocks_get(unit)) / 2;

    rmep_scan_us = rmep_scan_nof_clocks * 1000 / dnx_data_device.general.core_clock_khz_get(unit);

    if (lifetime_units == DBAL_ENUM_FVAL_LIFETIME_UNITS_SCAN_PERIOD_1)
    {
        *period_us = rmep_scan_us * lifetime;
    }
    else
    {
        if (lifetime_units == DBAL_ENUM_FVAL_LIFETIME_UNITS_SCAN_PERIOD_100)
        {
            *period_us = rmep_scan_us * lifetime * 100;
        }
        else
        {
            *period_us = rmep_scan_us * lifetime * 10000;
        }
    }

}

shr_error_e
dnx_oam_oamp_ccm_period_to_ccm_interval(
    int unit,
    int ccm_period,
    dbal_enum_value_field_ccm_interval_e * ccm_interval)
{
    SHR_FUNC_INIT_VARS(unit);
    switch (ccm_period)
    {
        case BCM_OAM_ENDPOINT_CCM_PERIOD_DISABLED:
            *ccm_interval = DBAL_ENUM_FVAL_CCM_INTERVAL_NO_TX;
            break;
        case BCM_OAM_ENDPOINT_CCM_PERIOD_3MS:
            *ccm_interval = DBAL_ENUM_FVAL_CCM_INTERVAL_3MS;
            break;
        case BCM_OAM_ENDPOINT_CCM_PERIOD_10MS:
            *ccm_interval = DBAL_ENUM_FVAL_CCM_INTERVAL_10MS;
            break;
        case BCM_OAM_ENDPOINT_CCM_PERIOD_100MS:
            *ccm_interval = DBAL_ENUM_FVAL_CCM_INTERVAL_100MS;
            break;
        case BCM_OAM_ENDPOINT_CCM_PERIOD_1S:
            *ccm_interval = DBAL_ENUM_FVAL_CCM_INTERVAL_1S;
            break;
        case BCM_OAM_ENDPOINT_CCM_PERIOD_10S:
            *ccm_interval = DBAL_ENUM_FVAL_CCM_INTERVAL_10S;
            break;
        case BCM_OAM_ENDPOINT_CCM_PERIOD_1M:
            *ccm_interval = DBAL_ENUM_FVAL_CCM_INTERVAL_1M;
            break;
        case BCM_OAM_ENDPOINT_CCM_PERIOD_10M:
            *ccm_interval = DBAL_ENUM_FVAL_CCM_INTERVAL_10M;
            break;
        default:
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "Invalid ccm_period passed %d.  Use one of the BCM_OAM_ENDPOINT_CCM_PERIOD_ constants.",
                         ccm_period);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_ccm_interval_to_ccm_period(
    int unit,
    dbal_enum_value_field_ccm_interval_e ccm_interval,
    int *ccm_period)
{
    SHR_FUNC_INIT_VARS(unit);
    switch (ccm_interval)
    {
        case DBAL_ENUM_FVAL_CCM_INTERVAL_NO_TX:
            *ccm_period = BCM_OAM_ENDPOINT_CCM_PERIOD_DISABLED;
            break;
        case DBAL_ENUM_FVAL_CCM_INTERVAL_3MS:
            *ccm_period = BCM_OAM_ENDPOINT_CCM_PERIOD_3MS;
            break;
        case DBAL_ENUM_FVAL_CCM_INTERVAL_10MS:
            *ccm_period = BCM_OAM_ENDPOINT_CCM_PERIOD_10MS;
            break;
        case DBAL_ENUM_FVAL_CCM_INTERVAL_100MS:
            *ccm_period = BCM_OAM_ENDPOINT_CCM_PERIOD_100MS;
            break;
        case DBAL_ENUM_FVAL_CCM_INTERVAL_1S:
            *ccm_period = BCM_OAM_ENDPOINT_CCM_PERIOD_1S;
            break;
        case DBAL_ENUM_FVAL_CCM_INTERVAL_10S:
            *ccm_period = BCM_OAM_ENDPOINT_CCM_PERIOD_10S;
            break;
        case DBAL_ENUM_FVAL_CCM_INTERVAL_1M:
            *ccm_period = BCM_OAM_ENDPOINT_CCM_PERIOD_1M;
            break;
        case DBAL_ENUM_FVAL_CCM_INTERVAL_10M:
            *ccm_period = BCM_OAM_ENDPOINT_CCM_PERIOD_10M;
            break;
        default:
            SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid ccm_interval passed %d", ccm_interval);
    }

exit:
    SHR_FUNC_EXIT;
}

int
dnx_oam_oamp_rmep_compare(
    int unit,
    int is_oam,
    dnx_oam_oamp_rmep_db_entry_t * old_entry_values,
    dnx_oam_oamp_rmep_db_entry_t * new_entry_values)
{
    uint32 new_lifetime_units = 0;
    uint32 new_lifetime = 0;

    dnx_oam_oamp_period_to_lifetime(unit, new_entry_values->period, &new_lifetime, &new_lifetime_units);

    if (is_oam)
    {
        if (old_entry_values->rmep_state.eth_state.interface_status !=
            new_entry_values->rmep_state.eth_state.interface_status)
        {
            return TRUE;
        }

        if (old_entry_values->rmep_state.eth_state.port_status != new_entry_values->rmep_state.eth_state.port_status)
        {
            return TRUE;
        }
    }
    else
    {
        if (old_entry_values->rmep_state.bfd_state.detect_multiplier !=
            new_entry_values->rmep_state.bfd_state.detect_multiplier)
        {
            return TRUE;
        }

        if (old_entry_values->rmep_state.bfd_state.state != new_entry_values->rmep_state.bfd_state.state)
        {
            return TRUE;
        }

        if (old_entry_values->rmep_state.bfd_state.flags != new_entry_values->rmep_state.bfd_state.flags)
        {
            return TRUE;
        }

        if (old_entry_values->rmep_state.bfd_state.diag_profile != new_entry_values->rmep_state.bfd_state.diag_profile)
        {
            return TRUE;
        }
    }

    if (old_entry_values->oam_id != new_entry_values->oam_id)
    {
        return TRUE;
    }
    if ((old_entry_values->lifetime != new_lifetime) || (old_entry_values->lifetime_units != new_lifetime_units))
    {
        return TRUE;
    }

    if (old_entry_values->punt_profile != new_entry_values->punt_profile)
    {
        return TRUE;
    }
    if (old_entry_values->punt_next_good_packet != new_entry_values->punt_next_good_packet)
    {
        return TRUE;
    }
    if (old_entry_values->punt_good_profile != new_entry_values->punt_good_profile)
    {
        return TRUE;
    }
    if (old_entry_values->loc_clear_threshold != new_entry_values->loc_clear_threshold)
    {
        return TRUE;
    }

    if (new_entry_values->last_ccm_lifetime_valid_on_create)
    {

        if (old_entry_values->last_ccm_lifetime_valid_on_create != new_entry_values->last_ccm_lifetime_valid_on_create)
        {
            return TRUE;
        }
    }

    return 0;
}

shr_error_e
dnx_oam_oamp_rmep_add(
    int unit,
    uint32 rmep_idx,
    uint32 is_oam,
    uint32 is_update,
    dnx_oam_oamp_rmep_db_entry_t * rmep_entry)
{
    dbal_tables_e rmep_table;
    dbal_entry_action_flags_e commit_type;
    uint32 entry_handle_id;
    dbal_result_type_t rmep_type;
    uint32 lifetime;
    uint32 lifetime_units;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    commit_type = DBAL_COMMIT;

    rmep_type = dnx_oam_oamp_rmep_type_get(unit, rmep_idx, is_oam);

    if ((rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_OAM_OFFLOADED) ||
        (rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_BFD_OFFLOADED))
    {
        rmep_table = DBAL_TABLE_OAMP_RMEP_STATIC_DATA_DB;
    }
    else
    {
        rmep_table = DBAL_TABLE_OAMP_RMEP_DB;
    }

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, rmep_table, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_RMEP_INDEX, rmep_idx);

    if (DBAL_TABLE_OAMP_RMEP_DB == rmep_table)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RESULT_TYPE, INST_SINGLE, rmep_type);
    }

    dnx_oam_oamp_period_to_lifetime(unit, rmep_entry->period, &lifetime, &lifetime_units);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_LIFETIME, INST_SINGLE, lifetime);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_LIFETIME_UNITS, INST_SINGLE, lifetime_units);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_LOC_CLEAR_LIMIT, INST_SINGLE,
                                 rmep_entry->loc_clear_threshold);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_LOC_CLEAR_ENABLE, INST_SINGLE,
                                 (rmep_entry->loc_clear_threshold == 0) ? 0 : 1);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PUNT_PROFILE, INST_SINGLE, rmep_entry->punt_profile);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_OAM_ID, INST_SINGLE, rmep_entry->oam_id);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PUNT_GOOD_PROFILE, INST_SINGLE,
                                 rmep_entry->punt_good_profile);

    if ((rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_OAM_OFFLOADED) ||
        (rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_BFD_OFFLOADED))
    {

        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT_FORCE));

        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_OAMP_RMEP_DB, entry_handle_id));

        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_RMEP_INDEX, rmep_idx);

        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RESULT_TYPE, INST_SINGLE, rmep_type);
    }

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_LAST_LIFETIME_STAMP, INST_SINGLE, lifetime);

    if ((!is_update || !is_oam) && (rmep_entry->last_ccm_lifetime_valid_on_create == 1))
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_LAST_LIFETIME_STAMP_VALID,
                                     INST_SINGLE, rmep_entry->last_ccm_lifetime_valid_on_create);
    }

    if (is_oam)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_ETH_INTERFACE_STATE, INST_SINGLE,
                                     rmep_entry->rmep_state.eth_state.interface_status);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_ETH_PORT_STATE, INST_SINGLE,
                                     rmep_entry->rmep_state.eth_state.port_status);
    }
    else
    {
#ifdef BCM_DNX2_SUPPORT
        if (DNX_OAMP_IS_V1(unit))
        {
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BFD_FLAGS_PROFILE, INST_SINGLE,
                                         rmep_entry->rmep_state.bfd_state.flags);
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BFD_STATE, INST_SINGLE,
                                         rmep_entry->rmep_state.bfd_state.state);
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BFD_DIAG_PROFILE, INST_SINGLE,
                                         rmep_entry->rmep_state.bfd_state.diag_profile);
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_DETECT_MULT, INST_SINGLE,
                                         rmep_entry->rmep_state.bfd_state.detect_multiplier);
        }
        else
#endif
        {
        }
    }

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PUNT_NEXT_GOOD_PACKET, INST_SINGLE,
                                 rmep_entry->punt_next_good_packet);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, commit_type));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_rmep_get(
    int unit,
    uint32 rmep_idx,
    uint32 is_oam,
    dnx_oam_oamp_rmep_db_entry_t * rmep_entry)
{
    dbal_tables_e rmep_table;
    uint32 entry_handle_id;
    uint32 rmep_type;
    uint32 lifetime;
    uint32 lifetime_units;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    rmep_type = dnx_oam_oamp_rmep_type_get(unit, rmep_idx, is_oam);

    if ((rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_OAM_OFFLOADED) ||
        (rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_BFD_OFFLOADED))
    {
        rmep_table = DBAL_TABLE_OAMP_RMEP_STATIC_DATA_DB;
    }
    else
    {
        rmep_table = DBAL_TABLE_OAMP_RMEP_DB;
    }

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, rmep_table, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_RMEP_INDEX, rmep_idx);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                    (unit, entry_handle_id, DBAL_FIELD_LIFETIME, INST_SINGLE, &lifetime));
    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                    (unit, entry_handle_id, DBAL_FIELD_LIFETIME_UNITS, INST_SINGLE, &lifetime_units));

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get(unit, entry_handle_id, DBAL_FIELD_LOC_CLEAR_LIMIT, INST_SINGLE,
                                                       &rmep_entry->loc_clear_threshold));

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get(unit, entry_handle_id, DBAL_FIELD_PUNT_PROFILE, INST_SINGLE,
                                                       &rmep_entry->punt_profile));
    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field16_get
                    (unit, entry_handle_id, DBAL_FIELD_OAM_ID, INST_SINGLE, &rmep_entry->oam_id));

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get(unit, entry_handle_id, DBAL_FIELD_PUNT_GOOD_PROFILE, INST_SINGLE,
                                                       &rmep_entry->punt_good_profile));

    if ((rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_OAM_OFFLOADED) ||
        (rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_BFD_OFFLOADED))
    {
        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_OAMP_RMEP_DB, entry_handle_id));

        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_RMEP_INDEX, rmep_idx);
        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
    }

    if (is_oam)
    {
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get
                        (unit, entry_handle_id, DBAL_FIELD_ETH_INTERFACE_STATE, INST_SINGLE,
                         &rmep_entry->rmep_state.eth_state.interface_status));
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get
                        (unit, entry_handle_id, DBAL_FIELD_ETH_PORT_STATE, INST_SINGLE,
                         &rmep_entry->rmep_state.eth_state.port_status));
    }
    else
    {
#ifdef BCM_DNX2_SUPPORT
        if (DNX_OAMP_IS_V1(unit))
        {
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get
                            (unit, entry_handle_id, DBAL_FIELD_BFD_FLAGS_PROFILE, INST_SINGLE,
                             &rmep_entry->rmep_state.bfd_state.flags));
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get
                            (unit, entry_handle_id, DBAL_FIELD_BFD_STATE, INST_SINGLE,
                             &rmep_entry->rmep_state.bfd_state.state));
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get
                            (unit, entry_handle_id, DBAL_FIELD_BFD_DIAG_PROFILE, INST_SINGLE,
                             &rmep_entry->rmep_state.bfd_state.diag_profile));
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field16_get
                            (unit, entry_handle_id, DBAL_FIELD_DETECT_MULT, INST_SINGLE,
                             &rmep_entry->rmep_state.bfd_state.detect_multiplier));
        }
        else
#endif
        {
        }
    }

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get(unit, entry_handle_id, DBAL_FIELD_RDI_RECEIVED, INST_SINGLE,
                                                       &rmep_entry->rdi_received));

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get
                    (unit, entry_handle_id, DBAL_FIELD_LOC, INST_SINGLE, &rmep_entry->loc));

    rmep_entry->lifetime = lifetime;
    rmep_entry->lifetime_units = lifetime_units;

    dnx_oam_oamp_lifetime_to_period(unit, lifetime, lifetime_units, &rmep_entry->period);

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_rmep_remove(
    int unit,
    uint32 rmep_idx,
    uint32 is_oam)
{
    dbal_tables_e rmep_table;
    uint32 entry_handle_id;
    uint32 rmep_type;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    rmep_type = dnx_oam_oamp_rmep_type_get(unit, rmep_idx, is_oam);

    if ((rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_OAM_OFFLOADED) ||
        (rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_BFD_OFFLOADED))
    {
        rmep_table = DBAL_TABLE_OAMP_RMEP_STATIC_DATA_DB;
    }
    else
    {
        rmep_table = DBAL_TABLE_OAMP_RMEP_DB;
    }

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, rmep_table, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_RMEP_INDEX, rmep_idx);

    if (DBAL_TABLE_OAMP_RMEP_DB == rmep_table)
    {

        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RESULT_TYPE, INST_SINGLE, rmep_type);

        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_LAST_LIFETIME_STAMP_VALID, INST_SINGLE, 0);

        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, rmep_table, entry_handle_id));

        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_RMEP_INDEX, rmep_idx);
    }

    if ((rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_OAM_OFFLOADED) ||
        (rmep_type == DBAL_RESULT_TYPE_OAMP_RMEP_DB_BFD_OFFLOADED))
    {

        SHR_IF_ERR_EXIT(dbal_entry_clear(unit, entry_handle_id, DBAL_COMMIT));

        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_OAMP_RMEP_DB, entry_handle_id));

        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_RMEP_INDEX, rmep_idx);
    }

    SHR_IF_ERR_EXIT(dbal_entry_clear(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_punt_profile_tbl_get(
    int unit,
    int profile_id,
    dnx_oam_oamp_punt_event_profile_t * punt_profile_data)
{
    uint32 entry_handle_id;
    uint32 punt_rate;
    uint32 punt_enable;
    uint32 rx_state_update_en;
    uint32 profile_scan_state_update_en;
    uint32 mep_rdi_update_loc_en;
    uint32 mep_rdi_update_loc_clear_en;
    uint32 mep_rdi_update_rx_en;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAM_PUNT_PROFILE_TBL, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_PUNT_PROFILE, profile_id);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_PROFILE_PUNT_RATE, INST_SINGLE, &(punt_rate));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_PROFILE_PUNT_ENABLE, INST_SINGLE, &(punt_enable));
    dbal_value_field32_request(unit, entry_handle_id,
                               DBAL_FIELD_PROFILE_RX_STATE_UPDATE_EN, INST_SINGLE, &(rx_state_update_en));
    dbal_value_field32_request(unit, entry_handle_id,
                               DBAL_FIELD_PROFILE_SCAN_STATE_UPDATE_EN, INST_SINGLE, &(profile_scan_state_update_en));
    dbal_value_field32_request(unit, entry_handle_id,
                               DBAL_FIELD_PROFILE_MEP_RDI_UPDATE_LOC_EN, INST_SINGLE, &(mep_rdi_update_loc_en));
    dbal_value_field32_request(unit, entry_handle_id,
                               DBAL_FIELD_PROFILE_MEP_RDI_UPDATE_LOC_CLEAR_EN, INST_SINGLE,
                               &(mep_rdi_update_loc_clear_en));
    {
        dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_PROFILE_MEP_RDI_UPDATE_RX_EN, INST_SINGLE,
                                   &(mep_rdi_update_rx_en));
    }

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

    punt_profile_data->punt_rate = punt_rate;
    punt_profile_data->punt_enable = punt_enable;
    punt_profile_data->rx_state_update_en = rx_state_update_en;
    punt_profile_data->profile_scan_state_update_en = profile_scan_state_update_en;
    punt_profile_data->mep_rdi_update_loc_en = mep_rdi_update_loc_en;
    punt_profile_data->mep_rdi_update_loc_clear_en = mep_rdi_update_loc_clear_en;

    {
        punt_profile_data->mep_rdi_update_rx_en = mep_rdi_update_rx_en;
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_punt_profile_tbl_set(
    int unit,
    int profile_id,
    const dnx_oam_oamp_punt_event_profile_t * punt_profile_data)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAM_PUNT_PROFILE_TBL, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_PUNT_PROFILE, profile_id);

    dbal_entry_value_field32_set(unit, entry_handle_id,
                                 DBAL_FIELD_PROFILE_PUNT_RATE, INST_SINGLE, punt_profile_data->punt_rate);
    dbal_entry_value_field32_set(unit, entry_handle_id,
                                 DBAL_FIELD_PROFILE_PUNT_ENABLE, INST_SINGLE, punt_profile_data->punt_enable);
    dbal_entry_value_field32_set(unit, entry_handle_id,
                                 DBAL_FIELD_PROFILE_RX_STATE_UPDATE_EN, INST_SINGLE,
                                 punt_profile_data->rx_state_update_en);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PROFILE_SCAN_STATE_UPDATE_EN, INST_SINGLE,
                                 punt_profile_data->profile_scan_state_update_en);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PROFILE_MEP_RDI_UPDATE_LOC_EN, INST_SINGLE,
                                 punt_profile_data->mep_rdi_update_loc_en);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PROFILE_MEP_RDI_UPDATE_LOC_CLEAR_EN, INST_SINGLE,
                                 punt_profile_data->mep_rdi_update_loc_clear_en);
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PROFILE_MEP_RDI_UPDATE_RX_EN, INST_SINGLE,
                                     punt_profile_data->mep_rdi_update_rx_en);
    }
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_period_to_rmep_db_nof_scans(
    int unit,
    int period,
    uint16 *nof_hw_scans)
{
    COMPILER_UINT64 nof_hw_scans_64_bit;
    COMPILER_UINT64 rmep_db_scan_interval_ns;
    COMPILER_UINT64 rmep_db_half_scan_interval_ns;
    COMPILER_UINT64 work_reg_64_a;
    COMPILER_UINT64 work_reg_64_b;
    SHR_FUNC_INIT_VARS(unit);

    COMPILER_64_SET(rmep_db_scan_interval_ns, 0, dnx_data_oam.oamp.rmep_max_self_contained_get(unit) / 2);
    COMPILER_64_UMUL_32(rmep_db_scan_interval_ns, dnx_data_oam.oamp.rmep_pair_sys_clocks_get(unit));
    COMPILER_64_UMUL_32(rmep_db_scan_interval_ns, 1000000);
    COMPILER_64_UDIV_32(rmep_db_scan_interval_ns, dnx_data_device.general.core_clock_khz_get(unit));

    rmep_db_half_scan_interval_ns = rmep_db_scan_interval_ns;
    COMPILER_64_UDIV_32(rmep_db_half_scan_interval_ns, 2);

    COMPILER_64_SET(nof_hw_scans_64_bit, 0, period);

    COMPILER_64_UMUL_32(nof_hw_scans_64_bit, 1000000);
    COMPILER_64_ADD_64(nof_hw_scans_64_bit, rmep_db_half_scan_interval_ns);
    COMPILER_64_UDIV_64(nof_hw_scans_64_bit, rmep_db_scan_interval_ns);
    COMPILER_64_SUB_32(nof_hw_scans_64_bit, 1);

    COMPILER_64_COPY(work_reg_64_a, nof_hw_scans_64_bit);
    COMPILER_64_SET(work_reg_64_b, 0, 0x0000FFFF);
    COMPILER_64_AND(work_reg_64_a, work_reg_64_b);
    *nof_hw_scans = (uint16) COMPILER_64_LO(work_reg_64_a);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_rmep_db_nof_scans_to_period(
    int unit,
    uint16 nof_hw_scans,
    int *period)
{
    COMPILER_UINT64 period_64_bit;
    COMPILER_UINT64 rmep_db_scan_interval_ns;
    COMPILER_UINT64 work_reg_64_a;
    COMPILER_UINT64 work_reg_64_b;
    SHR_FUNC_INIT_VARS(unit);

    COMPILER_64_SET(rmep_db_scan_interval_ns, 0, dnx_data_oam.oamp.rmep_max_self_contained_get(unit) / 2);
    COMPILER_64_UMUL_32(rmep_db_scan_interval_ns, dnx_data_oam.oamp.rmep_pair_sys_clocks_get(unit));
    COMPILER_64_UMUL_32(rmep_db_scan_interval_ns, 1000000);
    COMPILER_64_UDIV_32(rmep_db_scan_interval_ns, dnx_data_device.general.core_clock_khz_get(unit));

    period_64_bit = rmep_db_scan_interval_ns;
    COMPILER_64_UMUL_32(period_64_bit, (nof_hw_scans + 1));
    COMPILER_64_ADD_32(period_64_bit, 500000);
    COMPILER_64_UDIV_32(period_64_bit, 1000000);

    COMPILER_64_COPY(work_reg_64_a, period_64_bit);
    COMPILER_64_SET(work_reg_64_b, 0, 0x0000FFFF);
    COMPILER_64_AND(work_reg_64_a, work_reg_64_b);
    *period = (uint16) COMPILER_64_LO(work_reg_64_a);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_punt_good_profile_alloc(
    int unit,
    uint8 is_update,
    int punt_good_packet_period,
    int old_profile_id,
    dnx_oam_oamp_punt_good_profile_temp_data_t * hw_write_data)
{
    int profile_id = 0;
    uint16 hw_number_of_scans = 0;
    uint8 write_hw = 0, is_last = 0;
    SHR_FUNC_INIT_VARS(unit);

    if (punt_good_packet_period == 0)
    {
        hw_number_of_scans = 0;
    }
    else
    {

        dnx_oam_oamp_period_to_rmep_db_nof_scans(unit, punt_good_packet_period, &hw_number_of_scans);
    }

    if (is_update && old_profile_id != 0)
    {
        if (hw_number_of_scans == 0)
        {

            SHR_IF_ERR_EXIT(algo_oamp_db.oamp_punt_good_profile.free_single(unit, old_profile_id, &is_last));
        }
        else
        {

            SHR_IF_ERR_EXIT(algo_oamp_db.oamp_punt_good_profile.exchange
                            (unit, 0, &hw_number_of_scans, old_profile_id, NULL, &profile_id, &write_hw, &is_last));
        }

        hw_write_data->old_punt_good_profile = old_profile_id;
        hw_write_data->delete_old_punt_good_profile = is_last;
    }
    else
    {
        if (hw_number_of_scans)
        {

            SHR_IF_ERR_EXIT(algo_oamp_db.oamp_punt_good_profile.allocate_single
                            (unit, 0, &hw_number_of_scans, NULL, &profile_id, &write_hw));
        }
    }

    hw_write_data->new_punt_good_profile = profile_id;
    hw_write_data->write_new_punt_good_profile = write_hw;
    hw_write_data->new_punt_good_profile_data = hw_number_of_scans;

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_remote_endpoint_punt_good_profile_hw_configure(
    int unit,
    const dnx_oam_oamp_punt_good_profile_temp_data_t * hw_write_data)
{
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAMP_RMEP_PUNT_GOOD_TIMER, &entry_handle_id));

    if (hw_write_data->write_new_punt_good_profile)
    {

        dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_PUNT_GOOD_PROFILE,
                                  hw_write_data->new_punt_good_profile);

        dbal_entry_value_field16_set(unit, entry_handle_id, DBAL_FIELD_RMEP_PUNT_GOOD_TIMER_INIT_VALUE, INST_SINGLE,
                                     hw_write_data->new_punt_good_profile_data);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

    if (hw_write_data->delete_old_punt_good_profile)
    {

        dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_PUNT_GOOD_PROFILE,
                                  hw_write_data->old_punt_good_profile);
        SHR_IF_ERR_EXIT(dbal_entry_clear(unit, entry_handle_id, DBAL_COMMIT));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_punt_good_profile_get(
    int unit,
    uint8 punt_good_profile,
    int *punt_good_packet_period)
{
    uint16 hw_number_of_scans = 0;
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    if (punt_good_profile)
    {

        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAMP_RMEP_PUNT_GOOD_TIMER, &entry_handle_id));

        dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_PUNT_GOOD_PROFILE, punt_good_profile);

        dbal_value_field16_request(unit, entry_handle_id, DBAL_FIELD_RMEP_PUNT_GOOD_TIMER_INIT_VALUE, INST_SINGLE,
                                   &hw_number_of_scans);

        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

        if (hw_number_of_scans)
        {
            dnx_oam_oamp_rmep_db_nof_scans_to_period(unit, hw_number_of_scans, punt_good_packet_period);
        }
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_punt_good_profile_free(
    int unit,
    int punt_good_profile,
    dnx_oam_oamp_punt_good_profile_temp_data_t * hw_write_data)
{
    uint8 is_last = 0;
    SHR_FUNC_INIT_VARS(unit);

    if (punt_good_profile)
    {
        SHR_IF_ERR_EXIT(algo_oamp_db.oamp_punt_good_profile.free_single(unit, punt_good_profile, &is_last));
    }

    hw_write_data->delete_old_punt_good_profile = is_last;
    hw_write_data->old_punt_good_profile = punt_good_profile;

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_oam_oamp_rx_trap_codes_set_verify(
    int unit,
    dbal_enum_value_field_oamp_mep_type_e mep_type,
    uint32 trap_code)
{
    SHR_FUNC_INIT_VARS(unit);

#ifdef BCM_DNX2_SUPPORT
    if (DNX_OAMP_IS_V1(unit))
    {
        if (mep_type >= DBAL_NOF_ENUM_OAMP_MEP_TYPE_VALUES)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Error: Illegal MEP type.  Value provided is %d, maximum is %d",
                         mep_type, DBAL_NOF_ENUM_OAMP_MEP_TYPE_VALUES - 1);
        }
    }
    else
#endif
    {
    }

    if (trap_code >= DBAL_NOF_ENUM_INGRESS_TRAP_ID_VALUES)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Error: Illegal trap code.  Value provided is %d, maximum is %d",
                     trap_code, DBAL_NOF_ENUM_INGRESS_TRAP_ID_VALUES - 1);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_rx_trap_codes_set(
    int unit,
    dbal_enum_value_field_oamp_mep_type_e mep_type,
    uint32 trap_code,
    uint32 index)
{
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_oam_oamp_rx_trap_codes_set_verify(unit, mep_type, trap_code));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAMP_MEP_TYPE_TRAP_CODE_TCAM, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_INDEX, index);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_KEY_RECEIVED_TRAP_CODE, INST_SINGLE, trap_code);

    if (dnx_data_oam.oamp.feature_get(unit, dnx_data_oam_oamp_oamp_v2) == 1)
    {
    }
    else
    {
#ifdef BCM_DNX2_SUPPORT
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_KEY_MEP_TYPE, INST_SINGLE, mep_type);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_KEY_OPCODE_GACH_SELECT, INST_SINGLE, 0);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_KEY_OPCODE_GACH_CHANNEL, INST_SINGLE, 0);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_KEY_MEP_TYPE_MASK, INST_SINGLE,
                                     DEFAULT_MEP_TYPE_MASK);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_KEY_OPCODE_GACH_SELECT_MASK, INST_SINGLE,
                                     DEFAULT_GACH_SEL_MASK);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_KEY_OPCODE_GACH_CHANNEL_MASK, INST_SINGLE,
                                     DEFAULT_GACH_CHAN_MASK);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_KEY_RECEIVED_TRAP_CODE_MASK, INST_SINGLE,
                                     DEFAULT_TRAP_CODE_MASK);
#endif
    }
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RESULT_VALID, INST_SINGLE, TRUE);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_init_interrupt(
    int unit)
{
    bcm_switch_event_control_t event_control;
    bcm_switch_event_t switch_event = BCM_SWITCH_EVENT_DEVICE_INTERRUPT;
    uint32 enable = 1;
    uint8 dma_enable = 0;

    SHR_FUNC_INIT_VARS(unit);

    dma_enable = dnx_data_oam.oamp.oamp_fifo_dma_event_interface_enable_get(unit);

    if (dma_enable == 0)
    {

        event_control.event_id = _DNX_OAM_GET_OAMP_PENDING_EVENT_BY_DEVICE(unit);
        event_control.action = bcmSwitchEventForceUnmask;
        event_control.index = 0;

        SHR_IF_ERR_EXIT(bcm_dnx_switch_event_control_set(unit, switch_event, event_control, enable));

        event_control.action = bcmSwitchEventMask;

        SHR_IF_ERR_EXIT(bcm_dnx_switch_event_control_set(unit, switch_event, event_control, !enable));
    }

    dma_enable = dnx_data_oam.oamp.oamp_fifo_dma_report_interface_enable_get(unit);

    if (dma_enable == 0)
    {

        event_control.event_id = _DNX_OAM_GET_OAMP_STAT_PENDING_EVENT_BY_DEVICE(unit);
        event_control.action = bcmSwitchEventForceUnmask;
        event_control.index = 0;

        SHR_IF_ERR_EXIT(bcm_dnx_switch_event_control_set(unit, switch_event, event_control, enable));

        event_control.action = bcmSwitchEventMask;

        SHR_IF_ERR_EXIT(bcm_dnx_switch_event_control_set(unit, switch_event, event_control, !enable));
    }

exit:
    SHR_FUNC_EXIT;
}

void
dnx_oamp_copy_bit_array(
    uint8 *dst_buffer,
    uint32 dst_offset,
    const uint8 *src_buffer,
    uint32 src_offset,
    uint32 nof_bits_to_copy,
    uint8 read_from_hw)
{
    int index, bit_val, src_byte_offset, src_bit_offset, src_bit_in_byte_offset;
    int opposite_offset, dst_byte_offset, dst_bit_in_byte_offset;
    src_bit_offset = src_offset;
    for (index = 0; index < nof_bits_to_copy; index++, src_bit_offset++)
    {

        src_byte_offset = src_bit_offset >> UTILEX_BIT_BYTE_SHIFT;
        if (read_from_hw)
        {

            src_bit_in_byte_offset = UTILEX_GET_BITS_RANGE(src_bit_offset, UTILEX_BIT_BYTE_SHIFT - 1, 0);
        }
        else
        {

            src_bit_in_byte_offset = UTILEX_NOF_BITS_IN_BYTE - 1 -
                UTILEX_GET_BITS_RANGE(src_bit_offset, UTILEX_BIT_BYTE_SHIFT - 1, 0);
        }
        bit_val = UTILEX_GET_BIT(src_buffer[src_byte_offset], src_bit_in_byte_offset);

        opposite_offset = dst_offset + nof_bits_to_copy - 1 - index;
        dst_byte_offset = opposite_offset >> UTILEX_BIT_BYTE_SHIFT;
        if (read_from_hw)
        {

            dst_bit_in_byte_offset = UTILEX_NOF_BITS_IN_BYTE - 1 -
                UTILEX_GET_BITS_RANGE(opposite_offset, UTILEX_BIT_BYTE_SHIFT - 1, 0);
        }
        else
        {

            dst_bit_in_byte_offset = UTILEX_GET_BITS_RANGE(opposite_offset, UTILEX_BIT_BYTE_SHIFT - 1, 0);
        }

        UTILEX_SET_BIT(dst_buffer[dst_byte_offset], bit_val, dst_bit_in_byte_offset);
    }
}

shr_error_e
dnx_oam_oamp_init(
    int unit)
{
    uint8 dma_event_interface_enable = 0;
    uint8 dma_statistic_interface_enable = 0;

    SHR_FUNC_INIT_VARS(unit);

#ifdef BCM_DNX2_SUPPORT
    if (DNX_OAMP_IS_V1(unit))
    {
        SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_init(unit));
    }
#endif

    {
        dma_event_interface_enable = dnx_data_oam.oamp.oamp_fifo_dma_event_interface_enable_get(unit);
        dma_statistic_interface_enable = dnx_data_oam.oamp.oamp_fifo_dma_report_interface_enable_get(unit);

        if ((dma_statistic_interface_enable == 0) || (dma_event_interface_enable == 0))
        {

            SHR_IF_ERR_EXIT(dnx_oam_oamp_init_interrupt(unit));
        }

        if (dma_event_interface_enable)
        {

            SHR_IF_ERR_EXIT(dnx_oam_oamp_event_dma_init(unit));
        }

        if (dma_statistic_interface_enable)
        {

            SHR_IF_ERR_EXIT(dnx_oam_oamp_stat_dma_init(unit));
        }
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_deinit(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    {

        SHR_IF_ERR_CONT(dnx_oam_oamp_event_dma_deinit(unit));

        SHR_IF_ERR_CONT(dnx_oam_oamp_stat_dma_deinit(unit));
    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

#ifdef BCM_DNX2_SUPPORT

static shr_error_e
oam_oamp_get_group_crc(
    int unit,
    bcm_oam_group_t group,
    uint16 *crc)
{
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAM_GROUP_INFO_SW, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_OAM_GROUP_ID, group);

    dbal_value_field16_request(unit, entry_handle_id, DBAL_FIELD_RX_CRC, INST_SINGLE, crc);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}
#endif

shr_error_e
dnx_oamp_mep_db_ccm_endpoint_set(
    int unit,
    uint16 oam_id,
    dnx_oam_oamp_ccm_endpoint_t * entry_values)
{
    dnx_oam_oamp_mep_db_args_t *oamp_params = NULL;
    bcm_oam_group_info_t *group_info = NULL;
#ifdef BCM_DNX2_SUPPORT
    uint8 offloaded, q_entry;
    int system_headers_mode;
#endif
    SHR_FUNC_INIT_VARS(unit);

#ifdef BCM_DNX2_SUPPORT
    system_headers_mode = dnx_data_headers.system_headers.system_headers_mode_get(unit);
#endif

    SHR_NULL_CHECK(entry_values, _SHR_E_PARAM, "entry_values");
    SHR_ALLOC_SET_ZERO(oamp_params, sizeof(dnx_oam_oamp_mep_db_args_t), "Param struct for creating single entries",
                       "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);

#ifdef BCM_DNX2_SUPPORT
    if (DNX_OAMP_IS_V1(unit))
    {
        offloaded = _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_LM_DM_OFFLOADED);
        q_entry = _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_Q_ENTRY);

        if (_SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_UPDATE))
        {
            if (q_entry != 1)
            {

                if (offloaded == 1)
                {

                    SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mdb_get(unit, oam_id, MDB_PART_2_ACCESS, oamp_params));
                }

                SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mep_db_get(unit, oam_id, oamp_params));
            }
            else
            {

                SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mdb_get(unit, oam_id, MDB_Q_ENTRY_ACCESS, oamp_params));
            }
        }
        else
        {
            oamp_params->exclusive.oam_only.oam_lmm_da_profile = 0;
            oamp_params->flex_lm_dm_ptr = 0;

            oamp_params->flags = 0;
        }

        oamp_params->mep_type = entry_values->mep_type;

        UTILEX_SET_BIT(oamp_params->flags, _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_UPDATE),
                       OAMP_MEP_UPDATE);
        UTILEX_SET_BIT(oamp_params->flags, _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_LM_DM_OFFLOADED),
                       OAMP_MEP_LM_DM_OFFLOADED);
        if (!offloaded || !_SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_UPDATE))
        {

            UTILEX_SET_BIT(oamp_params->flags,
                           _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_OFFLOADED_LM_ENABLE),
                           OAMP_MEP_LM_ENABLE);
            UTILEX_SET_BIT(oamp_params->flags,
                           _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_OFFLOADED_LM_ENABLE),
                           OAMP_MEP_LM_STAT_ENABLE);
            UTILEX_SET_BIT(oamp_params->flags,
                           _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_OFFLOADED_DM_ENABLE),
                           OAMP_MEP_DM_ENABLE);
            UTILEX_SET_BIT(oamp_params->flags,
                           _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_OFFLOADED_DM_ENABLE),
                           OAMP_MEP_DM_STAT_ENABLE);
        }
        UTILEX_SET_BIT(oamp_params->flags, _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_Q_ENTRY),
                       OAMP_MEP_Q_ENTRY);
        UTILEX_SET_BIT(oamp_params->flags, _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_IS_UPMEP),
                       OAMP_MEP_IS_UPMEP);
        UTILEX_SET_BIT(oamp_params->flags, _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_PORT_TLV_EN),
                       OAMP_MEP_PORT_TLV_EN);
        UTILEX_SET_BIT(oamp_params->flags, _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_PORT_TLV_VAL),
                       OAMP_MEP_PORT_TLV_VAL);
        UTILEX_SET_BIT(oamp_params->flags, _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_RDI_FROM_PACKET),
                       OAMP_MEP_RDI_FROM_PACKET);

        if (!_SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_UPDATE))
        {

            UTILEX_SET_BIT(oamp_params->flags,
                           _SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_RDI_FROM_SCANNER),
                           OAMP_MEP_RDI_FROM_SCANNER);
        }

        if (entry_values->mep_type == DBAL_ENUM_FVAL_OAMP_MEP_TYPE_ETH_OAM)
        {

            UTILEX_SET_BIT(oamp_params->flags, DBAL_ENUM_FVAL_DA_UC_MC_TYPE_MC, OAMP_MEP_MC_UC_SEL);
        }

        if (_SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_DESTINATION_IS_FEC))
        {
            oamp_params->fec_id_or_glob_out_lif = entry_values->fec_id_or_glob_out_lif.glob_out_lif;
            UTILEX_SET_BIT(oamp_params->fec_id_or_glob_out_lif, TRUE, FIELD_IS_FEC_ID_FLAG);
        }
        else
        {
            oamp_params->fec_id_or_glob_out_lif = entry_values->fec_id_or_glob_out_lif.glob_out_lif;
        }

        oamp_params->mpls_pwe.label = entry_values->label;

        if (_SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_DOWN_MEP_EGRESS_INJECTION))
        {
            UTILEX_SET_BIT(oamp_params->flags, TRUE, OAMP_MEP_EGRESS_INJECTION);
            oamp_params->exclusive.oam_only.vsi = entry_values->vsi;
            oamp_params->exclusive.oam_only.ivec_address_factor = entry_values->ivec_address_factor;

            if (system_headers_mode == DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO_MODE)
            {
                oamp_params->counter_ptr = entry_values->counter_ptr;
                oamp_params->counter_interface = entry_values->counter_interface;
            }
        }
        else
        {
            oamp_params->counter_ptr = entry_values->counter_ptr;
            oamp_params->counter_interface = entry_values->counter_interface;
        }
        oamp_params->exclusive.oam_only.oam_mep_id = entry_values->mep_id;
        oamp_params->dest_sys_port_agr = entry_values->dest_sys_port_agr;
        oamp_params->extra_data_ptr = entry_values->extra_data_header;
        oamp_params->exclusive.oam_only.oam_maid = entry_values->maid;
        oamp_params->exclusive.oam_only.oam_inner_vid = entry_values->inner_vid;
        oamp_params->exclusive.oam_only.oam_outer_vid = entry_values->outer_vid;
        oamp_params->exclusive.oam_only.oam_ccm_interval = entry_values->ccm_interval;
        oamp_params->exclusive.oam_only.oam_sa_mac_msb_profile = entry_values->sa_gen_msb_profile;
        oamp_params->exclusive.oam_only.oam_sa_mac_lsb = entry_values->sa_gen_lsb;

        oamp_params->exclusive.oam_only.oam_icc_index = entry_values->icc_index;
        oamp_params->exclusive.oam_only.oam_mdl = entry_values->mdl;
        oamp_params->exclusive.oam_only.oam_nof_vlan_tags = entry_values->nof_vlan_tags;
        oamp_params->exclusive.oam_only.oam_inner_tpid_index = entry_values->inner_tpid_index;
        oamp_params->exclusive.oam_only.oam_inner_dei_pcp = entry_values->inner_pcp_dei;
        oamp_params->exclusive.oam_only.oam_outer_tpid_index = entry_values->outer_tpid_index;
        oamp_params->exclusive.oam_only.oam_outer_dei_pcp = entry_values->outer_pcp_dei;
        oamp_params->exclusive.oam_only.oam_interface_status_tlv_code = entry_values->interface_status_tlv_code;

        oamp_params->exclusive.oam_only.oam_prt_qualifier_profile = 0;

        oamp_params->itmh_tc_dp_profile = entry_values->itmh_tc_dp_profile;
        oamp_params->mep_profile = entry_values->mep_profile;
        oamp_params->mep_pe_profile = entry_values->mep_pe_profile;
        if (_SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_IS_UPMEP))
        {
            oamp_params->unified_port_access.ccm_eth_up_mep_port.pp_port =
                entry_values->unified_port_access.ccm_eth_up_mep_port.pp_port;
            oamp_params->unified_port_access.ccm_eth_up_mep_port.port_core =
                entry_values->unified_port_access.ccm_eth_up_mep_port.port_core;
        }
        else
        {
            oamp_params->unified_port_access.port_profile = entry_values->unified_port_access.port_profile;
        }
        oamp_params->mpls_pwe.push_profile = entry_values->push_profile;
        oamp_params->crps_core_select = entry_values->crps_core_select;
        oamp_params->exclusive.oam_only.server_destination = entry_values->server_destination;
        oamp_params->exclusive.oam_only.tx_signal = entry_values->signal_degradation_tx;

        if ((offloaded == 1) || (q_entry == 1))
        {

            SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mdb_add(unit, oam_id, oamp_params));
        }

        if (offloaded == 1)
        {

            UTILEX_SET_BIT(oamp_params->flags, TRUE, OAMP_MEP_Q_ENTRY);
            SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mdb_add(unit, oam_id, oamp_params));
            UTILEX_SET_BIT(oamp_params->flags, FALSE, OAMP_MEP_Q_ENTRY);
        }

        SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mep_db_add(unit, oam_id, oamp_params));

        if (((offloaded == 1) || (q_entry == 1))
            && (_SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_48B_MAID))
            && !_SHR_IS_FLAG_SET(entry_values->flags, DNX_OAMP_OAM_CCM_MEP_UPDATE))
        {
            uint16 calculated_crc = 0;
            SHR_ALLOC_SET_ZERO(group_info, sizeof(bcm_oam_group_info_t), "Group info struct", "%s%s%s\r\n", EMPTY,
                               EMPTY, EMPTY);

            SHR_IF_ERR_EXIT(dnx_oam_group_info_get(unit, entry_values->extra_data_header, group_info));

            SHR_IF_ERR_EXIT(oam_oamp_get_group_crc(unit, entry_values->extra_data_header, &calculated_crc));

            SHR_IF_ERR_EXIT(dnx_oamp_v1_mdb_extra_data_set
                            (unit, oam_id, offloaded, q_entry, calculated_crc, DBAL_DEFINE_OAM_OPCODE_CCM,
                             DNX_OAM_OAMP_NOF_MAID_BITS, group_info->name, FALSE));
        }
        else if (entry_values->extra_data.index != DNX_OAM_EXTRA_DATA_HEADER_INVALID)
        {
            SHR_IF_ERR_EXIT(dnx_oamp_v1_ccm_endpoint_extra_data_set(unit, &entry_values->extra_data));
        }
    }
#endif

exit:
    SHR_FREE(group_info);
    SHR_FREE(oamp_params);
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oamp_mep_db_ccm_endpoint_clear(
    int unit,
    uint16 oam_id,
    uint32 extra_data_length)
{
    dnx_oam_oamp_mep_db_args_t *oamp_params = NULL;
#ifdef BCM_DNX2_SUPPORT
    int access_index;
    uint32 nof_extra_data_access;
#endif
    SHR_FUNC_INIT_VARS(unit);

    SHR_ALLOC(oamp_params, sizeof(dnx_oam_oamp_mep_db_args_t),
              "Endpoint data read to find MDB entries before deleting", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);
#ifdef BCM_DNX2_SUPPORT
    if (DNX_OAMP_IS_V1(unit))
    {
        SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mep_db_get(unit, oam_id, oamp_params));

        if (UTILEX_GET_BIT(oamp_params->flags, OAMP_MEP_Q_ENTRY) == 1)
        {

            SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mdb_delete(unit, oam_id, MDB_Q_ENTRY_ACCESS));
        }
        else
        {
            if (UTILEX_GET_BIT(oamp_params->flags, OAMP_MEP_LM_DM_OFFLOADED) == 1)
            {

                SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mdb_delete(unit, oam_id, MDB_PART_1_ACCESS));
                SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mdb_delete(unit, oam_id, MDB_PART_2_ACCESS));
            }
        }

        if (extra_data_length != 0)
        {
            nof_extra_data_access = 1;

            if ((extra_data_length - DNX_OAM_MDB_EXTRA_DATA_HDR_SEG_LEN) > 63)
            {
                nof_extra_data_access =
                    (extra_data_length - DNX_OAM_MDB_EXTRA_DATA_HDR_SEG_LEN) / (DNX_OAM_MDB_EXTRA_DATA_PLD_SEG_LEN +
                                                                                1) + 2;
            }

            for (access_index = 0; access_index < nof_extra_data_access; access_index++)
            {
                SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mdb_delete(unit, oam_id, access_index + MDB_EXTRA_DATA_HDR_ACCESS));
            }
        }

        SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mep_db_delete(unit, oam_id));
    }
#endif

exit:
    SHR_FREE(oamp_params);
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_local_port_to_system_port_set(
    int unit,
    uint16 pp_port_profile,
    uint32 system_port)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAMP_LOCAL_PORT_2_SYSTEM_PORT, &entry_handle_id));

    dbal_entry_key_field16_set(unit, entry_handle_id, DBAL_FIELD_LOCAL_PORT_2_SYSTEM_PORT_PROFILE, pp_port_profile);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SYSTEM_PORT, INST_SINGLE, system_port);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_local_port_to_system_port_get(
    int unit,
    uint16 pp_port_profile,
    uint32 *system_port)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAMP_LOCAL_PORT_2_SYSTEM_PORT, &entry_handle_id));

    dbal_entry_key_field16_set(unit, entry_handle_id, DBAL_FIELD_LOCAL_PORT_2_SYSTEM_PORT_PROFILE, pp_port_profile);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_SYSTEM_PORT, INST_SINGLE, system_port);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_itmh_priority_profile_set(
    int unit,
    uint8 profile,
    uint8 tc,
    uint8 dp,
    uint8 qos)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAMP_ITMH_PRIORITY_PROFILE, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_ITMH_TC_DP_PROFILE, profile);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TC, INST_SINGLE, tc);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_DP, INST_SINGLE, dp);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_itmh_priority_profile_get(
    int unit,
    uint8 profile,
    uint8 *tc,
    uint8 *dp,
    uint8 *qos)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAMP_ITMH_PRIORITY_PROFILE, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_ITMH_TC_DP_PROFILE, profile);

    dbal_value_field8_request(unit, entry_handle_id, DBAL_FIELD_TC, INST_SINGLE, tc);
    dbal_value_field8_request(unit, entry_handle_id, DBAL_FIELD_DP, INST_SINGLE, dp);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_sa_mac_msb_profile_set(
    int unit,
    uint8 profile,
    bcm_mac_t sa_mac_addr_msb)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAMP_OAM_SA_MAC_MSB_PROFILE, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_SA_GEN_PROFILE, profile);

    {
#ifdef BCM_DNX2_SUPPORT

        dbal_entry_value_field_arr8_set(unit, entry_handle_id, DBAL_FIELD_MAC_MSB, INST_SINGLE, sa_mac_addr_msb);
#endif
    }

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_sa_mac_msb_profile_get(
    int unit,
    uint8 profile,
    bcm_mac_t sa_mac_addr_msb)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAMP_OAM_SA_MAC_MSB_PROFILE, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_SA_GEN_PROFILE, profile);

    {
#ifdef BCM_DNX2_SUPPORT
        dbal_value_field_arr8_request(unit, entry_handle_id, DBAL_FIELD_MAC_MSB, INST_SINGLE, sa_mac_addr_msb);
#endif
    }

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_profile_hw_set(
    int unit,
    oam_oamp_profile_hw_data_t * mep_hw_profiles_write_data)
{

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    if (mep_hw_profiles_write_data->flags & DNX_OAM_OAMP_PROFILE_ITMH_PRIORITY_FLAG)
    {
        SHR_IF_ERR_EXIT(dnx_oam_oamp_itmh_priority_profile_set(unit,
                                                               mep_hw_profiles_write_data->itmh_profile,
                                                               mep_hw_profiles_write_data->itmh_priority.tc,
                                                               mep_hw_profiles_write_data->itmh_priority.dp,
                                                               mep_hw_profiles_write_data->itmh_priority.qos));
    }

#ifdef BCM_DNX2_SUPPORT
    if (DNX_OAMP_IS_V1(unit))
    {

        if (mep_hw_profiles_write_data->flags & DNX_OAM_OAMP_PROFILE_OUTER_TPID_FLAG)
        {
            SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_tpid_profile_set(unit,
                                                             mep_hw_profiles_write_data->outer_tpid_index,
                                                             mep_hw_profiles_write_data->outer_tpid));
        }

        if (mep_hw_profiles_write_data->flags & DNX_OAM_OAMP_PROFILE_INNER_TPID_FLAG)
        {
            SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_tpid_profile_set(unit,
                                                             mep_hw_profiles_write_data->inner_tpid_index,
                                                             mep_hw_profiles_write_data->inner_tpid));
        }
    }
#endif

    if (mep_hw_profiles_write_data->flags & DNX_OAM_OAMP_PROFILE_SA_MAC_MSB_FLAG)
    {
        SHR_IF_ERR_EXIT(dnx_oam_oamp_sa_mac_msb_profile_set(unit,
                                                            mep_hw_profiles_write_data->sa_mac_msb_profile,
                                                            mep_hw_profiles_write_data->sa_mac_msb));
    }

#ifdef BCM_DNX2_SUPPORT
    if (DNX_OAMP_IS_V1(unit))
    {

        if (mep_hw_profiles_write_data->flags & DNX_OAM_OAMP_PROFILE_MEP_PROFILE_FLAG)
        {
            SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mep_profile_set(unit,
                                                            mep_hw_profiles_write_data->mep_profile_index,
                                                            ((mep_hw_profiles_write_data->flags &
                                                              DNX_OAM_OAMP_PROFILE_MPLS_LM_DM_SET) ==
                                                             DNX_OAM_OAMP_PROFILE_MPLS_LM_DM_SET),
                                                            &mep_hw_profiles_write_data->mep_profile));
        }

        if (mep_hw_profiles_write_data->flags & DNX_OAM_OAMP_PROFILE_EXP_TTL_FLAG)
        {
            SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_mpls_pwe_exp_ttl_profile_set(unit,
                                                                         mep_hw_profiles_write_data->mpls_pwe_exp_ttl_profile,
                                                                         mep_hw_profiles_write_data->ttl_exp.ttl,
                                                                         mep_hw_profiles_write_data->ttl_exp.exp));
        }

        if (mep_hw_profiles_write_data->flags & DNX_OAM_OAMP_PROFILE_LOCL_PORT_TO_SYSTEM_PORT_FLAG)
        {
            SHR_IF_ERR_EXIT(dnx_oam_oamp_local_port_to_system_port_set(unit,
                                                                       mep_hw_profiles_write_data->pp_port_profile,
                                                                       mep_hw_profiles_write_data->system_port));
        }
    }
#endif

    if (_SHR_IS_FLAG_SET(mep_hw_profiles_write_data->flags, DNX_OAM_OAMP_PROFILE_TRAP_TCAM_FLAG))
    {
        SHR_IF_ERR_EXIT(dnx_oam_oamp_rx_trap_codes_set(unit,
                                                       mep_hw_profiles_write_data->tcam_entry.mep_type,
                                                       mep_hw_profiles_write_data->tcam_entry.trap_code,
                                                       mep_hw_profiles_write_data->tcam_index));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_endpoint_bcm_mep_type_to_mep_db_mep_type(
    int unit,
    const bcm_oam_endpoint_type_t bcm_mep_type,
    dbal_enum_value_field_oamp_mep_type_e * mep_db_mep_type)
{

    SHR_FUNC_INIT_VARS(unit);

    switch (bcm_mep_type)
    {
        case bcmOAMEndpointTypeEthernet:
            *mep_db_mep_type = DBAL_ENUM_FVAL_OAMP_MEP_TYPE_ETH_OAM;
            break;
        case bcmOAMEndpointTypeBHHMPLS:
            *mep_db_mep_type = DBAL_ENUM_FVAL_OAMP_MEP_TYPE_Y1731_MPLSTP;
            break;
        case bcmOAMEndpointTypeBHHPwe:
            *mep_db_mep_type = DBAL_ENUM_FVAL_OAMP_MEP_TYPE_Y1731_PWE;
            break;
        case bcmOAMEndpointTypeBHHPweGAL:
            *mep_db_mep_type = DBAL_ENUM_FVAL_OAMP_MEP_TYPE_Y1731_MPLSTP;
            break;
        case bcmOAMEndpointTypeBhhSection:
            *mep_db_mep_type = DBAL_ENUM_FVAL_OAMP_MEP_TYPE_Y1731_PWE;
            break;
        case bcmOAMEndpointTypeMplsLmDmPw:
        case bcmOAMEndpointTypeMplsLmDmLsp:
        case bcmOAMEndpointTypeMplsLmDmSection:
            *mep_db_mep_type = DBAL_ENUM_FVAL_OAMP_MEP_TYPE_RFC_6374;
            break;
        default:
            SHR_ERR_EXIT(_SHR_E_PARAM, "Endpoint create error: MEP type %d is not supported.\n", bcm_mep_type);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_update_accelarated_endpoint_info_with_group_config(
    int unit,
    const uint8 *group_name,
    dnx_oam_oamp_ccm_endpoint_t * mep_db_entry)
{
    int i;
    int icc_index;
    dnx_oam_group_icc_profile_data_t icc_profile_data;
    dnx_oam_ma_name_type_e group_name_type = BCM_DNX_OAM_GROUP_NAME_TO_NAME_TYPE(group_name);

    SHR_FUNC_INIT_VARS(unit);

    if (group_name_type == DNX_OAMP_OAM_MA_NAME_TYPE_SHORT)
    {
        mep_db_entry->icc_index = DBAL_DEFINE_SHORT_ICC_INDEX_SHORT_FORMAT;
        mep_db_entry->maid =
            group_name[DNX_OAMP_OAM_GROUP_ICC_DATA_OFFSET + 1] + (group_name[DNX_OAMP_OAM_GROUP_ICC_DATA_OFFSET] << 8);
    }
    else if (group_name_type == DNX_OAMP_OAM_MA_NAME_TYPE_ICC)
    {
        for (i = 0; i < DNX_OAMP_OAM_GROUP_ICC_DATA_LENGTH; i++)
        {
            icc_profile_data[i] =
                group_name[DNX_OAMP_OAM_GROUP_ICC_DATA_OFFSET + (DNX_OAMP_OAM_GROUP_ICC_DATA_LENGTH - 1) - i];
        }

        SHR_IF_ERR_EXIT(algo_oam_db.oam_group_icc_profile.profile_get(unit, icc_profile_data, &icc_index));

        mep_db_entry->icc_index = (uint8) icc_index;

        mep_db_entry->maid =
            group_name[DNX_OAMP_OAM_GROUP_LONG_MA_NAME_DATA_OFFSET + 1] +
            (group_name[DNX_OAMP_OAM_GROUP_LONG_MA_NAME_DATA_OFFSET] << 8);
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Error:   Error in group name");
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_event_fifodma_thread(
    int unit,
    void *info)
{
    SHR_FUNC_INIT_VARS(unit);

    LOG_VERBOSE(BSL_LOG_MODULE, (BSL_META_U(unit, "dnx_oam_oamp_event_fifodma_thread - Entered\n")));

    dnx_fifodma_intr_handler(INT_TO_PTR(unit), info, NULL, NULL, NULL);

    SHR_EXIT();
exit:
    LOG_VERBOSE(BSL_LOG_MODULE, (BSL_META_U(unit, "dnx_oam_oamp_event_fifodma_thread - Thread Exiting ... \n")));
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_event_fifodma_deinit(
    int unit)
{
    int oam_oamp_event_channel;
    uint8 dma_event_interface_enable = 0;
    shr_thread_manager_handler_t dnx_oam_oamp_event_fifodma_thread_info;

    SHR_FUNC_INIT_VARS(unit);
    LOG_VERBOSE(BSL_LOG_MODULE, (BSL_META_U(unit, "dnx_oam_oamp_event_fifodma_deinit - Entered")));

    dma_event_interface_enable = dnx_data_oam.oamp.oamp_fifo_dma_event_interface_enable_get(unit);

    if (dma_event_interface_enable == 0)
    {
        LOG_VERBOSE(BSL_LOG_MODULE, (BSL_META_U(unit, "oamp_fifo_dma_event_interface_enable is 0\n")));
        SHR_FUNC_EXIT;
    }

    SHR_IF_ERR_EXIT(dnx_fifodma_info.
                    fifodma_thread_shr_thread_manager_handler.get(unit, &dnx_oam_oamp_event_fifodma_thread_info));

    if (dnx_oam_oamp_event_fifodma_thread_info != NULL)
    {
        SHR_IF_ERR_EXIT(shr_thread_manager_destroy(&dnx_oam_oamp_event_fifodma_thread_info));
        SHR_IF_ERR_EXIT(dnx_fifodma_info.fifodma_thread_shr_thread_manager_handler.set(unit, NULL));
    }

exit:

    SHR_IF_ERR_EXIT(soc_dnx_fifodma_channel_get(unit, soc_dnx_fifodma_src_oam_event, &oam_oamp_event_channel));
    soc_cmic_intr_disable(unit, INTR_FIFO_DMA(oam_oamp_event_channel));

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_event_fifodma_init(
    int unit)
{
    int thread_priority;
    shr_thread_manager_config_t thread_config_info;
    uint8 dma_event_interface_enable = 0;
    int oam_oamp_event_channel;
    shr_thread_manager_handler_t dnx_oam_oamp_event_fifodma_thread_info;

    SHR_FUNC_INIT_VARS(unit);
    LOG_VERBOSE(BSL_LOG_MODULE, (BSL_META_U(unit, "dnx_oam_oamp_event_fifodma_init - Entered\n")));

    dma_event_interface_enable = dnx_data_oam.oamp.oamp_fifo_dma_event_interface_enable_get(unit);

    if (dma_event_interface_enable == 0)
    {
        LOG_VERBOSE(BSL_LOG_MODULE, (BSL_META_U(unit, "oamp_fifo_dma_event_interface_enable is 0\n")));
        SHR_EXIT();
    }

    SHR_IF_ERR_EXIT(dnx_fifodma_info.
                    fifodma_thread_shr_thread_manager_handler.get(unit, &dnx_oam_oamp_event_fifodma_thread_info));

    if (dnx_oam_oamp_event_fifodma_thread_info)
    {

        LOG_VERBOSE(BSL_LOG_MODULE, (BSL_META_U(unit, "OAM event fifodma thread already initiated \n")));
        SHR_EXIT();
    }
    thread_priority = dnx_data_oam.oamp.oamp_fifo_dma_event_thread_priority_get(unit);

    SHR_IF_ERR_EXIT(soc_dnx_fifodma_channel_get(unit, soc_dnx_fifodma_src_oam_event, &oam_oamp_event_channel));

    shr_thread_manager_config_t_init(&thread_config_info);
    thread_config_info.name = "bcmOamEventFifodma";
    thread_config_info.bsl_module = BSL_LOG_MODULE;
    thread_config_info.type = SHR_THREAD_MANAGER_TYPE_EVENT;
    thread_config_info.interval = sal_sem_FOREVER;
    thread_config_info.callback = dnx_oam_oamp_event_fifodma_thread;
    thread_config_info.user_data = INT_TO_PTR(oam_oamp_event_channel);
    thread_config_info.thread_priority = thread_priority;
    thread_config_info.stop_timeout_usec = (10 * SECOND_USEC);
    SHR_IF_ERR_EXIT(shr_thread_manager_create(unit, &thread_config_info, &dnx_oam_oamp_event_fifodma_thread_info));
    SHR_IF_ERR_EXIT(dnx_fifodma_info.
                    fifodma_thread_shr_thread_manager_handler.set(unit, dnx_oam_oamp_event_fifodma_thread_info));

    LOG_VERBOSE(BSL_LOG_MODULE,
                (BSL_META_U(unit, "dnx_oam_oamp_event_fifodma_init - Task %s\n"), "bcmOamEventFifodma"));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_tx_pph_network_qos_set(
    int unit,
    uint32 network_qos)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAMP_TX_PPH_HEADER, &entry_handle_id));

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_NTWK_QOS, INST_SINGLE, network_qos);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

#ifdef BCM_DNX2_SUPPORT

    SHR_IF_ERR_EXIT(dnx_oam_oamp_v1_egress_inject_tx_pph_network_qos_set(unit, network_qos));
#endif

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_oam_oamp_tx_pph_network_qos_get(
    int unit,
    uint32 *network_qos)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_OAMP_TX_PPH_HEADER, &entry_handle_id));

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_NTWK_QOS, INST_SINGLE, network_qos);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}
