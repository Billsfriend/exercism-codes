#include "beer_song.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char* bottle_plural(uint8_t n) {
    return (n == 1) ? "bottle" : "bottles";
}

static char* verse_line(uint8_t current, uint8_t next, int is_first_line) {
    char buffer[256];
    int len;

    if (is_first_line) {
        if (current == 0) {
            len = snprintf(buffer, sizeof(buffer),
                           "No more bottles of beer on the wall, no more bottles of beer.");
        } else {
            len = snprintf(buffer, sizeof(buffer),
                           "%u %s of beer on the wall, %u %s of beer.",
                           current, bottle_plural(current), current, bottle_plural(current));
        }
    } else {
        if (next == 0) {
            len = snprintf(buffer, sizeof(buffer),
                           "Take it down and pass it around, no more bottles of beer on the wall.");
        } else if (next == 99) {
            len = snprintf(buffer, sizeof(buffer),
                           "Go to the store and buy some more, %u %s of beer on the wall.",
                           next, bottle_plural(next));
        } else {
            len = snprintf(buffer, sizeof(buffer),
                           "Take one down and pass it around, %u %s of beer on the wall.",
                           next, bottle_plural(next));
        }
    }

    char *line = malloc(len + 1);
    if (line) {
        strcpy(line, buffer);
    }
    return line;
}

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
    uint8_t current_bottles;
    int song_index = 0;

    for (int i = 0; i < take_down; i++) {
        current_bottles = start_bottles - i;
        uint8_t next_bottles = (current_bottles > 0) ? current_bottles - 1 : 99;

        song[song_index++] = verse_line(current_bottles, next_bottles, 1);

        song[song_index++] = verse_line(current_bottles, next_bottles, 0);

        if (i < take_down - 1) {
            song[song_index] = malloc(2);
            if (song[song_index]) {
                strcpy(song[song_index], "\0");
            }
            song_index++;
        }
    }
}