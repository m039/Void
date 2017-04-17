get_filename_component (CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../Third-Party/libCinder/" ABSOLUTE)
get_filename_component (APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)

set (FILES ${APP_PATH}/src/CubeApp.cpp)

include ("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

ci_make_app (
        APP_NAME    "VoidCinder"
        SOURCES     ${FILES}
        CINDER_PATH ${CINDER_PATH}
)
