/**
 * @file timer.c
 * @brief OrbitMesh Linux timer implementation.
 *
 * Provides a host-based timing source for
 * simulator execution and testing.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/types.h"

#include <time.h>


/*==============================================================================
 * Private State
 *============================================================================*/

static struct timespec g_start_time;


/*==============================================================================
 * Public API
 *============================================================================*/

void
om_linux_timer_init(void)
{
    clock_gettime(
        CLOCK_MONOTONIC,
        &g_start_time
    );
}


om_tick_t
om_linux_timer_get_ticks(void)
{
    struct timespec current;


    clock_gettime(
        CLOCK_MONOTONIC,
        &current
    );


    uint64_t elapsed_ms =
        ((uint64_t)(current.tv_sec - g_start_time.tv_sec)
         * 1000U)
        +
        ((uint64_t)(current.tv_nsec - g_start_time.tv_nsec)
         / 1000000U);


    return (om_tick_t)elapsed_ms;
}
