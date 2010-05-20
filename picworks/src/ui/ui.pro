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
        -lgraphicsd
    UI_DIR = ../../lib/debug/ui
    MOC_DIR = ../../lib/debug/moc
    OBJECTS_DIR = ../../lib/debug/obj
    RCC_DIR = ../../lib/debug/rcc
    DESTDIR = ../../lib
}
CONFIG(release, debug|release) { 
    LIBS += -L../../lib \
        -lcore \
        -lgraphics
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
    ../share/qtcolorpicker/qtcolorpicker.cpp \
    ../share/qtwindowlistmenu/qtwindowlistmenu.cpp \
    projectscene.cpp \
    projectview.cpp \
    projectwindow.cpp \
    twocolorselector.cpp
HEADERS += ui_global.h \
    mainwindow.h \
    aboutdialog.h \
    licensedialog.h \
    projectcreator.h \
    ../share/qtcolorpicker/qtcolorpicker.h \
    ../share/qtwindowlistmenu/qtwindowlistmenu.h \
    projectscene.h \
    projectview.h \
    projectwindow.h \
    twocolorselector.h
INCLUDEPATH += ../core \
    ../graphics \
    ../share/qtwindowlistmenu \
    ../share/qtcolorpicker
