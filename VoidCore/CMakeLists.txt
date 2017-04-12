cmake_minimum_required (VERSION 3.0)

project (VoidCore)

enable_testing()

set (CMAKE_CXX_STANDARD 14)

set (VoidCinder_VERSION_MAJOR 1)
set (VoidCinder_VERSION_MINOR 0)

add_subdirectory (Source)
add_subdirectory (Test)
