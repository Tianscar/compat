#ifdef COMPAT_INTTYPES_FUNCTIONS

#include <stdlib.h>
#include <wchar.h>
#include <assert.h>

#include "inttypes.h"

intmax_t __cdecl imaxabs (intmax_t j) {
    return j >= 0 ? j : -j;
}
imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom) {
    imaxdiv_t result;

    result.quot = numer / denom;
    result.rem = numer % denom;

    /* Verify the requirements of ISO C 99 section 6.5.5 paragraph 6:
     "When integers are divided, the result of the / operator is the
      algebraic quotient with any fractional part discarded.  (This is
      often called "truncation toward zero".)  If the quotient a/b is
      representable, the expression (a/b)*b + a%b shall equal a."  */
    if (!(denom == 0
          || (INTMAX_MIN + INTMAX_MAX < 0
              && denom == -1
              && numer < - INTMAX_MAX)))
    {
        if (!(result.quot * denom + result.rem == numer))
            /* The compiler's implementation of / and % is broken.  */
            abort ();
        if (!(numer >= 0
              ? result.rem >= 0
                && (denom >= 0
                    ? result.rem < denom
                    : /* Don't write  result.rem < - denom,
                       as it gives integer overflow if denom == INTMAX_MIN.  */
                    - result.rem > denom)
              : result.rem <= 0
                && (denom >= 0
                    ? result.rem > - denom
                    : result.rem > denom)))
            /* The compiler's implementation of / and % may be ok according to
               C89, but not to C99.  Please report this to <bug-gnulib@ngu.org>.
               This might be a big portability problem.  */
            abort ();
    }

    return result;
}

/* 7.8.2 Conversion functions for greatest-width integer types */

intmax_t __cdecl strtoimax (const char* __restrict nptr,
                    char** __restrict endptr, int base) {
    assert (sizeof (intmax_t) == sizeof (unsigned long int) || sizeof (intmax_t) == sizeof (unsigned long long int));

    if (sizeof (intmax_t) != sizeof (unsigned long int)) return strtoll(nptr, endptr, base);
    return strtol(nptr, endptr, base);
}
uintmax_t __cdecl strtoumax (const char* __restrict nptr,
                     char** __restrict endptr, int base) {
    assert (sizeof (uintmax_t) == sizeof (unsigned long int) || sizeof (uintmax_t) == sizeof (unsigned long long int));

    if (sizeof (uintmax_t) != sizeof (unsigned long int)) return strtoull(nptr, endptr, base);
    return strtoul(nptr, endptr, base);
}

intmax_t __cdecl wcstoimax (const wchar_t* __restrict nptr,
                    wchar_t** __restrict endptr, int base) {
    assert (sizeof (intmax_t) == sizeof (unsigned long int) || sizeof (intmax_t) == sizeof (unsigned long long int));

    if (sizeof (intmax_t) != sizeof (unsigned long int)) return wcstoll(nptr, endptr, base);
    return wcstol(nptr, endptr, base);
}
uintmax_t __cdecl wcstoumax (const wchar_t* __restrict nptr,
                     wchar_t** __restrict endptr, int base) {
    assert (sizeof (uintmax_t) == sizeof (unsigned long int) || sizeof (uintmax_t) == sizeof (unsigned long long int));

    if (sizeof (uintmax_t) != sizeof (unsigned long int)) return wcstoull(nptr, endptr, base);
    return wcstoul(nptr, endptr, base);
}

#endif