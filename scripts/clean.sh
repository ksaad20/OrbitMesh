#!/usr/bin/env bash

#
# OrbitMesh clean script.
#
# Removes generated build artifacts.
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


echo "OrbitMesh Clean"
echo "==============="


if [ -d "${BUILD_DIR}" ]; then

    rm -rf "${BUILD_DIR}"

    echo "Removed build directory."

else

    echo "No build directory found."

fi


echo "Clean completed."
