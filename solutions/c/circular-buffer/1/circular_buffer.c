#include "circular_buffer.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>

circular_buffer_t *new_circular_buffer(size_t capacity)
{
    if (capacity == 0) {
        return NULL;
    }
    
    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));
    if (!buffer) {
        return NULL;
    }
    
    buffer->buffer = malloc(capacity * sizeof(buffer_value_t));
    if (!buffer->buffer) {
        free(buffer);
        return NULL;
    }
    
    buffer->capacity = capacity;
    buffer->read_pos = 0;
    buffer->write_pos = 0;
    buffer->count = 0;
    
    return buffer;
}

void delete_buffer(circular_buffer_t *buffer)
{
    if (buffer) {
        free(buffer->buffer);
        free(buffer);
    }
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value)
{
    if (!buffer) {
        return EXIT_FAILURE;
    }
    
    if (buffer->count >= buffer->capacity) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }
    
    buffer->buffer[buffer->write_pos] = value;
    buffer->write_pos = (buffer->write_pos + 1) % buffer->capacity;
    buffer->count++;
    
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
    if (!buffer) {
        return EXIT_FAILURE;
    }
    
    buffer->buffer[buffer->write_pos] = value;
    buffer->write_pos = (buffer->write_pos + 1) % buffer->capacity;
    
    if (buffer->count < buffer->capacity) {
        buffer->count++;
    } else {
        buffer->read_pos = (buffer->read_pos + 1) % buffer->capacity;
    }
    
    return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value)
{
    if (!buffer || !value) {
        return EXIT_FAILURE;
    }
    
    if (buffer->count == 0) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    
    *value = buffer->buffer[buffer->read_pos];
    buffer->read_pos = (buffer->read_pos + 1) % buffer->capacity;
    buffer->count--;
    
    return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer)
{
    if (buffer) {
        buffer->read_pos = 0;
        buffer->write_pos = 0;
        buffer->count = 0;
    }
}