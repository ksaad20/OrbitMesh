/**
 * @file i2c_driver.c
 * @brief OrbitMesh I2C driver implementation.
 */

#include "orbitmesh/drivers/i2c_driver.h"

#include "orbitmesh/error.h"
#include "orbitmesh/i2c.h"


om_error_t
om_i2c_driver_init(void)
{
    return om_i2c_init();
}


om_error_t
om_i2c_driver_write(
    uint8_t address,
    const uint8_t *data,
    size_t length)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (length == 0U)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    return om_i2c_write(
        address,
        data,
        length
    );
}


om_error_t
om_i2c_driver_read(
    uint8_t address,
    uint8_t *data,
    size_t length)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (length == 0U)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    return om_i2c_read(
        address,
        data,
        length
    );
}
