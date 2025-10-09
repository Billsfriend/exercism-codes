#include "luhn.h"

bool luhn(const char *num) {
    int len = strlen(num);
    char striped_num[len];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (num[i] >= '0' && num[i] <= '9') {
            striped_num[j] = num[i];
            j++;
        } else if (num[i] != ' ') {
            return false;
        }
    }
    if (j <= 1) {
        return false;
    }
    int sum = 0;
    int digit;
    for (int i = 1; i <= j; i++) {
        digit = (int)(striped_num[j-i] - '0');
        if (i % 2 == 0) {
            digit *= 2;
            digit = (digit > 9) ? digit - 9 : digit;
        }
        sum += digit;
    }
    return sum % 10 == 0;
}