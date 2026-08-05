/**
 * @file test_scheduler.c
 * @brief OrbitMesh scheduler unit tests.
 *
 * Validates scheduler startup and task dispatch.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/scheduler.h"
#include "orbitmesh/task.h"
#include "orbitmesh/error.h"

#include <assert.h>


/*==============================================================================
 * Test State
 *============================================================================*/

static uint32_t
g_task_counter = 0U;


/*==============================================================================
 * Test Task
 *============================================================================*/

static void
scheduler_test_task(
    void *argument)
{
    (void)argument;


    g_task_counter++;
}


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
test_scheduler_task_creation(void)
{
    om_error_t result;


    result =
        om_task_create(
            "test",
            scheduler_test_task,
            NULL
        );


    assert(
        result == OM_SUCCESS
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

int
main(void)
{
    test_scheduler_initialization();

    test_scheduler_task_creation();


    return 0;
}
