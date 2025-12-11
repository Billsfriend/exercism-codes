#include "raindrops.h"
#include <string.h>
#include <stdio.h>

const int buffer_size = 16;

void convert(char result[], int drops) {
    size_t max_append;
    if (drops % 3 == 0) {
        max_append = buffer_size - strlen(result) - 1;
        strncat(result, "Pling", max_append);
    }
    if (drops % 5 == 0) {
        max_append = buffer_size - strlen(result) - 1;
        strncat(result, "Plang", max_append);
    }
    if (drops % 7 == 0) {
        max_append = buffer_size - strlen(result) - 1;
        strncat(result, "Plong", max_append);
    }
    if (result[0] == '\0') {
        snprintf(result, buffer_size, "%d", drops);
    }
}