#include "sublist.h"
#include <stdbool.h>

static bool is_sublist(int *list_to_compare, int *base_list,
                       size_t list_to_compare_element_count,
                       size_t base_list_element_count) {
    if (list_to_compare_element_count == 0) return true;
    if (list_to_compare_element_count > base_list_element_count) return false;
    for (size_t i = 0; i <= base_list_element_count - list_to_compare_element_count; i++) {
        if (base_list[i] == list_to_compare[0]) {
            bool match = true;
            for (size_t j = 1; j < list_to_compare_element_count; j++) {
                if (list_to_compare[j] != base_list[i+j]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
    }
    return false;
                                }

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) {
    bool ltc_is_sublist = is_sublist(list_to_compare, base_list, list_to_compare_element_count, base_list_element_count);
    bool ltc_is_superlist = is_sublist(base_list, list_to_compare, base_list_element_count, list_to_compare_element_count);
    if (ltc_is_sublist && ltc_is_superlist) {
        return EQUAL;
    } else if (ltc_is_sublist) {
        return SUBLIST;
    } else if (ltc_is_superlist) {
        return SUPERLIST;
    } else {
        return UNEQUAL;
    }
                                }