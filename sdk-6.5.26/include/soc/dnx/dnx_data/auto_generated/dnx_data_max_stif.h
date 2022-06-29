
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_MAX_STIF_H_

#define _DNX_DATA_MAX_STIF_H_




#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX family only!"
#endif


#define DNX_DATA_MAX_STIF_CONFIG_SRAM_BUFFERS_RESOLUTION (1)

#undef DNX_DATA_MAX_STIF_CONFIG_SRAM_BUFFERS_RESOLUTION
#define DNX_DATA_MAX_STIF_CONFIG_SRAM_BUFFERS_RESOLUTION (16)


#define DNX_DATA_MAX_STIF_CONFIG_SRAM_PDBS_RESOLUTION (1)

#undef DNX_DATA_MAX_STIF_CONFIG_SRAM_PDBS_RESOLUTION
#define DNX_DATA_MAX_STIF_CONFIG_SRAM_PDBS_RESOLUTION (16)


#define DNX_DATA_MAX_STIF_CONFIG_DRAM_BDB_RESOLUTION (1)

#undef DNX_DATA_MAX_STIF_CONFIG_DRAM_BDB_RESOLUTION
#define DNX_DATA_MAX_STIF_CONFIG_DRAM_BDB_RESOLUTION (16)


#define DNX_DATA_MAX_STIF_PORT_MAX_NOF_INSTANCES (1)

#undef DNX_DATA_MAX_STIF_PORT_MAX_NOF_INSTANCES
#define DNX_DATA_MAX_STIF_PORT_MAX_NOF_INSTANCES (4)


#define DNX_DATA_MAX_STIF_PORT_STIF_ETHU_SELECT_SIZE (1)

#undef DNX_DATA_MAX_STIF_PORT_STIF_ETHU_SELECT_SIZE
#define DNX_DATA_MAX_STIF_PORT_STIF_ETHU_SELECT_SIZE (6)


#define DNX_DATA_MAX_STIF_PORT_STIF_LANE_MAPPING_SIZE (1)

#undef DNX_DATA_MAX_STIF_PORT_STIF_LANE_MAPPING_SIZE
#define DNX_DATA_MAX_STIF_PORT_STIF_LANE_MAPPING_SIZE (4)


#define DNX_DATA_MAX_STIF_PORT_ETHU_ID  (1)

#undef DNX_DATA_MAX_STIF_PORT_ETHU_ID
#define DNX_DATA_MAX_STIF_PORT_ETHU_ID  (3)


#define DNX_DATA_MAX_STIF_REPORT_QSIZE_IDLE_REPORT_SIZE (1)

#undef DNX_DATA_MAX_STIF_REPORT_QSIZE_IDLE_REPORT_SIZE
#define DNX_DATA_MAX_STIF_REPORT_QSIZE_IDLE_REPORT_SIZE (8)


#define DNX_DATA_MAX_STIF_REPORT_QSIZE_IDLE_REPORT_PERIOD (1)

#undef DNX_DATA_MAX_STIF_REPORT_QSIZE_IDLE_REPORT_PERIOD
#define DNX_DATA_MAX_STIF_REPORT_QSIZE_IDLE_REPORT_PERIOD (256)


#define DNX_DATA_MAX_STIF_REPORT_QSIZE_IDLE_REPORT_PERIOD_INVALID (1)

#undef DNX_DATA_MAX_STIF_REPORT_QSIZE_IDLE_REPORT_PERIOD_INVALID
#define DNX_DATA_MAX_STIF_REPORT_QSIZE_IDLE_REPORT_PERIOD_INVALID (127)


#define DNX_DATA_MAX_STIF_REPORT_QSIZE_SCRUBBER_REPORT_CYCLES_UNIT (1)

#undef DNX_DATA_MAX_STIF_REPORT_QSIZE_SCRUBBER_REPORT_CYCLES_UNIT
#define DNX_DATA_MAX_STIF_REPORT_QSIZE_SCRUBBER_REPORT_CYCLES_UNIT (16)


#define DNX_DATA_MAX_STIF_REPORT_MAX_THRESHOLDS_PER_BUFFER (1)

#undef DNX_DATA_MAX_STIF_REPORT_MAX_THRESHOLDS_PER_BUFFER
#define DNX_DATA_MAX_STIF_REPORT_MAX_THRESHOLDS_PER_BUFFER (15)


#define DNX_DATA_MAX_STIF_REPORT_INCOMING_TC (1)

#undef DNX_DATA_MAX_STIF_REPORT_INCOMING_TC
#define DNX_DATA_MAX_STIF_REPORT_INCOMING_TC (2)


#define DNX_DATA_MAX_STIF_REPORT_RECORD_TWO_MSB (1)

#undef DNX_DATA_MAX_STIF_REPORT_RECORD_TWO_MSB
#define DNX_DATA_MAX_STIF_REPORT_RECORD_TWO_MSB (3)


#define DNX_DATA_MAX_STIF_REPORT_NOF_SOURCE_TYPES (1)

#undef DNX_DATA_MAX_STIF_REPORT_NOF_SOURCE_TYPES
#define DNX_DATA_MAX_STIF_REPORT_NOF_SOURCE_TYPES (4)


