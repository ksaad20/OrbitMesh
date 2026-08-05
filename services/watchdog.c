/**
 * @file watchdog.c
 * @brief OrbitMesh watchdog service.
 *
 * Provides high-level watchdog supervision
 * for autonomous system recovery.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/error.h"


/*==============================================================================
 * External Driver Functions
 *============================================================================*/

extern om_error_t
om_watchdog_driver_init(
    uint32_t timeout_ms);


extern om_error_t
om_watchdog_driver_feed(void);


/*==============================================================================
 * Private State
 *============================================================================*/

static om_bool_t g_watchdog_active = false;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize watchdog service.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_watchdog_service_init(void)
{
    om_error_t result;


    result =
        om_watchdog_driver_init(
            5000U
        );


    if (result == OM_SUCCESS)
    {
        g_watchdog_active = true;
    }


    return result;
}


/**
 * @brief Service watchdog.
 *
 * Called periodically by scheduler.
 */
void
om_watchdog_service_update(void)
{
    if (!g_watchdog_active)
    {
        return;
    }


    (void)om_watchdog_driver_feed();
}
