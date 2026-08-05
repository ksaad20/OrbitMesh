/**
 * @file timer_driver.c
 * @brief OrbitMesh timer driver implementation.
 */

#include "orbitmesh/timer.h"

#include "orbitmesh/error.h"


/**
 * @brief Initialize timer driver.
 *
 * @return Operation status.
 */
om_error_t
om_timer_driver_init(void)
{
    return om_timer_init();
}


/**
 * @brief Start timer instance.
 *
 * @param timer Timer instance.
 *
 * @return Operation status.
 */
om_error_t
om_timer_driver_start(
    om_timer_t *timer
)
{
    return om_timer_start(
        timer
    );
}


/**
 * @brief Stop timer instance.
 *
 * @param timer Timer instance.
 *
 * @return Operation status.
 */
om_error_t
om_timer_driver_stop(
    om_timer_t *timer
)
{
    return om_timer_stop(
        timer
    );
}


/**
 * @brief Get current timer tick value.
 *
 * @return Tick count.
 */
uint32_t
om_timer_driver_get_ticks(void)
{
    return om_timer_tick();
}
