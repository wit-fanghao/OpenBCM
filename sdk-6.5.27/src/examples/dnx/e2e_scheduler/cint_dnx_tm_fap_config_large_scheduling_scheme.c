/*
 * 
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * File:        cint_dnx_tm_fap_config_large_scheduling_scheme.c
 * Purpose:     Example of E2E scheduler configuration where resource management is by SDK
 *
 * The example shows how to configure:
 *     - Egress port scheduler with 2 HR's.
 *     - 3 levels of Composite CL schedulers.
 *     - CIR and EIR shaping.
 *     - Independent WFQ
 *
 * Usage:
 *     1. To setup the full TM hierarchy, call the following function from cint:
 *        cint_tm_setup_full();
 *
 *     2. To change rate of an egress port:
 *        cint_change_port_rate(unit,port_num,rate);
 *
 *     3. To change CIR/EIR rate of a SE:
 *        cint_change_se_rate(unit,level,index,cir,eir);
 *
 *     4. To change weight of SE:
 *        cint_change_se_weight(unit,level,index,eir_weight);
 *
 *     5. To change rate of a VOQ:
 *        cint_change_vc_rate(unit,voq_bundle,cos,rate);
 *
 *     6. To change weight of VOQ:
 *        cint_change_vc_weight(unit,voq_bundle,cos,eir_weight);
 */



/* Environment
 *    - Default Egress queue mapping disabled.
 *    - Default Egress Port Scheduler hierarchy disabled.
 *
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                              |
|                                                                   +              +                                                                                           |
|                                                                   |              |                                                                                           |
|                                                                  10G            10G                                                                                          |
|                                                                   +              +                                                                                           |
|                                                                +--v--+        +--v--+                                                                                        |
|                                                                | HR1 |        | HR4 |                                                                                        |
|                                                                +-----+        +--+--+                                                                                        |
|                                                         CIR - 1.6G|              |  CIR - 1.6G                                                                               |
|                                                         EIR - 8.4G|              |  EIR - 8.4G                                                                               |
|                                                                   |              |                                                                                           |
|                                        +-----------------------------------------+--------------------------------------+                                                    |
|                                        |                          |                                                     |                                                    |
|                         +-----------------------------------------+--------------------------------------+              |                                                    |
|                         |              |                                                                 |              |                                                    |
|                         |              |                                                                 |              |                                                    |
|                       +-v--------------v-+                                                             +-v--------------v-+                                                  |
|                       |       CL         | ...x18                                                      |        CL        |   ...x18                    (x18)                |
|                       +--+------------+--+                                                             +--+------------+--+                                                  |
|                          |            |                                                                   |            |                                                     |
|                   +------+            +----------+                                                 +------+            +----------+                                          |
|        CIR + 65M  |                              | CIR + 65M                            CIR + 65M  |                              | CIR + 65M                                |
|        EIR + 940M |                              | EIR + 940M                           EIR + 940M |                              | EIR + 940M                               |
|                   |                              |                                                 |                              |                                          |
|       +-----------v----------+               +---v------------------+                    +---------v------------+             +---v------------------+                       |
|       |         CL           | ...x18        |         CL           | ...x18             |         CL           | ...x18      |         CL           |    ...x18             |
|       +-----+----------+-----+               +-----+----------+-----+                    +-----+----------+-----+             +-----+----------+-----+                       |
|             |          |                           |          |                                |          |                         |          |                             |
|             |          |                           |          |                                |          |                         |          |                             |
|             |          |                           |          |                                |          |                         |          |                             |
|             |          |                           |          |                                |          |                         |          |                             |
|  CIR + 10M  |          |                CIR + 10M  |          |                     CIR + 10M  |          |              CIR + 10M  |          |                             |
|  EIR + 990M |          |                EIR + 990M |          |                     EIR + 990M |          |              EIR + 990M |          |                             |
|             |          |                           |          |                                |          |                         |          |                             |
|          +--v--+    +--v--+                     +--v--+    +--v--+                          +--v--+    +--v--+                   +--v--+    +--v--+                          |
|          | CL  |    | CL  |                     | CL  |    | CL  |                          | CL  |    | CL  |                   | CL  |    | CL  |                          |
|          +--+--+    +--+--+                     +--+--+    +--+--+                          +--+--+    +--+--+                   +--+--+    +--+--+                          |
|             |          |                           |          |                                |          |                         |          |                             |
|             |          |   ...x6                   |          |   ...x6                        |          |   ...x6                 |          |   ...x6                     |
|             |          |                           |          |                                |          |                         |          |                             |
|          |  v  |    |  v  |                     |  v  |    |  v  |                          |  v  |    |  v  |                   |  v  |    |  v  |                          |
|          | NO  |    | NO  |                     | NO  |    | NO  |                          | NO  |    | NO  |                   | NO  |    | NO  |                          |
|          |LIMIT|    |LIMIT|                     |LIMIT|    |LIMIT|                          |LIMIT|    |LIMIT|                   |LIMIT|    |LIMIT|                          |
|          |     |    |     |                     |     |    |     |                          |     |    |     |                   |     |    |     |                          |
|          +-----+    +-----+                     +-----+    +-----+                          +-----+    +-----+                   +-----+    +-----+                          |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
 *  ALL VOQs are with a bundle of 4
 *  All CL are in mode - 2SP, last WFQ!
 *
 */

