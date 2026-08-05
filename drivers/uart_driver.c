/**
 * @file uart_driver.c
 * @brief OrbitMesh UART driver implementation.
 *
 * Provides a simplified driver interface over UART HAL.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/drivers/uart.h"

#include "orbitmesh/error.h"
#include "orbitmesh/uart.h"


/**
 * @brief Initialize UART driver.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_init(void)
{
    return om_uart_init();
}


/**
 * @brief Transmit UART data.
 *
 * @param id UART peripheral identifier.
 * @param data Data buffer.
 * @param length Number of bytes.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_write(
    om_uart_id_t id,
    const uint8_t *data,
    size_t length)
{
    return om_uart_write(
        id,
        data,
        length
    );
}
