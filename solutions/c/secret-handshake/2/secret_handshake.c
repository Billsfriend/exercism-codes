#include "secret_handshake.h"
#include <stddef.h>
#include <stdlib.h>

#define MAX_COMMAND 4

static const char *all_commands[] = {"wink", "double blink", "close your eyes", "jump"};

const char **commands(size_t number) {
    const char **final_commands = calloc(MAX_COMMAND + 1, sizeof(char*));
    int command_count = 0;
    
    int reverse_seq = (number & 0x10) != 0;  // 0x10 = 16 = 2^4
    
    if (reverse_seq) {
        for (int i = MAX_COMMAND - 1; i >= 0; i--) {
            if (number & (1 << i)) {
                final_commands[command_count++] = all_commands[i];
            }
        }
    } else {
        for (int i = 0; i < MAX_COMMAND; i++) {
            if (number & (1 << i)) {
                final_commands[command_count++] = all_commands[i];
            }
        }
    }
    
    return final_commands;
}