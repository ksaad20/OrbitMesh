#include <assert.h>
#include <stdbool.h>

#include "orbitmesh/heartbeat.h"

void
run_test_heartbeat(void);

static void
test_heartbeat_update(void)
{
    om_heartbeat_update();

    assert(true);
}

void
run_test_heartbeat(void)
{
    test_heartbeat_update();
}
