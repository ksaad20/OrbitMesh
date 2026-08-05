#
# OrbitMesh Heartbeat Example
#
# Demonstrates:
# - service initialization
# - periodic task execution
# - system heartbeat monitoring
#
# License:
# Apache License 2.0
#


add_executable(
    orbitmesh_heartbeat

    main.c
)


target_link_libraries(
    orbitmesh_heartbeat

    orbitmesh
)


target_include_directories(
    orbitmesh_heartbeat
    PRIVATE

    ${PROJECT_SOURCE_DIR}/include
)
