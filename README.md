This is a standalone version of libbacktrace.

libbacktrace prints stack traces.

libbacktrace was originally writen by Ian Lance Taylor as part of GCC.

Building libbacktrace requires CMake.

    mkdir build
    cd build/
    cmake -G'Unix Makefiles' -DENABLE_LIBBACKTRACE_TEST=true -DBACKTRACE_SUPPORTS_DATA=true path/to/libbacktrace/source
    make

How to run the tests:

    ctest
