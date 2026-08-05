/**
 * @file uart.h
 * @brief OrbitMesh UART Hardware Abstraction Layer.
 *
 * Provides a hardware-independent UART interface for communication,
 * debugging, and telemetry.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_UART_H
#define ORBITMESH_UART_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "error.h"
#include "types.h"

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/*==============================================================================
 * UART Types
 *============================================================================*/

/**
 * @brief UART parity configuration.
 */
typedef enum
{
    OM_UART_PARITY_NONE = 0,
    OM_UART_PARITY_EVEN,
    OM_UART_PARITY_ODD
} om_uart_parity_t;


/**
 * @brief UART stop bit configuration.
 */
typedef enum
{
    OM_UART_STOP_BITS_1 = 0,
    OM_UART_STOP_BITS_2
} om_uart_stop_bits_t;


/**
 * @brief UART configuration.
 */
typedef struct
{
    /**
     * UART peripheral identifier.
     */
    om_uart_id_t id;

    /**
     * Baud rate.
     */
    uint32_t baud_rate;

    /**
     * Number of data bits.
     */
    uint8_t data_bits;

    /**
     * Parity mode.
     */
    om_uart_parity_t parity;

    /**
     * Stop bits.
     */
    om_uart_stop_bits_t stop_bits;

} om_uart_config_t;


/**
 * @brief UART receive callback.
 *
 * @param data Received byte.
 * @param argument User argument.
 */
typedef void (*om_uart_rx_callback_t)(
    uint8_t data,
    void *argument);


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize UART subsystem.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_uart_init(void);


/**
 * @brief Configure UART peripheral.
 *
 * @param config UART configuration.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_uart_configure(
    const om_uart_config_t *config);


/**
 * @brief Send a byte.
 *
 * @param id UART identifier.
 * @param data Byte to send.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_uart_write_byte(
    om_uart_id_t id,
    uint8_t data);


/**
 * @brief Send a buffer.
 *
 * @param id UART identifier.
 * @param data Buffer.
 * @param length Number of bytes.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_uart_write(
    om_uart_id_t id,
    const uint8_t *data,
    size_t length);


/**
 * @brief Read a byte.
 *
 * @param id UART identifier.
 * @param data Output byte.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_uart_read_byte(
    om_uart_id_t id,
    uint8_t *data);


/**
 * @brief Register receive callback.
 *
 * @param id UART identifier.
 * @param callback Callback.
 * @param argument User argument.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_uart_set_rx_callback(
    om_uart_id_t id,
    om_uart_rx_callback_t callback,
    void *argument);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_UART_H */
