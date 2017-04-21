cmake_minimum_required (VERSION 3.0 FATAL_ERROR)

project (VoidCinder)

set (CMAKE_CXX_STANDARD 14)

# Boost
set (Boost_NO_SYSTEM_PATHS TRUE)
if (Boost_NO_SYSTEM_PATHS)
    set (BOOST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/third-party/void-boost)

    if (APPLE)
        set (BOOST_LIBRARYDIR ${CMAKE_CURRENT_SOURCE_DIR}/precompiled/lib/macosx)
    endif()
endif()

set (VoidCinder_VERSION_MAJOR 1)
set (VoidCinder_VERSION_MINOR 0)

add_subdirectory (void-core)
add_subdirectory (void-app)
