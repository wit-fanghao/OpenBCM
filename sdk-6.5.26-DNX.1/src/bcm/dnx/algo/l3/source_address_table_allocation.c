/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

/** \file source_address_table_allocation.c
 *
 * Wrapper functions for utilex_multi_set.
 *
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_TEMPLATEMNGR
/**
* INCLUDE FILES:
* {
*/

#include <soc/sand/shrextend/shrextend_debug.h>
#include <bcm_int/dnx/algo/l3/algo_l3.h>
#include <bcm_int/dnx/algo/l3/source_address_table_allocation.h>
#include <shared/utilex/utilex_bitstream.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_l3.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_lif.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/access/algo_l3_access.h>
#include <bcm_int/dnx/algo/res_mngr/resource_tag_bitmap.h>

/** } **/

/** 
 *  Source address table template advanced algorithm.
 *  
 *  The algorithm works as following:
 *  
 *  We hold a res tag bitmap that has the same ID range as the source address table template.
 *  When allocating an entry for the first time, we allocate it in the res tag bitmap, since it allows
 *   us to allocate the number of indexes we need, a functionality that doesn't exist in template manager.
 *   Then we use the ID allocated in the resource manager to save the entry in the template manager.
 *  
 *  {
 */

/**
 * The tags are used to identify the top and bottom parts of the table.
 * We need to distinguish them because only the bottom(0-128 profiles from the source_address manager) can hold mac addresses.
 */
#define SOURCE_ADDRESS_BOTTOM_TAG  0

#define SOURCE_ADDRESS_TOP_TAG     1

/*
 * Print callback for the template. 
 */
void
dnx_algo_l3_source_address_table_entry_print_cb(
    int unit,
    const void *data)
{
    source_address_entry_t *entry_ptr = (source_address_entry_t *) data;
    SW_STATE_PRETTY_PRINT_INIT_VARIABLES();

    switch (entry_ptr->address_type)
    {
        case source_address_type_ipv4:
            SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_IPV4, "IP Address",
                                           entry_ptr->address.ipv4_address, "Address type: IPv4", NULL);
            break;
        case source_address_type_ipv6:
             /* coverity[overrun-buffer-val:FALSE]  */
            SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_IPV6, "IP Address",
                                           entry_ptr->address.ipv6_address, "Address type: IPv6", NULL);
            break;
        case source_address_type_mac_prefix:
             /* coverity[overrun-buffer-val:FALSE]  */
            SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_MAC, "MAC Address",
                                           entry_ptr->address.mac_address, "Address type: MAC", NULL);
            break;
        case source_address_type_mac_dual_homing:
            SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_MAC, "MAC Address Dual Homing",
                                           entry_ptr->address.mac_address, "Address type: MAC", NULL);
            break;
        case source_address_type_full_mac:
            SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_MAC, "MAC Address Full",
                                           entry_ptr->address.mac_address, "Address type: MAC", NULL);
            break;
        case source_address_type_default:
            SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_MAC, "Default entry",
                                           entry_ptr->address.mac_address, "Default address", NULL);
            break;
        default:
            SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_STRING, NULL, "Invalid entry type.", NULL, NULL);
    }

    SW_STATE_PRETTY_PRINT_FINISH();
}

