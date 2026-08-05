#ifndef ORBITMESH_DRIVERS_TIMER_DRIVER_H
#define ORBITMESH_DRIVERS_TIMER_DRIVER_H

#include <stdint.h>

#include "orbitmesh/timer.h"
#include "orbitmesh/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize the timer driver.
 *
 * @return OM_OK on success, otherwise an error code.
 */
om_error_t
om_timer_driver_init(void);

/**
 * @brief Start a timer instance.
 *
 * @param timer Pointer to the timer instance.
 *
 * @return OM_OK on success, otherwise an error code.
 */
om_error_t
om_timer_driver_start(
    om_timer_t *timer
);

/**
 * @brief Stop a timer instance.
 *
 * @param timer Pointer to the timer instance.
 *
 * @return OM_OK on success, otherwise an error code.
 */
om_error_t
om_timer_driver_stop(
    om_timer_t *timer
);

/**
 * @brief Get the current timer tick count.
 *
 * Returns the current system tick count if supported by the HAL.
 *
 * @return Current tick count.
 */
uint32_t
om_timer_driver_get_ticks(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_DRIVERS_TIMER_DRIVER_H */
