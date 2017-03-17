
/* Copyright (c) 2005-2017, Stefan Eilemann <eile@equalizergraphics.com>
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
/** A class for time measurements. */
class Clock
{
public:
    /** Construct a new clock. @version 1.0 */
    EXTRA_API Clock();

    /** Copy-construct a new clock with the same start time . @version 1.0 */
    EXTRA_API Clock(const Clock& from);

    /** Destroy the clock. @version 1.0 */
    EXTRA_API ~Clock();

    /** Assignment operator. @version 1.7.2 */
    EXTRA_API Clock& operator=(const Clock& ref);

    /**
     * Reset the base time of the clock to the current time.
     * @version 1.0
     */
    EXTRA_API void reset();

    /** Set the current time of the clock. @version 1.0 */
    EXTRA_API void set(const int64_t time);

    /**
     * @return the elapsed time in milliseconds since the last clock reset.
     * @version 1.0
     */
    EXTRA_API float getTimef() const;

    /**
     * @return the elapsed time in milliseconds since the last clock reset
     *         and atomically reset the clock.
     * @version 1.0
     */
    EXTRA_API float resetTimef();

    /**
     * @return the elapsed time in milliseconds since the last clock reset.
     * @version 1.0
     */
    EXTRA_API int64_t getTime64() const;

    /**
     * @return the elapsed time in milliseconds since the last clock reset.
     * @version 1.0
     */
    EXTRA_API double getTimed() const;

private:
    class Impl;
    Impl* const _impl;
};
}
