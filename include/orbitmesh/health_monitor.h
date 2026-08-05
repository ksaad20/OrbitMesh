/**
 * @file health_monitor.h
 * @brief OrbitMesh health monitoring service interface.
 *
 * Provides a lightweight health monitoring interface for
 * OrbitMesh services and system diagnostics.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_HEALTH_MONITOR_H
#define ORBITMESH_HEALTH_MONITOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "orbitmesh/error.h"

/*==============================================================================
 * Public Types
 *============================================================================*/

/**
 * @brief Health monitor status.
 */
typedef enum
{
    OM_HEALTH_STATUS_OK = 0,
    OM_HEALTH_STATUS_WARNING,
    OM_HEALTH_STATUS_FAULT
} om_health_status_t;

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the health monitoring service.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_health_monitor_init(void);

/**
 * @brief Report a health fault.
 *
 * @param module Name of the reporting module.
 * @param error OrbitMesh error code.
 */
void
om_health_monitor_fault(
    const char *module,
    om_error_t error);

/**
 * @brief Get the current health status.
 *
 * @return Current health status.
 */
om_health_status_t
om_health_monitor_status(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_HEALTH_MONITOR_H */
