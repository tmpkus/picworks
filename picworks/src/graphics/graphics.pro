# -------------------------------------------------
# PicWorks Graphics
# Subproject file
# by Galaxy.org
# 2010-5-15
# -------------------------------------------------
TARGET = graphics
TEMPLATE = lib
DEFINES += GRAPHICS_LIBRARY

include(../config.pri)
CONFIG(debug, debug|release) {
    mac:TARGET = $$join(TARGET,,,_debug)
    win32:TARGET = $$join(TARGET,,,d)
    UI_DIR = ../../lib/debug/ui
    MOC_DIR = ../../lib/debug/moc
    OBJECTS_DIR = ../../lib/debug/obj
    RCC_DIR = ../../lib/debug/rcc
    DESTDIR = ../../lib
}
CONFIG(release, debug|release) {
    UI_DIR = ../../lib/release/ui
    MOC_DIR = ../../lib/release/moc
    OBJECTS_DIR = ../../lib/release/obj
    RCC_DIR = ../../lib/release/rcc
    DESTDIR = ../../lib
}

SOURCES += shape.cpp
HEADERS += graphics_global.h \
    shape.h
