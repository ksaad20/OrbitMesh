#include <assert.h>
#include <stdio.h>

#include "orbitmesh/gpio.h"


static void
test_gpio_initialization(void)
{
    om_gpio_config_t config = {
        .pin = 1U,
        .mode = OM_GPIO_OUTPUT,
    };

    const int result = om_gpio_init(&config);

    assert(result == 0);
}


static void
test_gpio_write(void)
{
    const int result = om_gpio_write(
        1U,
        true
    );

    assert(result == 0);
}


static void
test_gpio_read(void)
{
    bool state = false;

    const int result = om_gpio_read(
        1U,
        &state
    );

    assert(result == 0);
}


void
run_test_gpio(void)
{
    test_gpio_initialization();
    test_gpio_write();
    test_gpio_read();

    printf("GPIO tests passed\n");
}
