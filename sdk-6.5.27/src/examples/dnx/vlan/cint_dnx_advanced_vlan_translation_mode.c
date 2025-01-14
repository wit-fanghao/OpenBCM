/* $Id: cint_dnx_advanced_vlan_translation_mode.c,v 1.1
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
*/

int qos_mode = 0; /* When set, this variable enables qos mapping in AVT mode */

/* Global declaration, since many cints use it and some redeclare it, or don't declare it at all, which causes errors. */
int advanced_vlan_translation_mode = 0;

/*
 * Fill Action
 */
int
vlan_translation_action_add(int unit, int action_id, int flags, bcm_vlan_action_t outer_vid_source, bcm_vlan_action_t inner_vid_source, uint16 outer_tpid, uint16 inner_tpid)
{
    char error_msg[200]={0,};
    bcm_vlan_action_set_t action;

    /* Create action ID*/
    bcm_vlan_action_set_t_init(&action);

    action.dt_outer = outer_vid_source;
    action.dt_inner = inner_vid_source;
    action.outer_tpid = outer_tpid;
    action.inner_tpid = inner_tpid;

    /* Enables outer_pcp_dei_source, inner_pcp_dei_source to be determined according to pre-defined qos mapping*/
    if (advanced_vlan_translation_mode && qos_mode) {
        action.dt_inner_pkt_prio = bcmVlanActionAdd;
        action.dt_outer_pkt_prio = bcmVlanActionAdd;
    }

    snprintf(error_msg, sizeof(error_msg), "outer tpid: 0x%x inner tpid: 0x%x", outer_tpid, inner_tpid);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set( unit,
                                           flags,
                                           action_id,
                                           &action), error_msg);

    return BCM_E_NONE;
}

/* set vlan port translation, determine edit profile for LIF */
int
vlan_port_translation_set(int unit, bcm_vlan_t new_vid, bcm_vlan_t new_inner_vid, bcm_gport_t vlan_port, uint32 edit_class_id, uint8 is_ingress) {
    bcm_vlan_port_translation_t port_trans;

    /* Set port translation */
    bcm_vlan_port_translation_t_init(&port_trans);
    port_trans.new_outer_vlan = new_vid;
    port_trans.new_inner_vlan = new_inner_vid;
    port_trans.gport = vlan_port;
    port_trans.vlan_edit_class_id = edit_class_id;
    port_trans.flags = is_ingress ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_translation_set(unit, &port_trans), "");

    if (verbose) {
        printf("Configure %s vlan port: 0x%x with outer vlan: %d, inner vlan: %d, ve profile: %d \n", (is_ingress ? "ingress" : "egress"), vlan_port, new_vid, new_inner_vid, edit_class_id);
    }

    return BCM_E_NONE;
}



/* Constant values for the old vlan translation actions and profiles */
const int INGRESS_NOP_PROFILE                   = 0;
const int INGRESS_REMOVE_TAGS_PROFILE           = 4;
const int INGRESS_REMOVE_OUTER_TAG_ACTION       = 5;
const int EGRESS_NOP_PROFILE                    = 0;
const int EGRESS_REMOVE_TAGS_PROFILE            = 2;
const int EGRESS_REMOVE_TAGS_PUSH_1_PROFILE     = 5;
const int EGRESS_REMOVE_TAGS_PUSH_2_PROFILE     = 8;
const int EGRESS_UNTAGGED_OFFSET                = 0;
const int EGRESS_SINGLE_TAGGED_OFFSET           = 1;
const int EGRESS_DOUBLE_TAGGED_OFFSET           = 2;

/* Flags for trill initialization */
const int VLAN_TRANSLATION_TRILL_ACTION = (1 << 20);
const int VLAN_TRANSLATION_TRILL_TPID_ACTION = (1 << 19);
const int TRILL_SINGLE_VLAN_ACTION      = 4;
const int TRILL_DOUBLE_VLAN_ACTION      = 10;
const int TRILL_TTS_VLAN_ACTION         = 16;
const int TRILL_SINGLE_VLAN_PROFILE     = 4;
const int TRILL_DOUBLE_VLAN_PROFILE     = 5;
const int TRILL_TTS_VLAN_PROFILE        = 6;
const int TRILL_OT_OFFSET               = 0;
const int TRILL_DT_OFFSET               = 1;
const int TRILL_IT_OFFSET               = 2;
const int TRILL_UT_OFFSET               = 3;


