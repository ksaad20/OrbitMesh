#
# OrbitMesh CMake helpers.
#
# Provides common build configuration
# for OrbitMesh targets.
#
# Author:
#     OrbitMesh Contributors
#
# License:
#     Apache License 2.0
#


#
# Set common compiler options.
#
function(
    orbitmesh_configure_target
    target
)

    target_compile_features(
        ${target}
        PRIVATE
        c_std_11
    )


    target_compile_options(
        ${target}
        PRIVATE

        -Wall

        -Wextra

        -Werror

        -ffunction-sections

        -fdata-sections
    )


    target_include_directories(
        ${target}
        PRIVATE

        ${PROJECT_SOURCE_DIR}/include
    )

endfunction()



#
# Add OrbitMesh source directory.
#
function(
    orbitmesh_add_sources
    target
)

    target_sources(
        ${target}
        PRIVATE

        ${ARGN}
    )

endfunction()



#
# Enable embedded linker optimizations.
#
function(
    orbitmesh_enable_embedded
    target
)

    target_link_options(
        ${target}
        PRIVATE

        -Wl,--gc-sections
    )

endfunction()
