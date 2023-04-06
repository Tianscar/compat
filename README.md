# Compat
A set of utilities for C99, for cross-platform compatibility.

## Usage
Copy [the files](/compat) to your project and `#include` them.

## Notes
### MSVC
#### dllexport
You need to define `COMPAT_DLLEXPORT` if you're building an executable or shared library.
#### C99
For `_MSC_VER` < 1800, `COMPAT_MSVC99` macro is automatically defined in `types.h`, to enable the C99 compatibility for MSVC.  
You can also define it manually if you don't want to link against any c runtime library except `msvcrt.dll`.  
Under the conditions above, if you want to use functions defined in `inttypes.h` (i.e. `imaxabs`), 
you need to define `COMPAT_MSVC99_TYPESFUNC` macro and add `inttypes.c` to your source file list.
#### UCRT
You need to define `COMPAT_UCRT` macro if you link your executable or library against `Microsoft Universal C Runtime (UCRT)`.

## License
[The Unlicense (Public Domain Equivalent)](/LICENSE)
