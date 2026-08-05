/**
 * @file i2c.c
 * @brief OrbitMesh I2C HAL implementation.
 *
 * Implements the hardware-independent I2C layer.
 *
 * MVP implementation:
 * - Static peripheral instances.
 * - No dynamic allocation.
 * - Deterministic behavior.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/i2c.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/*==============================================================================
 * Configuration
 *============================================================================*/

#ifndef OM_I2C_MAX_INSTANCES
#define OM_I2C_MAX_INSTANCES 8U
#endif


/*==============================================================================
 * Private Data
 *============================================================================*/

/**
 * @brief Internal I2C peripheral state.
 */
typedef struct
{
    bool configured;

    om_i2c_config_t config;

} om_i2c_state_t;


/**
 * @brief I2C instance table.
 */
static om_i2c_state_t g_i2c_instances[OM_I2C_MAX_INSTANCES];


/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_i2c_init(void)
{
    memset(
        g_i2c_instances,
        0,
        sizeof(g_i2c_instances));

    return OM_SUCCESS;
}


om_error_t
om_i2c_configure(
    const om_i2c_config_t *config)
{
    if (config == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (config->id >= OM_I2C_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    g_i2c_instances[config->id].configured = true;

    g_i2c_instances[config->id].config = *config;

    return OM_SUCCESS;
}


om_error_t
om_i2c_write(
    om_i2c_id_t id,
    uint8_t address,
    const uint8_t *data,
    size_t length)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (id >= OM_I2C_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (!g_i2c_instances[id].configured)
    {
        return OM_ERROR_INVALID_STATE;
    }

    /*
     * Platform-specific I2C transmission is implemented
     * by the board support layer.
     */

    (void)address;
    (void)length;

    return OM_SUCCESS;
}


om_error_t
om_i2c_read(
    om_i2c_id_t id,
    uint8_t address,
    uint8_t *data,
    size_t length)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (id >= OM_I2C_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (!g_i2c_instances[id].configured)
    {
        return OM_ERROR_INVALID_STATE;
    }

    /*
     * MVP simulation returns zero-filled data.
     * Hardware platforms replace this implementation.
     */

    memset(
        data,
        0,
        length);

    (void)address;

    return OM_SUCCESS;
}


om_error_t
om_i2c_transfer(
    om_i2c_id_t id,
    uint8_t address,
    const uint8_t *tx_data,
    size_t tx_length,
    uint8_t *rx_data,
    size_t rx_length)
{
    if (tx_data == NULL || rx_data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (id >= OM_I2C_MAX_INSTANCES)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (!g_i2c_instances[id].configured)
    {
        return OM_ERROR_INVALID_STATE;
    }

    /*
     * MVP behavior:
     * simulate register read by clearing receive buffer.
     */

    memset(
        rx_data,
        0,
        rx_length);

    (void)address;
    (void)tx_data;
    (void)tx_length;

    return OM_SUCCESS;
}
