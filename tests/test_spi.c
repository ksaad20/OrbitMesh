/**
 * @file test_spi.c
 * @brief OrbitMesh SPI unit tests.
 *
 * Validates SPI communication functionality.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/spi.h"
#include "orbitmesh/error.h"

#include <assert.h>


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_spi_initialization(void)
{
    om_error_t result;


    result =
        om_spi_init(
            0U
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_spi_transfer(void)
{
    uint8_t tx_data =
        0xAAU;

    uint8_t rx_data =
        0U;


    om_error_t result;


    result =
        om_spi_transfer(
            0U,
            &tx_data,
            &rx_data,
            1U
        );


    assert(
        result == OM_SUCCESS
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

int
main(void)
{
    test_spi_initialization();

    test_spi_transfer();


    return 0;
}
