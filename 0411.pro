#-------------------------------------------------
#
# Project created by QtCreator 2013-04-11T00:14:21
#
#-------------------------------------------------

QT       += core gui

TARGET = 0411
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rtime_process.cpp

HEADERS  += mainwindow.h \
    rtime_process.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../opencv/build/x86/vc10/lib/ -lopencv_core242
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../opencv/build/x86/vc10/lib/ -lopencv_core242d

INCLUDEPATH += $$PWD/../../../../../../opencv/build/include
DEPENDPATH += $$PWD/../../../../../../opencv/build/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../opencv/build/x86/vc10/lib/ -lopencv_highgui242
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../opencv/build/x86/vc10/lib/ -lopencv_highgui242d

INCLUDEPATH += $$PWD/../../../../../../opencv/build/include
DEPENDPATH += $$PWD/../../../../../../opencv/build/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../opencv/build/x86/vc10/lib/ -lopencv_imgproc242
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../opencv/build/x86/vc10/lib/ -lopencv_imgproc242d

INCLUDEPATH += $$PWD/../../../../../../opencv/build/include
DEPENDPATH += $$PWD/../../../../../../opencv/build/include
