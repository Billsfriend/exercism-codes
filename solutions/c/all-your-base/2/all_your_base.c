#include "all_your_base.h"
#include <stddef.h>
#include <stdint.h>

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base, size_t input_length) {
    if (input_base < 2 || output_base < 2 || input_length == 0) {
        return 0;
    }
    
    int decimal = 0;
    int input_factor = 1;
    for (size_t i = 0; i < input_length; i++) {
        int8_t input_digit = digits[input_length-i-1];
        if (input_digit >= input_base || input_digit < 0) {
            return 0;
        }
        decimal += input_digit * input_factor;
        input_factor *= input_base;
    }

    if (decimal < 2) {
        digits[0] = decimal;
        return 1;
    }
    size_t output_length = 0;
    int output_factor = 1;
    while (decimal > output_factor) {
        output_factor *= output_base;
        output_length++;
    }

    for (size_t i = 0; i < output_length; i++) {
        output_factor /= output_base;
        digits[i] = decimal / output_factor;
        decimal = decimal % output_factor;
    }
    return output_length;
}