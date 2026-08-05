#include <assert.h>
#include <stdio.h>

#include "orbitmesh/timer.h"


void run_test_timer(void);


static void
test_timer_initialization(void)
{
    const int result = om_timer_init();

    assert(result == 0);
}


static void
test_timer_tick(void)
{
    const om_tick_t before = om_timer_get_tick();

    om_timer_tick();

    const om_tick_t after = om_timer_get_tick();

    assert(after > before);
}


void
run_test_timer(void)
{
    test_timer_initialization();
    test_timer_tick();

    printf("Timer tests passed\n");
}
