#include <assert.h>
#include <stdio.h>

#include "orbitmesh/gpio.h"

void
run_test_gpio(void);

static void
test_gpio_initialization(void)
{
    const om_error_t result = om_gpio_init();

    assert(result == OM_SUCCESS);
}

static void
test_gpio_write(void)
{
    const om_gpio_config_t config =
    {
        .pin = 1U,
        .mode = OM_GPIO_OUTPUT,
        .pull = 0,
    };

    om_error_t result = om_gpio_configure(&config);

    assert(result == OM_SUCCESS);

    result = om_gpio_write(
        1U,
        OM_GPIO_HIGH);

    assert(result == OM_SUCCESS);
}

static void
test_gpio_read(void)
{
    om_gpio_level_t level = OM_GPIO_LOW;

    const om_error_t result =
        om_gpio_read(
            1U,
            &level);

    assert(result == OM_SUCCESS);
    assert(level == OM_GPIO_HIGH);
}

void
run_test_gpio(void)
{
    test_gpio_initialization();
    test_gpio_write();
    test_gpio_read();

    printf("GPIO tests passed\n");
}
