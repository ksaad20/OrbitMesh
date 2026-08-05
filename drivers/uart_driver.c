/**
 * @file uart_driver.c
 * @brief OrbitMesh UART driver implementation.
 *
 * Provides a simplified UART driver interface over the HAL layer.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/drivers/uart.h"

#include "orbitmesh/error.h"
#include "orbitmesh/uart.h"


#define OM_UART_DEFAULT_ID ((om_uart_id_t)0U)


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
 * @brief Write data using UART driver.
 *
 * @param data Data buffer.
 * @param length Number of bytes.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_write(
    const uint8_t *data,
    size_t length)
{
    return om_uart_write(
        OM_UART_DEFAULT_ID,
        data,
        length
    );
}
