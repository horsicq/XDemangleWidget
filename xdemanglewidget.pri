INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

FORMS += \
    $$PWD/dialogdemangle.ui \
    $$PWD/xdemanglewidget.ui

HEADERS += \
    $$PWD/dialogdemangle.h \
    $$PWD/xdemanglewidget.h

SOURCES += \
    $$PWD/dialogdemangle.cpp \
    $$PWD/xdemanglewidget.cpp

!contains(XCONFIG, xshortcuts) {
    XCONFIG += xshortcuts
    include($$PWD/../XShortcuts/xshortcuts.pri)
}

!contains(XCONFIG, xdemangle) {
    XCONFIG += xdemangle
    include($$PWD/../XDemangle/xdemangle.pri)
}
