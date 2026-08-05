/**
 * @file uart_driver.c
 * @brief OrbitMesh UART driver.
 *
 * Provides a generic UART interface built on
 * top of the OrbitMesh HAL.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/drivers/uart.h"
#include "orbitmesh/error.h"


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize UART driver.
 *
 * @param uart UART peripheral identifier.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_init(
    om_uart_id_t uart)
{
    return om_uart_init(
        uart
    );
}


/**
 * @brief Send bytes through UART.
 *
 * @param uart UART peripheral identifier.
 * @param data Data buffer.
 * @param length Number of bytes.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_write(
    om_uart_id_t uart,
    const uint8_t *data,
    size_t length)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    return om_uart_write(
        uart,
        data,
        length
    );
}


/**
 * @brief Receive bytes from UART.
 *
 * @param uart UART peripheral identifier.
 * @param buffer Destination buffer.
 * @param length Buffer length.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_uart_driver_read(
    om_uart_id_t uart,
    uint8_t *buffer,
    size_t length)
{
    if (buffer == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    return om_uart_read(
        uart,
        buffer,
        length
    );
}
