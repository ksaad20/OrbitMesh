/**
 * @file led_driver.c
 * @brief OrbitMesh LED driver.
 *
 * Provides a simple LED control interface built
 * on top of the GPIO driver layer.
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

static om_pin_t g_led_pin;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize LED driver.
 *
 * @param pin GPIO pin connected to LED.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_led_init(
    om_pin_t pin)
{
    g_led_pin = pin;


    return om_gpio_configure(
        pin,
        OM_GPIO_OUTPUT,
        OM_GPIO_NO_PULL
    );
}


/**
 * @brief Turn LED on.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_led_on(void)
{
    return om_gpio_write(
        g_led_pin,
        OM_GPIO_HIGH
    );
}


/**
 * @brief Turn LED off.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_led_off(void)
{
    return om_gpio_write(
        g_led_pin,
        OM_GPIO_LOW
    );
}


/**
 * @brief Toggle LED state.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_led_toggle(void)
{
    static om_bool_t state = false;


    state = !state;


    return om_gpio_write(
        g_led_pin,
        state
            ? OM_GPIO_HIGH
            : OM_GPIO_LOW
    );
}
