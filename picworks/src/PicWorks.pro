TARGET = PicWorks
TEMPLATE = app

QT *= network

CONFIG += precompile_header
PRECOMPILED_HEADER = core/pch.h
precompile_header:!isEmpty(PRECOMPILED_HEADER):DEFINES += USING_PCH

CONFIG += debug

# ensure one "debug_and_release" in CONFIG, for clarity...
debug_and_release {
    CONFIG -= debug_and_release
    CONFIG += debug_and_release
}
# ensure one "debug" or "release" in CONFIG so they can be used as
# conditionals instead of writing "CONFIG(debug, debug|release)"...
CONFIG(debug, debug|release) {
    CONFIG -= debug release
    CONFIG += debug
}
CONFIG(release, debug|release) {
    CONFIG -= debug release
    CONFIG += release
}

CONFIG(debug, debug|release) {
    UI_DIR = ../debug/ui
    MOC_DIR = ../debug/moc
    OBJECTS_DIR = ../debug/obj
    RCC_DIR = ../debug/rcc
    DESTDIR = ../debug
}
CONFIG(release, debug|release) {
    UI_DIR = ../release/ui
    MOC_DIR = ../release/moc
    OBJECTS_DIR = ../release/obj
    RCC_DIR = ../release/rcc
    DESTDIR = ../release
}

INCLUDEPATH += extra/qtsingleapplication \
    extra/qtwindowlistmenu \
    extra/qtcolorpicker \
    core ui graphics

include (extra/qtcolorpicker/qtcolorpicker.pri)

include (extra/qtwindowlistmenu/qtwindowlistmenu.pri)

include (extra/qtsingleapplication/qtsingleapplication.pri)

include (core/core.pri)

include (ui/ui.pri)

include (graphics/graphics.pri)

# platform-specific
win32 {
    # executable icon
    RC_FILE += ../res/pw.rc
}
# i18n
TRANSLATIONS += ../res/locale/pw_zh_CN.ts

RESOURCES += ../res/pwrs.qrc
