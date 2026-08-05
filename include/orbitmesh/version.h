/**
 * @file version.h
 * @brief OrbitMesh version information.
 *
 * This header defines the compile-time version information for the
 * OrbitMesh operating system.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_VERSION_H
#define ORBITMESH_VERSION_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Version Numbers
 *============================================================================*/

/**
 * @brief Major version.
 */
#define ORBITMESH_VERSION_MAJOR 0U

/**
 * @brief Minor version.
 */
#define ORBITMESH_VERSION_MINOR 1U

/**
 * @brief Patch version.
 */
#define ORBITMESH_VERSION_PATCH 0U

/*==============================================================================
 * Version Encoding
 *============================================================================*/

/**
 * @brief Encoded numeric version.
 *
 * Format:
 *
 * major * 10000 +
 * minor *   100 +
 * patch
 *
 * Example:
 *
 * 0.1.0 -> 100
 */
#define ORBITMESH_VERSION \
    ((ORBITMESH_VERSION_MAJOR * 10000U) + \
     (ORBITMESH_VERSION_MINOR *   100U) + \
      ORBITMESH_VERSION_PATCH)

/*==============================================================================
 * Version Strings
 *============================================================================*/

/**
 * @brief Project name.
 */
#define ORBITMESH_NAME "OrbitMesh"

/**
 * @brief Human-readable version string.
 */
#define ORBITMESH_VERSION_STRING "0.1.0"

/**
 * @brief Complete project identifier.
 */
#define ORBITMESH_FULL_VERSION \
    ORBITMESH_NAME " " ORBITMESH_VERSION_STRING

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Get the project version string.
 *
 * @return Constant null-terminated version string.
 */
const char *orbitmesh_version_string(void);

/**
 * @brief Get the encoded numeric version.
 *
 * @return Numeric version identifier.
 */
unsigned int orbitmesh_version(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_VERSION_H */
