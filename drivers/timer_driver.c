 /**
  * @file timer_driver.c
  * @brief OrbitMesh timer driver wrapper implementation.
  */

#include "orbitmesh/drivers/timer_driver.h"

#include "orbitmesh/error.h"
#include "orbitmesh/timer.h"


/**
 * @brief Initialize the timer driver.
 *
 * The timer HAL manages the timer hardware initialization internally.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_timer_driver_init(void)
{
    return om_timer_init();
}


/**
 * @brief Start a timer instance.
 *
 * @param timer Timer instance.
 *
 * @return OM_SUCCESS on success.
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
 * @brief Stop a timer instance.
 *
 * @param timer Timer instance.
 *
 * @return OM_SUCCESS on success.
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
 * @brief Get current timer tick count.
 *
 * Uses the HAL tick counter exposed through the timer subsystem.
 *
 * @return Current tick count.
 */
uint32_t
om_timer_driver_get_ticks(void)
{
    return om_timer_tick_count();
}
