/**
 * @file system.c
 * @brief ARM Cortex-M system initialization.
 *
 * Provides early hardware initialization before
 * OrbitMesh kernel startup.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/hal.h"


/*==============================================================================
 * External Functions
 *============================================================================*/

/**
 * @brief Configure system clock.
 */
extern void
om_clock_init(void);


/**
 * @brief Initialize interrupt controller.
 */
extern void
om_interrupt_init(void);


/*==============================================================================
 * Public API
 *============================================================================*/

void
om_system_init(void)
{
    /*
     * Configure processor clock.
     */
    om_clock_init();


    /*
     * Configure interrupt handling.
     */
    om_interrupt_init();


    /*
     * Initialize hardware abstraction layer.
     */
    om_hal_init();
}
