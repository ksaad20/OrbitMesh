/**
 * @file tick.c
 * @brief OrbitMesh system tick implementation.
 *
 * Provides the kernel time base.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/timer.h"


static om_tick_t
g_system_tick = 0U;


/**
 * @brief Increment system tick.
 *
 * Called from the platform timer interrupt.
 */
void
om_tick_increment(void)
{
    g_system_tick++;
}


/**
 * @brief Get current kernel tick.
 *
 * @return Current tick count.
 */
om_tick_t
om_tick_get(void)
{
    return g_system_tick;
}
