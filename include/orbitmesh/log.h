/**
 * @file log.h
 * @brief OrbitMesh logging service interface.
 *
 * Provides a lightweight logging API for the
 * OrbitMesh kernel, drivers, and services.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_LOG_H
#define ORBITMESH_LOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "orbitmesh/error.h"

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the logging service.
 *
 * @return OrbitMesh error code.
 */
om_error_t
om_logger_init(void);

/**
 * @brief Write an informational log message.
 *
 * Uses printf-style formatting.
 *
 * @param format Format string.
 * @param ... Format arguments.
 */
void
om_log_info(
    const char *format,
    ...);

/**
 * @brief Write a warning log message.
 *
 * Uses printf-style formatting.
 *
 * @param format Format string.
 * @param ... Format arguments.
 */
void
om_log_warning(
    const char *format,
    ...);

/**
 * @brief Write an error log message.
 *
 * Uses printf-style formatting.
 *
 * @param format Format string.
 * @param ... Format arguments.
 */
void
om_log_error(
    const char *format,
    ...);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_LOG_H */
