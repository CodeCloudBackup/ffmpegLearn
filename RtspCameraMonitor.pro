QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/../binary/FFmpeg431dev/include
INCLUDEPATH += $$PWD/../binary/SDL2/include

LIBS    +=  $$PWD/../binary/FFmpeg431dev/lib/avcodec.lib \
            $$PWD/../binary/FFmpeg431dev/lib/avdevice.lib \
            $$PWD/../binary/FFmpeg431dev/lib/avfilter.lib \
            $$PWD/../binary/FFmpeg431dev/lib/avformat.lib \
            $$PWD/../binary/FFmpeg431dev/lib/avutil.lib \
            $$PWD/../binary/FFmpeg431dev/lib/postproc.lib \
            $$PWD/../binary/FFmpeg431dev/lib/swresample.lib \
            $$PWD/../binary/FFmpeg431dev/lib/swscale.lib

LIBS    +=  $$PWD/../binary/SDL2/lib/x86/SDL2.lib
LIBS    +=  $$PWD/../binary/SDL2/lib/x86/SDL2main.lib

SOURCES += \
    main.cpp \
    mdump.cpp \
    menu_button.cpp \
    video_label.cpp \
    video_play.cpp \
    video_thread.cpp \
    widget.cpp

HEADERS += \
    common.h \
    ffmpeg_c.h \
    mdump.h \
    menu_button.h \
    video_label.h \
    video_play.h \
    video_thread.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc
