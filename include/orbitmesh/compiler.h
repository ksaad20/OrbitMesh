/**
 * @file compiler.h
 * @brief Compiler abstraction layer.
 *
 * Provides a compiler-independent interface for attributes, inlining,
 * alignment, branch prediction, and compile-time feature detection.
 *
 * This header should contain ONLY compiler-specific abstractions.
 * Generic utility macros belong in macros.h.
 *
 * Supported compilers:
 *   - GCC
 *   - Clang
 *   - Microsoft Visual C++
 *
 * Additional compiler support may be added in future releases.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_COMPILER_H
#define ORBITMESH_COMPILER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Compiler Identification
 *============================================================================*/

#if defined(__clang__)

#define OM_COMPILER_CLANG 1

#elif defined(__GNUC__)

#define OM_COMPILER_GCC 1

#elif defined(_MSC_VER)

#define OM_COMPILER_MSVC 1

#else

#define OM_COMPILER_UNKNOWN 1

#endif

/*==============================================================================
 * Function Attributes
 *============================================================================*/

#if defined(OM_COMPILER_GCC) || defined(OM_COMPILER_CLANG)

#define OM_INLINE               inline
#define OM_FORCE_INLINE         inline __attribute__((always_inline))
#define OM_NOINLINE             __attribute__((noinline))
#define OM_NORETURN             __attribute__((noreturn))
#define OM_WEAK                 __attribute__((weak))
#define OM_UNUSED               __attribute__((unused))
#define OM_PACKED               __attribute__((packed))
#define OM_ALIGNED(x)           __attribute__((aligned(x)))
#define OM_SECTION(name)        __attribute__((section(name)))

#elif defined(OM_COMPILER_MSVC)

#define OM_INLINE               __inline
#define OM_FORCE_INLINE         __forceinline
#define OM_NOINLINE             __declspec(noinline)
#define OM_NORETURN             __declspec(noreturn)
#define OM_WEAK
#define OM_UNUSED
#define OM_PACKED
#define OM_ALIGNED(x)           __declspec(align(x))
#define OM_SECTION(name)

#else

#define OM_INLINE               inline
#define OM_FORCE_INLINE         inline
#define OM_NOINLINE
#define OM_NORETURN
#define OM_WEAK
#define OM_UNUSED
#define OM_PACKED
#define OM_ALIGNED(x)
#define OM_SECTION(name)

#endif

/*==============================================================================
 * Branch Prediction
 *============================================================================*/

#if defined(OM_COMPILER_GCC) || defined(OM_COMPILER_CLANG)

#define OM_LIKELY(x)            __builtin_expect(!!(x), 1)
#define OM_UNLIKELY(x)          __builtin_expect(!!(x), 0)

#else

#define OM_LIKELY(x)            (x)
#define OM_UNLIKELY(x)          (x)

#endif

/*==============================================================================
 * Builtin Detection
 *============================================================================*/

#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

/*==============================================================================
 * Compile-Time Assertions
 *============================================================================*/

#if (__STDC_VERSION__ >= 201112L)

#define OM_STATIC_ASSERT(expr, msg) \
    _Static_assert((expr), msg)

#else

#define OM_STATIC_ASSERT(expr, msg)

#endif

/*==============================================================================
 * Compiler Memory Barrier
 *============================================================================*/

#if defined(OM_COMPILER_GCC) || defined(OM_COMPILER_CLANG)

#define OM_COMPILER_BARRIER() \
    __asm__ volatile("" ::: "memory")

#elif defined(OM_COMPILER_MSVC)

#include <intrin.h>

#define OM_COMPILER_BARRIER() \
    _ReadWriteBarrier()

#else

#define OM_COMPILER_BARRIER() \
    ((void)0)

#endif

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_COMPILER_H */
