
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_MAX_LATENCY_H_

#define _DNX_DATA_MAX_LATENCY_H_




#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX family only!"
#endif


#define DNX_DATA_MAX_LATENCY_FEATURES_LATENCY_BINS (1)

#undef DNX_DATA_MAX_LATENCY_FEATURES_LATENCY_BINS
#define DNX_DATA_MAX_LATENCY_FEATURES_LATENCY_BINS (8)


#define DNX_DATA_MAX_LATENCY_PROFILE_EGRESS_NOF (1)

#undef DNX_DATA_MAX_LATENCY_PROFILE_EGRESS_NOF
#define DNX_DATA_MAX_LATENCY_PROFILE_EGRESS_NOF (16)


#define DNX_DATA_MAX_LATENCY_PROFILE_INGRESS_NOF (1)

#undef DNX_DATA_MAX_LATENCY_PROFILE_INGRESS_NOF
#define DNX_DATA_MAX_LATENCY_PROFILE_INGRESS_NOF (32)


#define DNX_DATA_MAX_LATENCY_BASED_ADMISSION_REJECT_FLOW_PROFILE_VALUE (1)

#undef DNX_DATA_MAX_LATENCY_BASED_ADMISSION_REJECT_FLOW_PROFILE_VALUE
#define DNX_DATA_MAX_LATENCY_BASED_ADMISSION_REJECT_FLOW_PROFILE_VALUE (16)


#define DNX_DATA_MAX_LATENCY_BASED_ADMISSION_CGM_EXTENDED_PROFILES_ENABLE_VALUE (1)

#undef DNX_DATA_MAX_LATENCY_BASED_ADMISSION_CGM_EXTENDED_PROFILES_ENABLE_VALUE
#define DNX_DATA_MAX_LATENCY_BASED_ADMISSION_CGM_EXTENDED_PROFILES_ENABLE_VALUE (1)


#define DNX_DATA_MAX_LATENCY_BASED_ADMISSION_MAX_SUPPORTED_PROFILE (1)

#undef DNX_DATA_MAX_LATENCY_BASED_ADMISSION_MAX_SUPPORTED_PROFILE
#define DNX_DATA_MAX_LATENCY_BASED_ADMISSION_MAX_SUPPORTED_PROFILE (31)


#define DNX_DATA_MAX_LATENCY_INGRESS_JR_MODE_LATENCY_TIMESTAMP_LEFT_SHIFT (1)

#undef DNX_DATA_MAX_LATENCY_INGRESS_JR_MODE_LATENCY_TIMESTAMP_LEFT_SHIFT
#define DNX_DATA_MAX_LATENCY_INGRESS_JR_MODE_LATENCY_TIMESTAMP_LEFT_SHIFT (5)


#define DNX_DATA_MAX_LATENCY_INGRESS_NOF_FLOW_PROFILE (1)

#undef DNX_DATA_MAX_LATENCY_INGRESS_NOF_FLOW_PROFILE
#define DNX_DATA_MAX_LATENCY_INGRESS_NOF_FLOW_PROFILE (16)





#endif 
