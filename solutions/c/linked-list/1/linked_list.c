#include "linked_list.h"

#include <stdlib.h>
#include <stddef.h>

#define INVALID_VALUE -1

list_t *list_create(void) {
    list_t *list = malloc(sizeof(list_t));
    list->first = NULL;
    list->last = NULL;
    return list;
}

size_t list_count(const list_t *list) {
    size_t count = 0;
    list_node_t *current = list->first;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void list_push(list_t *list, ll_data_t item_data) {
    list_node_t *new_node = malloc(sizeof(list_node_t));
    new_node->prev = list->last;
    new_node->next = NULL;
    new_node->data = item_data;
    if (list->last == NULL) {
        list->first = new_node;
        list->last = new_node;
    } else {
        list->last->next = new_node;
        list->last = new_node;
    }
    list->last = new_node;
}

ll_data_t list_pop(list_t *list) {
    list_node_t *pop_node = list->last;
    if (pop_node == NULL) {
        return INVALID_VALUE;
    }
    ll_data_t data = pop_node->data;
    list->last = pop_node->prev;
    if (list->last != NULL) {
        list->last->next = NULL;
    } else {
        list->first = NULL;
    }
    free(pop_node);
    return data;
}

void list_unshift(list_t *list, ll_data_t item_data) {
    list_node_t *new_node = malloc(sizeof(list_node_t));
    new_node->next = list->first;
    new_node->prev = NULL;
    new_node->data = item_data;
    if (list->first == NULL) {
        list->first = new_node;
        list->last = new_node;
    } else {
        list->first->prev = new_node;
        list->first = new_node;
    }
}

ll_data_t list_shift(list_t *list) {
    list_node_t *shift_node = list->first;
    if (shift_node == NULL) {
        return INVALID_VALUE;
    }
    ll_data_t data = shift_node->data;
    list->first = shift_node->next;
    if (list->first != NULL) {
        list->first->prev = NULL;
    } else {
        list->last = NULL;
    }
    free(shift_node);
    return data;
}

void list_delete(list_t *list, ll_data_t data) {
    list_node_t *current = list->first;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->first = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->last = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

void list_destroy(list_t *list) {
    list_node_t *current = list->first;
    while (current != NULL) {
        list_node_t *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}