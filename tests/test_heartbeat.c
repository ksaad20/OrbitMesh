#include <assert.h>

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
    om_heartbeat_update();
}


static void
run_test_heartbeat(void)
{
    test_heartbeat_initialization();
    test_heartbeat_update();
}
