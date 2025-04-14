# 🧠 Operating System Simulations

This repository contains a collection of C/C++ implementations simulating classic Operating System algorithms. These are designed for educational and reference purposes, especially for students learning OS concepts.

## 📁 Contents

| File Name                    | Algorithm / Concept                         |
| ---------------------------- | ------------------------------------------- |
| `bankers.cpp`                | Banker's Algorithm (Deadlock Avoidance)     |
| `best_fit.cpp`               | Best Fit Memory Allocation                  |
| `dead_lock_detection.cpp`    | Deadlock Detection Algorithm                |
| `fcfs.cpp`                   | First-Come-First-Serve CPU Scheduling       |
| `hrrn.cpp`                   | Highest Response Ratio Next                 |
| `page_replacement.cpp`       | Page Replacement (FIFO, LRU, Optimal)       |
| `process.c`, `process.cpp`   | Basic Process Structure Simulations         |
| `producer_consumer_prob.cpp` | Producer-Consumer Problem (Synchronization) |
| `reader_write.cpp`           | Reader-Writer Problem (Synchronization)     |
| `round_robin.cpp`            | Round Robin Scheduling                      |
| `sjf.cpp`                    | Shortest Job First Scheduling               |
| `srtf.cpp`                   | Shortest Remaining Time First Scheduling    |

## ⚙️ How It Works

- **All inputs are hardcoded** within each source file for simplicity and demonstration purposes.
- Functions are modular and can be reused if you want to add custom input logic later.
- Compiled `.exe` and `.bin` files are included for direct execution on Windows.

> 📝 Feel free to use the existing functions if you're just exploring these algorithms or want to integrate custom input.

---

## 🚀 Running the Code

### Prerequisites

- C++ compiler like `g++`
- C compiler like `gcc` (for `process.c`)

### Compile Example (C++):

```bash
g++ page_replacement.cpp -o page_replacement
./page_replacement
```
