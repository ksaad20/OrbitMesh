/**
 * @file task_create.c
 * @brief OrbitMesh task creation implementation.
 *
 * Provides task allocation and initialization.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/task.h"
#include "orbitmesh/error.h"


om_error_t
om_task_create(
    const char *name,
    void (*entry)(void *),
    void *argument)
{
    (void)name;
    (void)entry;
    (void)argument;


    /*
     * MVP implementation:
     * Task registration will be connected
     * to the scheduler task table.
     */


    return OM_SUCCESS;
}
