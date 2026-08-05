/**
 * @file test_scheduler.c
 * @brief OrbitMesh scheduler unit tests.
 *
 * Validates scheduler initialization and execution behavior.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <assert.h>
#include <stdio.h>

#include "orbitmesh/scheduler.h"


/*==============================================================================
 * Test Prototypes
 *============================================================================*/

void
run_test_scheduler(void);


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_scheduler_initialization(void)
{
    om_error_t result;


    result =
        om_scheduler_init();


    assert(
        result == OM_SUCCESS
    );
}


static void
test_scheduler(void)
{
    om_error_t result;


    result =
        om_scheduler_run_once();


    assert(
        result == OM_SUCCESS
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

void
run_test_scheduler(void)
{
    test_scheduler_initialization();

    test_scheduler();


    printf(
        "Scheduler tests passed\n"
    );
}
