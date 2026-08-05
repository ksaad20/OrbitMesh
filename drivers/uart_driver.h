#ifndef ORBITMESH_UART_DRIVER_H
#define ORBITMESH_UART_DRIVER_H

#include "orbitmesh/drivers/uart_driver.h"
#include "orbitmesh/error.h"

om_error_t om_uart_driver_init(void);

om_error_t om_uart_driver_write(
    const uint8_t *data,
    size_t length
);

om_error_t om_uart_driver_read(
    uint8_t *buffer,
    size_t length
);

#endif
