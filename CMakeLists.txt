cmake_minimum_required(VERSION 3.20)

# ==============================================================================
# OrbitMesh
# An Open-Source Operating System for Small Satellites
# ==============================================================================

project(
    OrbitMesh
    VERSION 0.1.0
    DESCRIPTION "A lightweight operating system for CubeSats and embedded spacecraft."
    LANGUAGES C
)

# ==============================================================================
# C Standard
# ==============================================================================

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# ==============================================================================
# Build Options
# ==============================================================================

option(ORBITMESH_BUILD_TESTS "Build unit tests" ON)
option(ORBITMESH_BUILD_EXAMPLES "Build example applications" ON)
option(ORBITMESH_BUILD_DOCS "Build documentation" OFF)
option(ORBITMESH_ENABLE_WARNINGS "Enable compiler warnings" ON)
option(ORBITMESH_WARNINGS_AS_ERRORS "Treat warnings as errors" ON)

# ==============================================================================
# Output Directories
# ==============================================================================

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# ==============================================================================
# Compiler Warnings
# ==============================================================================

if(ORBITMESH_ENABLE_WARNINGS)

    if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")

        add_compile_options(
            -Wall
            -Wextra
            -Wpedantic
            -Wshadow
            -Wconversion
            -Wsign-conversion
            -Wdouble-promotion
            -Wformat=2
            -Wundef
            -Wcast-align
            -Wwrite-strings
            -Wstrict-prototypes
            -Wmissing-prototypes
            -Wmissing-declarations
        )

        if(ORBITMESH_WARNINGS_AS_ERRORS)
            add_compile_options(-Werror)
        endif()

    elseif(MSVC)

        add_compile_options(/W4)

    endif()

endif()

# ==============================================================================
# Include Directories
# ==============================================================================

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# ==============================================================================
# Source Directories
# ==============================================================================

add_subdirectory(kernel)
add_subdirectory(hal)
add_subdirectory(drivers)
add_subdirectory(services)

# ==============================================================================
# Examples
# ==============================================================================

if(ORBITMESH_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# ==============================================================================
# Tests
# ==============================================================================

if(ORBITMESH_BUILD_TESTS)

    enable_testing()

    add_subdirectory(tests)

endif()

# ==============================================================================
# Installation
# ==============================================================================

install(
    DIRECTORY include/
    DESTINATION include
)

# ==============================================================================
# Summary
# ==============================================================================

message(STATUS "")
message(STATUS "========================================")
message(STATUS "OrbitMesh ${PROJECT_VERSION}")
message(STATUS "========================================")
message(STATUS "Build type      : ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler        : ${CMAKE_C_COMPILER_ID}")
message(STATUS "C Standard      : C17")
message(STATUS "Tests           : ${ORBITMESH_BUILD_TESTS}")
message(STATUS "Examples        : ${ORBITMESH_BUILD_EXAMPLES}")
message(STATUS "Warnings        : ${ORBITMESH_ENABLE_WARNINGS}")
message(STATUS "Warnings Errors : ${ORBITMESH_WARNINGS_AS_ERRORS}")
message(STATUS "========================================")
message(STATUS "")
