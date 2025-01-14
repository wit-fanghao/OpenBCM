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
 * File:        dnx_init_dispatch.h
 * Purpose:     dnx init driver BCM API dispatch table
 * Generator:   modules_dispatch.py
 */

#ifndef _BCM_INT_DNX_INIT_DISPATCH_H
#define _BCM_INT_DNX_INIT_DISPATCH_H

#include <bcm/types.h>
#include <bcm_int/dispatch.h>

#ifdef BCM_DNX_SUPPORT

extern int bcm_dnx_init_check(int);
extern int bcm_dnx_init_advanced(int,bcm_init_advanced_info_t *);
extern int bcm_dnx_init(int);

#endif /* BCM_DNX_SUPPORT */
#endif /* !_BCM_INT_DNX_INIT_DISPATCH_H */
