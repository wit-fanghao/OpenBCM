/*
 * 
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 */
#include <sal/types.h>
/* FILE: wcmod_enum_defines.h */
/* DATE: Mon Jun 13 10:28:56 PDT 2011 */


/* This file is automatically generated. Do not modify it. Modify the
 * inc/enum_desc.txt to change enums, elems, or comments. For issues about
 * the process that creates this file contact the wcmod development team.
 */

#ifndef _WCMOD_ENUM_DEFINES_H
#define _WCMOD_ENUM_DEFINES_H

/*! \enum wcmod_lane_select 

A '1' in the latter part of the enum name signifies that the lane is selected.
Other parameters in the warpcore context will decide what to do with the
selected  lane(s). In most cases we either enable or disable a feature on the
selected lanes.

In the future, multiple lanes can be supported with a single call (for example,
disable autoneg on lanes 1,  and 3. only.)
But currently Tier1s only support operations on a single lane. If multiple
lanes need to be programmed, multiple calls to Tier1s should be made.

Lane selection is enumerated to avoid wrong selection of lanes.

In the future release, we can select all lanes, but not be in broadcast mode.
Currently lane_select is set to WCMOD_LANE_BCST to broadcast to all lanes.

Note that when you write, data is broadcast to registers of all lanes. But when
you read in broadcast mode, the value of the register in lane 0 is returned.

*/

typedef enum {
  WCMOD_LANE_0_0_0_1         = 0   ,  /*!< lane number  0       selected   */
  WCMOD_LANE_0_0_1_0               ,  /*!< lane number  1       selected   */
  WCMOD_LANE_0_0_1_1               ,  /*!< lane numbers 0,1     selected   */
  WCMOD_LANE_0_1_0_0               ,  /*!< lane number  2       selected   */
  WCMOD_LANE_0_1_0_1               ,  /*!< lane numbers 2,0     selected   */
  WCMOD_LANE_0_1_1_0               ,  /*!< lane numbers 2,1     selected   */
  WCMOD_LANE_0_1_1_1               ,  /*!< lane numbers 2,1,0   selected   */
  WCMOD_LANE_1_0_0_0               ,  /*!< lane number  3       selected   */
  WCMOD_LANE_1_0_0_1               ,  /*!< lane numbers 3,0     selected   */
  WCMOD_LANE_1_0_1_0               ,  /*!< lane numbers 3,1     selected   */
  WCMOD_LANE_1_0_1_1               ,  /*!< lane numbers 3,1,0   selected   */
  WCMOD_LANE_1_1_0_0               ,  /*!< lane numbers 3,2     selected   */
  WCMOD_LANE_1_1_0_1               ,  /*!< lane numbers 3,2,0   selected   */
  WCMOD_LANE_1_1_1_0               ,  /*!< lane numbers 3,2,1   selected   */
  WCMOD_LANE_1_1_1_1               ,  /*!< lane numbers 3,2,1,0 selected   */
  WCMOD_LANE_BCST                  ,  /*!< lane numbers 3,2,1,0 BCST       */
  WCMOD_LANE_0_0_0_1_0_0_0_0       ,  /*!< lane number 4 selected for QSGMII */
  WCMOD_LANE_0_0_1_0_0_0_0_0       ,  /*!< lane number 5 selected for QSGMII */
  WCMOD_LANE_0_1_0_0_0_0_0_0       ,  /*!< lane number 6 selected for QSGMII */
  WCMOD_LANE_1_0_0_0_0_0_0_0       ,  /*!< lane number 7 selected for QSGMII */
  WCMOD_LANE_0_0_0_1_0_0_0_1       ,  /*!< lane number 0 and lane 4 selected for QSGMII */
  WCMOD_LANE_1_1_1_1_1_1_1_1       ,  /*!< lane number 7 through 0 selected for QSGMII */
  WCMOD_LANE_ILLEGAL                 /*!< Illegal (programmatic boundary) */
} wcmod_lane_select;

/*! \def CNT_wcmod_lane_select Types of enum wcmod_lane_select */
#define CNT_wcmod_lane_select 23

/*!
\brief
This array returns the string version of the enum #wcmod_lane_select when indexed by the
enum var.

*/
extern char* e2s_wcmod_lane_select [CNT_wcmod_lane_select];
/*!
\brief
This array associates the enum #wcmod_lane_select enum with a bit mask.
The index is the #wcmod_lane_select enum value.  The value for each entry is
interpreted as follows.  If bit [n] is 1, then lane [n] is enabled; if bit [n]
is 0, then lane [n] is disabled.  By enabled, we mean that such-and-such
function is to be called for a lane; by disabled, we mean that such-and-such
function is not to be called for a lane.  So a value of 0xF indicates that all
lanes or enabled, while 0x5 indicates that only lanes 0 and 2 are enabled.

*/
extern int e2n_wcmod_lane_select [CNT_wcmod_lane_select];
/*! \enum wcmod_spd_intfc_set 

All legal speed-interface combination are encapsulated in this enum

There are 42 speed and interface combinations allowed for a logical Warpcore
port. Names and speeds are self explanatory.

Speed and interface selection is combined because we don't want the speeds
to be incompatible with interface.

*/

