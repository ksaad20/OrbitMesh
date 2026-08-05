/**
 * @file i2c.c
 * @brief OrbitMesh I2C HAL implementation.
 *
 * Hardware-independent I2C interface.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/i2c.h"
#include "orbitmesh/error.h"


om_error_t
om_i2c_init(
    uint32_t bus)
{
    (void)bus;

    return OM_SUCCESS;
}


om_error_t
om_i2c_write(
    uint32_t bus,
    uint8_t address,
    const uint8_t *data,
    uint32_t length)
{
    (void)bus;
    (void)address;
    (void)data;
    (void)length;


    return OM_SUCCESS;
}


om_error_t
om_i2c_read(
    uint32_t bus,
    uint8_t address,
    uint8_t *data,
    uint32_t length)
{
    (void)bus;
    (void)address;
    (void)data;
    (void)length;


    return OM_SUCCESS;
}
