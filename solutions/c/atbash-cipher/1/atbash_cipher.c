#include "atbash_cipher.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>

char *atbash_encode(const char *input) {
    size_t len = strlen(input);
    char *code = malloc(len * 2);
    size_t code_len = 0;
    for (size_t i = 0; i < len; i++) {
        if ((code_len + 1) % 6 == 0 && i + 1 != len) {
            code[code_len++] = ' ';
        }
        if (isalpha(input[i])) {
            char temp = tolower(input[i]);
            temp = 'z' - (temp - 'a');
            code[code_len++] = temp;
        } else if (isdigit(input[i])) {
            code[code_len++] = input[i];
        } else {
            continue;
        }
    }
    code[code_len++] = '\0';
    char *new_code = realloc(code, code_len);
    if (new_code == NULL) {
        return code;
    } else {
        return new_code;
    }
}

char *atbash_decode(const char *input) {
    size_t len = strlen(input);
    char *code = malloc(len);
    size_t code_len = 0;
    for (size_t i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            char temp = tolower(input[i]);
            temp = 'z' - (temp - 'a');
            code[code_len++] = temp;
        } else if (isdigit(input[i])) {
            code[code_len++] = input[i];
        } else {
            continue;
        }
    }
    code[code_len++] = '\0';
    char *new_code = realloc(code, code_len);
    if (new_code == NULL) {
        return code;
    } else {
        return new_code;
    }
}