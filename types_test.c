#include <stdio.h>

#include "compat/types.h"

COMPAT_EXPORT void export_function() {
    printf("COMPAT_EXPORT working!\n");
}

COMPAT_EXTERN void extern_function() {
    printf("COMPAT_EXTERN working!\n");
}

COMPAT_INLINE void inline_function() {
    printf("COMPAT_INLINE working!\n");
}

int main() {
    export_function();
    extern_function();
    inline_function();
    printf("true: %d\n", true);
    printf("false: %d\n", false);
    return 0;
}
