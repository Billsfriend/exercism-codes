#include "isogram.h"

bool is_isogram(const char phrase[]) {
    if (phrase == NULL) {
        return false;
    }
    
    int occurrences[26] = {0}; 

    for (int i = 0; phrase[i] != '\0'; i++) {
        if (!isalpha(phrase[i])) {
            continue;
        }
        
        int index = tolower(phrase[i]) - 'a';

        occurrences[index]++;

        if (occurrences[index] > 1) {
            return false;
        }
    }
    return true;
}