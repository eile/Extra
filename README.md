# Extra

C++ extensions to the std library with no additional dependencies

## Features

Hello provides the following functionality:
*

## Building from Source

Extra is a cross-platform library, designed to run on any modern
operating system, including all Unix variants and the Windows operating
system. It requires a C++11 compiler and uses CMake to create a
platform-specific build environment. The following platforms and build
environments are tested:

* Linux: Ubuntu 16.04, RHEL 6.8 (Makefile, Ninja)
* Windows: 7 (Visual Studio 2012)
* Mac OS X: 10.9 (Makefile, Ninja)

Building from source is as simple as:

    git clone https://github.com/BlueBrain/Extra.git
    mkdir Extra/build
    cd Extra/build
    cmake -GNinja ..
    ninja
