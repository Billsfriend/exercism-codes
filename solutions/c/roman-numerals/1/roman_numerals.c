#include "roman_numerals.h"
#include <stddef.h>
#include <stdlib.h>

#define MAX_DIGIT 4
#define MAX_NUM 3999

static const char roman_num[] = "IVXLCDM";

static size_t append_digit(char *buffer, size_t pos, unsigned int digit, unsigned int base_index)
{
    char one = roman_num[base_index];
    char five = roman_num[base_index + 1];
    char ten = roman_num[base_index + 2];

    switch (digit) {
    case 1:
        buffer[pos++] = one;
        break;
    case 2:
        buffer[pos++] = one;
        buffer[pos++] = one;
        break;
    case 3:
        buffer[pos++] = one;
        buffer[pos++] = one;
        buffer[pos++] = one;
        break;
    case 4:
        buffer[pos++] = one;
        buffer[pos++] = five;
        break;
    case 5:
        buffer[pos++] = five;
        break;
    case 6:
        buffer[pos++] = five;
        buffer[pos++] = one;
        break;
    case 7:
        buffer[pos++] = five;
        buffer[pos++] = one;
        buffer[pos++] = one;
        break;
    case 8:
        buffer[pos++] = five;
        buffer[pos++] = one;
        buffer[pos++] = one;
        buffer[pos++] = one;
        break;
    case 9:
        buffer[pos++] = one;
        buffer[pos++] = ten;
        break;
    default:
        break;
    }

    return pos;
}

char *to_roman_numeral(unsigned int number) {
    if (number == 0 || number > MAX_NUM) {
        return NULL;
    }

    size_t max_len = MAX_DIGIT * MAX_DIGIT + 1;
    char *result = malloc(max_len);
    if (result == NULL) {
        return NULL;
    }

    size_t pos = 0;

    unsigned int thousands = number / 1000U;
    for (unsigned int i = 0; i < thousands; i++) {
        result[pos++] = roman_num[6];  // 'M'
    }

    number %= 1000U;

    unsigned int hundreds = number / 100U;
    pos = append_digit(result, pos, hundreds, 4);

    unsigned int tens = (number / 10U) % 10U;
    pos = append_digit(result, pos, tens, 2);

    unsigned int ones = number % 10U;
    pos = append_digit(result, pos, ones, 0);

    result[pos] = '\0';

    return result;
}