# ==============================================================================
# OrbitMesh Kernel
#
# Core operating system functionality.
#
# This library provides:
#   - Kernel initialization
#   - Cooperative scheduler
#   - Task management
#   - System tick
#   - Software timers
#   - Panic handling
# ==============================================================================

set(ORBITMESH_KERNEL_SOURCES
    kernel.c
    kernel_init.c
    scheduler.c
    scheduler_idle.c
    task.c
    task_create.c
    task_delay.c
    task_priority.c
    timer.c
    tick.c
    startup.c
    interrupt.c
    panic.c
    version.c
)

add_library(
    orbitmesh_kernel
    STATIC
    ${ORBITMESH_KERNEL_SOURCES}
)

target_include_directories(
    orbitmesh_kernel
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(
    orbitmesh_kernel
    PUBLIC
        c_std_17
)

target_compile_definitions(
    orbitmesh_kernel
    PUBLIC
        ORBITMESH_KERNEL
)

set_target_properties(
    orbitmesh_kernel
    PROPERTIES
        OUTPUT_NAME orbitmesh_kernel
        C_STANDARD 17
        C_STANDARD_REQUIRED YES
        C_EXTENSIONS NO
)

install(
    TARGETS orbitmesh_kernel
    ARCHIVE DESTINATION lib
)
