/**
 * @file task.h
 * @brief OrbitMesh task management API.
 *
 * Provides the public interface for creating and managing
 * tasks within the OrbitMesh kernel.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ORBITMESH_TASK_H
#define ORBITMESH_TASK_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "compiler.h"
#include "error.h"
#include "types.h"

#include <stddef.h>
#include <stdint.h>

/*==============================================================================
 * Configuration
 *============================================================================*/

/**
 * @brief Default stack alignment.
 */
#define OM_TASK_STACK_ALIGNMENT 8U

/*==============================================================================
 * Types
 *============================================================================*/

/**
 * @brief Task entry function.
 *
 * @param argument User-supplied argument.
 */
typedef void (*om_task_entry_t)(
    void *argument
);

/**
 * @brief Task execution state.
 */
typedef enum
{
    OM_TASK_READY = 0,
    OM_TASK_RUNNING,
    OM_TASK_BLOCKED,
    OM_TASK_SUSPENDED,
    OM_TASK_TERMINATED

} om_task_state_t;

/**
 * @brief Task configuration.
 */
typedef struct
{
    const char *name;

    om_task_entry_t entry;

    void *argument;

    void *stack;

    om_size_t stack_size;

    om_priority_t priority;

} om_task_config_t;

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the task subsystem.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_init(void);

/**
 * @brief Create a task.
 *
 * @param config Task configuration.
 * @param task Destination task handle.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_create(
    const om_task_config_t *config,
    om_task_t **task
);

/**
 * @brief Destroy a task.
 *
 * @param task Task handle.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_destroy(
    om_task_t *task
);

/**
 * @brief Start scheduler execution.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_start_scheduler(void);

/**
 * @brief Yield execution.
 */
void
om_task_yield(void);

/**
 * @brief Delay the current task.
 *
 * @param ticks Delay duration.
 */
void
om_task_delay(
    om_tick_t ticks
);

/**
 * @brief Suspend a task.
 *
 * @param task Task handle.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_suspend(
    om_task_t *task
);

/**
 * @brief Resume a task.
 *
 * @param task Task handle.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_resume(
    om_task_t *task
);

/**
 * @brief Obtain the currently running task.
 *
 * @return Current task.
 */
om_task_t *
om_task_current(void);

/**
 * @brief Get the state of a task.
 *
 * @param task Task handle.
 *
 * @return Current task state.
 */
om_task_state_t
om_task_state(
    const om_task_t *task
);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TASK_H */
