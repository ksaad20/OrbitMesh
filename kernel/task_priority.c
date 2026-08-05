/**
 * @file task_priority.c
 * @brief OrbitMesh task priority management.
 *
 * Provides task priority configuration.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/task.h"
#include "orbitmesh/error.h"


om_error_t
om_task_set_priority(
    om_task_id_t task,
    uint8_t priority)
{
    (void)task;
    (void)priority;


    /*
     * MVP implementation.
     *
     * Priority scheduling support
     * will be expanded in the scheduler.
     */


    return OM_SUCCESS;
}


uint8_t
om_task_get_priority(
    om_task_id_t task)
{
    (void)task;


    return 0U;
}
