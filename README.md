# Intel CPU/iGPU Profiler

A comprehensive benchmarking and profiling suite for Intel CPUs and integrated GPUs using low-level Linux tools and custom C/C++ workloads.

## Overview

This project analyzes instruction throughput, caching behavior, thermal limits, and power efficiency across various workloads and system configurations on Intel hardware.

## Target System

**Samsung Galaxy Book 5 Pro**
- **Processor:** Intel® Core™ Ultra 7 258V @ 2.20 GHz
- **Memory:** 32.0 GB RAM 

## Key Features

- Custom C/C++ benchmarks for evaluating low-level CPU/GPU behavior
- Real-time profiling with tools like `perf`, `htop`, `vmstat`, `intel_gpu_top`, and `RAPL`
- Logging of cycles, instructions, thermal behavior, and power usage
- Scripts for automated profiling and data collection

## Tools & Technologies

- **Languages:** C, C++
- **Linux Tools:** 
  - `perf` - Performance counter statistics
  - `mpstat` - CPU utilization reporting
  - `vmstat` - Virtual memory statistics
  - `turbostat` - Intel CPU frequency and power data
  - `intel_gpu_top` - Intel GPU utilization monitoring
  - `RAPL` - Running Average Power Limit interface
- **Optional:** Python + Matplotlib for visual analysis

## Getting Started

*Instructions for installation and setup will be added as the project develops.*

## Usage

*Usage examples and documentation will be added as the project develops.*

## Contributing

Contributions to improve the profiler are welcome. Please feel free to submit a pull request.

## License

*License information will be added.*