/* In the old vlan translation mode, some actions and mappings were configured automatically.
   This function creates these actions, so old cints can be called without consequences.

    Egress and ingress actions are created in their respective functions, and then the tags and profile
    are mapped to their appropriate actions.
   */
int
vlan_translation_default_mode_init(int unit){

    advanced_vlan_translation_mode = 1;

    /*** CREATE INGRESS ACTIONS */
    BCM_IF_ERROR_RETURN_MSG(creat_default_ingress_actions(unit), "");

    /*** CREATE  EGRESS ACTIONS ***/
    BCM_IF_ERROR_RETURN_MSG(create_default_egress_actions(unit, 0), "");

    printf("Done configuring default vlan translation settings for unit %d\n", unit);

    return BCM_E_NONE;
}


/*
    Two ingress actions are created:
    REMOVE_TAGS: To remove vlan tags from the packet
    REMOVE_OUTER_TAG: To remove only the outer tag.

    Then, For each profile, we map the relevant tag to its action.
*/
int
creat_default_ingress_actions(int unit){
    int in_action_id;

    /* Ingress action 5: remove outer tag, preserve inner */
    in_action_id = INGRESS_REMOVE_OUTER_TAG_ACTION;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_create_mapping(unit, in_action_id, bcmVlanActionDelete, bcmVlanActionNone, -1, 1),
        "INGRESS_REMOVE_OUTER_TAG_ACTION");

    /* CREATE INGRESS ACTION 4: remove tags, mapped from edit profile 1 and all tag formats */
    in_action_id = INGRESS_REMOVE_TAGS_PROFILE;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_create_mapping(unit, in_action_id, bcmVlanActionDelete, bcmVlanActionDelete, in_action_id, 1),
        "INGRESS_REMOVE_TAGS_PROFILE");

    return BCM_E_NONE;
}


