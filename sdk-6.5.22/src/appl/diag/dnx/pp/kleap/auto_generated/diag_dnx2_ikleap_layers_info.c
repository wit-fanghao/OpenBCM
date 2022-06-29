/** \file diag_dnx2_ikleap_layers_info.c
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 */
/*
 * 
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2021 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SOCDNX_DIAGKLEAPDNX

#ifdef BCM_DNX2_SUPPORT

#include "diag_dnx2_ikleap_layers_info.h"
#include <soc/dnx/utils/dnx_pp_programmability_utils.h>
#include "diag_dnx2_ikleap_layers_info_internal.h"
#include "../diag_dnx_ikleap_layers_translation_to_pparse.h"

/* *INDENT-OFF* */

kleap_layer_to_pparse_t *vt1_header[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS]    = { 0 };
kleap_layer_to_pparse_t *vt1_qualifier[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS] = { 0 };
kleap_layer_to_pparse_t *vt2_header[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS]    = { 0 };
kleap_layer_to_pparse_t *vt2_qualifier[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS] = { 0 };
kleap_layer_to_pparse_t *vt3_header[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS]    = { 0 };
kleap_layer_to_pparse_t *vt3_qualifier[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS] = { 0 };
kleap_layer_to_pparse_t *vt4_header[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS]    = { 0 };
kleap_layer_to_pparse_t *vt4_qualifier[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS] = { 0 };
kleap_layer_to_pparse_t *vt5_header[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS]    = { 0 };
kleap_layer_to_pparse_t *vt5_qualifier[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS] = { 0 };
kleap_layer_to_pparse_t *fwd1_header[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS]    = { 0 };
kleap_layer_to_pparse_t *fwd1_qualifier[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS] = { 0 };
kleap_layer_to_pparse_t *fwd2_header[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS]    = { 0 };
kleap_layer_to_pparse_t *fwd2_qualifier[KLEAP_LAYER_TO_PARSE_MAX_NOF_CTX * KLEAP_NOF_RELATIVE_LAYERS] = { 0 };

    kleap_layer_to_pparse_t *dummy_headers_layers[8 * KLEAP_NOF_RELATIVE_LAYERS] = {
    &General_header,
    &FCoE_header,
    &PPPoE_header,
    &L2TP_header,
    &GTP_header,
    &BIER_NON_MPLS_header,
    &ETHERNET_header,
    &RCH_header,
    &SRV6_RCH_USP_PSP_AND_PSP_EXT_header,
    &IPv4_header,
    &IPv6_header,
    &MPLS_header,
    &INITIALIZATION_header,
    &General_layer,
    &ETHERNET_layer,
    &RCH_layer,
    &SRV6_RCH_USP_PSP_AND_PSP_EXT_layer,
    &PPPoE_layer,
    &L2TP_layer,
    &GTP_layer,
    &FCoE_layer,
    &MPLS_layer,
    &BIER_NON_MPLS_layer,
    &IPv4_layer,
    &IPv6_layer,
    &INITIALIZATION_layer
};

/*
 * Kleap layers info init.
 */
shr_error_e dnx_kleap_layers_info_init(int unit)
{
    char *image_name = NULL;

    SHR_FUNC_INIT_VARS(unit);

    /*
     * Get Image name.
     */
    SHR_IF_ERR_EXIT(dnx_pp_prgm_device_image_name_get(unit, &image_name));

    /*
     * Init the global layer structs.
     */
    diag_dnx2_ikleap_layers_info_vt1_header(unit,image_name);

    diag_dnx2_ikleap_layers_info_vt2_header(unit,image_name);

    diag_dnx2_ikleap_layers_info_vt3_header(unit,image_name);

    diag_dnx2_ikleap_layers_info_vt4_header(unit,image_name);

    diag_dnx2_ikleap_layers_info_vt5_header(unit,image_name);

    diag_dnx2_ikleap_layers_info_fwd1_header(unit,image_name);

    diag_dnx2_ikleap_layers_info_fwd2_header(unit,image_name);

    diag_dnx2_ikleap_layers_info_vt1_qualifier(unit,image_name);

    diag_dnx2_ikleap_layers_info_vt2_qualifier(unit,image_name);

    diag_dnx2_ikleap_layers_info_vt3_qualifier(unit,image_name);

    diag_dnx2_ikleap_layers_info_vt4_qualifier(unit,image_name);

    diag_dnx2_ikleap_layers_info_vt5_qualifier(unit,image_name);

    diag_dnx2_ikleap_layers_info_fwd1_qualifier(unit,image_name);

    diag_dnx2_ikleap_layers_info_fwd2_qualifier(unit,image_name);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

/*
 * Get functions for vt1_header structure.
 */
void diag_dnx2_ikleap_layers_info_vt1_header(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(vt1_header, standard_1_vt1_header, sizeof(standard_1_vt1_header));
        return;
    }

}

