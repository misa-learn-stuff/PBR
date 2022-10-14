CMAKE_MINIMUM_REQUIRED ( VERSION 3.1.0 )

PROJECT ( PBR )

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

###########################################################################
# glog

SET(WITH_GFLAGS OFF CACHE BOOL "Use gflags")
SET(BUILD_SHARED_LIBS OFF CACHE BOOL " " FORCE)
IF(WIN32)
  ADD_DEFINITIONS( -D GOOGLE_GLOG_DLL_DECL= )
ENDIF()
ADD_SUBDIRECTORY(src/ext/glog)
SET_PROPERTY(TARGET glog logging_unittest demangle_unittest utilities_unittest stl_logging_unittest PROPERTY FOLDER "ext")
INCLUDE_DIRECTORIES (
  src/ext/glog/src
  ${CMAKE_BINARY_DIR}/src/ext/glog
)

###########################################################################
# pbr

SET ( SOURCE_CORE
  src/core/geometry.cpp
  src/core/transform.cpp
  )

SET ( HEADERS_CORE
  src/core/geometry.h
  src/core/transform.h
  )

FILE ( GLOB SOURCE
  src/cameras/*
  )

INCLUDE_DIRECTORIES ( src )
INCLUDE_DIRECTORIES ( src/core )

# Visual Studio source folders
SOURCE_GROUP (core REGULAR_EXPRESSION src/core/.*)
SOURCE_GROUP (cameras REGULAR_EXPRESSION src/cameras/.*)

###########################################################################
# pbrt libraries and executables

ADD_LIBRARY ( pbr STATIC
  ${SOURCE}
  ${SOURCE_CORE}
  ${HEADERS_CORE}
  )

SET(ALL_PBR_LIBS
  pbr
  glog
)

# Main renderer
ADD_EXECUTABLE ( pbr_exe src/main/pbr.cpp )

SET_TARGET_PROPERTIES ( pbr_exe PROPERTIES OUTPUT_NAME pbr )
TARGET_LINK_LIBRARIES ( pbr_exe ${ALL_PBR_LIBS} )

# Unit test

FILE ( GLOB SOURCE_TEST
  src/tests/*.cpp
  src/tests/gtest/*.cc
  )

ADD_EXECUTABLE ( pbr_test ${SOURCE_TEST} )
TARGET_LINK_LIBRARIES ( pbr_test ${ALL_PBR_LIBS} )

ADD_TEST ( pbr_unit_test pbr_test )
