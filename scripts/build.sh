#!/usr/bin/env bash

#
# OrbitMesh build script.
#
# Builds the project using CMake.
#
# Author:
#     OrbitMesh Contributors
#
# License:
#     Apache License 2.0
#

set -euo pipefail


PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

BUILD_DIR="${PROJECT_ROOT}/build"


echo "OrbitMesh Build"
echo "==============="


mkdir -p "${BUILD_DIR}"


cd "${BUILD_DIR}"


cmake \
    .. \
    -DCMAKE_BUILD_TYPE=Debug


cmake \
    --build .


echo
echo "Build completed successfully."
