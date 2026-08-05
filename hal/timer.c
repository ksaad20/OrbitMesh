/**
 * @file timer.c
 * @brief OrbitMesh timer HAL implementation.
 *
 * Provides hardware-independent timer API.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/timer.h"
#include "orbitmesh/error.h"


static om_tick_t
g_ticks = 0U;


om_error_t
om_timer_init(
    uint32_t timer)
{
    (void)timer;

    g_ticks = 0U;


    return OM_SUCCESS;
}


om_error_t
om_timer_start(
    uint32_t timer,
    uint32_t period)
{
    (void)timer;
    (void)period;


    return OM_SUCCESS;
}


om_tick_t
om_timer_get_ticks(
    uint32_t timer)
{
    (void)timer;


    return g_ticks;
}


om_tick_t
om_timer_get_system_ticks(void)
{
    return g_ticks;
}
