/**
 * @file test_uart.c
 * @brief OrbitMesh UART unit tests.
 *
 * Validates UART communication functionality.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/uart.h"
#include "orbitmesh/error.h"

#include <assert.h>


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_uart_initialization(void)
{
    om_error_t result;


    result =
        om_uart_init();


    assert(
        result == OM_SUCCESS
    );
}


static void
test_uart_configuration(void)
{
    om_uart_config_t config =
    {
        .id = 0U,
        .baud_rate = 115200U,
        .data_bits = 8U,
        .parity = OM_UART_PARITY_NONE,
        .stop_bits = OM_UART_STOP_BITS_1
    };

    om_error_t result;


    result =
        om_uart_configure(
            &config
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_uart_write(void)
{
    uint8_t data =
        'A';

    om_error_t result;


    result =
        om_uart_write(
            0U,
            &data,
            1U
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_uart_read_byte(void)
{
    uint8_t data =
        0U;

    om_error_t result;


    result =
        om_uart_read_byte(
            0U,
            &data
        );


    assert(
        result == OM_SUCCESS ||
        result == OM_ERROR_TIMEOUT
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

int
main(void)
{
    test_uart_initialization();

    test_uart_configuration();

    test_uart_write();

    test_uart_read_byte();


    return 0;
}
