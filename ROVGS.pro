#-------------------------------------------------
#
# Project created by QtCreator 2018-03-05T09:45:07
#
#-------------------------------------------------

QT       += core gui
QT       += quick qml multimedia
QT       += printsupport widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ROVGS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Add OpenCV lib
INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib \
        -lopencv_core -lopencv_imgcodecs -lopencv_highgui \    #openCV lib
        -lrt \                                                 #Timer lib
        -lusb-1.0 \                                            #USB control lib

SOURCES += \
        main.cpp \
        rov_groundstation.cpp \
    src/joystick/joystick.cpp \
    gui.cpp \
    src/joystick/joystickdata.cpp \
    src/pingthread.cpp \
    src/robotthread.cpp \
    src/connector/udpConnector.cpp \
    src/MAVLinkDecoder/decoder.cpp \
    src/video/videoStream.cpp \
    src/video/PracticalSocket.cpp \
    src/timer/GStimer.cpp \
    src/MAVLinkDecoder/mavlinkmessagedealer.cpp \
    src/ROVsystem/systemMonitor.cpp \
    gsapplication.cpp \
    src/video/presenters_factory.cpp \
    src/video/videopresenter.cpp


RESOURCES += dialcontrol.qrc

HEADERS += \
        rov_groundstation.h \
    src/pingthread.h \
    src/robotthread.h \
    gui.h \
    src/joystick/joystick.h \
    src/joystick/joystickdata.h \
    src/connector/udpConnector.h \
    src/MAVLinkDecoder/decoder.h \
    src/communication/GSMAVLink.h \
    src/video/videoStream.h \
    src/video/config.h \
    src/video/PracticalSocket.h \
    src/timer/GStimer.h \
    src/MAVLinkDecoder/mavlinkmessagedealer.h \
    src/MAVLinkDecoder/mavlinkmessagedealer.h \
    src/debug/ROVGSdebug.h \
    src/main.h \
    src/ROVsystem/systemMonitor.h \
    gsapplication.h \
    src/video/presenters_factory.h \
    src/video/videopresenter.h


FORMS += \
        rov_groundstation.ui

INCLUDEPATH += /usr/local/include \
                /usr/local/include/cvd

BASEDIR      = $$IN_PWD
MAVLINKPATH_REL = src/mavlink/c_library_v2
MAVLINKPATH = $$BASEDIR/$$MAVLINKPATH_REL
MAVLINK_CONF = ardupilotmega

#INCLUDEPATH += $$MAVLINKPATH
INCLUDEPATH += $$MAVLINKPATH/ROV

LIBS += /usr/local/lib/libcvd.so\
        /usr/local/lib/libcvd.so.0

CONFIG += qwt

QWT_ROOT = /usr/local/qwt-6.1.4-svn #qwt控件安装位置，注意与qwtconfig.pri配置文件配合修改
include ( $${QWT_ROOT}/features/qwt.prf )




