#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int decimal_input) {
    unsigned int eggs = 0;
    unsigned int binary_base = 1;
    while (decimal_input > 0) {
        if ((decimal_input + binary_base) % (binary_base * 2) == 0) {
            eggs++;
            decimal_input -= binary_base;
        } else {
            ;
        }
        binary_base *= 2;
    }
    return eggs;
}