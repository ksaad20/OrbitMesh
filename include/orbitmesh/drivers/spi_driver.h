/**
 * @file spi_driver.h
 * @brief OrbitMesh SPI driver interface.
 *
 * High-level SPI driver API.
 *
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_DRIVERS_SPI_DRIVER_H
#define ORBITMESH_DRIVERS_SPI_DRIVER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <stdint.h>

#include "orbitmesh/error.h"
#include "orbitmesh/spi.h"


/**
 * @brief Initialize SPI driver.
 *
 * @param spi SPI peripheral identifier.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_spi_driver_init(
    om_spi_id_t spi);


/**
 * @brief Transfer SPI data.
 *
 * @param spi SPI peripheral identifier.
 * @param tx Transmit buffer.
 * @param rx Receive buffer.
 * @param length Number of bytes.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_spi_driver_transfer(
    om_spi_id_t spi,
    const uint8_t *tx,
    uint8_t *rx,
    size_t length);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_DRIVERS_SPI_DRIVER_H */
