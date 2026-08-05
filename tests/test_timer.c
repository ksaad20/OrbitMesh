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
 * Test Prototypes
 *============================================================================*/

void
run_test_timer(void);


/*==============================================================================
 * Tests
 *============================================================================*/

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


static void
test_timer_ticks(void)
{
    om_tick_t ticks =
        om_timer_get_ticks();


    assert(
        ticks >= 0U
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

void
run_test_timer(void)
{
    test_timer_initialization();

    test_timer_ticks();


    printf(
        "Timer tests passed\n"
    );
}
