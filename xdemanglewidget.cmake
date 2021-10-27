include_directories(${CMAKE_CURRENT_LIST_DIR})

include(${CMAKE_CURRENT_LIST_DIR}/../XShortcuts/xshortcuts.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../XDemangle/xdemangle.cmake)

set(XDEMANGLEWIDGET_SOURCES
    ${XSHORTCUTS_SOURCES}
    ${XDEMANGLE_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/dialogdemangle.cpp
    ${CMAKE_CURRENT_LIST_DIR}/dialogdemangle.ui
    ${CMAKE_CURRENT_LIST_DIR}/xdemanglewidget.cpp
    ${CMAKE_CURRENT_LIST_DIR}/xdemanglewidget.ui
)