typedef enum {
  WCMOD_SPD_ZERO             = 0   ,  /*!< Illegal value (programmatic boundary)      */
  WCMOD_SPD_10_SGMII               ,  /*!< 10Mb SGMII (serial, customer prop.)        */
  WCMOD_SPD_100_SGMII              ,  /*!< 100Mb SGMII (serial, customer prop.)       */
  WCMOD_SPD_100_FX                 ,  /*!< 100Mb fiber                                */
  WCMOD_SPD_1000_SGMII             ,  /*!< 1Gb SGMII (serial, customer prop.)         */
  WCMOD_SPD_2000                   ,  /*!< 2Gb serial(qsgmii serdes only)             */
  WCMOD_SPD_1000_FIBER             ,  /*!< 1Gb 1000BASE-X (serial)                    */
  WCMOD_SPD_2500                   ,  /*!< 2.5Gb (BRCM prop.) based on 1000BASE-X     */
  WCMOD_SPD_5000                   ,  /*!< 5Gb XAUI (BRCM prop.)                      */
  WCMOD_SPD_6000                   ,  /*!< 6b XAUI (BRCM prop.)                       */
  WCMOD_SPD_10000_HI               ,  /*!< 10Gb XAUI HiG (BRCM prop.)                 */
  WCMOD_SPD_10000                  ,  /*!< 10Gb XAUI                                  */
  WCMOD_SPD_12000_HI               ,  /*!< 10Gb XAUI HiG (BRCM prop.)                 */
  WCMOD_SPD_12500                  ,  /*!< 12.5Gb XAUI (BRCM prop.)                   */
  WCMOD_SPD_13000                  ,  /*!< 13Gb XAUI (BRCM prop.)                     */
  WCMOD_SPD_15000                  ,  /*!< 15Gb XAUI (BRCM prop.)                     */
  WCMOD_SPD_16000                  ,  /*!< 16Gb XAUI (BRCM prop.)                     */
  WCMOD_SPD_5000_SINGLE            ,  /*!< 5Gb serial (BRCM prop.)                    */
  WCMOD_SPD_6364_SINGLE            ,  /*!< 6.3Gb serial (BRCM prop.)                  */
  WCMOD_SPD_20000                  ,  /*!< 20Gb XAUI (BRCM prop.)                     */
  WCMOD_SPD_21000                  ,  /*!< 21Gb XAUI (BRCM prop.)                     */
  WCMOD_SPD_25455                  ,  /*!< 25Gb XAUI (BRCM prop.) 64/66 codec         */
  WCMOD_SPD_10000_HI_DXGXS         ,  /*!< 10Gb dual lane XGXS HiG (BRCM prop.)       */
  WCMOD_SPD_10000_DXGXS            ,  /*!< 10Gb dual lane XGXS (BRCM prop.)           */
  WCMOD_SPD_10500_HI_DXGXS         ,  /*!< 10.5Gb dual lane XGXS HiG (BRCM prop.)     */
  WCMOD_SPD_10500_DXGXS            ,  /*!< 10.5Gb dual lane XGXS (BRCM prop.)         */
  WCMOD_SPD_12773_HI_DXGXS         ,  /*!< 12.73Gb dual lane XGXS HiG (BRCM prop.)    */
  WCMOD_SPD_12773_DXGXS            ,  /*!< 12.73Gb dual lane XGXS (BRCM prop.)        */
  WCMOD_SPD_31500                  ,  /*!< 31.5Gb quad lane XAUI (BRCM prop.)         */
  WCMOD_SPD_40G                    ,  /*!< 40Gb quad lane XAUI (BRCM prop.)           */
  WCMOD_SPD_42G                    ,  /*!< 42Gb quad lane XAUI (BRCM prop.)           */
  WCMOD_SPD_10000_XFI              ,  /*!< 10Gb serial XFI                            */
  WCMOD_SPD_10000_SFI              ,  /*!< 10Gb serial SFI                            */
  WCMOD_SPD_10600_XFI_HG           ,  /*!< 10.5Gb serial XFI (HgSOLO)                 */
  WCMOD_SPD_20000_SCR              ,  /*!< 20Gb XAUI scrambled output                 */
  WCMOD_SPD_10000_HI_DXGXS_SCR       ,  /*!< 10Gb dual lane scrambled output HiG      */
  WCMOD_SPD_10000_DXGXS_SCR        ,  /*!< 10Gb dual lane scrambled output            */
  WCMOD_SPD_X2_10000               ,  /*!< 10Gb dual lane customer prop.              */
  WCMOD_SPD_X2_23000               ,  /*!< 2*11.5Gb dual lane customer prop.          */
  WCMOD_SPD_20000_HI_DXGXS         ,  /*!< 20Gb dual lane HiG                         */
  WCMOD_SPD_40G_KR4                ,  /*!< 40Gb quad lane MLD  backplane              */
  WCMOD_SPD_40G_CR4                ,  /*!< 40Gb quad lane MLD  copper cable           */
  WCMOD_SPD_15750_HI_DXGXS         ,  /*!< 15.75Gb scrambled dual lane HiG(BRCM prop) */
  WCMOD_SPD_21G_HI_DXGXS           ,  /*!< 21.2Gb dual HiG(BRCM prop.)(20+plldiv=70)  */
  WCMOD_SPD_R2_12000               ,  /*!< 12Gb dual customer prop.)                  */
  WCMOD_SPD_PCSBYP_3P125G          ,  /*!< 3.125Gb serial  pcbbyp                     */
  WCMOD_SPD_PCSBYP_5G              ,  /*!< 5.75 Gb serial  pcbbyp                     */
  WCMOD_SPD_PCSBYP_5P75G           ,  /*!< 5.75 Gb serial  pcbbyp                     */
  WCMOD_SPD_PCSBYP_6P25G           ,  /*!< 6.250Gb serial  pcbbyp                     */
  WCMOD_SPD_PCSBYP_10P3125         ,  /*!< 10P3125Gb serial                           */
  WCMOD_SPD_PCSBYP_10P9375         ,  /*!< 10P9375Gb serial                           */
  WCMOD_SPD_PCSBYP_11P5            ,  /*!< 11P5Gb    serial                           */
  WCMOD_SPD_11P5                   ,  /*!< 11P5Gb with PCS   serial                   */
  WCMOD_SPD_PCSBYP_12P5            ,  /*!< 12P5Gb    serial                           */
  WCMOD_SPD_12P5                   ,  /*!< 12P5Gb with PCS   serial                   */
  WCMOD_SPD_40G_XLAUI              ,  /*!< 40Gb quad lane  MLD  copper trace          */
  WCMOD_SPD_42G_XLAUI              ,  /*!< 42Gb quad lane  MLD  copper trace          */
  WCMOD_SPD_42G_KR4                ,  /*!< 42Gb quad lane  MLD  backplane             */
  WCMOD_SPD_20G_DXGXS              ,  /*!< 20Gb dual lane                             */
  WCMOD_SPD_20G_KR2                ,  /*!< 20Gb MLD backplane                         */
  WCMOD_SPD_20G_CR2                ,  /*!< 20Gb MLD copper                            */
  WCMOD_SPD_100G_CR10              ,  /*!< 100G                                       */
  WCMOD_SPD_120G_CR12              ,  /*!< 120G                                       */
  WCMOD_SPD_CUSTOM_BYPASS          ,  /*!< generic pcs bypass speed mode              */
  WCMOD_SPD_1G_QSGMII              ,  /*!< 1G QSGMII                                  */
  WCMOD_SPD_48G                    ,  /*!< ethernet 12.5G per lane                    */
  WCMOD_SPD_20G_DXGXS_SCR          ,  /*!< 20Gb dual scrambled lane                   */
  WCMOD_SPD_44G                    ,  /*!< ethernet 11.5G per lane                   */
  WCMOD_SPD_ILLEGAL                  /*!< Illegal value (programmatic boundary)      */
} wcmod_spd_intfc_set;

