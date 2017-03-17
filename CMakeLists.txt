# Copyright (c) BBP/EPFL 2017
#                        Stefan.Eilemann@epfl.ch

cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(Extra VERSION 1.0.0)
set(Extra_VERSION_ABI 1)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

set(EXTRA_DESCRIPTION
  "C++ extensions to the std library with no additional dependencies")
set(EXTRA_MAINTAINER "Blue Brain Project <bbp-open-source@googlegroups.com>")
set(EXTRA_LICENSE LGPL BSD)
include(Extra)

find_package(Boost QUIET COMPONENTS unit_test_framework)

add_subdirectory(extra)
add_subdirectory(tests)
extra_export_project()
