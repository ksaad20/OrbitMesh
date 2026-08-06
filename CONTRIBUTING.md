# Contributing to OrbitMesh

Thank you for your interest in contributing to **OrbitMesh**.

OrbitMesh is an open-source operating system designed for satellite and embedded systems with a strong focus on reliability, determinism, portability, and maintainability. Every contribution, whether code, documentation, testing, or issue reporting, is appreciated.

---

# Code of Conduct

By participating in this project, you agree to:

* Be respectful and constructive.
* Welcome contributors of all experience levels.
* Provide helpful feedback.
* Focus discussions on improving the project.

---

# Getting Started

1. Fork the repository.
2. Create a feature branch.

```bash
git checkout -b feature/my-feature
```

3. Make your changes.
4. Run the complete build and test suite.
5. Commit your changes.
6. Push your branch.
7. Open a Pull Request.

---

# Development Requirements

OrbitMesh currently targets:

* C17
* CMake ≥ 3.20
* GCC
* Clang

Recommended tools:

* CMake
* Ninja
* Git
* Clang-Format
* Clang-Tidy

---

# Building

Configure the project:

```bash
cmake -S . -B build
```

Build:

```bash
cmake --build build
```

Run tests:

```bash
cd build
ctest --output-on-failure
```

---

# Coding Style

Please follow the existing project style.

General guidelines:

* Use C17.
* Use descriptive identifiers.
* Prefer readability over cleverness.
* Avoid dynamic memory in kernel code unless explicitly required.
* Keep functions focused on a single responsibility.
* Document all public APIs.
* Use `const` whenever appropriate.
* Avoid compiler-specific extensions.

---

# Commit Messages

Write clear commit messages.

Examples:

```
kernel: add cooperative scheduler

hal: implement UART configuration

drivers: fix GPIO initialization

docs: improve scheduler documentation
```

---

# Pull Requests

Before submitting a Pull Request, ensure:

* The project builds successfully.
* All tests pass.
* New functionality includes appropriate tests.
* Public APIs are documented.
* Existing functionality is not broken.

Small, focused pull requests are preferred over very large ones.

---

# Reporting Issues

When opening an issue, please include:

* OrbitMesh version
* Compiler
* Operating system
* Steps to reproduce
* Expected behavior
* Actual behavior
* Relevant logs or screenshots

A minimal reproducible example is highly encouraged.

---

# Documentation Contributions

Documentation improvements are always welcome.

Examples include:

* README improvements
* API documentation
* Tutorials
* Architecture diagrams
* Examples

---

# Areas for Contribution

Contributors are especially encouraged to help with:

* Kernel development
* Scheduler improvements
* Memory management
* Hardware abstraction layer
* Device drivers
* Testing
* Documentation
* Build system
* Continuous Integration
* Examples

---

# Licensing

By submitting a contribution, you agree that your work will be licensed under the Apache License 2.0 used by this project.

---

Thank you for helping make OrbitMesh better.

