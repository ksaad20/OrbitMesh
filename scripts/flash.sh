#!/usr/bin/env bash

#
# OrbitMesh flash script.
#
# Programs OrbitMesh firmware onto ARM Cortex-M hardware.
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

FIRMWARE="${BUILD_DIR}/orbitmesh.bin"


echo "OrbitMesh Flash"
echo "==============="


if [ ! -f "${FIRMWARE}" ]; then

    echo "Firmware not found:"
    echo "${FIRMWARE}"

    echo
    echo "Run scripts/build.sh first."

    exit 1

fi


if ! command -v openocd >/dev/null 2>&1; then

    echo "OpenOCD not installed."

    echo "Install OpenOCD and try again."

    exit 1

fi


echo "Flashing firmware..."


openocd \
    -f interface/stlink.cfg \
    -f target/stm32g4x.cfg \
    -c "program ${FIRMWARE} verify reset exit"


echo
echo "Flash completed successfully."
