/**
 * @file hal.h
 * @brief OrbitMesh Hardware Abstraction Layer (HAL).
 *
 * Provides the common interface for hardware abstraction used by all
 * platform-specific drivers.
 *
 * The HAL isolates the kernel and drivers from processor- and
 * board-specific implementations.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_HAL_H
#define ORBITMESH_HAL_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "compiler.h"
#include "error.h"
#include "types.h"

#include <stdbool.h>
#include <stdint.h>

/*==============================================================================
 * HAL Status
 *============================================================================*/

/**
 * @brief HAL initialization state.
 */
typedef enum
{
    OM_HAL_UNINITIALIZED = 0,
    OM_HAL_INITIALIZED
} om_hal_state_t;

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the hardware abstraction layer.
 *
 * This function initializes all platform-specific hardware required by the
 * OrbitMesh kernel before drivers are started.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_hal_init(void);

/**
 * @brief Shut down the hardware abstraction layer.
 *
 * Intended primarily for host simulation and unit testing.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_hal_deinit(void);

/**
 * @brief Determine whether the HAL is initialized.
 *
 * @return true if initialized.
 */
bool
om_hal_is_initialized(void);

/**
 * @brief Get the current HAL state.
 *
 * @return Current HAL state.
 */
om_hal_state_t
om_hal_state(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_HAL_H */
