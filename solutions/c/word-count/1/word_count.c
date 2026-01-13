#include "word_count.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

int count_words(const char *sentence, word_count_word_t *words) {
    size_t word_count = 0;
    while (*sentence != '\0') {
        // detect start of word
        if (isalnum(*sentence)) {
            size_t word_len = 0;
            char temp_word[MAX_WORD_LENGTH+1];
            // reach end of word
            while (isalnum(*sentence) || *sentence == '\'') {
                if (word_len == MAX_WORD_LENGTH) {
                    return EXCESSIVE_LENGTH_WORD;
                }
                temp_word[word_len++] = tolower(*sentence);
                sentence++;
            }
            temp_word[word_len] = '\0'; // Add null terminator
            // Remove trailing apostrophes
            size_t end = word_len - 1;
            while (end > 0 && temp_word[end] == '\'') end--;
            if (end < word_len - 1) {
                memmove(temp_word, temp_word, end + 1);
                temp_word[end + 1] = '\0';
                word_len = end + 1;
                if (word_len == 0) {
                    continue;
                }
            }
            // check if word is unique
            int unique_word = 1;
            for (size_t i = 0; i < word_count; i++) {
                if (strcmp(temp_word, words[i].text) == 0) {
                    unique_word = 0;
                    words[i].count++;
                    break;
                }
            }
            if (unique_word) {
                if (word_count == MAX_WORDS) {
                    return EXCESSIVE_NUMBER_OF_WORDS;
                }
                strcpy(words[word_count].text, temp_word);
                words[word_count].count = 1;
                word_count++;
            }
        } else {
            sentence++;
        }
    }
    return word_count;
}