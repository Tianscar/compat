# Compat
A set of utilities for C99, for cross-platform compatibility.

## Usage
Copy [the files](/compat) to your project and `#include` them. `#include` [compat.h](compat/compat.h) to include all of them.  
Do not forget to reading the [Notes](#notes) below!

## Notes
### Windows
#### dllexport
You need to define `COMPAT_BUILDING_DLL` macro if you're building an executable or shared library.
#### UCRT
You need to define `COMPAT_UCRT` macro if you're linking your executable or library against [Universal C Runtime (UCRT)](https://learn.microsoft.com/en-us/cpp/windows/universal-crt-deployment).
#### RegExp
If you want to use [regex.h](/compat/regex.h), you need to build [gnuwin32/regex](/compat/gnuwin32/regex) and link to your executable or library. (Remember GnuWin32's license is LGPL-2.1!)
### MSVC
#### C99 standard types
For `_MSC_VER` < 1800, `COMPAT_TYPES` macro is automatically defined in [types.h](/compat/types.h), to enable the C99 standard types compatibility for MSVC.  
You can also define it manually if you don't want to link against any c runtime library except `msvcrt.dll`.  
Under the conditions above, if you want to use functions defined in [inttypes.h](/compat/msvc/inttypes.h) (e.g. `imaxabs`),
you need to define `COMPAT_INTTYPES_FUNCTIONS` macro and add [inttypes.c](/compat/msvc/inttypes.c) to your source file list.

## License
[The Unlicense (Public Domain Equivalent)](/LICENSE)