/*! \def CNT_wcmod_spd_intfc_set Types of enum wcmod_spd_intfc_set */
#define CNT_wcmod_spd_intfc_set  69 

/*!
\brief
This array returns the string version of the enum #wcmod_lane_select when indexed by the
enum var.

*/
extern char* e2s_wcmod_spd_intfc_set [CNT_wcmod_spd_intfc_set];
/*!
\brief
This array associates the enum #wcmod_lane_select enum with a bit mask.
The index is the #wcmod_lane_select enum value.  The value for each entry is
interpreted as follows.  If bit [n] is 1, then lane [n] is enabled; if bit [n]
is 0, then lane [n] is disabled.  By enabled, we mean that such-and-such
function is to be called for a lane; by disabled, we mean that such-and-such
function is not to be called for a lane.  So a value of 0xF indicates that all
lanes or enabled, while 0x5 indicates that only lanes 0 and 2 are enabled.

*/
extern int e2n_wcmod_spd_intfc_set [CNT_wcmod_spd_intfc_set];
/*! \enum wcmod_mdio_type 

Types of MDIO to access warpcore registers. 22 (32 registers) and 45 are
supported. Picking 22 automatically selects BRCM prop.) clause 22 mode
with extensions for 64K registers.  Actual clause 22 is not yet supported.

*/

