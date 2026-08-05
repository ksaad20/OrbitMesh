/**
 * @file health.h
 * @brief OrbitMesh system health monitoring service.
 *
 * Provides kernel and subsystem health information for spacecraft
 * housekeeping and diagnostics.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_HEALTH_H
#define ORBITMESH_HEALTH_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "orbitmesh/error.h"
#include "orbitmesh/types.h"

#include <stdbool.h>
#include <stdint.h>


/*==============================================================================
 * Health Data Types
 *============================================================================*/

/**
 * @brief Health status level.
 */
typedef enum
{
    OM_HEALTH_OK = 0,
    OM_HEALTH_WARNING,
    OM_HEALTH_ERROR
} om_health_status_t;


/**
 * @brief System health report.
 */
typedef struct
{
    /**
     * Current health state.
     */
    om_health_status_t status;


    /**
     * System uptime.
     */
    om_tick_t uptime_ticks;


    /**
     * Number of scheduler cycles.
     */
    uint32_t scheduler_cycles;


    /**
     * Number of detected faults.
     */
    uint32_t fault_count;


    /**
     * Heartbeat counter.
     */
    uint32_t heartbeat;

} om_health_report_t;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize health monitoring.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_health_init(void);


/**
 * @brief Update health information.
 *
 * Called periodically by the system.
 */
void
om_health_update(void);


/**
 * @brief Retrieve current health report.
 *
 * @param report Output report.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_health_get_report(
    om_health_report_t *report);


/**
 * @brief Register a detected system fault.
 */
void
om_health_record_fault(void);


/**
 * @brief Get current health status.
 *
 * @return Health status.
 */
om_health_status_t
om_health_status(void);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_HEALTH_H */