/**** Define global variables to make them accessible from CINT *********/

int          PORT_NUM_BASE = 13;  /* CGE-1*/
int          NUMBER_OF_PORTS = 1;/* when opening more than one port: can open enough CLs*/
int          HR_PER_PORTS = 8; /*Assume port priority to be 8*/
int          L4_NUM_ELEMENTS = 18;
int          L3_NUM_ELEMENTS = 18;
int          L2_NUM_ELEMENTS = 6;
int          EIR_SP_MODE[3] = {BCM_COSQ_SP1, BCM_COSQ_SP1, BCM_COSQ_SP3};
int          L4_EIR_WEIGHT[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int          L3_EIR_WEIGHT[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int          L2_EIR_WEIGHT[] = {1, 1, 1, 1, 1, 1};

int          UNIT_1K = 1000;
int          CREDIT_ADJUST = -13;

/* Units for all below rates and burst sizes are in Kbps */
int PORT_RATE    = 100 * UNIT_1K * UNIT_1K;

int L4_CIR_RATE  = 1660 * UNIT_1K;
int L4_EIR_RATE  = 8340 * UNIT_1K;
int L4_CIR_BURST = 4000;
int L4_EIR_BURST = 4000;

int L3_CIR_RATE  = 65 * UNIT_1K;
int L3_EIR_RATE  = 935 * UNIT_1K;
int L3_CIR_BURST = 4000;
int L3_EIR_BURST = 4000;

int L2_CIR_RATE  = 10 * UNIT_1K;
int L2_EIR_RATE  = 990 * UNIT_1K;
int L2_CIR_BURST = 4000;
int L2_EIR_BURST = 4000;

/** Practically these VOQ rates are not used.
 * In the traffic test are passed streams with TCs bigger than 2!*/
int VOQ_RATE[2]       = {1900, 3900};
int VOQ_COS_SP[4]     = {BCM_COSQ_SP0, BCM_COSQ_SP1, BCM_COSQ_SP1, BCM_COSQ_SP1};
int VOQ_COS_WEIGHT[4] = {0, 1, 3, 9};
int VOQ_MAX_BURST     = 3000;



/* CINT does not support multi-dimensional array.*/

bcm_gport_t  hr_info_gport_arr[(NUMBER_OF_PORTS*HR_PER_PORTS)];
bcm_gport_t  level4_gport_arr[(NUMBER_OF_PORTS*L4_NUM_ELEMENTS)];
bcm_gport_t  level3_gport_arr[(NUMBER_OF_PORTS*L4_NUM_ELEMENTS*L3_NUM_ELEMENTS)];
bcm_gport_t  level2_gport_arr[(NUMBER_OF_PORTS*L4_NUM_ELEMENTS*L3_NUM_ELEMENTS*L2_NUM_ELEMENTS)];
bcm_gport_t  voq_gport_arr[(NUMBER_OF_PORTS*L4_NUM_ELEMENTS*L3_NUM_ELEMENTS*L2_NUM_ELEMENTS)];



/*
    Configure a Composite SE.
    [1] Create a gport. The driver creates two gpors: one for CIR and another for EIR.
    [2] Configure CIR and CBS on the CIR flow (gport).
    [3] Configure EIR and EBS on the EIR flow (gport).
    [4] Configure SP scheduling mode for cir
    [5] Configure WFQ scheduling mode and weigth for cir
 */

int cint_composite_sched_config (int unit,
        int port,
        int flags,
        int cir_rate,
        int eir_rate,
        int cir_burst,
        int eir_burst,
        int eir_mode,
        int eir_weight,
        bcm_gport_t *cir_gport)
{
    bcm_gport_t eir_gport, dest_gport;
    bcm_cosq_gport_info_t gport_info;
    uint32 dummy_flags;
    bcm_port_interface_info_t interface_info;
    bcm_port_mapping_info_t mapping_info;
    bcm_cosq_scheduler_gport_params_t params;
    char error_msg[200]={0,};

    BCM_IF_ERROR_RETURN_MSG(bcm_port_get(unit, port, &dummy_flags, &interface_info, &mapping_info), "");
    BCM_GPORT_LOCAL_SET(dest_gport, port);

    params.type = bcmCosqSchedulerGportTypeClass2SpWfq;
    params.mode = bcmCosqSchedulerGportModeComposite;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeIndependent;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, 0, params, cir_gport), "");
    /*
        The gport of the EIR flow is created as a sub-flow of CIR flow by driver.
        The user just retrieves it.
     */
    gport_info.cosq=0;
    gport_info.in_gport = *cir_gport;
    bcm_cosq_gport_handle_get(unit, bcmCosqGportTypeCompositeFlow2,&gport_info);
    eir_gport = gport_info.out_gport;

    if (cir_rate > 0) {
        snprintf(error_msg, sizeof(error_msg), "cir_gport=0x%x", *cir_gport);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit, *cir_gport, 0, 0,
                cir_rate, 0), error_msg);

        snprintf(error_msg, sizeof(error_msg), "cir_gport=0x%x", *cir_gport);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit, *cir_gport, 0,
                bcmCosqControlBandwidthBurstMax, cir_burst), error_msg);
    }

    if (eir_rate > 0) {
        snprintf(error_msg, sizeof(error_msg), "eir_gport=0x%x", eir_gport);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit, eir_gport, 0, 0,
                eir_rate, 0), error_msg);

        snprintf(error_msg, sizeof(error_msg), "eir_gport=0x%x", eir_gport);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit, eir_gport, 0,
                bcmCosqControlBandwidthBurstMax, eir_burst), error_msg);
    }

    snprintf(error_msg, sizeof(error_msg), "cir_gport=0x%x", *cir_gport);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit, *cir_gport, 0,
            BCM_COSQ_SP0, 0), error_msg);

    snprintf(error_msg, sizeof(error_msg), "eir_gport=0x%x", eir_gport);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit, eir_gport, 0,
            eir_mode, eir_weight), error_msg);

    return BCM_E_NONE;
}


