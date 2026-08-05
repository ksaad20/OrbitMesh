/**
 * @file test_gpio.c
 * @brief OrbitMesh GPIO unit tests.
 *
 * Validates GPIO driver functionality.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/gpio.h"
#include "orbitmesh/error.h"

#include <assert.h>


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_gpio_configuration(void)
{
    om_gpio_config_t config =
    {
        .pin = 1U,
        .mode = OM_GPIO_OUTPUT,
        .pull = OM_GPIO_PULL_NONE
    };

    om_error_t result;


    result =
        om_gpio_configure(
            &config
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_gpio_write(void)
{
    om_error_t result;


    result =
        om_gpio_write(
            1U,
            OM_GPIO_HIGH
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_gpio_read(void)
{
    om_gpio_level_t level;

    om_error_t result;


    result =
        om_gpio_read(
            1U,
            &level
        );


    assert(
        result == OM_SUCCESS
    );


    assert(
        level == OM_GPIO_HIGH ||
        level == OM_GPIO_LOW
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

int
main(void)
{
    test_gpio_configuration();

    test_gpio_write();

    test_gpio_read();


    return 0;
}
