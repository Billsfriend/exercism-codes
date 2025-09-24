#include "hamming.h"

int compute(const char *lhs, const char *rhs){
    int sum = 0, i = 0;
    for (i = 0; lhs[i] != '\0' || rhs[i] != '\0'; i++) {
        if (lhs[i] == '\0' || rhs[i] == '\0') {
            return -1;
        } else if (lhs[i] != rhs[i]) {
            sum++;
        }
    }
    return sum;
}