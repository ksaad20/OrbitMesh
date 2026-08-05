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

#include "orbitmesh/drivers/watchdog_driver.h"

/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_watchdog_driver_init(
    uint32_t timeout_ms)
{
    return om_watchdog_init(
        timeout_ms
    );
}


om_error_t
om_watchdog_driver_feed(void)
{
    return om_watchdog_feed();
}


om_error_t
om_watchdog_driver_reset(void)
{
    return om_watchdog_reset();
}
