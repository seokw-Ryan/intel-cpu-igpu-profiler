## Flag Options
Here are some recommended compiler flags to test for performance comparison in C++ (assuming you're using GCC/Clang):

1. **Optimization Levels**:
```bash
-O0  # No optimization (baseline)
-O1  # Basic optimizations
-O2  # More aggressive optimizations (default for many projects)
-O3  # Maximum optimization (may sometimes be slower than O2)
-Os  # Optimize for size
-Ofast # Aggressive optimizations (may break strict standards compliance)
```

2. **Architecture-Specific Optimizations**:
```bash
-march=native  # Optimize for your specific CPU
-mtune=native  # Tune for your specific CPU
-mavx2 -mfma   # Enable AVX2 and FMA instructions (if supported)
```

3. **Link-Time Optimization**:
```bash
-flto  # Enable link-time optimizations
```

4. **Profile-Guided Optimization**:
```bash
# First compile with:
-fprofile-generate
# Run benchmarks to generate profile data
# Then recompile with:
-fprofile-use
```

5. **Parallelization**:
```bash
-fopenmp     # Enable OpenMP
-mparallel   # Auto-parallelization (Intel-specific)
```

To use these, you could create different build configurations like:
```bash
# Basic build
g++ -O2 -march=x86-64 -o myapp main.cpp

# Aggressive optimization
g++ -O3 -march=native -flto -fopenmp -o myapp_optimized main.cpp

# Profile-guided build
g++ -O3 -march=native -fprofile-generate -o myapp_profgen main.cpp
./myapp_profgen # run with typical workload
g++ -O3 -march=native -fprofile-use -o myapp_pgo main.cpp
```

For performance comparison:
1. Test each configuration separately
2. Use consistent benchmarking conditions
3. Monitor CPU frequency scaling (disable turbo boost for consistent results)
4. Check CPU utilization with `perf stat` or `time -v`

To check your CPU features (for architecture flags):
```bash
lscpu | grep Flags
# or
cat /proc/cpuinfo | grep flags
```

For Galaxy Book 5 Pro with Intel® Core™ Ultra 7 258V @ 2.20 GHz,


