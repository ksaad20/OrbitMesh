 /**
 * @file timer.h
 * @brief OrbitMesh software timer API.
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

/*==============================================================================
 * Types
 *============================================================================*/

/**
 * @brief Timer callback.
 *
 * @param argument User argument.
 */
typedef void (*om_timer_callback_t)(
    void *argument
);

/**
 * @brief Software timer object.
 *
 * Full definition for the MVP.
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

om_error_t
om_timer_init(void);

om_error_t
om_timer_create(
    om_timer_t *timer,
    om_tick_t period_ticks,
    bool periodic,
    om_timer_callback_t callback,
    void *argument
);

om_error_t
om_timer_start(
    om_timer_t *timer
);

om_error_t
om_timer_stop(
    om_timer_t *timer
);

om_error_t
om_timer_restart(
    om_timer_t *timer
);

bool
om_timer_is_running(
    const om_timer_t *timer
);

void
om_timer_tick(void);

/*==============================================================================
 * System Tick API
 *============================================================================*/

void
om_tick_increment(void);

om_tick_t
om_tick_get(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TIMER_H */
