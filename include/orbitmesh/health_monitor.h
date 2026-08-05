/**
 * @file health_monitor.h
 * @brief OrbitMesh health monitoring service.
 *
 * Provides a centralized interface for monitoring
 * overall spacecraft and operating system health.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ORBITMESH_HEALTH_MONITOR_H
#define ORBITMESH_HEALTH_MONITOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>


/**
 * @brief Overall system health state.
 */
typedef enum
{
    OM_HEALTH_OK = 0,
    OM_HEALTH_WARNING,
    OM_HEALTH_ERROR,
    OM_HEALTH_CRITICAL

} om_health_state_t;


/**
 * @brief Health monitor statistics.
 */
typedef struct
{
    /**
     * @brief Current system health.
     */
    om_health_state_t state;

    /**
     * @brief Number of detected faults.
     */
    uint32_t fault_count;

    /**
     * @brief Number of health monitor updates.
     */
    uint32_t heartbeat_count;

} om_health_status_t;


/**
 * @brief Initialize the health monitor.
 */
void
om_health_monitor_init(void);


/**
 * @brief Update the health monitor.
 *
 * Call periodically from the scheduler.
 */
void
om_health_monitor_update(void);


/**
 * @brief Set the current health state.
 *
 * @param state New health state.
 */
void
om_health_monitor_set_state(
    om_health_state_t state
);


/**
 * @brief Report a system fault.
 */
void
om_health_monitor_report_fault(void);


/**
 * @brief Get the current health state.
 *
 * @return Current health state.
 */
om_health_state_t
om_health_monitor_state(void);


/**
 * @brief Get the total number of faults.
 *
 * @return Fault count.
 */
uint32_t
om_health_monitor_fault_count(void);


/**
 * @brief Get the heartbeat counter.
 *
 * @return Heartbeat count.
 */
uint32_t
om_health_monitor_heartbeat(void);


/**
 * @brief Get a snapshot of the current health status.
 *
 * @param status Pointer to the destination structure.
 */
void
om_health_monitor_status(
    om_health_status_t *status
);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_HEALTH_MONITOR_H */
