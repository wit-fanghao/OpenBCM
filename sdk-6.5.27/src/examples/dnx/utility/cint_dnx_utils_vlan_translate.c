/*
 * VLAN translation utility functions
 */

/** 
 * \brief
 * 
 * This function performs the following steps: 
 * 1. Sets edit profile for ingress/egress LIF: 
 *      Calls bcm_vlan_port_translation_set using the following parameters:
 *          - is_ive
 *          - new_outer_vid
 *          - new_inner_vid
 *          - lif (gport)
 *          - vlan_edit_profile
 *
 * 2. Sets translation action:
 *      Calls bcm_vlan_translate_action_id_set using the following parameters:
 *          - is_ive
 *          - action_id
 *          - outer_tpid
 *          - inner_tpid
 *          - outer_action
 *          - inner_action
 * 3. Set translation action class (map edit_profile & tag_format to action_id):
 *      Calls bcm_vlan_translate_action_class_set using the following parameters:
 *          - is_ive
 *          - action_id
 *          - vlan_edit_profile
 *          - tag_format
 * Return value:
 *  - BCM_E_NONE if no error.
 *  - negative value in case of an error. See shr_error_e.
 *
 */

struct vlan_translate_with_eve_s
{
    uint16 outer_tpid;
    uint16 inner_tpid;
    bcm_vlan_t new_outer_vid;
    bcm_vlan_t new_inner_vid;
    uint32 vlan_edit_profile;
    bcm_port_tag_format_class_t tag_format;
    bcm_vlan_action_t outer_action;
    bcm_vlan_action_t inner_action;
    int eve_action_id;
};

/* Initialization of the global struct*/
vlan_translate_with_eve_s g_vlan_translate_with_eve = {
    /*  new outer tpid_value: */
    0x9100,
    /*  new inner tpid_value: */
    0x8100,
    /*  new outer vid: */
    0x100,
    /*  new inner vid: */
    0x200,
    /*  vlan_edit_profile: */
    2,
    /*  tag_format: */
    4,
    /*  EVE action: */
    bcmVlanActionNone, bcmVlanActionNone,
    /*  EVE Action ID */
    5,
};

int action_id_1;
int action_id;

int
vlan_translate_ive_eve_translation_set(
    int unit,
    bcm_gport_t lif,
    int outer_tpid,
    int inner_tpid,
    bcm_vlan_action_t outer_action,
    bcm_vlan_action_t inner_action,
    bcm_vlan_t new_outer_vid,
    bcm_vlan_t new_inner_vid,
    uint32 vlan_edit_profile,
    uint16 tag_format,
    uint8 is_ive)
{
    bcm_vlan_action_set_t action;
    bcm_vlan_translate_action_class_t action_class;
    bcm_vlan_port_translation_t port_trans;
    int flags;

    /*
     * set edit profile for ingress/egress LIF 
     */
    bcm_vlan_port_translation_t_init(&port_trans);
    port_trans.new_outer_vlan = new_outer_vid;
    port_trans.new_inner_vlan = new_inner_vid;
    port_trans.gport = lif;
    port_trans.vlan_edit_class_id = vlan_edit_profile;
    port_trans.flags = is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_translation_set(unit, &port_trans), "");

    /*
     * Create action ID
     */
    flags = (is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS);
    if (action_id_1)
    {
        flags |= BCM_VLAN_ACTION_SET_WITH_ID;
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create(unit, flags, &action_id_1), "");

    /*
     * Save the created action ID so it can be read from test
     */
    action_id = action_id_1;
    /*
     * Set translation action 
     */
    bcm_vlan_action_set_t_init(&action);
    action.outer_tpid = outer_tpid;
    action.inner_tpid = inner_tpid;
    action.dt_outer = outer_action;
    action.dt_inner = inner_action;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set(unit,
                                          (is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS),
                                          action_id_1, &action), "");

    /*
     * Set translation action class (map edit_profile & tag_format to action_id) 
     */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = vlan_edit_profile;
    action_class.tag_format_class_id = tag_format;
    action_class.vlan_translation_action_id = action_id_1;
    action_class.flags = (is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set(unit, &action_class), "");

    action_id_1 = 0;

    return BCM_E_NONE;
}

