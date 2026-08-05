/**
 * @file test_scheduler.c
 * @brief OrbitMesh scheduler tests.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <assert.h>

#include "orbitmesh/kernel.h"
#include "orbitmesh/task.h"


/**
 * @brief Public test entry point.
 */
void
run_test_scheduler(void);


/**
 * @brief Verify scheduler initialization state.
 */
static void
test_scheduler_initialization(void)
{
    om_error_t result;

    result =
        om_kernel_init();

    assert(
        result == OM_SUCCESS
    );

    assert(
        om_kernel_is_initialized()
    );
}


/**
 * @brief Verify task subsystem initialization.
 */
static void
test_scheduler_task_system(void)
{
    om_error_t result;

    result =
        om_task_init();

    assert(
        result == OM_SUCCESS
    );
}


/**
 * @brief Execute scheduler tests.
 */
static void
test_scheduler(void)
{
    test_scheduler_initialization();

    test_scheduler_task_system();
}


/**
 * @brief Run scheduler test suite.
 */
void
run_test_scheduler(void)
{
    test_scheduler_configuration();

    test_scheduler_write();

    test_scheduler_read();
}
