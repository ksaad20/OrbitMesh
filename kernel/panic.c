/**
 * @file panic.c
 * @brief Kernel panic handler.
 *
 * Implements the OrbitMesh panic handler.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/assert.h"
#include "orbitmesh/kernel.h"

#include <stddef.h>

/*==============================================================================
 * Private Functions
 *============================================================================*/

/**
 * @brief Enter an unrecoverable system halt.
 *
 * This function intentionally never returns.
 */
static OM_NORETURN void
panic_halt(void)
{
    for (;;)
    {
        /* Spin forever.
         *
         * Future implementations may:
         *  - Disable interrupts
         *  - Blink an LED
         *  - Emit a UART panic message
         *  - Trigger a watchdog reset
         *  - Store crash diagnostics
         */
    }
}

/*==============================================================================
 * Public API
 *============================================================================*/

OM_NORETURN
void
om_kernel_panic(const char *reason)
{
    /*
     * The reason is currently unused. Future releases will integrate the
     * logging and diagnostics services to record panic information.
     */
    OM_UNUSED_VAR(reason);

    panic_halt();
}

OM_NORETURN
void
om_assert_fail(
    const char *expression,
    const char *file,
    unsigned int line,
    const char *function)
{
    /*
     * Parameters are reserved for future diagnostics support.
     */
    OM_UNUSED_VAR(expression);
    OM_UNUSED_VAR(file);
    OM_UNUSED_VAR(line);
    OM_UNUSED_VAR(function);

    om_kernel_panic("Assertion failed");
}
