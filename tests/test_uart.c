#include <assert.h>
#include <stdio.h>

#include "orbitmesh/uart.h"


void run_test_uart(void);


static void
test_uart_initialization(void)
{
    const int result = om_uart_init();

    assert(result == 0);
}


static void
test_uart_write(void)
{
    const uint8_t message[] = "OrbitMesh";

    const int result = om_uart_write(
        0U,
        message,
        sizeof(message) - 1U
    );

    assert(result == 0);
}


static void
test_uart_read_byte(void)
{
    uint8_t byte = 0U;

    const int result = om_uart_read(
        0U,
        &byte
    );

    assert(result == 0);
}


void
run_test_uart(void)
{
    test_uart_initialization();
    test_uart_write();
    test_uart_read_byte();

    printf("UART tests passed\n");
}
