#include "kindergarten_garden.h"
#include <string.h>
#define PLANT_NUMBER 4 

static const struct {char letter; plant_t plant;} char2plant[] = {
    {'C', CLOVER},
    {'G', GRASS},
    {'R', RADISHES},
    {'V', VIOLETS}
};

plants_t plants(const char *diagram, const char *student) {
    size_t len = strlen(diagram);
    int student_order = student[0] - 'A';
    int plant_order = 0;
    plants_t result;
    result.plants[0] = diagram[2 * student_order];
    result.plants[1] = diagram[2 * student_order + 1];
    
    for (size_t i = 2*student_order; i < len; i += (len/2)) {
        for (int j = 0; j < PLANT_NUMBER; j++) {
            if (diagram[i] == char2plant[j].letter) result.plants[plant_order++] = char2plant[j].plant;
        }
        i++;
        for (int j = 0; j < PLANT_NUMBER; j++) {
            if (diagram[i] == char2plant[j].letter) result.plants[plant_order++] = char2plant[j].plant;
        }
    }
    return result;
}