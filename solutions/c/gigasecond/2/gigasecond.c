#include "gigasecond.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

void gigasecond(time_t input, char *output, size_t size) {
    input += 1000000000;
    char *str = ctime(&input);
    if (strlen(str) > size) {
        ;
    }

    const char *month_names[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    const char *month_nums[] = {
        "01", "02", "03", "04", "05", "06",
        "07", "08", "09", "10", "11", "12"
    };

    char month_str[4];
    strncpy(month_str, str + 4, 3);
    month_str[3] = '\0';

    const char *current_month_num = "00";
    for (int i = 0; i < 12; ++i) {
        if (strcmp(month_str, month_names[i]) == 0) {
            current_month_num = month_nums[i];
            break;
        }
    }

    if (str[8] == ' ') {
        str[8] = '0';
    }

    sprintf(output, "%.4s-%s-%.2s %.8s",
            str + 20,      // "yyyy"
            current_month_num,   // "mm"
            str + 8,       // "dd"
            str + 11);     // "hh:mm:ss"
}