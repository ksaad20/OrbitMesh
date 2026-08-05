#
# OrbitMesh RISC-V GCC toolchain.
#
# Configures cross compilation for
# RISC-V embedded targets.
#
# Author:
#     OrbitMesh Contributors
#
# License:
#     Apache License 2.0
#


set(
    CMAKE_SYSTEM_NAME
    Generic
)


set(
    CMAKE_SYSTEM_PROCESSOR
    riscv
)


#
# RISC-V GCC compiler.
#
set(
    CMAKE_C_COMPILER
    riscv64-unknown-elf-gcc
)


set(
    CMAKE_CXX_COMPILER
    riscv64-unknown-elf-g++
)


set(
    CMAKE_ASM_COMPILER
    riscv64-unknown-elf-gcc
)


#
# Default embedded ISA.
#
set(
    CMAKE_C_FLAGS_INIT
    "-march=rv32imac -mabi=ilp32"
)


set(
    CMAKE_EXE_LINKER_FLAGS_INIT
    "-Wl,--gc-sections"
)


#
# Prevent host dependency lookup.
#
set(
    CMAKE_FIND_ROOT_PATH_MODE_PROGRAM
    NEVER
)


set(
    CMAKE_FIND_ROOT_PATH_MODE_LIBRARY
    ONLY
)


set(
    CMAKE_FIND_ROOT_PATH_MODE_INCLUDE
    ONLY
)
