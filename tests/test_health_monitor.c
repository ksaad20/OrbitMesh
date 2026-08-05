/**
 * @file test_health_monitor.c
 * @brief OrbitMesh health monitor unit tests.
 *
 * Validates subsystem health tracking
 * and fault reporting.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/health_monitor.h"
#include "orbitmesh/error.h"

#include <assert.h>


/*==============================================================================
 * Tests
 *============================================================================*/

static void
test_health_initialization(void)
{
    om_error_t result;


    result =
        om_health_monitor_init();


    assert(
        result == OM_SUCCESS
    );


    assert(
        om_health_monitor_state()
        ==
        OM_HEALTH_OK
    );
}


static void
test_fault_reporting(void)
{
    uint32_t faults_before;


    faults_before =
        om_health_monitor_fault_count();


    om_health_monitor_fault(
        1U
    );


    assert(
        om_health_monitor_fault_count()
        ==
        faults_before + 1U
    );


    assert(
        om_health_monitor_state()
        ==
        OM_HEALTH_WARNING
    );
}


/*==============================================================================
 * Test Entry
 *============================================================================*/

void
run_test_health_monitor(void)
{
    test_health_monitor_configuration();

    test_health_monitor_write();

    test_health_monitor_read();
}
