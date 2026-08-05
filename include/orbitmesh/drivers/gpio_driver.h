/**
 * @file gpio_driver.h
 * @brief OrbitMesh GPIO driver interface.
 *
 * Provides GPIO driver functions built on top
 * of the OrbitMesh HAL layer.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_DRIVERS_GPIO_DRIVER_H
#define ORBITMESH_DRIVERS_GPIO_DRIVER_H

#include "orbitmesh/error.h"
#include "orbitmesh/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

om_error_t
om_gpio_driver_init(void);

om_error_t
om_gpio_driver_configure(
    om_pin_t pin,
    om_gpio_mode_t mode
);

om_error_t
om_gpio_driver_write(
    om_pin_t pin,
    om_gpio_level_t level
);

om_error_t
om_gpio_driver_read(
    om_pin_t pin,
    om_gpio_level_t *level
);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_DRIVERS_GPIO_DRIVER_H */
