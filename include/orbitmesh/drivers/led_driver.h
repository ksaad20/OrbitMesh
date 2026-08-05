#ifndef ORBITMESH_DRIVERS_LED_DRIVER_H
#define ORBITMESH_DRIVERS_LED_DRIVER_H

#include <stdbool.h>

#include "orbitmesh/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize the LED driver.
 *
 * @param pin GPIO pin connected to the LED.
 *
 * @return OM_OK on success, otherwise an error code.
 */
om_error_t
om_led_init(
    om_pin_t pin
);

/**
 * @brief Turn the LED on.
 *
 * @return OM_OK on success, otherwise an error code.
 */
om_error_t
om_led_on(void);

/**
 * @brief Turn the LED off.
 *
 * @return OM_OK on success, otherwise an error code.
 */
om_error_t
om_led_off(void);

/**
 * @brief Toggle the LED state.
 *
 * @return OM_OK on success, otherwise an error code.
 */
om_error_t
om_led_toggle(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_DRIVERS_LED_DRIVER_H */
