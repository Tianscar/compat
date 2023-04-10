# Compat
A set of utilities for C99, for cross-platform compatibility.  
Targeting compilers: GCC/MinGW (POSIX/Windows), Clang (POSIX and Windows), MSVC (Windows).

## Usage
Copy [the files](/compat) to your project and `#include` them. `#include` [compat.h](/compat/compat.h) to include all of them.  
Do not forget to reading the [notes](#notes-for-windows) below if you're developing for Windows!

## Notes for Windows
For building external libraries (if required), see [tests](/CMakeLists.txt) as reference.
### dllexport
You need to define `COMPAT_BUILDING_DLL` macro if you're building an executable or shared library.
### RegExp
If you want to use [regex.h](/compat/regex.h), you need to build 
either [libgnurx](/compat/windows/gnurx) (LGPL-2.1) or [libregex](/compat/windows/regex) (MIT and BSD 2-Clause)
and link to your executable or library.
### C11 threads emulation
If you want to use [threads.h](/compat/threads.h), you need to build [c11threads](/compat/windows/threads) (Public Domain) and link to your executable or library, 
unless you're using win-pthread which you need to define `COMPAT_WINPTHREAD` macro.
### C99 standard types
For MSVC `_MSC_VER` < 1800, the [headers](/compat/windows) for C99 standard types compatibility are force used.  
You can also define `COMPAT_TYPES` macro to use them if you don't want to link against any c runtime library except `msvcrt.dll`.

## License
[The Unlicense (Public Domain Equivalent)](/LICENSE)
