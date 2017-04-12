cmake_minimum_required (VERSION 3.0 FATAL_ERROR)

project (VoidCinder)

set (CMAKE_CXX_STANDARD 14)

set (VoidCinder_VERSION_MAJOR 1)
set (VoidCinder_VERSION_MINOR 0)

add_subdirectory (void-core)
add_subdirectory (void-app)
