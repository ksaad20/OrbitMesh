/**
 * @file i2c_driver.h
 * @brief OrbitMesh I2C driver interface.
 */

#ifndef ORBITMESH_I2C_DRIVER_H
#define ORBITMESH_I2C_DRIVER_H

#include <stddef.h>
#include <stdint.h>

#include "orbitmesh/error.h"

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @brief Initialize I2C driver.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_i2c_driver_init(void);


/**
 * @brief Write data to an I2C device.
 *
 * @param address Device address.
 * @param data Data buffer.
 * @param length Number of bytes.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_i2c_driver_write(
    uint8_t address,
    const uint8_t *data,
    size_t length);


/**
 * @brief Read data from an I2C device.
 *
 * @param address Device address.
 * @param data Receive buffer.
 * @param length Number of bytes.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_i2c_driver_read(
    uint8_t address,
    uint8_t *data,
    size_t length);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_I2C_DRIVER_H */
