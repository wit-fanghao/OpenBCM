/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * File:        dnx_trunk_dispatch.h
 * Purpose:     dnx trunk driver BCM API dispatch table
 * Generator:   modules_dispatch.py
 */

#ifndef _BCM_INT_DNX_TRUNK_DISPATCH_H
#define _BCM_INT_DNX_TRUNK_DISPATCH_H

#include <bcm/types.h>
#include <bcm_int/dispatch.h>

#ifdef BCM_DNX_SUPPORT

extern int bcm_dnx_trunk_bitmap_expand(int,bcm_pbmp_t *);
extern int bcm_dnx_trunk_chip_info_get(int,bcm_trunk_chip_info_t *);
extern int bcm_dnx_trunk_create(int,uint32,bcm_trunk_t *);
extern int bcm_dnx_trunk_destroy(int,bcm_trunk_t);
extern int bcm_dnx_trunk_detach(int);
extern int bcm_dnx_trunk_find(int,bcm_module_t,bcm_gport_t,bcm_trunk_t *);
extern int bcm_dnx_trunk_flow_agg_get(int,int,int,bcm_flow_agg_info_t *);
extern int bcm_dnx_trunk_flow_agg_set(int,int,int,bcm_flow_agg_info_t *);
extern int bcm_dnx_trunk_get(int,bcm_trunk_t,bcm_trunk_info_t *,int,bcm_trunk_member_t *,int *);
extern int bcm_dnx_trunk_init(int);
extern int bcm_dnx_trunk_member_add(int,bcm_trunk_t,bcm_trunk_member_t *);
extern int bcm_dnx_trunk_member_delete(int,bcm_trunk_t,bcm_trunk_member_t *);
extern int bcm_dnx_trunk_member_delete_all(int,bcm_trunk_t);
extern int bcm_dnx_trunk_member_hash_range_get(int,uint32,bcm_trunk_t,bcm_gport_t,bcm_trunk_member_range_t *);
extern int bcm_dnx_trunk_member_hash_range_set(int,uint32,bcm_trunk_t,bcm_gport_t,bcm_trunk_member_range_t);
extern int bcm_dnx_trunk_pp_port_allocation_get(int,bcm_trunk_t,uint32,bcm_trunk_pp_port_allocation_info_t *);
extern int bcm_dnx_trunk_pp_port_allocation_set(int,bcm_trunk_t,uint32,bcm_trunk_pp_port_allocation_info_t *);
extern int bcm_dnx_trunk_profile_create(int,uint32,bcm_trunk_profile_t *,int *);
extern int bcm_dnx_trunk_profile_destroy(int,uint32,int);
extern int bcm_dnx_trunk_profile_get(int,uint32,int,bcm_trunk_profile_t *,bcm_trunk_profile_info_t *);
extern int bcm_dnx_trunk_profile_set(int,uint32,int,bcm_trunk_profile_t *);
extern int bcm_dnx_trunk_psc_get(int,bcm_trunk_t,int *);
extern int bcm_dnx_trunk_psc_set(int,bcm_trunk_t,int);
extern int bcm_dnx_trunk_set(int,bcm_trunk_t,bcm_trunk_info_t *,int,bcm_trunk_member_t *);
extern int bcm_dnx_trunk_spa_to_system_phys_port_map_get(int,uint32,uint32,bcm_gport_t *);

#endif /* BCM_DNX_SUPPORT */
#endif /* !_BCM_INT_DNX_TRUNK_DISPATCH_H */