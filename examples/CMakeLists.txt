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
