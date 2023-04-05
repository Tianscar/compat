/*
 * ISO C Standard:  7.16  Boolean type and values  <stdbool.h>
 */

#ifndef _MSC_VER
#error The compiler is not MSVC!
#endif

#ifndef _STDBOOL_H
#define _STDBOOL_H

#ifndef COMPAT_MSVC99
#include <stdbool.h>
#else

#ifndef __cplusplus

#ifdef __clang__
#define bool	_Bool
#else
#define bool    unsigned char
#endif
#define true	1
#define false	0

#endif /* __cplusplus */

/* Signal that all the definitions are present.  */
#define __bool_true_false_are_defined	1

#endif  /* COMPAT_MSVC99 */
#endif	/* stdbool.h */