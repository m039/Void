cmake_minimum_required (VERSION 3.0)

project (VoidCore)

enable_testing()

set (CMAKE_CXX_STANDARD 14)

set (VoidCore_VERSION_MAJOR 1)
set (VoidCore_VERSION_MINOR 0)

# Boost
set (Boost_NO_SYSTEM_PATHS TRUE)
if (Boost_NO_SYSTEM_PATHS)
    set (BOOST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../third-party/void-boost)

    if (APPLE)
        set (BOOST_LIBRARYDIR ${CMAKE_CURRENT_SOURCE_DIR}/../precompiled/lib/macosx)
    endif()
endif()

set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.64.0 COMPONENTS context REQUIRED)

if(Boost_FOUND)
    list(APPEND VoidCore_LIBRARIES ${Boost_LIBRARIES})
endif()

include_directories(${Boost_INCLUDE_DIRS})

# Include third party headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../third-party/include)

add_subdirectory (src)
add_subdirectory (test)
