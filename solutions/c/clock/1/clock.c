#include "clock.h"
#include <math.h>
#include <stdio.h>

clock_t clock_create(int hour, int minute) {
    int hour_offset = floor(minute / 60.0);
    hour += hour_offset;
    minute += -hour_offset * 60;
    int day_offset = floor(hour / 24.0);
    hour += -day_offset * 24;
    clock_t clock;
    sprintf(clock.text, "%.2d:%.2d", hour, minute);
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
    int hour, minute;
    sscanf(clock.text, "%2d:%2d", &hour, &minute);
    return clock_create(hour, minute + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
    return clock_add(clock, -minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b) {
    for (long unsigned int i = 0; i < MAX_STR_LEN; i++) {
        if (a.text[i] != b.text[i]) {
            return false;
        }
    }
    return true;
}