/**
 * @file test_console.c
 * @brief OrbitMesh console unit tests.
 *
 * Validates console service behavior.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/console.h"
#include "orbitmesh/error.h"

#include <assert.h>


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_console_initialization(void)
{
    om_error_t result;


    result =
        om_console_init();


    assert(
        result == OM_SUCCESS
    );
}


static void
test_console_write(void)
{
    om_error_t result;


    result =
        om_console_write(
            "OrbitMesh console test\n"
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
    test_console_initialization();

    test_console_write();


    return 0;
}
