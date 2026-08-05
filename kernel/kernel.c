/**
 * @file kernel.c
 * @brief OrbitMesh kernel implementation.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "kernel_internal.h"

#include "scheduler.h"

#include <stddef.h>

/*==============================================================================
 * Global Kernel State
 *============================================================================*/

om_kernel_state_t g_kernel_state =
    OM_KERNEL_STATE_UNINITIALIZED;

om_tick_t g_kernel_ticks = 0U;

bool g_scheduler_running = false;

/*==============================================================================
 * Internal Functions
 *============================================================================*/

void
om_kernel_initialize_state(void)
{
    g_kernel_state = OM_KERNEL_STATE_UNINITIALIZED;
    g_kernel_ticks = 0U;
    g_scheduler_running = false;
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
om_kernel_init(void)
{
    om_kernel_initialize_state();

    g_kernel_state = OM_KERNEL_STATE_INITIALIZED;

    return OM_SUCCESS;
}

om_error_t
om_kernel_start(void)
{
    if (g_kernel_state != OM_KERNEL_STATE_INITIALIZED)
    {
        return OM_ERROR_INVALID_STATE;
    }

    g_scheduler_running = true;
    g_kernel_state = OM_KERNEL_STATE_RUNNING;

    while (g_scheduler_running)
    {
        om_scheduler_run_once();
    }

    return OM_SUCCESS;
}

om_error_t
om_kernel_stop(void)
{
    if (!g_scheduler_running)
    {
        return OM_ERROR_INVALID_STATE;
    }

    g_scheduler_running = false;
    g_kernel_state = OM_KERNEL_STATE_INITIALIZED;

    return OM_SUCCESS;
}

bool
om_kernel_is_initialized(void)
{
    return g_kernel_state != OM_KERNEL_STATE_UNINITIALIZED;
}

bool
om_kernel_is_running(void)
{
    return g_scheduler_running;
}

om_kernel_state_t
om_kernel_state(void)
{
    return g_kernel_state;
}

om_tick_t
om_kernel_uptime(void)
{
    return g_kernel_ticks;
}

OM_NORETURN
void
om_kernel_halt(void)
{
    for (;;)
    {
    }
}

OM_NORETURN
void
om_kernel_panic(
    const char *reason)
{
    (void)reason;

    g_kernel_state = OM_KERNEL_STATE_PANIC;

    om_kernel_halt();
}
