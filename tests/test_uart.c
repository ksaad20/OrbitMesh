#include <assert.h>
#include <stdio.h>
#include <stdint.h>

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


void
run_test_uart(void)
{
    test_uart_initialization();
    test_uart_write();

    printf("UART tests passed\n");
}
