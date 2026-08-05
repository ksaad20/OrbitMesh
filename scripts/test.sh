#!/usr/bin/env bash

#
# OrbitMesh test script.
#
# Builds and runs the test suite.
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


echo "OrbitMesh Tests"
echo "==============="


if [ ! -d "${BUILD_DIR}" ]; then

    echo "Build directory not found."
    echo "Running build first..."

    "${PROJECT_ROOT}/scripts/build.sh"

fi


cd "${BUILD_DIR}"


echo
echo "Building test targets..."


cmake \
    --build . \
    --target tests


echo
echo "Running tests..."


ctest \
    --output-on-failure


echo
echo "All tests passed."
