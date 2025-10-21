#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
    if(n == 1) {
        return 0;
    }
    int factor = 2;
    int factor_count = 0;
    for(; factor_count < MAXFACTORS && n > 1; factor_count++) {
        while (n % factor != 0) {
            factor++;
        }
        factors[factor_count] = factor;
        n = n / factor;
    }
    return factor_count;
}