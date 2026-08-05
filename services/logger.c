/**
 * @file logger.c
 * @brief OrbitMesh logging service.
 *
 * Provides a lightweight logging layer for
 * kernel, drivers, and services.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/log.h"
#include "orbitmesh/error.h"

#include <stdarg.h>
#include <stdio.h>


/*==============================================================================
 * Private State
 *============================================================================*/

static om_bool_t
g_logger_initialized = false;


/*==============================================================================
 * Private Functions
 *============================================================================*/

/**
 * @brief Write a formatted log message.
 *
 * @param prefix Log level prefix.
 * @param format Message format string.
 * @param args Format arguments.
 */
static void
om_log_write(
    const char *prefix,
    const char *format,
    va_list args)
{
    printf(
        "%s",
        prefix
    );

    vprintf(
        format,
        args
    );

    printf(
        "\n"
    );
}


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize logging service.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_logger_init(void)
{
    g_logger_initialized = true;

    return OM_SUCCESS;
}


/**
 * @brief Write informational log message.
 *
 * @param format Message format string.
 */
void
om_log_info(
    const char *format,
    ...)
{
    if (!g_logger_initialized ||
        format == NULL)
    {
        return;
    }

    va_list args;

    va_start(
        args,
        format
    );

    om_log_write(
        "[INFO] ",
        format,
        args
    );

    va_end(
        args
    );
}


/**
 * @brief Write warning log message.
 *
 * @param format Message format string.
 */
void
om_log_warning(
    const char *format,
    ...)
{
    if (!g_logger_initialized ||
        format == NULL)
    {
        return;
    }

    va_list args;

    va_start(
        args,
        format
    );

    om_log_write(
        "[WARN] ",
        format,
        args
    );

    va_end(
        args
    );
}


/**
 * @brief Write error log message.
 *
 * @param format Message format string.
 */
void
om_log_error(
    const char *format,
    ...)
{
    if (!g_logger_initialized ||
        format == NULL)
    {
        return;
    }

    va_list args;

    va_start(
        args,
        format
    );

    om_log_write(
        "[ERROR] ",
        format,
        args
    );

    va_end(
        args
    );
}
