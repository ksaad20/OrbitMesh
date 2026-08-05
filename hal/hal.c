/**
 * @file hal.c
 * @brief OrbitMesh Hardware Abstraction Layer implementation.
 *
 * Implements initialization and lifecycle management for the OrbitMesh
 * Hardware Abstraction Layer.
 *
 * The HAL provides a hardware-independent interface between the kernel,
 * drivers, and platform-specific implementations.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/hal.h"

/*==============================================================================
 * Private State
 *============================================================================*/

/**
 * @brief Current HAL state.
 */
static om_hal_state_t g_hal_state = OM_HAL_UNINITIALIZED;

/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_hal_init(void)
{
    if (g_hal_state == OM_HAL_INITIALIZED)
    {
        return OM_ERROR_INVALID_STATE;
    }

    /*
     * Platform-specific peripheral initialization will be added
     * as platform ports are implemented.
     */

    g_hal_state = OM_HAL_INITIALIZED;

    return OM_SUCCESS;
}

om_error_t
om_hal_deinit(void)
{
    if (g_hal_state != OM_HAL_INITIALIZED)
    {
        return OM_ERROR_INVALID_STATE;
    }

    /*
     * Platform-specific peripheral shutdown will be implemented
     * by each supported architecture.
     */

    g_hal_state = OM_HAL_UNINITIALIZED;

    return OM_SUCCESS;
}

bool
om_hal_is_initialized(void)
{
    return (g_hal_state == OM_HAL_INITIALIZED);
}

om_hal_state_t
om_hal_state(void)
{
    return g_hal_state;
}
