/***********************************************************************************
 *                                                                                 *
 * Copyright: (c) 2021 Broadcom.                                                   *
 * Broadcom Proprietary and Confidential. All rights reserved.                     *
 *                                                                                 *
 ***********************************************************************************/

/******************************************************************************
 ******************************************************************************
 *  Revision      :   *
 *                                                                            *
 *  Description   :  Enum types used by Serdes API functions                  *
 *                                                                            *
 ******************************************************************************
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BLACKHAWK7_L2P2_API_ENUM_H
#define BLACKHAWK7_L2P2_API_ENUM_H

#include "blackhawk7_l2p2_ipconfig.h"
#ifdef NON_SDK
#include <stdint.h>
#endif

/*! @file
 *  @brief Enum types used by Serdes API functions
 */

/*! @addtogroup APITag
 * @{
 */

/*! @defgroup SerdesAPIEnumTag Serdes API Enums
 * Enums used throughout Serdes APIs.
 */

/*! @addtogroup SerdesAPIEnumTag
 * @{
 */


/*--------------------------*/
/** Serdes RX PAM Mode Enum */
/*--------------------------*/
enum blackhawk7_l2p2_rx_pam_mode_enum {
    NRZ,
    PAM4_NR,
    PAM4_ER
};

enum blackhawk7_l2p2_cdr_enum {
    OS,
    BR
};

/*! Reference clock frequency enums
 *
 */
enum blackhawk7_l2p2_pll_refclk_enum {
    BLACKHAWK7_L2P2_PLL_REFCLK_UNKNOWN = 0, /*!< Refclk value to be determined by API. */
    BLACKHAWK7_L2P2_PLL_REFCLK_145P947802MHZ  = (int)0x16C0CF85, /*!< 145.947802 MHz  */
    BLACKHAWK7_L2P2_PLL_REFCLK_166P7974882MHZ = (int)0x27D19F0A, /*!< 166.7974882 MHz */
    BLACKHAWK7_L2P2_PLL_REFCLK_167P4107143MHZ = (int)0x0380249F, /*!< 167.4107143 MHz */
    BLACKHAWK7_L2P2_PLL_REFCLK_245P76MHZ      = (int)0x01901800, /*!< 245.76 MHz      */
    BLACKHAWK7_L2P2_PLL_REFCLK_250MHZ         = (int)0x001000FA, /*!< 250 MHz         */
    BLACKHAWK7_L2P2_PLL_REFCLK_425MHZ         = (int)0x001001A9, /*!< 425 MHz         */
    BLACKHAWK7_L2P2_PLL_REFCLK_534MHZ         = (int)0x00100216, /*!< 534 MHz         */
    BLACKHAWK7_L2P2_PLL_REFCLK_705MHZ         = (int)0x001002C1, /*!< 705 MHz         */
    BLACKHAWK7_L2P2_PLL_REFCLK_175MHZ         = (int)0x001000AF, /*!< 175 MHz         */
    BLACKHAWK7_L2P2_PLL_REFCLK_400MHZ         = (int)0x00100190, /*!< 400 MHz         */
    BLACKHAWK7_L2P2_PLL_REFCLK_266P67MHZ      = (int)0x0640682B, /*!< 266.67 MHz      */
    BLACKHAWK7_L2P2_PLL_REFCLK_100MHZ         = (int)0x00100064, /*!< 100 MHz         */
    BLACKHAWK7_L2P2_PLL_REFCLK_106P25MHZ      = (int)0x004001A9, /*!< 106.25 MHz      */
    BLACKHAWK7_L2P2_PLL_REFCLK_122P88MHZ      = (int)0x01900C00, /*!< 122.88 MHz      */
    BLACKHAWK7_L2P2_PLL_REFCLK_125MHZ         = (int)0x0010007D, /*!< 125 MHz         */
    BLACKHAWK7_L2P2_PLL_REFCLK_155P52MHZ      = (int)0x01900F30, /*!< 155.52 MHz      */
    BLACKHAWK7_L2P2_PLL_REFCLK_156P25MHZ      = (int)0x00400271, /*!< 156.25 MHz      */
    BLACKHAWK7_L2P2_PLL_REFCLK_159P375MHZ     = (int)0x008004FB, /*!< 159.375 MHz     */
    BLACKHAWK7_L2P2_PLL_REFCLK_161P1328125MHZ = (int)0x08005091, /*!< 161.1328125 MHz */
    BLACKHAWK7_L2P2_PLL_REFCLK_166P67MHZ      = (int)0x0640411B, /*!< 166.67 MHz      */
    BLACKHAWK7_L2P2_PLL_REFCLK_166P015625MHZ  = (int)0x64040D99, /*!< 166.015625 MHz */
    BLACKHAWK7_L2P2_PLL_REFCLK_167P38MHZ      = (int)0x06404162, /*!< 167.38 MHz      */
    BLACKHAWK7_L2P2_PLL_REFCLK_174P703125MHZ  = (int)0x04002BAD, /*!< 174.703125 MHz  */
    BLACKHAWK7_L2P2_PLL_REFCLK_212P5MHZ       = (int)0x002001A9, /*!< 212.5 MHz       */
    BLACKHAWK7_L2P2_PLL_REFCLK_311P04MHZ      = (int)0x01901E60, /*!< 311.04 MHz      */
    BLACKHAWK7_L2P2_PLL_REFCLK_312P5MHZ       = (int)0x00200271  /*!< 312.5 MHz       */
    };

