**UPDATE:** Ian Lance Taylor has now made a standalone version of his excellent libbacktrace available on GitHub! It is available here: https://github.com/ianlancetaylor/libbacktrace

**Please use ILT's repository.** The only reason why you may find the current repository valuable is it uses CMake while TLT's repository uses automake/autoconf.

This is a standalone version of libbacktrace.

libbacktrace prints stack traces.

libbacktrace was originally writen by Ian Lance Taylor as part of GCC.

Building libbacktrace requires CMake.

How to build with ninja:

    mkdir build
    cd build/
    cmake -GNinja -DENABLE_LIBBACKTRACE_TEST=true path/to/libbacktrace/source
    ninja

How to build with make:

    mkdir build
    cd build/
    cmake -G'Unix Makefiles' -DENABLE_LIBBACKTRACE_TEST=true path/to/libbacktrace/source
    make

How to run the tests:

    ctest
