/*
 * ISO C Standard:  7.16  Boolean type and values  <stdbool.h>
 */

#ifndef _STDBOOL_H
#define _STDBOOL_H

#if _MSC_VER >= 1800
/* MSVC >= 2013 has stdbool.h  */
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

#endif  /* _MSC_VER */
#endif	/* stdbool.h */