/** @brief Enumeration DIV values used by PLL configuration APIs.
 */
enum blackhawk7_l2p2_pll_div_enum {
    BLACKHAWK7_L2P2_PLL_DIV_UNKNOWN = 0, /*!< Divide value to be determined by API. */
    BLACKHAWK7_L2P2_PLL_DIV_82P50128477= (int)0x80544052, /*!< Divide by 82.50128477*/
    BLACKHAWK7_L2P2_PLL_DIV_85P67380253= (int)0xAC7E4055, /*!< Divide by 85.67380253*/
    BLACKHAWK7_L2P2_PLL_DIV_88P39285714= (int)0x64924058, /*!< Divide by 88.39285714*/
    BLACKHAWK7_L2P2_PLL_DIV_88P76582278= (int)0xC40D0058, /*!< Divide by 88.76582278*/
    BLACKHAWK7_L2P2_PLL_DIV_89P44777920= (int)0x72A1C059, /*!< Divide by 89.44777920*/
    BLACKHAWK7_L2P2_PLL_DIV_89P84376637= (int)0xD8010059, /*!< Divide by 89.84376637*/
    BLACKHAWK7_L2P2_PLL_DIV_179P6875327= (int)0xB00240B3, /*!< Divide by 179.6875327 */
    BLACKHAWK7_L2P2_PLL_DIV_66         = (int)0x00000042, /*!< Divide by 66         */
    BLACKHAWK7_L2P2_PLL_DIV_67         = (int)0x00000043, /*!< Divide by 67         */
    BLACKHAWK7_L2P2_PLL_DIV_70         = (int)0x00000046, /*!< Divide by 70         */
    BLACKHAWK7_L2P2_PLL_DIV_72         = (int)0x00000048, /*!< Divide by 72         */
    BLACKHAWK7_L2P2_PLL_DIV_74P25      = (int)0x4000004A, /*!< Divide by 74.25      */
    BLACKHAWK7_L2P2_PLL_DIV_76         = (int)0x0000004C, /*!< Divide by 76         */
    BLACKHAWK7_L2P2_PLL_DIV_73P6       = (int)0x99998049, /*!< Divide by 73.6       */
    BLACKHAWK7_L2P2_PLL_DIV_79P2       = (int)0x3333004F, /*!< Divide by 79.2       */
    BLACKHAWK7_L2P2_PLL_DIV_80         = (int)0x00000050, /*!< Divide by 80         */
    BLACKHAWK7_L2P2_PLL_DIV_82P5       = (int)0x80000052, /*!< Divide by 82.5       */
    BLACKHAWK7_L2P2_PLL_DIV_84         = (int)0x00000054, /*!< Divide by 84         */
    BLACKHAWK7_L2P2_PLL_DIV_85         = (int)0x00000055, /*!< Divide by 85         */
    BLACKHAWK7_L2P2_PLL_DIV_87P5       = (int)0x80000057, /*!< Divide by 87.5       */
    BLACKHAWK7_L2P2_PLL_DIV_89P6       = (int)0x99998059, /*!< Divide by 89.6       */
    BLACKHAWK7_L2P2_PLL_DIV_90         = (int)0x0000005A, /*!< Divide by 90         */
    BLACKHAWK7_L2P2_PLL_DIV_90P75      = (int)0xC000005A, /*!< Divide by 90.75      */
    BLACKHAWK7_L2P2_PLL_DIV_96         = (int)0x00000060, /*!< Divide by 96         */
    BLACKHAWK7_L2P2_PLL_DIV_100        = (int)0x00000064, /*!< Divide by 100        */
    BLACKHAWK7_L2P2_PLL_DIV_120        = (int)0x00000078, /*!< Divide by 120        */
    BLACKHAWK7_L2P2_PLL_DIV_127P401984 = (int)0x66E8807F, /*!< Divide by 127.401984 */
    BLACKHAWK7_L2P2_PLL_DIV_128        = (int)0x00000080, /*!< Divide by 128        */
    BLACKHAWK7_L2P2_PLL_DIV_136        = (int)0x00000088, /*!< Divide by 136        */
    BLACKHAWK7_L2P2_PLL_DIV_137P721519 = (int)0xB8B58089, /*!< Divide by 137.721519 */
    BLACKHAWK7_L2P2_PLL_DIV_140        = (int)0x0000008C, /*!< Divide by 140        */
    BLACKHAWK7_L2P2_PLL_DIV_142P0253165= (int)0x067B408E, /*!< Divide by 142.0253165*/
    BLACKHAWK7_L2P2_PLL_DIV_144        = (int)0x00000090, /*!< Divide by 144        */
    BLACKHAWK7_L2P2_PLL_DIV_152        = (int)0x00000098, /*!< Divide by 152        */
    BLACKHAWK7_L2P2_PLL_DIV_165P7770801= (int)0xC6EEC0A5, /*!< Divide by 165.7770801*/
    BLACKHAWK7_L2P2_PLL_DIV_170P800628 = (int)0xCCF600AA, /*!< Divide by 170.800628 */
    BLACKHAWK7_L2P2_PLL_DIV_141P4285714= (int)0x6DB6C08D, /*!< Divide by 141.4285714*/
    BLACKHAWK7_L2P2_PLL_DIV_171P347605 = (int)0x58FCC0AB, /*!< Divide by 171.347605 */
    BLACKHAWK7_L2P2_PLL_DIV_176P7857143= (int)0xC92480B0, /*!< Divide by 176.7857143*/
    BLACKHAWK7_L2P2_PLL_DIV_177P5316456= (int)0x881A00B1, /*!< Divide by 177.5316456*/
    BLACKHAWK7_L2P2_PLL_DIV_178P8955584= (int)0xE54340B2, /*!< Divide by 178.8955584*/
    BLACKHAWK7_L2P2_PLL_DIV_179P7348805= (int)0xBC2140B3, /*!< Divide by 179.7348805*/
    BLACKHAWK7_L2P2_PLL_DIV_179P7356828= (int)0xBC55C0B3, /*!< Divide by 179.7356828*/
    BLACKHAWK7_L2P2_PLL_DIV_180P5309734= (int)0x87EDC0B4, /*!< Divide by 180.5309734*/
    BLACKHAWK7_L2P2_PLL_DIV_184        = (int)0x000000B8, /*!< Divide by 184        */
    BLACKHAWK7_L2P2_PLL_DIV_192        = (int)0x000000C0, /*!< Divide by 192        */
    BLACKHAWK7_L2P2_PLL_DIV_198        = (int)0x000000C6, /*!< Divide by 198        */
    BLACKHAWK7_L2P2_PLL_DIV_200        = (int)0x000000C8, /*!< Divide by 200        */
    BLACKHAWK7_L2P2_PLL_DIV_224        = (int)0x000000E0, /*!< Divide by 224        */
    BLACKHAWK7_L2P2_PLL_DIV_240        = (int)0x000000F0, /*!< Divide by 240        */
    BLACKHAWK7_L2P2_PLL_DIV_54         = (int)0x00000036, /*!< Divide by 54         */
    BLACKHAWK7_L2P2_PLL_DIV_108        = (int)0x0000006C, /*!< Divide by 108        */
    BLACKHAWK7_L2P2_PLL_DIV_132        = (int)0x00000084, /*!< Divide by 132        */
    BLACKHAWK7_L2P2_PLL_DIV_147P2      = (int)0x33330093, /*!< Divide by 147.2      */
    BLACKHAWK7_L2P2_PLL_DIV_158P4      = (int)0x6666809E, /*!< Divide by 158.4      */
    BLACKHAWK7_L2P2_PLL_DIV_160        = (int)0x000000A0, /*!< Divide by 160        */
    BLACKHAWK7_L2P2_PLL_DIV_165        = (int)0x000000A5, /*!< Divide by 165        */
    BLACKHAWK7_L2P2_PLL_DIV_168        = (int)0x000000A8, /*!< Divide by 168        */
    BLACKHAWK7_L2P2_PLL_DIV_170        = (int)0x000000AA, /*!< Divide by 170        */
    BLACKHAWK7_L2P2_PLL_DIV_175        = (int)0x000000AF, /*!< Divide by 175        */
    BLACKHAWK7_L2P2_PLL_DIV_180        = (int)0x000000B4, /*!< Divide by 180        */
    BLACKHAWK7_L2P2_PLL_DIV_264        = (int)0x00000108, /*!< Divide by 264        */
    BLACKHAWK7_L2P2_PLL_DIV_280        = (int)0x00000118, /*!< Divide by 280        */
    BLACKHAWK7_L2P2_PLL_DIV_330        = (int)0x0000014A, /*!< Divide by 330        */
    BLACKHAWK7_L2P2_PLL_DIV_350        = (int)0x0000015E  /*!< Divide by 350        */
};

