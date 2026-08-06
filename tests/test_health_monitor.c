#include <assert.h>
#include <stdbool.h>

#include "orbitmesh/health_monitor.h"

void
run_test_health_monitor(void);

static void
test_health_monitor_state(void)
{
    const bool healthy = om_health_monitor_state();

    assert(healthy == true || healthy == false);
}

void
run_test_health_monitor(void)
{
    test_health_monitor_state();
}
