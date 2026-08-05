/**
 * @file software_timer.c
 * @brief OrbitMesh software timer service.
 *
 * Provides lightweight software timers driven
 * by the system tick.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/timer.h"
#include "orbitmesh/error.h"
#include "orbitmesh/types.h"


/*==============================================================================
 * Configuration
 *============================================================================*/

#define OM_MAX_SOFTWARE_TIMERS 16U


/*==============================================================================
 * Private Types
 *============================================================================*/

typedef struct
{
    om_bool_t active;

    om_tick_t period;

    om_tick_t next_expiration;

    void (*callback)(void);

} om_software_timer_t;


/*==============================================================================
 * Private State
 *============================================================================*/

static om_software_timer_t
    g_timers[OM_MAX_SOFTWARE_TIMERS];


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize software timers.
 */
void
om_software_timer_init(void)
{
    for (uint32_t i = 0U;
         i < OM_MAX_SOFTWARE_TIMERS;
         ++i)
    {
        g_timers[i].active = false;
    }
}


/**
 * @brief Create software timer.
 *
 * @param period Timer period in ticks.
 * @param callback Callback function.
 *
 * @return Timer identifier or error.
 */
int32_t
om_software_timer_create(
    om_tick_t period,
    void (*callback)(void))
{
    if (callback == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    for (uint32_t i = 0U;
         i < OM_MAX_SOFTWARE_TIMERS;
         ++i)
    {
        if (!g_timers[i].active)
        {
            g_timers[i].active = true;

            g_timers[i].period = period;

            g_timers[i].next_expiration = period;

            g_timers[i].callback = callback;


            return (int32_t)i;
        }
    }


    return OM_ERROR_NO_RESOURCES;
}


/**
 * @brief Process software timers.
 *
 * Called from the system tick handler.
 *
 * @param tick Current system tick.
 */
void
om_software_timer_process(
    om_tick_t tick)
{
    for (uint32_t i = 0U;
         i < OM_MAX_SOFTWARE_TIMERS;
         ++i)
    {
        if (g_timers[i].active &&
            tick >= g_timers[i].next_expiration)
        {
            g_timers[i].callback();


            g_timers[i].next_expiration =
                tick + g_timers[i].period;
        }
    }
}
