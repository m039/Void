cmake_minimum_required (VERSION 3.0)

project (VoidCore)

enable_testing()

set (CMAKE_CXX_STANDARD 14)

set (VoidCore_VERSION_MAJOR 1)
set (VoidCore_VERSION_MINOR 0)

add_subdirectory (src)
add_subdirectory (test)
