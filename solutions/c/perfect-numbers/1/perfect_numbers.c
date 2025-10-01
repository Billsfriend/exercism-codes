#include "perfect_numbers.h"

kind classify_number(int input) {
    if (input <= 0) {
        return ERROR;
    }
    if (input == 1) {
        return DEFICIENT_NUMBER;
    }
    int sum = 1;
    int biggest_factor = input;
    for (int i = 2; i < biggest_factor; i++) {
        if (input % i == 0) {
            sum += i;
            biggest_factor = input / i;
            if (i != biggest_factor) {
                sum += biggest_factor;
            }
        }
    }
    if (sum > input) {
        return ABUNDANT_NUMBER;
    } else if (sum == input) {
        return PERFECT_NUMBER;
    } else {
        return DEFICIENT_NUMBER;
    }
}