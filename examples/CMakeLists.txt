#
# OrbitMesh Examples
#
# Builds available example applications.
#
# License:
# Apache License 2.0
#


#
# Basic satellite application.
#
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/basic_satellite/CMakeLists.txt")

    add_subdirectory(
        basic_satellite
    )

endif()


#
# UART echo application.
#
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/uart_echo/CMakeLists.txt")

    add_subdirectory(
        uart_echo
    )

endif()


#
# Heartbeat application.
#
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/heartbeat/CMakeLists.txt")

    add_subdirectory(
        heartbeat
    )

endif()


#
# Telemetry application.
#
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/telemetry/CMakeLists.txt")

    add_subdirectory(
        telemetry
    )

endif()


#
# Sensor polling application.
#
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/sensor_polling/CMakeLists.txt")

    add_subdirectory(
        sensor_polling
    )

endif()
