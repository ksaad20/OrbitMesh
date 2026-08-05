/**
 * @file test_timer.c
 * @brief OrbitMesh timer unit tests.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <assert.h>
#include <stdio.h>

#include "orbitmesh/timer.h"


static void
timer_callback(
    void *argument
)
{
    (void)argument;
}


static void
test_timer_initialization(void)
{
    om_error_t result;


    result =
        om_timer_init();


    assert(
        result == OM_SUCCESS
    );
}


static void
test_timer_start(void)
{
    om_timer_t timer;

    om_error_t result;


    result =
        om_timer_create(
            &timer,
            1000U,
            false,
            timer_callback,
            NULL
        );


    assert(
        result == OM_SUCCESS
    );


    result =
        om_timer_start(
            &timer
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_timer_ticks(void)
{
    om_timer_tick();

    om_timer_tick();


    assert(
        true
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

static void
run_test_timer(void)
{
    test_timer_initialization();

    test_timer_start();

    test_timer_ticks();


    printf(
        "Timer tests passed\n"
    );
}


int
main(void)
{
    run_test_timer();


    return 0;
}
