/**
 * @file button_driver.h
 * @brief OrbitMesh button driver.
 *
 * Hardware-independent interface for push-button peripherals.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_DRIVERS_BUTTON_DRIVER_H
#define ORBITMESH_DRIVERS_BUTTON_DRIVER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "orbitmesh/error.h"
#include "orbitmesh/types.h"

#include <stdbool.h>

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize a button GPIO.
 *
 * @param pin GPIO pin connected to the button.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_button_init(
    om_pin_t pin);

/**
 * @brief Read the current button state.
 *
 * @param pin GPIO pin connected to the button.
 * @param pressed Storage for the button state.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_button_read(
    om_pin_t pin,
    bool *pressed);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_DRIVERS_BUTTON_DRIVER_H */
