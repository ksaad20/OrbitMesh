#include "orbitmesh/drivers/timer_driver.h"

#include "orbitmesh/timer.h"

om_error_t
om_timer_driver_init(void)
{
    return om_timer_init();
}

om_error_t
om_timer_driver_start(
    om_timer_t *timer
)
{
    return om_timer_start(
        timer
    );
}

om_error_t
om_timer_driver_stop(
    om_timer_t *timer
)
{
    return om_timer_stop(
        timer
    );
}

uint32_t
om_timer_driver_get_ticks(void)
{
#ifdef OM_TIMER_HAS_GET_TICKS
    return om_timer_get_ticks();
#else
    /*
     * The current HAL does not expose a function that returns the
     * system tick count. This should be replaced once such an API
     * is available.
     */
    return 0U;
#endif
}
