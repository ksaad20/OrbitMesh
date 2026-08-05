/**
 * @file scheduler.h
 * @brief Internal scheduler interface.
 *
 * This header defines the private scheduler interface used by the
 * OrbitMesh kernel. It is not part of the public API.
 *
 * Applications must never include this file directly.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_SCHEDULER_H
#define ORBITMESH_SCHEDULER_H

#include "kernel_internal.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Scheduler Configuration
 *============================================================================*/

/**
 * @brief Scheduler execution state.
 */
typedef enum
{
    OM_SCHEDULER_STOPPED = 0,
    OM_SCHEDULER_RUNNING
} om_scheduler_state_t;

/*==============================================================================
 * Internal Scheduler API
 *============================================================================*/

/**
 * @brief Initialize the scheduler.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_scheduler_init(void);

/**
 * @brief Start the scheduler.
 *
 * Called by om_kernel_start().
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_scheduler_start(void);

/**
 * @brief Stop the scheduler.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_scheduler_stop(void);

/**
 * @brief Execute one scheduling cycle.
 *
 * This function selects the next runnable task and performs any required
 * context switch operations.
 */
void
om_scheduler_run(void);

/**
 * @brief Advance the scheduler by one system tick.
 */
void
om_scheduler_tick(void);

/**
 * @brief Get the current scheduler state.
 *
 * @return Current scheduler state.
 */
om_scheduler_state_t
om_scheduler_state(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_SCHEDULER_H */
