get_filename_component (CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../Third-Party/Cinder/" ABSOLUTE)
get_filename_component (APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)

set (FILES ${APP_PATH}/src/VoidApp.cpp)

include ("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

ci_make_app (
        APP_NAME    VoidCinder
        SOURCES     ${FILES}
        CINDER_PATH ${CINDER_PATH}
)

if (APPLE)
    set_target_properties(VoidCinder PROPERTIES
            OUTPUT_NAME CMake
            MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/resources/Info.plist.in"
            )
endif()
