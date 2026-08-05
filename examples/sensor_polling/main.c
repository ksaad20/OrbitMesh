/**
 * @file main.c
 * @brief OrbitMesh sensor polling example.
 *
 * Demonstrates a periodic sensor acquisition
 * task running under the OrbitMesh scheduler.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/kernel.h"
#include "orbitmesh/task.h"
#include "orbitmesh/log.h"


/*==============================================================================
 * Configuration
 *============================================================================*/

#define SENSOR_POLL_PERIOD_MS 1000U


/*==============================================================================
 * Mock Sensor Interface
 *============================================================================*/

static int
sensor_read(void)
{
    /*
     * Placeholder payload sensor.
     *
     * Real hardware drivers connect through:
     * - I2C
     * - SPI
     * - ADC
     */
    return 42;
}


/*==============================================================================
 * Task
 *============================================================================*/

static void
sensor_task(
    void *argument)
{
    (void)argument;


    while (1)
    {
        int sensor_value;


        sensor_value =
            sensor_read();


        om_log_info(
            "Sensor value: %d",
            sensor_value
        );


        om_task_delay(
            SENSOR_POLL_PERIOD_MS
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


    om_task_create(
        "sensor",
        sensor_task,
        NULL
    );


    om_kernel_start();


    while (1)
    {
    }


    return 0;
}

