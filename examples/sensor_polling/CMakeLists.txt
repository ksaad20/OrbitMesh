#
# OrbitMesh Sensor Polling Example
#
# Demonstrates:
# - periodic sensor tasks
# - peripheral communication pattern
# - data acquisition workflow
#
# License:
# Apache License 2.0
#


add_executable(
    orbitmesh_sensor_polling

    main.c
)


target_link_libraries(
    orbitmesh_sensor_polling

    orbitmesh
)


target_include_directories(
    orbitmesh_sensor_polling
    PRIVATE

    ${PROJECT_SOURCE_DIR}/include
)
