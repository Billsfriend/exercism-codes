#include "binary.h"
#include <string.h>

int convert(const char *input) {
    if (input == NULL) {
        return INVALID;
    }
    size_t len = strlen(input);
    int output = 0;
    int binary_base = 1;
    for (int i = len-1; i >= 0; i--) {
        if (input[i] == '1') {
            output += binary_base;
        } else if (input[i] == '0'){
            ;
        } else {
            return INVALID;
        }
        binary_base *= 2;
    }
    return output;
}