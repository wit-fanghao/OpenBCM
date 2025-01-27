/** \file tune.c
 * main Tune module file
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
#define BSL_LOG_MODULE BSL_LS_BCMDNX_INITSEQDNX

/*
 * Include files.
 * {
 */
#include <soc/sand/shrextend/shrextend_debug.h>
#include <bcm/port.h>
#include <bcm/cosq.h>
#include <bcm_int/dnx/tune/iqs_tune.h>
#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>
#include <bcm_int/dnx/synce/synce.h>
#include <soc/sand/sand_aux_access.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_dev_init.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_fabric.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_ecgm.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_synce.h>
#include <bcm_int/dnx/auto_generated/dnx_port_dispatch.h>
#include "ingress_congestion_tune.h"
#include "egr_queuing_tune.h"
#include "scheduler_tune.h"
#include "nif_tune.h"
#include "trap_tune.h"
#include "oam_tune.h"
#include "policer_tune.h"
#include "ptp_tune.h"
#include "fabric_tune.h"
#include "fabric_cgm_tune.h"
#include "switch_tune.h"
#include "ecgm_tune.h"
#include "tsn_tune.h"

#include <soc/memory.h>
#include <soc/feature.h>
#include <soc/types.h>
#include <soc/register.h>
#include <soc/dnxc/drv_dnxc_utils.h>
#include <sal/core/boot.h>

/*
 * }
 * Include files.
 */
/*
 * Defines.
 * {
 */

/*
 * }
 * Defines.
 */

/*
 * See .h file
 */
shr_error_e
dnx_tune_init(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_tune_trap_init(unit));

    SHR_IF_ERR_EXIT(dnx_tune_oam_init(unit));

    SHR_IF_ERR_EXIT(dnx_tune_ingress_congestion_set(unit));

    SHR_IF_ERR_EXIT(dnx_tune_egr_queuing_rate_tune(unit));

    SHR_IF_ERR_EXIT(dnx_tune_scheduler_tune(unit));

    SHR_IF_ERR_EXIT(dnx_policer_tune_init(unit));

    SHR_IF_ERR_EXIT(dnx_ptp_tune_init(unit));

    SHR_IF_ERR_EXIT(dnx_tune_credit_generator_init(unit));

    {
        /*
         * Can't perform tuning when all fabric are not used. 
         */
        int fabric_is_used = dnx_data_fabric.general.feature_get(unit, dnx_data_fabric_general_is_used);
        if (dnx_data_fabric.general.feature_get(unit, dnx_data_fabric_general_blocks_exist) && fabric_is_used)
        {
            SHR_IF_ERR_EXIT(dnx_tune_fabric_cgm_set(unit));
        }
    }

    SHR_IF_ERR_EXIT(dnx_tune_iqs_init(unit));

    {
        SHR_IF_ERR_EXIT(dnx_ecgm_tune_init(unit));
    }

    SHR_IF_ERR_EXIT(dnx_tune_switch_init(unit));

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_tune_port_add(
    int unit)
{
    bcm_port_t port;
    dnx_algo_port_info_s port_info;
    int is_master = 0;

    SHR_FUNC_INIT_VARS(unit);

    /*
     * get logical port information
     */
    SHR_IF_ERR_EXIT(dnx_algo_port_added_port_get(unit, &port));
    SHR_IF_ERR_EXIT(dnx_algo_port_info_get(unit, port, &port_info));

    /*
     * priority config
     */
    SHR_IF_ERR_EXIT(dnx_port_tune_port_add_priority_config(unit, port));

    SHR_IF_ERR_EXIT(dnx_algo_port_is_master_get(unit, port, 0, &is_master));
    if (DNX_ALGO_PORT_TYPE_IS_NIF(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(ELK, STIF, L1, MGMT, FEEDBACK))
        && is_master)
    {
        SHR_IF_ERR_EXIT(dnx_port_tune_port_add_phy_control_config(unit, port));
    }

    /*
     * egress queuing tune
     */
    if (DNX_ALGO_PORT_TYPE_IS_EGR_TM(unit, port_info))
    {
        SHR_IF_ERR_EXIT(dnx_tune_egr_queuing_port_add(unit, port));
    }

    /*
     * TSN port tune
     */
    if (DNX_ALGO_PORT_TYPE_IS_NIF_ETH(unit, port_info, 0))
    {
        SHR_IF_ERR_EXIT(dnx_tsn_tune_port_add(unit, port));
    }
    /*
     * OTN/ETH/FLEXE CDR clock valid indication tune. The CDR clock
     * will be used for Nanosync if GDPLL is enabled.
     */
    if (dnx_data_synce.general.feature_get(unit, dnx_data_synce_general_synce_in_nanosync))
    {
        if (DNX_ALGO_PORT_TYPE_IS_OTN_PHY(unit, port_info)
            || DNX_ALGO_PORT_TYPE_IS_NIF_ETH(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(L1))
            || DNX_ALGO_PORT_TYPE_IS_FLEXE_PHY(unit, port_info, 1))
        {
            SHR_IF_ERR_EXIT(dnx_nanosync_nif_lane_clock_valid_set(unit, port));
        }
    }

    /*
     * Set RX Max frame size
     */
    if (DNX_ALGO_PORT_TYPE_IS_NIF_ETH(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(STIF, MGMT)) ||
        (DNX_ALGO_PORT_TYPE_IS_NIF_ETH_L1(unit, port_info, TRUE)
         && !dnx_data_nif.framer.feature_get(unit, dnx_data_nif_framer_l1_eth_supported)))
    {
        int size = dnx_data_nif.eth.packet_size_max_get(unit);
        SHR_IF_ERR_EXIT(bcm_dnx_port_frame_max_set(unit, port, size));
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_tune_port_remove(
    int unit)
{

    SHR_FUNC_INIT_VARS(unit);

    /*
     * Placeholder for tuning that should be done when removing port.
     * Currently - nothing to tune during port removal.
     */

    SHR_FUNC_EXIT;

}
