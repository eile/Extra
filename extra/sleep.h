
/* Copyright (c) 2008-2017, Stefan Eilemann <eile@equalizergraphics.com>
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

#include <extra/api.h>
#include <extra/types.h>

namespace extra
{
/**
 * Sleep the current thread for a number of milliseconds.
 * @version 1.0
 * @deprecated Use boost::this_thread::sleep()
 */
EXTRA_API void sleep(const uint32_t milliSeconds);
}
