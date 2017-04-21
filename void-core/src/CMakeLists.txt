file(GLOB_RECURSE LIBRARY_FILES *.cpp *.h)

add_library (VoidCore ${LIBRARY_FILES} Game/Config.h)

target_include_directories (VoidCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
