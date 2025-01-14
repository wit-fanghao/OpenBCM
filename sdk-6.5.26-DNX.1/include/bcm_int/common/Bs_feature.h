/*
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * File:    BS_feature.h
 *
 * Holds SDK features version info, to be shared with BS FW
 */

#ifndef __BS_FEATURE_H__
#define __BS_FEATURE_H__

/*#define _BCM_MBOX_SDK_VERSION         (0x01000000)*/
/*#define _BCM_MBOX_UC_MIN_VERSION      (0x01000000)*/

#define ENABLE       1
#define DISABLE      0
#define BS_SDK_BASE_VERSION         0x01000000
#define BS_SDK_VERSION   BS_SDK_BASE_VERSION         | \
                             (ENABLE << BS_NTP_PTP_TOD_DISABLE)    | \
                             (ENABLE << BS_NTP_PTP_TOD_OFFSET_CONFIG)

#define BS_MIN_UC_VERSION     0x01000000

/*BS FW version*/
extern uint32 bs_firmware_version;

#define BS_UC_FEATURE_CHECK(feature)  (bs_firmware_version & (1 << feature))

/* Feature support bit should be shared between SDK and BS UKERNEL version.
 * 8th and 24th bit is reserved as they are set in the legacy version
 * BS_BASE_SDK_VERSION : 0x01000000,BS_FW_VERSION : 0x01000100*/
#define BS_FEATURE_RESERVED1  8
#define BS_FEATURE_RESERVED2  24

/* Features added in uKernel BS SDK */
#define BS_NTP_PTP_TOD_DISABLE      1 /* Feature to disable NTP and PTP ToD updates */
#define BS_NTP_PTP_TOD_OFFSET_CONFIG  2  /* Feature to add offset to NTP and PTP ToD */

#endif /*__BS_FEATURE_H__*/

