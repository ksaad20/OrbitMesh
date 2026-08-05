/**
 * @file task.c
 * @brief OrbitMesh task management implementation.
 *
 * Minimal cooperative task manager for MVP.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "task_internal.h"

#include <stddef.h>
#include <string.h>

/*==============================================================================
 * Task Storage
 *============================================================================*/

om_task_t g_tasks[OM_CONFIG_MAX_TASKS];

bool g_task_used[OM_CONFIG_MAX_TASKS];

om_task_t *g_current_task = NULL;

/*==============================================================================
 * Internal Helpers
 *============================================================================*/

static void
om_task_clear(
    om_task_t *task)
{
    (void)memset(
        task,
        0,
        sizeof(*task)
    );

    task->state = OM_TASK_UNUSED;
}

/*==============================================================================
 * Task Initialization
 *============================================================================*/

om_error_t
om_task_init(void)
{
    for (om_size_t i = 0U; i < OM_CONFIG_MAX_TASKS; ++i)
    {
        om_task_clear(&g_tasks[i]);
        g_task_used[i] = false;
    }

    g_current_task = NULL;

    return OM_SUCCESS;
}

/*==============================================================================
 * Task Tick
 *============================================================================*/

void
om_task_tick(void)
{
    for (om_size_t i = 0U; i < OM_CONFIG_MAX_TASKS; ++i)
    {
        if (!g_task_used[i])
        {
            continue;
        }

        if (g_tasks[i].state == OM_TASK_SLEEPING)
        {
            if (g_tasks[i].delay_ticks > 0U)
            {
                --g_tasks[i].delay_ticks;
            }

            if (g_tasks[i].delay_ticks == 0U)
            {
                g_tasks[i].state = OM_TASK_READY;
            }
        }
    }
}

/*==============================================================================
 * Task Creation
 *============================================================================*/

om_error_t
om_task_create(
    const om_task_config_t *config,
    om_task_t **handle)
{
    if ((config == NULL) || (handle == NULL))
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    for (om_size_t i = 0U; i < OM_CONFIG_MAX_TASKS; ++i)
    {
        if (!g_task_used[i])
        {
            om_task_t *task = &g_tasks[i];

            om_task_clear(task);

            task->id = (om_task_id_t)(i + 1U);
            task->name = config->name;
            task->entry = config->entry;
            task->argument = config->argument;
            task->stack = config->stack;
            task->stack_size = config->stack_size;
            task->priority = config->priority;
            task->state = OM_TASK_READY;

            g_task_used[i] = true;

            *handle = task;

            return OM_SUCCESS;
        }
    }

    return OM_ERROR_NO_MEMORY;
}

/*==============================================================================
 * Task Delete
 *============================================================================*/

om_error_t
om_task_delete(
    om_task_t *task)
{
    if (task == NULL)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    for (om_size_t i = 0U; i < OM_CONFIG_MAX_TASKS; ++i)
    {
        if (&g_tasks[i] == task)
        {
            g_task_used[i] = false;
            om_task_clear(task);

            return OM_SUCCESS;
        }
    }

    return OM_ERROR_NOT_FOUND;
}

/*==============================================================================
 * Task Delay
 *============================================================================*/

om_error_t
om_task_delay(
    om_tick_t ticks)
{
    if (g_current_task == NULL)
    {
        return OM_ERROR_INVALID_STATE;
    }

    g_current_task->delay_ticks = ticks;
    g_current_task->state = OM_TASK_SLEEPING;

    return OM_SUCCESS;
}

/*==============================================================================
 * Task Information
 *============================================================================*/

om_task_t *
om_task_current(void)
{
    return g_current_task;
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


om_error_t
om_task_set_priority(
    om_task_t *task,
    om_priority_t priority)
{
    if (task == NULL)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    task->priority = priority;

    return OM_SUCCESS;
}


/*==============================================================================
 * Idle Task
 *============================================================================*/

om_task_t *
om_task_idle(void)
{
    return NULL;
}
