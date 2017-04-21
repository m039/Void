file(GLOB TEST_FILES *.cpp *.h)

add_executable (TestVoidCore ${TEST_FILES})

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.64.0 COMPONENTS context REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(TestVoidCore ${Boost_LIBRARIES})
endif()

target_link_libraries (TestVoidCore VoidCore)
