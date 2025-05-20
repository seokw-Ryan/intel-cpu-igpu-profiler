/*
 * CPU Loop Benchmark
 * 
 * This benchmark measures CPU performance by executing a series of computational loops.
 * It can be used to measure:
 * - Integer arithmetic performance
 * - Floating-point performance
 * - Memory access patterns
 * - Cache behavior
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

static double time_diff(struct timespec start, struct timespec end) {
    double sec  = end.tv_sec  - start.tv_sec;
    double nsec = end.tv_nsec - start.tv_nsec;
    return sec + nsec / 1e9;
}

int main(int argc, char *argv[]) {
    /* Number of iterations for arithmetic loops */
    size_t iterations = 100000000;  // default: 100 million
    if (argc > 1) {
        iterations = strtoull(argv[1], NULL, 10);
    }

    struct timespec t0, t1;
    double elapsed;
    
    // --- Integer arithmetic test ---
    long long i_acc = 0;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (size_t i = 0; i < iterations; ++i) {
        i_acc += (long long)i;
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    elapsed = time_diff(t0, t1);
    printf("Integer add:   %12zu ops in %8.4f s → %8.2f Mops/s\n",
           iterations, elapsed, iterations/elapsed/1e6);

    // --- Floating-point multiply test ---
    double f_acc = 1.0000001;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (size_t i = 0; i < iterations; ++i) {
        f_acc *= 1.0000001;
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    elapsed = time_diff(t0, t1);
    printf("FP multiply:  %12zu ops in %8.4f s → %8.2f Mops/s\n",
           iterations, elapsed, iterations/elapsed/1e6);

    // --- Memory sequential access test ---
    size_t array_size = 16 * 1024 * 1024;  // 16 million elements (~128 MB)
    long long *array = malloc(array_size * sizeof(*array));
    if (!array) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    // initialize
    for (size_t i = 0; i < array_size; ++i) {
        array[i] = (long long)i;
    }
    volatile long long sum = 0;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (size_t i = 0; i < array_size; ++i) {
        sum += array[i];
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    elapsed = time_diff(t0, t1);
    printf("Mem seq read:  %12zu ops in %8.4f s → %8.2f Mops/s\n",
           array_size, elapsed, array_size/elapsed/1e6);

    // --- Memory strided access test (cache‐thumping) ---
    size_t stride = 64;  // bytes / sizeof(long long) = 8 → stride=8? But here it's element count
    size_t step = stride / sizeof(long long);
    size_t accesses = array_size / step;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (size_t i = 0; i < array_size; i += step) {
        array[i] += 1;
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    elapsed = time_diff(t0, t1);
    printf("Mem stride %2zu: %8zu ops in %8.4f s → %8.2f Mops/s\n",
           stride, accesses, elapsed, accesses/elapsed/1e6);

    free((void*)array);
    return 0;
}
