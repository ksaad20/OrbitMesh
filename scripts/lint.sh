#!/usr/bin/env bash

#
# OrbitMesh lint script.
#
# Runs static analysis checks.
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


echo "OrbitMesh Lint"
echo "=============="


if [ ! -d "${BUILD_DIR}" ]; then

    echo "Build directory not found."
    echo "Run scripts/build.sh first."

    exit 1

fi


echo
echo "Running clang-tidy..."


find \
    "${PROJECT_ROOT}" \
    \( \
        -name "*.c" \
        -o \
        -name "*.cpp" \
    \) \
    -print0 |
while IFS= read -r -d '' file
do

    echo "Checking: ${file}"

    clang-tidy \
        "${file}" \
        -- \
        -I"${PROJECT_ROOT}/include"

done


echo
echo "Lint completed successfully."
