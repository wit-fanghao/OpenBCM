
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_MAX_SWITCH_H_

#define _DNX_DATA_MAX_SWITCH_H_




#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX (JR2) family only!"
#endif



#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LB_CLIENTS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LB_CLIENTS

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LB_CLIENTS (5)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LB_CRC_SEL_TCAM_ENTRIES (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LB_CRC_SEL_TCAM_ENTRIES

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LB_CRC_SEL_TCAM_ENTRIES (32)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_CRC_FUNCTIONS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_CRC_FUNCTIONS

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_CRC_FUNCTIONS (8)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_LABEL (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_LABEL

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_LABEL (0)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_LABEL_FORCE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_LABEL_FORCE

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_LABEL_FORCE (0)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_NEXT_LABEL (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_NEXT_LABEL

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_NEXT_LABEL (65535)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_NEXT_LABEL_VALID (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_NEXT_LABEL_VALID

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_INITIAL_RESERVED_NEXT_LABEL_VALID (65535)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_RESERVED_NEXT_LABEL_VALID (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_RESERVED_NEXT_LABEL_VALID

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_RESERVED_NEXT_LABEL_VALID (1)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NUM_VALID_MPLS_PROTOCOLS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NUM_VALID_MPLS_PROTOCOLS

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NUM_VALID_MPLS_PROTOCOLS (3)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LAYER_RECORDS_FROM_PARSER (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LAYER_RECORDS_FROM_PARSER

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LAYER_RECORDS_FROM_PARSER (8)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_SEEDS_PER_CRC_FUNCTION (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_SEEDS_PER_CRC_FUNCTION

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_SEEDS_PER_CRC_FUNCTION (65536)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_HASHING_SELECTION_PER_LAYER (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_HASHING_SELECTION_PER_LAYER

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_HASHING_SELECTION_PER_LAYER (1)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_MPLS_SPLIT_STACK_CONFIG (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_MPLS_SPLIT_STACK_CONFIG

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_MPLS_SPLIT_STACK_CONFIG (1)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_MPLS_CAM_NEXT_LABEL_VALID_FIELD_EXISTS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_MPLS_CAM_NEXT_LABEL_VALID_FIELD_EXISTS

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_MPLS_CAM_NEXT_LABEL_VALID_FIELD_EXISTS (1)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_PADDED_LAYERS_CRC_BUFFER (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_PADDED_LAYERS_CRC_BUFFER

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_PADDED_LAYERS_CRC_BUFFER (1)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_WIDE_HASH_BUFFER (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_WIDE_HASH_BUFFER

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_WIDE_HASH_BUFFER (1)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LB_MPLS_STACK (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LB_MPLS_STACK

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_LB_MPLS_STACK (4)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_BITS_MPLS_PROTOCOL_IDENTIFIER (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_BITS_MPLS_PROTOCOL_IDENTIFIER

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_NOF_BITS_MPLS_PROTOCOL_IDENTIFIER (5)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_SEED_CONFIGURATION_PER_PP_PORT (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_SEED_CONFIGURATION_PER_PP_PORT

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_SEED_CONFIGURATION_PER_PP_PORT (0)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_SWIG_BASE_OFFLINE_SIMULATION (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_SWIG_BASE_OFFLINE_SIMULATION

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_SWIG_BASE_OFFLINE_SIMULATION (0)

#endif 


#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_SIM_DEVICE_ENUM (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_LOAD_BALANCING_SIM_DEVICE_ENUM

#define DNX_DATA_MAX_SWITCH_LOAD_BALANCING_SIM_DEVICE_ENUM (6)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_SUPPORTED (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_SUPPORTED

#define DNX_DATA_MAX_SWITCH_SVTAG_SUPPORTED (1)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_SVTAG_LABEL_SIZE_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_SVTAG_LABEL_SIZE_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_SVTAG_LABEL_SIZE_BITS (32)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_OFFSET_ADDR_SIZE_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_OFFSET_ADDR_SIZE_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_OFFSET_ADDR_SIZE_BITS (8)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_OFFSET_ADDR_POSITION_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_OFFSET_ADDR_POSITION_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_OFFSET_ADDR_POSITION_BITS (16)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SIGNATURE_SIZE_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SIGNATURE_SIZE_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SIGNATURE_SIZE_BITS (8)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SIGNATURE_POSITION_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SIGNATURE_POSITION_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SIGNATURE_POSITION_BITS (24)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SCI_SIZE_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SCI_SIZE_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SCI_SIZE_BITS (10)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SCI_POSITION_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SCI_POSITION_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_SCI_POSITION_BITS (0)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_PKT_TYPE_SIZE_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_PKT_TYPE_SIZE_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_PKT_TYPE_SIZE_BITS (2)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_PKT_TYPE_POSITION_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_PKT_TYPE_POSITION_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_PKT_TYPE_POSITION_BITS (10)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_IPV6_INDICATION_POSITION_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_IPV6_INDICATION_POSITION_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_IPV6_INDICATION_POSITION_BITS (15)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_HW_FIELD_POSITION_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_HW_FIELD_POSITION_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_HW_FIELD_POSITION_BITS (0)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_ACCUMULATION_INDICATION_HW_FIELD_POSITION_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_ACCUMULATION_INDICATION_HW_FIELD_POSITION_BITS

#define DNX_DATA_MAX_SWITCH_SVTAG_EGRESS_SVTAG_ACCUMULATION_INDICATION_HW_FIELD_POSITION_BITS (32)

#endif 


#define DNX_DATA_MAX_SWITCH_SVTAG_UDP_DEDICATED_PORT (1)


#define DNX_DATA_MAX_SWITCH_SVTAG_INGRESS_SVTAG_POSITION_BYTES (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_SWITCH_SVTAG_INGRESS_SVTAG_POSITION_BYTES

#define DNX_DATA_MAX_SWITCH_SVTAG_INGRESS_SVTAG_POSITION_BYTES (12)

#endif 




#endif 

