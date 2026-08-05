#!/usr/bin/env bash

#
# OrbitMesh simulator runner.
#
# Launches the Linux simulator build.
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

SIMULATOR="${BUILD_DIR}/tools/simulator/orbitmesh_simulator"


echo "OrbitMesh Simulator"
echo "==================="


if [ ! -f "${SIMULATOR}" ]; then

    echo "Simulator binary not found."

    echo
    echo "Building project..."

    "${PROJECT_ROOT}/scripts/build.sh"

fi


echo
echo "Starting simulator..."
echo


"${SIMULATOR}"
