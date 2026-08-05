/**
 * @file clock.c
 * @brief ARM Cortex-M clock initialization.
 *
 * Provides the platform clock initialization interface
 * used during OrbitMesh startup.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include <stdint.h>


/*==============================================================================
 * Private State
 *============================================================================*/

static uint32_t g_system_clock_hz = 0U;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize system clock.
 *
 * Default Cortex-M implementation.
 *
 * Device-specific platforms may override this
 * for PLL and oscillator configuration.
 */
void
om_clock_init(void)
{
    /*
     * Default safe clock value.
     *
     * MCU-specific implementations should
     * configure the actual oscillator.
     */
    g_system_clock_hz = 8000000U;
}


/**
 * @brief Get current system clock frequency.
 *
 * @return Clock frequency in Hz.
 */
uint32_t
om_clock_get_frequency(void)
{
    return g_system_clock_hz;
}
