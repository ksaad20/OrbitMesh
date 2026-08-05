#ifndef ORBITMESH_MACROS_H
#define ORBITMESH_MACROS_H

#ifdef __cplusplus
extern "C" {
#endif

#define OM_ARRAY_SIZE(x) \
    (sizeof(x) / sizeof((x)[0]))

#define OM_MIN(a, b) \
    (((a) < (b)) ? (a) : (b))

#define OM_MAX(a, b) \
    (((a) > (b)) ? (a) : (b))

#define OM_CLAMP(v, lo, hi) \
    (OM_MIN(OM_MAX((v), (lo)), (hi)))

#define OM_ALIGN_UP(value, alignment) \
    (((value) + ((alignment) - 1U)) & ~((alignment) - 1U))

#define OM_ALIGN_DOWN(value, alignment) \
    ((value) & ~((alignment) - 1U))

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_MACROS_H */
