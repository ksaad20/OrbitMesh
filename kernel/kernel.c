/**
 * @file kernel.c
 * @brief OrbitMesh kernel core implementation.
 *
 * Owns the global kernel context and implements the kernel lifecycle.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "kernel_internal.h"

/*==============================================================================
 * Kernel Context
 *============================================================================*/

/**
 * @brief Global kernel context.
 */
typedef struct
{
    om_kernel_state_t state;
    om_tick_t uptime;
    bool scheduler_running;
} om_kernel_context_t;

/**
 * @brief Singleton kernel context.
 */
static om_kernel_context_t g_kernel =
{
    .state = OM_KERNEL_STATE_UNINITIALIZED,
    .uptime = 0U,
    .scheduler_running = false
};

/*==============================================================================
 * Internal API
 *============================================================================*/

void
om_kernel_initialize_state(void)
{
    g_kernel.state = OM_KERNEL_STATE_UNINITIALIZED;
    g_kernel.uptime = 0U;
    g_kernel.scheduler_running = false;
}

void
om_kernel_reset_state(void)
{
    om_kernel_initialize_state();
}

/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_kernel_start(void)
{
    if (g_kernel.state != OM_KERNEL_STATE_INITIALIZED)
    {
        return OM_ERROR_INVALID_STATE;
    }

    g_kernel.scheduler_running = true;
    g_kernel.state = OM_KERNEL_STATE_RUNNING;

    return OM_SUCCESS;
}

om_error_t
om_kernel_stop(void)
{
    if (!g_kernel.scheduler_running)
    {
        return OM_ERROR_INVALID_STATE;
    }

    g_kernel.scheduler_running = false;
    g_kernel.state = OM_KERNEL_STATE_INITIALIZED;

    return OM_SUCCESS;
}

bool
om_kernel_is_running(void)
{
    return g_kernel.scheduler_running;
}

om_kernel_state_t
om_kernel_state(void)
{
    return g_kernel.state;
}

om_tick_t
om_kernel_uptime(void)
{
    return g_kernel.uptime;
}
