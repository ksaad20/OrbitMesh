/**
 * @file main.c
 * @brief OrbitMesh basic satellite example.
 *
 * Demonstrates a minimal spacecraft application using OrbitMesh.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/hal.h"
#include "orbitmesh/kernel.h"
#include "orbitmesh/task.h"

#include "drivers/console/console.h"

#include "services/health/health.h"
#include "services/telemetry/telemetry.h"

#include <stddef.h>


/*==============================================================================
 * Task Definitions
 *============================================================================*/

/**
 * @brief Housekeeping task.
 *
 * Periodically updates spacecraft health state.
 */
static void
housekeeping_task(
    void *argument)
{
    (void)argument;

    while (true)
    {
        om_health_update();

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


    om_telemetry_packet_t packet;


    while (true)
    {
        if (om_telemetry_generate(&packet) == OM_SUCCESS)
        {
            om_console_printf(
                "Telemetry packet: %lu\r\n",
                (unsigned long)packet.sequence);
        }


        om_task_delay(5000U);
    }
}


/*==============================================================================
 * Application Entry Point
 *============================================================================*/

int
main(void)
{
    /*
     * Hardware initialization.
     */
    om_hal_init();


    /*
     * Developer console.
     */
    om_console_init();


    om_console_write(
        "OrbitMesh boot\r\n");


    /*
     * Services.
     */
    om_health_init();

    om_telemetry_init();


    /*
     * Create mission tasks.
     */
    om_task_create(
        "housekeeping",
        housekeeping_task,
        NULL,
        2U);


    om_task_create(
        "telemetry",
        telemetry_task,
        NULL,
        3U);


    /*
     * Start operating system.
     */
    om_kernel_start();


    return 0;
}
