/** \file src/bcm/dnx/multicast/multicast.c
 * 
 *
 * General MULTICAST functionality for DNX.
 * Dedicated set of MULTICAST APIs are distributed between multicast_*.c files: \n
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
#define BSL_LOG_MODULE BSL_LS_BCMDNX_MULTICAST

/*
 * Include files.
 * {
 */

#include <soc/sand/shrextend/shrextend_debug.h>
#include <bcm/types.h>
#include <bcm/error.h>
#include <bcm_int/common/multicast.h>
#include <bcm_int/dnx/bier/bier.h>
#include <bcm_int/dnx/multicast/multicast.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_multicast.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_crps.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_bier.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_max_device.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_tdm.h>
#include <soc/dnx/swstate/auto_generated/access/dnx_bier_db_access.h>
#include <soc/dnx/dnx_err_recovery_manager.h>
#include <bcm_int/dnx/cmn/dnxcmn.h>
#include <bcm_int/dnx/auto_generated/dnx_multicast_dispatch.h>

#include "multicast_imp.h"
/*
 * }
 */

/*
 * MACROs
 * {
 */

/**
 * \brief - For SAR groups, if Egress bypass is enabled setting of the MCDB is not needed.
 */
#define DNX_MULTICAST_SAR_SKIP_MCDB(unit, is_sar) ((is_sar == TRUE) ? ((dnx_data_tdm.params.feature_get(unit, dnx_data_tdm_params_egress_bypass_enable)) ? TRUE : FALSE) : FALSE)

/*
 * }
 */

/**
 * \brief - verify that multicast group at the soc property range
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] flags - specifies whether group id is ingress/egress and also whether the id is bitmap/group id
 *   \param [in] group - group/bitmap id
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 * \see
 *   * None
 */
static shr_error_e
dnx_multicast_mc_id_verify(
    int unit,
    uint32 flags,
    bcm_multicast_t group)
{
    SHR_FUNC_INIT_VARS(unit);

    {
        if (DNX_MULTICAST_IS_INGRESS_GROUP(flags) && (group > dnx_data_multicast.params.max_ing_mc_groups_get(unit)))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Ingress multicast ID (%d) is not at the valid range (> %u)\n",
                         group, dnx_data_multicast.params.max_ing_mc_groups_get(unit));
        }
        if (DNX_MULTICAST_IS_EGRESS_GROUP(flags) && (group > dnx_data_multicast.params.max_egr_mc_groups_get(unit)))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Egress multicast ID (%d) is not at the valid range (> %u)\n",
                         group, dnx_data_multicast.params.max_egr_mc_groups_get(unit));
        }
        if (DNX_MULTICAST_IS_EGRESS_BITMAP(flags) && (group >= dnx_data_multicast.params.nof_egr_mc_bitmaps_get(unit)))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Egress bitmap ID (%d) is not at the valid range (> %u)\n",
                         group, dnx_data_multicast.params.nof_egr_mc_bitmaps_get(unit));
        }
        if (DNX_MULTICAST_IS_INGRESS_BITMAP(flags) && (group >= dnx_data_multicast.params.nof_ing_mc_bitmaps_get(unit)))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Ingress bitmap ID (%d) is not at the valid range (> %u)\n",
                         group, dnx_data_multicast.params.nof_ing_mc_bitmaps_get(unit));
        }
    }
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify function for BCM-API: bcm_dnx_multicast_create()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] flags - specifies whether group id is ingress/egress and also whether the id is bitmap/group id
 *   \param [in] group_id - group/bitmap id
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *  this verifies that the correct flags are used and that group id in appropriate range and that the group is not open
 * \see
 *   * None
 */
static shr_error_e
dnx_multicast_create_verify(
    int unit,
    uint32 flags,
    bcm_multicast_t * group_id)
{
    uint32 is_open;
    uint32 active;
    uint32 valid_flags = 0;
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(group_id, _SHR_E_PARAM, "group_id");

    valid_flags = dnx_data_multicast.params.feature_get(unit, dnx_data_multicast_params_mcdb_formats_v2) ?
        (BCM_MULTICAST_WITH_ID | BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_TYPE_PORTS_GROUP |
         BCM_MULTICAST_ELEMENT_DYNAMIC | BCM_MULTICAST_ELEMENT_STATIC | BCM_MULTICAST_BIER_256_GROUP) :
        (BCM_MULTICAST_WITH_ID | BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_EGRESS_GROUP |
         BCM_MULTICAST_EGRESS_TDM_GROUP | BCM_MULTICAST_TYPE_PORTS_GROUP | BCM_MULTICAST_BIER_256_GROUP |
         BCM_MULTICAST_SAR_GROUP);
    if (flags & ~(valid_flags))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "An unsupported bcm multicast create flag was specified : 0x%x", flags);
    }

    /*
     * Multicast without ID is not supported
     */
    if (!(flags & BCM_MULTICAST_WITH_ID))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "flag BCM_MULTICAST_WITH_ID must be used\n");
    }

    {
        /*
         * one of BCM_MULTICAST_EGRESS_GROUP/BCM_MULTICAST_INGRESS_GROUP flags must be used with this API
         */
        if (!DNX_MULTICAST_IS_INGRESS(flags) && !DNX_MULTICAST_IS_EGRESS(flags) && !DNX_MULTICAST_IS_TDM(flags))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "one of BCM_MULTICAST_EGRESS_GROUP/BCM_MULTICAST_INGRESS_GROUP flags must be used with this API\n");
        }
    }

    /*
     * Multicast SAR verification
     */
    if (DNX_MULTICAST_IS_SAR(flags))
    {
        /** Check if Egress bypass is supported and enabled for device */
        if (dnx_data_tdm.params.feature_get(unit, dnx_data_tdm_params_is_egress_bypass_supported) != TRUE)
        {
            SHR_ERR_EXIT(_SHR_E_UNAVAIL, "Egress bypass is not supported for this device!\n");
        }

        /** Check for extra flags */
        if (flags & ~(BCM_MULTICAST_SAR_GROUP | BCM_MULTICAST_WITH_ID |
                      BCM_MULTICAST_EGRESS_TDM_GROUP | BCM_MULTICAST_EGRESS_GROUP))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported flags (0x%x) were specified for SAR group!", flags);
        }
    }

    /*
     * Multicast TDM verification
     */
    if (DNX_MULTICAST_IS_TDM(flags))
    {
        if (dnx_data_tdm.params.feature_get(unit, dnx_data_tdm_params_is_supported) != TRUE)
        {
            SHR_ERR_EXIT(_SHR_E_UNAVAIL, "TDM is not supported for this device\n");
        }
        if (flags & ~(BCM_MULTICAST_EGRESS_TDM_GROUP | BCM_MULTICAST_WITH_ID | BCM_MULTICAST_SAR_GROUP))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "An unsupported flags (0x%x) was specified for tdm group", flags);
        }
    }

    /*
     * BIER verification
     */
    if (DNX_MULTICAST_IS_BIER(flags))
    {
        SHR_INVOKE_VERIFY_DNXC(dnx_multicast_bfr_id_verify(unit, flags, *group_id));
        SHR_EXIT();
    }
    else
    {
        uint8 bier_inited = 0;
        SHR_IF_ERR_EXIT(dnx_bier_db.is_init(unit, &bier_inited));
        if (bier_inited && (*group_id < dnx_data_bier.params.nof_bfr_entries_get(unit)))
        {
            if (DNX_MULTICAST_IS_INGRESS(flags))
            {
                SHR_IF_ERR_EXIT(dnx_bier_db.ingress.active.get(unit, *group_id, &active));
            }
            else
            {
                SHR_IF_ERR_EXIT(dnx_bier_db.egress.active.get(unit, *group_id, &active));
            }
            if (active)
            {
                SHR_ERR_EXIT(_SHR_E_EXISTS, "Multicast ID is already used for BIER\n");
            }
        }
    }

    /*
     * Verify MC ID is in the valid range
     */
    SHR_INVOKE_VERIFY_DNXC(dnx_multicast_mc_id_verify(unit, flags, *group_id));

    /*
     * Verify that the group is not open
     */
    SHR_IF_ERR_EXIT(dnx_multicast_group_open_get(unit, *group_id, flags, &is_open));
    if (is_open)
    {
        SHR_ERR_EXIT(_SHR_E_EXISTS, "Multicast ID is already created\n");
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify function for BCM-API: bcm_dnx_multicast_destroy()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] flags - specifies whether group id is ingress/egress and also whether the id is bitmap/group id
 *   \param [in] group_id - group/bitmap id
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *  this verifies that the group id in appropriate range and that the group/bitmap is open
 * \see
 *   * None
 */