/*
 * Get functions for vt2_header structure.
 */
void diag_dnx2_ikleap_layers_info_vt2_header(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(vt2_header, standard_1_vt2_header, sizeof(standard_1_vt2_header));
        return;
    }

}

/*
 * Get functions for vt3_header structure.
 */
void diag_dnx2_ikleap_layers_info_vt3_header(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(vt3_header, standard_1_vt3_header, sizeof(standard_1_vt3_header));
        return;
    }

}

/*
 * Get functions for vt4_header structure.
 */
void diag_dnx2_ikleap_layers_info_vt4_header(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(vt4_header, standard_1_vt4_header, sizeof(standard_1_vt4_header));
        return;
    }

}

/*
 * Get functions for vt5_header structure.
 */
void diag_dnx2_ikleap_layers_info_vt5_header(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(vt5_header, standard_1_vt5_header, sizeof(standard_1_vt5_header));
        return;
    }

}

/*
 * Get functions for fwd1_header structure.
 */
void diag_dnx2_ikleap_layers_info_fwd1_header(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(fwd1_header, standard_1_fwd1_header, sizeof(standard_1_fwd1_header));
        return;
    }

}

/*
 * Get functions for fwd2_header structure.
 */
void diag_dnx2_ikleap_layers_info_fwd2_header(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(fwd2_header, standard_1_fwd2_header, sizeof(standard_1_fwd2_header));
        return;
    }

}

/*
 * Get functions for vt1_qualifier structure.
 */
void diag_dnx2_ikleap_layers_info_vt1_qualifier(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(vt1_qualifier, standard_1_vt1_qualifier, sizeof(standard_1_vt1_qualifier));
        return;
    }

}

/*
 * Get functions for vt2_qualifier structure.
 */
void diag_dnx2_ikleap_layers_info_vt2_qualifier(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(vt2_qualifier, standard_1_vt2_qualifier, sizeof(standard_1_vt2_qualifier));
        return;
    }

}

/*
 * Get functions for vt3_qualifier structure.
 */
void diag_dnx2_ikleap_layers_info_vt3_qualifier(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(vt3_qualifier, standard_1_vt3_qualifier, sizeof(standard_1_vt3_qualifier));
        return;
    }

}

/*
 * Get functions for vt4_qualifier structure.
 */
void diag_dnx2_ikleap_layers_info_vt4_qualifier(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(vt4_qualifier, standard_1_vt4_qualifier, sizeof(standard_1_vt4_qualifier));
        return;
    }

}

/*
 * Get functions for vt5_qualifier structure.
 */
void diag_dnx2_ikleap_layers_info_vt5_qualifier(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(vt5_qualifier, standard_1_vt5_qualifier, sizeof(standard_1_vt5_qualifier));
        return;
    }

}

/*
 * Get functions for fwd1_qualifier structure.
 */
void diag_dnx2_ikleap_layers_info_fwd1_qualifier(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(fwd1_qualifier, standard_1_fwd1_qualifier, sizeof(standard_1_fwd1_qualifier));
        return;
    }

}

/*
 * Get functions for fwd2_qualifier structure.
 */
void diag_dnx2_ikleap_layers_info_fwd2_qualifier(int unit, char *image_name)
{
    uint8 is_current_image = FALSE;

    dnx_pp_prgm_current_image_check(unit, "standard_1", &is_current_image);
    if (is_current_image)
    {
        sal_memcpy(fwd2_qualifier, standard_1_fwd2_qualifier, sizeof(standard_1_fwd2_qualifier));
        return;
    }

}

#else /* BCM_DNX2_SUPPORT */
typedef int make_iso_compilers_happy;
#endif /* BCM_DNX2_SUPPORT */
/* *INDENT-ON* */