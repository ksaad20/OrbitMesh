/**
 * @file task_internal.h
 * @brief Internal task management definitions.
 */

#ifndef ORBITMESH_TASK_INTERNAL_H
#define ORBITMESH_TASK_INTERNAL_H

#include "kernel_internal.h"
#include "task_control_block.h"

extern om_task_t g_tasks[OM_CONFIG_MAX_TASKS];
extern bool g_task_used[OM_CONFIG_MAX_TASKS];
extern om_task_t *g_current_task;

#ifdef __cplusplus
extern "C"
{
#endif

#define OM_TASK_INVALID_ID ((om_task_id_t)0U)

struct om_task
{
    om_task_id_t id;

    const char *name;

    om_task_entry_t entry;

    void *argument;

    void *stack;

    om_size_t stack_size;

    om_priority_t priority;

    om_task_state_t state;

    om_tick_t delay_ticks;

    struct om_task *next;
};


om_error_t
om_task_init(void);


om_task_t *
om_task_idle(void);


void
om_task_tick(void);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TASK_INTERNAL_H */
