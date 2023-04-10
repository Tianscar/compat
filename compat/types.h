#ifndef COMPAT_TYPES_H
#define COMPAT_TYPES_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
#include "windows/stddef.h"
#include "windows/inttypes.h"
#include "windows/stdbool.h"
#else
#include <stddef.h>
#include <inttypes.h>
#include <stdbool.h>
#endif

#endif //COMPAT_TYPES_H