static shr_error_e
dnx_multicast_destroy_verify(
    int unit,
    uint32 flags,
    bcm_multicast_t group_id)
{
    uint32 group_found = FALSE, group_is_open;
    int set_size;
    uint32 valid_flags = 0;
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Verify valid flags
     */
    valid_flags = dnx_data_multicast.params.feature_get(unit, dnx_data_multicast_params_mcdb_formats_v2) ?
        (BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_TYPE_PORTS_GROUP | BCM_MULTICAST_ELEMENT_DYNAMIC |
         BCM_MULTICAST_ELEMENT_STATIC | BCM_MULTICAST_BIER_256_GROUP) : (BCM_MULTICAST_INGRESS_GROUP |
                                                                         BCM_MULTICAST_EGRESS_GROUP |
                                                                         BCM_MULTICAST_TYPE_PORTS_GROUP |
                                                                         BCM_MULTICAST_BIER_256_GROUP);
    if (flags & ~(valid_flags))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "An unsupported bcm multicast destroy flag was specified : 0x%x", flags);
    }

    {
        /*
         * bitmap
         */
        if (DNX_MULTICAST_IS_BITMAP(flags))
        {
            if (DNX_MULTICAST_IS_INGRESS(flags) && group_id <= dnx_data_multicast.params.nof_ing_mc_bitmaps_get(unit))
            {
                SHR_IF_ERR_EXIT(dnx_multicast_group_open_get
                                (unit, group_id, BCM_MULTICAST_TYPE_PORTS_GROUP | BCM_MULTICAST_INGRESS_GROUP,
                                 &group_is_open));
                group_found |= group_is_open;
            }
            if (DNX_MULTICAST_IS_EGRESS(flags) && group_id <= dnx_data_multicast.params.nof_egr_mc_bitmaps_get(unit))
            {
                SHR_IF_ERR_EXIT(dnx_multicast_group_open_get
                                (unit, group_id, BCM_MULTICAST_TYPE_PORTS_GROUP | BCM_MULTICAST_EGRESS_GROUP,
                                 &group_is_open));
                group_found |= group_is_open;
            }
        }
        else
            /*
             * link list
             */
        {
            /*
             * ingress and egress multicast group are destroyed together cause flags doesn't have ing/egr indication
             */
            if (DNX_MULTICAST_IS_INGRESS(flags) && group_id <= dnx_data_multicast.params.max_ing_mc_groups_get(unit))
            {
                SHR_IF_ERR_EXIT(dnx_multicast_group_open_get
                                (unit, group_id, BCM_MULTICAST_INGRESS_GROUP, &group_is_open));
                group_found |= group_is_open;
            }
            if (DNX_MULTICAST_IS_EGRESS(flags) && group_id <= dnx_data_multicast.params.max_egr_mc_groups_get(unit))
            {
                SHR_IF_ERR_EXIT(dnx_multicast_group_open_get
                                (unit, group_id, BCM_MULTICAST_EGRESS_GROUP, &group_is_open));
                group_found |= group_is_open;
            }
        }
    }

    /*
     * BIER
     */
    if (DNX_MULTICAST_IS_BIER(flags))
    {
        if (!DNX_MULTICAST_IS_INGRESS(flags) && !DNX_MULTICAST_IS_EGRESS(flags))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "one of BCM_MULTICAST_EGRESS_GROUP/BCM_MULTICAST_INGRESS_GROUP flags must be used with this API\n");
        }
        if (group_id < dnx_data_bier.params.nof_bfr_entries_get(unit))
        {
            SHR_IF_ERR_EXIT(dnx_bier_db.set_size.get(unit, group_id, &set_size));
            group_found |= set_size ? TRUE : FALSE;
        }
        else
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "BIER group id is out of range!!\n");

        }
    }

    /*
     * verify that at least one of the groups are open
     */
    if (group_found == FALSE)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "group ID (%u) is not created\n", group_id);
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify function for BCM-API: bcm_dnx_multicast_add/delete/set/get()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] group - group/bitmap id
 *   \param [in] flags - specifies whether group id is ingress/egress and also whether the id is bitmap/group id
 *   \param [in] nof_replications - specifies the rep_array size
 *   \param [in] rep_array - contains the group/bitmap replications
 *   \param [in] api_indication - indicates from which API the verification function was called
 *   \param [in] rep_count - replication count, relevant only for the case when verify is called from the Get API
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *   this verifies that the the number of replications are bigger than zero and that
 *   the group id in appropriate range and that the group is open and that the flags are valid
 *   the bitmap/group creation is always with it so BCM_MULTICAST_WITH_ID always need to be used.
 * \see
 *   * None
 */
