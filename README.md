# OrbitMesh

[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.21816589.svg)](https://doi.org/10.5281/zenodo.21816589)
[![License: Apache-2.0](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](LICENSE)
[![C17](https://img.shields.io/badge/C-C17-blue.svg)](https://en.cppreference.com/w/c/17)
[![CMake](https://img.shields.io/badge/CMake-3.20+-064F8C.svg?logo=cmake)](https://cmake.org)
[![GitHub Actions](https://github.com/ksaad20/OrbitMesh/actions/workflows/ci.yml/badge.svg)](https://github.com/ksaad20/OrbitMesh/actions/workflows/ci.yml)
[![GitHub release](https://img.shields.io/github/v/release/ksaad20/OrbitMesh)](https://github.com/ksaad20/OrbitMesh/releases)
[![GitHub tag](https://img.shields.io/github/v/tag/ksaad20/OrbitMesh)](https://github.com/ksaad20/OrbitMesh/tags)
[![GitHub issues](https://img.shields.io/github/issues/ksaad20/OrbitMesh)](https://github.com/ksaad20/OrbitMesh/issues)
[![GitHub pull requests](https://img.shields.io/github/issues-pr/ksaad20/OrbitMesh)](https://github.com/ksaad20/OrbitMesh/pulls)
[![GitHub stars](https://img.shields.io/github/stars/ksaad20/OrbitMesh?style=social)](https://github.com/ksaad20/OrbitMesh/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/ksaad20/OrbitMesh?style=social)](https://github.com/ksaad20/OrbitMesh/network/members)
[![GitHub contributors](https://img.shields.io/github/contributors/ksaad20/OrbitMesh)](https://github.com/ksaad20/OrbitMesh/graphs/contributors)
[![Last Commit](https://img.shields.io/github/last-commit/ksaad20/OrbitMesh)](https://github.com/ksaad20/OrbitMesh/commits/main)
[![Repo Size](https://img.shields.io/github/repo-size/ksaad20/OrbitMesh)](https://github.com/ksaad20/OrbitMesh)
[![Code Size](https://img.shields.io/github/languages/code-size/ksaad20/OrbitMesh)](https://github.com/ksaad20/OrbitMesh)
[![Top Language](https://img.shields.io/github/languages/top/ksaad20/OrbitMesh)](https://github.com/ksaad20/OrbitMesh)
[![OpenSSF Scorecard](https://api.securityscorecards.dev/projects/github.com/ksaad20/OrbitMesh/badge)](https://securityscorecards.dev/viewer/?uri=github.com/ksaad20/OrbitMesh)
[![GitHub Pages](https://img.shields.io/badge/docs-GitHub%20Pages-blue)](https://ksaad20.github.io/OrbitMesh/)

<p align="center">
  <strong>An Open-Source Operating System for Small Satellites.</strong>
</p>

<p align="center">
  <em>Simple. Portable. Reliable.</em>
</p>

---

## Overview

**OrbitMesh** is a lightweight, open-source operating system designed for CubeSats, nanosatellites, educational spacecraft, and embedded space systems.

The project's goal is to provide a minimal yet production-oriented operating system that allows developers to build satellite software without starting from scratch. OrbitMesh focuses on portability, deterministic execution, and a clean architecture that can scale from university CubeSat missions to more advanced spacecraft.

---

## Why OrbitMesh?

Many small satellite teams spend months building infrastructure before they can begin developing mission software.

OrbitMesh provides that foundation so developers can focus on their payload, mission objectives, and research instead of reinventing core operating system components.

---

# MVP Goals

* Lightweight and easy to understand
* Portable across multiple processors
* Reliable deterministic execution
* Hardware-independent architecture
* Fast development workflow
* Open-source from the beginning

---

# MVP Features

## Real-Time Task Scheduler

A lightweight scheduler for deterministic task execution.

* Periodic tasks
* Priority scheduling
* Task delays
* Cooperative scheduling

---

## Hardware Abstraction Layer (HAL)

Write mission software once and port it to multiple processors.

Initial support includes:

* GPIO
* UART
* SPI
* I²C
* System timers

---

## Driver Framework

A simple, consistent interface for embedded peripherals.

Initial drivers:

* UART
* GPIO
* Timer
* SPI
* I²C

---

## Serial Debug Console

A built-in serial console for:

* Boot logs
* Error reporting
* Runtime diagnostics
* Debug messages

---

## Software Timer Service

Reliable software timers for:

* Sensor polling
* Periodic telemetry
* Health monitoring
* Timeouts

---

## Basic Health Monitor

Continuously monitors:

* Task execution
* System uptime
* Scheduler status

Provides early detection of software failures.

---

## CMake Build System

Simple cross-platform build system supporting:

* Local development
* Cross compilation
* Continuous Integration

---

## Documentation

Developer-focused documentation including:

* Quick Start
* Porting Guide
* Driver Development Guide
* Example Applications

---

# Planned Project Structure

```text
orbitmesh/
├── kernel/
├── hal/
├── drivers/
├── include/
├── examples/
├── tests/
├── docs/
├── scripts/
├── platform/
├── tools/
├── CMakeLists.txt
├── LICENSE
└── README.md
```

---

# Example Applications

The MVP will include working examples such as:

* LED blinker
* Periodic telemetry transmitter
* Sensor polling task
* UART command shell
* System heartbeat monitor

These examples are intended to help developers bring up new hardware quickly.

---

# Design Principles

* Simplicity over complexity
* Deterministic behavior
* Minimal dependencies
* Small memory footprint
* Clean modular architecture
* Easy portability
* Thorough documentation

---

# Target Platforms

Initial targets:

* ARM Cortex-M
* RISC-V
* Desktop simulation (Linux)

Additional architectures will be added as the project matures.

---

# Roadmap

### Version 0.1

* Kernel
* Scheduler
* HAL
* UART
* GPIO
* Timers
* Documentation

### Version 0.2

* SPI
* I²C
* Driver framework
* Example applications

### Version 0.3

* Health monitoring
* Improved diagnostics
* Platform ports
* CI testing

---

# Contributing

OrbitMesh welcomes contributions from embedded developers, aerospace engineers, researchers, students, and open-source contributors.

Whether you're improving documentation, adding board support, writing drivers, fixing bugs, or developing new features, your contributions help make spacecraft software more accessible.

---

# License

Licensed under the Apache License 2.0.

