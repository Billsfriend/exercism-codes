#include "saddle_points.h"
#include <stdlib.h>
#include <stdbool.h>

saddle_points_t *saddle_points(size_t rows, size_t columns, uint8_t matrix[][columns]) {
    // Allocate memory for the result structure
    saddle_points_t *result = malloc(sizeof(saddle_points_t));
    if (!result) {
        return NULL;
    }
    
    // Handle empty matrix
    if (rows == 0 || columns == 0 || matrix == NULL) {
        result->count = 0;
        result->points = NULL;
        return result;
    }
    
    // Allocate temporary storage for potential saddle points
    // Maximum possible saddle points is rows * columns
    saddle_point_t *temp_points = malloc(sizeof(saddle_point_t) * rows * columns);
    if (!temp_points) {
        free(result);
        return NULL;
    }
    
    size_t saddle_count = 0;
    
    // Check each element in the matrix
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            uint8_t current = matrix[i][j];
            bool is_saddle = true;
            
            // Check if current element is the maximum in its row
            for (size_t col = 0; col < columns; col++) {
                if (matrix[i][col] > current) {
                    is_saddle = false;
                    break;
                }
            }
            
            // If still a candidate, check if it's the minimum in its column
            if (is_saddle) {
                for (size_t row = 0; row < rows; row++) {
                    if (matrix[row][j] < current) {
                        is_saddle = false;
                        break;
                    }
                }
            }
            
            // If it's a saddle point, add it to the list
            if (is_saddle) {
                temp_points[saddle_count].row = i + 1;      // 1-indexed
                temp_points[saddle_count].column = j + 1;   // 1-indexed
                saddle_count++;
            }
        }
    }
    
    // Allocate the exact amount of memory needed
    if (saddle_count > 0) {
        result->points = malloc(sizeof(saddle_point_t) * saddle_count);
        if (!result->points) {
            free(temp_points);
            free(result);
            return NULL;
        }
        
        // Copy the saddle points to the result structure
        for (size_t i = 0; i < saddle_count; i++) {
            result->points[i] = temp_points[i];
        }
    } else {
        result->points = NULL;
    }
    
    result->count = saddle_count;
    
    // Free temporary storage
    free(temp_points);
    
    return result;
}

void free_saddle_points(saddle_points_t *sp) {
    if (sp) {
        if (sp->points) {
            free(sp->points);
        }
        free(sp);
    }
}
