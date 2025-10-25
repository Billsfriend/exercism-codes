#include "scrabble_score.h"
#include <string.h>
#define ALPHABET_SIZE 26

static const struct {
    const char letter;
    unsigned int value;
} scrabble_table[ALPHABET_SIZE] = {
    {'A',1}, {'E',1}, {'I',1}, {'O',1}, {'U',1}, {'L',1}, {'N',1}, {'R',1}, {'S',1}, {'T',1},
    {'D',2}, {'G',2},
    {'B',3}, {'C',3}, {'M',3}, {'P',3},
    {'F',4}, {'H',4}, {'V',4}, {'W',4}, {'Y',4},
    {'K',5},
    {'J',8}, {'X',8},
    {'Q',10}, {'Z',10}
};

unsigned int score(const char *word) {
    size_t len = strlen(word);
    unsigned int result = 0;
    for (size_t i = 0; i < len; i++) {
        char upper_word = word[i];
        upper_word = (upper_word >= 'a' && upper_word <= 'z') ? upper_word + ('A'-'a') : upper_word;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (upper_word == scrabble_table[j].letter) result += scrabble_table[j].value;
        }
    }
    return result;
}