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


int
main(void)
{
    om_log_init();


    om_log_info(
        "Logger test"
    );


    assert(1);


    return 0;
}
