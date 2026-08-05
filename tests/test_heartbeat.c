/**
 * @file test_heartbeat.c
 * @brief OrbitMesh heartbeat unit tests.
 *
 * Validates heartbeat service functionality.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/heartbeat.h"
#include "orbitmesh/error.h"

#include <assert.h>


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_heartbeat_initialization(void)
{
    om_error_t result;


    result =
        om_heartbeat_init();


    assert(
        result == OM_SUCCESS
    );


    assert(
        om_heartbeat_count()
        ==
        0U
    );
}


static void
test_heartbeat_update(void)
{
    uint32_t count_before;


    count_before =
        om_heartbeat_count();


    om_heartbeat_update();


    assert(
        om_heartbeat_count()
        ==
        count_before + 1U
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

int
main(void)
{
    test_heartbeat_initialization();

    test_heartbeat_update();


    return 0;
}
