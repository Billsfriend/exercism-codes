#include "two_fer.h"
#include <stdio.h>

const int buffer_size = 100;

void two_fer(char *buffer, const char *name) {
    if (name == NULL) {
        snprintf(buffer, buffer_size , "One for you, one for me.");
    } else {
        snprintf(buffer, buffer_size , "One for %s, one for me.", name);
    }
}