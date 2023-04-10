#include <stdio.h>

#include "compat/defs.h"

COMPAT_EXPORT void export_function() {
    printf("COMPAT_EXPORT working!\n");
}

COMPAT_EXTERN void extern_function() {
    printf("COMPAT_EXTERN working!\n");
}

COMPAT_FORCEINLINE void inline_function() {
    printf("COMPAT_FORCEINLINE working!\n");
}

int main() {
    export_function();
    extern_function();
    inline_function();
    return 0;
}
