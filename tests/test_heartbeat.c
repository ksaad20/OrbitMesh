#include <assert.h>
#include <stdbool.h>

#include "orbitmesh/heartbeat.h"


static void
test_heartbeat_initialization(void)
{
    const int result = om_heartbeat_init();

    assert(result == 0);
}


static void
test_heartbeat_update(void)
{
    const bool active_before = om_heartbeat_is_active();

    om_heartbeat_update();

    const bool active_after = om_heartbeat_is_active();

    assert(active_after != active_before || active_after == active_before);
}


void
run_test_heartbeat(void)
{
    test_heartbeat_initialization();
    test_heartbeat_update();
}
