#include "meetup.h"
#include <time.h>
#include <string.h>

#define INVALID_TIME -1

const char* weekdays[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
};

//first, second, third, fourth, last, teenth
const char* weektype[] = {
    "first", "second", "third", "fourth", "last", "teenth"
};

static int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int get_month_days(int year, int month) {
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days[month - 1];
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week) {
                            struct tm tm_info = {0};
                            tm_info.tm_year = year - 1900;
                            tm_info.tm_mon = month - 1;
                            tm_info.tm_mday = 1;
                            tm_info.tm_hour = 12;
                            time_t timestamp = mktime(&tm_info);
                            if (timestamp == -1) {
                                return INVALID_TIME;
                            }
                            int begin_wday = tm_info.tm_wday;
                            int target_wday = 0;
                            for (;target_wday < 7; target_wday++) {
                                if (strcmp(day_of_week, weekdays[target_wday]) == 0) {
                                    break;
                                }
                            }
                            int dow_list[6] = {0};
                            dow_list[0] = (target_wday - begin_wday + 8) % 7;
                            dow_list[0] += dow_list[0] == 0 ? 7 : 0;
                            for (int i = 1; i < 5; i++) {
                                dow_list[i] = dow_list[i-1] + 7;
                                if (dow_list[i] >= 13 && dow_list[i] <= 19) dow_list[5] = dow_list[i];
                            }
                            
                            int max_day = get_month_days(tm_info.tm_year + 1900, tm_info.tm_mon + 1);
                            
                            if (dow_list[4] > max_day) {
                                dow_list[4] -= 7;
                            } else if (dow_list[4] < 1) {
                                dow_list[4] += 7;
                            }
                            
                            for (int i = 0; i < 6; i++) {
                                if (strcmp(week, weektype[i]) == 0) {
                                    return dow_list[i];
                                }
                            }
                            return INVALID_TIME;
                        }