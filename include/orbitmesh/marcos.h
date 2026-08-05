/**
 * @file macros.h
 * @brief Common utility macros for OrbitMesh.
 *
 * This header provides compiler abstraction, utility macros, alignment helpers,
 * branch prediction hints, and compile-time assertions used throughout the
 * OrbitMesh operating system.
 *
 * This header intentionally contains no runtime code.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_MACROS_H
#define ORBITMESH_MACROS_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Standard Headers
 *============================================================================*/

#include <stddef.h>

/*==============================================================================
 * Compiler Detection
 *============================================================================*/

#if defined(__GNUC__) || defined(__clang__)

#define OM_INLINE          inline
#define OM_FORCE_INLINE    __attribute__((always_inline)) inline
#define OM_NOINLINE        __attribute__((noinline))
#define OM_NORETURN        __attribute__((noreturn))
#define OM_WEAK            __attribute__((weak))
#define OM_PACKED          __attribute__((packed))
#define OM_UNUSED          __attribute__((unused))
#define OM_LIKELY(x)       (__builtin_expect(!!(x), 1))
#define OM_UNLIKELY(x)     (__builtin_expect(!!(x), 0))

#elif defined(_MSC_VER)

#define OM_INLINE          __inline
#define OM_FORCE_INLINE    __forceinline
#define OM_NOINLINE        __declspec(noinline)
#define OM_NORETURN        __declspec(noreturn)
#define OM_WEAK
#define OM_PACKED
#define OM_UNUSED
#define OM_LIKELY(x)       (x)
#define OM_UNLIKELY(x)     (x)

#else

#define OM_INLINE          inline
#define OM_FORCE_INLINE    inline
#define OM_NOINLINE
#define OM_NORETURN
#define OM_WEAK
#define OM_PACKED
#define OM_UNUSED
#define OM_LIKELY(x)       (x)
#define OM_UNLIKELY(x)     (x)

#endif

/*==============================================================================
 * General Utilities
 *============================================================================*/

/**
 * @brief Suppress unused variable warnings.
 */
#define OM_UNUSED_VAR(x) ((void)(x))

/**
 * @brief Number of elements in a static array.
 */
#define OM_ARRAY_SIZE(array) \
    (sizeof(array) / sizeof((array)[0]))

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
 * @brief Clamp a value to a range.
 */
#define OM_CLAMP(value, minimum, maximum) \
    (OM_MIN(OM_MAX((value), (minimum)), (maximum)))

/**
 * @brief Absolute value.
 */
#define OM_ABS(value) \
    (((value) < 0) ? -(value) : (value))

/*==============================================================================
 * Alignment
 *============================================================================*/

/**
 * @brief Align a value upwards.
 */
#define OM_ALIGN_UP(value, alignment) \
    (((value) + ((alignment) - 1U)) & ~((alignment) - 1U))

/**
 * @brief Align a value downwards.
 */
#define OM_ALIGN_DOWN(value, alignment) \
    ((value) & ~((alignment) - 1U))

/**
 * @brief Test whether a value is aligned.
 */
#define OM_IS_ALIGNED(value, alignment) \
    (((value) & ((alignment) - 1U)) == 0U)

/*==============================================================================
 * Bit Operations
 *============================================================================*/

/**
 * @brief Create a bit mask.
 */
#define OM_BIT(position) \
    (1UL << (position))

/**
 * @brief Test whether a bit is set.
 */
#define OM_BIT_IS_SET(value, bit) \
    (((value) & OM_BIT(bit)) != 0UL)

/**
 * @brief Set a bit.
 */
#define OM_BIT_SET(value, bit) \
    ((value) |= OM_BIT(bit))

/**
 * @brief Clear a bit.
 */
#define OM_BIT_CLEAR(value, bit) \
    ((value) &= ~OM_BIT(bit))

/**
 * @brief Toggle a bit.
 */
#define OM_BIT_TOGGLE(value, bit) \
    ((value) ^= OM_BIT(bit))

/*==============================================================================
 * Compile-Time Assertions
 *============================================================================*/

#if __STDC_VERSION__ >= 201112L

#define OM_STATIC_ASSERT(condition, message) \
    _Static_assert((condition), message)

#else

#define OM_STATIC_ASSERT(condition, message)

#endif

/*==============================================================================
 * String Helpers
 *============================================================================*/

#define OM_STRINGIFY_IMPL(x) #x
#define OM_STRINGIFY(x) OM_STRINGIFY_IMPL(x)

/*==============================================================================
 * Version Helpers
 *============================================================================*/

#define OM_MAKE_VERSION(major, minor, patch) \
    (((major) * 10000U) + ((minor) * 100U) + (patch))

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_MACROS_H */
