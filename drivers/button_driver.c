/**
 * @file button_driver.c
 * @brief OrbitMesh button driver.
 */

#include "orbitmesh/drivers/button_driver.h"

#include "orbitmesh/gpio.h"

om_error_t
om_button_init(
    om_pin_t pin)
{
    const om_gpio_config_t config = {
        .pin = pin,
        .mode = OM_GPIO_INPUT,
        .pull = OM_GPIO_PULL_UP,
    };

    return om_gpio_configure(
        &config);
}

om_error_t
om_button_read(
    om_pin_t pin,
    bool *pressed)
{
    if (pressed == NULL)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    om_gpio_level_t level;

    om_error_t status = om_gpio_read(
        pin,
        &level);

    if (status != OM_SUCCESS)
    {
        return status;
    }

    *pressed = (level == OM_GPIO_HIGH);

    return OM_SUCCESS;
}
