
/* Copyright (c) 2012-2017, Stefan Eilemann <eile@eyescale.ch>
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

#pragma once
#ifndef _MSC_VER

#include <extra/types.h>
#include <time.h>

namespace extra
{
/** @internal @return a millisecond time as a unix timespec. */
inline timespec convertToTimespec(const uint32_t milliSeconds)
{
    timespec ts = {0, 0};
    ts.tv_sec = static_cast<int>(milliSeconds / 1000);
    ts.tv_nsec = (milliSeconds - ts.tv_sec * 1000) * 1000000;
    return ts;
}
}
#endif
