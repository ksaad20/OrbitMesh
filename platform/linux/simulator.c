/**
 * @file simulator.c
 * @brief OrbitMesh Linux simulator platform.
 *
 * Provides Linux-specific simulator initialization.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include <stdio.h>


/*==============================================================================
 * Public API
 *============================================================================*/

void
om_linux_simulator_init(void)
{
    printf(
        "OrbitMesh Linux platform initialized\n"
    );
}


void
om_linux_simulator_shutdown(void)
{
    printf(
        "OrbitMesh Linux platform shutdown\n"
    );
}