/*
   9 Egress actions are created:
   For each type of packet tag format (untagged, single tagged or double tagged) we create three profiles:
        REMOVE_TAGS: to remove all vlan tags
        REMOVE_TAGS_PUSH_1: to remove all tags, and push a new one
        REMOVE_TAGS_PUSH_2: to remove all tags, and push two new ones

   Then, For each profile, we map the relevant tag to its action.
*/
int
create_default_egress_actions(int unit, int is_trill){
    int eg_action_id;
    int eg_profile;
    int trill_flag = (is_trill) ? VLAN_TRANSLATION_TRILL_ACTION : 0;


    /* First action type: remove tags */
    eg_profile = EGRESS_REMOVE_TAGS_PROFILE;

    /* Egress action 3: get single tagged, remove tags */
    eg_action_id = EGRESS_REMOVE_TAGS_PROFILE + EGRESS_SINGLE_TAGGED_OFFSET;
    eg_action_id |= trill_flag;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_create_mapping(unit, eg_action_id , bcmVlanActionDelete, bcmVlanActionNone, -1, 0),
        "EGRESS_REMOVE_TAGS_PROFILE + EGRESS_SINGLE_TAGGED_OFFSET");

    /* Egress action 4: get double tagged, remove tags */
    eg_action_id = EGRESS_REMOVE_TAGS_PROFILE + EGRESS_DOUBLE_TAGGED_OFFSET;
    eg_action_id |= trill_flag;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_create_mapping(unit, eg_action_id , bcmVlanActionDelete, bcmVlanActionDelete, -1, 0),
        "EGRESS_REMOVE_TAGS_PROFILE + EGRESS_DOUBLE_TAGGED_OFFSET");

    /* Egress action 2: get untagged, remove tags.
       Also, map all remove tags actions */
    eg_action_id = EGRESS_REMOVE_TAGS_PROFILE + EGRESS_UNTAGGED_OFFSET;
    eg_action_id |= trill_flag;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_create_mapping(unit, eg_action_id , bcmVlanActionNone, bcmVlanActionNone, eg_profile, 0),
        "EGRESS_REMOVE_TAGS_PROFILE + EGRESS_UNTAGGED_OFFSET");


    /* Second action type: remove tags, push 1 */
    eg_profile = EGRESS_REMOVE_TAGS_PUSH_1_PROFILE;

    /* Egress action 6: get single tagged, remove tags push 1 */
    eg_action_id = EGRESS_REMOVE_TAGS_PUSH_1_PROFILE + EGRESS_SINGLE_TAGGED_OFFSET;
    eg_action_id |= trill_flag;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_create_mapping(unit, eg_action_id , bcmVlanActionReplace, bcmVlanActionNone, -1, 0),
        "EGRESS_REMOVE_TAGS_PUSH_1_PROFILE + EGRESS_SINGLE_TAGGED_OFFSET");

    /* Egress action 7: get double tagged, remove tags push 1 */
    eg_action_id = EGRESS_REMOVE_TAGS_PUSH_1_PROFILE + EGRESS_DOUBLE_TAGGED_OFFSET;
    eg_action_id |= trill_flag;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_create_mapping(unit, eg_action_id , bcmVlanActionReplace, bcmVlanActionDelete, -1, 0),
        "EGRESS_REMOVE_TAGS_PUSH_1_PROFILE + EGRESS_DOUBLE_TAGGED_OFFSET");


    /* Egress action 5: get untagged, remove tags push 1
       Also, map all remove tags push 1 actions */
    eg_action_id = EGRESS_REMOVE_TAGS_PUSH_1_PROFILE + EGRESS_UNTAGGED_OFFSET;
    eg_action_id |= trill_flag;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_create_mapping(unit, eg_action_id , bcmVlanActionAdd, bcmVlanActionNone, eg_profile, 0),
        "EGRESS_REMOVE_TAGS_PUSH_1_PROFILE + EGRESS_UNTAGGED_OFFSET");


    /* Third action type: remove tags, push 2 */
    eg_profile = EGRESS_REMOVE_TAGS_PUSH_2_PROFILE;

    /* Egress action 6: get single tagged, remove tags push 2 */
    eg_action_id = EGRESS_REMOVE_TAGS_PUSH_2_PROFILE + EGRESS_SINGLE_TAGGED_OFFSET;
    eg_action_id |= trill_flag;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_create_mapping(unit, eg_action_id , bcmVlanActionReplace, bcmVlanActionAdd, -1 , 0),
        "EGRESS_REMOVE_TAGS_PUSH_2_PROFILE + EGRESS_SINGLE_TAGGED_OFFSET");


    /* Egress action 7: get double tagged, remove tags push 2 */
    eg_action_id = EGRESS_REMOVE_TAGS_PUSH_2_PROFILE + EGRESS_DOUBLE_TAGGED_OFFSET;
    eg_action_id |= trill_flag;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_create_mapping(unit, eg_action_id , bcmVlanActionReplace, bcmVlanActionReplace, -1, 0),
        "EGRESS_REMOVE_TAGS_PUSH_2_PROFILE + EGRESS_DOUBLE_TAGGED_OFFSET");


    /* Egress action 5: get untagged, remove tags push 2
       Also, map all remove tags push 1 actions */
    eg_action_id = EGRESS_REMOVE_TAGS_PUSH_2_PROFILE + EGRESS_UNTAGGED_OFFSET;
    eg_action_id |= trill_flag;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_create_mapping(unit, eg_action_id , bcmVlanActionAdd, bcmVlanActionAdd, eg_profile, 0),
        "EGRESS_REMOVE_TAGS_PUSH_2_PROFILE + EGRESS_UNTAGGED_OFFSET");

    return BCM_E_NONE;
}


/*
 * Creates an action with the given id and configures it.
 * If given an edit profile, map it to this action + OFFSET if it's an egress action.
 */
