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
        om_uart_init(
            0U
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
test_uart_read(void)
{
    uint8_t data;


    om_error_t result;


    result =
        om_uart_read(
            0U,
            &data,
            1U
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

    test_uart_write();

    test_uart_read();


    return 0;
}
