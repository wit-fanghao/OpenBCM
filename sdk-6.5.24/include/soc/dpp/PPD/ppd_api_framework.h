/* 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2021 Broadcom Inc. All rights reserved.
*/


#ifndef __SOC_PPD_API_FRAMEWORK_INCLUDED__

#define __SOC_PPD_API_FRAMEWORK_INCLUDED__




#include <soc/dpp/SAND/Utils/sand_header.h>

#include <soc/dpp/SAND/Management/sand_general_macros.h>
#include <soc/dpp/SAND/Management/sand_error_code.h>





#define SOC_PPD_PROC_DESC_BASE_GENERAL_FIRST                  (SOC_PPD_PROC_BITS)
#define SOC_PPD_PROC_DESC_BASE_GENERAL_LAST                   (SOC_PPD_PROC_DESC_BASE_GENERAL_FIRST + 11)
#define SOC_PPD_PROC_DESC_BASE_LLP_PARSE_FIRST                (SOC_PPD_PROC_DESC_BASE_GENERAL_LAST)
#define SOC_PPD_PROC_DESC_BASE_LLP_PARSE_LAST                 (SOC_PPD_PROC_DESC_BASE_LLP_PARSE_FIRST + 23)
#define SOC_PPD_PROC_DESC_BASE_LLP_SA_AUTH_FIRST              (SOC_PPD_PROC_DESC_BASE_LLP_PARSE_LAST)
#define SOC_PPD_PROC_DESC_BASE_LLP_SA_AUTH_LAST               (SOC_PPD_PROC_DESC_BASE_LLP_SA_AUTH_FIRST + 19)
#define SOC_PPD_PROC_DESC_BASE_LLP_VID_ASSIGN_FIRST           (SOC_PPD_PROC_DESC_BASE_LLP_SA_AUTH_LAST)
#define SOC_PPD_PROC_DESC_BASE_LLP_VID_ASSIGN_LAST            (SOC_PPD_PROC_DESC_BASE_LLP_VID_ASSIGN_FIRST + 27)
#define SOC_PPD_PROC_DESC_BASE_LLP_FILTER_FIRST               (SOC_PPD_PROC_DESC_BASE_LLP_VID_ASSIGN_LAST)
#define SOC_PPD_PROC_DESC_BASE_LLP_FILTER_LAST                (SOC_PPD_PROC_DESC_BASE_LLP_FILTER_FIRST + 27)
#define SOC_PPD_PROC_DESC_BASE_LLP_COS_FIRST                  (SOC_PPD_PROC_DESC_BASE_LLP_FILTER_LAST)
#define SOC_PPD_PROC_DESC_BASE_LLP_COS_LAST                   (SOC_PPD_PROC_DESC_BASE_LLP_COS_FIRST + 39)
#define SOC_PPD_PROC_DESC_BASE_LLP_TRAP_FIRST                 (SOC_PPD_PROC_DESC_BASE_LLP_COS_LAST)
#define SOC_PPD_PROC_DESC_BASE_LLP_TRAP_LAST                  (SOC_PPD_PROC_DESC_BASE_LLP_TRAP_FIRST + 27)
#define SOC_PPD_PROC_DESC_BASE_LLP_MIRROR_FIRST               (SOC_PPD_PROC_DESC_BASE_LLP_TRAP_LAST)
#define SOC_PPD_PROC_DESC_BASE_LLP_MIRROR_LAST                (SOC_PPD_PROC_DESC_BASE_LLP_MIRROR_FIRST + 21)
#define SOC_PPD_PROC_DESC_BASE_MYMAC_FIRST                    (SOC_PPD_PROC_DESC_BASE_LLP_MIRROR_LAST)
#define SOC_PPD_PROC_DESC_BASE_MYMAC_LAST                     (SOC_PPD_PROC_DESC_BASE_MYMAC_FIRST + 39)
#define SOC_PPD_PROC_DESC_BASE_MPLS_TERM_FIRST                (SOC_PPD_PROC_DESC_BASE_MYMAC_LAST)
#define SOC_PPD_PROC_DESC_BASE_MPLS_TERM_LAST                 (SOC_PPD_PROC_DESC_BASE_MPLS_TERM_FIRST + 40)
#define SOC_PPD_PROC_DESC_BASE_VSI_FIRST                      (SOC_PPD_PROC_DESC_BASE_MPLS_TERM_LAST)
#define SOC_PPD_PROC_DESC_BASE_VSI_LAST                       (SOC_PPD_PROC_DESC_BASE_VSI_FIRST + 23)
#define SOC_PPD_PROC_DESC_BASE_LIF_FIRST                      (SOC_PPD_PROC_DESC_BASE_VSI_LAST)
#define SOC_PPD_PROC_DESC_BASE_LIF_LAST                       (SOC_PPD_PROC_DESC_BASE_LIF_FIRST + 65)
#define SOC_PPD_PROC_DESC_BASE_RIF_FIRST                      (SOC_PPD_PROC_DESC_BASE_LIF_LAST)
#define SOC_PPD_PROC_DESC_BASE_RIF_LAST                       (SOC_PPD_PROC_DESC_BASE_RIF_FIRST + 32)
#define SOC_PPD_PROC_DESC_BASE_LIF_ING_VLAN_EDIT_FIRST        (SOC_PPD_PROC_DESC_BASE_RIF_LAST)
#define SOC_PPD_PROC_DESC_BASE_LIF_ING_VLAN_EDIT_LAST         (SOC_PPD_PROC_DESC_BASE_LIF_ING_VLAN_EDIT_FIRST + 31)
#define SOC_PPD_PROC_DESC_BASE_LIF_COS_FIRST                  (SOC_PPD_PROC_DESC_BASE_LIF_ING_VLAN_EDIT_LAST)
#define SOC_PPD_PROC_DESC_BASE_LIF_COS_LAST                   (SOC_PPD_PROC_DESC_BASE_LIF_COS_FIRST + 59)
#define SOC_PPD_PROC_DESC_BASE_LIF_TABLE_FIRST                (SOC_PPD_PROC_DESC_BASE_LIF_COS_LAST)
#define SOC_PPD_PROC_DESC_BASE_LIF_TABLE_LAST                 (SOC_PPD_PROC_DESC_BASE_LIF_TABLE_FIRST + 17)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_MACT_FIRST               (SOC_PPD_PROC_DESC_BASE_LIF_TABLE_LAST)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_MACT_LAST                (SOC_PPD_PROC_DESC_BASE_FRWRD_MACT_FIRST + 25)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_MACT_MGMT_FIRST          (SOC_PPD_PROC_DESC_BASE_FRWRD_MACT_LAST)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_MACT_MGMT_LAST           (SOC_PPD_PROC_DESC_BASE_FRWRD_MACT_MGMT_FIRST + 100)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_IPV4_FIRST               (SOC_PPD_PROC_DESC_BASE_FRWRD_MACT_MGMT_LAST)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_IPV4_LAST                (SOC_PPD_PROC_DESC_BASE_FRWRD_IPV4_FIRST + 70)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_IPV6_FIRST               (SOC_PPD_PROC_DESC_BASE_FRWRD_IPV4_LAST)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_IPV6_LAST                (SOC_PPD_PROC_DESC_BASE_FRWRD_IPV6_FIRST + 51)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_ILM_FIRST                (SOC_PPD_PROC_DESC_BASE_FRWRD_IPV6_LAST)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_ILM_LAST                 (SOC_PPD_PROC_DESC_BASE_FRWRD_ILM_FIRST + 25)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_BMACT_FIRST              (SOC_PPD_PROC_DESC_BASE_FRWRD_ILM_LAST)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_BMACT_LAST               (SOC_PPD_PROC_DESC_BASE_FRWRD_BMACT_FIRST + 23)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_TRILL_FIRST              (SOC_PPD_PROC_DESC_BASE_FRWRD_BMACT_LAST)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_TRILL_LAST               (SOC_PPD_PROC_DESC_BASE_FRWRD_TRILL_FIRST + 32)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_EXTEND_P2P_FIRST         (SOC_PPD_PROC_DESC_BASE_FRWRD_TRILL_LAST)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_EXTEND_P2P_LAST          (SOC_PPD_PROC_DESC_BASE_FRWRD_EXTEND_P2P_FIRST + 40)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_FEC_FIRST                (SOC_PPD_PROC_DESC_BASE_FRWRD_EXTEND_P2P_LAST)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_FEC_LAST                 (SOC_PPD_PROC_DESC_BASE_FRWRD_FEC_FIRST + 51)
#define SOC_PPD_PROC_DESC_BASE_EG_FILTER_FIRST                (SOC_PPD_PROC_DESC_BASE_FRWRD_FEC_LAST)
#define SOC_PPD_PROC_DESC_BASE_EG_FILTER_LAST                 (SOC_PPD_PROC_DESC_BASE_EG_FILTER_FIRST + 39)
#define SOC_PPD_PROC_DESC_BASE_EG_QOS_FIRST                   (SOC_PPD_PROC_DESC_BASE_EG_FILTER_LAST)
#define SOC_PPD_PROC_DESC_BASE_EG_QOS_LAST                    (SOC_PPD_PROC_DESC_BASE_EG_QOS_FIRST + 23)
#define SOC_PPD_PROC_DESC_BASE_EG_ENCAP_FIRST                 (SOC_PPD_PROC_DESC_BASE_EG_QOS_LAST)
#define SOC_PPD_PROC_DESC_BASE_EG_ENCAP_LAST                  (SOC_PPD_PROC_DESC_BASE_EG_ENCAP_FIRST + 100)
#define SOC_PPD_PROC_DESC_BASE_EG_AC_FIRST                    (SOC_PPD_PROC_DESC_BASE_EG_ENCAP_LAST)
#define SOC_PPD_PROC_DESC_BASE_EG_AC_LAST                     (SOC_PPD_PROC_DESC_BASE_EG_AC_FIRST + 31)
#define SOC_PPD_PROC_DESC_BASE_EG_VLAN_EDIT_FIRST             (SOC_PPD_PROC_DESC_BASE_EG_AC_LAST)
#define SOC_PPD_PROC_DESC_BASE_EG_VLAN_EDIT_LAST              (SOC_PPD_PROC_DESC_BASE_EG_VLAN_EDIT_FIRST + 39)
#define SOC_PPD_PROC_DESC_BASE_EG_MIRROR_FIRST                (SOC_PPD_PROC_DESC_BASE_EG_VLAN_EDIT_LAST)
#define SOC_PPD_PROC_DESC_BASE_EG_MIRROR_LAST                 (SOC_PPD_PROC_DESC_BASE_EG_MIRROR_FIRST + 21)
#define SOC_PPD_PROC_DESC_BASE_PORT_FIRST                     (SOC_PPD_PROC_DESC_BASE_EG_MIRROR_LAST)
#define SOC_PPD_PROC_DESC_BASE_PORT_LAST                      (SOC_PPD_PROC_DESC_BASE_PORT_FIRST + 27)
#define SOC_PPD_PROC_DESC_BASE_LAG_FIRST                      (SOC_PPD_PROC_DESC_BASE_PORT_LAST)
#define SOC_PPD_PROC_DESC_BASE_LAG_LAST                       (SOC_PPD_PROC_DESC_BASE_LAG_FIRST + 31)
#define SOC_PPD_PROC_DESC_BASE_TRAP_MGMT_FIRST                (SOC_PPD_PROC_DESC_BASE_LAG_LAST)
#define SOC_PPD_PROC_DESC_BASE_TRAP_MGMT_LAST                 (SOC_PPD_PROC_DESC_BASE_TRAP_MGMT_FIRST + 33)
#define SOC_PPD_PROC_DESC_BASE_METERING_FIRST                 (SOC_PPD_PROC_DESC_BASE_TRAP_MGMT_LAST)
#define SOC_PPD_PROC_DESC_BASE_METERING_LAST                  (SOC_PPD_PROC_DESC_BASE_METERING_FIRST + 45)
#define SOC_PPD_PROC_DESC_BASE_COUNTING_FIRST                 (SOC_PPD_PROC_DESC_BASE_METERING_LAST)
#define SOC_PPD_PROC_DESC_BASE_COUNTING_LAST                  (SOC_PPD_PROC_DESC_BASE_COUNTING_FIRST + 25)
#define SOC_PPD_PROC_DESC_BASE_FP_FIRST                       (SOC_PPD_PROC_DESC_BASE_COUNTING_LAST)
#define SOC_PPD_PROC_DESC_BASE_FP_LAST                        (SOC_PPD_PROC_DESC_BASE_FP_FIRST + 40)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_FCF_FIRST                       (SOC_PPD_PROC_DESC_BASE_FP_LAST)
#define SOC_PPD_PROC_DESC_BASE_FRWRD_FCF_LAST                        (SOC_PPD_PROC_DESC_BASE_FRWRD_FCF_LAST + 40)
#define SOC_PPD_PROC_DESC_BASE_DIAG_FIRST                     (SOC_PPD_PROC_DESC_BASE_FP_LAST)
#define SOC_PPD_PROC_DESC_BASE_DIAG_LAST                      (SOC_PPD_PROC_DESC_BASE_DIAG_FIRST + 80)
#define SOC_PPD_PROC_DESC_BASE_SW_DB_FIRST                    (SOC_PPD_PROC_DESC_BASE_DIAG_LAST)
#define SOC_PPD_PROC_DESC_BASE_SW_DB_LAST                     (SOC_PPD_PROC_DESC_BASE_SW_DB_FIRST + 11)
#define SOC_PPD_PROC_DESC_BASE_TBL_ACCESS_FIRST               (SOC_PPD_PROC_DESC_BASE_SW_DB_LAST)
#define SOC_PPD_PROC_DESC_BASE_TBL_ACCESS_LAST                (SOC_PPD_PROC_DESC_BASE_TBL_ACCESS_FIRST + 11)
#define SOC_PPD_PROC_DESC_BASE_LEM_ACCESS_FIRST               (SOC_PPD_PROC_DESC_BASE_TBL_ACCESS_LAST)
#define SOC_PPD_PROC_DESC_BASE_LEM_ACCESS_LAST                (SOC_PPD_PROC_DESC_BASE_LEM_ACCESS_FIRST + 11)
#define SOC_PPD_PROC_DESC_BASE_FRAMEWORK_FIRST                (SOC_PPD_PROC_DESC_BASE_LEM_ACCESS_LAST)
#define SOC_PPD_PROC_DESC_BASE_FRAMEWORK_LAST                 (SOC_PPD_PROC_DESC_BASE_FRAMEWORK_FIRST + 12)
#define SOC_PPD_PROC_DESC_BASE_OAM_FIRST                      (SOC_PPD_PROC_DESC_BASE_FRAMEWORK_LAST)
#define SOC_PPD_PROC_DESC_BASE_OAM_LAST                       (SOC_PPD_PROC_DESC_BASE_OAM_FIRST + 100)
#define SOC_PPD_PROC_DESC_BASE_SRC_BIND_FIRST                 (SOC_PPD_PROC_DESC_BASE_OAM_LAST)
#define SOC_PPD_PROC_DESC_BASE_SRC_BIND_LAST                  (SOC_PPD_PROC_DESC_BASE_SRC_BIND_FIRST + 30)
#define SOC_PPD_PROC_DESC_BASE_PTP_FIRST                      (SOC_PPD_PROC_DESC_BASE_SRC_BIND_LAST)
#define SOC_PPD_PROC_DESC_BASE_PTP_LAST                       (SOC_PPD_PROC_DESC_BASE_PTP_FIRST + 30)









typedef enum
{
  
  SOC_PPD_PROCEDURE_DESC_ADD = SOC_PPD_PROC_DESC_BASE_FRAMEWORK_FIRST,
  SOC_PPD_FRAMEWORK_GET_PROCS_PTR,
  



  
  SOC_PPD_FRAMEWORK_PROCEDURE_DESC_LAST
} SOC_PPD_FRAMEWORK_PROCEDURE_DESC;

typedef enum SOC_PPD_ERR_LIST
{
  SOC_PPD_NO_ERR                     = SOC_SAND_OK,
  SOC_PPD_GEN_ERR                    = SOC_SAND_ERR,

  SOC_PPD_INVALID_DEVICE_TYPE_ERR,
  SOC_PPD_FUNC_UNSUPPORTED_ERR,
  SOC_PPD_ERR_OUT_OF_RESOURCES,
  SOC_PPD_ERR_NOT_EXIST,
  SOC_PPD_ERR_OUT_OF_RANGE_ERR,

  SOC_PPD_LAST_ERR
} SOC_PPD_ERR;










CONST SOC_PROCEDURE_DESC_ELEMENT*
  soc_ppd_framework_get_procs_ptr(void);


#include <soc/dpp/SAND/Utils/sand_footer.h>


#endif