/** TX AFE Settings Enum */
enum blackhawk7_l2p2_tx_afe_settings_enum {
    BLACKHAWK7_L2P2_TX_AFE_TAP0,
    BLACKHAWK7_L2P2_TX_AFE_TAP1,
    BLACKHAWK7_L2P2_TX_AFE_TAP2,
    BLACKHAWK7_L2P2_TX_AFE_TAP3,
    BLACKHAWK7_L2P2_TX_AFE_TAP4,
    BLACKHAWK7_L2P2_TX_AFE_TAP5
};

/** TXFIR Tap Enable Enum */
enum blackhawk7_l2p2_txfir_tap_enable_enum {
    BLACKHAWK7_L2P2_NRZ_LP_3TAP  = 0,
    BLACKHAWK7_L2P2_NRZ_6TAP     = 1,
    BLACKHAWK7_L2P2_PAM4_LP_3TAP = 2,
    BLACKHAWK7_L2P2_PAM4_6TAP    = 3
};

/*! @def BLACKHAWK7_L2P2_PLL_OPTION_REFCLK_MASK
 * Mask used for REFCLK options within enum blackhawk7_l2p2_pll_option_enum.
 * All REFCLK options should fall within this mask's range.
 */
#define BLACKHAWK7_L2P2_PLL_OPTION_REFCLK_MASK (0xF)

