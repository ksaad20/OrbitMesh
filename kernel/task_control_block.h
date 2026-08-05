/**
 * @file task_control_block.h
 * @brief Internal Task Control Block (TCB) definition.
 *
 * Defines the private task representation used by the OrbitMesh kernel.
 *
 * This header is NOT part of the public API.
 *
 * Applications must use:
 *
 *     #include <orbitmesh/task.h>
 *
 * instead of this header.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_TASK_CONTROL_BLOCK_H
#define ORBITMESH_TASK_CONTROL_BLOCK_H

#include "orbitmesh/task.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Internal Task Control Block.
 *
 * Exactly one instance exists for every allocated task.
 */
struct om_task
{
    /*==========================================================================
     * Identity
     *==========================================================================*/

    /**
     * Unique task identifier.
     */
    om_task_id_t id;

    /**
     * Human-readable task name.
     */
    const char *name;

    /*==========================================================================
     * Execution
     *==========================================================================*/

    /**
     * Task entry function.
     */
    om_task_function_t entry;

    /**
     * User-supplied argument.
     */
    void *argument;

    /*==========================================================================
     * Stack
     *==========================================================================*/

    /**
     * Lowest stack address.
     */
    void *stack_base;

    /**
     * Current stack pointer.
     *
     * Reserved for future context switching support.
     */
    void *stack_pointer;

    /**
     * Stack size in bytes.
     */
    om_size_t stack_size;

    /*==========================================================================
     * Scheduling
     *==========================================================================*/

    /**
     * Task priority.
     */
    om_priority_t priority;

    /**
     * Current task state.
     */
    om_task_state_t state;

    /**
     * Tick at which the task becomes runnable.
     */
    om_tick_t wake_tick;

    /*==========================================================================
     * Runtime Statistics
     *==========================================================================*/

    /**
     * Total scheduler ticks executed.
     */
    om_tick_t runtime_ticks;

    /**
     * Number of times scheduled.
     */
    om_tick_t context_switches;
};

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TASK_CONTROL_BLOCK_H */
