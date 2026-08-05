#ifndef ORBITMESH_DRIVERS_I2C_DRIVER_H
#define ORBITMESH_DRIVERS_I2C_DRIVER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <stdint.h>

#include "orbitmesh/error.h"
#include "orbitmesh/i2c.h"

om_error_t
om_i2c_driver_init(
    om_i2c_id_t i2c);

om_error_t
om_i2c_driver_write(
    om_i2c_id_t i2c,
    uint8_t address,
    const uint8_t *data,
    size_t length);

om_error_t
om_i2c_driver_read(
    om_i2c_id_t i2c,
    uint8_t address,
    uint8_t *data,
    size_t length);

#ifdef __cplusplus
}
#endif

#endif