int
vlan_translation_create_mapping(int unit, int action_id, bcm_vlan_action_t outer_vid_source, bcm_vlan_action_t inner_vid_source,
                                int edit_profile, uint8 is_ingress){

    int flags;
    char *ineg = (is_ingress) ? "ingress" : "egress";
    bcm_vlan_translate_action_class_t action_class;
    int tag_format;
    uint8 is_trill_vl_tpid = (action_id & VLAN_TRANSLATION_TRILL_TPID_ACTION) ? 1 : 0;
    uint8 is_trill = (action_id & VLAN_TRANSLATION_TRILL_ACTION) ? 1 : 0;
    /* 0x893B: native outer tpid for trill fgl. The vlan translation is done at IVE (is_ingress param), before trill encapsulation */
    uint16 outer_tpid = (is_trill && is_ingress && !is_trill_vl_tpid) ? 0x893B : 0x8100;
    uint16 inner_tpid = (is_trill) ? 0x893B : 0x9100;

    /* Remove the flags from the action id */
    action_id &= 0xff;

    /* Create new Action IDs */
    flags = (is_ingress) ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS;
    flags |= BCM_VLAN_ACTION_SET_WITH_ID;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create(unit, flags, &action_id), "");

    if (verbose) {
        printf("Created %s action id %d\n", ineg, action_id);
    }

    flags = (is_ingress) ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_action_add(unit, action_id, flags, outer_vid_source, inner_vid_source, outer_tpid, inner_tpid), "");

    if (verbose) {
        printf("Created %s translation action %d\n", ineg, action_id);
    }

    /* In case we don't want to create mapping, return here. */
    if (edit_profile < 0) {
        return BCM_E_NONE;
    }

    /* Map edit profile and all tag formats to command */
    int tag_format_index;
    int tag_format_array[5] = {0, 4, 8, 16, 24};
    for (tag_format_index = 0; tag_format_index < 5; tag_format_index++) {
        bcm_vlan_translate_action_class_t_init(&action_class);
        action_class.vlan_edit_class_id = edit_profile;
        action_class.tag_format_class_id = tag_format_array[tag_format_index];

        tag_format = action_class.tag_format_class_id;
        if (is_ingress) {
            action_class.vlan_translation_action_id = tag_format == 0 ? INGRESS_NOP_PROFILE :
                                                      tag_format < 16 ? INGRESS_REMOVE_OUTER_TAG_ACTION :
                                                      action_id;
        } else {
            action_class.vlan_translation_action_id = tag_format == 0 ? action_id :
                                                      tag_format < 16 ? action_id + EGRESS_SINGLE_TAGGED_OFFSET :
                                                      action_id + EGRESS_DOUBLE_TAGGED_OFFSET;
        }

        action_class.flags = flags;
        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set(unit,  &action_class), "");
    }

    if (verbose) {
        printf("Mapped %s edit profile %d and all tag_format to %s action %d\n", ineg, edit_profile, ineg, action_id);
    }

    return BCM_E_NONE;
}

/* When calling bcm_vlan_port_create in the old vlan translation mode, a default mapping would have been created.
   Call this function with the vlan port you used when calling bcm_vlan_port_create to create this mapping */
