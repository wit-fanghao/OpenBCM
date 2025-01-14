/*~~~~~~~~~~~~~~~~~~~~~~~~~~Cosq: E2E Scheduling~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*
 * 
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * File: cint_dnx_e2e_composite_se.c
 * Purpose: Example of Composite SE Validation
 *
 * Environment
 *    - Default Egress queue mapping in play.
 *    - Default Egress Port Scheduler hierarchy in play.
 *    - Default Ingress Scheduling Discipline (delay tolerance), queues sizes
 *    - Packet Size 1500 packet - size should be aligned with credit source settings
 *
 * - Port Scheduler
 *   - CL Scheduler Instance 0 (SP mode, Composite), Hookup both to Port Schedulers (SP0, SP2)
 *   - CL Scheduler Instance 1 (SP mode, Composite), Hookup both to Port Schedulers (SP1, SP4)
 *     - 4 FQ Schedulers
 *       Instance 0 and 1 hooked to CL Instance 0 (SP0, SP1)
 *       Instance 2 and 3 hooked to CL Instance 1 (SP0, SP1)
 *       - 1st Queue Group / Connector Group (4 elements in bundle) connected to
 *         corresponding FQ schedulers
 *       - 2nd Queue Group / Connector Group (4 elements in bundle) connected to
 *         corresponding FQ schedulers
 *
 * - test run 1
 *   - Input
 *     - Queue Group 1 - Cos 0
 *       Input 500 Mbps
 *     - Queue Group 1 - Cos 2
 *       Input 100 Mbps
 *
 *   - Expected Output
 *     - Queue Group 1 - Cos 0
 *       Expected Output 300 Mbps (CL instance 0 CIR/1st flow)
 *       Observed =>
 *       Expected Output 100 Mbps (CL instance 0 EIR/2nd flow)
 *       Observed =>
 *     - Queue Group 1 - Cos 2
 *       Expected Output 100 Mbps (CLI instance 1 CIR/1st flow)
 *       Observed =>
 *
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  |                                                                                |
 *  |                                       |                                        |
 *  |                                      SPR (500 Mbps)                            |
 *  |                                       |                                        |
 *  |                                      \/                                        |
 *  |                               +-------------------+                            |
 *  |                              /          HR         \                           |
 *  |                             /                       \                          |
 *  |                            / SP0  SP1  SP2  SP3  SP4 \                         |
 *  |                           +---------------------------+                        |
 *  |                              /     \   /          |                            |
 *  |                             /       \ /           |                            |
 *  |                           SPR       /\           SPR                           |
 *  |                      (300 Mbps)   SPR SPR     (200 Mbps)                       |
 *  |                          / (200 Mbps) (300 Mbps)  |                            |
 *  |                         /        /      \         |                            |
 *  |                        \/       \/      \/       \/                            |
 *  |                  +--------------+       +--------------+                       |
 *  |                 /CL (4 SP levels)\     /CL (4 SP levels)\                      |
 *  |                /                  \   /                  \                     |
 *  |               / SP0  SP1  SP2  SP3 \ / SP0  SP1  SP2  SP3 \                    |
 *  |              +---------------------++----------------------+                   |
 *  |                 /     \                /     \                                 |
 *  |                /       \              /       \                                |
 *  |              SPR       SPR          SPR       SPR                              |
 *  |          (500 Mbps) (500 Mbps)  (500 Mbps) (500 Mbps)                          |
 *  |             /             \        /             \                             |
 *  |            \/             \/      \/             \/                            |
 *  |         +------+      +------+   +------+      +------+                        |
 *  |        /   FQ   \    /   FQ   \ /   FQ   \    /   FQ   \                       |
 *  |       +----------+  +----------+----------+  +----------+                      |
 *  |            |             |          |              |                           |
 *  |            |             |          |              |                           |
 *  |           SPR           SPR        SPR            SPR                          |
 *  |        (500 Mbps)    (500 Mbps) (500 Mbps)    (500 Mbps)                       |
 *  |            |             |          |              |                           |
 *  |            |             |          |              |                           |
 *  |           \/            \/         \/             \/                           |
 *  |         |     |      |     |    |     |         |     |                        |
 *  |         |     |      |     |    |     |         |     |                        |
 *  |         |     |      |     |    |     |         |     |                        |
 *  |         |     |      |     |    |     |         |     |                        |
 *  |         |     |      |     |    |     |         |     |                        |
 *  |         +-----+      +-----+    +-----+         +-----+                        |
 *  |      Input:500 Mbps          Input:100 Mbps                +----------------+  |
 *  |                                                            |      KEY       |  |
 *  |                                                            +----------------+  |
 *  |                                                            |SPR- Rate Shaper|  |
 *  |                                                            |                |  |
 *  |                                                            +----------------+  |
 *  |                     +~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                             |
 *  |                     |   Figure 8: Composite SE   |                             |
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 */

/*
 * General Definitions
 */
int C4_NUM_COS = 4;

int C4_DEFAULT_E2E_SCHED_TYPE = bcmCosqSchedulerGportTypeHrEnhanced;
int C4_SCHED_CL_TYPE = bcmCosqSchedulerGportTypeClass4Sp;
int C4_SCHED_CL_MODE = bcmCosqSchedulerGportModeComposite;
int C4_NBR_SCHEDULERS = 2;
int C4_NBR_SCHEDULER_FLOWS = 2;
int C4_SCHEDULER0_CIR_MODE = BCM_COSQ_SP0;
int C4_SCHEDULER0_EIR_MODE = BCM_COSQ_SP2;
int C4_SCHEDULER1_CIR_MODE = BCM_COSQ_SP1;
int C4_SCHEDULER1_EIR_MODE = BCM_COSQ_SP4;
int C4_SCHED_CIR_KBITS_SEC_MAX = 3000000; /* 3000 Mbps */
int C4_SCHED_CIR_KBITS_SEC_MAX_MARGIN = 10; /* 10 Kbps */
int C4_SCHED_EIR_KBITS_SEC_MAX = 2000000; /* 2000 Mbps */
int C4_SCHED_EIR_KBITS_SEC_MAX_MARGIN = 2600; /* 2600 Kbps */
int C4_SCHED_KBITS_SEC_MAX = 5000000; /* 5000 Mbps */
int C4_SCHED_MAX_BURST = 3000;
int C4_SCHED_MAX_BURST_MARGIN = 75;

