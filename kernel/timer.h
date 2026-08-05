/**
 * @file timer.h
 * @brief OrbitMesh software timer API.
 *
 * Provides deterministic software timers for embedded and spacecraft
 * applications.
 *
 * The MVP implementation uses static allocation only and does not require
 * dynamic memory.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
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
 * @brief Software timer callback.
 *
 * @param argument User-supplied callback argument.
 */
typedef void (*om_timer_callback_t)(void *argument);

/**
 * @brief Software timer.
 *
 * Applications should treat this structure as opaque.
 * It is defined publicly only because the MVP uses static allocation.
 */
typedef struct
{
    bool allocated;
    bool running;
    bool periodic;

    om_tick_t period_ticks;
    om_tick_t remaining_ticks;

    om_timer_callback_t callback;
    void *argument;

} om_timer_t;

/*==============================================================================
 * Public API
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
 * @param period_ticks Timer period.
 * @param periodic True for periodic timer.
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
    void *argument);

/**
 * @brief Start a timer.
 *
 * @param timer Timer.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_timer_start(
    om_timer_t *timer);

/**
 * @brief Stop a timer.
 *
 * @param timer Timer.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_timer_stop(
    om_timer_t *timer);

/**
 * @brief Restart a timer.
 *
 * @param timer Timer.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_timer_restart(
    om_timer_t *timer);

/**
 * @brief Determine whether a timer is running.
 *
 * @param timer Timer.
 *
 * @return true if running.
 */
bool
om_timer_is_running(
    const om_timer_t *timer);

/**
 * @brief Process one scheduler tick.
 *
 * Called internally by the kernel.
 */
void
om_timer_tick(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TIMER_H */
