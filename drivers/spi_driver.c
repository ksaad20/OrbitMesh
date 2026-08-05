/**
 * @file spi_driver.c
 * @brief OrbitMesh SPI driver wrapper implementation.
 */

#include "orbitmesh/drivers/spi_driver.h"

#include "orbitmesh/spi.h"


/**
 * @brief Initialize SPI driver.
 *
 * @return Operation status.
 */
om_error_t
om_spi_driver_init(void)
{
    return om_spi_init();
}


/**
 * @brief Transfer data using SPI.
 *
 * @param id SPI peripheral identifier.
 * @param tx_data Transmit buffer.
 * @param rx_data Receive buffer.
 * @param length Number of bytes.
 *
 * @return Operation status.
 */
om_error_t
om_spi_driver_transfer(
    om_spi_id_t id,
    const uint8_t *tx_data,
    uint8_t *rx_data,
    size_t length
)
{
    return om_spi_transfer(
        id,
        tx_data,
        rx_data,
        length
    );
}
