/**
 * @file gpio.c
 * @brief OrbitMesh Linux GPIO simulation.
 *
 * Provides a host implementation of GPIO operations
 * for development and testing.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/error.h"
#include "orbitmesh/types.h"

#include <stdio.h>


/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_gpio_init(
    om_pin_t pin)
{
    printf(
        "GPIO initialized: %lu\n",
        (unsigned long)pin
    );


    return OM_SUCCESS;
}


om_error_t
om_gpio_write(
    om_pin_t pin,
    om_gpio_level_t level)
{
    printf(
        "GPIO %lu = %s\n",
        (unsigned long)pin,
        level == OM_GPIO_HIGH
            ? "HIGH"
            : "LOW"
    );


    return OM_SUCCESS;
}


om_gpio_level_t
om_gpio_read(
    om_pin_t pin)
{
    (void)pin;


    /*
     * Default simulated input state.
     */
    return OM_GPIO_LOW;
}
