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

#添加以下定义可以关闭qDebug和qWarning的输出 定义编译选项
DEFINES += QT_NO_WARNING_OUTPUT\
           QT_NO_DEBUG_OUTPUT


#条件编译
#DEFINES += RUN_ON_EMBEDDEDSYSTEM
#if(contains(DEFINES,RUN_ON_EMBEDDEDSYSTEM)){#contains和{必须在同一行，否则报错
#符合条件的编译
#}else{
#不符合条件的
#}

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
        app.cpp \
    fwigglywidget.cpp

HEADERS += \
        frmcomtool.h \
        app.h \
        myhelper.h \
    fwigglywidget.h

FORMS    += frmcomtool.ui

RESOURCES += \
    main.qrc

#CONFIG += qt warn_off release
