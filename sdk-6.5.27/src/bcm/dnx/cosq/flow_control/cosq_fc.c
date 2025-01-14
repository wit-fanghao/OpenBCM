/** \file src/bcm/dnx/cosq/flow_control/cosq_fc.c
 * 
 *
 * Flow control API functions for DNX. \n
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 */

/*
 * $Copyright:.$
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_COSQ

#include <soc/sand/shrextend/shrextend_debug.h>
#include <soc/dnx/dbal/dbal.h>
#include <soc/dnx/dnx_err_recovery_manager.h>
#include <bcm/cosq.h>
#include <bcm/types.h>
#include <bcm_int/dnx/cosq/cosq.h>
#include <bcm_int/dnx/cmn/dnxcmn.h>
#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>
#include <soc/portmod/portmod.h>
#include <bcm_int/dnx/cosq/flow_control/cosq_fc.h>
#include <bcm_int/dnx/cosq/flow_control/flow_control_imp.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_fc.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_nif.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_egr_queuing.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_sch.h>
#include <bcm_int/dnx/cosq/egress/ecgm.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/access/flow_control_access.h>
#include <bcm_int/dnx/cosq/scheduler/scheduler.h>

/*
 * Functions
 * {
 */

/**
 * \brief - This is a function to indicate that the combination of user specified source and target for the FC is illegal
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - unit id
 *   \param [in] is_delete - indicates weather the function is called from the add or delete API
 *   \param [in] source - holds information for the source of the Flow control
 *   \param [in] target - holds information for the target of the Flow control
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_fc_illegal_src_tar_combination(
    int unit,
    int is_delete,
    bcm_cosq_fc_endpoint_t * source,
    bcm_cosq_fc_endpoint_t * target)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_ERR_EXIT(_SHR_E_PARAM, "Illegal combination of source and target!");
exit:
    SHR_FUNC_EXIT;

}

/* *INDENT-OFF* */
/*
 * Reception Source Reaction-Points Matrix
 */
static fc_matrix_t reception_source_reaction_points_matrix[DNX_FC_RECEPTION_SOURCES][DNX_FC_RECEPTION_REACTION_POINTS] =
{
                           /** Interface                                                         Port                                                              Port+COSQ */
/** LLFC */                {{dnx_fc_rec_llfc_interface_map, dnx_fc_rec_llfc_interface_verify},  {NULL, dnx_fc_illegal_src_tar_combination},                       {NULL, dnx_fc_illegal_src_tar_combination}},
/** PFC */                 {{dnx_fc_rec_pfc_interface_map, dnx_fc_rec_pfc_interface_verify},    {dnx_fc_rec_pfc_port_cosq_map, dnx_fc_rec_pfc_port_cosq_verify},  {dnx_fc_rec_pfc_port_cosq_map, dnx_fc_rec_pfc_port_cosq_verify}},
/** Calendar */            {{dnx_fc_rec_cal_interface_map, dnx_fc_rec_cal_interface_verify},    {dnx_fc_rec_cal_port_cosq_map, dnx_fc_rec_cal_port_cosq_verify},  {dnx_fc_rec_cal_port_cosq_map, dnx_fc_rec_cal_port_cosq_verify}}
};

/*
 * Generation Source Destination Matrix
 */
static fc_matrix_t generation_source_destination_matrix[DNX_FC_GENERATION_SOURCES][DNX_FC_GENERATION_DESTINATIONS] =
{
                        /** LLFC                                                                 PFC                                                                  Calendar */
/** GLB Res */          {{dnx_fc_gen_glb_res_llfc_map, dnx_fc_gen_glb_res_llfc_verify},         {dnx_fc_gen_glb_res_pfc_map, dnx_fc_gen_glb_res_pfc_verify},         {dnx_fc_gen_glb_res_cal_map, dnx_fc_gen_glb_res_cal_verify}},
/** LLFC VSQs */        {{dnx_fc_gen_llfc_vsq_llfc_map, dnx_fc_gen_llfc_vsq_llfc_verify},       {NULL, dnx_fc_illegal_src_tar_combination},                          {dnx_fc_gen_llfc_vsq_cal_map, dnx_fc_gen_to_cal_verify}},
/** PFC VSQs */         {{NULL, dnx_fc_illegal_src_tar_combination},                            {dnx_fc_gen_pfc_vsq_pfc_map, dnx_fc_gen_pfc_vsq_pfc_verify},         {dnx_fc_gen_pfc_vsq_cal_map, dnx_fc_gen_pfc_vsq_cal_verify}},
/** CAT2 TC VSQs */     {{NULL, dnx_fc_illegal_src_tar_combination},                            {dnx_fc_gen_c2_tc_vsq_pfc_map, dnx_fc_gen_c2_tc_vsq_pfc_verify},     {dnx_fc_gen_vsq_a_d_cal_map, dnx_fc_gen_to_cal_verify}},
/** VSQ groups A-D */   {{dnx_fc_gen_vsq_d_pfc_llfc_map, dnx_fc_gen_vsq_d_pfc_llfc_verify},     {dnx_fc_gen_vsq_d_pfc_llfc_map, dnx_fc_gen_vsq_d_pfc_llfc_verify},   {dnx_fc_gen_vsq_a_d_cal_map, dnx_fc_gen_to_cal_verify}},
/** Almost full NIF*/   {{dnx_fc_gen_nif_llfc_map, dnx_fc_gen_nif_llfc_verify},                 {dnx_fc_gen_nif_pfc_map, dnx_fc_gen_nif_pfc_verify},                 {dnx_fc_gen_nif_cal_map, dnx_fc_gen_to_cal_verify}}
};
/* *INDENT-ON* */

