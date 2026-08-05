/**
 * @file main.c
 * @brief OrbitMesh telemetry example.
 *
 * Demonstrates collection and transmission
 * of system health telemetry.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/kernel.h"
#include "orbitmesh/task.h"
#include "orbitmesh/diagnostics.h"
#include "orbitmesh/uart.h"

#include <stdio.h>


/*==============================================================================
 * Configuration
 *============================================================================*/

#define UART_PORT 0U

#define TELEMETRY_PERIOD_MS 1000U


/*==============================================================================
 * Task
 *============================================================================*/

static void
telemetry_task(
    void *argument)
{
    (void)argument;


    while (1)
    {
        om_diagnostics_report_t report;


        if (om_diagnostics_collect(
                &report)
            == OM_SUCCESS)
        {
            char message[128];


            snprintf(
                message,
                sizeof(message),
                "HEALTH=%d FAULTS=%lu HEARTBEAT=%lu\n",
                report.health,
                (unsigned long)report.fault_count,
                (unsigned long)report.heartbeat_count
            );


            om_uart_write(
                UART_PORT,
                (uint8_t *)message,
                sizeof(message)
            );
        }


        om_task_delay(
            TELEMETRY_PERIOD_MS
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


    om_uart_init(
        UART_PORT
    );


    om_diagnostics_init();


    om_task_create(
        "telemetry",
        telemetry_task,
        NULL
    );


    om_kernel_start();


    while (1)
    {
    }


    return 0;
}
