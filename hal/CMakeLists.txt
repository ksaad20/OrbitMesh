# ==============================================================================
# OrbitMesh Hardware Abstraction Layer (HAL)
#
# Provides a hardware-independent interface for platform peripherals.
#
# Responsibilities:
#   - GPIO
#   - UART
#   - SPI
#   - I²C
#   - Timers
#   - Clock
#   - Interrupts
#   - Power
#   - Reset
# ==============================================================================

set(ORBITMESH_HAL_SOURCES
    hal.c
#   clock.c 
    gpio.c
    uart.c
#   spi.c
#   i2c.c
    timer.c
#   interrupt.c
#   power.c
#   reset.c
)

add_library(
    orbitmesh_hal
    STATIC
    ${ORBITMESH_HAL_SOURCES}
)

target_include_directories(
    orbitmesh_hal
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    orbitmesh_hal
    PUBLIC
        orbitmesh_kernel
)

target_compile_features(
    orbitmesh_hal
    PUBLIC
        c_std_17
)

target_compile_definitions(
    orbitmesh_hal
    PUBLIC
        ORBITMESH_HAL
)

set_target_properties(
    orbitmesh_hal
    PROPERTIES
        OUTPUT_NAME orbitmesh_hal
        C_STANDARD 17
        C_STANDARD_REQUIRED YES
        C_EXTENSIONS NO
)

install(
    TARGETS orbitmesh_hal
    ARCHIVE DESTINATION lib
)
