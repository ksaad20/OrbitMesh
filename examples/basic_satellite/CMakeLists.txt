#
# OrbitMesh Basic Satellite Example
#
# Demonstrates:
# - kernel startup
# - heartbeat service
# - health monitoring
# - telemetry workflow
#
# License:
# Apache License 2.0
#


add_executable(
    orbitmesh_basic_satellite

    main.c
)


target_link_libraries(
    orbitmesh_basic_satellite

    orbitmesh
)


target_include_directories(
    orbitmesh_basic_satellite
    PRIVATE

    ${PROJECT_SOURCE_DIR}/include
)
