#include "acronym.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *abbreviate(const char *phrase) {
    if (!phrase) {
        return NULL;
    }
    size_t len = strlen(phrase);
    bool first_char = true;
    char temp_abbr[len];
    size_t abbr_count = 0;
    for (size_t i = 0; i < len; i++) {
        char temp_char = phrase[i];
        if ((temp_char >= 'a' && temp_char <= 'z') || (temp_char >= 'A' && temp_char <= 'Z')) {
            if (first_char) {
                temp_abbr[abbr_count++] = temp_char;
                first_char = false;
            }
        } else if (temp_char != '\'') {
            first_char = true;
        }
    }
    if (abbr_count == 0) {
        return NULL;
    }
    char *result = malloc((abbr_count+1) * sizeof(char));
    if (!result) {
        return NULL;
    }
    for (size_t i = 0; i < abbr_count; i++) {
        if (temp_abbr[i] >= 'a' && temp_abbr[i] <= 'z') {
            temp_abbr[i] += ('A' - 'a');
        }
        result[i] = temp_abbr[i];
    }
    result[abbr_count] = '\0';
    return result;
}