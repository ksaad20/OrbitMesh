/**
 * @file reset.c
 * @brief OrbitMesh reset HAL implementation.
 *
 * Provides platform-independent reset control.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/error.h"


/**
 * @brief Initialize reset subsystem.
 *
 * @return OrbitMesh status.
 */
om_error_t
om_reset_init(void)
{
    return OM_SUCCESS;
}


/**
 * @brief Trigger system reset.
 */
void
om_reset_system(void)
{
    /*
     * Platform implementations may
     * invoke hardware reset registers.
     */
}
