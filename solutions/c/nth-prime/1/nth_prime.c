#include "nth_prime.h"

static int is_prime(uint32_t x) {
    for (uint32_t f = 2; f <= x/2; f++) {
        if (x % f == 0) {
            return 0;
        }
    }
    return 1;
}

uint32_t nth(uint32_t n) {
    if (n == 0) {
        return 0;
    }
    uint32_t num = 1;
    for (uint32_t i = 0; i < n; i++) {
        num++;
        while (!is_prime(num)) {
            num++;
        }
    }
    return num;
}