int
vlan_translation_vlan_port_create_to_translation(int unit, bcm_vlan_port_t *vlan_port){
    int port_id = vlan_port->vlan_port_id;
    bcm_vlan_t match_vlan = vlan_port->match_vlan;
    bcm_vlan_t match_inner_vlan = vlan_port->match_inner_vlan;
    bcm_vlan_t egress_vlan = vlan_port->egress_vlan;
    bcm_vlan_t egress_inner_vlan = vlan_port->egress_inner_vlan;
    int ingress_edit_profile = INGRESS_REMOVE_TAGS_PROFILE;
    int egress_edit_profile;


    /* Determine egress action */
    if ((vlan_port->egress_inner_vlan == BCM_VLAN_INVALID && vlan_port->egress_vlan != BCM_VLAN_INVALID) ||
        vlan_port->criteria == BCM_VLAN_PORT_MATCH_PORT_VLAN ||
        vlan_port->criteria == BCM_VLAN_PORT_MATCH_PORT_CVLAN ||
        vlan_port->criteria == BCM_VLAN_PORT_MATCH_PORT_INITIAL_VLAN) {
        egress_edit_profile = EGRESS_REMOVE_TAGS_PUSH_1_PROFILE;
    } else if ((vlan_port->egress_inner_vlan == BCM_VLAN_INVALID && vlan_port->egress_vlan == BCM_VLAN_INVALID) ||
               vlan_port->criteria == BCM_VLAN_PORT_MATCH_PORT) {
        egress_edit_profile = EGRESS_REMOVE_TAGS_PROFILE;
    } else if (vlan_port->egress_vlan == 0 && vlan_port->egress_inner_vlan == 0 &&
               (vlan_port->flags & BCM_VLAN_PORT_INNER_VLAN_PRESERVE) &&
               (vlan_port->flags & BCM_VLAN_PORT_OUTER_VLAN_PRESERVE)){
        egress_edit_profile = EGRESS_NOP_PROFILE;
        ingress_edit_profile = INGRESS_NOP_PROFILE; /* Change ingress mapping as well in this case (to NOP) */
    } else {
        egress_edit_profile = EGRESS_REMOVE_TAGS_PUSH_2_PROFILE;
    }


    /* Configre ingress editing */
    BCM_IF_ERROR_RETURN_MSG(vlan_port_translation_set(unit, match_vlan, match_inner_vlan, port_id, ingress_edit_profile, 1),
        "ingress profile");

    /* Configure egress editing*/
    BCM_IF_ERROR_RETURN_MSG(vlan_port_translation_set(unit, egress_vlan, egress_inner_vlan, port_id, egress_edit_profile, 0),
        "egress profile");

    return BCM_E_NONE;
}


int ive_eve_translation_set(int unit,
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
    int action_id_1;

    /* set edit profile for  ingress/egress LIF */
    bcm_vlan_port_translation_t_init(&port_trans);
    port_trans.new_outer_vlan = new_outer_vid;
    port_trans.new_inner_vlan = new_inner_vid;
    port_trans.gport = lif;
    port_trans.vlan_edit_class_id = vlan_edit_profile;
    port_trans.flags = is_ive ? BCM_VLAN_ACTION_SET_INGRESS:BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_translation_set(unit, &port_trans), "");

    /* Create action ID*/
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create( unit, (is_ive ? BCM_VLAN_ACTION_SET_INGRESS:BCM_VLAN_ACTION_SET_EGRESS), &action_id_1), "");

    /* Set translation action */
    bcm_vlan_action_set_t_init(&action);
    action.outer_tpid = outer_tpid;
    action.inner_tpid = inner_tpid;
    action.dt_outer = outer_action;
    action.dt_inner = inner_action;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set( unit,
                                            (is_ive ? BCM_VLAN_ACTION_SET_INGRESS:BCM_VLAN_ACTION_SET_EGRESS),
                                            action_id_1,
                                            &action), "");

    /* Set translation action class (map edit_profile & tag_format to action_id) */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = vlan_edit_profile;
    action_class.tag_format_class_id = tag_format;
    action_class.vlan_translation_action_id = action_id_1;
    action_class.flags = (is_ive ? BCM_VLAN_ACTION_SET_INGRESS:BCM_VLAN_ACTION_SET_EGRESS);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set( unit,  &action_class), "");


    return BCM_E_NONE;
}

