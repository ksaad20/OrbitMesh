/**
 * @file spi_driver.c
 * @brief OrbitMesh SPI driver.
 *
 * Provides a generic SPI interface built on top
 * of the OrbitMesh HAL layer.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/spi.h"
#include "orbitmesh/error.h"


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize SPI driver.
 *
 * @param spi SPI peripheral identifier.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_spi_driver_init(
    om_spi_id_t spi)
{
    return om_spi_init(
        spi
    );
}


/**
 * @brief Transfer SPI data.
 *
 * Performs full duplex SPI communication.
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
    size_t length)
{
    if (tx == NULL || rx == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    return om_spi_transfer(
        spi,
        tx,
        rx,
        length
    );
}
