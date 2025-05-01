📊 CPU Core Usage Monitoring (Linux)
To analyze how your benchmark utilizes CPU cores:

htop: Real-time, per-core usage and process tracking
→ sudo apt install htop → htop

taskset: Run a program on specific cores
→ taskset -c 0 ./prime_sieve

top -H -p <PID>: Monitor thread-level activity

mpstat: Per-core usage summary
→ mpstat -P ALL 1

perf top: Low-level profiling of function usage
→ sudo perf top

