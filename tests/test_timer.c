/**
 * @file test_timer.c
 * @brief OrbitMesh timer tests.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <assert.h>

#include "orbitmesh/timer.h"


/**
 * @brief Public test entry point.
 */
void
run_test_timer(void);


/**
 * @brief Verify timer initialization.
 */
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


/**
 * @brief Verify timer start operation.
 */
static void
test_timer_start(void)
{
    om_timer_t timer;

    om_error_t result;

    result =
        om_timer_start(
            &timer
        );

    assert(
        result == OM_SUCCESS
    );
}


/**
 * @brief Verify timer tick retrieval.
 */
static void
test_timer_ticks(void)
{
    om_tick_t ticks;

    ticks =
        om_timer_tick();

    assert(
        ticks >= 0U
    );
}


/**
 * @brief Execute timer tests.
 */
static void
test_timer(void)
{
    test_timer_initialization();

    test_timer_start();

    test_timer_ticks();
}


/**
 * @brief Run timer test suite.
 */
void
run_test_timer(void)
{
    test_timer();
}
