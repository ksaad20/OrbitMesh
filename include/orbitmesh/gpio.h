/**
 * @file gpio.h
 * @brief OrbitMesh GPIO Hardware Abstraction Layer.
 *
 * Provides a hardware-independent GPIO interface.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_GPIO_H
#define ORBITMESH_GPIO_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "error.h"
#include "types.h"

#include <stdbool.h>
#include <stdint.h>

/*==============================================================================
 * GPIO Types
 *============================================================================*/

/**
 * @brief GPIO pin mode.
 */
typedef enum
{
    OM_GPIO_INPUT = 0,
    OM_GPIO_OUTPUT
} om_gpio_mode_t;


/**
 * @brief GPIO pull configuration.
 */
typedef enum
{
    OM_GPIO_PULL_NONE = 0,
    OM_GPIO_PULL_UP,
    OM_GPIO_PULL_DOWN
} om_gpio_pull_t;


/**
 * @brief GPIO logic level.
 */
typedef enum
{
    OM_GPIO_LOW = 0,
    OM_GPIO_HIGH
} om_gpio_level_t;


/**
 * @brief GPIO pin configuration.
 */
typedef struct
{
    om_pin_t pin;
    om_gpio_mode_t mode;
    om_gpio_pull_t pull;

} om_gpio_config_t;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize GPIO subsystem.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_gpio_init(void);


/**
 * @brief Configure a GPIO pin.
 *
 * @param config GPIO configuration.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_gpio_configure(
    const om_gpio_config_t *config);


/**
 * @brief Write a GPIO output level.
 *
 * @param pin GPIO pin.
 * @param level Output level.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_gpio_write(
    om_pin_t pin,
    om_gpio_level_t level);


/**
 * @brief Read a GPIO input level.
 *
 * @param pin GPIO pin.
 * @param level Output storage.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_gpio_read(
    om_pin_t pin,
    om_gpio_level_t *level);


/**
 * @brief Toggle a GPIO output.
 *
 * @param pin GPIO pin.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_gpio_toggle(
    om_pin_t pin);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_GPIO_H */
