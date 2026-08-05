/**
 * @file spi.c
 * @brief OrbitMesh SPI HAL implementation.
 *
 * Implements the hardware-independent SPI layer.
 *
 * MVP implementation:
 * - Static peripheral instances.
 * - No dynamic memory allocation.
 * - Platform drivers provide actual hardware access.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/spi.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/*==============================================================================
 * Configuration
 *============================================================================*/

#ifndef OM_SPI_MAX_INSTANCES
#define OM_SPI_MAX_INSTANCES 8U
#endif


/*==============================================================================
 * Private Data
 *============================================================================*/

/**
 * @brief Internal SPI state.
 */
typedef struct
{
    bool configured;

    om_spi_config_t config;

} om_spi_state_t;


/**
 * @brief SPI instance table.
 */
static om_spi_state_t g_spi_instances[OM_SPI_MAX_INSTANCES];


/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_spi_init(void)
{
    memset(
        g_spi_instances,
        0,
        sizeof(g_spi_instances));

    return OM_SUCCESS;
}


om_error_t
om_spi_configure(
    const om_spi_config_t *config)
{
    if (config == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (config->id >= OM_SPI_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    g_spi_instances[config->id].configured = true;

    g_spi_instances[config->id].config = *config;

    return OM_SUCCESS;
}


om_error_t
om_spi_transfer(
    om_spi_id_t id,
    const uint8_t *tx_data,
    uint8_t *rx_data,
    size_t length)
{
    if (tx_data == NULL || rx_data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (id >= OM_SPI_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (!g_spi_instances[id].configured)
    {
        return OM_ERROR_INVALID_STATE;
    }

    /*
     * MVP simulation:
     * Loopback behavior.
     *
     * Platform implementations replace this with
     * actual SPI peripheral access.
     */
    for (size_t i = 0U; i < length; ++i)
    {
        rx_data[i] = tx_data[i];
    }

    return OM_SUCCESS;
}


om_error_t
om_spi_write(
    om_spi_id_t id,
    const uint8_t *data,
    size_t length)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (id >= OM_SPI_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (!g_spi_instances[id].configured)
    {
        return OM_ERROR_INVALID_STATE;
    }

    /*
     * Actual transmission is implemented by
     * the platform SPI driver.
     */

    (void)length;

    return OM_SUCCESS;
}


om_error_t
om_spi_read(
    om_spi_id_t id,
    uint8_t *data,
    size_t length)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (id >= OM_SPI_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (!g_spi_instances[id].configured)
    {
        return OM_ERROR_INVALID_STATE;
    }

    memset(
        data,
        0,
        length);

    return OM_SUCCESS;
}
