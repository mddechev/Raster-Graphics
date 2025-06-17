cmake_minimum_required(VERSION 3.10)

project(RasterGraphics VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add all source files
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/commands/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/image/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/image/types/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/session/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/utils/*.cpp"
)


add_executable(raster_graphics ${SOURCES} ${PROJECT_SOURCE_DIR}/main.cpp)

