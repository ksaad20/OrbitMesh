/**
 * @file test_version.c
 * @brief OrbitMesh version tests.
 *
 * @copyright Apache License 2.0
 */

#include "orbitmesh/version.h"

#include <assert.h>


int
main(void)
{
    const char *version;


    version =
        om_version_string();


    assert(
        version != 0
    );


    return 0;
}