#define DNX_DATA_MAX_STIF_REPORT_STAT_ID_MAX_COUNT (1)

#undef DNX_DATA_MAX_STIF_REPORT_STAT_ID_MAX_COUNT
#define DNX_DATA_MAX_STIF_REPORT_STAT_ID_MAX_COUNT (4)


#define DNX_DATA_MAX_STIF_REPORT_STAT_OBJECT_SIZE (1)

#undef DNX_DATA_MAX_STIF_REPORT_STAT_OBJECT_SIZE
#define DNX_DATA_MAX_STIF_REPORT_STAT_OBJECT_SIZE (20)


#define DNX_DATA_MAX_STIF_REPORT_BILLING_FORMAT_ELEMENT_PACKET_SIZE (1)

#undef DNX_DATA_MAX_STIF_REPORT_BILLING_FORMAT_ELEMENT_PACKET_SIZE
#define DNX_DATA_MAX_STIF_REPORT_BILLING_FORMAT_ELEMENT_PACKET_SIZE (14)


#define DNX_DATA_MAX_STIF_REPORT_BILLING_FORMAT_MSB_OPCODE_SIZE (1)

#undef DNX_DATA_MAX_STIF_REPORT_BILLING_FORMAT_MSB_OPCODE_SIZE
#define DNX_DATA_MAX_STIF_REPORT_BILLING_FORMAT_MSB_OPCODE_SIZE (2)


#define DNX_DATA_MAX_STIF_REPORT_BILLING_FORMAT_ETPP_METADATA_SIZE (1)

#undef DNX_DATA_MAX_STIF_REPORT_BILLING_FORMAT_ETPP_METADATA_SIZE
#define DNX_DATA_MAX_STIF_REPORT_BILLING_FORMAT_ETPP_METADATA_SIZE (24)


#define DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_ONE_TYPE_MASK (1)

#undef DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_ONE_TYPE_MASK
#define DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_ONE_TYPE_MASK (3)


#define DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_TWO_TYPES_MASK (1)

#undef DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_TWO_TYPES_MASK
#define DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_TWO_TYPES_MASK (15)


#define DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_THREE_TYPES_MASK (1)

#undef DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_THREE_TYPES_MASK
#define DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_THREE_TYPES_MASK (63)


#define DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_FOUR_TYPES_MASK (1)

#undef DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_FOUR_TYPES_MASK
#define DNX_DATA_MAX_STIF_REPORT_BILLING_OPSIZE_USE_FOUR_TYPES_MASK (255)


#define DNX_DATA_MAX_STIF_REPORT_BILLING_ENQ_ING_SIZE_SHIFT (1)

#undef DNX_DATA_MAX_STIF_REPORT_BILLING_ENQ_ING_SIZE_SHIFT
#define DNX_DATA_MAX_STIF_REPORT_BILLING_ENQ_ING_SIZE_SHIFT (16)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_ETPP_PIPE_LENGTH (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_ETPP_PIPE_LENGTH
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_ETPP_PIPE_LENGTH (770)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_ETPP_DEQ_SIZE_OF_FIFO (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_ETPP_DEQ_SIZE_OF_FIFO
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_ETPP_DEQ_SIZE_OF_FIFO (1024)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_CGM_PIPE_LENGTH (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_CGM_PIPE_LENGTH
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_CGM_PIPE_LENGTH (64)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_CGM_SIZE_OF_FIFO (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_CGM_SIZE_OF_FIFO
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_CGM_SIZE_OF_FIFO (208)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_LEVEL_SAMPLING (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_LEVEL_SAMPLING
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_LEVEL_SAMPLING (60)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_FC_DISABLE_VALUE (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_FC_DISABLE_VALUE
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_FC_DISABLE_VALUE (0)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_ETPP_FLOW_CONTROL_HIGH (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_ETPP_FLOW_CONTROL_HIGH
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_ETPP_FLOW_CONTROL_HIGH (91)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_ETPP_FLOW_CONTROL_LOW (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_ETPP_FLOW_CONTROL_LOW
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_ETPP_FLOW_CONTROL_LOW (90)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_CGM_FLOW_CONTROL_HIGH (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_CGM_FLOW_CONTROL_HIGH
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_CGM_FLOW_CONTROL_HIGH (63)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_CGM_FLOW_CONTROL_LOW (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_CGM_FLOW_CONTROL_LOW
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_BILLING_CGM_FLOW_CONTROL_LOW (62)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_QSIZE_CGM_FLOW_CONTROL_HIGH (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_QSIZE_CGM_FLOW_CONTROL_HIGH
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_QSIZE_CGM_FLOW_CONTROL_HIGH (123)


#define DNX_DATA_MAX_STIF_FLOW_CONTROL_QSIZE_CGM_FLOW_CONTROL_LOW (1)

#undef DNX_DATA_MAX_STIF_FLOW_CONTROL_QSIZE_CGM_FLOW_CONTROL_LOW
#define DNX_DATA_MAX_STIF_FLOW_CONTROL_QSIZE_CGM_FLOW_CONTROL_LOW (122)





#endif 
