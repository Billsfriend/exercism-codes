#include "pangram.h"

bool is_pangram(const char *sentence) {
    if (sentence == NULL) {
        return false;
    }
    bool alphabet[26] = {false};
    for (int i = 0; sentence[i] != '\0'; i++) {
        char c = tolower((unsigned char)sentence[i]);
        if (c >= 'a' && c <= 'z') {
            alphabet[c - 'a'] = true;
        }
    }
    for (int j = 0; j < 26; j++) {
        if (!alphabet[j]) {
            return false;
        }
    }
    return true;
}