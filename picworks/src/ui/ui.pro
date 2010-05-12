# -------------------------------------------------
# PicWorks Ui
# Subproject file
# by Galaxy.org
# 2009-9-5
# -------------------------------------------------
TARGET = ui
TEMPLATE = lib
DEFINES += UI_LIBRARY
include(../config.pri)
CONFIG(debug, debug|release) { 
    mac:TARGET = $$join(TARGET,,,_debug)
    win32:TARGET = $$join(TARGET,,,d)
    LIBS += -L../../lib \
        -lcored \
        -lQtSolutions_WindowMenu-2.2d
    UI_DIR = ../../lib/debug/ui
    MOC_DIR = ../../lib/debug/moc
    OBJECTS_DIR = ../../lib/debug/obj
    RCC_DIR = ../../lib/debug/rcc
    DESTDIR = ../../lib
}
CONFIG(release, debug|release) { 
    LIBS += -L../../lib \
        -lcore \
        -lQtSolutions_WindowMenu-2.2
    UI_DIR = ../../lib/release/ui
    MOC_DIR = ../../lib/release/moc
    OBJECTS_DIR = ../../lib/release/obj
    RCC_DIR = ../../lib/release/rcc
    DESTDIR = ../../lib
}
SOURCES += mainwindow.cpp \
    aboutdialog.cpp \
    licensedialog.cpp \
    projectcreator.cpp \
    ../share/qtcolorpicker/qtcolorpicker.cpp
HEADERS += ui_global.h \
    mainwindow.h \
    aboutdialog.h \
    licensedialog.h \
    projectcreator.h \
    ../share/qtcolorpicker/qtcolorpicker.h
INCLUDEPATH += ../core \
    ../share/qtwindowlistmenu \
    ../share/qtcolorpicker
