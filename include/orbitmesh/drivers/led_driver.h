/**
 * @file led_driver.h
 * @brief OrbitMesh LED driver interface.
 *
 * Provides a simple hardware-independent interface for controlling
 * a single status LED.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_DRIVERS_LED_DRIVER_H
#define ORBITMESH_DRIVERS_LED_DRIVER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "orbitmesh/error.h"
#include "orbitmesh/types.h"

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the LED driver.
 *
 * Configures the specified GPIO pin as an output.
 *
 * @param pin GPIO pin connected to the LED.
 *
 * @return OM_SUCCESS on success; otherwise an appropriate error code.
 */
om_error_t
om_led_init(
    om_pin_t pin);

/**
 * @brief Turn the LED on.
 *
 * @return OM_SUCCESS on success; otherwise an appropriate error code.
 */
om_error_t
om_led_on(void);

/**
 * @brief Turn the LED off.
 *
 * @return OM_SUCCESS on success; otherwise an appropriate error code.
 */
om_error_t
om_led_off(void);

/**
 * @brief Toggle the LED state.
 *
 * @return OM_SUCCESS on success; otherwise an appropriate error code.
 */
om_error_t
om_led_toggle(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_DRIVERS_LED_DRIVER_H */
