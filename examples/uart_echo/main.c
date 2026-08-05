/**
 * @file main.c
 * @brief OrbitMesh UART echo example.
 *
 * Demonstrates basic UART communication by
 * echoing received characters.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/kernel.h"
#include "orbitmesh/uart.h"


/*==============================================================================
 * Configuration
 *============================================================================*/

#define UART_PORT 0U


/*==============================================================================
 * Application Entry
 *============================================================================*/

int
main(void)
{
    uint8_t buffer;


    om_kernel_init();


    om_uart_init(
        UART_PORT
    );


    om_kernel_start();


    while (1)
    {
        if (om_uart_read(
                UART_PORT,
                &buffer,
                1U)
            == OM_SUCCESS)
        {
            om_uart_write(
                UART_PORT,
                &buffer,
                1U
            );
        }
    }


    return 0;
}
