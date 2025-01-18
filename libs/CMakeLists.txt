cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(yaya_arithmetic_libs)

include(FetchContent)

if(NOT TARGET yaya_macro)
    FetchContent_Declare(c_lib_macro
      GIT_REPOSITORY "https://github.com/seityaya/c_lib_macro.git"
      GIT_TAG "origin/master"
      SOURCE_DIR "${CMAKE_SOURCE_DIR}/libs/c_lib_macro"
    )
    FetchContent_MakeAvailable(c_lib_macro)
else()
    add_subdirectory(${CMAKE_SOURCE_DIR}/libs/c_lib_macro)
endif()

if(NOT TARGET yaya_testing)
    FetchContent_Declare(c_lib_testing
      GIT_REPOSITORY "https://github.com/seityaya/c_lib_testing.git"
      GIT_TAG "origin/master"
      SOURCE_DIR "${CMAKE_SOURCE_DIR}/libs/c_lib_testing"
    )
    FetchContent_MakeAvailable(c_lib_testing)
else()
    add_subdirectory(${CMAKE_SOURCE_DIR}/libs/c_lib_testing)
endif()
