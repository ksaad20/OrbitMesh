#!/usr/bin/env bash

#
# OrbitMesh formatting script.
#
# Applies clang-format to project source files.
#
# Author:
#     OrbitMesh Contributors
#
# License:
#     Apache License 2.0
#

set -euo pipefail


PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"


echo "OrbitMesh Format"
echo "================"


find \
    "${PROJECT_ROOT}" \
    \( \
        -name "*.c" \
        -o \
        -name "*.h" \
        -o \
        -name "*.cpp" \
    \) \
    -print0 |
while IFS= read -r -d '' file
do

    echo "Formatting: ${file}"

    clang-format \
        -i \
        "${file}"

done


echo
echo "Formatting completed."
