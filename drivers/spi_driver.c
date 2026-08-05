/**
 * @file spi_driver.c
 * @brief OrbitMesh SPI driver implementation.
 *
 * Provides a simplified SPI driver interface over the SPI HAL.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/drivers/spi_driver.h"

#include "orbitmesh/error.h"
#include "orbitmesh/spi.h"


#define OM_SPI_DEFAULT_ID ((om_spi_id_t)0U)


/**
 * @brief Initialize SPI driver.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_spi_driver_init(void)
{
    return OM_SUCCESS;
}


/**
 * @brief Transfer data over SPI.
 *
 * @param tx Transmit buffer.
 * @param rx Receive buffer.
 * @param length Transfer length.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_spi_driver_transfer(
    const uint8_t *tx,
    uint8_t *rx,
    size_t length)
{
    return om_spi_transfer(
        OM_SPI_DEFAULT_ID,
        tx,
        rx,
        length
    );
}
