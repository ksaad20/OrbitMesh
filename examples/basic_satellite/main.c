/**
 * @file main.c
 * @brief OrbitMesh basic satellite example.
 *
 * Demonstrates a minimal spacecraft application using OrbitMesh.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "orbitmesh/health_monitor.h"
#include "orbitmesh/kernel.h"
#include "orbitmesh/task.h"
#include "orbitmesh/telemetry.h"

#include <stdint.h>


/*==============================================================================
 * Task Definitions
 *============================================================================*/

/**
 * @brief Housekeeping task.
 *
 * Periodically refreshes spacecraft health monitoring.
 */
static void
housekeeping_task(
    void *argument)
{
    (void)argument;

    for (;;)
    {
        /*
         * Health monitoring is event driven in the
         * current OrbitMesh API. Future sensor checks
         * can report faults here.
         */

        om_task_delay(1000U);
    }
}


/**
 * @brief Telemetry task.
 *
 * Generates telemetry packets periodically.
 */
static void
telemetry_task(
    void *argument)
{
    (void)argument;

    for (;;)
    {
        om_telemetry_update();

        const om_telemetry_packet_t *packet =
            om_telemetry_packet();

        (void)packet;

        om_telemetry_send();

        om_task_delay(5000U);
    }
}


/*==============================================================================
 * Application Entry Point
 *============================================================================*/

int
main(void)
{
    om_kernel_init();

    om_task_init();

    om_health_monitor_init();

    om_telemetry_init();


    om_task_config_t housekeeping_config =
    {
        .name = "housekeeping",
        .entry = housekeeping_task,
        .argument = NULL,
        .stack = NULL,
        .stack_size = 0U,
        .priority = 2U
    };

    om_task_config_t telemetry_config =
    {
        .name = "telemetry",
        .entry = telemetry_task,
        .argument = NULL,
        .stack = NULL,
        .stack_size = 0U,
        .priority = 3U
    };


    (void)om_task_create(
        &housekeeping_config,
        NULL);

    (void)om_task_create(
        &telemetry_config,
        NULL);


    (void)om_kernel_start();


    return 0;
}