static shr_error_e
dnx_multicast_add_delete_set_get_verify(
    int unit,
    bcm_multicast_t group,
    uint32 flags,
    int nof_replications,
    bcm_multicast_replication_t * rep_array,
    dnx_multicast_api_indication_t api_indication,
    int *rep_count)
{
    uint32 is_open;
    uint8 is_tdm = 0;
    uint8 is_sar = 0;
    bcm_multicast_t group_id;
    bcm_port_t local_port = 0;
    dnx_algo_port_info_s port_info;
    uint32 valid_flags = 0;
    SHR_FUNC_INIT_VARS(unit);

    if (nof_replications > 0)
    {
        SHR_NULL_CHECK(rep_array, _SHR_E_PARAM, "replication array");
    }

    if (api_indication == DNX_MULTICAST_API_GET)
    {
        SHR_NULL_CHECK(rep_count, _SHR_E_PARAM, "replication count");
    }

    /*
     * Verify valid flags
     */
    valid_flags = dnx_data_multicast.params.feature_get(unit, dnx_data_multicast_params_mcdb_formats_v2) ?
        (BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_TYPE_PORTS_GROUP | BCM_MULTICAST_ELEMENT_DYNAMIC |
         BCM_MULTICAST_ELEMENT_STATIC | BCM_MULTICAST_WITH_ID | BCM_MULTICAST_REMOVE_ALL) :
        (BCM_MULTICAST_WITH_ID | BCM_MULTICAST_REMOVE_ALL | BCM_MULTICAST_INGRESS_GROUP |
         BCM_MULTICAST_EGRESS_GROUP | BCM_MULTICAST_TYPE_PORTS_GROUP);
    if (flags & ~(valid_flags))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "An unsupported bcm multicast destroy flag was specified : 0x%x", flags);
    }

    /*
     * verify that number of replications are bigger than zero
     */
    if (nof_replications < 0 && !(flags & BCM_MULTICAST_REMOVE_ALL))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "number of replications (%d) must not be negative\n", nof_replications);
    }

    group_id = _BCM_MULTICAST_ID_GET(group);
    SHR_INVOKE_VERIFY_DNXC(dnx_multicast_mc_id_verify(unit, flags, group_id));

    {
        /*
         * adding bitmap flag for internal group verification
         */
        if ((_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_ING_BMP) ||
            (_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_EGR_BMP))
        {
            flags |= BCM_MULTICAST_TYPE_PORTS_GROUP;
        }

#ifdef BCM_DNX2_SUPPORT
        /*
         * If it is Egress non-bitmap group, check if TDM or SAR
         */
        if (!DNX_MULTICAST_IS_INGRESS(flags) && !DNX_MULTICAST_IS_BITMAP(flags))
        {
            SHR_IF_ERR_EXIT(multicast_db.group_is_tdm.is_allocated(unit, group_id, &is_tdm));
            SHR_IF_ERR_EXIT(multicast_db.group_is_sar.is_allocated(unit, group_id, &is_sar));
        }
#endif

        /*
         * Multicast SAR verification
         */
        if (is_sar)
        {
            /** Verify flags */
            if (flags & ~(BCM_MULTICAST_REMOVE_ALL | BCM_MULTICAST_EGRESS_GROUP))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported flags (0x%x) were specified for SAR group", flags);
            }

            if (api_indication != DNX_MULTICAST_API_GET)
            {

                /** Verify number of replications */
                if (nof_replications > 1)
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM, "SAR MC groups can contain only 1 member!");
                }

                /** Verify member port type */
                if (!BCM_GPORT_IS_LOCAL(rep_array[0].port)
                    && ((rep_array[0].port < 0) || (rep_array[0].port >= SOC_MAX_NUM_PORTS)))
                {
                    SHR_ERR_EXIT(_SHR_E_PORT, "Invalid Port for SAR group!\n");
                }

                local_port =
                    (BCM_GPORT_IS_LOCAL(rep_array[0].port)) ? BCM_GPORT_LOCAL_GET(rep_array[0].
                                                                                  port) : rep_array[0].port;
                SHR_IF_ERR_EXIT(dnx_algo_port_info_get(unit, local_port, &port_info));
                if (!DNX_ALGO_PORT_TYPE_IS_FRAMER_SAR(unit, port_info, TRUE))
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM, "Member port type expected to be SAR!");
                }
            }

            /** Verify existing members */
            if ((api_indication == DNX_MULTICAST_API_ADD) || (api_indication == DNX_MULTICAST_API_DELETE))
            {
                bcm_multicast_replication_t out_rep_array;
                int out_rep_count = 0;
                SHR_IF_ERR_EXIT(bcm_dnx_multicast_get(unit, group, flags, 1, &out_rep_array, &out_rep_count));

                /** For 'add' API check if a replication already exists in the group */
                if ((out_rep_count > 0) && (api_indication == DNX_MULTICAST_API_ADD))
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM, "SAR group already contains a replication!");
                }

                /** For 'delete' API check if the provided replication is the same as the one set in the group */
                if ((out_rep_count > 0) && (out_rep_array.port != rep_array->port)
                    && (!(flags & BCM_MULTICAST_REMOVE_ALL)))
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM,
                                 "Input port does not match the existing port in the SAT group - input port 0x%x; existing port 0x%x!\n",
                                 rep_array->port, out_rep_array.port);
                }
            }
        }

        /*
         * Multicast TDM verification
         */
        if (is_tdm)
        {
            if (flags & ~(BCM_MULTICAST_REMOVE_ALL | BCM_MULTICAST_EGRESS_GROUP))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "An unsupported flags (0x%x) was specified for tdm group", flags);
            }
        }
        else
        {
            /*
             * verify that one of BCM_MULTICAST_EGRESS_GROUP/BCM_MULTICAST_INGRESS_GROUP flags used with this API
             */
            if (!DNX_MULTICAST_IS_INGRESS(flags) && !DNX_MULTICAST_IS_EGRESS(flags))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM,
                             "one of BCM_MULTICAST_EGRESS_GROUP/BCM_MULTICAST_INGRESS_GROUP flags must be used with this API\n");
            }
        }

        /*
         * BCM_MULTICAST_EGRESS_GROUP & BCM_MULTICAST_INGRESS_GROUP flags should not be used together
         */
        if (DNX_MULTICAST_IS_INGRESS(flags) && DNX_MULTICAST_IS_EGRESS(flags))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "one of BCM_MULTICAST_EGRESS_GROUP/BCM_MULTICAST_INGRESS_GROUP flags must be used with this API\n");
        }
    }

    /*
     * verify that the group is open
     */
    SHR_IF_ERR_EXIT(dnx_multicast_group_open_get(unit, group_id, flags, &is_open));
    if (is_open == FALSE)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Multicast ID (%d) is not created. Flags: 0x%X\n", group_id, flags);
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - creates multicast empty (ingress/egress) group/bitmap/element.
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] flags - specifies whether group id is ingress/egress and also whether the id is bitmap/group id
 *   \param [in] group - group/bitmap/element id.
 *   \param [in] core_id - core_id
 *
 * \remark
 * allocate an mcdb entry and move the existing one if needed
 * \see
 *   * None
 */
static int
dnx_multicast_create_allocation(
    int unit,
    uint32 flags,
    bcm_multicast_t group,
    uint32 core_id)
{
    uint8 is_allocated = FALSE;
    uint32 entry_id;
    SHR_FUNC_INIT_VARS(unit);

    if (DNX_MULTICAST_IS_MC_ELEMENT_DYNAMIC(flags))
    {
        /** If we reached this point, we already checked that the Dynamic ME is not opened,
         * which means no entry is allocated for it. */
        is_allocated = FALSE;
    }
    else
    {
        /** If desired entry already allocated, relocate the existing entry otherwise allocate it */
        SHR_IF_ERR_EXIT(dnx_multicast_id_to_entry(unit, group, DNX_MULTICAST_IS_BITMAP(flags),
                                                  DNX_MULTICAST_IS_INGRESS(flags), FALSE, core_id, &entry_id));
    }

    SHR_IF_ERR_EXIT(multicast_db.mcdb.is_allocated(unit, entry_id, &is_allocated));
    if (is_allocated)
    {
        SHR_IF_ERR_EXIT(dnx_multicast_entry_relocate(unit, flags, group, core_id, entry_id));
    }
    else
    {
        SHR_IF_ERR_EXIT(dnx_multicast_entry_allocate(unit, flags, core_id, TRUE, &entry_id));
    }


    /*
     * clear entry
     */
    SHR_IF_ERR_EXIT(dnx_multicast_entry_clear
                    (unit, entry_id, DNX_MULTICAST_IS_TDM(flags), DNX_MULTICAST_IS_BITMAP(flags)));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - creates multicast empty (ingress/egress) group/bitmap.
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] group - group/bitmap id. see remarks
 *   \param [in] flags - specifies whether group id is ingress/egress and also whether the id is bitmap/group id
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *   the bitmap/group creation is always with it so BCM_MULTICAST_WITH_ID always need to be used.
 *   for bitmap the group encapsulated with bitmap indication. this way other API's will recognize this group as bitmap
 * \see
 *   * None
 */
