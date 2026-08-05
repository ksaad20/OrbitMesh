/**
 * @file scheduler.c
 * @brief Cooperative task scheduler.
 *
 * Implements the OrbitMesh MVP scheduler.
 *
 * Scheduling policy:
 *   - Cooperative
 *   - Fixed priorities
 *   - Round-robin within equal priorities
 *   - Static task table
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "scheduler.h"
#include "task_internal.h"

/*==============================================================================
 * Private State
 *============================================================================*/

/**
 * @brief Scheduler execution state.
 */
static om_scheduler_state_t g_scheduler_state =
    OM_SCHEDULER_STOPPED;

/*==============================================================================
 * Public API
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
    if (g_scheduler_state == OM_SCHEDULER_RUNNING)
    {
        return OM_ERROR_INVALID_STATE;
    }

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
    /*
     * Advance all delayed tasks.
     */
    om_task_tick();
}

void
om_scheduler_run(void)
{
    /*
     * MVP scheduler.
     *
     * Future implementation:
     *
     * 1. Scan task table.
     * 2. Find READY task with highest priority.
     * 3. Run task.
     * 4. Task voluntarily yields.
     * 5. Repeat.
     */
}

/**
 * @file scheduler.c
 * @brief OrbitMesh cooperative scheduler.
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
    om_task_t *best = NULL;

    for (size_t i = 0; i < OM_CONFIG_MAX_TASKS; ++i)
    {
        if (!g_task_used[i])
        {
            continue;
        }

        if (g_tasks[i].state != OM_TASK_READY)
        {
            continue;
        }

        if ((best == NULL) ||
            (g_tasks[i].priority < best->priority))
        {
            best = &g_tasks[i];
        }
    }

    if (best == NULL)
    {
        return;
    }

    g_current_task = best;

    best->state = OM_TASK_RUNNING;

    best->entry(best->argument);

    if (best->state == OM_TASK_RUNNING)
    {
        best->state = OM_TASK_READY;
    }
}
