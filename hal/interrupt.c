/**
 * @file interrupt.c
 * @brief OrbitMesh interrupt HAL implementation.
 *
 * Provides platform-independent interrupt
 * control abstraction.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/error.h"


om_error_t
om_interrupt_init(void)
{
    return OM_SUCCESS;
}


void
om_interrupt_enable(void)
{
}


void
om_interrupt_disable(void)
{
}