/* set translation actions (replace) */
int
vlan_translate_action_set(int unit, int action_id_1, int action_id_2, uint8 is_ingress, bcm_vlan_action_t outer_action, bcm_vlan_action_t inner_action) {
    bcm_vlan_action_set_t action;
    uint32 flags;

    flags = is_ingress ? BCM_VLAN_ACTION_SET_INGRESS : BCM_VLAN_ACTION_SET_EGRESS;

    /* Create action IDs*/
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create( unit, flags | BCM_VLAN_ACTION_SET_WITH_ID, &action_id_1), "");

    if(action_id_2 != 0) {
        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create( unit, flags | BCM_VLAN_ACTION_SET_WITH_ID, &action_id_2), "");
    }

    /* Set translation action 1. outer action, set TPID 0x8100. */
    bcm_vlan_action_set_t_init(&action);
    action.dt_outer = outer_action;
    action.dt_inner = inner_action;
    action.outer_tpid = 0x8100;
    /* JR2 needs a valid inner TPID in case of inner_action is add*/
    if (inner_action == bcmVlanActionArpVlanTranslateAdd) {
        action.inner_tpid = 0x8100;
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set(unit,
                                           flags,
                                           action_id_1,
                                           &action), "1");

    if(action_id_2 != 0) {
        /* Set translation action 2. outer action, set TPID 0x9100. */
        bcm_vlan_action_set_t_init(&action);
        action.dt_outer = outer_action;
        action.dt_inner = inner_action;
        action.outer_tpid = 0x9100;
        action.inner_tpid = 0x8100;
        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set( unit,
                                               flags,
                                               action_id_2,
                                               &action), "2");
    }

    return BCM_E_NONE;
}



/* Set untagged and single tagged packets, matched with default out-LIF to use action ID */
int
vlan_default_translate_action_class_set(int unit, int action_id) {
    bcm_vlan_translate_action_class_t action_class;

    /* Set translation action class for single tagged packets with TPID 0x8100 */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = 2;
    /* On JR2, default tag format id is 8 for ctag TPID 0x8100 */
    action_class.tag_format_class_id = 8;
    action_class.vlan_translation_action_id = action_id;
    action_class.flags = BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set( unit,  &action_class), "");

    /* Set translation action class for untagged */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = 2;
    action_class.tag_format_class_id = 0;
    action_class.vlan_translation_action_id = action_id;
    action_class.flags = BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set( unit,  &action_class), "");

    return BCM_E_NONE;
}

/* Destroys all ingress/ egress actions. */
int
vlan_translation_default_mode_destroy(int unit){

    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_destroy_all(unit, BCM_VLAN_ACTION_SET_INGRESS),
        "Failed to clean ingress action ids");
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_destroy_all(unit, BCM_VLAN_ACTION_SET_EGRESS),
        "Failed to clean ingress action ids");

    return BCM_E_NONE;
}


/* Set ports TPID class to handle priority and non priority packets as desired
   port1: priority - pass, non priority - pass
   port2: priority - drop, non priority - pass
   port3: priority - replace outer/add inner, non priority (untagged) - add vid */
