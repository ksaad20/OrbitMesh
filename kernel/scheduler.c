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
