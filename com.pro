#-------------------------------------------------
#
# Project created by QtCreator 2016-09-19T22:25:56
#
#-------------------------------------------------

QT       += core gui network sql xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# application name
TARGET              = ComTool

# type
TEMPLATE            = app

DESTDIR             = bin
win32:RC_FILE       = main.rc
PRECOMPILED_HEADER  = myhelper.h

include($$PWD/qextserialport/qextserialport.pri)

# build dir
BuildDir =build_$$QT_VERSION

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/$$BuildDir/debug
    OBJECTS_DIR = $$PWD/$$BuildDir/debug/.obj
    MOC_DIR = $$PWD/$$BuildDir/debug/.moc
    RCC_DIR = $$PWD/$$BuildDir/debug/.rcc
    UI_DIR = $$PWD/$$BuildDir/debug/.ui
} else {
    DESTDIR = $$PWD/$$BuildDir/release
    OBJECTS_DIR = $$PWD/$$BuildDir/release/.obj
    MOC_DIR = $$PWD/$$BuildDir/release/.moc
    RCC_DIR = $$PWD/$$BuildDir/release/.rcc
    UI_DIR = $$PWD/$$BuildDir/release/.ui
}

SOURCES += main.cpp\
        frmcomtool.cpp \
        app.cpp

HEADERS += \
        frmcomtool.h \
        app.h \
        myhelper.h

FORMS    += frmcomtool.ui

RESOURCES += \
    main.qrc

#CONFIG += qt warn_off release
