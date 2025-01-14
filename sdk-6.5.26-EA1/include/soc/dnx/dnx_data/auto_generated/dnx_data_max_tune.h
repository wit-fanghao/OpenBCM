
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_MAX_TUNE_H_

#define _DNX_DATA_MAX_TUNE_H_




#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX (JR2) family only!"
#endif



#define DNX_DATA_MAX_TUNE_ECGM_CORE_FLOW_CONTROL_PERCENTAGE_RATIO (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TUNE_ECGM_CORE_FLOW_CONTROL_PERCENTAGE_RATIO

#define DNX_DATA_MAX_TUNE_ECGM_CORE_FLOW_CONTROL_PERCENTAGE_RATIO (92)

#endif 


#define DNX_DATA_MAX_TUNE_ECGM_PORT_QUEUE_UC_FLOW_CONTROL_MIN_THRESH (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TUNE_ECGM_PORT_QUEUE_UC_FLOW_CONTROL_MIN_THRESH

#define DNX_DATA_MAX_TUNE_ECGM_PORT_QUEUE_UC_FLOW_CONTROL_MIN_THRESH (100)

#endif 


#define DNX_DATA_MAX_TUNE_ECGM_TOTAL_DBS (1)


#define DNX_DATA_MAX_TUNE_ECGM_UC_POOL_SIZE_GLOBAL_CORE_TH (1)


#define DNX_DATA_MAX_TUNE_ECGM_MC_POOL_SIZE_GLOBAL_CORE_TH (1)


#define DNX_DATA_MAX_TUNE_ECGM_MC_DROP_GLOBAL_CORE_TH (1)


#define DNX_DATA_MAX_TUNE_ECGM_UC_FC_GLOBAL_CORE_TH (1)


#define DNX_DATA_MAX_TUNE_IQS_CREDIT_RESOLUTION_UP_TH (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TUNE_IQS_CREDIT_RESOLUTION_UP_TH

#define DNX_DATA_MAX_TUNE_IQS_CREDIT_RESOLUTION_UP_TH (131072)

#endif 


#define DNX_DATA_MAX_TUNE_FABRIC_CGM_LLFC_PIPE_TH (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TUNE_FABRIC_CGM_LLFC_PIPE_TH

#define DNX_DATA_MAX_TUNE_FABRIC_CGM_LLFC_PIPE_TH (376)

#endif 


#define DNX_DATA_MAX_TUNE_FABRIC_CGM_DROP_FABRIC_CLASS_TH (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TUNE_FABRIC_CGM_DROP_FABRIC_CLASS_TH

#define DNX_DATA_MAX_TUNE_FABRIC_CGM_DROP_FABRIC_CLASS_TH (2048)

#endif 


#define DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_HIGH_SEV_MIN_LINKS_PARAM (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_HIGH_SEV_MIN_LINKS_PARAM

#define DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_HIGH_SEV_MIN_LINKS_PARAM (64)

#endif 


#define DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_EGRESS_PIPE_LEVEL_TH_BASE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_EGRESS_PIPE_LEVEL_TH_BASE

#define DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_EGRESS_PIPE_LEVEL_TH_BASE (1000)

#endif 


#define DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_EGRESS_PIPE_LEVEL_TH_OFFSET (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_EGRESS_PIPE_LEVEL_TH_OFFSET

#define DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_EGRESS_PIPE_LEVEL_TH_OFFSET (300)

#endif 


#define DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_TOTAL_EGRESS_PIPE_LEVEL_TH_BASE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_TOTAL_EGRESS_PIPE_LEVEL_TH_BASE

#define DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_TOTAL_EGRESS_PIPE_LEVEL_TH_BASE (4000)

#endif 


#define DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_TOTAL_EGRESS_PIPE_LEVEL_TH_OFFSET (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_TOTAL_EGRESS_PIPE_LEVEL_TH_OFFSET

#define DNX_DATA_MAX_TUNE_FABRIC_CGM_RCI_TOTAL_EGRESS_PIPE_LEVEL_TH_OFFSET (1000)

#endif 




#endif 

