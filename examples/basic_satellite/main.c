/**
 * @file main.c
 * @brief OrbitMesh basic satellite application.
 *
 * Minimal spacecraft flight software example.
 *
 * @copyright Apache License 2.0
 */

#include "main.h"

#include "orbitmesh/kernel.h"
#include "orbitmesh/heartbeat.h"
#include "orbitmesh/health_monitor.h"


/**
 * @brief Satellite application initialization.
 */
void
basic_satellite_init(void)
{
    om_health_monitor_init();

    om_heartbeat_init();
}


/**
 * @brief Satellite application loop.
 */
void
basic_satellite_run(void)
{
    while (1)
    {
        om_heartbeat_update();
    }
}


/**
 * @brief Application entry point.
 */
int
main(void)
{
    om_kernel_init();


    basic_satellite_init();


    om_kernel_start();


    basic_satellite_run();


    return 0;
}
