
/* Copyright (c) 2010-2017, Stefan Eilemann <eile@equalizergraphics.com>
 *                          Daniel Nachbaur <danielnachbaur@gmail.com>
 *
 * This file is part of Extra <https://github.com/BlueBrain/Extra>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of Eyescale Software GmbH nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <extra/Clock.h>
#include <extra/MTQueue.h>
#include <iostream>
#include <thread>

#define BOOST_TEST_MODULE MTQueue
#include <boost/test/unit_test.hpp>

#define NOPS 100000
#define NTHREADS 4

extra::MTQueue<uint64_t> queue;
extra::MTQueue<uint64_t>::Group group(NTHREADS + 1);

#ifdef LB_GCC_4_6_OR_LATER
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
static void read()
{
    uint64_t item = 0xffffffffffffffffull;
#ifndef NDEBUG
    uint64_t last = 0;
#endif
    while (queue.popBarrier(item, group))
    {
#ifndef NDEBUG
        BOOST_CHECK_LT(last, item);
        last = item;
#endif
    }
    BOOST_CHECK(queue.isEmpty());
}

BOOST_AUTO_TEST_CASE(perf)
{
    std::vector<std::thread> readers;
    while (readers.size() < NTHREADS)
        readers.emplace_back(std::thread([] { read(); }));

    extra::Clock clock;
    for (size_t i = 1; i < NOPS; ++i)
        queue.push(i);
    const float time = clock.getTimef();

    read();

    for (size_t i = 0; i < NTHREADS; ++i)
        readers[i].join();

    std::cout << NOPS / time << " writes/ms" << std::endl;
}
