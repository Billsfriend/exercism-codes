#include "bob.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 34

const char *to_silence = "Fine. Be that way!";
const char *to_yell_question = "Calm down, I know what I'm doing!";
const char *to_question = "Sure.";
const char *to_yell = "Whoa, chill out!";
const char *to_others = "Whatever.";

char *hey_bob(char *greeting) {
    int upper_count = 0;
    int lower_count = 0;
    int all_space = 1;
    int is_question = 0;
    char *greeting_start = greeting;
    while (*greeting != '\0') {
        if (islower(*greeting)) {
            lower_count++;
        } else if (isupper(*greeting)) {
            upper_count++;
        }
        if (!isspace(*greeting)) {
            all_space = 0;
        }
        greeting++;
    }
    int all_upper = upper_count && (!lower_count);
    while (--greeting != greeting_start) {
        if (*greeting == '?') {
            is_question = 1;
            break;
        } else if (!isspace(*greeting)) {
            break;
        }
    }
    char *reply = calloc(MAX_LEN, sizeof(char));
    if (all_space) {
        strcpy(reply, to_silence);
    } else if (all_upper && is_question) {
        strcpy(reply, to_yell_question);
    } else if (all_upper) {
        strcpy(reply, to_yell);
    } else if (is_question) {
        strcpy(reply, to_question);
    } else {
        strcpy(reply, to_others);
    }
    return reply;
}