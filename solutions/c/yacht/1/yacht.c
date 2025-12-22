#include "yacht.h"

int score(dice_t dice, category_t category) {
    int result = 0;
    if (category <= SIXES) {
        for (int i = 0; i<5; i++) {
            if (dice.faces[i] == (int)category) {
                result += category;
            }
        }
    } else if (category == CHOICE) {
        for (int i = 0; i<5; i++) {
            result += dice.faces[i];
        }
    } else if (category == YACHT) {
        for (int i = 0; i<4; i++) {
            if (dice.faces[i] != dice.faces[i+1]) {
                return 0;
            }
        }
        result = 50;
    } else if (category <= BIG_STRAIGHT) {
        int face_count[7] = {0};
        for (int i = 0; i<5; i++) {
            face_count[dice.faces[i]]++;
        }
        
        if (category == LITTLE_STRAIGHT) {
            for (int i = 1; i < 6; i++) {
                if (face_count[i] != 1) return 0;
            }
            result = 30;
        } else if (category == BIG_STRAIGHT) {
            for (int i = 2; i < 7; i++) {
                if (face_count[i] != 1) return 0;
            }
            result = 30;
        } else if (category == FOUR_OF_A_KIND) {
            for (int i = 1; i<7; i++) {
                if (face_count[i] >= 4) return i * 4;
            }
            result = 0;
        } else if (category == FULL_HOUSE) {
            int three_sum = 0;
            int two_sum = 0;
            for (int i = 1; i<7; i++) {
                if (face_count[i] == 3) three_sum = 3 * i;
                if (face_count[i] == 2) two_sum = 2 * i;
            }
            result = three_sum > 0 && two_sum > 0 ? three_sum + two_sum : 0;
        }
    }
    return result;
}