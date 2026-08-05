/**
 * @file main.c
 * @brief OrbitMesh heartbeat example.
 *
 * Demonstrates a periodic heartbeat service
 * running under the OrbitMesh scheduler.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/kernel.h"
#include "orbitmesh/task.h"
#include "orbitmesh/heartbeat.h"


/*==============================================================================
 * Configuration
 *============================================================================*/

#define HEARTBEAT_INTERVAL_MS 1000U


/*==============================================================================
 * Task
 *============================================================================*/

static void
heartbeat_task(
    void *argument)
{
    (void)argument;


    while (1)
    {
        om_heartbeat_update();


        om_task_delay(
            HEARTBEAT_INTERVAL_MS
        );
    }
}


/*==============================================================================
 * Application Entry
 *============================================================================*/

int
main(void)
{
    om_kernel_init();


    om_heartbeat_init();


    om_task_create(
        "heartbeat",
        heartbeat_task,
        NULL
    );


    om_kernel_start();


    while (1)
    {
    }


    return 0;
}
