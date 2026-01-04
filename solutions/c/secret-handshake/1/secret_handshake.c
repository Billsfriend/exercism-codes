#include "secret_handshake.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND 4

static const char *all_commands[] = {"wink", "double blink", "close your eyes", "jump"};

const char **commands(size_t number) {
    int binary_seq[MAX_COMMAND + 1];
    int binary_count = 0;
    int reverse_seq = 0;
    while (number > 0) {
        binary_seq[binary_count++] = number % 2;
        number /= 2;
    }
    if (binary_count > MAX_COMMAND) {
        reverse_seq = 1;
        binary_count--;
    }
    const char **final_commands = calloc(MAX_COMMAND, sizeof(char*));
    int command_count = 0;
    if (reverse_seq) {
        for (int i = binary_count-1; i >= 0; i--) {
            if (binary_seq[i]) {
                final_commands[command_count++] = all_commands[i];
            }
        }
    } else {
        for (int i = 0; i < binary_count; i++) {
            if (binary_seq[i]) {
                final_commands[command_count++] = all_commands[i];
            }
        }
    }
    return final_commands;
}