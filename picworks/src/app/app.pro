# -------------------------------------------------
# PicWorks
# Main application file
# by Galaxy.org
# 2009-9-5
# -------------------------------------------------
TARGET = PicWorks
TEMPLATE = app
QT *= network
CONFIG += precompile_header
PRECOMPILED_HEADER = pch.h
precompile_header:!isEmpty(PRECOMPILED_HEADER):DEFINES += USING_PCH
SOURCES += main.cpp
INCLUDEPATH += ../share/qtsingleapplication \
    ../ui \
    ../core
include(../config.pri)
CONFIG(debug, debug|release) { 
    LIBS += -L../../lib \
        -lQtSolutions_SingleApplication-2.6d \
        -luid \
        -lcored
    UI_DIR = ../../debug/ui
    MOC_DIR = ../../debug/moc
    OBJECTS_DIR = ../../debug/obj
    RCC_DIR = ../../debug/rcc
    DESTDIR = ../../debug
}
CONFIG(release, debug|release) { 
    LIBS += -L../../lib \
        -lQtSolutions_SingleApplication-2.6 \
        -lui \
        -lcore
    UI_DIR = ../../release/ui
    MOC_DIR = ../../release/moc
    OBJECTS_DIR = ../../release/obj
    RCC_DIR = ../../release/rcc
    DESTDIR = ../../release
}
# platform-specific
win32 {
    # executable icon
    RC_FILE += ../../res/pw.rc
}
# i18n
TRANSLATIONS += resources/locale/pw_zh_CN.ts
