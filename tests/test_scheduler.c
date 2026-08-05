/**
 * @file test_scheduler.c
 * @brief OrbitMesh scheduler behavior tests.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <assert.h>

#include "orbitmesh/kernel.h"
#include "orbitmesh/task.h"


/**
 * @brief Verify scheduler startup state.
 */
static void
test_scheduler_state(void)
{
    om_error_t result;

    result = om_kernel_init();

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
test_scheduler_task_init(void)
{
    om_error_t result;

    result = om_task_init();

    assert(
        result == OM_SUCCESS
    );
}


/**
 * @brief Scheduler test entry.
 */
void
test_scheduler(void)
{
    test_scheduler_state();

    test_scheduler_task_init();
}