int get_nif_port_bmp(int unit,
        int port_base,
        bcm_pbmp_t* port_bmp,
        int* num_of_ports)
{
    bcm_port_config_t       port_config;
    bcm_pbmp_t              port_set;
    int                     port,port_index,num_of_ports_get;
    BCM_PBMP_CLEAR(port_bmp);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_config_get(unit, &port_config), "");

    BCM_PBMP_OR(port_bmp,port_config.sfi); /* fabric_links */
    BCM_PBMP_OR(port_bmp,port_config.cpu); /* CPU */
    BCM_PBMP_NEGATE(port_bmp, port_bmp);
    BCM_PBMP_AND(port_bmp,port_config.all); /* All - fabric_links - CPU = Ports in system (no CPU)*/
    BCM_PBMP_COUNT(port_bmp,num_of_ports_get);
    if ((*num_of_ports <= 0) || (*num_of_ports >= num_of_ports_get))
    {
        *num_of_ports=num_of_ports_get;
    }
    else
    {
        port_base=(port_base>0)?num_of_ports_get:0;
        port_index=0;
        BCM_PBMP_CLEAR(port_set);
        BCM_PBMP_ITER(port_bmp,port) {
            if (port<port_base)
            {
                continue;
            }
            if(port_index==*num_of_ports)
            {
                break;
            }
            BCM_PBMP_PORT_ADD(&port_set, port);
            port_index++;
        }
        *port_bmp=port_set;
    }
    return BCM_E_NONE;
}

/*
    Main function to configure the whole TM hierarchy.
 */
/**
 * cint_dnx_tm_fap_config_large_scheduling_scheme.c expects that all regions for the schedulers allocated are with nof_remote_cores=1
 * This can be set with the following soc property:
 * dtm_flow_nof_remote_cores_region_X=1
 */

