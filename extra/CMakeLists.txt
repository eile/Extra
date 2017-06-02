# Copyright (c) BBP/EPFL 2017
#                        Stefan.Eilemann@epfl.ch

set(EXTRA_PUBLIC_HEADERS
  Clock.h
  MTQueue.h
  MTQueue.ipp
  sleep.h
  time.h
  types.h
)

set(EXTRA_SOURCES
  Clock.cpp
  sleep.cpp
)

common_library(Extra)
