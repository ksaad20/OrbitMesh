/**
 * @file startup.c
 * @brief OrbitMesh kernel startup layer.
 *
 * Provides the common startup entry path
 * before application execution.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/kernel.h"


/**
 * @brief OrbitMesh startup routine.
 *
 * Called by platform startup code.
 */
void
om_startup(void)
{
    om_kernel_init();
}
