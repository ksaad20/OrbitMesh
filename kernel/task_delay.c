/**
 * @file task_delay.c
 * @brief OrbitMesh task delay implementation.
 *
 * Provides cooperative task delay support.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/task.h"
#include "orbitmesh/error.h"


om_error_t
om_task_delay(
    uint32_t milliseconds)
{
    (void)milliseconds;


    /*
     * MVP implementation.
     *
     * Hardware ports may replace this
     * with scheduler tick blocking.
     */


    return OM_SUCCESS;
}
