# Copyright (c) BBP/EPFL 2017
#                        Stefan.Eilemann@epfl.ch

extra_library(Extra
  PUBLIC_HEADERS
    clock.h
    mtQueue.h
    mtQueue.ipp
    sleep.h
    time.h
    types.h
  SOURCES
    clock.cpp
    sleep.cpp
  )
