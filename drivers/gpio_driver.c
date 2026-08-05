/**
 * @file gpio_driver.c
 * @brief OrbitMesh GPIO driver.
 *
 * Provides a generic GPIO driver interface built
 * on top of the hardware abstraction layer.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/gpio.h"
#include "orbitmesh/error.h"
#include "orbitmesh/types.h"


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
    return OM_SUCCESS;
}


/**
 * @brief Configure a GPIO pin.
 *
 * @param pin GPIO identifier.
 * @param mode Pin direction.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_gpio_driver_configure(
    om_pin_t pin,
    om_gpio_mode_t mode)
{
    return om_gpio_configure(
        pin,
        mode,
        OM_GPIO_NO_PULL
    );
}


/**
 * @brief Write GPIO output level.
 *
 * @param pin GPIO identifier.
 * @param level Output level.
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
 * @param pin GPIO identifier.
 *
 * @return GPIO level.
 */
om_gpio_level_t
om_gpio_driver_read(
    om_pin_t pin)
{
    return om_gpio_read(
        pin
    );
}
