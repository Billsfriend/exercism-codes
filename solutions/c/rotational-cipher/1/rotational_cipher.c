#include "rotational_cipher.h"
#include <string.h>
#include <stdlib.h>

char *rotate(const char *text, int shift_key) {
    int len = strlen(text);
    char *cipher = malloc(len + 1);
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            cipher[i] = 'a' + (text[i] - 'a' + shift_key) % 26;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            cipher[i] = 'A' + (text[i] - 'A' + shift_key) % 26;
        } else {
            cipher[i] = text[i];
        }
    }
    cipher[len] = '\0';
    return cipher;
}