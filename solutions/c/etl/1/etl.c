#include "etl.h"
#include <ctype.h>
#include <stdlib.h>

int convert(const legacy_map *input, const size_t input_len, new_map **output) {
    size_t total_key = 0, key_count = 0;
    for (size_t i = 0; i < input_len; i++) {
        legacy_map temp = input[i];
        while (*temp.keys != '\0') {
            total_key++;
            temp.keys++;
        }
    }
    if (total_key == 0) {
        *output = NULL;
        return 0;
    }

    *output = malloc(total_key * sizeof(new_map));
    if (*output == NULL) {
        return 0;
    }
    for (size_t i = 0; i < input_len; i++) {
        legacy_map temp = input[i];
        while (*temp.keys != '\0') {
            (*output)[key_count].key = tolower(*temp.keys);
            (*output)[key_count++].value = temp.value;
            temp.keys++;
        }
    }
    for (size_t i = 0; i < key_count-1; i++) {
        int swapped = 0;
        for (size_t j = 0; j < key_count-i-1; j++) {
            if ((*output)[j].key > (*output)[j+1].key) {
                new_map temp = (*output)[j];
                (*output)[j] = (*output)[j+1];
                (*output)[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
    return key_count;
}