int C4_NBR_QUEUE_GROUPS = 2;
int C4_NBR_FQ_SCHEDULERS = 4;


/* handles */
int c4_my_modid = 0;


bcm_gport_t c4_gport_ucast_voq_connector_group0[32];
bcm_gport_t c4_gport_ucast_voq_connector_group1[32];
bcm_gport_t c4_gport_ucast_queue_group0[32];
bcm_gport_t c4_gport_ucast_queue_group1[32];
bcm_gport_t c4_gport_ucast_scheduler[32];
bcm_gport_t c4_gport_ucast_scheduler_sf2[32]; /* sub-flow two */
bcm_gport_t c4_gport_ucast_scheduler1[32];
bcm_gport_t c4_gport_ucast_scheduler1_sf2[32]; /* sub-flow two */
bcm_gport_t c4_gport_ucast_scheduler_fq0[32];
bcm_gport_t c4_gport_ucast_scheduler_fq1[32];
bcm_gport_t c4_gport_ucast_scheduler_fq2[32];
bcm_gport_t c4_gport_ucast_scheduler_fq3[32];
bcm_gport_t c4_e2e_gport[32];
bcm_gport_t c4_e2e_parent_gport[32];

int c4_use_same_handles = 0;


void e2e_composite_se_display_handles(int idx)
{
    printf("  e2eGport(0x%x)\n", c4_e2e_gport[idx]);
    printf("    sched0Gport(0x%x), sched0Sf2(0x%x) sched1Gport(0x%x), sched1Sf2(0x%x)\n",
            c4_gport_ucast_scheduler[idx], c4_gport_ucast_scheduler_sf2[idx],
            c4_gport_ucast_scheduler1[idx], c4_gport_ucast_scheduler1_sf2[idx]);
    printf("    l3_fq0(0x%x) l3_fq1(0x%x) l3_fq2(0x%x) l3_fq3(0x%x)\n",
            c4_gport_ucast_scheduler_fq0[idx], c4_gport_ucast_scheduler_fq1[idx],
            c4_gport_ucast_scheduler_fq2[idx], c4_gport_ucast_scheduler_fq3[idx]);
    printf("    connGrp0Gport(0x%x) connGrp1Gport(0x%x)\n",
            c4_gport_ucast_voq_connector_group0[idx], c4_gport_ucast_voq_connector_group1[idx]);
    printf("    ucastGrp0Gport(0x%x) ucastGrp1Gport(0x%x)\n",
            c4_gport_ucast_queue_group0[idx], c4_gport_ucast_queue_group1[idx]);
}


