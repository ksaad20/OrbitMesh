/**
 * @file log.h
 * @brief OrbitMesh logging service interface.
 *
 * Provides a generic logging API for OrbitMesh services.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_LOG_H
#define ORBITMESH_LOG_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "orbitmesh/error.h"

#include <stdarg.h>

/*==============================================================================
 * Log Levels
 *============================================================================*/

/**
 * @brief Logging severity levels.
 */
typedef enum
{
    OM_LOG_DEBUG = 0,
    OM_LOG_INFO,
    OM_LOG_WARNING,
    OM_LOG_ERROR,
    OM_LOG_FATAL
} om_log_level_t;

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the logging subsystem.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_log_init(void);

/**
 * @brief Write a formatted log message.
 *
 * @param level Log severity.
 * @param format printf-style format string.
 * @param ... Format arguments.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_log(
    om_log_level_t level,
    const char *format,
    ...);

/**
 * @brief Flush pending log output.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_log_flush(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_LOG_H */
