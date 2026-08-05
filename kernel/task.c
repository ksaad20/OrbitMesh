/**
 * @file task.c
 * @brief OrbitMesh task management.
 *
 * Implements the cooperative task subsystem.
 *
 * MVP Characteristics
 * -------------------
 * - Static task allocation
 * - No heap usage
 * - Deterministic execution
 * - Cooperative scheduling
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "task_internal.h"
#include "scheduler.h"

#include <string.h>

/*==============================================================================
 * Private Data
 *============================================================================*/

/**
 * @brief Task Control Block pool.
 */
static struct om_task g_tasks[OM_CONFIG_MAX_TASKS];

/**
 * @brief Indicates whether a task slot is allocated.
 */
static bool g_task_used[OM_CONFIG_MAX_TASKS];

/**
 * @brief Pointer to the currently running task.
 */
static om_task_t *g_current_task = NULL;

/**
 * @brief Next task identifier.
 */
static om_task_id_t g_next_task_id = 1U;

/*==============================================================================
 * Private Functions
 *============================================================================*/

/**
 * @brief Allocate a free task slot.
 *
 * @return Pointer to the allocated task or NULL if none are available.
 */
static om_task_t *
task_allocate(void)
{
    for (size_t i = 0U; i < OM_CONFIG_MAX_TASKS; ++i)
    {
        if (!g_task_used[i])
        {
            g_task_used[i] = true;

            memset(
                &g_tasks[i],
                0,
                sizeof(struct om_task));

            g_tasks[i].id = g_next_task_id++;

            return &g_tasks[i];
        }
    }

    return NULL;
}

/**
 * @brief Release a task slot.
 *
 * @param task Task to release.
 */
static void
task_release(
    om_task_t *task)
{
    if (task == NULL)
    {
        return;
    }

    for (size_t i = 0U; i < OM_CONFIG_MAX_TASKS; ++i)
    {
        if (&g_tasks[i] == task)
        {
            g_task_used[i] = false;
            memset(task, 0, sizeof(struct om_task));
            return;
        }
    }
}

/*==============================================================================
 * Internal API
 *============================================================================*/

om_error_t
om_task_init(void)
{
    memset(g_tasks, 0, sizeof(g_tasks));
    memset(g_task_used, 0, sizeof(g_task_used));

    g_current_task = NULL;
    g_next_task_id = 1U;

    return OM_SUCCESS;
}

om_task_t *
om_task_idle(void)
{
    return NULL;
}

void
om_task_tick(void)
{
    for (size_t i = 0U; i < OM_CONFIG_MAX_TASKS; ++i)
    {
        if (!g_task_used[i])
        {
            continue;
        }

        if (g_tasks[i].state == OM_TASK_SLEEPING &&
            g_tasks[i].delay_ticks > 0U)
        {
            --g_tasks[i].delay_ticks;

            if (g_tasks[i].delay_ticks == 0U)
            {
                g_tasks[i].state = OM_TASK_READY;
            }
        }
    }
}

/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_task_create(
    const om_task_config_t *config,
    om_task_t **task)
{
    if ((config == NULL) || (task == NULL))
    {
        return OM_ERROR_NULL_POINTER;
    }

    om_task_t *new_task = task_allocate();

    if (new_task == NULL)
    {
        return OM_ERROR_TASK_LIMIT;
    }

    new_task->name = config->name;
    new_task->entry = config->entry;
    new_task->argument = config->argument;
    new_task->stack = config->stack;
    new_task->stack_size = config->stack_size;
    new_task->priority = config->priority;
    new_task->state = OM_TASK_READY;

    *task = new_task;

    return OM_SUCCESS;
}

om_error_t
om_task_delete(
    om_task_t *task)
{
    if (task == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    task_release(task);

    return OM_SUCCESS;
}

om_task_t *
om_task_current(void)
{
    return g_current_task;
}

/*==============================================================================
 * Public API (continued)
 *============================================================================*/

void
om_task_yield(void)
{
    /*
     * Cooperative scheduling:
     * Yielding simply invokes the scheduler. The scheduler
     * decides which READY task to run next.
     */
    om_scheduler_run();
}

void
om_task_delay(
    om_tick_t ticks)
{
    if (g_current_task == NULL)
    {
        return;
    }

    g_current_task->delay_ticks = ticks;
    g_current_task->state = OM_TASK_SLEEPING;

    om_scheduler_run();
}

om_error_t
om_task_suspend(
    om_task_t *task)
{
    if (task == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    task->state = OM_TASK_SUSPENDED;

    return OM_SUCCESS;
}

om_error_t
om_task_resume(
    om_task_t *task)
{
    if (task == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (task->state == OM_TASK_SUSPENDED)
    {
        task->state = OM_TASK_READY;
    }

    return OM_SUCCESS;
}

om_error_t
om_task_set_priority(
    om_task_t *task,
    om_priority_t priority)
{
    if (task == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (priority > OM_CONFIG_MAX_PRIORITY)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    task->priority = priority;

    return OM_SUCCESS;
}

om_priority_t
om_task_priority(
    const om_task_t *task)
{
    if (task == NULL)
    {
        return 0U;
    }

    return task->priority;
}

om_task_state_t
om_task_state(
    const om_task_t *task)
{
    if (task == NULL)
    {
        return OM_TASK_TERMINATED;
    }

    return task->state;
}
