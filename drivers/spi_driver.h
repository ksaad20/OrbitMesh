/**
 * @file spi_driver.h
 * @brief OrbitMesh SPI driver interface.
 *
 * Provides a generic SPI driver API built on top
 * of the OrbitMesh HAL layer.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_DRIVERS_SPI_DRIVER_H
#define ORBITMESH_DRIVERS_SPI_DRIVER_H

#include <stddef.h>
#include <stdint.h>

#include "orbitmesh/error.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize SPI driver.
 *
 * Initializes the SPI subsystem.
 *
 * @return OM_ERROR_OK on success, otherwise an error code.
 */
om_error_t
om_spi_driver_init(void);


/**
 * @brief Transfer SPI data.
 *
 * Performs full duplex SPI communication.
 *
 * @param tx Transmit buffer.
 * @param rx Receive buffer.
 * @param length Number of bytes to transfer.
 *
 * @return OM_ERROR_OK on success, otherwise an error code.
 */
om_error_t
om_spi_driver_transfer(
    const uint8_t *tx,
    uint8_t *rx,
    size_t length
);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_DRIVERS_SPI_DRIVER_H */
