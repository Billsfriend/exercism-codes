#include "grains.h"

uint64_t square(uint8_t index) {
    return index == 1 ? 1ULL : square(index-1) * 2ULL;
}

uint64_t total(void) {
    uint64_t sum = 0ULL;
    for (uint8_t i = 1; i <= 64; i++) {
        sum += square(i);
    }
    return sum;
}