shr_error_e
dnx_algo_l3_source_address_table_create(
    int unit,
    uint32 node_id,
    multi_set_t * multi_set_template,
    dnx_algo_template_create_data_t * create_data,
    void *extra_arguments,
    uint32 alloc_flags)
{
    uint32 profiles_per_mac = 0, nof_mac_profiles = 0;
    uint32 tag;
    dnx_algo_res_create_data_t res_tag_bitmap_create_info;
    resource_tag_bitmap_utils_extra_arg_create_info_t extra_create_info;
    resource_tag_bitmap_utils_tag_info_t tag_info;
    SHR_FUNC_INIT_VARS(unit);

    /*
     * 1. Create a regular multi_set_template.
     */
    SHR_IF_ERR_EXIT(multi_set_create(unit, node_id, multi_set_template, create_data, NULL, alloc_flags));

    /*
     * 2. Create a res_tag_bitmap to manage the entries.
     *    The tag will distinguish the top part of the table (tag 't') from the bottom part (tag 'b').
     *    We need this distinction because only the bottom part can hold MAC entries.
     *    In case of IP (not ethernet) the entire table can be used.
     *    In case of IP first attempt to allocate in the top part,
     *    so the bottom(the first 128 profiles) will be reserved for MAC. If the allocation in the top part is not
     *    successful, try to allocate a profile in the bottom part(mac range).
     */

    profiles_per_mac =
        dnx_data_l3.source_address.address_type_info_get(unit, source_address_type_mac_prefix)->nof_entries;
    nof_mac_profiles = dnx_data_l3.source_address.nof_mymac_prefixes_get(unit) * profiles_per_mac;

    sal_memset(&extra_create_info, 0, sizeof(extra_create_info));
    extra_create_info.grains_size[0] = nof_mac_profiles;
    extra_create_info.max_tags_value[0] = 1;

    sal_memset(&res_tag_bitmap_create_info, 0, sizeof(res_tag_bitmap_create_info));
    sal_strncpy(res_tag_bitmap_create_info.name, create_data->name, sizeof(res_tag_bitmap_create_info.name));
    res_tag_bitmap_create_info.first_element = create_data->first_profile;
    res_tag_bitmap_create_info.nof_elements = create_data->nof_profiles;
    res_tag_bitmap_create_info.flags = RESOURCE_TAG_BITMAP_CREATE_FLAGS_NONE;
    sal_strncpy(res_tag_bitmap_create_info.advanced_algo_name, create_data->advanced_algo_name,
                sizeof(res_tag_bitmap_create_info.advanced_algo_name));

    SHR_IF_ERR_EXIT(resource_tag_bitmap_create(unit, node_id, &((*multi_set_template)->allocation_bitmap),
                                               &res_tag_bitmap_create_info, &extra_create_info, alloc_flags));

    /*
     * Set the tags.
     */
    tag = SOURCE_ADDRESS_BOTTOM_TAG;

    tag_info.tags[0] = tag;
    tag_info.force_tag = FALSE;
    tag_info.element = create_data->first_profile;
    tag_info.nof_elements = nof_mac_profiles;
    SHR_IF_ERR_EXIT(resource_tag_bitmap_tag_set(unit, node_id, ((*multi_set_template)->allocation_bitmap), &tag_info));

    tag = SOURCE_ADDRESS_TOP_TAG;

    tag_info.tags[0] = tag;
    tag_info.force_tag = FALSE;
    tag_info.element = create_data->first_profile + nof_mac_profiles;
    tag_info.nof_elements = create_data->nof_profiles - nof_mac_profiles;
    SHR_IF_ERR_EXIT(resource_tag_bitmap_tag_set(unit, node_id, ((*multi_set_template)->allocation_bitmap), &tag_info));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *  Verification function for dnx_algo_l3_source_address_table_allocate.
 *   We assume that all pointers were already checked for NULL by the template manager, and that 
 *   the entry was checked for being in a legal range. 
 *  
 *  Therefore, we only verify that the address type is legal, and that it fits with the given profile if 
 *   WITH_ID flag was used. 
 */
shr_error_e
dnx_algo_l3_source_address_table_allocate_verify(
    int unit,
    uint32 flags,
    source_address_entry_t * profile_data,
    int profile)
{
    int nof_entries_to_allocate;
    int start_byte, end_byte, current_byte, illegal_byte_set;
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Verify profile data.
     * Verify the type, and verify that the bits that are not part of the address are not set.
     * In a union, the data is always aligned to LSB, so we check the MSBs for each data type.
     */
    start_byte = 0;
    end_byte = sizeof(bcm_ip6_t);
    switch (profile_data->address_type)
    {
        case source_address_type_ipv6:
            /*
             * IPv6 is the largest member of the union, so it can use all of its bits.
             */
            start_byte = end_byte;
            break;
        case source_address_type_ipv4:
            start_byte = sizeof(bcm_ip_t);
            break;
        case source_address_type_mac_prefix:
        case source_address_type_mac_dual_homing:
            start_byte = sizeof(bcm_mac_t);

            /*
             * Also check that 10 LSBs of the mac address should are unset.
             */
            if (SOURCE_ADDRESS_GET_MY_MAC_LSB(profile_data->address.mac_address) != 0)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "10 LSBs of the mac address shouldn't be set.");
            }

            break;
        case source_address_type_full_mac:
            start_byte = sizeof(bcm_mac_t);
            break;
        case source_address_type_default:
            break;
        default:
            /*
             * Unknown / illegal type.
             */
            SHR_ERR_EXIT(_SHR_E_PARAM, "Illegal address type. Was %d.", (int) profile_data->address_type);
    }

    illegal_byte_set = FALSE;

    for (current_byte = start_byte; current_byte < end_byte; current_byte++)
    {
        if (profile_data->address.ipv6_address[current_byte] != 0)
        {
            illegal_byte_set = TRUE;
        }
    }

    if (illegal_byte_set)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Illegal bits were set in the profile data address field.");
    }

    /*
     * Verify given profile if WITH_ID. 
     * It should:
     *   A. Be a multiple of the number of entries this address type uses.
     *   B. If it's a mac entry, it can only be in the bottom half of the entries.
     */
    if (_SHR_IS_FLAG_SET(flags, DNX_ALGO_TEMPLATE_ALLOCATE_WITH_ID))
    {
        nof_entries_to_allocate =
            dnx_data_l3.source_address.address_type_info_get(unit, profile_data->address_type)->nof_entries;

        if (profile % nof_entries_to_allocate != 0)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "Given profile is illegal for this address type. Needs to be a multiple of %d but was %d",
                         nof_entries_to_allocate, profile);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_algo_l3_source_address_table_allocate(
    int unit,
    uint32 node_id,
    multi_set_t multi_set_template,
    uint32 flags,
    int nof_references,
    void *profile_data,
    void *extra_arguments,
    int *profile,
    uint8 *first_reference)
{
    source_address_entry_t *entry_ptr = (source_address_entry_t *) profile_data;
    int tmp_profile, rv;
    uint8 allocation_needed = TRUE, with_id;
    uint8 allocation_successful = FALSE;
    SHR_FUNC_INIT_VARS(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_algo_l3_source_address_table_allocate_verify(unit, flags, entry_ptr, *profile));

    with_id = (_SHR_IS_FLAG_SET(flags, DNX_ALGO_TEMPLATE_ALLOCATE_WITH_ID));

    /*
     * 1. Check if the data already exists or if it needs to be allocated.
     */
    rv = multi_set_member_lookup(unit, node_id, multi_set_template, profile_data, &tmp_profile);

    /*
     * If E_NOT_FOUND was returned, it means the data wasn't allocated yet and we need to allocate it. 
     * Otherwise, check for errors, and if none were returned, it means the data is already allocated. 
     * If WITH_ID, make sure the existing profile match the given profile.
     * Otherwise, save the profile we found and use it with the multi set template.
     */
    if (rv != _SHR_E_NOT_FOUND)
    {
        SHR_IF_ERR_EXIT(rv);
        if (with_id && (*profile != tmp_profile))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "This data already exists in profile %d. Given profile %d", tmp_profile,
                         *profile);
        }

        allocation_needed = FALSE;
        *profile = tmp_profile;
    }

    /*
     * 2. If data doesn't already exist, allocate in the res tag bitmap.
     */
    if (allocation_needed)
    {
        uint32 tag;
        uint32 profiles_reserved_for_mac_addresses;
        int nof_entries_to_allocate;
        uint32 res_tag_bitmap_flags;
        resource_tag_bitmap_utils_alloc_info_t res_tag_bitmap_alloc_info;

        nof_entries_to_allocate =
            dnx_data_l3.source_address.address_type_info_get(unit, entry_ptr->address_type)->nof_entries;
        res_tag_bitmap_flags = with_id ? RESOURCE_TAG_BITMAP_ALLOC_WITH_ID : 0;
        res_tag_bitmap_flags |= RESOURCE_TAG_BITMAP_ALLOC_ALIGN_ZERO | RESOURCE_TAG_BITMAP_ALWAYS_CHECK_TAG;

        sal_memset(&res_tag_bitmap_alloc_info, 0, sizeof(resource_tag_bitmap_utils_alloc_info_t));
        res_tag_bitmap_alloc_info.flags = res_tag_bitmap_flags;
        res_tag_bitmap_alloc_info.align = nof_entries_to_allocate;
        res_tag_bitmap_alloc_info.count = nof_entries_to_allocate;

        profiles_reserved_for_mac_addresses =
            dnx_data_l3.source_address.nof_mymac_prefixes_get(unit) *
            dnx_data_l3.source_address.address_type_info_get(unit, source_address_type_mac_prefix)->nof_entries;

        if ((entry_ptr->address_type != source_address_type_default) &&
            (entry_ptr->address_type != source_address_type_mac_prefix))
        {
            /*
             * The entire table can be used by IP addresses and MAC addresses(in case of ARP).
             * The MAC addresses used by the VSI are limited to 64 MACs.
             * First attempt to allocate in the top part,
             * so the bottom will be reserved for MAC(VSI).
             * If the allocation in the top part is not successful,
             * try to allocate a profile in the bottom part(MAC range).
             * However, if WITH_ID is used and the ID is in the MAC range, then skip this.
             */
            if (!
                (_SHR_IS_FLAG_SET(flags, DNX_ALGO_TEMPLATE_ALLOCATE_WITH_ID)
                 && (*profile < profiles_reserved_for_mac_addresses)))
            {
                int nof_used_elements_per_grain = 0;
                int grain_size = multi_set_template->allocation_bitmap->resource->tag_level_info[0].grain_size;
                /** the number of grains is used to calculate the valid profile range*/
                int nof_grains = (dnx_data_l3.source_address.source_address_table_size_get(unit) / grain_size) - 1;

                tag = SOURCE_ADDRESS_TOP_TAG;

                /** check if they are available elements.*/
                SHR_IF_ERR_EXIT(resource_tag_bitmap_nof_allocated_elements_in_range_get(unit, node_id,
                                                                                        multi_set_template->allocation_bitmap,
                                                                                        tag * grain_size,
                                                                                        nof_grains * grain_size,
                                                                                        &nof_used_elements_per_grain));
                if (nof_used_elements_per_grain < (nof_grains * grain_size))
                {
                    res_tag_bitmap_alloc_info.tags[0] = tag;
                    rv = resource_tag_bitmap_alloc(unit, node_id,
                                                   multi_set_template->allocation_bitmap, &res_tag_bitmap_alloc_info,
                                                   profile);
                    /*
                     * If E_RESOURCE was returned, it means that allocation was unsuccessful. 
                     * We'll attempt to allocate below.
                     * Otherwise, check that no other error was returned, and set the the allocation 
                     * succeeded.
                     */
                    if (rv != _SHR_E_RESOURCE)
                    {
                        SHR_IF_ERR_EXIT(rv);
                        allocation_successful = TRUE;
                    }
                }
            }
        }

        /*
         * Attempt to allocate in the bottom half if we didn't allocate in the top.
         */
        if (!allocation_successful)
        {
            tag = SOURCE_ADDRESS_BOTTOM_TAG;

            res_tag_bitmap_alloc_info.tags[0] = tag;

            rv = resource_tag_bitmap_alloc(unit, node_id,
                                           multi_set_template->allocation_bitmap, &res_tag_bitmap_alloc_info, profile);
            /** Retrun _E_FULL in case of _E_RESOURCE*/
            rv = ((rv == _SHR_E_RESOURCE) ? _SHR_E_FULL : rv);
            SHR_IF_ERR_EXIT(rv);
            allocation_successful = TRUE;
        }
    }

    /*
     * 3. Use the allocated profile for the multi set template WITH_ID.
     */
    if (!allocation_needed || allocation_successful)
    {
        SHR_IF_ERR_EXIT(multi_set_member_add(unit, node_id, multi_set_template,
                                             DNX_ALGO_TEMPLATE_ALLOCATE_WITH_ID, nof_references,
                                             profile_data, NULL, profile, first_reference));
    }

    /*
     * Sanity check: allocation_needed and first_reference should be the same.
     */
    if (allocation_needed != *first_reference)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Algorithm inconsistency. allocation_needed: %d, first_reference: %d",
                     allocation_needed, *first_reference);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_algo_l3_source_address_table_free(
    int unit,
    uint32 node_id,
    multi_set_t multi_set_template,
    int profile,
    int nof_references,
    uint8 *last_reference)
{
    int dummy_ref_count;
    source_address_entry_t entry_data;
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Get the entry data, in case we need to deallocate it from the resource manager.
     */
    SHR_IF_ERR_EXIT(multi_set_get_by_index
                    (unit, node_id, multi_set_template, profile, &dummy_ref_count, (void *) &entry_data));

    /*
     * Free from the multi set template.
     */
    SHR_IF_ERR_EXIT(multi_set_member_remove_by_index_multiple
                    (unit, node_id, multi_set_template, profile, nof_references, last_reference));

    /*
     * If last reference, free from the res tag bitmap as well.
     */
    if (*last_reference)
    {
        int nof_entries_to_deallocate;

        nof_entries_to_deallocate =
            dnx_data_l3.source_address.address_type_info_get(unit, entry_data.address_type)->nof_entries;

        SHR_IF_ERR_EXIT(resource_tag_bitmap_free_several(unit, node_id,
                                                         multi_set_template->allocation_bitmap,
                                                         nof_entries_to_deallocate, profile, NULL));
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_algo_l3_source_address_table_clear(
    int unit,
    uint32 node_id,
    multi_set_t multi_set_template)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Clear template and resource.
     */
    SHR_IF_ERR_EXIT(multi_set_clear(unit, node_id, multi_set_template));

    SHR_IF_ERR_EXIT(resource_tag_bitmap_clear(unit, node_id, multi_set_template->allocation_bitmap));

exit:
    SHR_FUNC_EXIT;
}

/*
 * Initialize the source address table allocation algoirthm, implemented by tempalte manager.
 */
shr_error_e
dnx_algo_l3_source_address_table_init(
    int unit)
{
    dnx_algo_template_create_data_t source_address_template_data;
    source_address_entry_t source_address_entry;
    SHR_FUNC_INIT_VARS(unit);

    sal_memset(&source_address_entry, 0, sizeof(source_address_entry_t));
    source_address_entry.address_type = source_address_type_default;

    /*
     * Create template.
     */
    sal_memset(&source_address_template_data, 0, sizeof(dnx_algo_template_create_data_t));

    source_address_template_data.flags =
        DNX_ALGO_TEMPLATE_CREATE_USE_ADVANCED_ALGORITHM | DNX_ALGO_TEMPLATE_CREATE_USE_DEFAULT_PROFILE;
    source_address_template_data.data_size = sizeof(source_address_entry_t);
    source_address_template_data.first_profile = 0;
    source_address_template_data.default_data = &source_address_entry;
    source_address_template_data.default_profile = SOURCE_ADDRESS_TABLE_DEFAULT_PROFILE;
    source_address_template_data.max_references = dnx_data_lif.out_lif.nof_local_out_lifs_get(unit);
    source_address_template_data.nof_profiles = dnx_data_l3.source_address.source_address_table_size_get(unit);
    source_address_template_data.advanced_algorithm = DNX_ALGO_TEMPLATE_ADVANCED_ALGORITHM_L3_SOURCE_TABLE;
    sal_strncpy(source_address_template_data.name, DNX_ALGO_L3_EGRESS_SOURCE_ADDRESS_TABLE_RESOURCE,
                DNX_ALGO_TEMPLATE_MNGR_MAX_NAME_LENGTH - 1);

    SHR_IF_ERR_EXIT(algo_l3_db.source_address_table_allocation.source_address_table.create
                    (unit, &source_address_template_data, NULL));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_algo_l3_source_address_table_deinit(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Sw state is deinitilzed in algo_l3.c
     */

    /*
     * Resource and template manager don't require deinitialization per instance.
     */

    SHR_EXIT();

exit:
    SHR_FUNC_EXIT;
}

/**
 * }
 */
