/**
 * @file test_task.c
 * @brief OrbitMesh task unit tests.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "orbitmesh/task.h"

#include <assert.h>
#include <stdio.h>


static void
task_test_function(
    void *argument)
{
    (void)argument;
}


/**
 * @brief Test task creation.
 */
static void
test_task_creation(void)
{
    om_task_config_t config =
    {
        .name = "unit_task",
        .entry = task_test_function,
        .argument = NULL,
        .stack = NULL,
        .stack_size = 0U,
        .priority = 0U
    };

    om_task_t *task = NULL;

    om_error_t result;

    result =
        om_task_create(
            &config,
            &task
        );

    assert(
        result == OM_SUCCESS
    );

    assert(
        task != NULL
    );
}


/**
 * @brief Test task delay API.
 */
static void
test_task_delay(void)
{
    /*
     * Delay is a scheduler operation and has no return value.
     */
    om_task_delay(
        10U
    );
}


/**
 * @brief Run task tests.
 */
void
run_test_task(void)
{
    test_task_configuration();

    test_task_write();

    test_task_read();
}
