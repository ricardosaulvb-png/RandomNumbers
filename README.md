# 🕒 How Random Can a Clock Be? Designing and Evaluating an Experimental Generator

This repository presents an **experimental 32-bit Pseudo-Random Number Generator (PRNG) library** for modern C++. Born from a research-driven mindset, this project explores the boundaries of low-level hardware entropy, evaluating whether the linear structure of time can be transformed into a useful chaotic sequence using native bit-shuffling routines.

The project functions as an **open laboratory** [r/cpp]. In addition to the core library architecture, it includes an automated statistical suite so any developer can clone the codebase, execute raw stress tests, and empirically audit the random quality firsthand [r/cpp].

---

## 🛠️ 1. Library Architecture and Design

The library is engineered under a strict **header-only philosophy** [r/cpp]. It requires no intricate compilation steps, external `.lib` files, or complex environmental setups; simply include the header into your project to generate high-entropy random numbers at CPU-cycle speed.

### Core Technical Pillars:
* **Stable Hardware Entropy:** It captures the high-resolution ticks of `std::chrono::steady_clock`. Unlike the traditional system clock, this is a monotonic stopwatch that **never moves backward**, making the algorithm completely immune to edge-case bugs triggered by automatic OS time adjustments or NTP protocol synchronizations [r/cpp].
* **Destruction of Linear Patterns (Thomas Wang Mixer):** Since time flows in a predictable straight line, standard fixed arithmetic operations yield highly predictable subsequences. To solve this, the library executes low-level register bit-shuffling utilizing native processor logic:
  * **Bit-Shifts (`>>`):** Displaces the raw 1s and 0s of the integer to overlay them.
  * **XOR Operations (`^`):** Smashes the linear structure by performing bit-wise toggling.
  * **Prime Hexadecimal Multiplications (`0x45d9f3b`):** Uniformly scatters the internal entropy across the full 32-bit integer range [r/cpp].
* **Pure O(1) Performance:** The implementation operates strictly on local register memory. It generates zero dynamic allocation overhead (*heap*), avoids internal loop latency, and eliminates the need for heavy data structures (like `std::vector`) to mitigate collisions, ensuring ultra-fast execution speeds.

---

## 📁 Repository Structure and Components

The experimental ecosystem is split cleanly into two primary source files located right at the root of the repository, designed to work in lockstep:

### 1. `program_test.cpp`
* **Location:** Repository Root.
* **Function:** Houses the complete source code of the **experimental library (`aleatorio()`)** integrated with a high-speed stress-testing loop in the `main` function. When compiled and run, it hammers the generator to capture **100,000 continuous samples** in a raw burst, automatically exporting them to a flat file named `datos_random.txt` directly on your Desktop.

### 2. `grafics_and_results.py`
* **Location:** Repository Root.
* **Function:** Acts as the automated, unified statistical auditing suite written in Python. It seamlessly ingests the `datos_random.txt` data payload, executes four industry-standard mathematical tests (Shannon Entropy, Monobit Bit-Frequency, Chi-Square Uniformity, and Autocorrelation) in milliseconds [r/cpp], and fires up an interactive **XY Scatter Plot** to visually validate the independence of consecutive numbers.

---

## 📊 Empirical Validation and Laboratory Benchmarks

Stressing the library through the automated Python suite exposes fascinating mathematical conclusions regarding its behavior:

* **Shannon Entropy (7.9536 bits/byte):** Demonstrates an exceptionally high symbol diversity and lack of pattern, closely reaching the 8.0 absolute theoretical limit. This indicates a high level of mathematical uncertainty, though it does not imply cryptographic security.
* **Linear Autocorrelation Coefficient (-0.0019):** Virtually zero. It mathematically proves that the bit-mixer functions properly and subsequent values remain completely independent of their consecutive neighbors.
* **Chi-Square Test (P-Value = 0.000000):** The library **fails** global uniformity under strict conditions. This transparently validates our initial hypothesis: since the root entropy source is a hardware clock, executing ultra-fast iterations clusters specific time increments, showcasing the limits of stateless PRNG designs.

---

## 🚀 Step-by-Step Execution Guide

1. **Generate Raw Data:** Open your C++ IDE, inspect the library implementation inside **`program_test.cpp`**, and execute it to generate the `datos_random.txt` data file onto your Windows Desktop environment (`C:\Users\Acer\Desktop\datos_random.txt`).
2. **Setup the Python Environment:** Install the required scientific visualization libraries by running the following command in your terminal:
   ```bash
   pip install matplotlib scipy
   ```
3. **Audit the Algorithm:** Run the testing suite directly via your permanent Windows Command Prompt (`cmd`):
   ```bash
   cd Desktop
   python grafics_and_results.py
   ```



