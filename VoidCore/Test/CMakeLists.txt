set (TEST_FILES Main.cpp SimpleTest.cpp)

add_executable (TestVoidCore ${TEST_FILES})

target_link_libraries (TestVoidCore VoidCore)
