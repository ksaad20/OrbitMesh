/**
 * @file health_monitor.c
 * @brief OrbitMesh health monitoring service.
 *
 * Provides subsystem health tracking and fault
 * reporting for autonomous operation.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/health_monitor.h"
#include "orbitmesh/error.h"


/*==============================================================================
 * Private State
 *============================================================================*/

static om_health_state_t g_health_state =
    OM_HEALTH_OK;


static uint32_t g_fault_count = 0U;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize health monitor.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_health_monitor_init(void)
{
    g_health_state = OM_HEALTH_OK;

    g_fault_count = 0U;


    return OM_SUCCESS;
}


/**
 * @brief Report a subsystem fault.
 *
 * @param fault Fault identifier.
 */
void
om_health_monitor_fault(
    uint32_t fault)
{
    (void)fault;


    g_fault_count++;


    g_health_state =
        OM_HEALTH_WARNING;
}


/**
 * @brief Get current health state.
 *
 * @return Health status.
 */
om_health_state_t
om_health_monitor_state(void)
{
    return g_health_state;
}


/**
 * @brief Get total fault count.
 *
 * @return Number of recorded faults.
 */
uint32_t
om_health_monitor_fault_count(void)
{
    return g_fault_count;
}
