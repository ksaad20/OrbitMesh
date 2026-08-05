/**
 * @file uart.c
 * @brief OrbitMesh UART HAL implementation.
 *
 * Implements the hardware-independent UART layer.
 *
 * MVP implementation:
 * - Static peripheral instances.
 * - No dynamic memory.
 * - Platform hooks can replace the internal behavior later.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/uart.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/*==============================================================================
 * Configuration
 *============================================================================*/

#ifndef OM_UART_MAX_INSTANCES
#define OM_UART_MAX_INSTANCES 8U
#endif


/*==============================================================================
 * Private Data
 *============================================================================*/

/**
 * @brief Internal UART state.
 */
typedef struct
{
    bool configured;

    om_uart_config_t config;

    om_uart_rx_callback_t rx_callback;

    void *rx_argument;

} om_uart_state_t;


/**
 * @brief UART instance table.
 */
static om_uart_state_t g_uart_instances[OM_UART_MAX_INSTANCES];


/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_uart_init(void)
{
    memset(
        g_uart_instances,
        0,
        sizeof(g_uart_instances));

    return OM_SUCCESS;
}


om_error_t
om_uart_configure(
    const om_uart_config_t *config)
{
    if (config == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (config->id >= OM_UART_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    g_uart_instances[config->id].configured = true;

    g_uart_instances[config->id].config = *config;

    return OM_SUCCESS;
}


om_error_t
om_uart_write_byte(
    om_uart_id_t id,
    uint8_t data)
{
    (void)data;

    if (id >= OM_UART_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (!g_uart_instances[id].configured)
    {
        return OM_ERROR_INVALID_STATE;
    }

    /*
     * Platform-specific transmission is implemented by
     * the selected platform driver.
     */

    return OM_SUCCESS;
}


om_error_t
om_uart_write(
    om_uart_id_t id,
    const uint8_t *data,
    size_t length)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (id >= OM_UART_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (!g_uart_instances[id].configured)
    {
        return OM_ERROR_INVALID_STATE;
    }

    for (size_t i = 0U; i < length; ++i)
    {
        om_error_t result =
            om_uart_write_byte(id, data[i]);

        if (result != OM_SUCCESS)
        {
            return result;
        }
    }

    return OM_SUCCESS;
}


om_error_t
om_uart_read_byte(
    om_uart_id_t id,
    uint8_t *data)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (id >= OM_UART_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (!g_uart_instances[id].configured)
    {
        return OM_ERROR_INVALID_STATE;
    }

    /*
     * No data source exists in the MVP simulation.
     * Platform drivers provide actual reception.
     */

    return OM_ERROR_NOT_AVAILABLE;
}


om_error_t
om_uart_set_rx_callback(
    om_uart_id_t id,
    om_uart_rx_callback_t callback,
    void *argument)
{
    if (id >= OM_UART_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (!g_uart_instances[id].configured)
    {
        return OM_ERROR_INVALID_STATE;
    }

    g_uart_instances[id].rx_callback = callback;

    g_uart_instances[id].rx_argument = argument;

    return OM_SUCCESS;
}