typedef enum {
  WCMOD_MDIO_CL22            = 0   ,  /*!< IEEE clause 22 (BRCM prop.) based MDIO */
  WCMOD_MDIO_CL45                  ,  /*!< IEEE clause 45 based MDIO */
  WCMOD_MDIO_CL22_IEEE             ,  /*!< IEEE clause 22 (not BRCM prop.) based MDIO */
  WCMOD_MDIO_PCB                   ,  /*!< For verilog only (drive parallel bus) */
  WCMOD_MDIO_ILLEGAL                 /*!<  */
} wcmod_mdio_type;

/*! \def CNT_wcmod_mdio_type Types of enum wcmod_mdio_type */
#define CNT_wcmod_mdio_type 5

/*!
\brief
This array returns the string version of the enum #wcmod_mdio_type when indexed
by the enum var.

*/
extern char* e2s_wcmod_mdio_type [CNT_wcmod_mdio_type];
/*! \enum wcmod_port_type 

This is the port mode type enumeration.

WC can be configured in combo mode (i.e. entire WC is a single port) or
independent mode (i.e. WC has more than one port (2, 3, or 4) that are
controlled individually.

*/

typedef enum {
  WCMOD_COMBO                = 0   ,  /*!< Combo mode treats 4 channels as one logical port */
  WCMOD_INDEPENDENT                ,  /*!< Each channel is one logical port */
  WCMOD_DXGXS                      ,  /*!< Each paired channel(0-1, 2-3) is one logical port */
  WCMOD_PORT_MODE_ILLEGAL            /*!<  */
} wcmod_port_type;

/*! \def CNT_wcmod_port_type Types of enum wcmod_port_type */
#define CNT_wcmod_port_type 4

/*!
\brief
This array returns the string version of the enum #wcmod_port_type when indexed
by the enum var.

*/
extern char* e2s_wcmod_port_type [CNT_wcmod_port_type];

/*! \enum firmware_mode_type 

This is the firmware_mode type enumeration.

microController  can be configured in SFP_OPT_SR4, SFP_DAC
, XLAUI, etc ...

*/

typedef enum {
  WCMOD_DEFAULT                = 0   ,  /*!< default mode */
  WCMOD_SFP_OPT_SR4                  ,  /*!< SFP-OPT-SR4 */
  WCMOD_SFP_DAC                      ,  /*!< SFP-DAC */
  WCMOD_XLAUI                        ,  /*!< XLAUI  */
  WCMOD_FORCE_OSDFE                  ,  /*!< FORCE_OSDFE  */
  WCMOD_FORCE_BRDFE                  ,  /*!< FORCE_BRDFE  */
  WCMOD_SW_CL72                      ,  /*!< SW_CL72 */
  WCMOD_CL72_woAN                    ,  /*!<CL72_woAN */
  WCMOD_FIRMWARE_MODE_ILLEGAL
} wcmod_firmware_mode_type;

/*! \def CNT_wcmod_port_type Types of enum wcmod_firmware_mode_type */
#define CNT_wcmod_firmware_mode_type 9


/*!
\brief
This array returns the string version of the enum #wcmod_firmware_mode_type when indexed
by the enum var.

*/
extern char* e2s_wcmod_firmware_mode_type [CNT_wcmod_firmware_mode_type];
/*! \enum wcmod_os_type 

Oversampling type. The oversampling is fixed for combo. But can be configured
in independent mode to either 0S5 or OS8

*/

typedef enum {
  WCMOD_OS1                  = 0   ,  /*!< Hardly ever used. */
  WCMOD_OS3                        ,  /*!< Hardly ever used. */
  WCMOD_OS5                        ,  /*!< WC Independent mode can have OS5 or OS8 */
  WCMOD_OS6                        ,  /*!< This mode is exclusive to QUAD_SGMII */
  WCMOD_OS_IND_LANE                ,  /*!< This mode is exclusive to XENIA */
  WCMOD_OS8                        ,  /*!< WC Independent mode can have OS5 or OS8 */
  WCMOD_OS_ILLEGAL                   /*!<  */
} wcmod_os_type;

/*! \def CNT_wcmod_os_type Types of enum wcmod_os_type */
#define CNT_wcmod_os_type 7

/*!
\brief
This array returns the string version of the enum #wcmod_port_type when indexed
by the enum var.

*/
extern char* e2s_wcmod_os_type [CNT_wcmod_os_type];
/*! \enum wcmod_duplex_type 

wcmod_duplex_type Duplex types (only half and full duplex supported)

*/

