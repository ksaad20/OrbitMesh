/**
 * @file led_driver.c
 * @brief OrbitMesh LED driver implementation.
 */

#include <stdbool.h>

#include "orbitmesh/gpio.h"
#include "orbitmesh/error.h"


#define OM_LED_PIN 0U


static bool led_state = false;


/**
 * @brief Initialize LED driver.
 *
 * Configures the LED GPIO pin as an output.
 *
 * @return Operation status.
 */
om_error_t
om_led_init(void)
{
    om_gpio_config_t config = {
        .mode = OM_GPIO_OUTPUT,
    };

    return om_gpio_configure(
        OM_LED_PIN,
        &config
    );
}


/**
 * @brief Turn LED on.
 *
 * @return Operation status.
 */
om_error_t
om_led_on(void)
{
    led_state = true;

    return om_gpio_write(
        OM_LED_PIN,
        true
    );
}


/**
 * @brief Turn LED off.
 *
 * @return Operation status.
 */
om_error_t
om_led_off(void)
{
    led_state = false;

    return om_gpio_write(
        OM_LED_PIN,
        false
    );
}


/**
 * @brief Toggle LED state.
 *
 * @return Operation status.
 */
om_error_t
om_led_toggle(void)
{
    led_state = !led_state;

    return om_gpio_write(
        OM_LED_PIN,
        led_state
    );
}
