cmake_minimum_required(VERSION 3.20)

project(orbitmesh_basic_satellite C)

add_executable(
    orbitmesh_basic_satellite
    main.c
)

target_include_directories(
    orbitmesh_basic_satellite
    PRIVATE
    ${PROJECT_SOURCE_DIR}/../../include
)

target_link_libraries(
    orbitmesh_basic_satellite
    PRIVATE
    orbitmesh_kernel
    orbitmesh_hal
    orbitmesh_drivers
    orbitmesh_services
)
