/**
 * @file simulator.c
 * @brief OrbitMesh Linux simulator entry point.
 *
 * Provides a desktop environment for running OrbitMesh
 * without embedded hardware.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/kernel.h"
#include "orbitmesh/hal.h"

#include <stdio.h>


/**
 * @brief Simulator entry point.
 */
int
main(void)
{
    printf(
        "OrbitMesh Linux Simulator\n");


    printf(
        "Initializing HAL...\n");


    om_hal_init();


    printf(
        "Starting kernel...\n");


    om_kernel_start();


    return 0;
}
