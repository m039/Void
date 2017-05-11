file (GLOB TEST_FILES *.cpp *.h)

add_executable (TestVoidCore ${TEST_FILES})

include_directories(VoidCore)

target_link_libraries (TestVoidCore VoidCore ${VoidCore_LIBRARIES})
