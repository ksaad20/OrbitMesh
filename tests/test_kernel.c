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
    om_tick_t uptime_before;
    om_tick_t uptime_after;

    uptime_before =
        om_kernel_uptime();

    uptime_after =
        om_kernel_uptime();

    assert(
        uptime_after >= uptime_before
    );
}


/**
 * @brief Run kernel tests.
 */
void
run_test_kernel(void)
{
    test_kernel_initialization();
}

void
run_test_kernel(void);
