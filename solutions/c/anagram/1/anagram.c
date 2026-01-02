#include "anagram.h"
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

static bool is_anagram(const char *subject, const char *candidate) {
   size_t len = strlen(subject);
   // Count letter frequencies in subject
   int subject_count[26] = {0};
   for (size_t i = 0; i < len; i++) {
      char c = tolower(subject[i]);
      if (c >= 'a' && c <= 'z') {
         subject_count[c - 'a']++;
      }
   }
   
   // Subtract letter frequencies from candidate
   for (size_t i = 0; i < len; i++) {
      char c = tolower(candidate[i]);
      if (c >= 'a' && c <= 'z') {
         subject_count[c - 'a']--;
      }
      if (subject_count[c - 'a'] < 0) {
         return false;
      }
   }
   
   return true;
}

/**
 * @description - determines if any of the words in candidate are anagrams
 *                for subject. Contents of candidate structures may be modified.
 */
void find_anagrams(const char *subject, struct candidates *candidates) {
   size_t len = strlen(subject);
   for (size_t i = 0; i < candidates->count; i++) {
      if (candidates->candidate[i].is_anagram == UNCHECKED) {
         // check word length to avoid index out of bounds
         if (len != strlen(candidates->candidate[i].word)) {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
            continue;
         }
         // identical words are not anagrams
         size_t j = 0;
         for (; j < len; j++) {
            if (tolower(subject[j]) != tolower(candidates->candidate[i].word[j])) {
               break;
            }
         }
         if (j == len) {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
         } else {
            // check if the words are anagrams
            if (is_anagram(subject, candidates->candidate[i].word)) {
               candidates->candidate[i].is_anagram = IS_ANAGRAM;
            } else {
               candidates->candidate[i].is_anagram = NOT_ANAGRAM;
            }
         }
      }
   }
}