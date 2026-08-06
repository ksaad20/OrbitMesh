/**
 * @file gpio.c
 * @brief OrbitMesh GPIO HAL implementation.
 *
 * Implements the hardware-independent GPIO layer.
 *
 * MVP implementation:
 * - Static pin configuration storage.
 * - No dynamic memory.
 * - Deterministic behavior.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/gpio.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/*==============================================================================
 * Configuration
 *============================================================================*/

/**
 * @brief Maximum supported GPIO pins in MVP simulation.
 *
 * Platform ports may override this value.
 */
#ifndef OM_GPIO_MAX_PINS
#define OM_GPIO_MAX_PINS 128U
#endif

/*==============================================================================
 * Private Data
 *============================================================================*/

/**
 * @brief GPIO pin state.
 */
typedef struct
{
    bool configured;
    om_gpio_mode_t mode;
    om_gpio_pull_t pull;
    om_gpio_level_t level;

} om_gpio_pin_state_t;


/**
 * @brief GPIO state table.
 */
static om_gpio_pin_state_t g_gpio_pins[OM_GPIO_MAX_PINS];


/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_gpio_init(void)
{
    memset(
        g_gpio_pins,
        0,
        sizeof(g_gpio_pins));

    return OM_SUCCESS;
}


om_error_t
om_gpio_configure(
    const om_gpio_config_t *config)
{
    if (config == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }

    if (config->pin >= OM_GPIO_MAX_PINS)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    g_gpio_pins[config->pin].configured = true;
    g_gpio_pins[config->pin].mode = config->mode;
    g_gpio_pins[config->pin].pull = config->pull;
    g_gpio_pins[config->pin].level = OM_GPIO_LOW;

    return OM_SUCCESS;
}


static void
test_gpio_write(void)
{
    const om_gpio_config_t config =
    {
        .pin = 1U,
        .mode = OM_GPIO_OUTPUT,
        .pull = OM_GPIO_NO_PULL,
    };

    int result = om_gpio_configure(&config);
    assert(result == OM_SUCCESS);

    result = om_gpio_write(
        1U,
        OM_GPIO_HIGH
    );

    assert(result == OM_SUCCESS);
}


static void
test_gpio_read(void)
{
    const om_gpio_config_t config =
    {
        .pin = 1U,
        .mode = OM_GPIO_OUTPUT,
        .pull = OM_GPIO_NO_PULL,
    };

    int result = om_gpio_configure(&config);
    assert(result == OM_SUCCESS);

    result = om_gpio_write(
        1U,
        OM_GPIO_HIGH
    );
    assert(result == OM_SUCCESS);

    om_gpio_level_t level = OM_GPIO_LOW;

    result = om_gpio_read(
        1U,
        &level
    );
    assert(result == OM_SUCCESS);

    assert(level == OM_GPIO_HIGH);
}


om_error_t
om_gpio_toggle(
    om_pin_t pin)
{
    if (pin >= OM_GPIO_MAX_PINS)
    {
        return OM_ERROR_INVALID_ARGUMENT;
    }

    if (!g_gpio_pins[pin].configured)
    {
        return OM_ERROR_INVALID_STATE;
    }

    if (g_gpio_pins[pin].mode != OM_GPIO_OUTPUT)
    {
        return OM_ERROR_INVALID_STATE;
    }

    if (g_gpio_pins[pin].level == OM_GPIO_LOW)
    {
        g_gpio_pins[pin].level = OM_GPIO_HIGH;
    }
    else
    {
        g_gpio_pins[pin].level = OM_GPIO_LOW;
    }

    return OM_SUCCESS;
}
