/**
 * @file watchdog_driver.c
 * @brief OrbitMesh watchdog driver.
 *
 * Provides a generic watchdog interface built
 * on top of the HAL layer.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/error.h"

#include <stdint.h>


/*==============================================================================
 * External HAL Functions
 *============================================================================*/

extern om_error_t
om_watchdog_init(
    uint32_t timeout_ms);


extern om_error_t
om_watchdog_feed(void);


extern om_error_t
om_watchdog_reset(void);


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize watchdog driver.
 *
 * @param timeout_ms Reset timeout.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_watchdog_driver_init(
    uint32_t timeout_ms)
{
    return om_watchdog_init(
        timeout_ms
    );
}


/**
 * @brief Feed watchdog timer.
 *
 * Prevents system reset.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_watchdog_driver_feed(void)
{
    return om_watchdog_feed();
}


/**
 * @brief Force watchdog reset.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_watchdog_driver_reset(void)
{
    return om_watchdog_reset();
}