int
bcm_dnx_multicast_create(
    int unit,
    uint32 flags,
    bcm_multicast_t * group)
{
    uint32 core_id;
    uint32 bmp_flags = 0;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    *group = _BCM_MULTICAST_ID_GET(*group);
    SHR_INVOKE_VERIFY_DNXC(dnx_multicast_create_verify(unit, flags, group));

    /** create bier group */
    if (DNX_MULTICAST_IS_BIER(flags))
    {
        SHR_IF_ERR_EXIT(dnx_multicast_bier_create(unit, flags, *group));

        /** mark group as open. HW for ingress & SW for egress */
        SHR_IF_ERR_EXIT(dnx_multicast_group_open_set(unit, *group, flags, TRUE));
        SHR_EXIT();
    }
#ifdef BCM_DNX2_SUPPORT
    /** Create SAR group */
    if (DNX_MULTICAST_IS_SAR(flags))
    {
        SHR_IF_ERR_EXIT(multicast_db.group_is_sar.allocate_single(unit, DNX_ALGO_RES_ALLOCATE_WITH_ID, NULL, group));
    }

    /** mark group as TDM */
    if (DNX_MULTICAST_IS_TDM(flags) && !DNX_MULTICAST_SAR_SKIP_MCDB(unit, DNX_MULTICAST_IS_SAR(flags)))
    {
        SHR_IF_ERR_EXIT(multicast_db.group_is_tdm.allocate_single(unit, DNX_ALGO_RES_ALLOCATE_WITH_ID, NULL, group));
    }
#endif
    /** allocation */
    if (DNX_MULTICAST_IS_INGRESS(flags) || DNX_MULTICAST_IS_MC_ELEMENT_DYNAMIC(flags) ||
        DNX_MULTICAST_IS_MC_ELEMENT_STATIC(flags))
    {
        SHR_IF_ERR_EXIT(dnx_multicast_create_allocation(unit, flags & (~BCM_MULTICAST_EGRESS_GROUP), *group, 0));
    }
    if (DNX_MULTICAST_IS_EGRESS(flags) && !DNX_MULTICAST_SAR_SKIP_MCDB(unit, DNX_MULTICAST_IS_SAR(flags)))
    {
        DNXCMN_CORES_ITER(unit, BCM_CORE_ALL, core_id)
        {
            SHR_IF_ERR_EXIT(dnx_multicast_create_allocation
                            (unit, flags & (~BCM_MULTICAST_INGRESS_GROUP), *group, core_id));
        }
    }

    /** mark group as open. HW for ingress & SW for egress */
    SHR_IF_ERR_EXIT(dnx_multicast_group_open_set(unit, *group, flags, TRUE));

    /** handle bitmap new group */
    if (DNX_MULTICAST_IS_BITMAP(flags))
    {
        {
            bmp_flags = 0;

            /** set the representation for bitmap */
            if (DNX_MULTICAST_IS_INGRESS(flags))
            {
                bmp_flags |= _BCM_MULTICAST_TYPE_ING_BMP;
            }
            if (DNX_MULTICAST_IS_EGRESS(flags))
            {
                bmp_flags |= _BCM_MULTICAST_TYPE_EGR_BMP;
            }
            _BCM_MULTICAST_GROUP_SET(*group, bmp_flags, *group);

            /** set group to be empty - this will actually allocate an empty bitmap */
            SHR_IF_ERR_EXIT(bcm_dnx_multicast_set(unit, *group, flags, 0, NULL));
        }
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - destroy the ingress and egress multicast for bitmap/groups id.
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] flags - specifies whether group id is ingress/egress and also whether the id is bitmap/group id
 *   \param [in] group - group/bitmap id created at bcm_multicast_create API
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_multicast_group_destroy(
    int unit,
    uint32 flags,
    bcm_multicast_t group)
{
    uint32 entry_id;
    uint32 core_id = 0;
    uint32 tmp_flags;
    uint32 is_open = FALSE;
#ifdef BCM_DNX2_SUPPORT
    uint8 is_tdm_allocated;
#endif
    uint8 is_sar_allocated = FALSE;
    dnx_multicast_mcdb_dbal_field_t entry_val;
    uint32 cur_entry_replaced;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_multicast_destroy_verify(unit, flags, _BCM_MULTICAST_ID_GET(group)));

    /*
     * try to destroy bier group. if this is not an bier group continue to multicast
     */
    if (DNX_MULTICAST_IS_BIER(flags))
    {
        SHR_IF_ERR_EXIT(dnx_multicast_bier_destroy(unit, flags, group));

        /** mark group as close. HW for ingress & SW for egress */
        SHR_IF_ERR_EXIT(dnx_multicast_group_open_set(unit, _BCM_MULTICAST_ID_GET(group), flags, FALSE));

        SHR_EXIT();
    }

    /*
     * Free Ingress link lists, bitmaps or elements, close the group if open.
     */
    if (DNX_MULTICAST_IS_INGRESS(flags) || DNX_MULTICAST_IS_MC_ELEMENT_DYNAMIC(flags) ||
        DNX_MULTICAST_IS_MC_ELEMENT_STATIC(flags) || (!DNX_MULTICAST_IS_EGRESS(flags)
                                                      && DNX_MULTICAST_IS_BITMAP(flags)))
    {
        tmp_flags = flags & (~BCM_MULTICAST_EGRESS_GROUP);
        SHR_IF_ERR_EXIT(dnx_multicast_group_open_get(unit, _BCM_MULTICAST_ID_GET(group), tmp_flags, &is_open));
        if (is_open)
        {
            SHR_IF_ERR_EXIT(bcm_dnx_multicast_delete(unit, group, tmp_flags | BCM_MULTICAST_REMOVE_ALL, 0, NULL));
            SHR_IF_ERR_EXIT(dnx_multicast_id_to_entry(unit, _BCM_MULTICAST_ID_GET(group),
                                                      DNX_MULTICAST_IS_BITMAP(flags), TRUE,
                                                      DNX_MULTICAST_IS_MC_ELEMENT_DYNAMIC(flags), core_id, &entry_id));

            SHR_IF_ERR_EXIT(multicast_db.mcdb.free_single(unit, entry_id, NULL));
            SHR_IF_ERR_EXIT(dnx_multicast_group_open_set(unit, _BCM_MULTICAST_ID_GET(group), tmp_flags, FALSE));
        }
    }

    /*
     * free egress link list and close the group if open.
     */
    if (DNX_MULTICAST_IS_EGRESS(flags))
    {
        tmp_flags = flags & (~BCM_MULTICAST_INGRESS_GROUP);
        SHR_IF_ERR_EXIT(dnx_multicast_group_open_get(unit, _BCM_MULTICAST_ID_GET(group), tmp_flags, &is_open));
        if (is_open)
        {
#ifdef BCM_DNX2_SUPPORT
            /** Check if SAR group if allocated */
            SHR_IF_ERR_EXIT(multicast_db.
                            group_is_sar.is_allocated(unit, _BCM_MULTICAST_ID_GET(group), &is_sar_allocated));
            if (is_sar_allocated)
            {
                /** Free SAR group */
                SHR_IF_ERR_EXIT(multicast_db.group_is_sar.free_single(unit, _BCM_MULTICAST_ID_GET(group), NULL));
            }
#endif
            if (!DNX_MULTICAST_SAR_SKIP_MCDB(unit, is_sar_allocated))
            {
                SHR_IF_ERR_EXIT(bcm_dnx_multicast_delete(unit, group, tmp_flags | BCM_MULTICAST_REMOVE_ALL, 0, NULL));
                DNXCMN_CORES_ITER(unit, BCM_CORE_ALL, core_id)
                {
                    SHR_IF_ERR_EXIT(dnx_multicast_id_to_entry(unit, _BCM_MULTICAST_ID_GET(group),
                                                              DNX_MULTICAST_IS_BITMAP(flags), FALSE, FALSE, core_id,
                                                              &entry_id));
                    /** for bitmap cases - need to release first bitmap entry */
                    if (DNX_MULTICAST_IS_BITMAP(flags))
                    {
                        SHR_IF_ERR_EXIT(dnx_multicast_entry_get(unit, entry_id, &entry_val));
                        SHR_IF_ERR_EXIT(dnx_multicast_entry_remove
                                        (unit, entry_val.bmp_ptr, entry_id, DNX_MULTICAST_END_OF_LIST_PTR, TRUE,
                                         &cur_entry_replaced));
                    }
                    SHR_IF_ERR_EXIT(multicast_db.mcdb.free_single(unit, entry_id, NULL));
                }
#ifdef BCM_DNX2_SUPPORT
                /** free tdm group if allocated*/
                SHR_IF_ERR_EXIT(multicast_db.
                                group_is_tdm.is_allocated(unit, _BCM_MULTICAST_ID_GET(group), &is_tdm_allocated));
                if (is_tdm_allocated)
                {
                    SHR_IF_ERR_EXIT(multicast_db.group_is_tdm.free_single(unit, group, NULL));
                }
#endif
            }

            SHR_IF_ERR_EXIT(dnx_multicast_group_open_set(unit, _BCM_MULTICAST_ID_GET(group), tmp_flags, FALSE));
        }
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - destroy the ingress and egress multicast for bitmap/groups id.
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] group - group/bitmap id created at bcm_multicast_create API
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_multicast_destroy(
    int unit,
    bcm_multicast_t group)
{
    uint32 flags;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);


    if (_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_ING_BMP)
    {
        flags = BCM_MULTICAST_TYPE_PORTS_GROUP | BCM_MULTICAST_INGRESS_GROUP;
    }
    else if (_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_EGR_BMP)
    {
        flags = BCM_MULTICAST_TYPE_PORTS_GROUP | BCM_MULTICAST_EGRESS_GROUP;
    }
    else
    {
        flags = BCM_MULTICAST_EGRESS_GROUP | BCM_MULTICAST_INGRESS_GROUP;
    }

    SHR_IF_ERR_EXIT(bcm_dnx_multicast_group_destroy(unit, flags, group));

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - set the content (replications) of a multicast group/bitmap
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] group - group/bitmap id
 *   \param [in] flags - specifies whether group id is ingress/egress and also whether the id is bitmap/group id
 *   \param [in] nof_replications - specifies the rep_array size
 *   \param [in] rep_array - contains the group/bitmap replications
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_multicast_set(
    int unit,
    bcm_multicast_t group,
    uint32 flags,
    int nof_replications,
    bcm_multicast_replication_t * rep_array)
{
    uint8 is_tdm_allocated = FALSE;
    uint8 is_sar_allocated = FALSE;
    uint8 is_bitmap = FALSE;
    bcm_port_t local_port = 0;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_multicast_add_delete_set_get_verify
                           (unit, group, flags, nof_replications, rep_array, DNX_MULTICAST_API_SET, NULL));

    {
        if ((_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_ING_BMP) ||
            (_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_EGR_BMP))
        {
            is_bitmap = TRUE;
        }
    }

    if (is_bitmap == TRUE)
    {
        /** handle bitmap case */
        SHR_IF_ERR_EXIT(dnx_multicast_bitmap_create
                        (unit, _BCM_MULTICAST_ID_GET(group), flags, TRUE, nof_replications, rep_array));
    }
    else
    {
#ifdef BCM_DNX2_SUPPORT
        /** handle TDM case */
        if (!DNX_MULTICAST_IS_INGRESS(flags) && !DNX_MULTICAST_IS_BITMAP(flags)
            && !DNX_MULTICAST_IS_MC_ELEMENT_STATIC(flags) && !DNX_MULTICAST_IS_MC_ELEMENT_DYNAMIC(flags))
        {
            SHR_IF_ERR_EXIT(multicast_db.group_is_tdm.is_allocated(unit, group, &is_tdm_allocated));
            SHR_IF_ERR_EXIT(multicast_db.
                            group_is_sar.is_allocated(unit, _BCM_MULTICAST_ID_GET(group), &is_sar_allocated));
        }
#endif
        if (DNX_MULTICAST_SAR_SKIP_MCDB(unit, is_sar_allocated))
        {
            /** Set channel for Multicast SAR group */
            local_port = (BCM_GPORT_IS_LOCAL(rep_array->port)) ? BCM_GPORT_LOCAL_GET(rep_array->port) : rep_array->port;
            SHR_IF_ERR_EXIT(dnx_multicast_group_sar_port_set(unit, _BCM_MULTICAST_ID_GET(group), local_port));
        }
        else
        {
            if (is_tdm_allocated)
            {
                SHR_IF_ERR_EXIT(dnx_multicast_tdm_set(unit, group, flags, nof_replications, rep_array));
            }
            else
            {
                /** next link list with replications created and the old link list is removed */
                SHR_IF_ERR_EXIT(dnx_multicast_linklist_create(unit, group, flags, TRUE, nof_replications, rep_array));
            }
        }
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - get the content (replications) of a multicast group/bitmap.
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] group - group/bitmap id
 *   \param [in] flags - specifies whether group id is ingress/egress and also whether the id is bitmap/group id
 *   \param [in] max_replications - specifies the rep_array size
 *   \param [in,out] out_rep_array - pointer to the the group/bitmap replications array
 *   \param [in,out] rep_count - pointer to number of replications
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   See out_rep_array above - pointer to the the group/bitmap replications array read from HW
 *   See rep_count - pointer to number of replications read from HW
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_multicast_get(
    int unit,
    bcm_multicast_t group,
    uint32 flags,
    int max_replications,
    bcm_multicast_replication_t * out_rep_array,
    int *rep_count)
{
    bcm_core_t core_id = 0;
    uint32 channel_id = 0;
    uint8 is_tdm_allocated = FALSE;
    uint8 is_sar_allocated = FALSE;
    uint8 is_bitmap = FALSE;
    bcm_port_t sar_port_logical = 0;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_multicast_add_delete_set_get_verify
                           (unit, group, flags, max_replications, out_rep_array, DNX_MULTICAST_API_GET, rep_count));

    {
        if ((_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_ING_BMP) ||
            (_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_EGR_BMP))
        {
            is_bitmap = TRUE;
        }
    }

    if (is_bitmap == TRUE)
    {
        /** handle bitmap case */
        SHR_IF_ERR_EXIT(dnx_multicast_bitmap_get
                        (unit, _BCM_MULTICAST_ID_GET(group), flags, max_replications, out_rep_array, rep_count));
    }
    else
    {
#ifdef BCM_DNX2_SUPPORT
        /** handle TDM case */
        if (!DNX_MULTICAST_IS_INGRESS(flags) && !DNX_MULTICAST_IS_BITMAP(flags)
            && !DNX_MULTICAST_IS_MC_ELEMENT_STATIC(flags) && !DNX_MULTICAST_IS_MC_ELEMENT_DYNAMIC(flags))
        {
            SHR_IF_ERR_EXIT(multicast_db.group_is_tdm.is_allocated(unit, group, &is_tdm_allocated));
            SHR_IF_ERR_EXIT(multicast_db.
                            group_is_sar.is_allocated(unit, _BCM_MULTICAST_ID_GET(group), &is_sar_allocated));
        }
#endif
        if (DNX_MULTICAST_SAR_SKIP_MCDB(unit, is_sar_allocated))
        {
            /** Multicast SAR group */
            DNXCMN_CORES_ITER(unit, BCM_CORE_ALL, core_id)
            {
                SHR_IF_ERR_EXIT(dnx_multicast_sar_group_channel_get(unit, core_id, group, &channel_id));
                SHR_IF_ERR_EXIT(dnx_algo_port_sar_channel_logical_get(unit, channel_id, &sar_port_logical));
                if (sar_port_logical != BCM_PORT_INVALID)
                {
                    out_rep_array[core_id].port = sar_port_logical;
                    *rep_count += 1;
                }
            }
        }
        else
        {
            if (is_tdm_allocated)
            {
                SHR_IF_ERR_EXIT(dnx_multicast_tdm_get(unit, group, flags, max_replications, out_rep_array, rep_count));
            }
            else
            {
                /** Go through the link list in order to get the replications */
                SHR_IF_ERR_EXIT(dnx_multicast_linklist_iter(unit, group, flags, NULL, DNX_MULTICAST_ENTRY_ITER_GET,
                                                            max_replications, out_rep_array, rep_count));
            }
        }
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - Adds multicast destinations for multicast group/bitmap.
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] group - group/bitmap id
 *   \param [in] flags - specifies whether group id is ingress/egress and also whether the id is bitmap/group id
 *   \param [in] nof_replications - specifies the rep_array size
 *   \param [in] rep_array - contains the group/bitmap replications
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_multicast_add(
    int unit,
    bcm_multicast_t group,
    uint32 flags,
    int nof_replications,
    bcm_multicast_replication_t * rep_array)
{
    uint8 is_tdm_allocated = FALSE;
    uint8 is_sar_allocated = FALSE;
    uint8 is_bitmap = FALSE;
    bcm_port_t local_port = 0;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_multicast_add_delete_set_get_verify
                           (unit, group, flags, nof_replications, rep_array, DNX_MULTICAST_API_ADD, NULL));

    {
        if ((_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_ING_BMP) ||
            (_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_EGR_BMP))
        {
            is_bitmap = TRUE;
        }
    }

    /*
     * handle bitmap case
     */
    if (is_bitmap == TRUE)
    {
        SHR_IF_ERR_EXIT(dnx_multicast_bitmap_create
                        (unit, _BCM_MULTICAST_ID_GET(group), flags, FALSE, nof_replications, rep_array));
    }
    else
    {
#ifdef BCM_DNX2_SUPPORT
        /*
         * handle TDM case
         */
        if (!DNX_MULTICAST_IS_INGRESS(flags) && !DNX_MULTICAST_IS_BITMAP(flags)
            && !DNX_MULTICAST_IS_MC_ELEMENT_STATIC(flags) && !DNX_MULTICAST_IS_MC_ELEMENT_DYNAMIC(flags))
        {
            SHR_IF_ERR_EXIT(multicast_db.group_is_tdm.is_allocated(unit, group, &is_tdm_allocated));
            SHR_IF_ERR_EXIT(multicast_db.
                            group_is_sar.is_allocated(unit, _BCM_MULTICAST_ID_GET(group), &is_sar_allocated));
        }
#endif
        if (DNX_MULTICAST_SAR_SKIP_MCDB(unit, is_sar_allocated))
        {
            /** When in bypass mode, add channel for Multicast SAR group */
            local_port = (BCM_GPORT_IS_LOCAL(rep_array->port)) ? BCM_GPORT_LOCAL_GET(rep_array->port) : rep_array->port;
            SHR_IF_ERR_EXIT(dnx_multicast_group_sar_port_set(unit, _BCM_MULTICAST_ID_GET(group), local_port));
        }
        else
        {
            if (is_tdm_allocated)
            {
                SHR_IF_ERR_EXIT(dnx_multicast_tdm_add(unit, group, flags, nof_replications, rep_array));
            }
            else
            {
                /*
                 * create link list with new replications
                 */
                SHR_IF_ERR_EXIT(dnx_multicast_linklist_create(unit, group, flags, FALSE, nof_replications, rep_array));
            }
        }
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - Removes multicast destinations from multicast group/bitmap.
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] group - group/bitmap id
 *   \param [in] flags - specifies whether group id is ingress/egress and also whether the id is bitmap/group id
 *   \param [in] nof_replications - specifies the rep_array size
 *   \param [in] rep_array - contains the group/bitmap replications
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_multicast_delete(
    int unit,
    bcm_multicast_t group,
    uint32 flags,
    int nof_replications,
    bcm_multicast_replication_t * rep_array)
{
    uint8 is_tdm_allocated = FALSE;
    uint8 is_sar_allocated = FALSE;
    uint8 is_bitmap = FALSE;
    uint32 action, rep_exist;
    int rep_count_out;
    bcm_core_t core_id;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_multicast_add_delete_set_get_verify
                           (unit, group, flags, nof_replications, rep_array, DNX_MULTICAST_API_DELETE, NULL));

    action =
        (flags & BCM_MULTICAST_REMOVE_ALL) ? DNX_MULTICAST_ENTRY_ITER_REMOVE_ALL : DNX_MULTICAST_ENTRY_ITER_REMOVE_LIST;

    {
        if ((_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_ING_BMP) ||
            (_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_EGR_BMP))
        {
            is_bitmap = TRUE;
        }
    }

    /** Go through the link list in order to find the replications and delete them */
    if (is_bitmap == TRUE)
    {
        if (flags & BCM_MULTICAST_REMOVE_ALL)
        {
            /** if remove all set the group to 0 instead. */
            SHR_IF_ERR_EXIT(bcm_dnx_multicast_set(unit, group, flags, 0, NULL));
        }
        else
        {
            SHR_IF_ERR_EXIT(dnx_multicast_bitmap_delete
                            (unit, _BCM_MULTICAST_ID_GET(group), flags, action, nof_replications, rep_array));
        }
    }
    else
    {
#ifdef BCM_DNX2_SUPPORT
        /** handle TDM case */
        if (!DNX_MULTICAST_IS_INGRESS(flags) && !DNX_MULTICAST_IS_BITMAP(flags)
            && !DNX_MULTICAST_IS_MC_ELEMENT_STATIC(flags) && !DNX_MULTICAST_IS_MC_ELEMENT_DYNAMIC(flags))
        {
            SHR_IF_ERR_EXIT(multicast_db.group_is_tdm.is_allocated(unit, group, &is_tdm_allocated));
            SHR_IF_ERR_EXIT(multicast_db.group_is_sar.is_allocated(unit, group, &is_sar_allocated));
        }
#endif
        if (DNX_MULTICAST_SAR_SKIP_MCDB(unit, is_sar_allocated))
        {
            /** Unmap the replication's channel from the SAR group */
            SHR_IF_ERR_EXIT(dnx_multicast_group_sar_port_set(unit, _BCM_MULTICAST_ID_GET(group), BCM_PORT_INVALID));
        }
        else
        {
            if (is_tdm_allocated)
            {
                SHR_IF_ERR_EXIT(dnx_multicast_tdm_delete(unit, group, flags, nof_replications, rep_array));
            }
            else
            {
                if (action == DNX_MULTICAST_ENTRY_ITER_REMOVE_ALL)
                {
                    SHR_IF_ERR_EXIT(dnx_multicast_linklist_iter(unit, group, flags, NULL, action,
                                                                nof_replications, rep_array, &rep_count_out));
                }
                else
                {
                    SHR_IF_ERR_EXIT(dnx_multicast_linklist_rep_remove(unit, group, flags, nof_replications, rep_array));
                }

                /** update replication per core for egress group */
                if (DNX_MULTICAST_IS_EGRESS_GROUP(flags))
                {
                    DNXCMN_CORES_ITER(unit, BCM_CORE_ALL, core_id)
                    {
                        SHR_IF_ERR_EXIT(dnx_multicast_exr_core_rep_exist(unit, group, core_id, &rep_exist));
                        SHR_IF_ERR_EXIT(dnx_multicast_egr_core_enable_set(unit, group, core_id, rep_exist));
                    }
                }
            }
        }
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify function for BCM-API: bcm_multicast_stat_control_set()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] core_id - ALL/0/1
 *   \param [in] flags - BCM_MULICAST_STAT_EXTERNAL for STIF counters, otherwise CRPS
 *   \param [in] command_id - counter processor command id
 *   \param [in] type - type of control
 *   \param [in] arg - arg of control
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_multicast_stat_control_set_verify(
    int unit,
    bcm_core_t core_id,
    uint32 flags,
    int command_id,
    bcm_multicast_stat_control_type_t type,
    int arg)
{
    uint32 legal_flags;
    int nof_command;
    SHR_FUNC_INIT_VARS(unit);

    /** check for valid core - BCM_CORE_ALL also allowed */
    DNXCMN_CORE_VALIDATE(unit, core_id, TRUE);

    legal_flags = BCM_MULICAST_STAT_EXTERNAL;

    if ((flags & ~legal_flags) != 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "illegal flags specified");
    }
    if (type == bcmMulticastStatControlCountAllCopiesAsOne)
    {
        if (arg != FALSE && arg != TRUE)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "illegal arg (=%d) value", arg);
        }

        nof_command = dnx_data_crps.src_interface.command_id_get(unit, bcmStatCounterInterfaceIngressReceivePp)->size;
        if (command_id < 0 || command_id > nof_command - 1)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "illegal command_id, got (=%d), for max value (=%d)", command_id,
                         nof_command - 1);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_multicast_stat_count_copies_symmetric_verify(
    int unit,
    int flags,
    int command_id)
{
    int first_core_arg = 0;
    int current_core_arg = 0;
    int core_found = FALSE;
    int core;
    SHR_FUNC_INIT_VARS(unit);

    DNXCMN_CORES_ITER(unit, BCM_CORE_ALL, core)
    {
        if (core_found)
        {
            SHR_IF_ERR_EXIT(dnx_multicast_stat_count_copies_get(unit, core, flags, command_id, &current_core_arg));

            if (first_core_arg != current_core_arg)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM,
                             "get count copies for asymetric configuration require a specific core, got BCM_CORE_ALL");
            }
        }
        else
        {
            SHR_IF_ERR_EXIT(dnx_multicast_stat_count_copies_get(unit, core, flags, command_id, &first_core_arg));
            core_found = TRUE;
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify function for BCM-API: bcm_multicast_stat_control_get()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] core_id - ALL/0/1
 *   \param [in] flags - BCM_MULICAST_STAT_EXTERNAL for STIF counters, otherwise CRPS
 *   \param [in] command_id - counter processor command id
 *   \param [in] type - type of control
 *   \param [in] arg - arg of control
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_multicast_stat_control_get_verify(
    int unit,
    bcm_core_t core_id,
    uint32 flags,
    int command_id,
    bcm_multicast_stat_control_type_t type,
    int *arg)
{
    uint32 legal_flags;
    SHR_FUNC_INIT_VARS(unit);

    /** check for valid core */
    DNXCMN_CORE_VALIDATE(unit, core_id, TRUE);

    legal_flags = BCM_MULICAST_STAT_EXTERNAL;

    if ((flags & ~legal_flags) != 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "illegal flags specified");
    }
    SHR_NULL_CHECK(arg, _SHR_E_PARAM, "arg");

    /** BCM_CORE_ALL not allowed for symmetric configuration only API*/
    if (core_id == BCM_CORE_ALL)
    {
        SHR_INVOKE_VERIFY_DNXC(dnx_multicast_stat_count_copies_symmetric_verify(unit, flags, command_id));
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - statistics control API, related to gather statistics on multicast packets in CRPS/STIF.
 *      currently refer to ingress multicast only.
 *      valid types:
 *      1. bcmMulticastStatControlCountAllCopiesAsOne - count all copies or just original. (for CRPS configured per command_id, for STIF single configuration)
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] core_id - ALL/0/1
 *   \param [in] flags - BCM_MULICAST_STAT_EXTERNAL for STIF counters, otherwise CRPS
 *   \param [in] command_id - counter processor command id
 *   \param [in] type - type of control
 *   \param [in] arg - arg of control
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_multicast_stat_control_set(
    int unit,
    bcm_core_t core_id,
    uint32 flags,
    int command_id,
    bcm_multicast_stat_control_type_t type,
    int arg)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_multicast_stat_control_set_verify(unit, core_id, flags, command_id, type, arg));

    switch (type)
    {
        case bcmMulticastStatControlCountAllCopiesAsOne:
            SHR_IF_ERR_EXIT(dnx_multicast_stat_count_copies_set(unit, core_id, flags, command_id, arg));
            break;
        default:
            break;
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - statistics control API, related to gather statistics on multicast packets in CRPS/STIF.
 *      currently refer to ingress multicast only.
 *      valid types:
 *      1. bcmMulticastStatControlCountAllCopiesAsOne - count all copies or just original. (for CRPS configured per command_id, for STIF single configuration)
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] core_id - ALL/0/1
 *   \param [in] flags - BCM_MULICAST_STAT_EXTERNAL for STIF counters, otherwise CRPS
 *   \param [in] command_id - counter processor command id
 *   \param [in] type - type of control
 *   \param [out] arg - arg of control
 *
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_multicast_stat_control_get(
    int unit,
    bcm_core_t core_id,
    uint32 flags,
    int command_id,
    bcm_multicast_stat_control_type_t type,
    int *arg)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_multicast_stat_control_get_verify(unit, core_id, flags, command_id, type, arg));

    switch (type)
    {
        case bcmMulticastStatControlCountAllCopiesAsOne:
            SHR_IF_ERR_EXIT(dnx_multicast_stat_count_copies_get(unit, core_id, flags, command_id, arg));
            break;
        default:
            break;
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;

}
/**
 * \brief - Verify function for BCM-API: bcm_multicast_group_get()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] group - group/bitmap ID created at bcm_multicast_create API
 *   \param [in] flags - variable to hold the requested flags for the specified group
 *
 * \remark
 *  This verifies that the group id is in appropriate range and that the flags pointer is not NULL
 * \see
 *   * None
 */
