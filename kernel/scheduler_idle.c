/**
 * @file scheduler_idle.c
 * @brief OrbitMesh idle scheduler task.
 *
 * Runs when no application task is ready.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/types.h"


void
om_scheduler_idle(void)
{
    while (1)
    {
        /*
         * Idle loop.
         *
         * Hardware platforms may enter
         * low-power mode here.
         */
    }
}
