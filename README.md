# Intel CPU/iGPU Profiler

A comprehensive benchmarking and profiling suite for Intel CPUs and integrated GPUs using low-level Linux tools and custom C/C++ workloads.

## Overview

This project analyzes instruction throughput, caching behavior, thermal limits, and power efficiency across various workloads and system configurations on Intel hardware.

## Target System

**Samsung Galaxy Book 5 Pro**
- **Processor:** Intel® Core™ Ultra 7 258V @ 2.20 GHz
- **Memory:** 32.0 GB RAM 

## Project Structure

- `benchmarks/` - C/C++ source files for CPU and GPU benchmarks
- `scripts/` - Bash/Python automation for running tests and processing results
- `data/` - Raw log files from benchmark runs
- `results/` - Processed CSVs and visualization plots
- `docs/` - Design notes and methodology documentation

## Key Features

- Custom C/C++ benchmarks for evaluating low-level CPU/GPU behavior
- Real-time profiling with tools like `perf`, `htop`, `vmstat`, `intel_gpu_top`, and `RAPL`
- Logging of cycles, instructions, thermal behavior, and power usage
- Scripts for automated profiling and data collection

## Tools & Technologies

- **Languages:** C, C++, Python, Bash
- **Linux Tools:** 
  - `perf` - Performance counter statistics
  - `mpstat` - CPU utilization reporting
  - `vmstat` - Virtual memory statistics
  - `turbostat` - Intel CPU frequency and power data
  - `intel_gpu_top` - Intel GPU utilization monitoring
  - `RAPL` - Running Average Power Limit interface
- **Visualization:** Python + Matplotlib for analysis and reporting

## Getting Started

1. Clone this repository
2. Build the benchmarks with `cd benchmarks && make`
3. Run benchmarks with `scripts/run_bench.sh`
4. Process results with `scripts/parse_logs.py`
5. Generate plots with `scripts/plot_results.py`

## License

This project is licensed under the MIT License - see the LICENSE file for details.
