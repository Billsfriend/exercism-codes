#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int allergen_code) {
    return (allergen_code & (1 << allergen)) != 0;
}

allergen_list_t get_allergens(int allergen_code) {
    allergen_list_t allergen_list;
    allergen_list.count = 0;
    for (int i = 0; i < ALLERGEN_COUNT; i++) {
        if (allergen_code & (1 << i)) {
            allergen_list.allergens[i] = true;
            allergen_list.count++;
        } else {
            allergen_list.allergens[i] = false;
        }
    }
    return allergen_list;
}