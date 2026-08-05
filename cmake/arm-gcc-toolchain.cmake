#
# OrbitMesh ARM GCC toolchain.
#
# Configures cross compilation for
# ARM Cortex-M targets.
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
    arm
)


#
# ARM GCC compiler.
#
set(
    CMAKE_C_COMPILER
    arm-none-eabi-gcc
)


set(
    CMAKE_CXX_COMPILER
    arm-none-eabi-g++
)


set(
    CMAKE_ASM_COMPILER
    arm-none-eabi-gcc
)


#
# Embedded compile settings.
#
set(
    CMAKE_C_FLAGS_INIT
    "-mcpu=cortex-m4 -mthumb"
)


set(
    CMAKE_EXE_LINKER_FLAGS_INIT
    "-Wl,--gc-sections"
)


#
# Prevent host library lookup.
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
