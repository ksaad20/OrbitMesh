/**
 * @file button_driver.c
 * @brief OrbitMesh button driver implementation.
 */

#include "orbitmesh/drivers/button_driver.h"

#include "orbitmesh/error.h"
#include "orbitmesh/gpio.h"


om_error_t
om_button_init(
    om_pin_t pin)
{
    return om_gpio_configure(
        pin,
        OM_GPIO_INPUT
    );
}


om_error_t
om_button_read(
    om_pin_t pin,
    bool *pressed)
{
    if (pressed == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    return om_gpio_read(
        pin,
        pressed
    );
}
