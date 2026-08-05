/**
 * @file uart_driver.c
 * @brief OrbitMesh UART driver interface implementation.
 *
 * Provides a driver-level abstraction over the UART HAL.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/drivers/uart.h"

#include "orbitmesh/error.h"
#include "orbitmesh/uart.h"


/**
 * @brief Initialize UART driver.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_uart_driver_init(void)
{
    return om_uart_init();
}


/**
 * @brief Write data through UART driver.
 *
 * @param data Buffer containing bytes to transmit.
 * @param length Number of bytes to transmit.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_uart_driver_write(
    const uint8_t *data,
    size_t length)
{
    return om_uart_write(
        data,
        length
    );
}


/**
 * @brief Read data through UART driver.
 *
 * @param data Buffer receiving bytes.
 * @param length Maximum number of bytes to read.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_uart_driver_read(
    uint8_t *data,
    size_t length)
{
    return om_uart_read(
        data,
        length
    );
}
