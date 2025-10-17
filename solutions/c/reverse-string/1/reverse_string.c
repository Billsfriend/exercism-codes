#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value) {
    size_t len = strlen(value);
    char *reverse = malloc(len+1);
    for (size_t i = 0; i < len; i++) {
        reverse[i] = value[len-1-i];
    }
    reverse[len] = '\0';
    return reverse;
}