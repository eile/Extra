# Copyright (c) BBP/EPFL 2017
#                        Stefan.Eilemann@epfl.ch
# Change this number when adding tests to force a CMake run: 0
include(InstallFiles)

set(TEST_LIBRARIES Extra ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
include(CommonCTest)
install_files(share/Extra/tests FILES ${TEST_FILES} COMPONENT examples)
