#include "orbitmesh/drivers/button_driver.h"

#include <stdbool.h>

#include "orbitmesh/gpio.h"

om_error_t
om_button_init(
    om_pin_t pin
)
{
    const om_gpio_config_t config = {
        .mode = OM_GPIO_INPUT,
        .pull = OM_GPIO_PULL_UP,
    };

    (void)pin;

    return om_gpio_configure(
        &config
    );
}

om_error_t
om_button_read(
    om_pin_t pin,
    bool *pressed
)
{
    return om_gpio_read(
        pin,
        pressed
    );
}
