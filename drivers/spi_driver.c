/**
 * @file spi_driver.c
 * @brief OrbitMesh SPI driver implementation.
 */

#include "orbitmesh/drivers/spi_driver.h"

#include "orbitmesh/error.h"
#include "orbitmesh/spi.h"


om_error_t
om_spi_driver_init(
    om_spi_id_t id)
{
    return om_spi_init(
        id
    );
}


om_error_t
om_spi_driver_transfer(
    om_spi_id_t id,
    const uint8_t *tx,
    uint8_t *rx,
    size_t length)
{
    if (tx == NULL && rx == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (length == 0U)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    return om_spi_transfer(
        id,
        tx,
        rx,
        length
    );
}
