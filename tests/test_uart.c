#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "orbitmesh/uart.h"

void
run_test_uart(void);

static void
test_uart_initialization(void)
{
    const om_error_t result = om_uart_init();

    assert(result == OM_SUCCESS);
}

static void
test_uart_write(void)
{
    const om_uart_config_t config =
    {
        .id = 0U,
        .baud_rate = 115200U,
        .data_bits = 8U,
        .parity = OM_UART_PARITY_NONE,
        .stop_bits = OM_UART_STOP_BITS_1,
    };

    om_error_t result = om_uart_configure(
        &config);

    assert(result == OM_SUCCESS);

    static const uint8_t message[] = "OrbitMesh";

    result = om_uart_write(
        0U,
        message,
        sizeof(message) - 1U);

    assert(result == OM_SUCCESS);
}

void
run_test_uart(void)
{
    test_uart_initialization();
    test_uart_write();

    printf("UART tests passed\n");
}
