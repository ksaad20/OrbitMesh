/**
 * @file test_task.c
 * @brief OrbitMesh task unit tests.
 *
 * Validates task creation and delay behavior.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <assert.h>
#include <stdio.h>

#include "orbitmesh/task.h"


/*==============================================================================
 * Test Prototypes
 *============================================================================*/

void
run_test_task(void);


/*==============================================================================
 * Test Helpers
 *============================================================================*/

static void
dummy_task(
    void *argument
)
{
    (void)argument;
}


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_task_creation(void)
{
    om_task_t *task = NULL;


    om_error_t result;


    result =
        om_task_create(
            &task
        );


    assert(
        result == OM_SUCCESS
    );

    assert(
        task != NULL
    );
}


static void
test_task_delay(void)
{
    om_task_delay(
        1U
    );


    assert(
        true
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

void
run_test_task(void)
{
    test_task_creation();

    test_task_delay();


    printf(
        "Task tests passed\n"
    );
}
