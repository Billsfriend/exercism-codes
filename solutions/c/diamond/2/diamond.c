#include "diamond.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char **make_diamond(const char letter) {
    if (letter > 'Z' || letter < 'A') {
        return NULL;
    }
    int axis_len = letter - 'A';
    int line_count = axis_len * 2 + 1;
    char **diamond = malloc(line_count * sizeof(char*));
    if (diamond == NULL) {
        return NULL;
    }
    for (int i = 0; i < line_count; i++) {
        diamond[i] = malloc(sizeof(char[line_count]));
        if (diamond[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(diamond[j]);
                free(diamond);
                return NULL;
            }
        }
        for (int j = 0; j < line_count; j++) {
            char temp_letter = 'A' + i > letter ? 2 * letter - 'A' - i : 'A' + i;
            int l1 = ((i + j) == axis_len);
            int l2 = ((i + j) == 3 * axis_len);
            int l3 = ((i - j) == axis_len);
            int l4 = ((j - i) == axis_len);
            diamond[i][j] = l1 || l2 || l3 || l4 ? temp_letter : ' ';
        }
        diamond[i][line_count] = '\0';
    }
    return diamond;
}

void free_diamond(char **diamond) {
    if (diamond == NULL) {
        return;
    }
    size_t len = strlen(diamond[0]);
    for (size_t i = 0; i < len; i++) {
        free(diamond[i]);
    }
    free(diamond);
}