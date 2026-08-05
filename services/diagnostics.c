/**
 * @file diagnostics.c
 * @brief OrbitMesh diagnostics service.
 *
 * Provides runtime system status information
 * for debugging and telemetry.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/health_monitor.h"
#include "orbitmesh/heartbeat.h"
#include "orbitmesh/error.h"


/*==============================================================================
 * Public Types
 *============================================================================*/

typedef struct
{
    uint32_t heartbeat_count;

    uint32_t fault_count;

    om_health_state_t health;

} om_diagnostics_report_t;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize diagnostics service.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_diagnostics_init(void)
{
    return OM_SUCCESS;
}


/**
 * @brief Generate diagnostics report.
 *
 * @param report Output report structure.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_diagnostics_collect(
    om_diagnostics_report_t *report)
{
    if (report == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    report->heartbeat_count =
        om_heartbeat_count();


    report->fault_count =
        om_health_monitor_fault_count();


    report->health =
        om_health_monitor_state();


    return OM_SUCCESS;
}
