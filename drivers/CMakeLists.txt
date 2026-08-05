# ==============================================================================
# OrbitMesh Drivers
#
# Hardware-independent peripheral driver implementations.
#
# This library builds on the Hardware Abstraction Layer (HAL) to provide
# reusable drivers for common embedded peripherals.
#
# Responsibilities:
#   - GPIO
#   - UART
#   - SPI
#   - I²C
#   - Timer
#   - LED
#   - Button
#   - Watchdog
# ==============================================================================

set(ORBITMESH_DRIVER_SOURCES
    gpio_driver.c
    uart_driver.c
    spi_driver.c
    i2c_driver.c
    timer_driver.c
    led_driver.c
    button_driver.c
    watchdog_driver.c
)

add_library(
    orbitmesh_drivers
    STATIC
    ${ORBITMESH_DRIVER_SOURCES}
)

target_include_directories(
    orbitmesh_drivers
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    orbitmesh_drivers
    PRIVATE
        orbitmesh_hal
)

target_compile_features(
    orbitmesh_drivers
    PUBLIC
        c_std_17
)

target_compile_definitions(
    orbitmesh_drivers
    PRIVATE
        ORBITMESH_DRIVERS
)

set_target_properties(
    orbitmesh_drivers
    PROPERTIES
        OUTPUT_NAME orbitmesh_drivers
        C_STANDARD 17
        C_STANDARD_REQUIRED YES
        C_EXTENSIONS NO
)

install(
    TARGETS orbitmesh_drivers
    ARCHIVE DESTINATION lib
)
