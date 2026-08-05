/**
 * @file watchdog_driver.h
 * @brief OrbitMesh watchdog driver interface.
 *
 * Provides a generic watchdog driver API built on
 * top of the OrbitMesh HAL.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_DRIVERS_WATCHDOG_DRIVER_H
#define ORBITMESH_DRIVERS_WATCHDOG_DRIVER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "orbitmesh/error.h"

#include <stdint.h>

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the watchdog.
 *
 * @param timeout_ms Watchdog timeout in milliseconds.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_watchdog_driver_init(
    uint32_t timeout_ms);

/**
 * @brief Feed the watchdog timer.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_watchdog_driver_feed(void);

/**
 * @brief Force a watchdog reset.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_watchdog_driver_reset(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_DRIVERS_WATCHDOG_DRIVER_H */
