/**
 * @file timer.c
 * @brief OrbitMesh software timer implementation.
 *
 * Implements a lightweight software timer service.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "kernel_internal.h"

#include "orbitmesh/timer.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/*==============================================================================
 * Private Data
 *============================================================================*/

/**
 * @brief Software timer table.
 */
static om_timer_t g_timers[OM_CONFIG_MAX_TIMERS];

/**
 * @brief Timer allocation bitmap.
 */
static bool g_timer_used[OM_CONFIG_MAX_TIMERS];

/*==============================================================================
 * Private Functions
 *============================================================================*/

/**
 * @brief Allocate a timer.
 *
 * @return Pointer to the allocated timer or NULL if none are available.
 */
static om_timer_t *
timer_allocate(void)
{
    for (size_t i = 0U; i < OM_CONFIG_MAX_TIMERS; ++i)
    {
        if (!g_timer_used[i])
        {
            g_timer_used[i] = true;

            memset(
                &g_timers[i],
                0,
                sizeof(om_timer_t));

            return &g_timers[i];
        }
    }

    return NULL;
}

/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_timer_init(void)
{
    memset(g_timers, 0, sizeof(g_timers));
    memset(g_timer_used, 0, sizeof(g_timer_used));

    return OM_SUCCESS;
}

void
om_timer_tick(void)
{
    for (size_t i = 0U; i < OM_CONFIG_MAX_TIMERS; ++i)
    {
        if (!g_timer_used[i])
        {
            continue;
        }

        om_timer_t *timer = &g_timers[i];

        if (!timer->running)
        {
            continue;
        }

        if (timer->remaining_ticks > 0U)
        {
            --timer->remaining_ticks;
        }

        if (timer->remaining_ticks == 0U)
        {
            if (timer->callback != NULL)
            {
                timer->callback(timer->argument);
            }

            if (timer->periodic)
            {
                timer->remaining_ticks = timer->period_ticks;
            }
            else
            {
                timer->running = false;
            }
        }
    }
}
