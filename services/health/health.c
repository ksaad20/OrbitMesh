/**
 * @file health.c
 * @brief OrbitMesh system health monitoring implementation.
 *
 * Implements spacecraft housekeeping health tracking.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "health.h"

#include "orbitmesh/kernel.h"
#include "orbitmesh/timer.h"

#include <string.h>

/*==============================================================================
 * Private State
 *============================================================================*/

/**
 * @brief Current health report.
 */
static om_health_report_t g_health;


/**
 * @brief Health service initialized flag.
 */
static bool g_initialized = false;


/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_health_init(void)
{
    memset(
        &g_health,
        0,
        sizeof(g_health));

    g_health.status = OM_HEALTH_OK;

    g_initialized = true;

    return OM_SUCCESS;
}


void
om_health_update(void)
{
    if (!g_initialized)
    {
        return;
    }


    /*
     * Update heartbeat counter.
     *
     * This provides a simple alive indicator
     * for telemetry systems.
     */
    ++g_health.heartbeat;


    /*
     * Update uptime from kernel.
     */
    g_health.uptime_ticks =
        om_kernel_uptime();


    /*
     * MVP assumes healthy operation unless
     * faults have been recorded.
     */
    if (g_health.fault_count == 0U)
    {
        g_health.status = OM_HEALTH_OK;
    }
    else
    {
        g_health.status = OM_HEALTH_WARNING;
    }
}


om_error_t
om_health_get_report(
    om_health_report_t *report)
{
    if (report == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    if (!g_initialized)
    {
        return OM_ERROR_INVALID_STATE;
    }


    *report = g_health;


    return OM_SUCCESS;
}


void
om_health_record_fault(void)
{
    if (!g_initialized)
    {
        return;
    }


    ++g_health.fault_count;


    g_health.status = OM_HEALTH_ERROR;
}


om_health_status_t
om_health_status(void)
{
    return g_health.status;
}
