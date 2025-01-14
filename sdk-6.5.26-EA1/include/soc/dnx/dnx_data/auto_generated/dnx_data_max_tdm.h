
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_MAX_TDM_H_

#define _DNX_DATA_MAX_TDM_H_




#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX (JR2) family only!"
#endif



#define DNX_DATA_MAX_TDM_PARAMS_CONTEXT_MAP_BASE_SIZE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_CONTEXT_MAP_BASE_SIZE

#define DNX_DATA_MAX_TDM_PARAMS_CONTEXT_MAP_BASE_SIZE (14)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_CONTEXT_MAP_BASE_NOF (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_CONTEXT_MAP_BASE_NOF

#define DNX_DATA_MAX_TDM_PARAMS_CONTEXT_MAP_BASE_NOF (16384)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_SID_MIN_SIZE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_SID_MIN_SIZE

#define DNX_DATA_MAX_TDM_PARAMS_SID_MIN_SIZE (1)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_SID_SIZE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_SID_SIZE

#define DNX_DATA_MAX_TDM_PARAMS_SID_SIZE (14)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_NOF_STREAM_IDS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_NOF_STREAM_IDS

#define DNX_DATA_MAX_TDM_PARAMS_NOF_STREAM_IDS (16384)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_GLOBAL_SID_OFFSET_SIZE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_GLOBAL_SID_OFFSET_SIZE

#define DNX_DATA_MAX_TDM_PARAMS_GLOBAL_SID_OFFSET_SIZE (5)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_GLOBAL_SID_OFFSET_NOF (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_GLOBAL_SID_OFFSET_NOF

#define DNX_DATA_MAX_TDM_PARAMS_GLOBAL_SID_OFFSET_NOF (32)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_SID_OFFSET_SIZE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_SID_OFFSET_SIZE

#define DNX_DATA_MAX_TDM_PARAMS_SID_OFFSET_SIZE (6)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_SID_OFFSET_NOF (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_SID_OFFSET_NOF

#define DNX_DATA_MAX_TDM_PARAMS_SID_OFFSET_NOF (33)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_SID_OFFSET_NOF_IN_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_SID_OFFSET_NOF_IN_BITS

#define DNX_DATA_MAX_TDM_PARAMS_SID_OFFSET_NOF_IN_BITS (257)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_SID_MAX_SIZE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_SID_MAX_SIZE

#define DNX_DATA_MAX_TDM_PARAMS_SID_MAX_SIZE (18)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_CONTEXT_SIZE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_CONTEXT_SIZE

#define DNX_DATA_MAX_TDM_PARAMS_CONTEXT_SIZE (10)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_NOF_CONTEXTS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_NOF_CONTEXTS

#define DNX_DATA_MAX_TDM_PARAMS_NOF_CONTEXTS (1024)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_PKT_SIZE_SIZE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_PKT_SIZE_SIZE

#define DNX_DATA_MAX_TDM_PARAMS_PKT_SIZE_SIZE (10)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_PKT_SIZE_LOWER_LIMIT (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_PKT_SIZE_LOWER_LIMIT

#define DNX_DATA_MAX_TDM_PARAMS_PKT_SIZE_LOWER_LIMIT (64)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_PKT_SIZE_UPPER_LIMIT (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_PKT_SIZE_UPPER_LIMIT

#define DNX_DATA_MAX_TDM_PARAMS_PKT_SIZE_UPPER_LIMIT (511)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_LINK_MASK_SIZE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_LINK_MASK_SIZE

#define DNX_DATA_MAX_TDM_PARAMS_LINK_MASK_SIZE (6)

#endif 


#define DNX_DATA_MAX_TDM_PARAMS_LINK_MASK_NOF (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TDM_PARAMS_LINK_MASK_NOF

#define DNX_DATA_MAX_TDM_PARAMS_LINK_MASK_NOF (36)

#endif 




#endif 

