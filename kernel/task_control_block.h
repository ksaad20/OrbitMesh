/**
 * @file task_control_block.h
 * @brief Internal Task Control Block definition.
 *
 * Single internal representation of an OrbitMesh task.
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
 */
struct om_task
{
    /**
     * Task identifier.
     */
    om_task_id_t id;

    /**
     * Task name.
     */
    const char *name;

    /**
     * Entry callback.
     */
    om_task_entry_t entry;

    /**
     * User argument.
     */
    void *argument;

    /**
     * Task stack memory.
     */
    void *stack;

    /**
     * Stack size.
     */
    om_size_t stack_size;

    /**
     * Scheduling priority.
     */
    om_priority_t priority;

    /**
     * Current state.
     */
    om_task_state_t state;

    /**
     * Remaining delay ticks.
     */
    om_tick_t delay_ticks;

    /**
     * Runtime ticks.
     */
    om_tick_t runtime_ticks;

    /**
     * Number of executions.
     */
    om_tick_t context_switches;

    /**
     * Next task.
     */
    struct om_task *next;
};

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TASK_CONTROL_BLOCK_H */