int cint_tm_setup(int unit,
        int port_base,
        int num_ports,
        int num_l4_se,
        int num_l3_se,
        int num_l2_se)
{
    bcm_module_t my_modid =0;
    int          voq_base = 32;

    int CREDIT_OVER_SUBSCRIBE = 1; /* percent*/

    double dbl;
    int se_index;
    bcm_gport_t parent_gport, cir_gport=0, eir_gport=0, gsrc_port=0;
    bcm_gport_t vc_group=0, gloc_port=0;
    bcm_gport_t system_port_gport=0, portmod_gport=0, flow_voq_gport=0;
    bcm_gport_t gucast_queue_group=0, gvoq_connector=0, gvoq_base=0,ge2e=0;
    bcm_cosq_voq_connector_gport_t voq_connector;
    int core = 0, connector_id;
    bcm_cosq_gport_info_t       gport_info;
    bcm_cosq_gport_connection_t connection;
    int remote_credit_size;
    uint32 port_flags;
    bcm_port_interface_info_t interface_info;
    bcm_port_mapping_info_t mapping_info;
    bcm_cosq_ingress_queue_bundle_gport_config_t conf;
    bcm_port_resource_t resource;
    int delay_tolerance_level, rate_class;

    int credit_worth = *(dnxc_data_get(unit, "iqs", "credit", "worth", NULL));
    int legacy_credit_worth = 1024;
    int multiplier = (credit_worth / legacy_credit_worth);
    char error_msg[200]={0,};
    L4_CIR_BURST *= multiplier;
    L4_EIR_BURST *= multiplier;
    L3_CIR_BURST *= multiplier;
    L3_EIR_BURST *= multiplier;
    L2_CIR_BURST *= multiplier;
    L2_EIR_BURST *= multiplier;
    VOQ_MAX_BURST *= multiplier;

    int port,port_index, prio, l4_index, l3_index,voq_index, cos,se_elem, flags, flags2;
    unsigned int uflags;
    bcm_cosq_gport_info_t gport_info_porttc, gport_info_hr;
    bcm_pbmp_t port_set;
    /*int CARD_NUM_OF_PORTS;*/
    /*if (port_base != -1) PORT_NUM_BASE   = port_base;*/
    /*if (num_ports != -1) NUMBER_OF_PORTS = num_ports;*/
    /*get_nif_port_bmp practically will always return 13 for port_set and 1 for num_ports*/
    BCM_PBMP_CLEAR(port_set);
    BCM_PBMP_PORT_ADD(&port_set, port_base);
    num_ports = 1;


    NUMBER_OF_PORTS = num_ports;
    if (num_l4_se != -1) L4_NUM_ELEMENTS = num_l4_se;
    if (num_l3_se != -1) L3_NUM_ELEMENTS = num_l3_se;
    if (num_l2_se != -1) L2_NUM_ELEMENTS = num_l2_se;

    printf ("------------------------------------------------\n");
    printf ("Setting Scheduling Hirarchy: num_ports=%d l4_se=%d l3_se=%d l2_se=%d\n\n",
            NUMBER_OF_PORTS,L4_NUM_ELEMENTS, L3_NUM_ELEMENTS, L2_NUM_ELEMENTS);


    /* Build an array of GPORTS of HRs.
       Each HR represents priority of specific port.
       These HRs are used to connect the aggregation level to the port.
     */
    port_index=0;
    BCM_PBMP_ITER(port_set, port) {
        /* Create GPORT for locoal port*/
        BCM_GPORT_LOCAL_SET(gloc_port, port);

        /* Get GPORT of Port TC of the designated local port*/
        gport_info_porttc.cosq = 0;
        gport_info_porttc.in_gport = gloc_port;

        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_handle_get(unit, bcmCosqGportTypeE2EPortTC,
                &gport_info_porttc), "");

        /* Get GPORT of HR */
        gport_info_hr.in_gport = gport_info_porttc.out_gport;
        snprintf(error_msg, sizeof(error_msg), "unit(%d), failed to get port(%d) info", unit, port);
        BCM_IF_ERROR_RETURN_MSG(bcm_port_get(unit, port, &uflags, &interface_info, &mapping_info), error_msg);

        for (prio=0; prio < mapping_info.num_priorities; prio++) {
            gport_info_hr.cosq = prio;
            snprintf(error_msg, sizeof(error_msg), "failed for bcmCosqGportTypeSched prio=%d", prio);
            BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_handle_get(unit, bcmCosqGportTypeSched,
                    &gport_info_hr), error_msg);
            hr_info_gport_arr[(port_index)*HR_PER_PORTS+prio] = gport_info_hr.out_gport;
        }

        /* Get a handler to the E2E Port-Scheduler*/
        BCM_COSQ_GPORT_E2E_PORT_SET(&ge2e, &port);

        /* Set shaper rate */
        snprintf(error_msg, sizeof(error_msg), "failed for port %d prio=%d", ge2e, prio);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit, ge2e, 0, 0,
                PORT_RATE, 0), error_msg);
        port_index++;
    }

    /* Build level 4:
       [1] Greate a GPORT of a composite CL of type SP (only 2 SP's are used).
       [2] CIR gport is attached to SP1
       [3] EIR gport is attached to SP2
       [4] Define the connection point on the "father" HR
       [5] connect the CL to the "father" (credit source).
     */

    printf ("\n**** Level 4****\n");
    dbl = L4_CIR_RATE + L4_EIR_RATE;
    printf ("CR Rate: %3.3f Mbits, SE Elements: %d\n", (dbl/UNIT_1K), L4_NUM_ELEMENTS);

    /* The following flags are used for L4 and L3 SE's */
    flags = (BCM_COSQ_GPORT_SCHEDULER |
            BCM_COSQ_GPORT_SCHEDULER_CLASS_MODE4_2SP_WFQ |
            BCM_COSQ_GPORT_SCHEDULER_CLASS_WFQ_MODE_INDEPENDENT |
            BCM_COSQ_GPORT_COMPOSITE);
    port_index=0;
    BCM_PBMP_ITER(port_set,port) {
        for (se_elem = 0; se_elem < L4_NUM_ELEMENTS; se_elem++) {

            snprintf(error_msg, sizeof(error_msg), "Configuring L4 SE %d ERROR: port=%d l4=%d",
                (port_index)*L4_NUM_ELEMENTS + se_elem,
                port, se_elem);
            BCM_IF_ERROR_RETURN_MSG(cint_composite_sched_config (unit, port, flags, L4_CIR_RATE,
                    L4_EIR_RATE, L4_CIR_BURST, L4_EIR_BURST,
                    EIR_SP_MODE[4-2], L4_EIR_WEIGHT[se_elem], &cir_gport), error_msg);

            gport_info.cosq=0;
            gport_info.in_gport = cir_gport;
            bcm_cosq_gport_handle_get(unit, bcmCosqGportTypeCompositeFlow2,
                    &gport_info);
            eir_gport = gport_info.out_gport;

            snprintf(error_msg, sizeof(error_msg), "failed for SP0 cir_gport=0x%x", cir_gport);
            BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit,
                    hr_info_gport_arr[(port_index)*HR_PER_PORTS+0],
                    cir_gport, 0), error_msg);

            snprintf(error_msg, sizeof(error_msg), "failed for SP1 eir_gport=0x%x", eir_gport);
            BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit,
                    hr_info_gport_arr[(port_index)*HR_PER_PORTS+1],
                    eir_gport, 0), error_msg);
            level4_gport_arr[(port_index)*L4_NUM_ELEMENTS + se_elem] = cir_gport;
        }
        port_index++;
    }

    /* Build level 3 SE:
       [1] Greate a GPORT of a composite CL of type single WFQ.
       [2] get EIR gport
       [3] Set the shaper of the CIR, and disable the shaper of the EIR.
       [4] Define the connection point on the "father" level4 element
       [5] connect the CL to the "father" (credit source).
     */

    printf ("\n**** Level 3 ****\n");
    dbl = L3_CIR_RATE + L3_EIR_RATE;
    printf ("CR Rate: %3.3f Mbits, SE Elements: %d\n", (dbl/UNIT_1K), L3_NUM_ELEMENTS);
    port_index=0;
    BCM_PBMP_ITER(port_set,port) {
        for (l4_index = 0; l4_index < L4_NUM_ELEMENTS; l4_index++) {
            for (se_elem = 0; se_elem < L3_NUM_ELEMENTS; se_elem++) {

                se_index = (port_index)*L4_NUM_ELEMENTS*L3_NUM_ELEMENTS  +
                        l4_index*L3_NUM_ELEMENTS + se_elem;

                snprintf(error_msg, sizeof(error_msg), "Configuring L3 SE %d ERROR: port=%d l4=%d l3=%d",
                    se_index, port, l4_index, se_elem);
                BCM_IF_ERROR_RETURN_MSG(cint_composite_sched_config (unit, port, flags, L3_CIR_RATE,
                        L3_EIR_RATE, L3_CIR_BURST, L3_EIR_BURST,
                        EIR_SP_MODE[3-2], L3_EIR_WEIGHT[se_elem], &cir_gport), error_msg);

                gport_info.cosq=0;
                gport_info.in_gport = cir_gport;
                bcm_cosq_gport_handle_get (unit, bcmCosqGportTypeCompositeFlow2,
                        &gport_info);
                eir_gport = gport_info.out_gport;

                parent_gport = level4_gport_arr[l4_index];

                snprintf(error_msg, sizeof(error_msg), "failed for CIR se_index=%d", se_index);
                BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, parent_gport, cir_gport, 0), error_msg);

                snprintf(error_msg, sizeof(error_msg), "failed for EIR se_index=%d", se_index);
                BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, parent_gport,
                        eir_gport, 0), error_msg);

                level3_gport_arr[se_index] = cir_gport;
            }
        }
        port_index++;
    }

    /* Build level 2:
       [1] Greate a GPORT of a composite CL of type 3 SPs with single last WFQ.
       [2] Define the connection point on the "father" level3 element
       [3] CIR gport is attached to SP1 of father SE
       [4] EIR gport is attached to SP2 of father SE
       [5] connect the CL to the "father" (credit source).
     */

    printf ("\n**** Level 2 ****\n");
    dbl = L2_CIR_RATE+L2_EIR_RATE;
    printf ("CR Rate: %3.3f Mbits, SE Elements: %d\n", (dbl/UNIT_1K), L2_NUM_ELEMENTS);

    flags = (BCM_COSQ_GPORT_SCHEDULER |
            BCM_COSQ_GPORT_SCHEDULER_CLASS_MODE4_2SP_WFQ |
            BCM_COSQ_GPORT_SCHEDULER_CLASS_WFQ_MODE_INDEPENDENT |
            BCM_COSQ_GPORT_COMPOSITE);
    port_index=0;
    BCM_PBMP_ITER(port_set,port) {
        for (l4_index = 0; l4_index < L4_NUM_ELEMENTS; l4_index++) {
            for (l3_index = 0; l3_index < L3_NUM_ELEMENTS; l3_index++) {
                for (se_elem=0; se_elem < L2_NUM_ELEMENTS; se_elem++) {

                    se_index = (port_index)*L4_NUM_ELEMENTS*L3_NUM_ELEMENTS*L2_NUM_ELEMENTS +
                            l4_index*L3_NUM_ELEMENTS*L2_NUM_ELEMENTS +
                            l3_index*L2_NUM_ELEMENTS + se_elem;

                    snprintf(error_msg, sizeof(error_msg), "Configuring L2 SE %d ERROR: port=%d l4=%d l3=%d l2=%d",
                        se_index, port, l4_index, l3_index, se_elem);
                    BCM_IF_ERROR_RETURN_MSG(cint_composite_sched_config (unit, port, flags,
                            L2_CIR_RATE, L2_EIR_RATE, L2_CIR_BURST,
                            L2_EIR_BURST, EIR_SP_MODE[2-2],
                            L2_EIR_WEIGHT[se_elem], &cir_gport), error_msg);

                    gport_info.cosq=0;
                    gport_info.in_gport = cir_gport;
                    snprintf(error_msg, sizeof(error_msg), "failed for EIR se_index=%d", se_index);
                    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_handle_get(unit,
                            bcmCosqGportTypeCompositeFlow2,
                            &gport_info), error_msg);
                    eir_gport = gport_info.out_gport;

                    parent_gport = level3_gport_arr[(port_index)*L4_NUM_ELEMENTS +
                                                    l4_index*L3_NUM_ELEMENTS + l3_index];

                    snprintf(error_msg, sizeof(error_msg), "failed for CIR se_index=%d", se_index);
                    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, parent_gport,
                            cir_gport, 0), error_msg);
                    snprintf(error_msg, sizeof(error_msg), "failed for EIR se_index=%d", se_index);
                    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, parent_gport,
                            eir_gport, 0), error_msg);

                    level2_gport_arr[se_index] = cir_gport;
                }
            }
        }
        port_index++;
    }

    /*
         Create VOQ connectors and VOQs
     */

    /* VOQ connector flags */
    flags  = BCM_COSQ_GPORT_VOQ_CONNECTOR | BCM_COSQ_VOQ_CONNECTOR_GPORT_F_WITH_ID;

    /* VOQ flags */
    flags2 = BCM_COSQ_GPORT_UCAST_QUEUE_GROUP |  BCM_COSQ_GPORT_WITH_ID;

    printf ("\n**** SET VOQs and VOQ connectors from dnx****\n");
    port_index=0;
    BCM_PBMP_ITER(port_set,port) {
        /* create gport  */
        BCM_GPORT_LOCAL_SET(portmod_gport, port);
        /* encapsulate sys port id to gport */
        BCM_GPORT_SYSTEM_PORT_ID_SET(system_port_gport,(my_modid * 100) + port);

        snprintf(error_msg, sizeof(error_msg), "system_port_gport=0x%x portmod_gport=0x%x", system_port_gport, portmod_gport);
        BCM_IF_ERROR_RETURN_MSG(bcm_stk_sysport_gport_set(unit, system_port_gport, portmod_gport), error_msg);

        for (l4_index = 0; l4_index < L4_NUM_ELEMENTS; l4_index++) {

            printf("Configuring VOQ[%d:%d:%d:%d]: voq_index=%d flow_id=0x%x\n",
                    port, l4_index, 0, 0,
                    (port_index)*L4_NUM_ELEMENTS*L3_NUM_ELEMENTS*L2_NUM_ELEMENTS +
                    l4_index* L3_NUM_ELEMENTS*L2_NUM_ELEMENTS,
                    (((port_index)*L4_NUM_ELEMENTS*L3_NUM_ELEMENTS*L2_NUM_ELEMENTS +
                            l4_index* L3_NUM_ELEMENTS*L2_NUM_ELEMENTS) * 4) + voq_base);

            for (l3_index = 0; l3_index < L3_NUM_ELEMENTS; l3_index++) {
                for (se_elem = 0; se_elem < L2_NUM_ELEMENTS; se_elem++) {

                    voq_index = (port_index)*L4_NUM_ELEMENTS*L3_NUM_ELEMENTS*L2_NUM_ELEMENTS +
                            l4_index* L3_NUM_ELEMENTS*L2_NUM_ELEMENTS +
                            l3_index* L2_NUM_ELEMENTS + se_elem;
                    /* create VOQ connector for a VOQ bundle */
                    connector_id = (voq_index * 4) + voq_base;

                    BCM_COSQ_GPORT_VOQ_CONNECTOR_CORE_SET(vc_group,
                            connector_id, mapping_info.core);

                    voq_connector.flags = flags;
                    voq_connector.port = portmod_gport;
                    voq_connector.nof_remote_cores = 1;
                    voq_connector.remote_modid = my_modid + mapping_info.core;
                    voq_connector.numq = 4;
                    snprintf(error_msg, sizeof(error_msg), "vc_group=0x%x", vc_group);
                    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_voq_connector_gport_add(unit, voq_connector, &vc_group), error_msg);

                    /* set VOQ connector shaper */
                    for (cos = 0; cos < 2; cos++) {
                        snprintf(error_msg, sizeof(error_msg), "vc_group=0x%x", vc_group);
                        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit, vc_group, cos,
                                0, VOQ_RATE[cos], 0), error_msg);

                        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit, vc_group, cos,
                                bcmCosqControlBandwidthBurstMax,
                                VOQ_MAX_BURST), error_msg);
                    }

                    for (cos = 0; cos < 4; cos++) {
                        snprintf(error_msg, sizeof(error_msg), "vc_group=0x%x cos=%d", vc_group, cos);
                        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit, vc_group, cos,
                                VOQ_COS_SP[cos], VOQ_COS_WEIGHT[cos]), error_msg);

                        /* set slow disable for voq */
                        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit, vc_group, cos,
                                bcmCosqControlFlowSlowRate,
                                0), error_msg);

                        /* attach VOQ connector to level 2 CL */
                        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit,
                                level2_gport_arr[voq_index],
                                vc_group, cos), error_msg);
                    }

                    /*
                       [1] Create VOQ GPORT
                       [2] Assotiate the VOQ with the system port
                     */
                    /** For Jericho2 only Symetric mode is supported */
                    core = BCM_CORE_ALL;
                    BCM_GPORT_UNICAST_QUEUE_GROUP_CORE_QUEUE_SET(gvoq_base, core,
                            (voq_index * 4) + voq_base);
                    BCM_IF_ERROR_RETURN_MSG(bcm_port_resource_get(unit, port, &resource), "");
                    BCM_IF_ERROR_RETURN_MSG(appl_dnx_e2e_voq_profiles_get(unit, resource.speed, &delay_tolerance_level, &rate_class), "");
                    conf.flags = flags2;
                    conf.port = system_port_gport;
                    conf.numq = 4;
                    conf.local_core_id = BCM_CORE_ALL;
                    for (cos = 0; cos < 4; cos++) {
                        conf.queue_atrributes[cos].delay_tolerance_level = delay_tolerance_level;
                        conf.queue_atrributes[cos].rate_class = rate_class;
                    }
                    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_ingress_queue_bundle_gport_add(unit, &conf, &gvoq_base), "");
                    /** bcm_cosq_ingress_queue_bundle_gport_add will return a gport with core == BCM_CORE_ALL
                     * In order to be complient with the asymmetric scheme created
                     * the VOQ gport BCM_CORE_ALL should be replaced with the relevant core */
                    BCM_GPORT_UNICAST_QUEUE_GROUP_CORE_QUEUE_SET(gvoq_base, mapping_info.core,
                            (voq_index * 4) + voq_base);

                    if (voq_index < sizeof(voq_gport_arr)/sizeof(voq_gport_arr[0]))
                        voq_gport_arr[voq_index] = gvoq_base;

                    /* Egress side: connect VOQ to voq connector */

                    connection.flags = BCM_COSQ_GPORT_CONNECTION_EGRESS;
                    connection.remote_modid = my_modid + mapping_info.core;
                    connection.voq = gvoq_base;
                    connection.voq_connector = vc_group;
                    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), "");

                    /* Ingress side: connect VOQ to VOQ-connector */

                    connection.flags = BCM_COSQ_GPORT_CONNECTION_INGRESS;
                    connection.remote_modid = my_modid + mapping_info.core;
                    connection.voq = gvoq_base;
                    connection.voq_connector = vc_group;

                    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), "");
                }
            }
        }
        printf  ("\n" );
        port_index++;
    }

    /* Enable traffic. This step can be done any time after bcm and soc are initialized  */
    BCM_IF_ERROR_RETURN_MSG(bcm_stk_module_enable(unit, my_modid, NUMBER_OF_PORTS, 1), "");
    return BCM_E_NONE;
}


