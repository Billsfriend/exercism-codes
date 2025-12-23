#include "list_ops.h"

#include <stdlib.h>
#include <stdbool.h>

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]) {
    list_t *result_list = malloc(sizeof(list_t) + length * sizeof(list_element_t));
    if (!result_list) {
        return NULL;
    }
    for (size_t i = 0; i < length; i++) {
        result_list->elements[i] = elements[i];
    }
    result_list->length = length;
    return result_list;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2) {
    size_t length_sum = list1->length + list2->length;
    list_t *result_list = new_list(length_sum, list1->elements);
    for (size_t i = list1->length; i < length_sum; i++) {
        result_list->elements[i] = list2->elements[i-list1->length];
    }
    return result_list;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
    if (list == NULL || list->length == 0) {
        list_t *empty = malloc(sizeof(list_t));
        if (empty) empty->length = 0;
        return empty;
    }

    size_t new_length = 0;
    for (size_t i = 0; i < list->length; i++) {
        if (filter(list->elements[i])) {
            new_length++;
        }
    }

    list_t *result = malloc(sizeof(list_t) + new_length * sizeof(list_element_t));
    
    if (result == NULL) {
        return NULL;
    }

    result->length = new_length;

    size_t write_index = 0;
    for (size_t i = 0; i < list->length; i++) {
        if (filter(list->elements[i])) {
            result->elements[write_index] = list->elements[i];
            write_index++;
        }
    }

    return result;
}

// returns the length of the list
size_t length_list(list_t *list) {
    return list->length;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)){
    if (list == NULL || list->length == 0) {
        list_t *empty = malloc(sizeof(list_t));
        if (empty) empty->length = 0;
        return empty;
    }

    list_t *result = malloc(sizeof(list_t) + list->length * sizeof(list_element_t));
    result->length = list->length;

    for (size_t i = 0; i < list->length; i++) {
        result->elements[i] = map(list->elements[i]);
    }
    return result;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
    if (list == NULL || list->length == 0) {
        return initial;
    }

    for (size_t i = 0; i < list->length; i++) {
        initial = foldl(list->elements[i], initial);
    }

    return initial;
                                                  }

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
    return foldl_list(reverse_list(list), initial, foldr);
                                                  }

// reverse the elements of the list
list_t *reverse_list(list_t *list) {
    if (list == NULL || list->length == 0) {
        list_t *empty = malloc(sizeof(list_t));
        if (empty) empty->length = 0;
        return empty;
    }

    list_t *result = malloc(sizeof(list_t) + list->length * sizeof(list_element_t));

    result->length = list->length;

    for (size_t i = 0; i < list->length; i++) {
        result->elements[i] = list->elements[list->length - i - 1];
    }

    return result;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list) {
    free(list);
}