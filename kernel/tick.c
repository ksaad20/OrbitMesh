/**
 * @file tick.c
 * @brief OrbitMesh system tick implementation.
 */

#include "orbitmesh/timer.h"

void
om_tick_increment(void);

om_tick_t
om_tick_get(void);

static om_tick_t g_system_tick = 0U;

void
om_tick_increment(void)
{
    ++g_system_tick;
}

om_tick_t
om_tick_get(void)
{
    return g_system_tick;
}
