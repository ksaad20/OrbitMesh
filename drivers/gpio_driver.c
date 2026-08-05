/**
 * @file gpio_driver.c
 * @brief OrbitMesh GPIO driver.
 *
 * Provides a generic GPIO interface built on top
 * of the OrbitMesh HAL layer.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/drivers/gpio_driver.h"

#include "orbitmesh/error.h"
#include "orbitmesh/gpio.h"


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize GPIO driver.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_gpio_driver_init(void)
{
    return OM_SUCCESS;;
}


/**
 * @brief Configure GPIO pin.
 *
 * @param pin GPIO pin identifier.
 * @param mode GPIO operating mode.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_gpio_driver_configure(
    om_pin_t pin,
    om_gpio_mode_t mode)
{
    om_gpio_config_t config = {
        .pin = pin,
        .mode = mode,
        .pull = OM_GPIO_PULL_NONE
    };

    return om_gpio_configure(
        &config
    );
}


/**
 * @brief Write GPIO output level.
 *
 * @param pin GPIO pin identifier.
 * @param level GPIO output level.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_gpio_driver_write(
    om_pin_t pin,
    om_gpio_level_t level)
{
    return om_gpio_write(
        pin,
        level
    );
}


/**
 * @brief Read GPIO input level.
 *
 * @param pin GPIO pin identifier.
 * @param level Pointer to store GPIO level.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_gpio_driver_read(
    om_pin_t pin,
    om_gpio_level_t *level)
{
    if (level == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    return om_gpio_read(
        pin,
        level
    );
}
