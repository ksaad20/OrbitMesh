#include <assert.h>
#include <stdio.h>

#include "orbitmesh/hal.h"


void run_test_hal(void);


static void
test_hal_initialization(void)
{
    const int result = om_hal_init();

    assert(result == 0);
}


static void
test_hal_status(void)
{
    const bool initialized = om_hal_is_initialized();

    assert(initialized == true);
}


void
run_test_hal(void)
{
    test_hal_initialization();
    test_hal_status();

    printf("HAL tests passed\n");
}
