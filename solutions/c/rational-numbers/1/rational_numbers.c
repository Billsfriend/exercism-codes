#include "rational_numbers.h"
#include <math.h>
#include <stdlib.h>

static int16_t gcd(int16_t a, int16_t b) {
    while (b != 0) {
        int16_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

rational_t add(rational_t x, rational_t y) {
    rational_t z;
    z.numerator = x.numerator * y.denominator + x.denominator * y.numerator;
    z.denominator = x.denominator * y.denominator;
    return reduce(z);
}

rational_t subtract(rational_t x, rational_t y) {
    rational_t z;
    z.numerator = x.numerator * y.denominator - x.denominator * y.numerator;
    z.denominator = x.denominator * y.denominator;
    return reduce(z);
}

rational_t multiply(rational_t x, rational_t y) {
    rational_t z;
    z.numerator = x.numerator * y.numerator;
    z.denominator = x.denominator * y.denominator;
    return reduce(z);
}

rational_t divide(rational_t x, rational_t y) {
    rational_t z;
    z.numerator = x.numerator * y.denominator;
    z.denominator = x.denominator * y.numerator;
    return reduce(z);
}

rational_t absolute(rational_t x) {
    rational_t z;
    z.numerator = x.numerator < 0 ? -x.numerator : x.numerator;
    z.denominator = x.denominator < 0 ? -x.denominator : x.denominator;
    return reduce(z);
}

rational_t exp_rational(rational_t x, int16_t a) {
    if (a == 0) {
        rational_t one = {1, 1};
        return one;
    } else if (a < 0) {
        int16_t temp = x.numerator;
        x.numerator = x.denominator;
        x.denominator = temp;
        a = -a;
    }
    rational_t z = {1, 1};
    for (int16_t i = 0; i < a; i++) {
        z.numerator *= x.numerator;
        z.denominator *= x.denominator;
    }
    return reduce(z);
}

float exp_real(uint16_t a, rational_t x) {
    return pow(a, ((float)x.numerator/(float)x.denominator));
}

rational_t reduce(rational_t x) {
    if (x.numerator == 0) {
        rational_t zero = {0, 1};
        return zero;
    }
    int16_t sign = x.numerator * x.denominator < 0 ? -1 : 1;
    x.numerator = abs(x.numerator);
    x.denominator = abs(x.denominator);
    int16_t common_divisor = gcd(x.numerator, x.denominator);
    x.numerator = x.numerator / common_divisor * sign;
    x.denominator = x.denominator / common_divisor;
    return x;
}
