/**
 * @file platform.c
 * @brief OrbitMesh Linux platform implementation.
 *
 * Provides platform-level initialization hooks
 * for the Linux simulator.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/error.h"


/*==============================================================================
 * External Functions
 *============================================================================*/

extern void
om_linux_simulator_init(void);


/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_platform_init(void)
{
    om_linux_simulator_init();

    return OM_SUCCESS;
}
