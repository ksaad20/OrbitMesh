#include <assert.h>
#include <stdio.h>

#include "orbitmesh/gpio.h"


void run_test_gpio(void);


static void
test_gpio_initialization(void)
{
    const int result = om_gpio_init();

    assert(result == 0);
}


static void
test_gpio_write(void)
{
    const int result = om_gpio_write(
        1U,
        OM_GPIO_HIGH
    );

    assert(result == 0);
}


static void
test_gpio_read(void)
{
    om_gpio_level_t level = OM_GPIO_LOW;

    const int result = om_gpio_read(
        1U,
        &level
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
