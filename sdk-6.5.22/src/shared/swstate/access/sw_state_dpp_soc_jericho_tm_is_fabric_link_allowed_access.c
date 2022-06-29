/* 
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2021 Broadcom Inc. All rights reserved.
 * 
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 */

#include <sal/core/libc.h>
#include <shared/swstate/sw_state.h>
#include <shared/error.h>
#include <shared/swstate/sw_state_defs.h>
#include <shared/bsl.h>
#include <shared/swstate/access/sw_state_access.h>
#include <shared/swstate/access/sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_access.h>

#ifdef _ERR_MSG_MODULE_NAME
    #error "_ERR_MSG_MODULE_NAME redefined"
#endif

#define _ERR_MSG_MODULE_NAME BSL_LS_SHARED_SWSTATE

extern shr_sw_state_t *sw_state[BCM_MAX_NUM_UNITS];

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_alloc_bitmap(int unit, int _nof_bits_to_alloc){
    SW_STATE_INIT_FUNC_DEFS;
    SHR_SW_STATE_ALLOC_BITMAP(
        unit,
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
        _nof_bits_to_alloc,
        SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
        "sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_alloc");
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_free(int unit){
    SW_STATE_INIT_FUNC_DEFS;
    SHR_SW_STATE_FREE(
        unit,
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
        SW_STATE_NONE,
        "sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_alloc");
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_set(int unit, int _bit_num){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _bit_num, _bit_num, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_SET(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         _bit_num);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_clear(int unit, int _bit_num){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _bit_num, _bit_num, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_CLEAR(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         _bit_num);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_get(int unit, int _bit_num, uint8* result){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _bit_num, _bit_num, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_GET(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         _bit_num,
         result);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_read(int unit, int sw_state_bmp_first, int result_first, int _range, SHR_BITDCL *result){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, sw_state_bmp_first, sw_state_bmp_first + _range - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_READ(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         sw_state_bmp_first,
         result_first,
         _range,
         result);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_write(int unit, int sw_state_bmp_first, int input_bmp_first, int _range, SHR_BITDCL *input_bmp){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, sw_state_bmp_first, sw_state_bmp_first + _range - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_WRITE(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         sw_state_bmp_first,
         input_bmp_first,
          _range,
         input_bmp);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_and(int unit, int _first, int _count, SHR_BITDCL *input_bmp){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _first, _first + _count - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_AND(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         input_bmp,
         _first,
         _count);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_or(int unit, int _first, int _count, SHR_BITDCL *input_bmp){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _first, _first + _count - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_OR(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         input_bmp,
         _first,
         _count);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_xor(int unit, int _first, int _count, SHR_BITDCL *input_bmp){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _first, _first + _count - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_XOR(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         input_bmp,
         _first,
         _count);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_remove(int unit, int _first, int _count, SHR_BITDCL *input_bmp){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _first, _first + _count - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_REMOVE(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         input_bmp,
         _first,
         _count);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_negate(int unit, int _first, int _count){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _first, _first + _count - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_NEGATE(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         _first,
         _count);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_clear(int unit, int _first, int _count){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _first, _first + _count - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_CLEAR(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         _first,
         _count);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_set(int unit, int _first, int _count){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _first, _first + _count - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_SET(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         _first,
         _count);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_null(int unit, int _first, int _count, uint8 *result){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _first, _first + _count - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_NULL(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         _first,
         _count,
         result);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_test(int unit, int _first, int _count, uint8 *result){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _first, _first + _count - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_TEST(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         _first,
         _count,
         result);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_eq(int unit, SHR_BITDCL *input_bmp, int _first, int _count, uint8 *result){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _first, _first + _count - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_EQ(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         _first,
         _count,
         input_bmp,
         result);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_count(int unit, int _first, int _range, int *result){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_BITDCL_VERIFY(sw_state_access[unit].dpp.soc.jericho.tm.verify(unit),
        sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed, _first, _first + _range - 1, "is_fabric_link_allowed");
        SHR_SW_STATE_BIT_RANGE_COUNT(
        unit,
         SW_STATE_IS_WB_CHECK | SW_STATE_ALLOW_AUTOSYNC,
         sw_state[unit]->dpp.soc.jericho.tm.is_fabric_link_allowed,
         _first,
         _range,
         result);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 


int
sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_access_cb_init(int unit){
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.alloc_bitmap = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_alloc_bitmap;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.free = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_free;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_set = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_set;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_clear = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_clear;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_get = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_get;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_read = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_read;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_write = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_write;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_and = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_and;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_or = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_or;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_xor = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_xor;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_remove = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_remove;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_negate = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_negate;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_clear = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_clear;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_set = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_set;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_null = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_null;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_test = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_test;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_eq = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_eq;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_access[unit].dpp.soc.jericho.tm.is_fabric_link_allowed.bit_range_count = sw_state_dpp_soc_jericho_tm_is_fabric_link_allowed_bit_range_count;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
    return _SHR_E_NONE;
}

#undef _ERR_MSG_MODULE_NAME