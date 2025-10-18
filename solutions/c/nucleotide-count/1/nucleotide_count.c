#include "nucleotide_count.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *count(const char *dna_strand) {
    size_t len = strlen(dna_strand);
    int acgt_count[4] = {0};
    char *output = malloc(64 * sizeof(char));
    for (size_t i = 0; i<len; i++) {
        switch (dna_strand[i]) {
            case 'A':
                acgt_count[0]++;
                break;
            case 'C':
                acgt_count[1]++;
                break;
            case 'G':
                acgt_count[2]++;
                break;
            case 'T':
                acgt_count[3]++;
                break;
            default:
                output[0] = '\0';
                return output;
        }
    }
    sprintf(output, "A:%d C:%d G:%d T:%d", acgt_count[0], acgt_count[1], acgt_count[2], acgt_count[3]);
    return output;
}