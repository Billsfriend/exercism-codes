#include "high_scores.h"

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len-1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int32_t best = 0;
    for (size_t i = 0; i < scores_len; i++) {
        if (scores[i] > best) {
            best = scores[i];
        }
    }
    return best;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
    output[0] = INT32_MIN;
    output[1] = INT32_MIN;
    output[2] = INT32_MIN;
    for (size_t i = 0; i < scores_len; i++) {
        for (int j = 0; j < 3; j++) {
            if (scores[i] > output[j]) {
                for (int k = 2; k > j; k--) {
                    output[k] = output[k-1];
                }
                output[j] = scores[i];
                break;
            }
        }
    }
    return scores_len < 3 ? scores_len : 3;
                          }
