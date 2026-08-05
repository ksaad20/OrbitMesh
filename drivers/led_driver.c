/**
 * @file led_driver.c
 * @brief OrbitMesh LED driver.
 */

#include "orbitmesh/drivers/led_driver.h"

#include "orbitmesh/gpio.h"

static om_pin_t g_led_pin = 0U;

om_error_t
om_led_init(
    om_pin_t pin)
{
    g_led_pin = pin;

    const om_gpio_config_t config = {
        .pin = pin,
        .mode = OM_GPIO_OUTPUT,
        .pull = OM_GPIO_PULL_NONE,
    };

    return om_gpio_configure(
        &config);
}

om_error_t
om_led_on(void)
{
    return om_gpio_write(
        g_led_pin,
        OM_GPIO_HIGH);
}

om_error_t
om_led_off(void)
{
    return om_gpio_write(
        g_led_pin,
        OM_GPIO_LOW);
}

om_error_t
om_led_toggle(void)
{
    return om_gpio_toggle(
        g_led_pin);
}