/* Change the BW of the egress port.
   unit: 0
   port: egress port number.
   rate: unit is in kbps.
 */

int cint_change_port_rate (int  unit,
        int  port,
        int  rate)
{
    bcm_gport_t  ge2e;
    char error_msg[200]={0,};

    /* Get a handler to the E2E Port-Scheduler */
    BCM_COSQ_GPORT_E2E_PORT_SET(&ge2e, &port);

    /* Set shaper rate */
    snprintf(error_msg, sizeof(error_msg), "gport=0x%x port=%d", ge2e, port);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit, ge2e, 0, 0,
            rate, 0), error_msg);
    return BCM_E_NONE;
}


/* Change the CIR/EIR BW of an SE.

   unit: 0
   level: user=2, port=3, LM=4
   Index: 0 - 1st user/port/LM ... 5/23/23 - last user/port/LM
   cir_rate: unit is kbps.
             To change only EIR, set cir_rate to -1.
             Setting rate=0 will disable rate shaping (unlimited).
   eir_rate: unit is kbps.
             To change only CIR, set eir_rate to -1.
             Setting rate=0 will disable rate shaping (unlimited).
 */

int cint_change_se_rate (int  unit,
        int  level,
        int  index,
        int  cir_rate,
        int  eir_rate)
{
    bcm_gport_t            cir_gport;
    bcm_cosq_gport_info_t  gport_info;
    bcm_gport_t            *gport_p[] = {level2_gport_arr,
            level3_gport_arr,
            level4_gport_arr};
    char error_msg[200]={0,};

    /* default to level2 if level is invalid. */
    cir_gport = gport_p[(level >= 2 && level <= 4) ? (level-2):0][index];

    if (cir_rate != -1) {
        snprintf(error_msg, sizeof(error_msg), "cir_gport=0x%x", cir_gport);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit, cir_gport,
            0, 0, cir_rate, 0), error_msg);
    }

    gport_info.cosq = 0;
    gport_info.in_gport = cir_gport;
    bcm_cosq_gport_handle_get(unit, bcmCosqGportTypeCompositeFlow2, &gport_info);

    if (eir_rate != -1) {
        snprintf(error_msg, sizeof(error_msg), "eir_gport=0x%x", gport_info.out_gport);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit, gport_info.out_gport,
            0, 0, eir_rate, 0), error_msg);
    }

    return BCM_E_NONE;
}



