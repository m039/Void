file(GLOB TEST_FILES *.cpp *.h)

add_executable (TestVoidCore ${TEST_FILES})

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED COMPONENTS context coroutine)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(TestVoidCore ${Boost_LIBRARIES})
endif()

target_link_libraries (TestVoidCore VoidCore)
