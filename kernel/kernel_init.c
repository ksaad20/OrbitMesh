/**
 * @file kernel_init.c
 * @brief Kernel initialization.
 *
 * Implements initialization of the OrbitMesh kernel.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/assert.h"
#include "orbitmesh/error.h"
#include "orbitmesh/kernel.h"

/*==============================================================================
 * Private State
 *============================================================================*/

/**
 * @brief Current kernel state.
 */
static om_kernel_state_t kernel_state = OM_KERNEL_STATE_UNINITIALIZED;

/**
 * @brief System uptime in scheduler ticks.
 */
static om_tick_t kernel_uptime = 0U;

/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_kernel_init(void)
{
    if (kernel_state != OM_KERNEL_STATE_UNINITIALIZED)
    {
        return OM_ERROR_INVALID_STATE;
    }

    kernel_uptime = 0U;
    kernel_state = OM_KERNEL_STATE_INITIALIZED;

    return OM_SUCCESS;
}

bool
om_kernel_is_initialized(void)
{
    return (kernel_state != OM_KERNEL_STATE_UNINITIALIZED);
}

bool
om_kernel_is_running(void)
{
    return (kernel_state == OM_KERNEL_STATE_RUNNING);
}

om_kernel_state_t
om_kernel_state(void)
{
    return kernel_state;
}

om_tick_t
om_kernel_uptime(void)
{
    return kernel_uptime;
}
