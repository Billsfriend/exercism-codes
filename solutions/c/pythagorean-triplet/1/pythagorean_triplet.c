#include "pythagorean_triplet.h"
#include <stdlib.h>

triplets_t *triplets_with_sum(uint16_t sum) {
   size_t count = 0;
   size_t max_triplets = (sum / 6) + 10;
   triplet_t *temp = malloc(max_triplets * sizeof(triplet_t));
   if (temp == NULL) {
      return NULL;
   }
   
   for (uint16_t i = 1; i < sum/3; i++) {
      for (uint16_t j = i+1; j <= (sum-i)/2; j++) {
         uint16_t k = sum - i - j;
         if (k > j && i*i + j*j == k*k) {
            temp[count] = (triplet_t){i, j, k};
            count++;
         }
      }
   }
   
   // Allocate result with flexible array member
   triplets_t *result = malloc(sizeof(triplets_t) + count * sizeof(triplet_t));
   if (result == NULL) {
      free(temp);
      return NULL;
   }
   result->count = count;
   
   // Copy triplets to result
   for (size_t i = 0; i < count; i++) {
      result->triplets[i] = temp[i];
   }
   
   free(temp);
   return result;
}

void free_triplets(triplets_t *triplets) {
   free(triplets);
}