typedef enum {
  WCMOD_SIMPLEX              = 0   ,  /*!< This is never used in WC or any modern PHY chips */
  WCMOD_HALF_DUPLEX                ,  /*!< This is relevent only for 1G and below */
  WCMOD_DUPLEX                     ,  /*!< This is default for 10G and above */
  WCMOD_DUPLEX_ILLEGAL               /*!< Illegal value. programmatic boundary. */
} wcmod_duplex_type;

/*! \def CNT_wcmod_duplex_type Types of enum wcmod_duplex_type */
#define CNT_wcmod_duplex_type 4

/*!
\brief
This array returns the string version of the enum #wcmod_port_type when indexed
by the enum var.

*/
extern char* e2s_wcmod_duplex_type [CNT_wcmod_duplex_type];
/*! \enum wcmod_diag_type 

wcmod_diag_type enumerates categories of diagnostic data.
has many intermediate stages between down and up. This enum is work in progress


<table cellspacing=0>
<tr><td colspan=3><B>'per_lane_control' bit-mappings</B></td></tr>

<tr><td><B>Type</B></td><td><B>Description</B></td><td><B>Scope</B></td></tr>

<tr><td>General</td>
<td> Combo/independent, Device and Revision Id, VCO settings, Firmware state
and version, active/passive lanes, MDIO type. PLL info, Oversampling Info</td>
<td>Device</td></tr>

<tr><td>Link</td>
<td> Speeds, oversampling, interface, forced/Autoneg, link status, sync
status, RX sequencer on/off </td>
<td>Lane</td></tr>

<tr><td>Autoneg</td>
<td> Local and remote advertisement, link status, cl73/37/BAM info </td>
<td>Lane</td></tr>

<tr><td>Internal Traffic</td>
<td> PRBS type, CJPat Type, Prog_data value, Any associated recorded errors,
and misc. info (IPG etc.)</td>
<td>Lane </td></tr>

<tr>
<td>DFE</td>
<td>Equalization info, Tap settings. (pre/post/overrides), peaking filter values </td>
<td>Lane</td></tr>

<tr><td>IEEE info</td>
<td>Clause 72, FEC</td>
<td>Lane</td></tr>

<tr><td>Topology</td>
<td>Looping info (Gloop/rloop), lane swapping, polarity swap info</td>
<td>Device</td></tr>

<tr><td>EEE</td>
<td>EEE full, passthru modes, some window values?</td>
<td>Lane</td></tr>

<tr><td>Eye Margin</td>
<td>Eye margin measurement (readout only)</td>
<td>Lane</td></tr>

<tr><td>All</td>
<td>All of the above. Except eye margin.</td>
<td>Device</td></tr>

</table>


*/

typedef enum {
  WCMOD_DIAG_GENERAL         = 0x00001 ,  /*!< General device wide information.         */
  WCMOD_DIAG_LINK            = 0x00002 ,  /*!< Link specific info.                      */
  WCMOD_DIAG_ANEG            = 0x00004 ,  /*!< Autoneg specific info.                   */
  WCMOD_DIAG_TFC             = 0x00008 ,  /*!< State of tx/rx internal tfc              */
  WCMOD_DIAG_DFE             = 0x00010 ,  /*!< DFE related info.                        */
  WCMOD_DIAG_SLICERS         = 0x00020 ,  /*!< P1, M1, D  slicer values. */
  WCMOD_DIAG_TX_AMPS         = 0x00040 ,  /*!< Idriver, Predriver, post2_coef */
  WCMOD_DIAG_TX_TAPS         = 0x00080 ,  /*!< Pre, Main, Post */
  WCMOD_DIAG_RX_TAPS         = 0x00100 ,  /*!< PF,  VGA, TAP1 through TAP5 */
  WCMOD_DIAG_IEEE            = 0x00200 ,  /*!< IEEE related info                        */
  WCMOD_DIAG_TOPOLOGY        = 0x00400 ,  /*!< Loopbacks etc.                           */
  WCMOD_DIAG_EEE             = 0x00800 ,  /*!< EEE                                      */
  WCMOD_DIAG_EYE             = 0x01000 ,  /*!< eye margin msmt                          */
  WCMOD_DIAG_SPEED           = 0x02000 ,  /*!< sub-category of WCMOD_DIAG_LINK(for SDK) */
  WCMOD_DIAG_TX_LOOPBACK     = 0x04000 ,  /*!< sub-category of WCMOD_DIAG_TOPOLOGY(for SDK) */
  WCMOD_DIAG_RX_LOOPBACK     = 0x08000 ,  /*!< sub-category of WCMOD_DIAG_TOPOLOGY(for SDK) */
  WCMOD_DIAG_RX_PPM          = 0x10000 ,  /*!< ppm offset that receiver is tracking */
  WCMOD_DIAG_PRBS            = 0x20000 ,  /*!< prbs info */
  WCMOD_DIAG_RX_SIGDET       = 0x40000 ,  /*!< Per lane rx signal detect info. */
  WCMOD_DIAG_POLARITY        = 0x80000 ,  /*!< per lane rx/tx polarity */
  WCMOD_DIAG_RX_PCS_BYPASS_LOOPBACK     = 0x100000 ,  /*!< sub-category of WCMOD_DIAG_TOPOLOGY(for SDK) */
  WCMOD_DIAG_PRBS_DECOUPLE_TX  = 0x200000 ,  /*!< sub-category of WCMOD_DIAG_TOPOLOGY(for SDK) */
  WCMOD_DIAG_PRBS_DECOUPLE_RX  = 0x400000 ,  /*!< sub-category of WCMOD_DIAG_TOPOLOGY(for SDK) */
  WCMOD_DIAG_TX_SQUELCH      = 0x800000 ,  /*!< sub-category of WCMOD_Diag for tx_squelch(for SDK) */
  WCMOD_DIAG_ALL             = 0xffffff ,  /*!< Everything but eye margin                */
  WCMOD_DIAG_ILLEGAL         = 0x000000   /*!< Illegal value. programmatic boundary.    */
} wcmod_diag_type;