/* unit: 0
   level: user=2, port=3, LM=4
   Index: 0 - 1st user/port/LM ... 5/23/23 - last user/port/LM
   eir_weigth: unit is 1..63. The lower weight gets the higher rate.
 */

int cint_change_se_weight (int  unit,
        int  level,
        int  index,
        int  eir_weight)
{
    bcm_gport_t            cir_gport;
    bcm_cosq_gport_info_t  gport_info;
    bcm_gport_t            *gport_p[] = {level2_gport_arr,
            level3_gport_arr,
            level4_gport_arr};
    char error_msg[200]={0,};

    /* default to level2 if level is invalid. */
    if (level < 2 || level > 4) level = 2;
    cir_gport = gport_p[level-2][index];

    gport_info.cosq = 0;
    gport_info.in_gport = cir_gport;
    bcm_cosq_gport_handle_get(unit, bcmCosqGportTypeCompositeFlow2, &gport_info);

    snprintf(error_msg, sizeof(error_msg), "failed for EIR eir_gport=0x%x", eir_gport);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit, gport_info.out_gport, 0,
            EIR_SP_MODE[level-2], eir_weight), error_msg);

    return BCM_E_NONE;
}


/* Change the BW of a VOQ connector.

   unit: 0
   voq_bundle_id: 1st voq of a VOQ bundle.
   cos: 0-3. voq_bundle_id+cos gets a VOQ.
   rate: unit is kbps. Setting rate=0 will disable rate shaping (unlimited).
 */

