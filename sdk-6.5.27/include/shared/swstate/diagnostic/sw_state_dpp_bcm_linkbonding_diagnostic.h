/* 
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 * 
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 * search for 'sw_state_diagnostic_cbs_t' for the root of the struct
 */

#ifndef _SHR_SW_STATE_DPP_BCM_LINKBONDING_DIAGNOSTIC_H_
#define _SHR_SW_STATE_DPP_BCM_LINKBONDING_DIAGNOSTIC_H_

#ifdef BCM_WARM_BOOT_SUPPORT
/********************************* diagnostic calbacks definitions *************************************/
/* this set of callbacks, are the callbacks used in the diagnostic calbacks struct 'sw_state_cbs_t' to */
/* access the data in 'sw_state_t'.                                                                */
/* the calbacks are inserted into the diagnostic struct by 'sw_state_diagnostic_cb_init'.                  */
/***************************************************************************************************/

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_linkbonding_dump */
typedef int (*sw_state_dpp_bcm_linkbonding_dump_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_linkbonding_lbg_valid_bmp_dump */
typedef int (*sw_state_dpp_bcm_linkbonding_lbg_valid_bmp_dump_cb)(
    int unit, int linkbonding_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_linkbonding_modem_to_ports_dump */
typedef int (*sw_state_dpp_bcm_linkbonding_modem_to_ports_dump_cb)(
    int unit, int linkbonding_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_linkbonding_port_to_lbg_dump */
typedef int (*sw_state_dpp_bcm_linkbonding_port_to_lbg_dump_cb)(
    int unit, int linkbonding_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_linkbonding_modem_to_ing_lbg_dump */
typedef int (*sw_state_dpp_bcm_linkbonding_modem_to_ing_lbg_dump_cb)(
    int unit, int linkbonding_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_linkbonding_modem_to_egr_lbg_dump */
typedef int (*sw_state_dpp_bcm_linkbonding_modem_to_egr_lbg_dump_cb)(
    int unit, int linkbonding_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_linkbonding_modem_to_ctrl_ports_dump */
typedef int (*sw_state_dpp_bcm_linkbonding_modem_to_ctrl_ports_dump_cb)(
    int unit, int linkbonding_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_linkbonding_lbg_speed_dump */
typedef int (*sw_state_dpp_bcm_linkbonding_lbg_speed_dump_cb)(
    int unit, int linkbonding_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

/*********************************** diagnostic calbacks struct ****************************************/
/* this set of structs, rooted at 'sw_state_cbs_t' define the diagnostic layer for the entire SW state.*/
/* use this tree to dump fields in the sw state rooted at 'sw_state_t'.              */
/* NOTE: 'sw_state_t' data should not be accessed directly.                                        */
/***************************************************************************************************/

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_linkbonding_lbg_valid_bmp_diagnostic_cbs_s {
    sw_state_dpp_bcm_linkbonding_lbg_valid_bmp_dump_cb dump;
} sw_state_dpp_bcm_linkbonding_lbg_valid_bmp_diagnostic_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_linkbonding_modem_to_ports_diagnostic_cbs_s {
    sw_state_dpp_bcm_linkbonding_modem_to_ports_dump_cb dump;
} sw_state_dpp_bcm_linkbonding_modem_to_ports_diagnostic_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_linkbonding_port_to_lbg_diagnostic_cbs_s {
    sw_state_dpp_bcm_linkbonding_port_to_lbg_dump_cb dump;
} sw_state_dpp_bcm_linkbonding_port_to_lbg_diagnostic_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_linkbonding_modem_to_ing_lbg_diagnostic_cbs_s {
    sw_state_dpp_bcm_linkbonding_modem_to_ing_lbg_dump_cb dump;
} sw_state_dpp_bcm_linkbonding_modem_to_ing_lbg_diagnostic_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_linkbonding_modem_to_egr_lbg_diagnostic_cbs_s {
    sw_state_dpp_bcm_linkbonding_modem_to_egr_lbg_dump_cb dump;
} sw_state_dpp_bcm_linkbonding_modem_to_egr_lbg_diagnostic_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_linkbonding_modem_to_ctrl_ports_diagnostic_cbs_s {
    sw_state_dpp_bcm_linkbonding_modem_to_ctrl_ports_dump_cb dump;
} sw_state_dpp_bcm_linkbonding_modem_to_ctrl_ports_diagnostic_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_linkbonding_lbg_speed_diagnostic_cbs_s {
    sw_state_dpp_bcm_linkbonding_lbg_speed_dump_cb dump;
} sw_state_dpp_bcm_linkbonding_lbg_speed_diagnostic_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_linkbonding_diagnostic_cbs_s {
#if defined(BCM_PETRA_SUPPORT)
    sw_state_dpp_bcm_linkbonding_dump_cb dump;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
    sw_state_dpp_bcm_linkbonding_lbg_valid_bmp_diagnostic_cbs_t lbg_valid_bmp;
    sw_state_dpp_bcm_linkbonding_modem_to_ports_diagnostic_cbs_t modem_to_ports;
    sw_state_dpp_bcm_linkbonding_port_to_lbg_diagnostic_cbs_t port_to_lbg;
    sw_state_dpp_bcm_linkbonding_modem_to_ing_lbg_diagnostic_cbs_t modem_to_ing_lbg;
    sw_state_dpp_bcm_linkbonding_modem_to_egr_lbg_diagnostic_cbs_t modem_to_egr_lbg;
    sw_state_dpp_bcm_linkbonding_modem_to_ctrl_ports_diagnostic_cbs_t modem_to_ctrl_ports;
    sw_state_dpp_bcm_linkbonding_lbg_speed_diagnostic_cbs_t lbg_speed;
} sw_state_dpp_bcm_linkbonding_diagnostic_cbs_t;

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

int sw_state_dpp_bcm_linkbonding_diagnostic_cb_init(int unit);

#endif /* BCM_WARM_BOOT_SUPPORT */

#endif /* _SHR_SW_STATE_DPP_BCM_LINKBONDING_DIAGNOSTIC_H_ */
