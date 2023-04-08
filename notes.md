.a - static lib

.bin - binary file at offset 0 - https://stackoverflow.com/questions/2427011/what-is-the-difference-between-elf-files-and-bin-file

ELF - Executable and Linkable Format - a common standard file format for executable files, object code, shared 
  libraries, and core dumps.

linker

Mach-O - a file format for executables, object code, shared libraries, dynamically-loaded code, and core dumps. 
  It was developed to replace the a.out format.

Mach - an OS kernel developed at Carnegie Mellon University by Richard Rashid and Avie Tevanian to support operating 
  system research, primarily distributed and parallel computing. Whilst considered one of the earliest examples of a 
  microkernel, not all versions of Mach are microkernels. Derivatives include GNU Hurd and Apple's XNU kernel used in 
  macOS, iOS, iPadOS, tvOS, watchOS and NeXTSTEP.


shared / static libraries

shared libraries - https://stackoverflow.com/questions/2649334/difference-between-static-and-shared-libraries
.so      - linux
.dll     - windows
.dylib   - macos

static libraries
.a       - linux, macos
.lib     - windows

shared libraries - smaller executable size at a systems level, run-time loading cost, replaceable, small additional 
  calling cost \
static libraries - larger executable size, no load cost, not replaceable, no extra calling cost, complier doesn't 
  need to use whole library - can pick and mix


.sys - https://en.wikipedia.org/wiki/.sys

systems language - short for operating systems language





nm jinni.dylib to see all exported symbols (defaults to alphabetical, use -m to see in order of definition)

put dylib in /Users/<user_name>/Library/Group Containers/UBF8T346G9.Office


build with `gcc -dynamiclib -o jinni.dylib jinni.c`





The gcc -shared and gcc -dynamic options both generate shared libraries, but they use different mechanisms for resolving symbol references at runtime.

The -shared option creates a shared library that uses the traditional Unix symbol resolution mechanism. When a shared library is loaded, the dynamic linker searches for unresolved symbols in the library and its dependencies, and resolves them at runtime. This means that the library's symbols are resolved dynamically at runtime, and the library can be used by any program that depends on it.

The -dynamic option, on the other hand, creates a shared library that uses the dynamic symbol resolution mechanism. This means that the library's symbols are resolved at load time, and the library can only be used by programs that are linked against the library's exports. This is similar to how dynamic libraries work on Windows.

In general, the -shared option is more widely supported and is the recommended option for creating shared libraries on Unix-like systems, including macOS. The -dynamic option is less commonly used and is not supported on all platforms.



he gcc -dynamic and gcc -dynamiclib options are used to generate dynamically linked shared libraries in macOS, but they have some differences in how they are used.

The -dynamic option creates a dynamic shared library that is intended to be linked directly with a program at link time. When a program is linked with a dynamic library using -dynamic, the linker creates a reference to the dynamic library in the program's binary, and the dynamic library is loaded into memory when the program is executed.

The -dynamiclib option, on the other hand, creates a dynamic shared library that is intended to be loaded at runtime using the dlopen function. This allows the library to be loaded and unloaded dynamically, which can be useful in certain situations.

In general, if you are creating a shared library that you want to link directly with a program at link time, you should use the -dynamic option. If you are creating a shared library that you want to load at runtime using dlopen, you should use the -dynamiclib option.




On macOS, the gcc -shared and gcc -dynamiclib options are both used to generate dynamically linked shared libraries, but they have some differences in how they are used.

The -shared option creates a shared library that is intended to be used on Unix-like systems, including macOS and Linux. The library can be linked with a program at link time using the -l option, or it can be loaded at runtime using the dlopen function.

The -dynamiclib option, on the other hand, is specific to macOS and is used to create dynamic shared libraries that are intended to be loaded at runtime using the dlopen function. Unlike shared libraries created with the -shared option, a dynamic library created with -dynamiclib will have a .dylib file extension instead of a .so extension.

In general, if you are creating a shared library that you want to use on multiple platforms, including macOS and Linux, you should use the -shared option. If you are creating a shared library that is specific to macOS and you want to load it dynamically using dlopen, you should use the -dynamiclib option.



https://github.com/wine-mirror/wine \
https://github.com/wine-mirror/wine/blob/master/dlls/oleaut32/tests/safearray.c \
https://wiki.winehq.org/Download \
https://gitlab.winehq.org/wine/wine \
https://stackoverflow.com/questions/18784470/where-is-safearray-var-type-stored