/** 
 * \brief
 * 
 * This function performs the following steps: 
 * 1. Sets edit profile for ingress/egress LIF: 
 *      Calls bcm_vlan_port_translation_set using the following parameters:
 *          - is_ive
 *          - new_outer_vid
 *          - new_inner_vid
 *          - lif (gport)
 *          - vlan_edit_profile
 *
 * 2. Sets translation action:
 *      Calls bcm_vlan_translate_action_id_set using the following parameters:
 *          - is_ive
 *          - action_id
 *          - outer_tpid
 *          - inner_tpid
 *          - outer_tpid_action
 *          - inner_tpid_action
 *          - outer_action
 *          - inner_action
 * 3. Set translation action class (map edit_profile & tag_format to action_id):
 *      Calls bcm_vlan_translate_action_class_set using the following parameters:
 *          - is_ive
 *          - action_id
 *          - vlan_edit_profile
 *          - tag_format
 * Return value:
 *  - BCM_E_NONE if no error.
 *  - negative value in case of an error. See shr_error_e.
 *  
 *  Note:
 *  This function performs same actions as
 *  vlan_translate_ive_eve_translation_set.
 *  The difference between the two is in the input parameters:
 *  - outer_tpid_action
 *  - inner_tpid_action
 *  The above function use default value of
 *  bcmVlanTpidActionNone for these parameters.
 *  In below function, user can set its values as he likes.
 */
int
vlan_translate_ive_eve_translation_set_with_tpid_action(
    int unit,
    bcm_gport_t lif,
    int outer_tpid,
    int inner_tpid,
    bcm_vlan_tpid_action_t outer_tpid_action,
    bcm_vlan_tpid_action_t inner_tpid_action,
    bcm_vlan_action_t outer_action,
    bcm_vlan_action_t inner_action,
    bcm_vlan_t new_outer_vid,
    bcm_vlan_t new_inner_vid,
    uint32 vlan_edit_profile,
    uint16 tag_format,
    uint8 is_ive)

{
    bcm_vlan_action_set_t action;
    bcm_vlan_translate_action_class_t action_class;
    bcm_vlan_port_translation_t port_trans;
    int flags;

    /*
     * set edit profile for ingress/egress LIF 
     */
    bcm_vlan_port_translation_t_init(&port_trans);
    port_trans.new_outer_vlan = new_outer_vid;
    port_trans.new_inner_vlan = new_inner_vid;
    port_trans.gport = lif;
    port_trans.vlan_edit_class_id = vlan_edit_profile;
    port_trans.flags = is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_translation_set(unit, &port_trans), "");

    /*
     * Create action ID
     */
    flags = (is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS);
    if (action_id_1)
    {
        flags |= BCM_VLAN_ACTION_SET_WITH_ID;
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create(unit, flags, &action_id_1), "");

    /*
     * Set translation action 
     */
    bcm_vlan_action_set_t_init(&action);
    action.outer_tpid = outer_tpid;
    action.inner_tpid = inner_tpid;
    action.outer_tpid_action = outer_tpid_action;
    action.inner_tpid_action = inner_tpid_action;
    action.dt_outer = outer_action;
    action.dt_inner = inner_action;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set(unit,
                                          (is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS),
                                          action_id_1, &action), "");

    /*
     * Set translation action class (map edit_profile & tag_format to action_id) 
     */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = vlan_edit_profile;
    action_class.tag_format_class_id = tag_format;
    action_class.vlan_translation_action_id = action_id_1;
    action_class.flags = (is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set(unit, &action_class), "");

    action_id_1 = 0;

    return BCM_E_NONE;
}

/** 
 * \brief
 * 
 * This function performs the following steps: 
 * 1. Sets edit profile for ingress/egress LIF: 
 *      Calls bcm_vlan_port_translation_set using the following parameters:
 *          - is_ive
 *          - new_outer_vid
 *          - new_inner_vid
 *          - lif (gport)
 *          - vlan_edit_profile
 *
 * 2. Sets translation action:
 *      Calls bcm_vlan_translate_action_id_set using the following parameters:
 *          - is_ive
 *          - action_id
 *          - outer_tpid
 *          - inner_tpid
 *          - outer_tpid_action
 *          - inner_tpid_action
 *          - outer_action
 *          - inner_action
 * 3. Set translation action class (map edit_profile & tag_format to action_id):
 *      Calls bcm_vlan_translate_action_class_set using the following parameters:
 *          - is_ive
 *          - action_id
 *          - vlan_edit_profile
 *          - tag_format
 * Return value:
 *  - BCM_E_NONE if no error.
 *  - negative value in case of an error. See shr_error_e.
 *  
 *  Note:
 *  This function performs same actions as
 *  vlan_translate_ive_eve_translation_set_with_tpid_action.
 *  The difference between the two is in the input parameters:
 *  - outer_pri_action
 *  - inner_pri_action
 *  The above function use default value of
 *  bcmVlanActionNone for these parameters.
 *  In below function, user can set values to modify pri mapping.
 */