/* Added parameter: kbits_sec_max_port identify maximum bandwidth for the Interface and port. */
/* One example of running (see Negev UM for figure description is by running: main(500000)) */
int e2e_composite_se_setup(int unit, int kbits_sec_max_port, int port_idx)
{
    int idx, port, system_port;
    bcm_gport_t dest_gport[32];
    bcm_gport_t sys_gport[32];
    int num_cos = 4;
    int flags = 0, default_flags = 0, default_voq_flags = 0, default_connector_flags = 0;
    int voq;
    bcm_cosq_gport_connection_t connection;
    int max_burst;
    int cosq = 0;
    bcm_cosq_delay_tolerance_t delay_tolerance;
    int kbits_sec_max;
    bcm_cosq_voq_connector_gport_t config;
    uint32 dummy_flags ;
    bcm_port_interface_info_t interface_info;
    bcm_port_mapping_info_t mapping_info ;
    bcm_cosq_ingress_queue_bundle_gport_config_t conf;
    bcm_port_resource_t resource;
    int delay_tolerance_level, rate_class;
    bcm_cosq_scheduler_gport_params_t params;

    printf("\nSetup\n");

    int credit_worth = *(dnxc_data_get(unit, "iqs", "credit", "worth", NULL));
    C4_SCHED_MAX_BURST *=(credit_worth / 1024);
    C4_SCHED_MAX_BURST_MARGIN *=(credit_worth / 1024);

    if (c4_use_same_handles == 1) {
        default_flags = BCM_COSQ_SCHEDULER_GPORT_WITH_ID;
        default_voq_flags = BCM_COSQ_GPORT_WITH_ID;
        default_connector_flags = BCM_COSQ_VOQ_CONNECTOR_GPORT_F_WITH_ID;
        e2e_composite_se_display_handles(0);
    }

    idx = port_idx;

    port = idx + 1;
    system_port = idx + 1;
    BCM_GPORT_SYSTEM_PORT_ID_SET(sys_gport[idx], system_port);
    BCM_GPORT_LOCAL_SET(dest_gport[idx], port);

    BCM_IF_ERROR_RETURN_MSG(bcm_port_get(unit, port, &dummy_flags, &interface_info, &mapping_info), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_stk_sysport_gport_set(unit, sys_gport[idx], dest_gport[idx]), "");

    /*
     * create CL scheduler (Instance 0)
     */

    params.type = bcmCosqSchedulerGportTypeClass4Sp;
    params.mode = bcmCosqSchedulerGportModeComposite;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeNone;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, default_flags, params, &c4_gport_ucast_scheduler[idx]), "");


    /* COS 0, CL scheduler (Instance 0) scheduling discipline configuration */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_scheduler[idx],
            0,
            C4_SCHEDULER0_CIR_MODE,
            0), "");

    BCM_COSQ_GPORT_E2E_PORT_SET(c4_e2e_gport[idx], port);

    /* CL scheduler (instance 0) attach to E2E port scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_e2e_gport[idx],
            c4_gport_ucast_scheduler[idx], 0), "");

    /* CL (sf2) setup */
    BCM_COSQ_GPORT_COMPOSITE_SF2_CORE_SET(c4_gport_ucast_scheduler_sf2[idx],c4_gport_ucast_scheduler[idx], mapping_info.core);
    /* COS 0, CL scheduler instance 0 (sf2) scheduling discipline configuration */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_scheduler_sf2[idx],
            0,
            C4_SCHEDULER0_EIR_MODE,
            0), "");

    /* CL scheduler instance 0 (sf2) attach to E2E port scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_e2e_gport[idx],
            c4_gport_ucast_scheduler_sf2[idx], 0), "");


    /*
     * create CL scheduler (Instance 1)
     */

    params.type = bcmCosqSchedulerGportTypeClass4Sp;
    params.mode = bcmCosqSchedulerGportModeComposite;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeNone;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, default_flags, params, &c4_gport_ucast_scheduler1[idx]), "");


    /* COS 0, CL scheduler instance 1 scheduling discipline configuration */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_scheduler1[idx],
            0,
            C4_SCHEDULER1_CIR_MODE,
            0), "");

    BCM_COSQ_GPORT_E2E_PORT_SET(c4_e2e_gport[idx], port);

    /* CL scheduler instance 1 attach to E2E port scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_e2e_gport[idx],
            c4_gport_ucast_scheduler1[idx], 0), "");

    /* CL instance 1 (sf2) setup */
    BCM_COSQ_GPORT_COMPOSITE_SF2_CORE_SET(c4_gport_ucast_scheduler1_sf2[idx],c4_gport_ucast_scheduler1[idx], mapping_info.core);
    /* COS 0, CL scheduler instance 1 (sf2) scheduling discipline configuration */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_scheduler1_sf2[idx],
            0,
            C4_SCHEDULER1_EIR_MODE,
            0), "");

    /* CL scheduler instance 1 (sf2) attach to E2E port scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_e2e_gport[idx],
            c4_gport_ucast_scheduler1_sf2[idx], 0), "");


    /* create scheduler FQ scheduler (instance 0) - will aggregrate all cos 0 queues */

    params.type = bcmCosqSchedulerGportTypeFq;
    params.mode = bcmCosqSchedulerGportModeSimple;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeNone;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, default_flags, params, &c4_gport_ucast_scheduler_fq0[idx]), "");

    /* COS 0, FQ scheduler (instance 0) scheduling discipline configuration */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_scheduler_fq0[idx],
            0,
            BCM_COSQ_SP0,
            0), "");

    /* FQ scheduler (instance 0) attach to CL scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler[idx],
            c4_gport_ucast_scheduler_fq0[idx], 0), "");


    /* create scheduler FQ scheduler (instance 1) - will aggregrate all cos 1 queues */

    params.type = bcmCosqSchedulerGportTypeFq;
    params.mode = bcmCosqSchedulerGportModeSimple;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeNone;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, default_flags, params, &c4_gport_ucast_scheduler_fq1[idx]), "");

    /* COS 0, FQ scheduler (instance 1) scheduling discipline configuration */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_scheduler_fq1[idx],
            0,
            BCM_COSQ_SP1,
            0), "");


    /* FQ scheduler (instance 1) attach to CL scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler[idx],
            c4_gport_ucast_scheduler_fq1[idx], 0), "");


    /* create scheduler FQ scheduler (instance 2) - will aggregrate all cos 2 queues */

    params.type = bcmCosqSchedulerGportTypeFq;
    params.mode = bcmCosqSchedulerGportModeSimple;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeNone;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, default_flags, params, &c4_gport_ucast_scheduler_fq2[idx]), "");

    /* COS 0, FQ scheduler (instance 2) scheduling discipline configuration */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_scheduler_fq2[idx],
            0,
            BCM_COSQ_SP0,
            0), "");


    /* FQ scheduler (instance 2) attach to CL scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler1[idx],
            c4_gport_ucast_scheduler_fq2[idx], 0), "");


    /* create scheduler FQ scheduler (instance 3) - will aggregrate all cos 3 queues */

    params.type = bcmCosqSchedulerGportTypeFq;
    params.mode = bcmCosqSchedulerGportModeSimple;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeNone;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, default_flags, params, &c4_gport_ucast_scheduler_fq3[idx]), "");

    /* COS 0, FQ scheduler (instance 3) scheduling discipline configuration */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_scheduler_fq3[idx],
            0,
            BCM_COSQ_SP1,
            0), "");


    /* FQ scheduler (instance 3) attach to CL scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler1[idx],
            c4_gport_ucast_scheduler_fq3[idx], 0), "");


    /* create voq connector bundle, 4 elements in bundle */
    BCM_GPORT_LOCAL_SET(config.port, port);
    config.flags = BCM_COSQ_GPORT_VOQ_CONNECTOR | default_connector_flags;
    config.numq = num_cos;
    config.remote_modid = c4_my_modid + mapping_info.core;
    config.nof_remote_cores = 1;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_voq_connector_gport_add(unit, &config, &c4_gport_ucast_voq_connector_group0[idx]), "");

    /* COS 0 (bundle 1st element), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_voq_connector_group0[idx],
            0,
            BCM_COSQ_SP0,
            0), "");

    /* COS 0 (bundle 1st element), attach to FQ scheduler (instance 0) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler_fq0[idx],
            c4_gport_ucast_voq_connector_group0[idx], 0), "");


    /* COS 1, (bundle 2nd element), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_voq_connector_group0[idx],
            1,
            BCM_COSQ_SP0,
            0), "");

    /* COS 1 (bundle 2nd element), attach to FQ scheduler (instance 1) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler_fq1[idx],
            c4_gport_ucast_voq_connector_group0[idx], 1), "");


    /* COS 2, (bundle 3nd element), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_voq_connector_group0[idx],
            2,
            BCM_COSQ_SP0,
            0), "");

    /* COS 2 (bundle 3rd element), attach to FQ scheduler (instance 2) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler_fq2[idx],
            c4_gport_ucast_voq_connector_group0[idx], 2), "");

    /* COS 3, (bundle 4th element), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_voq_connector_group0[idx],
            3,
            BCM_COSQ_SP0,
            0), "");

    /* COS 3 (bundle 4th element), attach to FQ scheduler (instance 3) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler_fq3[idx],
            c4_gport_ucast_voq_connector_group0[idx], 3), "");


    /* create queue group bundle, 4 elements in bundle */
    flags = BCM_COSQ_GPORT_UCAST_QUEUE_GROUP | default_voq_flags;
    BCM_IF_ERROR_RETURN_MSG(bcm_port_resource_get(unit, port, &resource), "");
    BCM_IF_ERROR_RETURN_MSG(appl_dnx_e2e_voq_profiles_get(unit, resource.speed, &delay_tolerance_level, &rate_class), "");
    conf.flags = flags;
    conf.port = sys_gport[idx];
    conf.numq = num_cos;
    conf.local_core_id = BCM_CORE_ALL;
    for (cosq = 0; cosq < num_cos; cosq++) {
        conf.queue_atrributes[cosq].delay_tolerance_level = delay_tolerance_level;
        conf.queue_atrributes[cosq].rate_class = rate_class;
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_ingress_queue_bundle_gport_add(unit, &conf, &c4_gport_ucast_queue_group0[idx]), "");
    printf("ucast gport(0x%08x)\n", c4_gport_ucast_queue_group0[idx]);


    /* connect VoQ to flow */
    connection.flags = BCM_COSQ_GPORT_CONNECTION_INGRESS;
    connection.remote_modid = c4_my_modid  + mapping_info.core;
    BCM_GPORT_UNICAST_QUEUE_GROUP_CORE_QUEUE_SET( c4_gport_ucast_queue_group0[idx], mapping_info.core, BCM_GPORT_UNICAST_QUEUE_GROUP_QID_GET(c4_gport_ucast_queue_group0[idx]));
    connection.voq = c4_gport_ucast_queue_group0[idx];
    connection.voq_connector = c4_gport_ucast_voq_connector_group0[idx];

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), "");

    /* connect flow to VoQ */
    connection.flags = BCM_COSQ_GPORT_CONNECTION_EGRESS;
    connection.remote_modid = c4_my_modid + mapping_info.core;
    BCM_GPORT_UNICAST_QUEUE_GROUP_CORE_QUEUE_SET( c4_gport_ucast_queue_group0[idx], mapping_info.core, BCM_GPORT_UNICAST_QUEUE_GROUP_QID_GET(c4_gport_ucast_queue_group0[idx]));
    connection.voq = c4_gport_ucast_queue_group0[idx];
    connection.voq_connector = c4_gport_ucast_voq_connector_group0[idx];

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), "");

    /* configuration for another queue group */
    /* create voq connector bundle, 4 elements in the bundle */
    BCM_GPORT_LOCAL_SET(config.port, port);
    config.flags = BCM_COSQ_GPORT_VOQ_CONNECTOR | default_connector_flags;
    config.numq = num_cos;
    config.remote_modid = c4_my_modid + mapping_info.core;
    config.nof_remote_cores = 1;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_voq_connector_gport_add(unit, &config, &c4_gport_ucast_voq_connector_group1[idx]), "");

    /* COS 0 (bundle 1st element), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_voq_connector_group1[idx],
            0,
            BCM_COSQ_SP0,
            0), "");

    /* COS 0 (bundle 1st element), attach to FQ scheduler (instance 0) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler_fq0[idx],
            c4_gport_ucast_voq_connector_group1[idx], 0), "");

    /* COS 1 (bundle 2nd element), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_voq_connector_group1[idx],
            1,
            BCM_COSQ_SP0,
            0), "");

    /* COS 1 (bundle 2nd element), attach to FQ scheduler (instance 1) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler_fq1[idx],
            c4_gport_ucast_voq_connector_group1[idx], 1), "");

    /* COS 2 (bundle 3rd element), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_voq_connector_group1[idx],
            2,
            BCM_COSQ_SP0,
            0), "");

    /* COS 2 (bundle 3rd element), attach to FQ scheduler (instance 2) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler_fq2[idx],
            c4_gport_ucast_voq_connector_group1[idx], 2), "");

    /* COS 3 (bundle 4th element), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c4_gport_ucast_voq_connector_group1[idx],
            3,
            BCM_COSQ_SP0,
            0), "");

    /* COS 3 (bundle 4th element), attach to FQ scheduler (instance 3) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c4_gport_ucast_scheduler_fq3[idx],
            c4_gport_ucast_voq_connector_group1[idx], 3), "");

    /* create queue group bundle, 4 elements in bundle */
    flags = BCM_COSQ_GPORT_UCAST_QUEUE_GROUP | BCM_COSQ_GPORT_TM_FLOW_ID | default_voq_flags;
    BCM_IF_ERROR_RETURN_MSG(bcm_port_resource_get(unit, port, &resource), "");
    BCM_IF_ERROR_RETURN_MSG(appl_dnx_e2e_voq_profiles_get(unit, resource.speed, &delay_tolerance_level, &rate_class), "");
    conf.flags = flags;
    conf.port = sys_gport[idx];
    conf.numq = num_cos;
    conf.local_core_id = BCM_CORE_ALL;
    for (cosq = 0; cosq < num_cos; cosq++) {
        conf.queue_atrributes[cosq].delay_tolerance_level = delay_tolerance_level;
        conf.queue_atrributes[cosq].rate_class = rate_class;
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_ingress_queue_bundle_gport_add(unit, &conf, &c4_gport_ucast_queue_group1[idx]), "");
    printf("ucast gport(0x%08x)\n", c4_gport_ucast_queue_group1[idx]);

    /* connect VoQ to flow */
    connection.flags = BCM_COSQ_GPORT_CONNECTION_INGRESS;
    connection.remote_modid = c4_my_modid + mapping_info.core;
    BCM_GPORT_UNICAST_QUEUE_GROUP_CORE_QUEUE_SET( c4_gport_ucast_queue_group1[idx], mapping_info.core, BCM_GPORT_UNICAST_QUEUE_GROUP_QID_GET(c4_gport_ucast_queue_group1[idx]));
    connection.voq = c4_gport_ucast_queue_group1[idx];
    connection.voq_connector = c4_gport_ucast_voq_connector_group1[idx];

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), "");

    /* connect flow to VoQ */
    connection.flags = BCM_COSQ_GPORT_CONNECTION_EGRESS;
    connection.remote_modid = c4_my_modid + mapping_info.core;
    BCM_GPORT_UNICAST_QUEUE_GROUP_CORE_QUEUE_SET(c4_gport_ucast_queue_group1[idx], mapping_info.core, BCM_GPORT_UNICAST_QUEUE_GROUP_QID_GET(c4_gport_ucast_queue_group1[idx]));
    connection.voq = c4_gport_ucast_queue_group1[idx];
    connection.voq_connector = c4_gport_ucast_voq_connector_group1[idx];

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), "");

    /*
     * Set rate on the E2E Interface
     */

    BCM_COSQ_GPORT_E2E_PORT_SET(c4_e2e_gport[idx], port);

    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_port_get(unit,
            c4_e2e_gport[idx],
            0,
            &c4_e2e_parent_gport[idx]), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c4_e2e_parent_gport[idx],
            0,
            0,
            kbits_sec_max_port,
            0), "");

    /*
     * Set rate on the E2E port
     */

    BCM_COSQ_GPORT_E2E_PORT_SET(c4_e2e_gport[idx], port);

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c4_e2e_gport[idx],
            0,
            0,
            kbits_sec_max_port,
            0), "");

    /*
     * bandwidth set for CL instance 0 (PIR) flow
     */
    kbits_sec_max = C4_SCHED_CIR_KBITS_SEC_MAX;
    max_burst = C4_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c4_gport_ucast_scheduler[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    /* Set max burst on the CL instance 0 Scheduler - PIR flow */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c4_gport_ucast_scheduler[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");

    /*
     * bandwidth set for CL instance 0 (EIR) flow
     */
    kbits_sec_max = C4_SCHED_EIR_KBITS_SEC_MAX;
    max_burst = C4_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c4_gport_ucast_scheduler_sf2[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    /* Set max burst on the CL instance 0 Scheduler - EIR flow */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c4_gport_ucast_scheduler_sf2[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");

    /*
     * bandwidth set for CL instance 1 (PIR) flow
     */
    kbits_sec_max = C4_SCHED_CIR_KBITS_SEC_MAX;
    max_burst = C4_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c4_gport_ucast_scheduler1[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    /* Set max burst on the CL instance 0 Scheduler - PIR flow */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c4_gport_ucast_scheduler1[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");


    /*
     * bandwidth set for CL instance 0 (EIR) flow
     */
    kbits_sec_max = C4_SCHED_EIR_KBITS_SEC_MAX;
    max_burst = C4_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c4_gport_ucast_scheduler1_sf2[idx],
            0,
            0,
            kbits_sec_max,
            0), "");


    /* Set max burst on the CL instance 0 Scheduler - EIR flow */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c4_gport_ucast_scheduler1_sf2[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");

    /*
     * FQ scheduler (instance 0)
     */
    kbits_sec_max = C4_SCHED_KBITS_SEC_MAX; /* 500 Mbps */
    max_burst =  C4_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c4_gport_ucast_scheduler_fq0[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c4_gport_ucast_scheduler_fq0[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");

    /*
     * FQ scheduler (instance 1)
     */
    kbits_sec_max = C4_SCHED_KBITS_SEC_MAX; /* 500 Mbps */
    max_burst =  C4_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c4_gport_ucast_scheduler_fq1[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c4_gport_ucast_scheduler_fq1[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");

    /*
     * FQ scheduler (instance 2)
     */
    kbits_sec_max = C4_SCHED_KBITS_SEC_MAX; /* 500 Mbps */
    max_burst =  C4_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c4_gport_ucast_scheduler_fq2[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c4_gport_ucast_scheduler_fq2[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");

    /*
     * FQ scheduler (instance 3)
     */
    kbits_sec_max = C4_SCHED_KBITS_SEC_MAX; /* 500 Mbps */
    max_burst =  C4_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c4_gport_ucast_scheduler_fq3[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c4_gport_ucast_scheduler_fq3[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");

    /*
     * Connector Group 0
     */
    kbits_sec_max = C4_SCHED_KBITS_SEC_MAX; /* 500 Mbps */
    max_burst =  C4_SCHED_MAX_BURST;
    for (cosq=0; cosq<4; cosq++) {
        /* Set rate on the Connector flow */
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
                c4_gport_ucast_voq_connector_group0[idx],
                cosq,
                0,
                kbits_sec_max,
                0), "");

        /* Set maxburst on the Connector flow */
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
                c4_gport_ucast_voq_connector_group0[idx],
                cosq,
                bcmCosqControlBandwidthBurstMax,
                max_burst), "");

    }

    /*
     * Connector Group 1
     */
    kbits_sec_max = C4_SCHED_KBITS_SEC_MAX; /* 500 Mbps */
    max_burst =  C4_SCHED_MAX_BURST;
    for (cosq=0; cosq<4; cosq++) {
        /* Set rate on the Connector flow */
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
                c4_gport_ucast_voq_connector_group1[idx],
                cosq,
                0,
                kbits_sec_max,
                0), "");

        /* Set maxburst on the Connector flow */
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
                c4_gport_ucast_voq_connector_group1[idx],
                cosq,
                bcmCosqControlBandwidthBurstMax,
                max_burst), "");

    }

    if (c4_use_same_handles == 0) {
        e2e_composite_se_display_handles(idx);
    }

    printf("port(%d) sysport(%d) ucast gport(0x%08x)\n", port, system_port, c4_gport_ucast_queue_group0[idx]);

    printf("cint_dnx_e2e_composite_se.c completed with status (%s)\n", bcm_errmsg(BCM_E_NONE));
    return BCM_E_NONE;
}

int e2e_composite_se_teardown(int unit, int port_idx)
{
    int                           idx = port_idx;
    bcm_gport_t                   gport_ucast_voq_connector_group;
    bcm_gport_t                   gport_ucast_queue_group;
    bcm_gport_t                   gport_scheduler_fq;
    bcm_gport_t                   gport_ucast_scheduler;
    int                           nbr_queue_groups, nbr_fq_sched, nbr_sched, nbr_sched_flw;
    bcm_cosq_gport_connection_t   connection;
    int                           cosq = 0;
    uint32 dummy_flags;
    bcm_port_interface_info_t interface_info;
    bcm_port_mapping_info_t mapping_info;
    char error_msg[200]={0,};

    int C4_NBR_SCHEDULER_FLOWS = 2;
    printf("\nTeardown\n");

    e2e_composite_se_display_handles(idx);

    BCM_IF_ERROR_RETURN_MSG(bcm_port_get(unit, port_idx, &dummy_flags, &interface_info, &mapping_info), "");

    /* detach scheduler sub-tree from E2E hierarchy */
    for (nbr_sched = 0; nbr_sched < C4_NBR_SCHEDULERS; nbr_sched++) {
        switch(nbr_sched) {
        case 0:
            for (nbr_sched_flw = 0; nbr_sched_flw < C4_NBR_SCHEDULER_FLOWS; nbr_sched_flw++) {
                switch(nbr_sched_flw) {
                case 0: gport_ucast_scheduler = c4_gport_ucast_scheduler[idx]; break;
                default: gport_ucast_scheduler = c4_gport_ucast_scheduler_sf2[idx]; break;
                }

                snprintf(error_msg, sizeof(error_msg), "detach for SE(0x%x) failed", gport_ucast_scheduler);
                BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_detach(unit, c4_e2e_gport[idx], gport_ucast_scheduler, 0), error_msg);
                printf("  detached schedGport(0x%x)\n", gport_ucast_scheduler);
            }
            break;

        default:
            for (nbr_sched_flw = 0; nbr_sched_flw < C4_NBR_SCHEDULER_FLOWS; nbr_sched_flw++) {
                switch(nbr_sched_flw) {
                case 0: gport_ucast_scheduler = c4_gport_ucast_scheduler1[idx]; break;
                default: gport_ucast_scheduler = c4_gport_ucast_scheduler1_sf2[idx]; break;
                }

                snprintf(error_msg, sizeof(error_msg), "detach for SE(0x%x) failed", gport_ucast_scheduler);
                BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_detach(unit, c4_e2e_gport[idx], gport_ucast_scheduler, 0), error_msg);
                printf("  detached schedGport(0x%x)\n", gport_ucast_scheduler);
            }
            break;
        }
    }

    /* dis-associate queue from connectors */
    for (nbr_queue_groups = 0; nbr_queue_groups < C4_NBR_QUEUE_GROUPS; nbr_queue_groups++) {
        switch (nbr_queue_groups) {
        case 0: gport_ucast_queue_group = c4_gport_ucast_queue_group0[idx];
        gport_ucast_voq_connector_group = c4_gport_ucast_voq_connector_group0[idx]; break;
        default: gport_ucast_queue_group = c4_gport_ucast_queue_group1[idx];
        gport_ucast_voq_connector_group = c4_gport_ucast_voq_connector_group1[idx]; break;
        }

        connection.flags = BCM_COSQ_GPORT_CONNECTION_INGRESS | BCM_COSQ_GPORT_CONNECTION_INVALID;
        connection.remote_modid = c4_my_modid + mapping_info.core;
        connection.voq = gport_ucast_queue_group;
        connection.voq_connector = gport_ucast_voq_connector_group;

        snprintf(error_msg, sizeof(error_msg), "resetting queue2connector association failed, queue(0x%x)", gport_ucast_queue_group);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), error_msg);
        printf("  disconnected (Ingress) ucastGport(0x%x) from connGport(0x%x)\n", gport_ucast_queue_group, gport_ucast_voq_connector_group);
    }

    /* dis-associate connectors from queues */
    for (nbr_queue_groups = 0; nbr_queue_groups < C4_NBR_QUEUE_GROUPS; nbr_queue_groups++) {
        switch (nbr_queue_groups) {
        case 0: gport_ucast_queue_group = c4_gport_ucast_queue_group0[idx];
        gport_ucast_voq_connector_group = c4_gport_ucast_voq_connector_group0[idx]; break;
        default: gport_ucast_queue_group = c4_gport_ucast_queue_group1[idx];
        gport_ucast_voq_connector_group = c4_gport_ucast_voq_connector_group1[idx]; break;
        }

        connection.flags = BCM_COSQ_GPORT_CONNECTION_EGRESS | BCM_COSQ_GPORT_CONNECTION_INVALID;
        connection.remote_modid = c4_my_modid + mapping_info.core;
        connection.voq = gport_ucast_queue_group;
        connection.voq_connector = gport_ucast_voq_connector_group;

        snprintf(error_msg, sizeof(error_msg), "resetting connector2queue association failed, Connector(0x%x)", gport_ucast_voq_connector_group);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), error_msg);
        printf("  disconnected (Engress) connGport(0x%x) from ucastGport(0x%x)\n", gport_ucast_voq_connector_group, gport_ucast_queue_group);
    }

    /* delete queues */
    for (nbr_queue_groups = 0; nbr_queue_groups < C4_NBR_QUEUE_GROUPS; nbr_queue_groups++) {
        switch (nbr_queue_groups) {
        case 0: gport_ucast_queue_group = c4_gport_ucast_queue_group0[idx]; break;
        default: gport_ucast_queue_group = c4_gport_ucast_queue_group1[idx]; break;
        }

        snprintf(error_msg, sizeof(error_msg), "delete for QueueGroup(0x%x) failed", gport_ucast_queue_group);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_delete(unit, gport_ucast_queue_group), error_msg);
        printf("  deleted ucastGport(0x%x)\n", gport_ucast_queue_group);
    }

    /* detach connectors */
    for (nbr_queue_groups = 0; nbr_queue_groups < C4_NBR_QUEUE_GROUPS; nbr_queue_groups++) {
        switch (nbr_queue_groups) {
        case 0: gport_ucast_voq_connector_group = c4_gport_ucast_voq_connector_group0[idx]; break;
        default: gport_ucast_voq_connector_group = c4_gport_ucast_voq_connector_group1[idx]; break;
        }

        for (cosq = 0; cosq < 4; cosq++) {
            switch (cosq) {
            case 0: gport_scheduler_fq = c4_gport_ucast_scheduler_fq0[idx]; break;
            case 1: gport_scheduler_fq = c4_gport_ucast_scheduler_fq1[idx]; break;
            case 2: gport_scheduler_fq = c4_gport_ucast_scheduler_fq2[idx]; break;
            default: gport_scheduler_fq = c4_gport_ucast_scheduler_fq3[idx]; break;
            }

            snprintf(error_msg, sizeof(error_msg), "detach for Connector:cosq(0x%x:%d) from Sched(0x%x) failed", gport_ucast_voq_connector_group, cosq, gport_scheduler_fq);
            BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_detach(unit, gport_scheduler_fq, gport_ucast_voq_connector_group, cosq), error_msg);
            printf("  detached connGport:cosq(0x%x:%d) from schedGport(0x%x)\n", gport_ucast_voq_connector_group, cosq, gport_scheduler_fq);
        }
    }

    /* delete connectors */
    for (nbr_queue_groups = 0; nbr_queue_groups < C4_NBR_QUEUE_GROUPS; nbr_queue_groups++) {
        switch (nbr_queue_groups) {
        case 0: gport_ucast_voq_connector_group = c4_gport_ucast_voq_connector_group0[idx]; break;
        default: gport_ucast_voq_connector_group = c4_gport_ucast_voq_connector_group1[idx]; break;
        }

        /* delete connectors */
        snprintf(error_msg, sizeof(error_msg), "delete for ConnectorGroup(0x%x) failed", gport_ucast_voq_connector_group);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_delete(unit, gport_ucast_voq_connector_group), error_msg);
        printf("  delete connGport(0x%x)\n", gport_ucast_voq_connector_group);
    }

    /* detach intermediate Scheduler elements (SE) */
    for (nbr_fq_sched = 0; nbr_fq_sched < C4_NBR_FQ_SCHEDULERS; nbr_fq_sched++) {
        switch (nbr_fq_sched) {
        case 0: gport_scheduler_fq = c4_gport_ucast_scheduler_fq0[idx];
        gport_ucast_scheduler = c4_gport_ucast_scheduler[idx]; break;
        case 1: gport_scheduler_fq = c4_gport_ucast_scheduler_fq1[idx];
        gport_ucast_scheduler = c4_gport_ucast_scheduler[idx]; break;
        case 2: gport_scheduler_fq = c4_gport_ucast_scheduler_fq2[idx];
        gport_ucast_scheduler = c4_gport_ucast_scheduler1[idx]; break;
        default: gport_scheduler_fq = c4_gport_ucast_scheduler_fq3[idx];
        gport_ucast_scheduler = c4_gport_ucast_scheduler1[idx]; break;
        }

        snprintf(error_msg, sizeof(error_msg), "detach for SE(0x%x) failed", gport_scheduler_fq);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_detach(unit, gport_ucast_scheduler, gport_scheduler_fq, 0), error_msg);
        printf("  detached schedGport(0x%x)\n", gport_scheduler_fq);
    }

    /* delete intermediate Scheduler elements (SE) */
    for (nbr_fq_sched = 0; nbr_fq_sched < C4_NBR_FQ_SCHEDULERS; nbr_fq_sched++) {
        switch (nbr_fq_sched) {
        case 0: gport_scheduler_fq = c4_gport_ucast_scheduler_fq0[idx]; break;
        case 1: gport_scheduler_fq = c4_gport_ucast_scheduler_fq1[idx]; break;
        case 2: gport_scheduler_fq = c4_gport_ucast_scheduler_fq2[idx]; break;
        default: gport_scheduler_fq = c4_gport_ucast_scheduler_fq3[idx]; break;
        }

        snprintf(error_msg, sizeof(error_msg), "delete for SE(0x%x) failed", gport_scheduler_fq);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_delete(unit, gport_scheduler_fq), error_msg);
        printf("  delete schedGport(0x%x)\n", gport_scheduler_fq);
    }

    /* delete scheduler  element at top of sub-tree */
    for (nbr_sched = 0; nbr_sched < C4_NBR_SCHEDULERS; nbr_sched++) {
        switch(nbr_sched) {
        case 0: gport_ucast_scheduler = c4_gport_ucast_scheduler[idx]; break;
        default: gport_ucast_scheduler = c4_gport_ucast_scheduler1[idx]; break;
        }

        snprintf(error_msg, sizeof(error_msg), "delete for SE(0x%x) failed", gport_ucast_scheduler);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_delete(unit, gport_ucast_scheduler), error_msg);
        printf("  delete schedGport(0x%x)\n", gport_ucast_scheduler);
    }

    printf("cint_dnx_e2e_composite_se.c (teardown) completed with status (%s)\n", bcm_errmsg(rc));

    c4_use_same_handles = 1;

    return BCM_E_NONE;
}

