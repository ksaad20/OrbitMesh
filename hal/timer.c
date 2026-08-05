/**
 * @file timer.c
 * @brief OrbitMesh software timer implementation.
 *
 * Minimal timer implementation for the OrbitMesh MVP.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "orbitmesh/timer.h"

#include <stddef.h>

/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_timer_init(void)
{
    return OM_SUCCESS;
}

om_error_t
om_timer_create(
    om_timer_t *timer,
    om_tick_t period_ticks,
    bool periodic,
    om_timer_callback_t callback,
    void *argument
)
{
    if (timer == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    timer->allocated = true;
    timer->running = false;
    timer->periodic = periodic;
    timer->period_ticks = period_ticks;
    timer->remaining_ticks = period_ticks;
    timer->callback = callback;
    timer->argument = argument;

    return OM_SUCCESS;
}

om_error_t
om_timer_start(
    om_timer_t *timer
)
{
    if (timer == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    timer->running = true;
    timer->remaining_ticks = timer->period_ticks;

    return OM_SUCCESS;
}

om_error_t
om_timer_stop(
    om_timer_t *timer
)
{
    if (timer == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    timer->running = false;

    return OM_SUCCESS;
}

om_error_t
om_timer_restart(
    om_timer_t *timer
)
{
    if (timer == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    timer->remaining_ticks = timer->period_ticks;
    timer->running = true;

    return OM_SUCCESS;
}

bool
om_timer_is_running(
    const om_timer_t *timer
)
{
    if (timer == NULL)
    {
        return false;
    }

    return timer->running;
}

void
om_timer_tick(void)
{
    /* MVP placeholder.
     * Scheduler integration will be added in a future release.
     */
}
