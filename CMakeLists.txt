cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(Whoops VERSION 1.1 LANGUAGES CXX)

# Options
OPTION(BUILD_SHARED_LIBS "Build ${PROJECT_NAME}.a rather than ${PROJECT_NAME}.so" OFF)

# -----------------------------------------------------------------------------
# Build settings
# -----------------------------------------------------------------------------

# C++ requirements
# ----------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_COLOR_MAKEFILE ON)

# Build settings
# --------------
include_directories("${CMAKE_SOURCE_DIR}")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message("-- Configuring clang options")
    set(CMAKE_CXX_FLAGS "-arch x86_64 -std=c++17 -stdlib=libc++ -DBOOST_LOG_DYN_LINK -Wno-deprecated-declarations")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    message("-- Configuring gcc options")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -DBOOST_LOG_DYN_LINK")
endif()

# -----------------------------------------------------------------------------
# Create target and set properties
# -----------------------------------------------------------------------------

# Set the library sources
# -----------------------
set(SOURCES
    src/peg.cpp
    src/board.cpp
    src/main.cpp
)

# Create the executable
# ---------------------
add_executable(${PROJECT_NAME} ${SOURCES})
