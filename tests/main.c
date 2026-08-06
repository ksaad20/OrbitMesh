/**
 * @file main.c
 * @brief OrbitMesh test runner.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

void
run_test_kernel(void);

void
run_test_task(void);

void
run_test_scheduler(void);

void
run_test_timer(void);

void
run_test_hal(void);

void
run_test_gpio(void);

void
run_test_uart(void);

void
run_test_health_monitor(void);

void
run_test_heartbeat(void);

int
main(void)
{
    run_test_kernel();

    run_test_task();

    run_test_scheduler();

    run_test_timer();

    run_test_hal();

    run_test_gpio();

    run_test_uart();

    run_test_health_monitor();

    run_test_heartbeat();

    printf(
        "All OrbitMesh tests passed\n"
    );

    return 0;
}
