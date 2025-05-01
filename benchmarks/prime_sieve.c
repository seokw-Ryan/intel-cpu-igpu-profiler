/*  prime_sieve.c  —  Lightweight CPU benchmark
    ---------------------------------------------------------
    Generates all prime numbers ≤ N using a cache-friendly
    segmented Sieve of Eratosthenes, then prints:
      • the largest prime found
      • elapsed wall-clock time in seconds
      • primes-per-second rate

    Build:  gcc -O3 -march=native -pipe prime_sieve.c -o prime_sieve -lm
    Run  :  ./prime_sieve [N]         (default N = 500 000 000)
*/

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <string.h>

static inline double now_sec(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

int main(int argc, char *argv[]) {
    uint64_t N = (argc > 1) ? strtoull(argv[1], NULL, 10) : 500000000ULL;
    uint64_t root = (uint64_t)sqrt((double)N) + 1;

    /* small primes up to √N */
    uint8_t *is_prime = calloc(root + 1, 1);
    uint64_t *prime = malloc((root / 10) * sizeof(uint64_t));
    uint64_t pcnt = 0;

    for (uint64_t i = 2; i <= root; ++i)
        if (!is_prime[i]) {
            prime[pcnt++] = i;
            for (uint64_t j = i * i; j <= root; j += i) is_prime[j] = 1;
        }
    free(is_prime);

    /* segmented sieve */
    const uint64_t SEG = 1ULL << 20;                // 1 MB segments
    uint8_t *segment = malloc(SEG);

    double t0 = now_sec();
    uint64_t max_prime = 2, total_primes = (N >= 2);

    for (uint64_t low = 0; low <= N; low += SEG) {
        uint64_t high = (low + SEG - 1 < N) ? low + SEG - 1 : N;
        memset(segment, 0, high - low + 1);

        for (uint64_t i = 0; i < pcnt; ++i) {
            uint64_t p = prime[i];
            uint64_t start = (low + p - 1) / p * p;
            if (start < p * p) start = p * p;
            for (uint64_t j = start; j <= high; j += p)
                segment[j - low] = 1;
        }
        for (uint64_t i = (low == 0) ? 2 : 0; i <= high - low; ++i)
            if (!segment[i]) {
                ++total_primes;
                max_prime = low + i;
            }
    }
    double t1 = now_sec();
    free(segment); free(prime);

    double elapsed = t1 - t0;
    printf("largest prime ≤ %llu : %llu\n", (unsigned long long)N,
                                           (unsigned long long)max_prime);
    printf("elapsed time         : %.3f s\n", elapsed);
    printf("primes per second    : %.2f M\n",
           total_primes / (elapsed * 1e6));

    return 0;
}
