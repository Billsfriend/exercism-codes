#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate) {
    int remainder = candidate, digits = 0, sum = 0;
    while(remainder > 0) {
        remainder = remainder / 10;
        digits++;
    }
    remainder = candidate;
    for(int i = 1; i <= digits; i++) {
        sum += pow((remainder % 10),digits);
        remainder = remainder / 10;
    }
    return candidate == sum;
}