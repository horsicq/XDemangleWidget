include_directories(${CMAKE_CURRENT_LIST_DIR})

if (NOT DEFINED XDEMANGLE_SOURCES)
    include(${CMAKE_CURRENT_LIST_DIR}/../XDemangle/xdemangle.cmake)
    set(XDEMANGLEWIDGET_SOURCES ${XDEMANGLEWIDGET_SOURCES} ${XDEMANGLE_SOURCES})
endif()

include(${CMAKE_CURRENT_LIST_DIR}/../XShortcuts/xshortcuts.cmake)

set(XDEMANGLEWIDGET_SOURCES
    ${XDEMANGLEWIDGET_SOURCES}
    ${XDEMANGLE_SOURCES}
    ${XSHORTCUTS_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/dialogdemangle.cpp
    ${CMAKE_CURRENT_LIST_DIR}/dialogdemangle.h
    ${CMAKE_CURRENT_LIST_DIR}/dialogdemangle.ui
    ${CMAKE_CURRENT_LIST_DIR}/xdemanglewidget.cpp
    ${CMAKE_CURRENT_LIST_DIR}/xdemanglewidget.h
    ${CMAKE_CURRENT_LIST_DIR}/xdemanglewidget.ui
)
