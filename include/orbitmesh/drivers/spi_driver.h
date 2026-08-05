/**
 * @file spi_driver.h
 * @brief OrbitMesh SPI driver interface.
 */

#ifndef ORBITMESH_SPI_DRIVER_H
#define ORBITMESH_SPI_DRIVER_H

#include <stddef.h>
#include <stdint.h>

#include "orbitmesh/error.h"
#include "orbitmesh/spi.h"

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @brief Initialize SPI driver.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_spi_driver_init(void);


/**
 * @brief Transfer data using SPI.
 *
 * @param id SPI device identifier.
 * @param tx Transmit buffer.
 * @param rx Receive buffer.
 * @param length Transfer length.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_spi_driver_transfer(
    om_spi_id_t id,
    const uint8_t *tx,
    uint8_t *rx,
    size_t length);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_SPI_DRIVER_H */
