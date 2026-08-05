#include "orbitmesh/drivers/led_driver.h"

#include <stdbool.h>

#include "orbitmesh/gpio.h"

static om_pin_t g_led_pin;

om_error_t
om_led_init(
    om_pin_t pin
)
{
    g_led_pin = pin;

    const om_gpio_config_t config = {
        .mode = OM_GPIO_OUTPUT,
        .pull = OM_GPIO_NO_PULL,
    };

    return om_gpio_configure(
        &config
    );
}

om_error_t
om_led_on(void)
{
    return om_gpio_write(
        g_led_pin,
        true
    );
}

om_error_t
om_led_off(void)
{
    return om_gpio_write(
        g_led_pin,
        false
    );
}

om_error_t
om_led_toggle(void)
{
    bool state = false;

    if (om_gpio_read(
            g_led_pin,
            &state
        ) != OM_OK)
    {
        return OM_ERROR;
    }

    return om_gpio_write(
        g_led_pin,
        !state
    );
}
