/**
 * @file test_kernel.c
 * @brief OrbitMesh kernel unit tests.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "orbitmesh/kernel.h"

#include <assert.h>
#include <stdio.h>


/**
 * @brief Test kernel initialization.
 */
static void
test_kernel_initialization(void)
{
    om_error_t result;

    result =
        om_kernel_init();

    assert(
        result == OM_SUCCESS
    );

    assert(
        om_kernel_is_initialized()
    );
}


/**
 * @brief Test kernel state reporting.
 */
static void
test_kernel_state(void)
{
    om_kernel_state_t state;

    state =
        om_kernel_state();

    assert(
        state == OM_KERNEL_STATE_INITIALIZED ||
        state == OM_KERNEL_STATE_RUNNING
    );
}


/**
 * @brief Test kernel uptime access.
 */
static void
test_kernel_uptime(void)
{
    om_tick_t uptime;

    uptime =
        om_kernel_uptime();

    assert(
        uptime >= 0U
    );
}


/**
 * @brief Run kernel tests.
 */
int
main(void)
{
    test_kernel_initialization();

    test_kernel_state();

    test_kernel_uptime();

    printf(
        "Kernel tests passed\n"
    );

    return 0;
}
