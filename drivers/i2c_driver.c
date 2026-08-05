/**
 * @file i2c_driver.c
 * @brief OrbitMesh I2C driver.
 *
 * Provides a generic I2C interface built on top
 * of the OrbitMesh HAL layer.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/i2c.h"
#include "orbitmesh/error.h"


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize I2C driver.
 *
 * @param i2c I2C peripheral identifier.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_i2c_driver_init(
    om_i2c_id_t i2c)
{
    return om_i2c_init(
        i2c
    );
}


/**
 * @brief Write data to an I2C device.
 *
 * @param i2c I2C peripheral identifier.
 * @param address Device address.
 * @param data Data buffer.
 * @param length Number of bytes.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_i2c_driver_write(
    om_i2c_id_t i2c,
    uint8_t address,
    const uint8_t *data,
    size_t length)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    return om_i2c_write(
        i2c,
        address,
        data,
        length
    );
}


/**
 * @brief Read data from an I2C device.
 *
 * @param i2c I2C peripheral identifier.
 * @param address Device address.
 * @param data Destination buffer.
 * @param length Number of bytes.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_i2c_driver_read(
    om_i2c_id_t i2c,
    uint8_t address,
    uint8_t *data,
    size_t length)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    return om_i2c_read(
        i2c,
        address,
        data,
        length
    );
}
