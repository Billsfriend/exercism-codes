#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
    size_t out_len = 0;
    for (size_t i = 0; i < integers_len; i++) {
        uint32_t integer = integers[i];
        if (integer == 0) {output[out_len++] = 0;}
        uint8_t output_array[5] = {0};
        size_t array_len = 0;
        while (integer > 0) {
            output_array[array_len] = integer & 0x7f;
            integer = integer >> 7;
            if (array_len > 0) output_array[array_len] |= 0x80;
            array_len++;
        }
        for (int j = array_len; j >= 0; j--) {
            output[out_len + array_len - j] = output_array[j-1];
        }
        out_len += array_len;
    }
    return out_len;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
    size_t out_len = 0;
    uint32_t num = 0;
    int complete = 0;
    for (size_t i = 0; i < buffer_len; i++) {
        uint8_t byte = bytes[i];
        num <<= 7;
        num |= (byte & 0x7f);
        if ((byte >> 7) == 1) {
            complete = 0;
        } else {
            output[out_len] = num;
            num = 0;
            out_len++;
            complete = 1;
        }
    }
    if (complete == 0) return -1;
    return out_len;
}
