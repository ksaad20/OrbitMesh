/**
 * @file uart.h
 * @brief OrbitMesh UART driver interface.
 *
 * Provides a simplified UART driver API built on top
 * of the OrbitMesh HAL layer.
 *
 * @author OrbitMesh Contributors
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


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize UART driver.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_init(void);


/**
 * @brief Write data through UART.
 *
 * @param data Data buffer.
 * @param length Number of bytes to send.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_write(
    const uint8_t *data,
    size_t length);


/**
 * @brief Read data from UART.
 *
 * @param data Receive buffer.
 * @param length Number of bytes to read.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_read(
    uint8_t *data,
    size_t length);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_DRIVERS_UART_H */