/*! \def CNT_wcmod_diag_type Types of enum wcmod_diag_type */
#define CNT_wcmod_diag_type 25

/*!
\brief
This array returns the string version of the enum #wcmod_port_type when indexed
by the enum var.

*/
extern char* e2s_wcmod_diag_type [CNT_wcmod_diag_type];

typedef enum {
  WCMOD_INFO_DSC             = 0x000000 , 
  WCMOD_INFO_RD              = 0x000004 , 
  WCMOD_INFO_WR              = 0x000008 , 
  WCMOD_INFO_SPEED           = 0x000010 ,  
  WCMOD_INFO_ANEG            = 0x000020 ,  
  WCMOD_INFO_TX_AMPS         = 0x000040 ,  /* same position as WCMOD_DIAG_TX_AMPS, and below */
  WCMOD_INFO_TX_TAPS         = 0x000080 ,  
  WCMOD_INFO_RX_TAPS         = 0x000100 ,  
  WCMOD_INFO_IEEE            = 0x000200 ,  
  WCMOD_INFO_TOPOLOGY        = 0x000400 ,  
  WCMOD_INFO_EEE             = 0x000800 ,  
  WCMOD_INFO_EYE             = 0x001000 ,  /* 0x002000 is not defined */
  WCMOD_INFO_TX_LOOPBACK     = 0x004000 ,  
  WCMOD_INFO_RX_LOOPBACK     = 0x008000 ,  
  WCMOD_INFO_RX_PPM          = 0x010000 ,  
  WCMOD_INFO_PRBS            = 0x020000 , 
  WCMOD_INFO_RX_SIGDET       = 0x040000 ,  
  WCMOD_INFO_POLARITY        = 0x080000 ,  /* same position as WCMOD_DIAG_POLARITY, and above */
  WCMOD_INFO_TFC             = 0x100000 , 
  WCMOD_INFO_DFE             = 0x200000 ,
  WCMOD_INFO_SLICERS         = 0x400000 ,
  WCMOD_INFO_ALL             = 0x800000 ,   /* 0x80_0000 */
  WCMOD_INFO_ALL_LANES       =0x1000000     /*0x100_0000 */
} wcmod_info_type;



/*! \enum wcmod_model_type 

wcmod_model_type enumerates different generations and  revisions of warpcore.
Note that we pretty much only look at different versions of Warpcore.

We rely on all the information being in the SERDES_ID register.


*/

typedef enum {
  WCMOD_WC                   = 0   ,  /*!< Generic Warpcore (any model) */
  WCMOD_WC_A0                      ,  /*!< Warpcore Version A0 */
  WCMOD_WC_A1                      ,  /*!< Warpcore Version A1 */
  WCMOD_WC_A2                      ,  /*!< Warpcore Version A2 */
  WCMOD_WC_B0                      ,  /*!< Warpcore Version B0 */
  WCMOD_WC_B1                      ,  /*!< Warpcore Version B1 */
  WCMOD_WC_B2                      ,  /*!< Warpcore Version B2 */
  WCMOD_WC_C0                      ,  /*!< Warpcore Version C0, model no. differs from other WCs */
  WCMOD_WC_C1                      ,  /*!< Warpcore Version C1, model no. differs from other WCs */
  WCMOD_WC_C2                      ,  /*!< Warpcore Version C2, model no. differs from other WCs */
  WCMOD_WC_D0                      ,  /*!< Warpcore Version D0 */
  WCMOD_WC_D1                      ,  /*!< Warpcore Version D1 */
  WCMOD_WC_D2                      ,  /*!< Warpcore Version D2 */
  WCMOD_XN                         ,  /*!< Generic Xenia Core (any model) */
  WCMOD_WL                         ,  /*!< Generic Warpcore Lite (any model) */
  WCMOD_WL_A0                      ,  /*!< WarpLite Core A0*/
  WCMOD_WL_B0                      ,  /*!< WarpLite Core B0*/
  WCMOD_QS                         ,  /*!< Generic QSGMII core (any model) */
  WCMOD_QS_A0                      ,  /*!< QSGMII core Version A0 */
  WCMOD_QS_B0                      ,  /*!< QSGMII core Version B0 */
  WCMOD_MODEL_TYPE_ILLEGAL           /*!< Illegal value. programmatic boundary. */
} wcmod_model_type;

