#ifndef COMPAT_TYPES_H
#define COMPAT_TYPES_H

#ifdef _MSC_VER
#ifndef COMPAT_MSVC99
#if _MSC_VER < 0x0708
#define COMPAT_MSVC99 1
#endif
#endif
#endif
#ifdef COMPAT_MSVC99
#include "msvc/stddef.h"
#include "msvc/inttypes.h"
#include "msvc/stdbool.h"
#else
#include <stddef.h>
#include <inttypes.h>
#include <stdbool.h>
#endif

#if defined(__GNUC__) && __GNUC__ >= 4
#define COMPAT_EXPORT extern __attribute__ ((visibility ("default")))
#elif defined(_MSC_VER)
#ifdef COMPAT_DLLEXPORT
#define COMPAT_EXPORT __declspec(dllexport)
#else
#define COMPAT_EXPORT __declspec(dllimport)
#endif
#else
#define COMPAT_EXPORT extern
#endif

#if defined(__GNUC__) && __GNUC__ >= 4
#define COMPAT_EXTERN extern __attribute__ ((visibility ("hidden")))
#else
#define COMPAT_EXTERN extern
#endif

#ifdef _MSC_VER
#define COMPAT_INLINE __forceinline
#elif defined(__cplusplus) || !defined(__STRICT_ANSI__) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)
#define COMPAT_INLINE inline static
#elif defined(__GNUC__)
#define COMPAT_INLINE __inline__ static
#elif
#define COMPAT_INLINE static
#endif

#endif //COMPAT_TYPES_H
