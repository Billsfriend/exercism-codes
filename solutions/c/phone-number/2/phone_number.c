#include "phone_number.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static size_t expect_len = 10;

char *phone_number_clean(const char *input) {
    size_t len = strlen(input);

    char digit[len];
    size_t digit_count = 0;
    // strip non-digit
    for (size_t i = 0; i < len; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            digit[digit_count++] = input[i];
        }
    }
    char *result = malloc((expect_len + 1) * sizeof(char));
    // digit count not match
    if (digit_count > (expect_len+1) || digit_count < expect_len) {
        for (size_t i = 0; i < expect_len; i++) {
            result[i] = '0';
        }
        result[expect_len] = '\0';
        return result;
    }
    // remove country code
    bool country_mismatch = false;
    if (digit_count == expect_len+1) {
        country_mismatch = digit[0] != '1';
        for (size_t i = 0; i < expect_len; i++) {
            result[i] = digit[i+1];
        }
    } else {
        for (size_t i = 0; i < expect_len; i++) {
            result[i] = digit[i];
        }
    }
    // check N=2-9
    bool n_range_mismatch = result[0] < '2' || result[3] < '2';
    if (country_mismatch || n_range_mismatch) {
        for (size_t i = 0; i < expect_len; i++) {
            result[i] = '0';
        }
    }
    result[expect_len] = '\0';
    return result;
}