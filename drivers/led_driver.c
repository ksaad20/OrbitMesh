#include "orbitmesh/drivers/led_driver.h"

#include "orbitmesh/gpio.h"

static om_pin_t led_pin;

om_error_t
om_led_init(om_pin_t pin)
{
    led_pin = pin;

    const om_gpio_config_t config = {
        .mode = OM_GPIO_OUTPUT,
        .pull = OM_GPIO_NO_PULL,
    };

    return om_gpio_configure(
        led_pin,
        &config
    );
}

om_error_t
om_led_on(void)
{
    return om_gpio_write(
        led_pin,
        true
    );
}

om_error_t
om_led_off(void)
{
    return om_gpio_write(
        led_pin,
        false
    );
}

om_error_t
om_led_toggle(void)
{
    static bool state = false;

    state = !state;

    return om_gpio_write(
        led_pin,
        state
    );
}
