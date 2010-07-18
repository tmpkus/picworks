# -------------------------------------------------
# PicWorks Tools: VerGen
# by Galaxy.org
# 2010-5-16
# -------------------------------------------------
TARGET = vergen
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG(debug, debug|release) {
    MOC_DIR = ../debug/moc
    OBJECTS_DIR = ../debug/obj
    RCC_DIR = ../debug/rcc
    DESTDIR = ../debug
}
CONFIG(release, debug|release) {
    MOC_DIR = ../release/moc
    OBJECTS_DIR = ../release/obj
    RCC_DIR = ../release/rcc
    DESTDIR = ../release
}
