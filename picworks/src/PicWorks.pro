TEMPLATE = subdirs
CONFIG += precompile_header
PRECOMPILED_HEADER = pch.h
precompile_header:!isEmpty(PRECOMPILED_HEADER):DEFINES += USING_PCH
SUBDIRS += core graphics ui app
