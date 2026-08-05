/**
 * @file test_scheduler.c
 * @brief OrbitMesh scheduler unit tests.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <assert.h>
#include <stdio.h>

#include "orbitmesh/kernel.h"
#include "orbitmesh/task.h"


/*
 * Public test entry point.
 */
void
run_test_scheduler(void);


/*
 * Verify scheduler can initialize with kernel startup.
 */
static void
test_scheduler_initialization(void)
{
    om_error_t result =
        om_kernel_init();

    assert(
        result == OM_SUCCESS
    );
}


/*
 * Verify scheduler can handle a task registration.
 */
static void
test_scheduler_task_registration(void)
{
    om_task_t *task =
        NULL;

    om_task_config_t config =
    {
        .name = "scheduler_test",
        .priority = 1U,
        .stack_size = 1024U
    };


    om_error_t result =
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


/*
 * Scheduler test runner.
 */
void
run_test_scheduler(void)
{
    test_scheduler_initialization();

    test_scheduler_task_registration();

    printf(
        "Scheduler tests passed\n"
    );
}
