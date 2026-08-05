/**
 * @file power.c
 * @brief OrbitMesh power management HAL.
 *
 * Provides platform-independent power control.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/error.h"


/**
 * @brief Initialize power subsystem.
 *
 * @return OrbitMesh status.
 */
om_error_t
om_power_init(void)
{
    return OM_SUCCESS;
}


/**
 * @brief Enter low power mode.
 */
void
om_power_sleep(void)
{
    /*
     * Platform-specific implementations
     * may use sleep instructions here.
     */
}


/**
 * @brief Reset power subsystem.
 */
void
om_power_reset(void)
{
}
