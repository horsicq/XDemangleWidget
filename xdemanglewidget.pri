INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

FORMS += \
    $$PWD/xdemanglewidget.ui

HEADERS += \
    $$PWD/xdemanglewidget.h

SOURCES += \
    $$PWD/xdemanglewidget.cpp

!contains(XCONFIG, xshortcuts) {
    XCONFIG += xshortcuts
    include($$PWD/../XShortcuts/xshortcuts.pri)
}
