# ==============================================================================
# OrbitMesh Unit Tests
#
# Builds the OrbitMesh unit test suite.
#
# The test suite is intended to run on the host machine (Linux, macOS, Windows)
# rather than on embedded hardware.
# ==============================================================================

cmake_minimum_required(VERSION 3.20)

include(CTest)

#------------------------------------------------------------------------------
# Test Executable
#------------------------------------------------------------------------------

add_executable(
    orbitmesh_tests

    test_version.c
    test_kernel.c
    test_scheduler.c
    test_task.c
    test_timer.c
    test_hal.c
    test_gpio.c
    test_uart.c
    test_spi.c
    test_i2c.c
    test_console.c
    test_logger.c
    test_health_monitor.c
)

#------------------------------------------------------------------------------
# Include Directories
#------------------------------------------------------------------------------

target_include_directories(
    orbitmesh_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

#------------------------------------------------------------------------------
# Linked Libraries
#------------------------------------------------------------------------------

target_link_libraries(
    orbitmesh_tests
    PRIVATE
        orbitmesh_kernel
        orbitmesh_hal
        orbitmesh_drivers
        orbitmesh_services
)

#------------------------------------------------------------------------------
# Compiler Features
#------------------------------------------------------------------------------

target_compile_features(
    orbitmesh_tests
    PRIVATE
        c_std_17
)

#------------------------------------------------------------------------------
# Warnings
#------------------------------------------------------------------------------

if(MSVC)

    target_compile_options(
        orbitmesh_tests
        PRIVATE
            /W4
    )

else()

    target_compile_options(
        orbitmesh_tests
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Werror
    )

endif()

#------------------------------------------------------------------------------
# Register Tests
#------------------------------------------------------------------------------

add_test(
    NAME orbitmesh_tests
    COMMAND orbitmesh_tests
)
