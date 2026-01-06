#include "series.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

slices_t slices(char *input_text, unsigned int substring_length) {
    if (*input_text == '\0' || substring_length == 0 || substring_length > MAX_SERIES_LENGTH) {
        slices_t empty;
        empty.substring_count = 0;
        empty.substring = malloc(sizeof(char*));
        if (empty.substring != NULL) {
            empty.substring[0] = "";
        }
        return empty;
    }
    slices_t result;
    size_t len = strlen(input_text);
    result.substring_count = len - substring_length + 1;
    result.substring = malloc(result.substring_count * sizeof(char*));
    for (size_t i = 0; i <= len - substring_length; i++) {
        result.substring[i] = malloc((substring_length + 1) * sizeof(char));
        if (result.substring[i] == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(result.substring[j]);
            }
            free(result.substring);
            result.substring_count = 0;
            result.substring = NULL;
            return result;
        }
        strncpy(result.substring[i], input_text, substring_length);
        input_text++;
        result.substring[i][substring_length] = '\0';
    }
    return result;
}