/**
 * @file test_logger.c
 * @brief OrbitMesh logger unit tests.
 *
 * Validates logging subsystem.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/log.h"

#include <assert.h>


void
run_test_logger(void)
{
    test_logger_configuration();

    test_logger_write();

    test_logger_read();
}
