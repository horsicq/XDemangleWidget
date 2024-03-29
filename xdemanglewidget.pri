INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/dialogdemangle.h \
    $$PWD/xdemanglewidget.h

SOURCES += \
    $$PWD/dialogdemangle.cpp \
    $$PWD/xdemanglewidget.cpp

FORMS += \
    $$PWD/dialogdemangle.ui \
    $$PWD/xdemanglewidget.ui

!contains(XCONFIG, xshortcuts) {
    XCONFIG += xshortcuts
    include($$PWD/../XShortcuts/xshortcuts.pri)
}

!contains(XCONFIG, xdemangle) {
    XCONFIG += xdemangle
    include($$PWD/../XDemangle/xdemangle.pri)
}

DISTFILES += \
    $$PWD/LICENSE \
    $$PWD/README.md \
    $$PWD/xdemanglewidget.cmake