int
vlan_translate_ive_eve_translation_set_with_pri_action(
    int unit,
    bcm_gport_t lif,
    int outer_tpid,
    int inner_tpid,
    bcm_vlan_tpid_action_t outer_tpid_action,
    bcm_vlan_tpid_action_t inner_tpid_action,
    bcm_vlan_action_t outer_action,
    bcm_vlan_action_t inner_action,
    bcm_vlan_action_t outer_pri_action,
    bcm_vlan_action_t inner_pri_action,
    bcm_vlan_t new_outer_vid,
    bcm_vlan_t new_inner_vid,
    uint32 vlan_edit_profile,
    uint16 tag_format,
    uint8 is_ive)

{
    bcm_vlan_action_set_t action;
    bcm_vlan_translate_action_class_t action_class;
    bcm_vlan_port_translation_t port_trans;
    int flags;

    /*
     * set edit profile for ingress/egress LIF 
     */
    bcm_vlan_port_translation_t_init(&port_trans);
    port_trans.new_outer_vlan = new_outer_vid;
    port_trans.new_inner_vlan = new_inner_vid;
    port_trans.gport = lif;
    port_trans.vlan_edit_class_id = vlan_edit_profile;
    port_trans.flags = is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_translation_set(unit, &port_trans), "");

    /*
     * Create action ID
     */
    flags = (is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS);
    if (action_id_1)
    {
        flags |= BCM_VLAN_ACTION_SET_WITH_ID;
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create(unit, flags, &action_id_1), "");

    /*
     * Set translation action 
     */
    bcm_vlan_action_set_t_init(&action);
    action.outer_tpid = outer_tpid;
    action.inner_tpid = inner_tpid;
    action.outer_tpid_action = outer_tpid_action;
    action.inner_tpid_action = inner_tpid_action;
    action.dt_outer = outer_action;
    action.dt_inner = inner_action;
    action.dt_outer_pkt_prio = outer_pri_action;
    action.dt_inner_pkt_prio = inner_pri_action;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set(unit,
                                          (is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS),
                                          action_id_1, &action), "");

    /*
     * Set translation action class (map edit_profile & tag_format to action_id) 
     */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = vlan_edit_profile;
    action_class.tag_format_class_id = tag_format;
    action_class.vlan_translation_action_id = action_id_1;
    action_class.flags = (is_ive ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set(unit, &action_class), "");

    action_id_1 = 0;

    return BCM_E_NONE;
}

/** 
 * \brief
 * 
 * This function performs the following steps: 
 * 1. Sets edit profile for egress LIF: 
 *      Calls bcm_vlan_port_translation_set using the following parameters:
 *          - new_outer_vid
 *          - new_inner_vid
 *          - lif (gport)
 *          - vlan_edit_profile
 *
 * 2. Sets translation action:
 *      Calls bcm_vlan_translate_action_id_set using the following parameters:
 *          - action_id
 *          - outer_tpid
 *          - inner_tpid
 *          - outer_action
 *          - inner_action
 * 3. Set translation action class with additional flags(map edit_profile & tag_format to action_id):
 *      Calls bcm_vlan_translate_action_class_set using the following parameters:
 *          - action_id
 *          - vlan_edit_profile
 *          - tag_format
 *          - flag
 *            - without BCM_VLAN_ACTION_SET_EGRESS_DISABLE_MEMBERSHIP -> user outer VLAN for egress membership after EVE
 *            - with BCM_VLAN_ACTION_SET_EGRESS_DISABLE_MEMBERSHIP -> disable egress membership after EVE
 *            - with BCM_VLAN_ACTION_SET_EGRESS_ENABLE_INNER_MEMBERSHIP -> use inner VLAN for membership filter after EVE
 *            - BCM_VLAN_ACTION_SET_EGRESS_DISABLE_OUTER_TAG_REMOVAL -> disable tag removing after EVE
 *            - without BCM_VLAN_ACTION_SET_EGRESS_DISABLE_MIRRORING -> use outer VLAN for mirroring after EVE
 *            - with BCM_VLAN_ACTION_SET_EGRESS_DISABLE_MIRRORING -> disable mirroring after EVE
 *            - with BCM_VLAN_ACTION_SET_EGRESS_ENABLE_INNER_MIRRORING -> use inner VLAN for mirroring after EVE
 *  Note:
 *  This function serves the same purpose as vlan_translate_ive_eve_translation_set ingress part
 *    the difference is it allows additional flags for post EVE actions, explained above
 */
