/**
 * @file task_scheduler.h
 * @brief Scheduler-facing task interface.
 *
 * Defines the private interface used by the scheduler to inspect and control
 * tasks. This header is internal to the kernel and must not be included by
 * applications.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_TASK_SCHEDULER_H
#define ORBITMESH_TASK_SCHEDULER_H

#include "task_internal.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Task Enumeration
 *============================================================================*/

/**
 * @brief Get the total number of allocated tasks.
 *
 * @return Number of active tasks.
 */
size_t
om_task_count(void);

/**
 * @brief Get a task by table index.
 *
 * @param index Task table index.
 *
 * @return Task pointer or NULL if the slot is unused.
 */
om_task_t *
om_task_at(
    size_t index);

/**
 * @brief Get the currently running task.
 *
 * @return Current task.
 */
om_task_t *
om_task_current_internal(void);

/**
 * @brief Set the currently running task.
 *
 * @param task Task to become current.
 */
void
om_task_set_current(
    om_task_t *task);

/*==============================================================================
 * Task State
 *============================================================================*/

/**
 * @brief Test whether a task is runnable.
 *
 * @param task Task.
 *
 * @return true if the task is READY.
 */
bool
om_task_is_ready(
    const om_task_t *task);

/**
 * @brief Mark a task as running.
 *
 * @param task Task.
 */
void
om_task_mark_running(
    om_task_t *task);

/**
 * @brief Mark a task as ready.
 *
 * @param task Task.
 */
void
om_task_mark_ready(
    om_task_t *task);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TASK_SCHEDULER_H */
