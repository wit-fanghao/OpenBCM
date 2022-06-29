/***********************************************************************************
 *                                                                                 *
 * Copyright: (c) 2019 Broadcom.                                                   *
 * Broadcom Proprietary and Confidential. All rights reserved.                     *
 */

/***********************************************************************************
 ***********************************************************************************
 *                                                                                 *
 *  Revision    :     *
 *                                                                                 *
 *  Description :  Power management functions provided to IP User                  *
 */

/** @file merlin16_pcieg3_pwr_mgt.h
 * Power management functions provided to IP User
 */
#ifndef MERLIN16_PCIEG3_API_PWR_MGT_H
#define MERLIN16_PCIEG3_API_PWR_MGT_H

#include "merlin16_pcieg3_ipconfig.h"
#include "common/srds_api_enum.h"
#include "common/srds_api_err_code.h"
#include "merlin16_pcieg3_dependencies.h"

/*-----------------------*/
/*  IDDQ / Clkgate APIs  */
/*-----------------------*/
/** Core configuration for IDDQ.
 * Note: User also needs to configure all lanes through merlin16_pcieg3_lane_config_for_iddq()
 * before enabling IDDQ by asserting IDDQ pin.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @return Error Code generated by API (returns ERR_CODE_NONE if no errors)
 */
err_code_t merlin16_pcieg3_core_config_for_iddq(srds_access_t *sa__);

/** Serdes Core Powerdown.
 * Along with merlin16_pcieg3_core_pwrdn(), all lanes powerdowns should also be issued using
 * merlin16_pcieg3_lane_pwrdn() to complete a Core Powerdown.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @param mode based on enum #srds_core_pwrdn_mode_enum select from ON, CORE, DEEP power down modes
 * @return Error Code generated by API (returns ERR_CODE_NONE if no errors)
 */
err_code_t merlin16_pcieg3_core_pwrdn(srds_access_t *sa__, enum srds_core_pwrdn_mode_enum mode);

/**************************************************/
/* LANE Based APIs - Required to be used per Lane */
/**************************************************/

/*--------------------------------------------------------------*/
/*  IDDQ / Powerdown / Deep Powerdown / Isolate Pins  */
/*--------------------------------------------------------------*/
/** Lane configurations for IDDQ.
 * Note: User needs to configure all lanes through merlin16_pcieg3_lane_config_for_iddq() and also call merlin16_pcieg3_core_config_for_iddq()
 * before enabling IDDQ by asserting IDDQ pin.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @return Error Code generated by API (returns ERR_CODE_NONE if no errors)
 */
err_code_t merlin16_pcieg3_lane_config_for_iddq(srds_access_t *sa__);

/** Serdes Lane Powerdown.
 * Powers down option available - TX only, RX only, complete LANE, complete lane DEEP, PWR_ON
 * Note: To wake up from lane DEEP powerdown, first call PWR_ON and then de-assert lane_dp_reset [wr_ln_dp_s_rstb(0x1)].
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @param mode Enable/Disable lane powerdown based on #srds_core_pwrdn_mode_enum
 * @return Error Code generated by API (returns ERR_CODE_NONE if no errors)
 */
err_code_t merlin16_pcieg3_lane_pwrdn(srds_access_t *sa__, enum srds_core_pwrdn_mode_enum mode);

#endif