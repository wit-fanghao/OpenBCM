/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2021 Broadcom Inc. All rights reserved.
 *
 * File:	traverse_key.h
 * Purpose:	BCM API Traverse routine key
 * Generator:	mkdispatch 1.54
 */

#ifndef	_BCM_INT_TRAVERSE_KEY_H
#define	_BCM_INT_TRAVERSE_KEY_H

#ifdef	BCM_RPC_SUPPORT

#define	BCM_TRAVERSE_LOOKUP_KEYLEN	5
#define	BCM_TRAVERSE_LOOKUP_COUNT	178

typedef int (*_bcm_traverse_handler_t)(bcm_rlink_traverse_data_t **);
typedef struct _bcm_traverse_lookup_s {
	uint32			key[BCM_TRAVERSE_LOOKUP_KEYLEN];
	_bcm_traverse_handler_t	routine;
} _bcm_traverse_lookup_t;

extern _bcm_traverse_lookup_t _bcm_traverse_lookup[BCM_TRAVERSE_LOOKUP_COUNT];

#endif	/* BCM_RPC_SUPPORT */

#endif	/* !_BCM_INT_TRAVERSE_KEY_H */