int
e2e_composite_se_verify_mode(int unit, bcm_gport_t gport, int cosq, int exp_mode)
{
    int mode, weight;


    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_get(unit, gport, cosq, &mode, &weight), "");
    if (mode != exp_mode) {
        printf("sched mode mismatch on gport (0x%x) expected(BCM_COSQ_SP%d) retreived (BCM_COSQ_SP%d)\n", gport, (exp_mode - BCM_COSQ_SP0), (mode - BCM_COSQ_SP0));
    }

    return BCM_E_NONE;
}

int
e2e_composite_se_verify_bandwidth(int unit, bcm_gport_t gport, int cosq, int exp_rate, int margin)
{
    uint32 kbits_sec_min, kbits_sec_max, flags;
    char error_msg[200]={0,};


    snprintf(error_msg, sizeof(error_msg), "failed on gport (0x%x)", gport);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_get(unit, gport, cosq, &kbits_sec_min, &kbits_sec_max, &flags), error_msg);
    if ( (kbits_sec_max < (exp_rate - margin)) ||
            (kbits_sec_max > (exp_rate + margin)) ) {
        printf("bandwidth_get mismatch on gport (0x%x) expected(%d) retreived (%d)\n", gport, exp_rate, kbits_sec_max);
    }

    return BCM_E_NONE;
}

