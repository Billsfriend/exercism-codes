#include "space_age.h"

float age(planet_t planet, int64_t seconds) {
    float in_earth_years[] = {
        [MERCURY] = 0.2408467, [VENUS] = 0.61519726, [EARTH] = 1.0, [MARS] = 1.8808158,
        [JUPITER] = 11.862615, [SATURN] = 29.447498, [URANUS] = 84.016846, [NEPTUNE] = 164.79132
    };
    if (planet < MERCURY || planet > NEPTUNE) {
        return -1.0f;
    }
    float planet_years = seconds / 31557600.0 / in_earth_years[planet];
    return(planet_years);
}