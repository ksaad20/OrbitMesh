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

#include <stddef.h>
#include <stdint.h>

#include "orbitmesh/drivers/spi_driver.h"
#include "orbitmesh/error.h"
#include "orbitmesh/spi.h"


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize SPI driver.
 *
 * Initializes the SPI subsystem through the OrbitMesh HAL.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_spi_driver_init(void)
{
    return om_spi_init();
}


/**
 * @brief Transfer SPI data.
 *
 * Performs full duplex SPI communication.
 *
 * @param tx Transmit buffer.
 * @param rx Receive buffer.
 * @param length Number of bytes to transfer.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_spi_driver_transfer(
    const uint8_t *tx,
    uint8_t *rx,
    size_t length)
{
    if (tx == NULL || rx == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (length == 0U)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    return om_spi_transfer(
        tx,
        rx,
        length
    );
}
