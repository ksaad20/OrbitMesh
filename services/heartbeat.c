/**
 * @file heartbeat.c
 * @brief OrbitMesh heartbeat service.
 *
 * Provides periodic system heartbeat generation
 * for health monitoring and diagnostics.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/heartbeat.h"
#include "orbitmesh/error.h"
#include "orbitmesh/log.h"


/*==============================================================================
 * Private State
 *============================================================================*/

static om_bool_t g_heartbeat_active = false;

static uint32_t g_heartbeat_count = 0U;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize heartbeat service.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_heartbeat_init(void)
{
    g_heartbeat_active = true;

    g_heartbeat_count = 0U;


    return OM_SUCCESS;
}


/**
 * @brief Execute heartbeat update.
 *
 * Called periodically by the scheduler.
 */
void
om_heartbeat_update(void)
{
    if (!g_heartbeat_active)
    {
        return;
    }


    g_heartbeat_count++;


    om_log_info(
        "Heartbeat %lu",
        (unsigned long)g_heartbeat_count
    );
}


/**
 * @brief Get heartbeat counter.
 *
 * @return Number of heartbeat events.
 */
uint32_t
om_heartbeat_count(void)
{
    return g_heartbeat_count;
}
