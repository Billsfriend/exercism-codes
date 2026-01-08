#include "flower_field.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static void annotate_flower(char **annotation, const size_t rows, size_t i, size_t j) {
    const size_t cols = strlen(annotation[0]);
    size_t top = i > 0 ? (i - 1) : 0;
    size_t bottom = i < (rows - 1) ? (i + 1) : (rows - 1);
    size_t left = j > 0 ? (j - 1) : 0;
    size_t right = j < (cols - 1) ? (j + 1) : (cols - 1);
    for (size_t x = top; x <= bottom; x++) {
        for (size_t y = left; y <= right; y++) {
            if (annotation[x][y] == '*') {
                continue;
            } else {
                annotation[x][y] = (annotation[x][y] == ' ') ? '1' : (annotation[x][y] + 1); 
            }
        }
    }
}

char **annotate(const char **garden, const size_t rows) {
    // invalid input
    if (garden == NULL || rows == 0) {
        return NULL;
    }

    // initialize pointer
    char **annotation = malloc((rows + 1) * sizeof(char*));
    if (annotation == NULL) {
        return NULL;
    }

    const size_t cols = strlen(garden[0]);
    size_t flower_rows[cols * rows];
    size_t flower_cols[cols * rows];
    size_t flower_count = 0;

    for (size_t i = 0; i < rows; i++) {
        // initialize every row
        annotation[i] = malloc(sizeof(char[cols]));
        if (annotation[i] == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(annotation[j]);
            }
            free(annotation);
            return NULL;
        }
        
        // fill with space
        memset(annotation[i], ' ', cols);

        // note every flower
        for (size_t j = 0; j < cols; j++) {
            if (garden[i][j] == '*') {
                annotation[i][j] = '*';
                flower_rows[flower_count] = i;
                flower_cols[flower_count++] = j;
            }
        }

        annotation[i][cols] = '\0';
    }
    annotation[rows] = NULL;

    // mark every flower
    for (size_t k = 0; k < flower_count; k++) {
        annotate_flower(annotation, rows, flower_rows[k], flower_cols[k]);
    }

    return annotation;
}

void free_annotation(char **annotation) {
    for (int i = 0; annotation[i] != NULL; i++) {
        free(annotation[i]);
    }
    free(annotation);
}