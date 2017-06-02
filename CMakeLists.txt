# Copyright (c) BBP/EPFL 2017
#                        Stefan.Eilemann@epfl.ch

cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(Extra VERSION 1.0.0)
set(Extra_VERSION_ABI 1)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake
                              ${CMAKE_SOURCE_DIR}/CMake/common)
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/CMake/common/Common.cmake)
  message(FATAL_ERROR "CMake/common missing, run: git submodule update --init")
endif()

set(EXTRA_DESCRIPTION
  "C++ extensions to the std library with no additional dependencies")
set(EXTRA_MAINTAINER "Blue Brain Project <bbp-open-source@googlegroups.com>")
set(EXTRA_LICENSE LGPL BSD)

include(Common)

common_find_package(Boost QUIET COMPONENTS unit_test_framework)

common_find_package_post()
add_subdirectory(extra)
add_subdirectory(tests)

set(DOXYGEN_MAINPAGE_MD README.md)
set(DOXYGEN_EXTRA_INPUT ${PROJECT_SOURCE_DIR}/README.md)
include(DoxygenRule) # must be after all targets
include(CPackConfig)
include(CTest)