/**
 * \brief -
 * To return types of source and target when generation
 * \par DIRECT_INPUT:
 *   \param [in] unit - unit
 *   \param [in] source - source object
 *   \param [in] target - target object
 *   \param [out] source_type - type of source object
 *   \param [out] target_type - type of target object
 * \par DIRECT OUTPUT:
 *   see shr_error_e
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_cosq_fc_gen_src_target_get(
    int unit,
    bcm_cosq_fc_endpoint_t * source,
    bcm_cosq_fc_endpoint_t * target,
    dnx_fc_gen_src_t * source_type,
    dnx_fc_gen_dest_t * target_type)
{
    dnx_algo_port_info_s port_info;
    bcm_port_t port;
    SHR_FUNC_INIT_VARS(unit);

    /** Determine the generation source */
    if (BCM_COSQ_GPORT_IS_VSQ(source->port))
    {
        if (BCM_COSQ_GPORT_IS_VSQ_SRC_PORT(source->port))
        {
            /** Source is Source Port VSQ (E) */
            *source_type = DNX_FC_GEN_SRC_LLFC_VSQ;
        }
        else if (BCM_COSQ_GPORT_IS_VSQ_PG(source->port))
        {
            /** Source is Source Port + TC VSQ (F) */
            *source_type = DNX_FC_GEN_SRC_PFC_VSQ;
        }
        else if (BCM_COSQ_GPORT_IS_VSQ_CTTC(source->port) && (BCM_COSQ_GPORT_VSQ_CT_GET(source->port) == 2))
        {
            /** Source is VSQ B (Category + Traffic Class)  when Category is 2 (unicast queues) */
            *source_type = DNX_FC_GEN_SRC_CAT2_TC_VSQ;
        }
        else if (BCM_COSQ_GPORT_IS_VSQ_GL(source->port))
        {
            /** Source is Global VSQ (Global resources thresholds) */
            *source_type = DNX_FC_GEN_SRC_GLB_RES;
        }
        else
        {
            /** Source is CT VSQs (A), CTTC VSQs (B), CTCC VSQs (C) and ST VSQs (D) */
            *source_type = DNX_FC_GEN_SRC_VSQ_A_D;
        }
    }
    else if (BCM_GPORT_IS_LOCAL(source->port) || BCM_GPORT_IS_LOCAL_INTERFACE(source->port))
    {
        port =
            BCM_GPORT_IS_LOCAL(source->
                               port) ? BCM_GPORT_LOCAL_GET(source->port) : BCM_GPORT_LOCAL_INTERFACE_GET(source->port);
        SHR_IF_ERR_EXIT(dnx_algo_port_info_get(unit, port, &port_info));
        if (DNX_ALGO_PORT_TYPE_IS_NIF(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(L1, MGMT)))
        {
            /** Source is Almost Full NIF (MLF FIFO thresholds) */
            *source_type = DNX_FC_GEN_SRC_ALMOST_FULL_NIF;
        }
        else
        {
            SHR_ERR_EXIT(_SHR_E_PORT, "Unsupported source port (0x%x), must be NIF", source->port);
        }
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "Unsupported Gport type (0x%x)", source->port);
    }

    if (target_type != NULL)
    {
        /** Determine the generation target */
        if (BCM_GPORT_IS_CONGESTION(target->port) && !BCM_GPORT_IS_CONGESTION_COE(target->port))
        {
            /** Target is OOB calendar (COE calendar not supported for generation) */
            *target_type = DNX_FC_GEN_DEST_CAL;
        }
        else if (BCM_GPORT_IS_LOCAL(target->port) || BCM_GPORT_IS_LOCAL_INTERFACE(target->port)
                 || (target->flags & BCM_COSQ_FC_ENDPOINT_PORT_IMPLICIT))
        {
            if (!(target->flags & BCM_COSQ_FC_ENDPOINT_PORT_IMPLICIT))
            {
                /** No Implicit flag - Determine target based on target input structure */
                port =
                    BCM_GPORT_IS_LOCAL(target->port) ? BCM_GPORT_LOCAL_GET(target->port) :
                    BCM_GPORT_LOCAL_INTERFACE_GET(target->port);
                SHR_IF_ERR_EXIT(dnx_algo_port_info_get(unit, port, &port_info));
                if (DNX_ALGO_PORT_TYPE_IS_NIF_ILKN(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(L1, MGMT)))
                {
                    /** NIF IKLN, excluding ELK - Target is ILKN Inband calendar */
                    *target_type = DNX_FC_GEN_DEST_CAL;
                }
                else if (DNX_ALGO_PORT_TYPE_IS_NIF_ETH(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(L1, MGMT)))
                {
                    /** NIF ETH, excluding STIF */
                    if (target->cosq == BCM_COS_INVALID)
                    {
                        /** COSQ invalid - Target is LLFC */
                        *target_type = DNX_FC_GEN_DEST_LLFC;
                    }
                    else if ((target->cosq >= BCM_COS_MIN) || (target->cosq <= BCM_COS_MAX))
                    {
                        /** COSQ valid - Target is PFC */
                        *target_type = DNX_FC_GEN_DEST_PFC;
                    }
                    else
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported COSQ %d", target->cosq);
                    }
                }
                else
                {
                    SHR_ERR_EXIT(_SHR_E_PORT, "Unsupported target port (0x%x), must be NIF", source->port);
                }
            }
            else
            {
                /** Implicit flag - Determine target based on source input structure */
                if (source->cosq == BCM_COS_INVALID)
                {
                    /** COSQ invalid - Target is LLFC */
                    *target_type = DNX_FC_GEN_DEST_LLFC;
                }
                else if ((source->cosq >= BCM_COS_MIN) || (source->cosq <= BCM_COS_MAX))
                {
                    /** COSQ valid - Target is PFC */
                    *target_type = DNX_FC_GEN_DEST_PFC;
                }
                else
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported COSQ %d", target->cosq);
                }
            }
        }
        else
        {
            SHR_ERR_EXIT(_SHR_E_PORT, "Unsupported Gport (0x%x)", target->port);
        }
    }
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief -
 * To return types of source and target when reception
 * \par DIRECT_INPUT:
 *   \param [in] unit - unit
 *   \param [in] source - source object
 *   \param [in] target - target object
 *   \param [out] source_type - type of source object
 *   \param [out] target_type - type of target object
 * \par DIRECT OUTPUT:
 *   see shr_error_e
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_cosq_fc_rec_src_target_get(
    int unit,
    bcm_cosq_fc_endpoint_t * source,
    bcm_cosq_fc_endpoint_t * target,
    dnx_fc_rec_src_t * source_type,
    dnx_fc_rec_reaction_point_t * target_type)
{
    dnx_algo_port_info_s port_info;
    bcm_port_t port;
    bcm_cosq_fc_endpoint_t endpoint;
    SHR_FUNC_INIT_VARS(unit);

    /** Determine the reception source */
    if (BCM_GPORT_IS_CONGESTION(source->port))
    {
        /** Source is OOB or COE calendar */
        *source_type = DNX_FC_REC_SRC_CAL;
    }
    else if (BCM_GPORT_IS_LOCAL(source->port) || BCM_GPORT_IS_LOCAL_INTERFACE(source->port))
    {
        port =
            BCM_GPORT_IS_LOCAL(source->
                               port) ? BCM_GPORT_LOCAL_GET(source->port) : BCM_GPORT_LOCAL_INTERFACE_GET(source->port);
        SHR_IF_ERR_EXIT(dnx_algo_port_info_get(unit, port, &port_info));
        if (DNX_ALGO_PORT_TYPE_IS_NIF_ILKN(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(L1)))
        {
            /** Source is ILKN inband calendar */
            *source_type = DNX_FC_REC_SRC_CAL;
        }
        else if (DNX_ALGO_PORT_TYPE_IS_NIF(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(L1, MGMT)) ||
                 DNX_ALGO_PORT_TYPE_IS_CPU(unit, port_info))
        {
            if (source->cosq == BCM_COS_INVALID)
            {
                /** Source is LLFC (from NIF or CPU port) */
                *source_type = DNX_FC_REC_SRC_LLFC;
            }
            else if ((source->cosq >= BCM_COS_MIN) && (source->cosq <= BCM_COS_MAX))
            {
                /** Source is PFC (from NIF or CPU port) */
                *source_type = DNX_FC_REC_SRC_PFC;
            }
            else
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported COSQ %d", source->cosq);
            }
        }
        else
        {
            SHR_ERR_EXIT(_SHR_E_PORT, "Unsupported source port (0x%x), must be NIF or CPU", source->port);
        }
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "Unsupported source Gport type (0x%x)", source->port);
    }

    /** Determine the reception target */
    if (target_type != NULL)
    {
        if (!(target->flags & BCM_COSQ_FC_ENDPOINT_PORT_IMPLICIT))
        {
            /** No Implicit flag - Determine target based on target input structure */
            sal_memcpy(&endpoint, target, sizeof(endpoint));
        }
        else
        {
            /** Implicit flag - Determine target based on source input structure */
            sal_memcpy(&endpoint, source, sizeof(endpoint));
        }
        /** Make sure the target Gport is Local or Interface */
        if (BCM_GPORT_IS_LOCAL(endpoint.port) || BCM_GPORT_IS_LOCAL_INTERFACE(endpoint.port))
        {
            port =
                BCM_GPORT_IS_LOCAL(endpoint.port) ? BCM_GPORT_LOCAL_GET(endpoint.port) :
                BCM_GPORT_LOCAL_INTERFACE_GET(endpoint.port);
            SHR_IF_ERR_EXIT(dnx_algo_port_info_get(unit, port, &port_info));
            /** Make sure the target port is NIF or CPU */
            if (DNX_ALGO_PORT_TYPE_IS_NIF(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(L1, MGMT)) ||
                DNX_ALGO_PORT_TYPE_IS_CPU(unit, port_info))
            {
                if (BCM_GPORT_IS_LOCAL_INTERFACE(endpoint.port))
                {
                    if (endpoint.cosq == BCM_COS_INVALID)
                    {
                        /** Target is Interface */
                        *target_type = DNX_FC_REC_REACTION_POINT_INTERFACE;
                    }
                    else
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported target COSQ %d", endpoint.cosq);
                    }
                }
                else
                {
                    if (endpoint.cosq == BCM_COS_INVALID)
                    {
                        /** Target is Port */
                        *target_type = DNX_FC_REC_REACTION_POINT_PORT;
                    }
                    else if ((endpoint.cosq >= BCM_COS_MIN) || (endpoint.cosq <= BCM_COS_MAX))
                    {
                        /** Target is Port + COSQ */
                        *target_type = DNX_FC_REC_REACTION_POINT_PORT_COSQ;
                    }
                    else
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported target COSQ %d", endpoint.cosq);
                    }
                }
            }
            else
            {
                SHR_ERR_EXIT(_SHR_E_PORT, "Unsupported target port (0x%x), must be NIF or CPU", endpoint.port);
            }
        }
        else
        {
            SHR_ERR_EXIT(_SHR_E_PORT, "Unsupported target Gport type (0x%x)", endpoint.port);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief -
 * To associate ingress objects to a reaction FC in the generation path, or associating the received FC with a reaction egress object in the reception path.
 *
 * Use cases:
 *  ** Use case: "Generation from GLB RES to LLFC"
 *  Set the path for generation from Global recources to LLFC.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ Global Gport
 *        source->flags - BCM_COSQ_FC_BDB, BCM_COSQ_FC_HEADROOM or BCM_COSQ_FC_IS_OCB_ONLY
 *        source->cosq - 0 for Pool 0, 1 for Pool 1 and -1 for Total
 *        source->calendar - not relevant
 *        source->priority - 0 (HDRAM does not have low and high priority)
 *  - target
 *        target->port - Interface Gport or Local Gport
 *        target->flags - 0
 *        target->cosq - -1, not relevant
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 * Use cases:
 *  ** Use case: "Generation from GLB RES to PFC"
 *  Set the path for generation from Global recources to PFC.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ Global Gport
 *        source->flags - BCM_COSQ_FC_BDB, BCM_COSQ_FC_HEADROOM or BCM_COSQ_FC_IS_OCB_ONLY
 *        source->cosq - 0 for Pool 0, 1 for Pool 1 and -1 for Total
 *        source->calendar - not relevant
 *        source->priority - 0 for high, 1 for low priority
 *  - target
 *        target->port - Interface Gport or Local Gport
 *        target->flags - 0
 *        target->cosq - [0,7]
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 * Use cases:
 *  ** Use case: "Generation from GLB RES to OOB calendar"
 *  Set the path for generation from Global recources to OOB calendar.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ Global Gport
 *        source->flags - BCM_COSQ_FC_BDB, BCM_COSQ_FC_HEADROOM or BCM_COSQ_FC_IS_OCB_ONLY
 *        source->cosq - 0 for Pool 0, 1 for Pool 1 and -1 for Total
 *        source->calendar - not relevant
 *        source->priority - 0 for high, 1 for low priority
 *  - target
 *        target->port - Congestion Gport
 *        target->flags - 0
 *        target->cosq - -1, not relevant
 *        target->calendar - calender entry index
 *        target->priority - not relevant
 *
 *  ** Use case: "Generation from LLFC VSQ to LLFC"
 *  Set the path for generation from LLFC VSQ to LLFC.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ LLFC Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Interface Gport or Local Gport
 *        target->flags - 0 or BCM_COSQ_FC_ENDPOINT_PORT_IMPLICIT
 *        target->cosq - -1, not relevant
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 *  ** Use case: "Generation from LLFC VSQ to OOB calendar"
 *  Set the path for generation from LLFC VSQ to OOB calendar.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ LLFC Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Congestion Gport
 *        target->flags - 0
 *        target->cosq - -1, not relevant
 *        target->calendar - calender entry index
 *        target->priority - not relevant
 *
 *  ** Use case: "Generation from PFC VSQ to OOB calendar"
 *  Set the path for generation from PFC VSQ to OOB calendar.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ PFC Gport
 *        source->flags - 0
 *        source->cosq - [0,7]
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Congestion Gport
 *        target->flags - 0
 *        target->cosq - -1, not relevant
 *        target->calendar - calender entry index
 *        target->priority - not relevant
 *
 *  ** Use case: "Generation from Cat2 + TC VSQ to PFC"
 *  Set the path for generation from Cat2 + TC VSQ to PFC.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ Cat2 + TC Gport
 *        source->flags - 0 or BCM_COSQ_FC_ENDPOINT_PORT_IMPLICIT
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Interface Gport or Local Gport
 *        target->flags - 0
 *        target->cosq - [0,7]
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 *  ** Use case: "Generation from Cat2 + TC VSQ to OOB calendar"
 *  Set the path for generation from Cat2 + TC VSQ to OOB calendar.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ Cat2 + TC Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Congestion Gport
 *        target->flags - 0
 *        target->cosq - -1, not relevant
 *        target->calendar - calender entry index
 *        target->priority - not relevant
 *
 *  ** Use case: "Generation from VSQ Group A-D to OOB calendar"
 *  Set the path for generation from VSQ Group A-D to OOB calendar.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Congestion Gport
 *        target->flags - 0
 *        target->cosq - -1, not relevant
 *        target->calendar - calender entry index
 *        target->priority - not relevant
 *
 *  ** Use case: "Generation from Almost Full NIF to PFC"
 *  Set the path for generation from Almost Full NIF to PFC.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - Interface Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Interface Gport or Local Gport
 *        target->flags - 0 or BCM_COSQ_FC_ENDPOINT_PORT_IMPLICIT
 *        target->cosq - -1, not relevant
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 *  ** Use case: "Generation from Almost Full NIF to LLFC"
 *  Set the path for generation from Almost Full NIF to LLFC.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - Interface Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Interface Gport or Local Gport
 *        target->flags - 0 or BCM_COSQ_FC_ENDPOINT_PORT_IMPLICIT
 *        target->cosq - [0,7]
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 *  ** Use case: "Generation from Almost Full NIF to OOB calendar"
 *  Set the path for generation from Almost Full NIF to OOB calendar.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - Interface Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Congestion Gport
 *        target->flags - 0
 *        target->cosq - -1, not relevant
 *        target->calendar - calender entry index
 *        target->priority - not relevant
 *
 *  ** Use case: "Reception from LLFC to Interface reaction point"
 *  Set the path for reception from LLFC to Interface reaction point.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlReception
 *  - source
 *        source->port - Interface Gport or Local Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - -1, not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Interface Gport
 *        target->flags - 0 or BCM_COSQ_FC_ENDPOINT_PORT_IMPLICIT
 *        target->cosq - -1, not relevant
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 *  ** Use case: "Reception from PFC to port reaction point"
 *  Set the path for reception from PFC to port reaction point.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlReception
 *  - source
 *        source->port - Local Gport
 *        source->flags - 0
 *        source->cosq - [0,7]
 *        source->calendar - -1, not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Local Gport
 *        target->flags - 0 or BCM_COSQ_FC_PORT_OVER_PFC
 *        target->cosq - -1, not relevant
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 *  ** Use case: "Reception from PFC to port+COSQ reaction point"
 *  Set the path for reception from PFC to port+COSQ reaction point.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlReception
 *  - source
 *        source->port - Local Gport
 *        source->flags - 0
 *        source->cosq - [0,7]
 *        source->calendar - -1, not relevant
 *        source->priority - not relevant
 *  - target
 *        target->port - Local Gport
 *        target->flags - 0 or BCM_COSQ_FC_INHERIT_UP, BCM_COSQ_FC_INHERIT_DOWN,
                  BCM_COSQ_FC_PORT_OVER_PFC, BCM_COSQ_FC_ENDPOINT_PORT_IMPLICIT
 *        target->cosq - [0,7]
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 *  ** Use case: "Reception from OOB calendar to Interface reaction point"
 *  Set the path for reception from OOB calendar to Interface reaction point.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlReception
 *  - source
 *        source->port - Congestion Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - calender entry index
 *        source->priority - not relevant
 *  - target
 *        target->port - Interface Gport
 *        target->flags - 0
 *        target->cosq - -1, not relevant
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 *  ** Use case: "Reception from OOB calendar to Port reaction point"
 *  Set the path for reception from OOB calendar to Port reaction point.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlReception
 *  - source
 *        source->port - Congestion Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - calender entry index
 *        source->priority - not relevant
 *  - target
 *        target->port - Local Gport
 *        target->flags - 0
 *        target->cosq - -1, not relevant
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 *  ** Use case: "Reception from OOB calendar to Port+COSQ reaction point"
 *  Set the path for reception from OOB calendar to Port+COSQ reaction point.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlReception
 *  - source
 *        source->port - Congestion Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - calender entry index
 *        source->priority - not relevant
 *  - target
 *        target->port - Local Gport
 *        target->flags - 0
 *        target->cosq - [0,7]
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 *  ** Use case: "Mapping q-pair to HR flow control"
 *  Set mapping of EGQ q-pair to SCH HR
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlInternal
 *  - source
 *        source->port - local port TC gport
 *        source->flags - 0
 *        source->cosq - TC - offset of qpair from base q-pair
 *        source->calendar - 0, not relevant
 *        source->priority - 0, not relevant
 *  - target
 *        target->port - E2E port TC gport
 *        target->flags - 0
 *        target->cosq - offset of HR from base HR
 *        target->calendar - not relevant
 *        target->priority - not relevant
 *
 *   \param [in] unit - unit
 *   \param [in] fc_direction - indicates if the path is reception or generation
 *   \param [in] source - source object
 *   \param [in] target - target object
 *   see shr_error_e
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_cosq_fc_path_add(
    int unit,
    bcm_cosq_fc_direction_type_t fc_direction,
    bcm_cosq_fc_endpoint_t * source,
    bcm_cosq_fc_endpoint_t * target)
{
    dnx_fc_gen_src_t source_type_gen = DNX_FC_GENERATION_SOURCES;
    dnx_fc_gen_dest_t target_type_gen = DNX_FC_GENERATION_DESTINATIONS;
    dnx_fc_rec_src_t source_type_rec = DNX_FC_RECEPTION_SOURCES;
    dnx_fc_rec_reaction_point_t target_type_rec = DNX_FC_RECEPTION_REACTION_POINTS;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_NULL_CHECK(target, _SHR_E_PARAM, "target");
    SHR_NULL_CHECK(source, _SHR_E_PARAM, "source");

    if (fc_direction == bcmCosqFlowControlGeneration)
    {
        /** Verify input gport and get source and target type */
        SHR_IF_ERR_EXIT(dnx_cosq_fc_gen_src_target_get(unit, source, target, &source_type_gen, &target_type_gen));

        /*
         * Call the appropriate function to verify the case specific parameters
         */
        SHR_INVOKE_VERIFY_DNXC(generation_source_destination_matrix[source_type_gen][target_type_gen].verify
                               (unit, FALSE, source, target));

        /*
         * Call the appropriate function to write to HW
         */
        SHR_IF_ERR_EXIT(generation_source_destination_matrix[source_type_gen][target_type_gen].map
                        (unit, FALSE, source, target));
    }
    else if (fc_direction == bcmCosqFlowControlReception)
    {
        /** Verify input gport and get source and target type */
        SHR_IF_ERR_EXIT(dnx_cosq_fc_rec_src_target_get(unit, source, target, &source_type_rec, &target_type_rec));

        /*
         * Call the appropriate function to verify the case specific parameters
         */
        SHR_INVOKE_VERIFY_DNXC(reception_source_reaction_points_matrix[source_type_rec][target_type_rec].verify
                               (unit, FALSE, source, target));

        /*
         * Call the appropriate function to write to HW
         */
        SHR_IF_ERR_EXIT(reception_source_reaction_points_matrix[source_type_rec][target_type_rec].map
                        (unit, FALSE, source, target));
    }
    else if (fc_direction == bcmCosqFlowControlInternal)
    {
        {
            SHR_IF_ERR_EXIT(dnx_scheduler_internal_fc_map_set(unit, source, target, TRUE));
        }
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Unit %d, invalid flow control direction %d", unit, fc_direction);
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief -
 * To delete reception and generation paths.
 *
 *   \param [in] unit - unit
 *   \param [in] fc_direction - indicates if the path is reception or generation
 *   \param [in] source - source object
 *   \param [in] target - target object
 *   see shr_error_e
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_cosq_fc_path_delete(
    int unit,
    bcm_cosq_fc_direction_type_t fc_direction,
    bcm_cosq_fc_endpoint_t * source,
    bcm_cosq_fc_endpoint_t * target)
{
    dnx_fc_gen_src_t source_type_gen = DNX_FC_GENERATION_SOURCES;
    dnx_fc_gen_dest_t target_type_gen = DNX_FC_GENERATION_DESTINATIONS;
    dnx_fc_rec_src_t source_type_rec = DNX_FC_RECEPTION_SOURCES;
    dnx_fc_rec_reaction_point_t target_type_rec = DNX_FC_RECEPTION_REACTION_POINTS;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_NULL_CHECK(target, _SHR_E_PARAM, "target");
    SHR_NULL_CHECK(source, _SHR_E_PARAM, "source");

    if (fc_direction == bcmCosqFlowControlGeneration)
    {
        /** Verify input gport and get source and target type */
        SHR_IF_ERR_EXIT(dnx_cosq_fc_gen_src_target_get(unit, source, target, &source_type_gen, &target_type_gen));

        /*
         * Call the appropriate function to verify the case specific parameters
         */
        SHR_INVOKE_VERIFY_DNXC(generation_source_destination_matrix[source_type_gen][target_type_gen].verify
                               (unit, TRUE, source, target));

        /*
         * Call the appropriate function to write to HW
         */
        SHR_IF_ERR_EXIT(generation_source_destination_matrix[source_type_gen][target_type_gen].map
                        (unit, TRUE, source, target));
    }
    else if (fc_direction == bcmCosqFlowControlReception)
    {
        /** Verify input gport and get source and target type */
        SHR_IF_ERR_EXIT(dnx_cosq_fc_rec_src_target_get(unit, source, target, &source_type_rec, &target_type_rec));

        /*
         * Call the appropriate function to verify the case specific parameters
         */
        SHR_INVOKE_VERIFY_DNXC(reception_source_reaction_points_matrix[source_type_rec][target_type_rec].verify
                               (unit, TRUE, source, target));

        /*
         * Call the appropriate function to write to HW
         */
        SHR_IF_ERR_EXIT(reception_source_reaction_points_matrix[source_type_rec][target_type_rec].map
                        (unit, TRUE, source, target));
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Unit %d, unsupported flow control direction %d", unit, fc_direction);
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - This function to verify the parameters for flow control sources for generation
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - unit id
 *   \param [in] source - holds information for the source of the Flow control
 *   \param [in] source_type_gen - holds information for the type of the source object
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_cosq_fc_gen_src_verify(
    int unit,
    bcm_cosq_fc_endpoint_t * source,
    dnx_fc_gen_src_t source_type_gen)
{
    SHR_FUNC_INIT_VARS(unit);

    switch (source_type_gen)
    {
        case DNX_FC_GEN_SRC_GLB_RES:
        {
            /** Verify source flags */
            if (source->flags & ~(BCM_COSQ_FC_BDB | BCM_COSQ_FC_HEADROOM | BCM_COSQ_FC_IS_OCB_ONLY))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source flags.");
            }

            /** Verify source COSQ */
            if ((source->cosq < -1) || (source->cosq > 1))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source COSQ");
            }
            break;
        }
        case DNX_FC_GEN_SRC_PFC_VSQ:
        {
            /** Verify source flags */
            if (source->flags != 0)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source flags.");
            }

            /** Verify source COSQ */
            if ((source->cosq < 0) || (source->cosq > 7))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source COSQ");
            }
            break;
        }
        case DNX_FC_GEN_SRC_CAT2_TC_VSQ:
        case DNX_FC_GEN_SRC_VSQ_A_D:
        case DNX_FC_GEN_SRC_ALMOST_FULL_NIF:
        case DNX_FC_GEN_SRC_LLFC_VSQ:
        {
            /** Verify source flags */
            if (source->flags != 0)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source flags.");
            }

            /** Verify source COSQ */
            if (source->cosq != BCM_COS_INVALID)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source COSQ, must be -1");
            }
            break;
        }
        default:
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "The input source_type_gen(%d) supplied is not valid. \n", source_type_gen);
            break;
        }
    }
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - This function to verify the parameters for flow control sources for reception
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - unit id
 *   \param [in] source - holds information for the source of the Flow control
 *   \param [in] source_type_rec - holds information for the type of the source object
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_cosq_fc_rec_src_verify(
    int unit,
    bcm_cosq_fc_endpoint_t * source,
    dnx_fc_rec_src_t source_type_rec)
{
    SHR_FUNC_INIT_VARS(unit);

    switch (source_type_rec)
    {
        case DNX_FC_REC_SRC_LLFC:
        {
            /** Verify source flags */
            if (source->flags != 0)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source flags.");
            }

            /** Verify source calender_index */
            if (source->calender_index != -1)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source calender_index, must be -1");
            }
            break;
        }
        case DNX_FC_REC_SRC_PFC:
        {
            /** Verify source flags */
            if (source->flags != 0)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source flags.");
            }

            /** Verify source calender_index */
            if (source->calender_index != -1)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source calender_index, must be -1");
            }
            break;
        }
        case DNX_FC_REC_SRC_CAL:
        {
            /** Verify source flags */
            if (source->flags != 0)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source flags.");
            }

            /** Verify source COSQ */
            if (source->cosq != BCM_COS_INVALID)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source COSQ, must be -1");
            }

             /** Verify source calender_index */
            if ((source->calender_index < 0) || (source->calender_index > 511))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid source calender_index");
            }
            break;
        }
        default:
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "The input source_type_rec(%d) supplied is not valid. \n", source_type_rec);
            break;
        }
    }
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief -
 * To get reception reaction points and generation targets.
 * Use cases:
 *  ** Use case: "Generation from GLB RES"
 *  Return the targets of generation from Global recources.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ Global Gport
 *        source->flags - BCM_COSQ_FC_BDB, BCM_COSQ_FC_HEADROOM or BCM_COSQ_FC_IS_OCB_ONLY
 *        source->cosq - 0 for Pool 0, 1 for Pool 1 and -1 for Total
 *        source->calendar - not relevant
 *        source->priority - 0 for high, 1 for low priority
 *  - target_max - maximum size of target array
 *
 *  ** Use case: "Generation from LLFC VSQ"
 *  Return the targets of generation from LLFC VSQ.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ LLFC Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target_max - maximum size of target array
 *
 *  ** Use case: "Generation from PFC VSQ"
 *  Return the targets of generation from PFC VSQ.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ PFC Gport
 *        source->flags - 0
 *        source->cosq - [0,7]
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target_max - maximum size of target array
 *
 *  ** Use case: "Generation from Cat2 + TC VSQ"
 *  Return the targets of generation from Cat2 + TC VSQ.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ Cat2 + TC Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target_max - maximum size of target array
 *
 *  ** Use case: "Generation from VSQ Group A-D"
 *  Return the targets of generation from VSQ Group A-D.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - VSQ Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target_max - maximum size of target array
 *
 *  ** Use case: "Generation from Almost Full NIF"
 *  Return the targets of generation from Almost Full NIF.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlGeneration
 *  - source
 *        source->port - Interface Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - not relevant
 *        source->priority - not relevant
 *  - target_max - maximum size of target array
 *
 *  ** Use case: "Reception from LLFC"
 *  Return the targets of reception from LLFC.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlReception
 *  - source
 *        source->port - Interface Gport or Local Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - -1, not relevant
 *        source->priority - not relevant
 *  - target_max - maximum size of target array
 *
 *  ** Use case: "Reception from PFC"
 *  Return the targets of reception from PFC.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlReception
 *  - source
 *        source->port - Interface Gport or Local Gport
 *        source->flags - 0
 *        source->cosq - [0,7]
 *        source->calendar - -1, not relevant
 *        source->priority - not relevant
 *  - target_max - maximum size of target array
 *
 *  ** Use case: "Reception from OOB calendar"
 *  Return the targets of reception from OOB calendar.
 *  Parameters:
 *  - fc_direction - bcmCosqFlowControlReception
 *  - source
 *        source->port - Congestion Gport
 *        source->flags - 0
 *        source->cosq - -1, not relevant
 *        source->calendar - calender entry index
 *        source->priority - not relevant
 *  - target_max - maximum size of target array
 *
 *   \param [in] unit - unit
 *   \param [in] fc_direction - indicates if the path is reception or generation
 *   \param [in] source - source object
 *   \param [in] target_max - maximum size of target array
 *   \param [out] target - target object array
 *   \param [out] target_count - updated size(valid entries) of target array
 * \return
 *   see shr_error_e
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_cosq_fc_path_get(
    int unit,
    bcm_cosq_fc_direction_type_t fc_direction,
    bcm_cosq_fc_endpoint_t * source,
    int target_max,
    bcm_cosq_fc_endpoint_t * target,
    int *target_count)
{
    dnx_fc_gen_src_t source_type_gen = DNX_FC_GENERATION_SOURCES;
    dnx_fc_rec_src_t source_type_rec = DNX_FC_RECEPTION_SOURCES;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_NULL_CHECK(target, _SHR_E_PARAM, "target");
    SHR_NULL_CHECK(target_count, _SHR_E_PARAM, "target_count");
    sal_memset(target, 0, sizeof(bcm_cosq_fc_endpoint_t) * target_max);
    sal_memset(target_count, 0, sizeof(uint32));

    if (fc_direction == bcmCosqFlowControlGeneration)
    {
        /** Verify input gport and get source for generation */
        SHR_IF_ERR_EXIT(dnx_cosq_fc_gen_src_target_get(unit, source, target, &source_type_gen, NULL));

        /*
         * Call the appropriate function to verify the case specific parameters
         */
        SHR_INVOKE_VERIFY_DNXC(dnx_cosq_fc_gen_src_verify(unit, source, source_type_gen));

        /*
         * Call the appropriate function to read from HW
         */
        switch (source_type_gen)
        {
            case DNX_FC_GEN_SRC_GLB_RES:
            {
                /** Use case: Generation from GLB RES */
                SHR_IF_ERR_EXIT(dnx_fc_gen_glb_res_target_get(unit, source, target_max, target, target_count));
                break;
            }
            case DNX_FC_GEN_SRC_LLFC_VSQ:
            {
                /** Use case: Generation from LLFC VSQ */
                SHR_IF_ERR_EXIT(dnx_fc_gen_llfc_vsq_target_get(unit, source, target_max, target, target_count));
                break;
            }
            case DNX_FC_GEN_SRC_PFC_VSQ:
            {
                /** Use case: Generation from PFC VSQ */
                SHR_IF_ERR_EXIT(dnx_fc_gen_pfc_vsq_target_get(unit, source, target_max, target, target_count));
                break;
            }
            case DNX_FC_GEN_SRC_CAT2_TC_VSQ:
            {
                /** Use case: Generation from Cat2 + TC VSQ */
                SHR_IF_ERR_EXIT(dnx_fc_gen_c2_tc_vsq_target_get(unit, source, target_max, target, target_count));
                break;
            }
            case DNX_FC_GEN_SRC_VSQ_A_D:
            {
                /** Use case: Generation from VSQ Group A-D */
                SHR_IF_ERR_EXIT(dnx_fc_gen_vsq_a_d_target_get(unit, source, target_max, target, target_count));
                break;
            }
            case DNX_FC_GEN_SRC_ALMOST_FULL_NIF:
            {
                /** Use case: Generation from Almost Full NIF */
                SHR_IF_ERR_EXIT(dnx_fc_gen_nif_target_get(unit, source, target_max, target, target_count));
                break;
            }
            default:
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "The reception source type is not valid. \n");
                break;
            }
        }
    }
    else if (fc_direction == bcmCosqFlowControlReception)
    {
        /** Verify input gport and get source for reception */
        SHR_IF_ERR_EXIT(dnx_cosq_fc_rec_src_target_get(unit, source, target, &source_type_rec, NULL));

        /*
         * Call the appropriate function to verify the case specific parameters
         */
        SHR_INVOKE_VERIFY_DNXC(dnx_cosq_fc_rec_src_verify(unit, source, source_type_rec));

        /*
         * Call the appropriate function to read from HW
         */
        switch (source_type_rec)
        {
            case DNX_FC_REC_SRC_LLFC:
            case DNX_FC_REC_SRC_PFC:
            {
                /** Use case: Reception from LLFC */
                /** Use case: Reception from PFC */
                SHR_IF_ERR_EXIT(dnx_fc_rec_llfc_pfc_react_point_get(unit, source, target_max, target, target_count));
                break;
            }
            case DNX_FC_REC_SRC_CAL:
            {
                /** Use case: Reception from Calendar(OOB, COE) */
                SHR_IF_ERR_EXIT(dnx_fc_rec_cal_react_point_get(unit, source, target_max, target, target_count));
                break;
            }
            default:
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "The reception source type is not valid. \n");
                break;
            }
        }
    }
    else if (fc_direction == bcmCosqFlowControlInternal)
    {
        {
            SHR_IF_ERR_EXIT(dnx_scheduler_internal_fc_map_get(unit, source, target_max, target, target_count));
        }
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Unit %d, unsupported flow control direction %d", unit, fc_direction);
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}
