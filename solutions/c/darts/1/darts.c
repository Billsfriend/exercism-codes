#include "darts.h"
#include <math.h>

int score(coordinate_t landing_position) {
    float dist_to_center;
    dist_to_center = sqrt(pow(landing_position.x, 2) + pow(landing_position.y, 2));
    if (dist_to_center > 10.0F) {
        return 0;
    } else if (dist_to_center > 5.0F) {
        return 1;
    } else if (dist_to_center > 1.0F) {
        return 5;
    } else {
        return 10;
    }
}