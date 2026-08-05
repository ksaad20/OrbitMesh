/**
 * @file task.c
 * @brief OrbitMesh task management implementation.
 *
 * Minimal cooperative task manager for the OrbitMesh MVP.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "task_internal.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/*==============================================================================
 * Internal Task Storage
 *============================================================================*/

/**
 * @brief Static task table.
 */
om_task_t g_tasks[OM_CONFIG_MAX_TASKS];

/**
 * @brief Allocation bitmap.
 */
bool g_task_used[OM_CONFIG_MAX_TASKS];

/**
 * @brief Currently executing task.
 */
om_task_t *g_current_task = NULL;

/*==============================================================================
 * Internal Helpers
 *============================================================================*/

/**
 * @brief Reset a task control block.
 *
 * @param task Task to reset.
 */
static void
om_task_clear(
    om_task_t *task)
{
    (void)memset(
        task,
        0,
        sizeof(*task)
    );

    task->state = OM_TASK_TERMINATED;
}

/**
 * @brief Allocate a free task slot.
 *
 * @return Free task or NULL.
 */
static om_task_t *
om_task_allocate(void)
{
    for (om_size_t i = 0U;
         i < OM_CONFIG_MAX_TASKS;
         ++i)
    {
        if (!g_task_used[i])
        {
            g_task_used[i] = true;

            om_task_clear(
                &g_tasks[i]
            );

            g_tasks[i].id =
                (om_task_id_t)(i + 1U);

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
om_task_release(
    om_task_t *task)
{
    if (task == NULL)
    {
        return;
    }

    for (om_size_t i = 0U;
         i < OM_CONFIG_MAX_TASKS;
         ++i)
    {
        if (&g_tasks[i] == task)
        {
            g_task_used[i] = false;

            om_task_clear(
                &g_tasks[i]
            );

            if (g_current_task == task)
            {
                g_current_task = NULL;
            }

            return;
        }
    }
}

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the task subsystem.
 */
om_error_t
om_task_init(void)
{
    for (om_size_t i = 0U;
         i < OM_CONFIG_MAX_TASKS;
         ++i)
    {
        g_task_used[i] = false;

        om_task_clear(
            &g_tasks[i]
        );
    }

    g_current_task = NULL;

    return OM_SUCCESS;
}

/**
 * @brief Create a new task.
 */
om_error_t
om_task_create(
    const om_task_config_t *config,
    om_task_t **task)
{
    if ((config == NULL) ||
        (task == NULL))
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    om_task_t *new_task =
        om_task_allocate();

    if (new_task == NULL)
    {
        return OM_ERROR_OUT_OF_MEMORY;
    }

    new_task->name = config->name;
    new_task->entry = config->entry;
    new_task->argument = config->argument;
    new_task->stack = config->stack;
    new_task->stack_size = config->stack_size;
    new_task->priority = config->priority;

    new_task->state = OM_TASK_READY;

    new_task->delay_ticks = 0U;
    new_task->runtime_ticks = 0U;
    new_task->context_switches = 0U;
    new_task->next = NULL;

    *task = new_task;

    return OM_SUCCESS;
}
/*==============================================================================
 * Task Destruction
 *============================================================================*/

/**
 * @brief Destroy a task.
 */
om_error_t
om_task_destroy(
    om_task_t *task)
{
    if (task == NULL)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    om_task_release(task);

    return OM_SUCCESS;
}

/*==============================================================================
 * Scheduler Interaction
 *============================================================================*/

/**
 * @brief Yield execution.
 *
 * Cooperative scheduler MVP implementation.
 */
void
om_task_yield(void)
{
    if (g_current_task != NULL)
    {
        g_current_task->state = OM_TASK_READY;
    }
}

/**
 * @brief Delay the current task.
 *
 * For the MVP, a delay is represented as a blocked task with a countdown.
 * The scheduler/tick subsystem is responsible for decrementing delay_ticks
 * and restoring the READY state when the delay expires.
 */
void
om_task_delay(
    om_tick_t ticks)
{
    if (g_current_task == NULL)
    {
        return;
    }

    g_current_task->delay_ticks = ticks;

    if (ticks > 0U)
    {
        g_current_task->state = OM_TASK_BLOCKED;
    }
}

/**
 * @brief Start scheduler execution.
 */
om_error_t
om_task_start_scheduler(void)
{
    return om_scheduler_start();
}

/*==============================================================================
 * Task State Management
 *============================================================================*/

/**
 * @brief Suspend a task.
 */
om_error_t
om_task_suspend(
    om_task_t *task)
{
    if (task == NULL)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    task->state = OM_TASK_SUSPENDED;

    return OM_SUCCESS;
}

/**
 * @brief Resume a suspended task.
 */
om_error_t
om_task_resume(
    om_task_t *task)
{
    if (task == NULL)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (task->state == OM_TASK_SUSPENDED)
    {
        task->state = OM_TASK_READY;
    }

    return OM_SUCCESS;
}

/*==============================================================================
 * Task Information
 *============================================================================*/

/**
 * @brief Return the current task.
 */
om_task_t *
om_task_current(void)
{
    return g_current_task;
}

/**
 * @brief Return the current task state.
 */
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
