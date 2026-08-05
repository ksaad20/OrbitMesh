#
# OrbitMesh Blinky Example
#
# Demonstrates:
# - kernel startup
# - scheduler execution
# - GPIO driver usage
# - LED control
#
# License:
# Apache License 2.0
#


add_executable(
    orbitmesh_blinky

    main.c
)


target_link_libraries(
    orbitmesh_blinky

    orbitmesh
)


target_include_directories(
    orbitmesh_blinky
    PRIVATE

    ${PROJECT_SOURCE_DIR}/include
)
