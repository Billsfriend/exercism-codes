#include "dnd_character.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

int ability(void) {
    int rolled[4];
    int min = 6;
    int sum = 0;
    for (int i = 0; i < 4; i ++) {
        rolled[i] = rand() % 6 + 1;
        if (rolled[i] < min) {
            min = rolled[i];
        }
        sum += rolled[i];
    }
    return sum - min;
}

int modifier(int score) {
    return floor((score - 10)/2.0);
}

dnd_character_t make_dnd_character(void) {
    srand(time(NULL));
    dnd_character_t new;
    new.strength = ability();
    new.dexterity = ability();
    new.constitution = ability();
    new.intelligence = ability();
    new.wisdom = ability();
    new.charisma = ability();
    new.hitpoints = 10 + modifier(new.constitution);
    return new;
}