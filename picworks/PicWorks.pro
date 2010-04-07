# -------------------------------------------------
# PicWorks
# Main project file
# by Galaxy.org
# 2009-9-5
# -------------------------------------------------
TARGET = PicWorks
TEMPLATE = app
CONFIG += precompile_header
PRECOMPILED_HEADER = src/stable.h
precompile_header:!isEmpty(PRECOMPILED_HEADER):DEFINES += USING_PCH

# platform-specific
win32 { 
    # generate version number
    MAJOR = 0
    MINOR = 0
    REVISION = 0
    DEST = src/version.cpp
    IN = tools/vergen/version.in
    versiontarget.target = $$DEST
    versiontarget.commands = tools/vergen/vergen.exe \
        $$MAJOR \
        $$MINOR \
        $$REVISION \
        $$DEST \
        $$IN
    versiontarget.depends = FORCE
    PRE_TARGETDEPS += $$DEST
    QMAKE_EXTRA_TARGETS += versiontarget
    
    # executable icon
    RC_FILE += resources/pw.rc
}
unix { 
    # generate version number
    MAJOR = 0
    MINOR = 0
    REVISION = 0
    DEST = src/version.cpp
    IN = tools/vergen/version.in
    versiontarget.target = $$DEST
    versiontarget.commands = tools/vergen/vergen \
        $$MAJOR \
        $$MINOR \
        $$REVISION \
        $$DEST \
        $$IN
    versiontarget.depends = FORCE
    PRE_TARGETDEPS += $$DEST
    QMAKE_EXTRA_TARGETS += versiontarget
}

# submodel common, common files in PicWorks
include (src/common.pri)

# submodel view, most are UI component
include (src/view/view.pri)

# submodel model, data model in PicWorks
include (src/model/model.pri)

# submodel item, items in PicWorks
include (src/item/item.pri)

# submodel util, useful utilities in PicWorks
include (src/util/util.pri)

# submodel QtSingleApplication
include (src/extern/qtsingleapplication/qtsingleapplication.pri)
debug_and_release { 
    CONFIG -= debug_and_release
    CONFIG += debug_and_release
}
CONFIG(release, debug|release) { 
    CONFIG -= debug \
        release
    CONFIG += release
}

# shut up debug messages when release
# Note: QT_NO_DEBUG_OUPUT macro should be commented for release mode,
# this is because there is some bugs in QtSingleApplication solution.
# If these bugs fixes in future versions, this macro defination should
# be added.
# DEFINES += QT_NO_DEBUG_OUTPUT
debug { 
    UI_DIR = ./debug/tmp/ui
    MOC_DIR = ./debug/tmp/moc
    OBJECTS_DIR = ./debug/tmp/obj
    RCC_DIR = ./debug/tmp/rcc
}
release { 
    UI_DIR = ./release/tmp/ui
    MOC_DIR = ./release/tmp/moc
    OBJECTS_DIR = ./release/tmp/obj
    RCC_DIR = ./release/tmp/rcc
}

# resource files
RESOURCES += resources/pw.qrc

# i18n
TRANSLATIONS += resources/locale/pw_zh_CN.ts
