/**
 * @file health_monitor.h
 * @brief OrbitMesh health monitoring service interface.
 */

#ifndef ORBITMESH_HEALTH_MONITOR_H
#define ORBITMESH_HEALTH_MONITOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "orbitmesh/error.h"

/*==============================================================================
 * Public Types
 *============================================================================*/

/**
 * @brief Overall system health state.
 */
typedef enum
{
    OM_HEALTH_OK = 0,
    OM_HEALTH_WARNING,
    OM_HEALTH_FAULT
} om_health_state_t;

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the health monitor.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_health_monitor_init(void);

/**
 * @brief Report a system fault.
 *
 * The parameter list must exactly match the implementation in
 * health_monitor.c.
 */
void
om_health_monitor_fault(
    om_error_t error);

/**
 * @brief Get the current health state.
 *
 * @return Current health state.
 */
om_health_state_t
om_health_monitor_state(void);

/**
 * @brief Get the accumulated fault count.
 *
 * @return Number of reported faults.
 */
uint32_t
om_health_monitor_fault_count(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_HEALTH_MONITOR_H */
