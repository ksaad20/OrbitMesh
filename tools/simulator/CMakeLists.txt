/**
 * @file CMakeLists.txt
 * @brief OrbitMesh Linux simulator build configuration.
 *
 * Builds the desktop simulator used for development and CI testing.
 *
 * @copyright Apache License 2.0
 */


add_executable(
    orbitmesh_simulator

    simulator.c
)


target_link_libraries(
    orbitmesh_simulator

    orbitmesh
)


target_include_directories(
    orbitmesh_simulator

    PRIVATE

    ${PROJECT_SOURCE_DIR}/include
)
