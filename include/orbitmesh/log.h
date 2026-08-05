/**
 * @file log.h
 * @brief OrbitMesh logging service interface.
 *
 * Provides a lightweight logging API for OrbitMesh services.
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

#include <stdbool.h>

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the logging service.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_logger_init(void);


/**
 * @brief Log an informational message.
 *
 * @param message Null-terminated message string.
 */
void
om_log_info(
    const char *message);


/**
 * @brief Log a warning message.
 *
 * @param message Null-terminated message string.
 */
void
om_log_warning(
    const char *message);


/**
 * @brief Log an error message.
 *
 * @param message Null-terminated message string.
 */
void
om_log_error(
    const char *message);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_LOG_H */
