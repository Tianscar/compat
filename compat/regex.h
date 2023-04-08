#ifndef COMPAT_REGEX_H
#define COMPAT_REGEX_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
#ifdef COMPAT_BUILDING_DLL
#define BUILD_REGEX_DLL 1
#else
#define USE_REGEX_DLL 1
#endif
#include "gnuwin32/regex/regex.h"
#else
#include <regex.h>
#endif

#endif //COMPAT_REGEX_H
