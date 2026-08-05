/**
 * @file i2c.h
 * @brief OrbitMesh I2C Hardware Abstraction Layer.
 *
 * Provides a hardware-independent I2C interface for embedded peripherals.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_I2C_H
#define ORBITMESH_I2C_H

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
 * I2C Types
 *============================================================================*/

/**
 * @brief I2C bus speed.
 */
typedef enum
{
    OM_I2C_SPEED_STANDARD = 100000U,
    OM_I2C_SPEED_FAST = 400000U
} om_i2c_speed_t;


/**
 * @brief I2C configuration.
 */
typedef struct
{
    /**
     * I2C peripheral identifier.
     */
    om_i2c_id_t id;

    /**
     * Bus speed.
     */
    om_i2c_speed_t speed;

} om_i2c_config_t;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize I2C subsystem.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_i2c_init(void);


/**
 * @brief Configure an I2C peripheral.
 *
 * @param config I2C configuration.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_i2c_configure(
    const om_i2c_config_t *config);


/**
 * @brief Write bytes to an I2C device.
 *
 * @param id I2C peripheral identifier.
 * @param address Device address.
 * @param data Data buffer.
 * @param length Number of bytes.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_i2c_write(
    om_i2c_id_t id,
    uint8_t address,
    const uint8_t *data,
    size_t length);


/**
 * @brief Read bytes from an I2C device.
 *
 * @param id I2C peripheral identifier.
 * @param address Device address.
 * @param data Receive buffer.
 * @param length Number of bytes.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_i2c_read(
    om_i2c_id_t id,
    uint8_t address,
    uint8_t *data,
    size_t length);


/**
 * @brief Write then read in one transaction.
 *
 * Useful for register-based sensors.
 *
 * @param id I2C peripheral identifier.
 * @param address Device address.
 * @param tx_data Write buffer.
 * @param tx_length Write length.
 * @param rx_data Receive buffer.
 * @param rx_length Receive length.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_i2c_transfer(
    om_i2c_id_t id,
    uint8_t address,
    const uint8_t *tx_data,
    size_t tx_length,
    uint8_t *rx_data,
    size_t rx_length);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_I2C_H */
