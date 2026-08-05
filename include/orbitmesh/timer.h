/**
 * @file timer.h
 * @brief OrbitMesh software timer API.
 *
 * Provides deterministic software timers for the OrbitMesh MVP.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ORBITMESH_TIMER_H
#define ORBITMESH_TIMER_H

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
 * Types
 *============================================================================*/

/**
 * @brief Timer callback function.
 *
 * @param argument User-supplied argument.
 */
typedef void (*om_timer_callback_t)(
    void *argument
);

/**
 * @brief Software timer object.
 *
 * The handle type is declared in types.h:
 *
 *     typedef struct om_timer om_timer_t;
 *
 * This is the single definition of the timer structure.
 */
struct om_timer
{
    bool allocated;

    bool running;

    bool periodic;

    om_tick_t period_ticks;

    om_tick_t remaining_ticks;

    om_timer_callback_t callback;

    void *argument;
};

/*==============================================================================
 * Timer API
 *============================================================================*/

/**
 * @brief Initialize the timer subsystem.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_timer_init(void);

/**
 * @brief Create a software timer.
 *
 * @param timer Timer object.
 * @param period_ticks Timer period in ticks.
 * @param periodic True for a periodic timer.
 * @param callback Callback function.
 * @param argument Callback argument.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_timer_create(
    om_timer_t *timer,
    om_tick_t period_ticks,
    bool periodic,
    om_timer_callback_t callback,
    void *argument
);

/**
 * @brief Start a timer.
 *
 * @param timer Timer object.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_timer_start(
    om_timer_t *timer
);

/**
 * @brief Stop a timer.
 *
 * @param timer Timer object.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_timer_stop(
    om_timer_t *timer
);

/**
 * @brief Reset a timer.
 *
 * @param timer Timer object.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_timer_reset(
    om_timer_t *timer
);

/**
 * @brief Determine whether a timer is running.
 *
 * @param timer Timer object.
 *
 * @retval true Timer is running.
 * @retval false Timer is stopped.
 */
bool
om_timer_is_running(
    const om_timer_t *timer
);

/**
 * @brief Process timer updates.
 *
 * Called once every system tick.
 */
void
om_timer_tick(void);

/*==============================================================================
 * System Tick API
 *============================================================================*/

/**
 * @brief Increment the kernel tick.
 *
 * Called by the platform timer interrupt.
 */
void
om_tick_increment(void);

/**
 * @brief Get the current kernel tick.
 *
 * @return Current tick count.
 */
om_tick_t
om_tick_get(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TIMER_H */
