/**
 * @file uptime.c
 * @brief OrbitMesh uptime service.
 *
 * Provides system uptime tracking for telemetry,
 * diagnostics, and health reporting.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/timer.h"
#include "orbitmesh/error.h"


/*==============================================================================
 * Private State
 *============================================================================*/

static om_tick_t g_start_tick = 0U;


/*==============================================================================
 * External Functions
 *============================================================================*/

extern om_tick_t
om_timer_get_system_ticks(void);


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize uptime service.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uptime_init(void)
{
    g_start_tick =
        om_timer_get_system_ticks();


    return OM_SUCCESS;
}


/**
 * @brief Get system uptime.
 *
 * @return Elapsed ticks since startup.
 */
om_tick_t
om_uptime_get(void)
{
    return (
        om_timer_get_system_ticks()
        -
        g_start_tick
    );
}
