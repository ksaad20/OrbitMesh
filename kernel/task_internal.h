/**
 * @file task_internal.h
 * @brief Internal task management definitions.
 *
 * Private definitions shared by the OrbitMesh kernel task subsystem.
 * This header is not part of the public API.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_TASK_INTERNAL_H
#define ORBITMESH_TASK_INTERNAL_H

#include "kernel_internal.h"

#include "orbitmesh/task.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Internal Constants
 *============================================================================*/

/**
 * @brief Invalid task identifier.
 */
#define OM_TASK_INVALID_ID ((om_task_id_t)0U)

/*==============================================================================
 * Internal Task Structure
 *============================================================================*/

/**
 * @brief Internal task control block (TCB).
 */
struct om_task
{
    /**
     * Unique task identifier.
     */
    om_task_id_t id;

    /**
     * Human-readable task name.
     */
    const char *name;

    /**
     * Task entry function.
     */
    om_task_function_t entry;

    /**
     * User-supplied argument.
     */
    void *argument;

    /**
     * Base of the task stack.
     */
    void *stack;

    /**
     * Stack size in bytes.
     */
    om_size_t stack_size;

    /**
     * Current scheduling priority.
     */
    om_priority_t priority;

    /**
     * Current task state.
     */
    om_task_state_t state;

    /**
     * Delay remaining in scheduler ticks.
     */
    om_tick_t delay_ticks;

    /**
     * Next task in an internal linked list.
     */
    struct om_task *next;
};

/*==============================================================================
 * Internal API
 *============================================================================*/

/**
 * @brief Initialize the task subsystem.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_init(void);

/**
 * @brief Get the scheduler idle task.
 *
 * @return Idle task.
 */
om_task_t *
om_task_idle(void);

/**
 * @brief Update delayed tasks.
 *
 * Called once per scheduler tick.
 */
void
om_task_tick(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TASK_INTERNAL_H */
