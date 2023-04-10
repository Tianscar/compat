#ifndef COMPAT_DEFS_H
#define COMPAT_DEFS_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
#ifdef __GNUC__
#define COMPAT_DLLIMPORT __attribute__ ((dllimport)) extern
#define COMPAT_DLLEXPORT __attribute__ ((dllexport)) extern
#else
#define COMPAT_DLLIMPORT __declspec (dllimport)
#define COMPAT_DLLEXPORT __declspec (dllexport)
#endif
#ifdef COMPAT_BUILDING_DLL
#define COMPAT_EXPORT COMPAT_DLLEXPORT
#else
#define COMPAT_EXPORT COMPAT_DLLIMPORT
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
#define COMPAT_INLINE __inline
#elif defined(__cplusplus) || __STDC_VERSION__ >= 199901L
#define COMPAT_INLINE inline
#elif defined(__GNUC__)
#define COMPAT_INLINE __inline__
#else
#define COMPAT_INLINE
#endif

#ifdef _MSC_VER
#define COMPAT_FORCEINLINE __forceinline
#elif defined(__GNUC__)
#define COMPAT_FORCEINLINE inline static __attribute__ ((always_inline))
#elif
#define COMPAT_FORCEINLINE inline static
#endif

#ifdef __GNUC__
#define COMPAT_RESTRICT __restrict__
#elif defined(_MSC_VER)
#define COMPAT_RESTRICT __restrict
#else
#define COMPAT_RESTRICT restrict
#endif

#ifdef _MSC_VER
#define COMPAT_NORETURN __declspec (noreturn)
#elif defined(__GNUC__) && (__GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 5))
#define COMPAT_NORETURN __attribute__ ((noreturn))
#else
#define COMPAT_NORETURN
#endif

#endif //COMPAT_DEFS_H
