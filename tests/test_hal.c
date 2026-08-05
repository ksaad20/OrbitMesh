/**
 * @file test_hal.c
 * @brief OrbitMesh HAL unit tests.
 *
 * Validates HAL initialization.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/hal.h"
#include "orbitmesh/error.h"

#include <assert.h>


int
main(void)
{
    om_error_t result;


    result =
        om_hal_init();


    assert(
        result == OM_SUCCESS
    );


    return 0;
}
