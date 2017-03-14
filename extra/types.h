
/* Copyright (c) 2007-2017, Stefan Eilemann <eile@equalizergraphics.com>
 *
 * This file is part of Extra <https://github.com/BlueBrain/Extra>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 2.1 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * @file lunchbox/types.h
 * Basic type definitions not provided by the standard, forward declarations of
 * Extra types.
 */

/**
 * @namespace extra
 * @brief Abstraction layer and common utilities for C++ programming.
 *
 * Extra provides C++ classes to abstract the underlying operating system and
 * to implement common utilities for multi-threaded C++ programs. It does not
 * have any requirements beyond C++11 and standard system headers.
 */

#pragma once

#include <sys/types.h>

#ifndef _MSC_VER
#include <stdint.h>
#endif

#ifdef _WIN32
#include <basetsd.h>

#ifdef _MSC_VER
typedef UINT64 uint64_t;
typedef INT64 int64_t;
typedef UINT32 uint32_t;
typedef INT32 int32_t;
typedef UINT16 uint16_t;
typedef INT16 int16_t;
typedef UINT8 uint8_t;
typedef INT8 int8_t;

#ifndef HAVE_SSIZE_T
typedef SSIZE_T ssize_t;
#define HAVE_SSIZE_T
#endif

#endif // Win32, Visual C++
#endif // Win32

namespace extra
{
class Clock;
}
