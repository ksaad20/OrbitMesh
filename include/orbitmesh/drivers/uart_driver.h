#ifndef ORBITMESH_DRIVERS_UART_H
#define ORBITMESH_DRIVERS_UART_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <stdint.h>

#include "orbitmesh/error.h"


om_error_t
om_uart_driver_init(void);


om_error_t
om_uart_driver_write(
    const uint8_t *data,
    size_t length);


om_error_t
om_uart_driver_read(
    uint8_t *data,
    size_t length);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_DRIVERS_UART_H */