int
ive_priority_tags_main(int unit, int port1, int port2, int port3, int port4) {

    char error_msg[200]={0,};
    bcm_gport_t vlan_port;
    int action_id_1=5, action_id_2=6;
    int vlan_edit_profile = 2;
    bcm_port_tpid_class_t port_tpid_class;
    bcm_vlan_translate_action_class_t action_class;
    bcm_vlan_action_set_t action;
    bcm_vlan_t default_vsi = 1;
    bcm_vlan_t new_vid = 40;
    bcm_port_tag_format_class_t tag_format_ctag = 8; /* Use default */
    bcm_vlan_port_t vp;
    bcm_l2_addr_t l2addr;
    bcm_mac_t mac = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};

    /* set port2 to drop priority tag packet */
    bcm_port_tpid_class_t_init(&port_tpid_class);
    port_tpid_class.port = port2;
    port_tpid_class.tpid1 = 0x8100;
    port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_ANY;
    port_tpid_class.tag_format_class_id = tag_format_ctag;
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_OUTER_IS_PRIO | BCM_PORT_TPID_CLASS_DISCARD;
    snprintf(error_msg, sizeof(error_msg), "port=%d", port2);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), error_msg);

    /* set port3 tag format for priority packets */
    bcm_port_tpid_class_t_init(&port_tpid_class);
    port_tpid_class.port = port3;
    port_tpid_class.tpid1 = 0x8100;
    port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_ANY;
    port_tpid_class.tag_format_class_id = tag_format_ctag;
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_OUTER_IS_PRIO;
    port_tpid_class.vlan_translation_action_id = 0;
    snprintf(error_msg, sizeof(error_msg), "port=%d", port3);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), error_msg);

    /* Create a VLAN port for port3 */
    bcm_vlan_port_t_init(&vp);
    vp.criteria = BCM_VLAN_PORT_MATCH_PORT;
    vp.port = port3;
    vp.vsi = default_vsi;
    vp.flags = BCM_VLAN_PORT_CREATE_INGRESS_ONLY;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vp), "");

    /* set edit profile for ingress LIF */
    BCM_IF_ERROR_RETURN_MSG(vlan_port_translation_set(unit, new_vid, new_vid, vp.vlan_port_id, vlan_edit_profile, 1), "");

    /* Create action ID 1 */
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create( unit, BCM_VLAN_ACTION_SET_INGRESS | BCM_VLAN_ACTION_SET_WITH_ID, &action_id_1), "1");

    /* Create action ID 2 */
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create( unit, BCM_VLAN_ACTION_SET_INGRESS | BCM_VLAN_ACTION_SET_WITH_ID, &action_id_2), "2");


    /*
     * For priority tagged, replace outer vlan and add inner
     */
    bcm_vlan_action_set_t_init(&action);
    action.dt_outer = bcmVlanActionReplace;
    action.dt_inner = bcmVlanActionAdd;
    action.outer_tpid = 0x9100;
    action.inner_tpid = 0x8100;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set( unit,
                                           BCM_VLAN_ACTION_SET_INGRESS,
                                           action_id_1,
                                           &action), "1");

    /*
     * For untagged, add vlan
     */
    bcm_vlan_action_set_t_init(&action);
    action.dt_outer = bcmVlanActionAdd;
    action.dt_inner = bcmVlanActionNone;
    action.outer_tpid = 0x8100;
    action.inner_tpid = 0x9100;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set( unit,
                                           BCM_VLAN_ACTION_SET_INGRESS,
                                           action_id_2,
                                           &action), "1");

    /* Set translation action class - priority packets */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = vlan_edit_profile;
    action_class.tag_format_class_id = tag_format_ctag;
    action_class.vlan_translation_action_id = action_id_1;
    action_class.flags = BCM_VLAN_ACTION_SET_INGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set( unit, &action_class), "");

    /* Set translation action class - untagged packets */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = vlan_edit_profile;
    action_class.tag_format_class_id = 0;
    action_class.vlan_translation_action_id = action_id_2;
    action_class.flags = BCM_VLAN_ACTION_SET_INGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set( unit, &action_class), "");

    /* set static entry in MAC table */
    bcm_l2_addr_t_init(&l2addr, mac, 1);
    l2addr.port = port4;
    l2addr.flags = BCM_L2_STATIC;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, &l2addr), "");

    /* set static entry in MAC table */
    bcm_l2_addr_t_init(&l2addr, mac, new_vid);
    l2addr.port = port4;
    l2addr.flags = BCM_L2_STATIC;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, &l2addr), "");

    return BCM_E_NONE;
}

/* Set port TPID class to handle priority and non priority packets as desired.
   Egress vlan translation: priority - delete vlan, non priority (untagged) - add vid */
