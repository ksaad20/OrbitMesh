/**
 * @file task.h
 * @brief OrbitMesh task management API.
 *
 * Public interface for creating, controlling, and querying tasks.
 *
 * @note
 * Tasks are cooperatively scheduled in the OrbitMesh MVP.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
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
#include "config.h"
#include "error.h"
#include "types.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*==============================================================================
 * Task Types
 *============================================================================*/

/**
 * @brief Task entry function.
 *
 * @param argument User-supplied task argument.
 */
typedef void (*om_task_function_t)(void *argument);

/**
 * @brief Task execution state.
 */
typedef enum
{
    OM_TASK_READY = 0,
    OM_TASK_RUNNING,
    OM_TASK_BLOCKED,
    OM_TASK_SLEEPING,
    OM_TASK_SUSPENDED,
    OM_TASK_TERMINATED
} om_task_state_t;

/**
 * @brief Task configuration.
 */
typedef struct
{
    const char *name;
    om_task_function_t entry;
    void *argument;
    void *stack;
    om_size_t stack_size;
    om_priority_t priority;
} om_task_config_t;

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Create a task.
 *
 * @param config Task configuration.
 * @param task Receives the created task handle.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_create(
    const om_task_config_t *config,
    om_task_t **task);

/**
 * @brief Delete a task.
 *
 * @param task Task to delete.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_delete(
    om_task_t *task);

/**
 * @brief Yield execution to another runnable task.
 */
void
om_task_yield(void);

/**
 * @brief Delay the current task.
 *
 * @param ticks Number of scheduler ticks.
 */
void
om_task_delay(
    om_tick_t ticks);

/**
 * @brief Suspend a task.
 *
 * @param task Task to suspend.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_suspend(
    om_task_t *task);

/**
 * @brief Resume a suspended task.
 *
 * @param task Task to resume.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_resume(
    om_task_t *task);

/**
 * @brief Set a task's priority.
 *
 * @param task Task.
 * @param priority New priority.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_set_priority(
    om_task_t *task,
    om_priority_t priority);

/**
 * @brief Get a task's priority.
 *
 * @param task Task.
 *
 * @return Current priority.
 */
om_priority_t
om_task_priority(
    const om_task_t *task);

/**
 * @brief Get the current task.
 *
 * @return Pointer to the currently running task.
 */
om_task_t *
om_task_current(void);

/**
 * @brief Get a task's current state.
 *
 * @param task Task.
 *
 * @return Task state.
 */
om_task_state_t
om_task_state(
    const om_task_t *task);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TASK_H */
