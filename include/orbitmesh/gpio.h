/**
 * @file gpio.h
 * @brief OrbitMesh GPIO Hardware Abstraction Layer.
 *
 * Provides a hardware-independent interface for configuring and controlling
 * General Purpose Input/Output (GPIO) peripherals across supported platforms.
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
 * @brief GPIO pin direction.
 */
typedef enum
{
    OM_GPIO_INPUT = 0,
    OM_GPIO_OUTPUT
} om_gpio_mode_t;

/**
 * @brief GPIO pull resistor configuration.
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
    /**
     * @brief GPIO pin identifier.
     */
    om_pin_t pin;

    /**
     * @brief GPIO operating mode.
     */
    om_gpio_mode_t mode;

    /**
     * @brief Internal pull resistor configuration.
     */
    om_gpio_pull_t pull;

} om_gpio_config_t;

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the GPIO subsystem.
 *
 * @return OM_SUCCESS on success; otherwise an appropriate error code.
 */
om_error_t
om_gpio_init(void);

/**
 * @brief Configure a GPIO pin.
 *
 * @param[in] config Pointer to the GPIO configuration structure.
 *
 * @return OM_SUCCESS on success; otherwise an appropriate error code.
 */
om_error_t
om_gpio_configure(
    const om_gpio_config_t *config);

/**
 * @brief Write a logic level to a GPIO output pin.
 *
 * @param[in] pin GPIO pin identifier.
 * @param[in] level Logic level to drive.
 *
 * @return OM_SUCCESS on success; otherwise an appropriate error code.
 */
om_error_t
om_gpio_write(
    om_pin_t pin,
    om_gpio_level_t level);

/**
 * @brief Read the logic level of a GPIO pin.
 *
 * @param[in] pin GPIO pin identifier.
 * @param[out] level Pointer that receives the current logic level.
 *
 * @return OM_SUCCESS on success; otherwise an appropriate error code.
 */
om_error_t
om_gpio_read(
    om_pin_t pin,
    om_gpio_level_t *level);

/**
 * @brief Toggle the logic level of a GPIO output pin.
 *
 * @param[in] pin GPIO pin identifier.
 *
 * @return OM_SUCCESS on success; otherwise an appropriate error code.
 */
om_error_t
om_gpio_toggle(
    om_pin_t pin);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_GPIO_H */
