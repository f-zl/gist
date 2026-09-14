# Win32Utf8

A little library that makes a C/C++ program's standard library APIs work with UTF-8 string on Windows

It can work just by linking against this object library, no header or explicit function call is needed

## How does it work

Many Win32 APIs have -W and -A variants, like WriteConsoleW and WriteConsoleA. -W APIs use `wchar_t` strings with UTF-16 encoding. -A APIs use `char` strings with encoding specified by code pages

Many standary library APIs use -A APIs (printf, fopen, std::cout, std::fstream may use WriteConsoleA, CreateFileA, etc). In order to make these APIs work with UTF-8 `char` strings, we need to set code pages to UTF-8 (65001)

To set the code pages programmatically:

- stdout: use `SetConsoleOutputCP(CP_UTF8)`
- stdin: use `SetConsoleCP(CP_UTF8)`
- argv: use [application manifests][1]
- env: use application manifests
- file system: use application manifests

How to do this just by linking against a library:
- use a C++ global object's constructor to automatically execute functions
- use a resource file (.rc) to embed an application manifest that sets the active code page

This library should be linked as an object, not as a static/dynamic library

## Note

Encoding of string literals in an executable has nothing to do with the OS\
It depends on source file encoding and compiler options

C and C++ string literals like `u8"Hi世界"` uses UTF-8 encoding. The type of the literal is `char8_t [N]` (`char [N]` before C23)

To create UTF-8 encoded `char` string like `"Hi世界"`, use `gcc -fexec-charset=UTF-8` (default) or MSVC `cl /utf8`

Use application manifest to set active code page requires Windows version 1903 (May 2019). GDI functions still use system locale, not necessarily UTF-8 encoding

Windows uses UTF-16 internally, therefore -A APIs that work with UTF-8 still have encoding conversion cost. They don't provide best performance

This library changes code page when the program starts. It doesn't change code page back when the program finishes. If desired, the destructor of `Win32Utf8` can be used for that

[1]: https://learn.microsoft.com/en-us/windows/apps/design/globalizing/use-utf8-code-page
