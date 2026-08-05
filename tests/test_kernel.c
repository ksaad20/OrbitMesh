/**
 * @file test_kernel.c
 * @brief OrbitMesh kernel unit tests.
 *
 * Validates kernel initialization and startup
 * behavior using the Linux simulator.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/kernel.h"
#include "orbitmesh/error.h"

#include <assert.h>


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_kernel_initialization(void)
{
    om_error_t result;


    result =
        om_kernel_init();


    assert(
        result == OM_SUCCESS
    );
}


static void
test_kernel_state(void)
{
    om_kernel_state_t state;


    state =
        om_kernel_get_state();


    assert(
        state == OM_KERNEL_INITIALIZED
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

int
main(void)
{
    test_kernel_initialization();

    test_kernel_state();


    return 0;
}
