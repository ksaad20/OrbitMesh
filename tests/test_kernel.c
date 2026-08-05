/**
 * @file test_kernel.c
 * @brief OrbitMesh kernel unit tests.
 *
 * Validates kernel initialization and lifecycle behavior.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <assert.h>
#include <stdio.h>

#include "orbitmesh/kernel.h"


/*==============================================================================
 * Test Prototypes
 *============================================================================*/

void
run_test_kernel(void);


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_kernel_initialization(void)
{
    om_error_t result;


    result =
        om_kernel_init();


    assert(
        result == OM_SUCCESS
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

void
run_test_kernel(void)
{
    test_kernel_initialization();


    printf(
        "Kernel tests passed\n"
    );
}
