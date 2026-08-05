/**
 * @file test_i2c.c
 * @brief OrbitMesh I2C unit tests.
 *
 * Validates I2C communication functionality.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/i2c.h"
#include "orbitmesh/error.h"

#include <assert.h>


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_i2c_initialization(void)
{
    om_error_t result;


    result =
        om_i2c_init(
            0U
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_i2c_write(void)
{
    uint8_t data =
        0x55U;


    om_error_t result;


    result =
        om_i2c_write(
            0U,
            0x40U,
            &data,
            1U
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_i2c_read(void)
{
    uint8_t data;


    om_error_t result;


    result =
        om_i2c_read(
            0U,
            0x40U,
            &data,
            1U
        );


    assert(
        result == OM_SUCCESS
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

void
run_test_i2c(void)
{
    test_i2c_configuration();

    test_i2c_write();

    test_i2c_read();
}
