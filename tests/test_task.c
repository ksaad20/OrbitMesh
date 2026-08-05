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
    om_task_t task;

    om_error_t result;


    result =
        om_task_create(
            &task,
            "test_task",
            dummy_task,
            NULL,
            NULL,
            0U
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_task_delay(void)
{
    om_error_t result;


    result =
        om_task_delay(
            1U
        );


    assert(
        result == OM_SUCCESS
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
