CMAKE_MINIMUM_REQUIRED ( VERSION 3.1.0 )

PROJECT ( PBR )

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

SET ( SOURCE_CORE
  src/core/transform.cpp
  )

SET ( HEADERS_CORE
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

ADD_LIBRARY ( pbr STATIC
  ${SOURCE}
  ${SOURCE_CORE}
  ${HEADERS_CORE}
  )

SET(ALL_PBRT_LIBS
  pbr
)

# Main renderer
ADD_EXECUTABLE ( pbr_exe src/main/pbr.cpp )

SET_TARGET_PROPERTIES ( pbr_exe PROPERTIES OUTPUT_NAME pbr )
TARGET_LINK_LIBRARIES ( pbr_exe ${ALL_PBRT_LIBS} )

