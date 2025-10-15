#include "sieve.h"

/// Calculate at most `max_primes` prime numbers in the interval [2,limit]
/// using the Sieve of Eratosthenes and store the prime numbers in `primes`
/// in increasing order.
/// The function returns the number of calculated primes.
uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    int prime_mark[limit-1];
    for (size_t i = 0; i < limit-1; i++) {
        prime_mark[i] = 1;
    }
    size_t prime_index = 0;
    for (size_t i = 2; i <= limit; i++) {
        if (prime_index == max_primes) {
            break;
        }
        if (prime_mark[i-2]) {
            primes[prime_index] = i;
            prime_index++;
            for (size_t j = 2*i; j <= limit; j += i) {
                prime_mark[j-2] = 0;
            }
        }
    }
    return prime_index;
}