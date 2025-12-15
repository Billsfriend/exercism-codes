#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{
    complex_t c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

complex_t c_sub(complex_t a, complex_t b)
{
    complex_t minus_b = {
        .real = -b.real,
        .imag = -b.imag
    };
    return c_add(a, minus_b);
}

complex_t c_mul(complex_t a, complex_t b)
{
    complex_t c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

complex_t c_div(complex_t a, complex_t b)
{
    complex_t c;
    c.real = (a.real * b.real + a.imag * b.imag) / pow(c_abs(b), 2);
    c.imag = (a.imag * b.real - a.real * b.imag) / pow(c_abs(b), 2);
    return c;
}

double c_abs(complex_t x)
{
    return sqrt(pow(x.real, 2) + pow(x.imag, 2));
}

complex_t c_conjugate(complex_t x)
{
    complex_t c = {
        .real = x.real,
        .imag = -x.imag
    };
    return c;
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    complex_t c;
    c.real = exp(x.real) * cos(x.imag);
    c.imag = exp(x.real) * sin(x.imag);
    return c;
}