/** PLL Configuration Options Enum used for configure_pll APIs
 *  If using REFCLK options, only one REFCLK option may be used at a time.
 */
enum blackhawk7_l2p2_pll_option_enum {
    BLACKHAWK7_L2P2_PLL_OPTION_NONE              =  0,
    BLACKHAWK7_L2P2_PLL_OPTION_REFCLK_DOUBLER_EN =  1,
    BLACKHAWK7_L2P2_PLL_OPTION_REFCLK_DIV2_EN    =  2,
    BLACKHAWK7_L2P2_PLL_OPTION_REFCLK_DIV4_EN    =  3,
    BLACKHAWK7_L2P2_PLL_OPTION_POWERDOWN         =  1<<4,
    BLACKHAWK7_L2P2_PLL_OPTION_DISABLE_VERIFY    =  1<<5
};

/** DCO DAC Step Size Enum */
enum blackhawk7_l2p2_dco_dac_step_size_enum {
    BLACKHAWK7_L2P2_DCO_DAC_STEP_SIZE_0P8_MV           = 2,
    BLACKHAWK7_L2P2_DCO_DAC_STEP_SIZE_1P2_MV           = 3
};
/** DCO DAC Step Size Enum */
enum blackhawk7_l2p2_dco_dac_step_size_boost_enum {
    BLACKHAWK7_L2P2_DCO_DAC_STEP_SIZE_BOOST_n12P5_PCT  = 1,
    BLACKHAWK7_L2P2_DCO_DAC_STEP_SIZE_BOOST_0_PCT      = 3,
    BLACKHAWK7_L2P2_DCO_DAC_STEP_SIZE_BOOST_12P5_PCT   = 5,
    BLACKHAWK7_L2P2_DCO_DAC_STEP_SIZE_BOOST_25_PCT     = 7
};

/** Force / Get Force CDR Mode Enum */
enum blackhawk7_l2p2_force_cdr_mode_enum {
    BLACKHAWK7_L2P2_OSCDR_FORCE_ENABLE,     /*!< Force OS-CDR mode */
    BLACKHAWK7_L2P2_OSCDR_FORCE_DISABLE,    /*!< Disable Force OS-CDR mode */
    BLACKHAWK7_L2P2_BRCDR_FORCE_ENABLE,     /*!< Force BR-CDR mode */
    BLACKHAWK7_L2P2_BRCDR_FORCE_DISABLE,    /*!< Disable Force BR-CDR mode */
    BLACKHAWK7_L2P2_CDR_FORCE_DISABLE       /*!< Disable Force CDR modes */
};

/** PRBS Error Analyzer Aggregate Mode */
enum srds_prbs_error_analyzer_aggregate_mode_enum {
    SRDS_IEEE_50GE,              /* 50G w/ Bit Muxing 2:1 and No Code Word Interleaving 50GE/100GE 56G BHK */
    SRDS_BHK_200GE,              /* 200G w/ Bit Muxing 2:1 and 2 Code Word Interleaving 200GE/400GE 56G BHK */
    SRDS_CUSTOM
};






/*! @} SerdesAPIEnumTag */
/*! @} APITag */
#endif /*#define BLACKHAWK7_L2P2_API_ENUM_H*/
#ifdef __cplusplus
}
#endif
