#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H
#include <stddef.h>
#include <stdint.h>

// Structure to represent a single saddle point
typedef struct {
    uint8_t row;
    uint8_t column;
} saddle_point_t;

// Structure to hold all saddle points found in a matrix
typedef struct {
    size_t count;
    saddle_point_t *points;
} saddle_points_t;

// Function to find all saddle points in a matrix
// Parameters:
//   rows: number of rows in the matrix
//   columns: number of columns in the matrix
//   matrix: pointer to the matrix data (flattened 2D array)
// Returns:
//   pointer to saddle_points_t structure containing all saddle points
saddle_points_t *saddle_points(size_t rows, size_t columns, uint8_t matrix[][columns]);

// Function to free the memory allocated for saddle points
void free_saddle_points(saddle_points_t *sp);

#endif
