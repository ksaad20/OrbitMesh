/**
 * @file macros.h
 * @brief Common OrbitMesh utility macros.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ORBITMESH_MACROS_H
#define ORBITMESH_MACROS_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Common macros
 *============================================================================*/

/**
 * @brief Number of elements in an array.
 */
#define OM_ARRAY_SIZE(array) \
    (sizeof(array) / sizeof((array)[0]))

/**
 * @brief Suppress unused variable warnings.
 */
#define OM_UNUSED(variable) \
    ((void)(variable))

/**
 * @brief Minimum of two values.
 */
#define OM_MIN(a, b) \
    (((a) < (b)) ? (a) : (b))

/**
 * @brief Maximum of two values.
 */
#define OM_MAX(a, b) \
    (((a) > (b)) ? (a) : (b))

/**
 * @brief Clamp a value between a minimum and maximum.
 */
#define OM_CLAMP(value, minimum, maximum) \
    (OM_MIN(OM_MAX((value), (minimum)), (maximum)))

/**
 * @brief Align a value upward.
 */
#define OM_ALIGN_UP(value, alignment) \
    (((value) + ((alignment) - 1U)) & ~((alignment) - 1U))

/**
 * @brief Align a value downward.
 */
#define OM_ALIGN_DOWN(value, alignment) \
    ((value) & ~((alignment) - 1U))

/**
 * @brief Static assertion wrapper.
 */
#define OM_STATIC_ASSERT(condition, message) \
    _Static_assert((condition), message)

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_MACROS_H */