/*! \def CNT_wcmod_model_type Types of enum wcmod_model_type */
#define CNT_wcmod_model_type 21

/*!
\brief
This array returns the string version of the enum #wcmod_port_type when indexed
by the enum var.

*/
extern char* e2s_wcmod_model_type [CNT_wcmod_model_type];
/*! \enum wcmod_an_type 

wcmod_an_type enumerates different types of autoneg modes in warpcore.

*/

typedef enum {
  WCMOD_CL73                 = 0   ,  /*!< Warpcore autoneg CL73 enable */
  WCMOD_CL37                       ,  /*!< Warpcore autoneg CL37 enable */
  WCMOD_CL73_BAM                   ,  /*!< Warpcore autoneg CL73 enable with Brcm Aneg Mode */
  WCMOD_CL37_BAM                   ,  /*!< Warpcore autoneg CL37 enable with  Brcm Aneg Mode */
  WCMOD_AN_TYPE_ILLEGAL              /*!< Illegal value. programmatic boundary. */
} wcmod_an_type;

/*! \def CNT_wcmod_an_type Types of enum wcmod_an_type */
#define CNT_wcmod_an_type 5

/*!
\brief
This array returns the string version of the enum #wcmod_port_type when indexed
by the enum var.

*/
extern char* e2s_wcmod_an_type [CNT_wcmod_an_type];
/*! \enum wcmod_tech_ability 

wcmod_tech_ability enumerates different types of speed advertisements in the
basic autoneg page. Currently for CL73 only.

Currently all speeds have the following bit positions in wcmod_st

\li WCMOD_ABILITY_1G_KX            Bit Pos: 0
\li WCMOD_ABILITY_10G_KX4          Bit Pos: 1
\li WCMOD_ABILITY_10G_KR           Bit Pos: 2
\li WCMOD_ABILITY_40G_KR4          Bit Pos: 3
\li WCMOD_ABILITY_40G_CR4          Bit Pos: 4
\li WCMOD_ABILITY_100G_CR10        Bit Pos: 5
\li WCMOD_ABILITY_2P5G             Bit Pos: 6
\li WCMOD_ABILITY_5G_X4            Bit Pos: 7
\li WCMOD_ABILITY_6G_X4            Bit Pos: 8
\li WCMOD_ABILITY_10G_HIGIG        Bit Pos: 9
\li WCMOD_ABILITY_10G_CX4          Bit Pos: 10
\li WCMOD_ABILITY_12G_X4           Bit Pos: 11
\li WCMOD_ABILITY_12P5_X4          Bit Pos: 12
\li WCMOD_ABILITY_13G_X4           Bit Pos: 13
\li WCMOD_ABILITY_15G_X4           Bit Pos: 14
\li WCMOD_ABILITY_16G_X4           Bit Pos: 15
\li WCMOD_ABILITY_20G_X4           Bit Pos: 16
\li WCMOD_ABILITY_40G              Bit Pos: 17
\li WCMOD_ABILITY_31P5G            Bit Pos: 18
\li WCMOD_ABILITY_25P455G          Bit Pos: 19
\li WCMOD_ABILITY_21G_X4           Bit Pos: 20
\li WCMOD_ABILITY_20G_X4S          Bit Pos: 21
\li WCMOD_ABILITY_10G_DXGXS_HIGIG  Bit Pos: 22
\li WCMOD_ABILITY_10G_DXGXS        Bit Pos: 23
\li WCMOD_ABILITY_10P5G_DXGXS      Bit Pos: 24
\li WCMOD_ABILITY_12P5_DXGXS       Bit Pos: 25
\li WCMOD_ABILITY_20G_KR2_HIGIG    Bit Pos: 26
\li WCMOD_ABILITY_20G_KR2          Bit Pos: 27
\li WCMOD_ABILITY_15P75G_R2        Bit Pos: 28


*/

