# ==============================================================================
# OrbitMesh Services
#
# High-level operating system services built on top of the kernel,
# hardware abstraction layer, and device drivers.
#
# Current MVP Services:
#   - Logging
#   - Health monitoring
#   - Telemetry
#   - Event logging
#
# Planned Services:
#   - Serial console
#   - Software timers
#   - Heartbeat
#   - Diagnostics
#   - Uptime service
#   - Watchdog service
# ==============================================================================

set(ORBITMESH_SERVICE_SOURCES
    logger.c

    # Flight software services
    health_monitor.c
    telemetry.c
    telemetry_packet.c
    event_log.c

    # --------------------------------------------------------------------------
    # Planned services (enable as implemented)
    # --------------------------------------------------------------------------
    # console.c
    # software_timer.c
    # heartbeat.c
    # uptime.c
    # diagnostics.c
    # watchdog.c
)

add_library(
    orbitmesh_services
    STATIC
    ${ORBITMESH_SERVICE_SOURCES}
)

target_include_directories(
    orbitmesh_services
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    orbitmesh_services
    PRIVATE
        orbitmesh_kernel
        orbitmesh_hal
        # orbitmesh_drivers
)

target_compile_features(
    orbitmesh_services
    PUBLIC
        c_std_17
)

target_compile_definitions(
    orbitmesh_services
    PRIVATE
        ORBITMESH_SERVICES
)

set_target_properties(
    orbitmesh_services
    PROPERTIES
        OUTPUT_NAME orbitmesh_services
        C_STANDARD 17
        C_STANDARD_REQUIRED YES
        C_EXTENSIONS NO
)

install(
    TARGETS orbitmesh_services
    ARCHIVE DESTINATION lib
)
