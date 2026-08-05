/**
 * @file kernel.h
 * @brief OrbitMesh kernel public API.
 *
 * Provides the primary interface for initializing, starting, and querying the
 * OrbitMesh kernel.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_KERNEL_H
#define ORBITMESH_KERNEL_H

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
 * Kernel State
 *============================================================================*/

/**
 * @brief Kernel execution state.
 */
typedef enum
{
    OM_KERNEL_STATE_UNINITIALIZED = 0,
    OM_KERNEL_STATE_INITIALIZED,
    OM_KERNEL_STATE_RUNNING,
    OM_KERNEL_STATE_PANIC
} om_kernel_state_t;

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the kernel.
 *
 * This function prepares all kernel subsystems but does not start task
 * scheduling.
 *
 * @return
 *  - OM_SUCCESS on success.
 *  - Appropriate error code on failure.
 */
om_error_t
om_kernel_init(void);

/**
 * @brief Start the scheduler.
 *
 * This function does not normally return.
 *
 * @return Error code if startup fails.
 */
om_error_t
om_kernel_start(void);

/**
 * @brief Stop the kernel.
 *
 * Intended primarily for simulation and testing.
 *
 * @return Error code.
 */
om_error_t
om_kernel_stop(void);

/**
 * @brief Determine whether the kernel has been initialized.
 *
 * @return true if initialized.
 */
bool
om_kernel_is_initialized(void);

/**
 * @brief Determine whether the scheduler is running.
 *
 * @return true if running.
 */
bool
om_kernel_is_running(void);

/**
 * @brief Retrieve the current kernel state.
 *
 * @return Current kernel state.
 */
om_kernel_state_t
om_kernel_state(void);

/**
 * @brief Obtain the system uptime in scheduler ticks.
 *
 * @return Current uptime.
 */
om_tick_t
om_kernel_uptime(void);

/**
 * @brief Enter the kernel panic state.
 *
 * This function never returns.
 *
 * @param reason Human-readable panic reason.
 */
OM_NORETURN
void
om_kernel_panic(
    const char *reason);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_KERNEL_H */
