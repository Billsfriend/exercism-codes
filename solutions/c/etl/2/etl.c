#include "etl.h"
#include <ctype.h>
#include <stdlib.h>

static int cmp_new_map(const void *a, const void *b) {
    return ((new_map *)a)->key - ((new_map *)b)->key;
}

int convert(const legacy_map *input, const size_t input_len, new_map **output) {
    int total_key = 0, key_count = 0;
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
    qsort(*output, key_count, sizeof(new_map), cmp_new_map);
    return key_count;
}