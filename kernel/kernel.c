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
/**
 * @file kernel.c
 * @brief OrbitMesh kernel core implementation.
 *
 * Implements the kernel lifecycle and owns the global kernel state.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "kernel_internal.h"

#include "scheduler.h"
#include "task_control_block.h"

#include <stdbool.h>

/*==============================================================================
 * Private Kernel Context
 *============================================================================*/

/**
 * @brief Kernel context.
 *
 * This structure owns all global kernel state.
 */
typedef struct
{
    om_kernel_state_t state;
    om_tick_t uptime_ticks;
    bool running;
} om_kernel_context_t;

/**
 * @brief Global kernel context.
 */
static om_kernel_context_t g_kernel =
{
    .state = OM_KERNEL_STATE_UNINITIALIZED,
    .uptime_ticks = 0U,
    .running = false
};

/*==============================================================================
 * Internal Functions
 *============================================================================*/

void
om_kernel_initialize_state(void)
{
    g_kernel.state = OM_KERNEL_STATE_UNINITIALIZED;
    g_kernel.uptime_ticks = 0U;
    g_kernel.running = false;
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

    om_error_t result = om_scheduler_start();

    if (result != OM_SUCCESS)
    {
        return result;
    }

    g_kernel.running = true;
    g_kernel.state = OM_KERNEL_STATE_RUNNING;

    /*
     * Cooperative scheduler loop.
     *
     * Returns only after om_kernel_stop() is called.
     */
    while (g_kernel.running)
    {
        om_scheduler_run();
    }

    return OM_SUCCESS;
}

om_error_t
om_kernel_stop(void)
{
    if (!g_kernel.running)
    {
        return OM_ERROR_INVALID_STATE;
    }

    (void)om_scheduler_stop();

    g_kernel.running = false;
    g_kernel.state = OM_KERNEL_STATE_INITIALIZED;

    return OM_SUCCESS;
}

bool
om_kernel_is_initialized(void)
{
    return g_kernel.state != OM_KERNEL_STATE_UNINITIALIZED;
}

bool
om_kernel_is_running(void)
{
    return g_kernel.running;
}

om_kernel_state_t
om_kernel_state(void)
{
    return g_kernel.state;
}

om_tick_t
om_kernel_uptime(void)
{
    return g_kernel.uptime_ticks;
}
/**
 * @file tick.c
 * @brief OrbitMesh system tick implementation.
 *
 * Implements the kernel system tick.
 *
 * Responsibilities:
 *  - Advance kernel uptime
 *  - Update delayed tasks
 *  - Drive software timers
 *  - Notify the scheduler
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "kernel_internal.h"

#include "scheduler.h"

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Process one system tick.
 *
 * This function is intended to be called by the platform timer interrupt
 * handler at a fixed frequency (for example, 1000 Hz).
 */
void
om_kernel_tick(void)
{
    /*
     * Advance the kernel clock.
     */
    ++g_kernel.uptime_ticks;

    /*
     * Update scheduler timing.
     */
    om_scheduler_tick();

    /*
     * Software timers will be processed here in a future implementation.
     */
}
