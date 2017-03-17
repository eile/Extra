# Copyright (c) BBP/EPFL 2017
#                        Stefan.Eilemann@epfl.ch

extra_library(Extra
  PUBLIC_HEADERS
    Clock.h
    MTQueue.h
    MTQueue.ipp
    sleep.h
    time.h
    types.h
  SOURCES
    Clock.cpp
    sleep.cpp
  )
