#ifndef COMPAT_REGEX_H
#define COMPAT_REGEX_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)

#else
#include <regex.h>
#endif

#endif //COMPAT_REGEX_H
