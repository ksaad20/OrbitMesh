#
# OrbitMesh Telemetry Example
#
# Demonstrates:
# - system diagnostics
# - health monitoring
# - telemetry output
#
# License:
# Apache License 2.0
#


add_executable(
    orbitmesh_telemetry

    main.c
)


target_link_libraries(
    orbitmesh_telemetry

    orbitmesh
)


target_include_directories(
    orbitmesh_telemetry
    PRIVATE

    ${PROJECT_SOURCE_DIR}/include
)
