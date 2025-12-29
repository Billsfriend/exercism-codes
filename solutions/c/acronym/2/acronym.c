#include "acronym.h"
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
    if (!phrase)
        return NULL;
    size_t len = strlen(phrase);
    int first_char = 1;
    char temp_abbr[len];
    size_t abbr_count = 0;
    const char start_trigger[] = " -";
    for (size_t i = 0; i < len; i++) {
        char temp_char = phrase[i];
        if (isalpha(temp_char)) {
            if (first_char) {
                temp_abbr[abbr_count++] = temp_char;
                first_char = 0;
            }
        } else if (strchr(start_trigger, temp_char)) {
            first_char = 1;
        }
    }
    if (abbr_count == 0) {
        return NULL;
    }
    char *result = malloc((abbr_count+1) * sizeof(char));
    if (!result)
        return NULL;
    for (size_t i = 0; i < abbr_count; i++) {
        result[i] = toupper(temp_abbr[i]);
    }
    result[abbr_count] = '\0';
    return result;
}