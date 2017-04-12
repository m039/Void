set (LIBRARY_FILES VoidCore.cpp)

add_library (VoidCore ${LIBRARY_FILES})

target_include_directories (VoidCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
