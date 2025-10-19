#include "protein_translation.h"
#include <string.h>
#include <stdio.h>

protein_t protein(const char *const rna) {
    protein_t result = { .valid = true, .count = 0 };

    if (rna == NULL) {
        result.valid = false;
        return result;
    }

    size_t len = strlen(rna);

    if (len == 0) {
        return result;
    }

    static const struct {
        const char *codon;
        amino_acid_t amino_acid;
    } codon_table[] = {
        {"AUG", Methionine},
        {"UUU", Phenylalanine}, {"UUC", Phenylalanine},
        {"UUA", Leucine}, {"UUG", Leucine},
        {"UCU", Serine}, {"UCC", Serine}, {"UCA", Serine}, {"UCG", Serine},
        {"UAU", Tyrosine}, {"UAC", Tyrosine},
        {"UGU", Cysteine}, {"UGC", Cysteine},
        {"UGG", Tryptophan},
        {"UAA", Stop}, {"UAG", Stop}, {"UGA", Stop}
    };

    for (size_t i = 0; i < len; i += 3) {
        if (i + 2 >= len) {
            result.valid = false;
            break;
        }

        char current_codon[4] = {0};
        current_codon[0] = rna[i];
        current_codon[1] = rna[i+1];
        current_codon[2] = rna[i+2];

        amino_acid_t found_acid;
        bool found = false;
        for (size_t j = 0; j < sizeof(codon_table) / sizeof(codon_table[0]); ++j) {
            if (strcmp(current_codon, codon_table[j].codon) == 0) {
                found_acid = codon_table[j].amino_acid;
                found = true;
                break;
            }
        }

        if (!found) {
            result.valid = false;
            break;
        }

        if (found_acid == Stop) {
            break;
        }

        if (result.count < MAX_AMINO_ACIDS) {
            result.amino_acids[result.count++] = found_acid;
        } else {
            result.valid = false;
            break;
        }
    }

    return result;
}