/**
 * @file test_task.c
 * @brief OrbitMesh task unit tests.
 *
 * Validates task management functionality.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/task.h"
#include "orbitmesh/error.h"

#include <assert.h>


/*==============================================================================
 * Test State
 *============================================================================*/

static uint32_t
g_execution_count = 0U;


/*==============================================================================
 * Test Task
 *============================================================================*/

static void
task_test_function(
    void *argument)
{
    (void)argument;


    g_execution_count++;
}


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_task_creation(void)
{
    om_error_t result;


    result =
        om_task_create(
            "unit_task",
            task_test_function,
            NULL
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
            10U
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_task_counter(void)
{
    assert(
        g_execution_count == 0U
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

int
main(void)
{
    test_task_creation();

    test_task_delay();

    test_task_counter();


    return 0;
}
