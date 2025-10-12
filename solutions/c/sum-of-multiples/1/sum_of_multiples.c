#include "sum_of_multiples.h"
#include <stdbool.h>
#include <string.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) {
    bool multiples[limit];
    memset(multiples, 0, sizeof(multiples));
    unsigned int sum = 0;
    for (size_t i = 0; i < number_of_factors; i++) {
        if (factors[i] == 0) {
            continue;
        }
        for (unsigned int factor = factors[i]; factor < limit; factor += factors[i]) {
            if (!multiples[factor]) {
                sum += factor;
                multiples[factor] = true;
            }
        }
    }
    return sum;
                 }