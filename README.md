感谢[一次型解决超前进位加法器——32位CLA的实现 —— 叶逸昇]("https://yeyisheng.github.io/2024/11/21/%E4%B8%80%E6%AC%A1%E5%9E%8B%E8%A7%A3%E5%86%B3%E8%B6%85%E5%89%8D%E8%BF%9B%E4%BD%8D%E5%8A%A0%E6%B3%95%E5%99%A8%E2%80%94%E2%80%9432%E4%BD%8DCLA%E7%9A%84%E5%AE%9E%E7%8E%B0/", ), 其中详细的叙述给了我不小的帮助

# Data Lab: Bitwise Arithmetic Implementation

[![C++](https://img.shields.io/badge/C%2B%2B-23-blue.svg)](https://en.cppreference.com/w/cpp/23)
[![CMake](https://img.shields.io/badge/CMake-3.30+-blue.svg)](https://cmake.org/)
[![GoogleTest](https://img.shields.io/badge/GoogleTest-1.17.0-blue.svg)](https://github.com/google/googletest)

A computer systems programming assignment that implements integer arithmetic operations using only bitwise operators, helping students understand how computers perform basic mathematical operations at the hardware level.

## Overview

This project implements fundamental integer arithmetic operations (`add`, `subtract`, `multiply`, `divide`, `modulo`) using only bitwise operators. The goal is to demonstrate understanding of:

- Two's complement representation
- Bitwise manipulation
- Carry propagation in addition
- Shift-and-add multiplication
- Long division algorithms
- Hardware-level integer arithmetic

## Prerequisites

### System Requirements
- **C++ Compiler**: GCC 13+ or Clang 16+ with C++23 support
- **Build System**: CMake 3.30+
- **Operating System**: Linux, macOS, or Windows (with WSL2)

### Required Tools
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install build-essential cmake git clang-format clang-tidy

# macOS (with Homebrew)
brew install cmake llvm clang-format

# Windows (with Chocolatey)
choco install cmake git llvm
```

### Development Environment
- **IDE**: VS Code, CLion, or any C++ IDE
- **Version Control**: Git
- **Testing Framework**: GoogleTest (automatically downloaded via CMake)

## Building the Project

### Clone and Setup
```bash
git clone https://github.com/bmyjacks/CSC3060_data_lab.git
cd data_lab
```

### Configure with CMake
```bash
# Release build (recommended for performance)
cmake -DCMAKE_BUILD_TYPE=Release -B build

# Debug build (for development/debugging)
cmake -DCMAKE_BUILD_TYPE=Debug -B build
```

### Build
```bash
cmake --build build
```

## Running Tests

### Run All Tests
```bash
ctest --test-dir build -V
```

### Manual Test Execution
```bash
# Run test executable directly
build/test_data_lab

# With GoogleTest filters
build/test_data_lab --gtest_filter="AddTest.*"
```

### Test Coverage
The test suite includes:
- **60 total tests** across 5 function suites
- Basic functionality tests
- Edge cases (INT32_MAX, INT32_MIN, overflow)
- Bit manipulation scenarios

## Assignment Rules
Please refer to the assignment pdf.


---

**Course**: CSC3060: Computer Systems  
**Assignment**: Data Lab  
**Due Date**: January 30, 2026 23:59 UTC+8  
**Total Points**: 100
