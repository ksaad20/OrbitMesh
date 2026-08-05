/**
 * @file scheduler.c
 * @brief OrbitMesh scheduler implementation.
 *
 * Minimal cooperative scheduler implementation for MVP.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "scheduler.h"

#include "task_internal.h"

static om_scheduler_state_t g_scheduler_state =
    OM_SCHEDULER_STOPPED;

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

void
om_scheduler_tick(void)
{
    om_task_tick();
}

void
om_scheduler_run(void)
{
    for (om_size_t i = 0U; i < OM_CONFIG_MAX_TASKS; ++i)
    {
        if (!g_task_used[i])
        {
            continue;
        }

        if (g_tasks[i].state != OM_TASK_READY)
        {
            continue;
        }

        g_current_task = &g_tasks[i];

        g_tasks[i].state = OM_TASK_RUNNING;

        if (g_tasks[i].entry != NULL)
        {
            g_tasks[i].entry(
                g_tasks[i].argument
            );
        }

        if (g_tasks[i].state == OM_TASK_RUNNING)
        {
            g_tasks[i].state = OM_TASK_READY;
        }

        break;
    }

    g_current_task = NULL;
}
