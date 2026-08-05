/**
 * @file button_driver.c
 * @brief OrbitMesh button driver.
 *
 * Provides a simple button input interface built
 * on top of the GPIO layer.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/gpio.h"
#include "orbitmesh/error.h"
#include "orbitmesh/types.h"


/*==============================================================================
 * Private State
 *============================================================================*/

static om_pin_t g_button_pin;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize button driver.
 *
 * @param pin GPIO pin connected to button.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_button_init(
    om_pin_t pin)
{
    g_button_pin = pin;


    return om_gpio_configure(
        pin,
        OM_GPIO_INPUT,
        OM_GPIO_PULL_UP
    );
}


/**
 * @brief Read button state.
 *
 * @return true when button is pressed.
 */
om_bool_t
om_button_pressed(void)
{
    return (
        om_gpio_read(
            g_button_pin
        )
        == OM_GPIO_LOW
    );
}
