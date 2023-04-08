#ifndef COMPAT_TYPES_H
#define COMPAT_TYPES_H

#ifdef _MSC_VER
#ifndef COMPAT_TYPES
#if _MSC_VER < 0x708
#define COMPAT_TYPES 1
#endif
#endif
#endif
#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)) && defined(COMPAT_TYPES)
#include "msvc/stddef.h"
#include "msvc/inttypes.h"
#include "msvc/stdbool.h"
#else
#include <stddef.h>
#include <inttypes.h>
#include <stdbool.h>
#endif

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__))
#ifdef __GNUC__
#define COMPAT_DLL_IMPORT __attribute__((dllimport)) extern
#define COMPAT_DLL_EXPORT __attribute__((dllexport)) extern
#else
#define COMPAT_DLL_IMPORT __declspec(dllimport)
#define COMPAT_DLL_EXPORT __declspec(dllexport)
#endif
#ifdef COMPAT_BUILDING_DLL
#define COMPAT_EXPORT COMPAT_DLL_EXPORT
#else
#define COMPAT_EXPORT COMPAT_DLL_IMPORT
#endif
#elif defined(__GNUC__) && __GNUC__ >= 4
#define COMPAT_EXPORT extern __attribute__ ((visibility ("default")))
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

#ifdef __GNUC__
#define COMPAT_RESTRICT __restrict__
#elif defined(_MSC_VER)
#define COMPAT_RESTRICT __restrict
#else
#define COMPAT_RESTRICT restrict
#endif

#endif //COMPAT_TYPES_H
