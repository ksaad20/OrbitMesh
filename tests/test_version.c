/**
 * @file test_version.c
 * @brief OrbitMesh version tests.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/version.h"

#include <assert.h>


void
run_test_version(void)
{
    test_version_configuration();

    test_version_write();

    test_version_read();
}
