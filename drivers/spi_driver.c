/**
 * @file spi_driver.c
 * @brief OrbitMesh SPI driver wrapper implementation.
 */

#include "orbitmesh/drivers/spi_driver.h"

#include "orbitmesh/error.h"
#include "orbitmesh/spi.h"


/**
 * @brief Initialize the SPI driver.
 *
 * The HAL SPI layer currently manages the SPI peripheral
 * initialization internally, so no SPI identifier is required.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_spi_driver_init(void)
{
    return om_spi_init();
}


/**
 * @brief Transfer data through SPI.
 *
 * Uses the default SPI peripheral identifier.
 *
 * @param tx_data Transmit buffer.
 * @param rx_data Receive buffer.
 * @param length Number of bytes to transfer.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_spi_driver_transfer(
    const uint8_t *tx_data,
    uint8_t *rx_data,
    size_t length
)
{
    return om_spi_transfer(
        0U,
        tx_data,
        rx_data,
        length
    );
}