int
eve_priority_tags_main(int unit, int port1, int port2) {

    char error_msg[200]={0,};
    bcm_gport_t vlan_port;
    int action_id_1=5, action_id_2=6;;
    bcm_port_tpid_class_t port_tpid_class;
    bcm_vlan_translate_action_class_t action_class;
    bcm_vlan_action_set_t action;
    bcm_vlan_t default_vsi = 1;
    bcm_vlan_t new_vid = 50;
    bcm_port_tag_format_class_t tag_format_ctag = 8; /* Use default */
    int vlan_edit_profile = 2;
    bcm_l2_addr_t l2addr;
    bcm_mac_t mac = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};

    /* classify all incoming packets to default VSI */
    bcm_vlan_port_t vp;
    bcm_vlan_port_t_init(&vp);
    vp.criteria = BCM_VLAN_PORT_MATCH_PORT;
    vp.port = port1;
    vp.vsi = default_vsi;
    vp.flags = BCM_VLAN_PORT_CREATE_INGRESS_ONLY;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vp), "");

    /* set tag format 2 for priority packets */
    bcm_port_tpid_class_t_init(&port_tpid_class);
    port_tpid_class.port = port1;
    port_tpid_class.tpid1 = 0x8100;
    port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_ANY;
    port_tpid_class.tag_format_class_id = tag_format_ctag;
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_OUTER_IS_PRIO;
    port_tpid_class.vlan_translation_action_id = 0;
    snprintf(error_msg, sizeof(error_msg), "port=%d", port1);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), error_msg);

    /* set tag format 2 for priority packets on port2*/
    bcm_port_tpid_class_t_init(&port_tpid_class);
    port_tpid_class.port = port2;
    port_tpid_class.tpid1 = 0x8100;
    port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_ANY;
    port_tpid_class.tag_format_class_id = tag_format_ctag;
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_OUTER_IS_PRIO;
    snprintf(error_msg, sizeof(error_msg), "port=%d", port2);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), error_msg);

    /* Create a egress vlan port */
    bcm_vlan_port_t_init(&vp);
    vp.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    vp.port = port2;
    vp.vsi = default_vsi;
    vp.flags = BCM_VLAN_PORT_CREATE_EGRESS_ONLY | BCM_VLAN_PORT_VLAN_TRANSLATION;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vp), "");
    vlan_port = vp.vlan_port_id;

    /* set edit profile for egress LIF */
    BCM_IF_ERROR_RETURN_MSG(vlan_port_translation_set(unit, new_vid, new_vid, vlan_port, vlan_edit_profile, 0), "");

    /* Create action ID 1 */
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create( unit, BCM_VLAN_ACTION_SET_EGRESS | BCM_VLAN_ACTION_SET_WITH_ID, &action_id_1), "1");

    /* Create action ID 2 */
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create( unit, BCM_VLAN_ACTION_SET_EGRESS | BCM_VLAN_ACTION_SET_WITH_ID, &action_id_2), "2");

    /*
     * For priority tagged, delete vlan
     */
    bcm_vlan_action_set_t_init(&action);
    action.dt_outer = bcmVlanActionDelete;
    action.dt_inner = bcmVlanActionNone;
    action.outer_tpid = 0x8100;
    action.inner_tpid = 0x9100;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set(unit,
                                           BCM_VLAN_ACTION_SET_EGRESS,
                                           action_id_1,
                                           &action), "1");

    /*
     * For untagged, add vlan
     */
    bcm_vlan_action_set_t_init(&action);
    action.dt_outer = bcmVlanActionAdd;
    action.dt_inner = bcmVlanActionNone;
    action.outer_tpid = 0x8100;
    action.inner_tpid = 0x9100;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set(unit,
                                           BCM_VLAN_ACTION_SET_EGRESS,
                                           action_id_2,
                                           &action), "2");

    /* Set translation action class - priority packets */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = vlan_edit_profile;
    action_class.tag_format_class_id = tag_format_ctag;
    action_class.vlan_translation_action_id = action_id_1;
    action_class.flags = BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set( unit, &action_class), "");

    /* Set translation action class - untagged packets */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = vlan_edit_profile;
    action_class.tag_format_class_id = 0;
    action_class.vlan_translation_action_id = action_id_2;
    action_class.flags = BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set( unit, &action_class), "");

    /* set static entry in MAC table */
    bcm_l2_addr_t_init(&l2addr, mac, 1);
    l2addr.port = port2;
    l2addr.flags = BCM_L2_STATIC;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, &l2addr), "");

    /* set static entry in MAC table */
    bcm_l2_addr_t_init(&l2addr, mac, new_vid);
    l2addr.port = port2;
    l2addr.flags = BCM_L2_STATIC;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, &l2addr), "");

    return BCM_E_NONE;
}