int cint_change_vc_rate (int  unit,
        int  core,
        int  voq_bundle_id,  /* 1st voq of 4 VOQ's*/
        int  cos,
        int  rate)
{
    bcm_gport_t vc_group;
    char error_msg[200]={0,};

    BCM_COSQ_GPORT_VOQ_CONNECTOR_CORE_SET(vc_group, voq_bundle_id, core);

    snprintf(error_msg, sizeof(error_msg), "vc_group=0x%x", vc_group);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit, vc_group, cos,
            0, rate, 0), error_msg);
    return BCM_E_NONE;
}


/* Change the weight of a VOQ connector.

   unit: 0
   voq_bundle_id: 1st voq of a VOQ bundle.
   cos: 0-3. voq_bundle_id+cos gets a VOQ.
   weight: relative weight, 0..63.
 */

int cint_change_vc_weight (int  unit,
        int  voq_bundle_id,  /* 1st voq of 4 VOQ's */
        int  cos,
        int  eir_weight)
{
    bcm_gport_t vc_group;
    char error_msg[200]={0,};

    BCM_COSQ_GPORT_VOQ_CONNECTOR_CORE_SET(vc_group, voq_bundle_id, 0);

    snprintf(error_msg, sizeof(error_msg), "vc_group=0x%x cos=%d", vc_group, cos);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit, vc_group, cos,
            BCM_COSQ_SP1, eir_weight), error_msg);
    return BCM_E_NONE;
}


int cint_tm_rate_no_limit (int unit, int port_rate)
{
    int level;

    if (port_rate != -1)
        BCM_IF_ERROR_RETURN_MSG(cint_change_port_rate(unit,2,port_rate), "");

    for (level=2; level <= 4; level++) {
        BCM_IF_ERROR_RETURN_MSG(cint_change_se_rate(unit,level,0,0,0), "");
    }
    BCM_IF_ERROR_RETURN_MSG(cint_change_vc_rate(unit, 0x20, 0, 0), "");
    return BCM_E_NONE;
}


int cint_tm_setup_full (int unit,int port_base,int nof_ports)
{
    return cint_tm_setup(unit, port_base, nof_ports,
            L4_NUM_ELEMENTS, L3_NUM_ELEMENTS, L2_NUM_ELEMENTS);
}

