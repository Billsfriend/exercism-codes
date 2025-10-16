#include "square_root.h"

int square_root(int num) {
    int low = 1;
    int high = num;
    while (low <= high) {
        int mid = (high + low)/2;
        int guess = mid * mid;
        if (guess == num) {
            return mid;
        } else if (guess > num) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return -1;
}