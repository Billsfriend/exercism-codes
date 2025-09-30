#include "collatz_conjecture.h"

int steps(int start) {
    int steps_taken = 0;
    if (start <= 0) {
            return -1;
        }
    while (start != 1) {
        if (start % 2 == 0) {
            start = start / 2;
        } else {
            start = 3 * start + 1;
        }
        steps_taken++;
    }
    return steps_taken;

}