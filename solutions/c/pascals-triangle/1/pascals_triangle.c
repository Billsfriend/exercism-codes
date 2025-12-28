#include "pascals_triangle.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void free_triangle(uint8_t **triangle, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

uint8_t **create_triangle(size_t rows) {
    if (rows == 0) {
        uint8_t **triangle = malloc(sizeof(uint8_t*));
        triangle[0] = calloc(1, sizeof(uint8_t));
        return triangle;
    }
    uint8_t **triangle = malloc(rows * sizeof(uint8_t*));
    for (size_t i = 0; i < rows; i++) {
        triangle[i] = calloc(rows, sizeof(uint8_t));
        for (size_t j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }
    return triangle;
}