static shr_error_e
dnx_multicast_group_get_verify(
    int unit,
    bcm_multicast_t group,
    uint32 *flags)
{
    bcm_multicast_t group_id;
    int type = 0;
    SHR_FUNC_INIT_VARS(unit);

    /**
      * Verify flags pointer
      */
    SHR_NULL_CHECK(flags, _SHR_E_PARAM, "Flags");

    /**
      * Get the Multicast goup ID and type
      */
    group_id = _BCM_MULTICAST_ID_GET(group);
    type = _SHR_MULTICAST_TYPE_GET(group);

    if ((type == _BCM_MULTICAST_TYPE_ING_BMP) || (type == _BCM_MULTICAST_TYPE_EGR_BMP))
    {
        /**
          * Verify bitmap group ID
          */
        if ((group_id >= dnx_data_multicast.params.nof_ing_mc_bitmaps_get(unit)) &&
            (group_id >= dnx_data_multicast.params.nof_egr_mc_bitmaps_get(unit)))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Bitmap group ID out of range (0x%x)\n", group_id);
        }
    }
    else if (type == 0)
    {
        {
            /**
              * Verify link list and BIER group ID
              */
            if ((group_id > dnx_data_multicast.params.max_ing_mc_groups_get(unit)) &&
                (group_id > dnx_data_multicast.params.max_egr_mc_groups_get(unit)) &&
                (group_id > dnx_data_bier.params.nof_bfr_entries_get(unit)))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Linked list or BIER group ID out of range (0x%x)\n", group_id);
            }
        }
    }
    else
    {
        /**
          * This is not supported type, nor type 0 (TM)
          */
        SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported group type (%d)\n", type);
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Get the flags of Ingress or Egress Multicast groups
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -  Unit-ID
 *   \param [in] group - group/bitmap ID created at bcm_multicast_create API
 *   \param [out] flags - variable to hold the requested flags for the specified group
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_multicast_group_get(
    int unit,
    bcm_multicast_t group,
    uint32 *flags)
{
    uint32 is_open_egr = FALSE;
    uint32 is_open_ing = FALSE;
#ifdef BCM_DNX2_SUPPORT
    uint8 is_tdm_allocated = FALSE;
    uint8 is_sar_allocated = FALSE;
    int rc = 0;
#endif
    uint8 is_bitmap = FALSE;
    int set_size = 0;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_multicast_group_get_verify(unit, group, flags));

    /**
      * Init flags to 0
      */
    *flags = 0;

    {
        if ((_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_ING_BMP) ||
            (_SHR_MULTICAST_TYPE_GET(group) == _BCM_MULTICAST_TYPE_EGR_BMP))
        {
            is_bitmap = TRUE;
        }
    }

    /**
      * Check if group is of bitmap type.
      */
    if (is_bitmap == TRUE)
    {
        /**
          * If group is of bitmap type, add relevant flag.
          */
        *flags |= BCM_MULTICAST_TYPE_PORTS_GROUP;
    }
    else
    {
        /**
          * If group is not of bitmap or element type, it might be BIER.
          * Check if BIER group is created with the given group ID.
          * Size equal to zero indicates that group is not created.
          */
        if (dnx_data_bier.params.nof_bfr_entries_get(unit))
        {
            SHR_IF_ERR_EXIT(dnx_bier_db.set_size.get(unit, group, &set_size));
            if (set_size != 0)
            {
                /**
                  * If BIER group is created, add relevant flag according to size.
                  */
                if (set_size == 64)
                {
                    *flags |= BCM_MULTICAST_BIER_64_GROUP;
                }
                else if (set_size == 128)
                {
                    *flags |= BCM_MULTICAST_BIER_128_GROUP;
                }
                else
                {
                    *flags |= BCM_MULTICAST_BIER_256_GROUP;
                }
            }
        }
    }

    if (dnx_data_multicast.params.max_egr_mc_groups_get(unit) >= 0)
    {
        /**
          * Check if group is open as Egress group.
          */
        SHR_IF_ERR_EXIT(dnx_multicast_group_open_get
                        (unit, _BCM_MULTICAST_ID_GET(group), *flags | BCM_MULTICAST_EGRESS_GROUP, &is_open_egr));
    }

    /**
      * Check if group is open as Ingress group.
      */
    SHR_IF_ERR_EXIT(dnx_multicast_group_open_get
                    (unit, _BCM_MULTICAST_ID_GET(group), *flags | BCM_MULTICAST_INGRESS_GROUP, &is_open_ing));

    /**
      * Add the relevant flags.
      */
#ifdef BCM_DNX2_SUPPORT
    if (is_open_egr == TRUE)
    {
        /**
         * Check if group is regular Egress or Egress TDM
         */
        rc = multicast_db.group_is_tdm.is_allocated(unit, _BCM_MULTICAST_ID_GET(group), &is_tdm_allocated);
        if ((rc == BCM_E_NONE) && is_tdm_allocated)
        {
            *flags |= BCM_MULTICAST_EGRESS_TDM_GROUP;
        }
        else
        {
            *flags |= BCM_MULTICAST_EGRESS_GROUP;
        }

        /**
         * Check if the group is also SAR
         */
        rc = multicast_db.group_is_sar.is_allocated(unit, _BCM_MULTICAST_ID_GET(group), &is_sar_allocated);
        if ((rc == BCM_E_NONE) && is_sar_allocated)
        {
            *flags |= BCM_MULTICAST_SAR_GROUP;
        }
    }
#endif
    if (is_open_ing == TRUE)
    {
        *flags |= BCM_MULTICAST_INGRESS_GROUP;
    }


    /**
      * Always return BCM_MULTICAST_WITH_ID flag.
      */
    *flags |= BCM_MULTICAST_WITH_ID;

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief -
 * Add bfr id into bier multicast group
 *
 * \param [in] unit -  Unit-ID
 * \param [in] group -  group id
 * \param [in] flags -  flag
 * \param [in] nof_bfrs -  number of bfr ids
 * \param [in] bfr_id -  bfr id array
 * \param [in] replication -  application array
 * \return
 *   See bcm_error_e
 * \remark
 *   * None
 */
int
bcm_dnx_multicast_bfr_id_add(
    int unit,
    bcm_multicast_t group,
    uint32 flags,
    int nof_bfrs,
    uint32 *bfr_id,
    bcm_multicast_replication_t * replication)
{
    int index = 0;

    SHR_FUNC_INIT_VARS(unit);

    for (index = 0; index < nof_bfrs; index++)
    {
        SHR_IF_ERR_EXIT(dnx_multicast_bfr_id_add(unit, flags, group, bfr_id[index], replication[index]));
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief -
 * delete bfr id from bier multicast group
 *
 * \param [in] unit -  Unit-ID
 * \param [in] group -  group id
 * \param [in] flags -  flag
 * \param [in] nof_bfrs -  number of bfr ids
 * \param [in] bfr_id -  bfr id array
 * \param [in] replication -  application array
 * \return
 *   See bcm_error_e
 * \remark
 *   * None
 */
int
bcm_dnx_multicast_bfr_id_delete(
    int unit,
    bcm_multicast_t group,
    uint32 flags,
    int nof_bfrs,
    uint32 *bfr_id,
    bcm_multicast_replication_t * replication)
{
    int index = 0;

    SHR_FUNC_INIT_VARS(unit);

    for (index = 0; index < nof_bfrs; index++)
    {
        SHR_IF_ERR_EXIT(dnx_multicast_bfr_id_delete(unit, flags, group, bfr_id[index], replication[index]));
    }

exit:
    SHR_FUNC_EXIT;

}

/**
 * \brief -
 * Retrieve bfr id replication information from 
 * bier multicast group
 *
 * \param [in] unit -  Unit-ID
 * \param [in] group -  group id
 * \param [in] flags -  flag
 * \param [in] nof_bfrs -  number of bfr ids
 * \param [in] bfr_id -  bfr id array
 * \param [out] replication -  application array
 * \return
 *   See bcm_error_e
 * \remark
 *   * None
 */
int
bcm_dnx_multicast_bfr_id_get(
    int unit,
    bcm_multicast_t group,
    uint32 flags,
    int nof_bfrs,
    uint32 *bfr_id,
    bcm_multicast_replication_t * replication)
{
    int index = 0;

    SHR_FUNC_INIT_VARS(unit);

    for (index = 0; index < nof_bfrs; index++)
    {
        SHR_IF_ERR_EXIT(dnx_multicast_bfr_id_get(unit, flags, group, bfr_id[index], replication + index));
    }

exit:
    SHR_FUNC_EXIT;

}