int
vlan_translate_eve_translation_set(
    int unit,
    bcm_gport_t lif,
    int additional_flag)
{
    bcm_vlan_action_set_t action;
    bcm_vlan_translate_action_class_t action_class;
    bcm_vlan_port_translation_t port_trans;

    /*
     * set edit profile for egress LIF 
     */
    bcm_vlan_port_translation_t_init(&port_trans);
    port_trans.new_outer_vlan = g_vlan_translate_with_eve.new_outer_vid;
    port_trans.new_inner_vlan = g_vlan_translate_with_eve.new_inner_vid;
    port_trans.gport = lif;
    port_trans.vlan_edit_class_id = g_vlan_translate_with_eve.vlan_edit_profile;
    port_trans.flags = BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_translation_set(unit, &port_trans), "");

    /*
     * Create action ID
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create(unit, BCM_VLAN_ACTION_SET_EGRESS | BCM_VLAN_ACTION_SET_WITH_ID,
                                             &g_vlan_translate_with_eve.eve_action_id), "");

    /*
     * Set translation action 
     */
    bcm_vlan_action_set_t_init(&action);
    action.outer_tpid = g_vlan_translate_with_eve.outer_tpid;
    action.inner_tpid = g_vlan_translate_with_eve.inner_tpid;
    action.dt_outer = g_vlan_translate_with_eve.outer_action;
    action.dt_inner = g_vlan_translate_with_eve.inner_action;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set(unit,BCM_VLAN_ACTION_SET_EGRESS,
                                          g_vlan_translate_with_eve.eve_action_id, &action), "");

    /*
     * Set translation action class (map edit_profile & tag_format to action_id) 
     */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = g_vlan_translate_with_eve.vlan_edit_profile;
    action_class.tag_format_class_id = g_vlan_translate_with_eve.tag_format;
    action_class.vlan_translation_action_id = g_vlan_translate_with_eve.eve_action_id;
    action_class.flags = BCM_VLAN_ACTION_SET_EGRESS;
    action_class.flags |= additional_flag;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set(unit, &action_class), "");

    return BCM_E_NONE;
}

/* 
 * JR2 only, update post EVE actions, flag is same as above function
 */
int
vlan_translate_post_eve_update(
    int unit,
    int additional_flag)
{
    bcm_vlan_translate_action_class_t action_class;

    /*
     * Set translation action class (map edit_profile & tag_format to action_id) 
     */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = g_vlan_translate_with_eve.vlan_edit_profile;
    action_class.tag_format_class_id = g_vlan_translate_with_eve.tag_format;
    action_class.vlan_translation_action_id = g_vlan_translate_with_eve.eve_action_id;
    action_class.flags = BCM_VLAN_ACTION_SET_EGRESS;
    action_class.flags |= additional_flag;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set(unit, &action_class), "");

    return BCM_E_NONE;
}


/* Classify a Ports combination of TPIDs to a specific tag format.
 * Applicable only in AVT mode. 
 *  
 * INPUT: 
 *   port: Physical port or a PWE gport
 *   tag_format: Tag format.
 *   outer_tpid: Outer TPID value
 *   inner_tpid: Inner TPID value
 */
int vlan_translate_tag_classification_set(int unit,
                                          bcm_port_t port,
                                          bcm_port_tag_format_class_t tag_format,
                                          uint32 outer_tpid,
                                          uint32 inner_tpid)
{
    char error_msg[200]={0,};
    bcm_port_tpid_class_t tpid_class;

    bcm_port_tpid_class_t_init(&tpid_class);

    tpid_class.flags = 0;   /* Both for Ingress and Egress */
    tpid_class.port = port;
    tpid_class.tag_format_class_id = tag_format;
    tpid_class.tpid1 = outer_tpid;
    tpid_class.tpid2 = inner_tpid;
    snprintf(error_msg, sizeof(error_msg), "port - %d", port);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &tpid_class), error_msg);

    return BCM_E_NONE;
}
