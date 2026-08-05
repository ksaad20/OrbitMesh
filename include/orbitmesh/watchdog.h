/**
 * @file watchdog.h
 * @brief OrbitMesh Watchdog HAL.
 *
 * Hardware abstraction layer for watchdog peripherals.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_WATCHDOG_H
#define ORBITMESH_WATCHDOG_H

#ifdef __cplusplus
extern "C"
{
#endif

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
om_watchdog_init(
    uint32_t timeout_ms);

/**
 * @brief Feed (kick) the watchdog.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_watchdog_feed(void);

/**
 * @brief Force a watchdog reset.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_watchdog_reset(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_WATCHDOG_H */
