get_filename_component (CINDER_PATH "${THIRD_PARTY_PATH}/Cinder/" ABSOLUTE)
get_filename_component (APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)

file (GLOB_RECURSE FILES "${APP_PATH}/src/*.cpp" "${APP_PATH}/src/*.h")

include ("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

include_directories (${THIRD_PARTY_PATH}/gainput/lib/include)

add_definitions(-DSUPPORT_GAMEPADS)

ci_make_app (
        APP_NAME    VoidCinder
        SOURCES     ${FILES}
        CINDER_PATH ${CINDER_PATH}
        LIBRARIES	VoidCore
					${VoidCore_LIBRARIES}
					${PRECOMPILED_PATH}/libgainputstatic.a
)

if (APPLE)
	set_target_properties (
			VoidCinder
			PROPERTIES
			OUTPUT_NAME CMake
			MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/resources/macosx/Info.plist.in"
	)
elseif (UNIX)
	target_link_libraries (VoidCinder VoidCore X11)
endif()
