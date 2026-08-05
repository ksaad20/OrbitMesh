/**
 * @file test_timer.c
 * @brief OrbitMesh timer unit tests.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <assert.h>
#include <stdio.h>

#include "orbitmesh/timer.h"


/*==============================================================================
 * Test Cases
 *============================================================================*/

/**
 * @brief Test timer initialization.
 */
static void
test_timer_initialization(void)
{
    om_error_t result;

    result = om_timer_init();

    assert(
        result == OM_SUCCESS
    );
}


/**
 * @brief Test timer creation and start.
 */
static void
test_timer_start(void)
{
    om_timer_t timer;

    om_timer_config_t config =
    {
        .period = 1000U,
        .callback = NULL,
        .argument = NULL
    };


    om_error_t result;


    result = om_timer_create(
        &config,
        &timer
    );

    assert(
        result == OM_SUCCESS
    );


    result = om_timer_start(
        &timer
    );

    assert(
        result == OM_SUCCESS
    );
}


/**
 * @brief Test timer tick handling.
 */
static void
test_timer_ticks(void)
{
    om_tick_t before;
    om_tick_t after;


    before = om_timer_tick_count();


    om_timer_tick();


    after = om_timer_tick_count();


    assert(
        after >= before
    );
}


/*==============================================================================
 * Test Runner
 *============================================================================*/

void
run_test_timer(void)
{
    test_timer_initialization();

    test_timer_start();

    test_timer_ticks();


    printf(
        "Timer tests passed\n"
    );
}
