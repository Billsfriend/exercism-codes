#include "spiral_matrix.h"
#include <stdlib.h>

spiral_matrix_t *spiral_matrix_create(int size)
{
    spiral_matrix_t *result = malloc(sizeof(spiral_matrix_t));
    if (result == NULL) {
        return NULL;
    }

    if (size == 0) {
        result->size = 0;
        result->matrix = NULL;
        return result;
    }

    result->matrix = malloc(size * sizeof(int *));
    if (result->matrix == NULL) {
        free(result);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        result->matrix[i] = malloc(size * sizeof(int));
        if (result->matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(result->matrix[j]);
            }
            free(result->matrix);
            free(result);
            return NULL;
        }
    }

    result->size = size;
    int current_number = 1;
    int top = 0, bottom = size - 1;
    int left = 0, right = size - 1;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            result->matrix[top][i] = current_number++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result->matrix[i][right] = current_number++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result->matrix[bottom][i] = current_number++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result->matrix[i][left] = current_number++;
            }
            left++;
        }
    }

    return result;
}

void spiral_matrix_destroy(spiral_matrix_t *matrix)
{
    if (matrix == NULL) {
        return;
    }

    if (matrix->matrix != NULL) {
        for (int i = 0; i < matrix->size; i++) {
            free(matrix->matrix[i]);
        }
        free(matrix->matrix);
    }

    free(matrix);
}