typedef enum {
  WCMOD_ABILITY_1G_KX        = 0   ,  /*!< CL73 speed 1G_KX ease        */
  WCMOD_ABILITY_10G_KX4            ,  /*!< please write comments        */
  WCMOD_ABILITY_10G_KR             ,  /*!< please write comments        */
  WCMOD_ABILITY_40G_KR4            ,  /*!< please write comments        */
  WCMOD_ABILITY_40G_CR4            ,  /*!< please write comments        */
  WCMOD_ABILITY_100G_CR10          ,  /*!< please write comments        */
  WCMOD_ABILITY_2P5G               ,  /*!< please write comments        */
  WCMOD_ABILITY_5G_X4              ,  /*!< please write comments        */
  WCMOD_ABILITY_6G_X4              ,  /*!< please write comments        */
  WCMOD_ABILITY_10G_HIGIG          ,  /*!< please write comments        */
  WCMOD_ABILITY_10G_CX4            ,  /*!< please write comments        */
  WCMOD_ABILITY_12G_X4             ,  /*!< please write comments        */
  WCMOD_ABILITY_12P5_X4            ,  /*!< please write comments        */
  WCMOD_ABILITY_13G_X4             ,  /*!< please write comments        */
  WCMOD_ABILITY_15G_X4             ,  /*!< please write comments        */
  WCMOD_ABILITY_16G_X4             ,  /*!< please write comments        */
  WCMOD_ABILITY_20G_X4             ,  /*!< please write comments        */
  WCMOD_ABILITY_40G                ,  /*!< please write comments        */
  WCMOD_ABILITY_31P5G              ,  /*!< please write comments        */
  WCMOD_ABILITY_25P455G            ,  /*!< please write comments        */
  WCMOD_ABILITY_21G_X4             ,  /*!< please write comments        */
  WCMOD_ABILITY_20G_X4S            ,  /*!< XAUI 8b10b scrambled data    */
  WCMOD_ABILITY_10G_DXGXS_HIGIG       ,  /*!< please write comments        */
  WCMOD_ABILITY_10G_DXGXS          ,  /*!< please write comments        */
  WCMOD_ABILITY_10P5G_DXGXS        ,  /*!< please write comments        */
  WCMOD_ABILITY_12P5_DXGXS         ,  /*!< please write comments        */
  WCMOD_ABILITY_20G_KR2_HIGIG       ,  /*!< please write comments        */
  WCMOD_ABILITY_20G_KR2            ,  /*!< please write comments        */
  WCMOD_ABILITY_15P75G_R2          ,  /*!< please write comments        */
  WCMOD_ABILITY_ILLEGAL              /*!< Illegal. Programmatic boundary */
} wcmod_tech_ability;

/*! \def CNT_wcmod_tech_ability Types of enum wcmod_tech_ability */
#define CNT_wcmod_tech_ability 30

/*!
\brief
This array returns the string version of the enum #wcmod_port_type when indexed
by the enum var.

*/
extern char* e2s_wcmod_tech_ability [CNT_wcmod_tech_ability];
/*!
\brief
This array associates the enum #wcmod_lane_select enum with a bit mask.
The index is the #wcmod_lane_select enum value.  The value for each entry is
interpreted as follows.  If bit [n] is 1, then lane [n] is enabled; if bit [n]
is 0, then lane [n] is disabled.  By enabled, we mean that such-and-such
function is to be called for a lane; by disabled, we mean that such-and-such
function is not to be called for a lane.  So a value of 0xF indicates that all
lanes or enabled, while 0x5 indicates that only lanes 0 and 2 are enabled.

*/
extern int e2n_wcmod_tech_ability [CNT_wcmod_tech_ability];
/*! \enum wcmod_eye_direction 

The direction of slicer changing always moves from the middle of the eye.
Currently all speeds have the following bit positions in wcmod_st

\li WCMOD_EYE_VU: Vertical,   Upward direction
\li WCMOD_EYE_VD: Vertical,   Downward direction
\li WCMOD_EYE_HL: Horizontal, Left  direction
\li WCMOD_EYE_HR: Horizontal, Right direction


*/

typedef enum {
  WCMOD_EYE_VU               = 0   ,  /*!< Vertical,   Upward direction */
  WCMOD_EYE_VD                     ,  /*!< Vertical,   Downward direction */
  WCMOD_EYE_HL                     ,  /*!< Horizontal, Left  direction */
  WCMOD_EYE_HR                     ,  /*!< Horizontal, Right direction */
  WCMOD_EYE_ILLEGAL                  /*!< Programmatic illegal boundary. */
} wcmod_eye_direction;

/*! \def CNT_wcmod_eye_direction Types of enum wcmod_eye_direction */
#define CNT_wcmod_eye_direction 5

/*!
\brief
This array returns the string version of the enum #wcmod_port_type when indexed
by the enum var.

*/
extern char* e2s_wcmod_eye_direction [CNT_wcmod_eye_direction];
#endif /* _WCMOD_ENUM_DEFINES_H */