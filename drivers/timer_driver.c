/**
 * @file timer_driver.c
 * @brief OrbitMesh timer driver.
 *
 * Provides a generic timer interface built on top
 * of the OrbitMesh HAL layer.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/timer.h"
#include "orbitmesh/error.h"


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize timer driver.
 *
 * @param timer Timer identifier.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_timer_driver_init(
    uint32_t timer)
{
    return om_timer_init(
        timer
    );
}


/**
 * @brief Start hardware timer.
 *
 * @param timer Timer identifier.
 * @param frequency Timer frequency in Hz.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_timer_driver_start(
    uint32_t timer,
    uint32_t frequency)
{
    return om_timer_start(
        timer,
        frequency
    );
}


/**
 * @brief Stop hardware timer.
 *
 * @param timer Timer identifier.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_timer_driver_stop(
    uint32_t timer)
{
    return om_timer_stop(
        timer
    );
}


/**
 * @brief Get current timer tick count.
 *
 * @param timer Timer identifier.
 *
 * @return Current tick value.
 */
uint32_t
om_timer_driver_get_ticks(
    uint32_t timer)
{
    return om_timer_get_ticks(
        timer
    );
}
