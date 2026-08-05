/**
 * @file version.c
 * @brief OrbitMesh version information.
 *
 * Implements the version information API.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/version.h"

/*==============================================================================
 * Public API
 *============================================================================*/

const char *
orbitmesh_version_string(void)
{
    return ORBITMESH_VERSION_STRING;
}

unsigned int
orbitmesh_version(void)
{
    return ORBITMESH_VERSION;
}
