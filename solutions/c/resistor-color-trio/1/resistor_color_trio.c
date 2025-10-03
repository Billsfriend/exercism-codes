#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t *input) {
    resistor_value_t output;
    output.unit = input[2] / 3;
    output.value = (input[0] * 10 + input[1]) * pow(10,input[2] % 3);
    if (output.value >= 1000 && output.value % 1000 == 0) {
        output.value = output.value / 1000;
        output.unit++;
       }
    return output;
}