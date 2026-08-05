/**
 * @file test_timer.c
 * @brief OrbitMesh timer unit tests.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <assert.h>
#include <stdio.h>

#include "orbitmesh/timer.h"


/*
 * Public test entry point.
 * Declared here to satisfy -Wmissing-prototypes.
 */
void
run_test_timer(void);


/*
 * Verify timer creation works.
 */
static void
test_timer_initialization(void)
{
    om_timer_t timer;

    om_error_t result =
        om_timer_create(
            &timer,
            1000U,
            false,
            NULL,
            NULL
        );

    assert(
        result == OM_SUCCESS
    );
}


/*
 * Verify timer tick access works.
 */
static void
test_timer_ticks(void)
{
    om_tick_t ticks =
        om_timer_get_ticks();

    assert(
        ticks >= 0U
    );
}


/*
 * Timer test runner.
 */
void
run_test_timer(void)
{
    test_timer_initialization();

    test_timer_ticks();

    printf(
        "Timer tests passed\n"
    );
}
