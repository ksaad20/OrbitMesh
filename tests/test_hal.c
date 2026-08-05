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


void
run_test_hal(void)
{
    test_hal_configuration();

    test_hal_write();

    test_hal_read();
}
