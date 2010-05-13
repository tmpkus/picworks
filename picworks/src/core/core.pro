# -------------------------------------------------
# PicWorks Utilities
# Subproject file
# by Galaxy.org
# 2009-10-13
# -------------------------------------------------
TARGET = core
TEMPLATE = lib
DEFINES += UTIL_LIBRARY
include(../config.pri)
include(../share/qtsingleapplication/qtsingleapplication.pri)
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
HEADERS += action.h \
    util_global.h \
    actioncontainer.h \
    actionmanager.h \
    appcontext.h \
    appresource.h \
    constants.h \
    idmanager.h \
    imageio.h \
    singleton.h \
    version.h \
    gpwdat.h
SOURCES += action.cpp \
    actioncontainer.cpp \
    actionmanager.cpp \
    appcontext.cpp \
    appresource.cpp \
    idmanager.cpp \
    imageio.cpp \
    singleton.cpp \
    version.cpp \
    constants.cpp \
    gpwdat.cpp
INCLUDEPATH += ../ui
RESOURCES += ../../res/pwrc.qrc
