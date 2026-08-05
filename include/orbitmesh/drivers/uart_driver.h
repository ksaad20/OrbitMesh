/**
 * @file uart.h
 * @brief OrbitMesh UART driver interface.
 *
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_DRIVERS_UART_H
#define ORBITMESH_DRIVERS_UART_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <stdint.h>

#include "orbitmesh/error.h"
#include "orbitmesh/uart.h"


/**
 * @brief Initialize UART driver.
 *
 * @param uart UART peripheral identifier.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_init(
    om_uart_id_t uart);


/**
 * @brief Send UART data.
 *
 * @param uart UART peripheral identifier.
 * @param data Data buffer.
 * @param length Data length.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_write(
    om_uart_id_t uart,
    const uint8_t *data,
    size_t length);


/**
 * @brief Receive UART data.
 *
 * @param uart UART peripheral identifier.
 * @param data Receive buffer.
 * @param length Buffer length.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_read(
    om_uart_id_t uart,
    uint8_t *data,
    size_t length);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_DRIVERS_UART_H */
