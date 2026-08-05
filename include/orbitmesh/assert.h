/**
 * @file assert.h
 * @brief Runtime assertion support for OrbitMesh.
 *
 * Provides configurable runtime assertions for debugging and development.
 * Assertions can be completely disabled at compile time by setting
 * OM_CONFIG_ENABLE_ASSERTS to 0.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_ASSERT_H
#define ORBITMESH_ASSERT_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "compiler.h"
#include "config.h"

#include <stdbool.h>

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Assertion handler.
 *
 * Called whenever an assertion fails.
 *
 * @param expression Failed expression.
 * @param file Source file.
 * @param line Source line.
 * @param function Function name.
 */
OM_NORETURN
void om_assert_fail(
    const char *expression,
    const char *file,
    unsigned int line,
    const char *function);

/*==============================================================================
 * Assertions
 *============================================================================*/

#if OM_CONFIG_ENABLE_ASSERTS

#define OM_ASSERT(expr)                                                \
    do                                                                 \
    {                                                                  \
        if (OM_UNLIKELY(!(expr)))                                      \
        {                                                              \
            om_assert_fail(                                            \
                #expr,                                                 \
                __FILE__,                                              \
                __LINE__,                                              \
                __func__);                                             \
        }                                                              \
    } while (0)

#else

#define OM_ASSERT(expr) ((void)0)

#endif

/*==============================================================================
 * Convenience Assertions
 *============================================================================*/

/**
 * @brief Assert that a pointer is not NULL.
 */
#define OM_ASSERT_NOT_NULL(ptr) \
    OM_ASSERT((ptr) != NULL)

/**
 * @brief Assert that an index is within bounds.
 */
#define OM_ASSERT_INDEX(index, limit) \
    OM_ASSERT((index) < (limit))

/**
 * @brief Assert that a value is aligned.
 */
#define OM_ASSERT_ALIGNED(value, alignment) \
    OM_ASSERT((((uintptr_t)(value)) & ((alignment) - 1U)) == 0U)

/**
 * @brief Marks unreachable code.
 */
#define OM_ASSERT_UNREACHABLE() \
    OM_ASSERT(false)

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_ASSERT_H */
