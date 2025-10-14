#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna)
{
    if (dna == NULL) {
        return NULL;
    }

    size_t len = strlen(dna);
    char *rna = malloc(len + 1);
    if (rna == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        switch (dna[i]) {
            case 'A':
                rna[i] = 'U';
                break;
            case 'T':
                rna[i] = 'A';
                break;
            case 'C':
                rna[i] = 'G';
                break;
            case 'G':
                rna[i] = 'C';
                break;
            default:
                free(rna);
                return NULL; // or handle invalid input as needed
        }
    }

    rna[len] = '\0';
    return rna;
}
