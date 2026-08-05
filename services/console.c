/**
 * @file console.c
 * @brief OrbitMesh console service.
 *
 * Provides a lightweight command console over UART.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/console.h"
#include "orbitmesh/error.h"

#include <stddef.h>
#include <string.h>


/*==============================================================================
 * Private State
 *============================================================================*/

static om_bool_t g_console_initialized = false;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize console service.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_console_init(void)
{
    g_console_initialized = true;

    return OM_SUCCESS;
}


/**
 * @brief Write text to console.
 *
 * @param message Text buffer.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_console_write(
    const char *message)
{
    if (!g_console_initialized)
    {
        return OM_ERROR_INVALID_STATE;
    }


    if (message == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    /*
     * UART backend handles actual output.
     */
    return OM_SUCCESS;
}


/**
 * @brief Process console input.
 *
 * Called periodically by the service scheduler.
 */
void
om_console_process(void)
{
    if (!g_console_initialized)
    {
        return;
    }


    /*
     * Command processing will be expanded
     * as services are added.
     */
}
