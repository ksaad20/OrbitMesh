/**
 * @file kernel_internal.h
 * @brief Internal kernel definitions.
 *
 * This header contains private definitions shared between OrbitMesh kernel
 * source files. It is NOT part of the public API and must never be included
 * outside of the kernel implementation.
 *
 * Public code should include:
 *
 *     <orbitmesh/kernel.h>
 *
 * instead of this header.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_KERNEL_INTERNAL_H
#define ORBITMESH_KERNEL_INTERNAL_H

#include "orbitmesh/compiler.h"
#include "orbitmesh/config.h"
#include "orbitmesh/error.h"
#include "orbitmesh/kernel.h"
#include "orbitmesh/macros.h"
#include "orbitmesh/types.h"

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Kernel Global State
 *============================================================================*/

/**
 * @brief Current kernel state.
 */
extern om_kernel_state_t g_kernel_state;

/**
 * @brief Scheduler tick count.
 */
extern om_tick_t g_kernel_ticks;

/**
 * @brief Indicates whether the scheduler is running.
 */
extern bool g_scheduler_running;

/*==============================================================================
 * Internal Initialization
 *============================================================================*/

/**
 * @brief Initialize internal kernel state.
 *
 * Called only from om_kernel_init().
 */
void
om_kernel_initialize_state(void);

/**
 * @brief Reset the kernel state.
 */
void
om_kernel_reset_state(void);

/*==============================================================================
 * Scheduler Helpers
 *============================================================================*/

/**
 * @brief Advance the scheduler by one system tick.
 */
void
om_scheduler_tick(void);

/**
 * @brief Execute one scheduler iteration.
 */
void
om_scheduler_run_once(void);

/*==============================================================================
 * Panic Helpers
 *============================================================================*/

/**
 * @brief Enter an unrecoverable kernel halt.
 *
 * Never returns.
 */
OM_NORETURN
void
om_kernel_halt(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_KERNEL_INTERNAL_H */
