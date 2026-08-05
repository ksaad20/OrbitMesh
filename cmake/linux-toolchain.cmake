#
# OrbitMesh Linux toolchain.
#
# Configures native Linux builds
# for simulator and development.
#
# Author:
#     OrbitMesh Contributors
#
# License:
#     Apache License 2.0
#


set(
    CMAKE_SYSTEM_NAME
    Linux
)


set(
    CMAKE_SYSTEM_PROCESSOR
    ${CMAKE_HOST_SYSTEM_PROCESSOR}
)


#
# Native compiler.
#
set(
    CMAKE_C_COMPILER
    gcc
)


set(
    CMAKE_CXX_COMPILER
    g++
)


set(
    CMAKE_ASM_COMPILER
    gcc
)


#
# Development compile options.
#
set(
    CMAKE_C_FLAGS_INIT
    "-Wall -Wextra"
)


#
# Use host libraries.
#
set(
    CMAKE_FIND_ROOT_PATH_MODE_PROGRAM
    NEVER
)


set(
    CMAKE_FIND_ROOT_PATH_MODE_LIBRARY
    BOTH
)


set(
    CMAKE_FIND_ROOT_PATH_MODE_INCLUDE
    BOTH
)
