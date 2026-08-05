/**
 * @file scheduler.c
 * @brief OrbitMesh cooperative scheduler implementation.
 *
 * Minimal scheduler for MVP.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "scheduler.h"

#include "task_internal.h"

#include <stddef.h>

/*==============================================================================
 * Scheduler State
 *============================================================================*/

static om_scheduler_state_t g_scheduler_state =
    OM_SCHEDULER_STOPPED;


/*==============================================================================
 * Public Internal API
 *============================================================================*/

om_error_t
om_scheduler_init(void)
{
    g_scheduler_state = OM_SCHEDULER_STOPPED;

    return OM_SUCCESS;
}


om_error_t
om_scheduler_start(void)
{
    g_scheduler_state = OM_SCHEDULER_RUNNING;

    return OM_SUCCESS;
}


om_error_t
om_scheduler_stop(void)
{
    g_scheduler_state = OM_SCHEDULER_STOPPED;

    return OM_SUCCESS;
}


om_scheduler_state_t
om_scheduler_state(void)
{
    return g_scheduler_state;
}


/*==============================================================================
 * Scheduler Execution
 *============================================================================*/

void
om_scheduler_tick(void)
{
    om_task_tick();
}


void
om_scheduler_run(void)
{
    if (g_scheduler_state != OM_SCHEDULER_RUNNING)
    {
        return;
    }

    om_task_t *task = om_task_next_ready();

    if (task == NULL)
    {
        return;
    }

    g_current_task = task;

    task->state = OM_TASK_RUNNING;

    task->entry(task->argument);

    task->state = OM_TASK_READY;
}