int
e2e_composite_se_verify_burst_size(int unit, bcm_gport_t gport, int cosq, int exp_burst_size, int margin)
{
    int max_burst;
    char error_msg[200]={0,};


    snprintf(error_msg, sizeof(error_msg), "BandwidthBurstMax on gport (0x%x) failed", gport);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_get(unit, gport, cosq, bcmCosqControlBandwidthBurstMax, &max_burst), error_msg);
    if ( (max_burst < (exp_burst_size - margin)) || (max_burst > (exp_burst_size + margin)) ) {
        printf("control_get-BandwidthBurstMax mismatch on Sched (0x%x) expected(%d) retreived (%d)\n", gport, exp_burst_size, max_burst);
    }

    return BCM_E_NONE;
}

int
e2e_composite_se_verify(int unit, int kbits_sec_max_port, int port_idx)
{
    int                           idx = port_idx;
    int                           exp_mode, exp_weight, exp_margin, exp_kbits_sec_max;
    int                           cosq, slow_rate;
    bcm_gport_t                   gport_ucast_voq_connector_group;
    bcm_gport_t                   gport_ucast_queue_group;
    bcm_gport_t                   gport_scheduler_fq;
    bcm_gport_t                   gport_ucast_scheduler;
    int                           nbr_queue_groups, nbr_fq_sched, nbr_sched, nbr_sched_flw;
    bcm_cosq_scheduler_gport_params_t params_get;
    bcm_cosq_gport_info_t gport_info;
    char error_msg[200]={0,};


    printf("\nVerify Setup\n");

    exp_margin = kbits_sec_max_port /100; /* 1% error */
    BCM_IF_ERROR_RETURN_MSG(e2e_composite_se_verify_bandwidth(unit, c4_e2e_parent_gport[idx], 0, kbits_sec_max_port, exp_margin), "");

    exp_margin = kbits_sec_max_port /100; /* 1% error */
    BCM_IF_ERROR_RETURN_MSG(e2e_composite_se_verify_bandwidth(unit, c4_e2e_gport[idx], 0, kbits_sec_max_port, exp_margin), "");

    /* retrive e2e port scheduling element */
    gport_info.in_gport = c4_e2e_gport[idx];
    gport_info.cosq = 0;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_handle_get(unit, bcmCosqGportTypeSched, &gport_info), "");
    c4_e2e_gport[idx] = gport_info.out_gport;
    snprintf(error_msg, sizeof(error_msg), "failed on e2e Sched (0x%x)", c4_e2e_gport[idx]);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_get(unit, 0, c4_e2e_gport[idx], &params_get), error_msg);
    if (params_get.type != C4_DEFAULT_E2E_SCHED_TYPE) {
        printf("gport get mismatch on E2E Sched (0x%x) expected type(%d) retreived type (%d)\n", c4_e2e_gport[idx], C4_DEFAULT_E2E_SCHED_TYPE, params_get.type);
    }

    /* retreive scheduler element at top of sub-tree */
    for (nbr_sched = 0; nbr_sched < C4_NBR_SCHEDULERS; nbr_sched++) {
        switch(nbr_sched) {
        case 0: gport_ucast_scheduler = c4_gport_ucast_scheduler[idx]; break;
        default: gport_ucast_scheduler = c4_gport_ucast_scheduler1[idx]; break;
        }

        /* retreive type of scheduling element */
        snprintf(error_msg, sizeof(error_msg), "failed on Sched (0x%x)", gport_ucast_scheduler);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_get(unit, 0, gport_ucast_scheduler, &params_get), error_msg);
        if (params_get.type != C4_SCHED_CL_TYPE) {
            printf("gport get mismatch on Sched (0x%x) expected type(%d) retreived type (%d)\n", gport_ucast_scheduler, C4_SCHED_CL_TYPE, params_get.type);
        }
        if (params_get.mode != C4_SCHED_CL_MODE) {
            printf("gport get mismatch on Sched (0x%x) expected mode(%d) retreived mode (%d)\n", gport_ucast_scheduler, C4_SCHED_CL_MODE, params_get.mode);
        }
    }

    /* retreive scheduler element at top of sub-tree */
    for (nbr_sched = 0; nbr_sched < C4_NBR_SCHEDULERS; nbr_sched++) {
        switch(nbr_sched) {
        case 0:
            for (nbr_sched_flw = 0; nbr_sched_flw < C4_NBR_SCHEDULER_FLOWS; nbr_sched_flw++) {
                switch(nbr_sched_flw) {
                case 0: gport_ucast_scheduler = c4_gport_ucast_scheduler[idx];
                exp_mode = C4_SCHEDULER0_CIR_MODE;
                exp_kbits_sec_max = C4_SCHED_CIR_KBITS_SEC_MAX;
                exp_margin = C4_SCHED_CIR_KBITS_SEC_MAX_MARGIN; break;
                default: gport_ucast_scheduler = c4_gport_ucast_scheduler_sf2[idx];
                exp_mode = C4_SCHEDULER0_EIR_MODE;
                exp_kbits_sec_max = C4_SCHED_EIR_KBITS_SEC_MAX;
                exp_margin = C4_SCHED_EIR_KBITS_SEC_MAX_MARGIN; break;
                }

                /* retreive SE scheduling discipline */
                BCM_IF_ERROR_RETURN_MSG(e2e_composite_se_verify_mode(unit, gport_ucast_scheduler, 0, exp_mode), "");

                /* retreive rate of Scheduler */
                BCM_IF_ERROR_RETURN_MSG(e2e_composite_se_verify_bandwidth(unit, gport_ucast_scheduler, 0, exp_kbits_sec_max, exp_margin), "");

                /* retreive scheduler burst size */
                BCM_IF_ERROR_RETURN_MSG(e2e_composite_se_verify_burst_size(unit, gport_ucast_scheduler, 0, C4_SCHED_MAX_BURST, C4_SCHED_MAX_BURST_MARGIN), "");
            }
            break;

        default:
            for (nbr_sched_flw = 0; nbr_sched_flw < C4_NBR_SCHEDULER_FLOWS; nbr_sched_flw++) {
                switch(nbr_sched_flw) {
                case 0: gport_ucast_scheduler = c4_gport_ucast_scheduler1[idx];
                exp_mode = C4_SCHEDULER1_CIR_MODE;
                exp_kbits_sec_max = C4_SCHED_CIR_KBITS_SEC_MAX;
                exp_margin = C4_SCHED_CIR_KBITS_SEC_MAX_MARGIN; break;
                default: gport_ucast_scheduler = c4_gport_ucast_scheduler1_sf2[idx];
                exp_mode = C4_SCHEDULER1_EIR_MODE;
                exp_kbits_sec_max = C4_SCHED_EIR_KBITS_SEC_MAX;
                exp_margin = C4_SCHED_EIR_KBITS_SEC_MAX_MARGIN; break;
                }

                /* retreive SE scheduling discipline */
                BCM_IF_ERROR_RETURN_MSG(e2e_composite_se_verify_mode(unit, gport_ucast_scheduler, 0, exp_mode), "");

                /* retreive rate of Scheduler */
                BCM_IF_ERROR_RETURN_MSG(e2e_composite_se_verify_bandwidth(unit, gport_ucast_scheduler, 0, exp_kbits_sec_max, exp_margin), "");

                /* retreive scheduler burst size */
                BCM_IF_ERROR_RETURN_MSG(e2e_composite_se_verify_burst_size(unit, gport_ucast_scheduler, 0, C4_SCHED_MAX_BURST, C4_SCHED_MAX_BURST_MARGIN), "");
            }
            break;
        }
    }

    /* Reference other scripts for verification of remaining hierarchy */

    printf("cint_dnx_e2e_composite_se.c (verify) completed with status (%s)\n", bcm_errmsg(BCM_E_NONE));

    return BCM_E_NONE;
}

