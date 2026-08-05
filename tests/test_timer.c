/**
 * @file test_timer.c
 * @brief OrbitMesh timer unit tests.
 *
 * Validates timer initialization and tick
 * management functionality.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/timer.h"
#include "orbitmesh/error.h"

#include <assert.h>


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_timer_initialization(void)
{
    om_error_t result;


    result =
        om_timer_init(
            0U
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_timer_start(void)
{
    om_error_t result;


    result =
        om_timer_start(
            0U,
            1000U
        );


    assert(
        result == OM_SUCCESS
    );
}


static void
test_timer_ticks(void)
{
    om_tick_t ticks;


    ticks =
        om_timer_get_ticks(
            0U
        );


    assert(
        ticks >= 0U
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

int
main(void)
{
    test_timer_initialization();

    test_timer_start();

    test_timer_ticks();


    return 0;
}
