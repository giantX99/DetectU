QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#QT += multimedia

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
####################################################################################################

INCLUDEPATH += C:/Users/gian-/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/opencv/build/include
LIBS += -LC:/Users/gian-/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/opencv/build/x64/vc16/lib

Debug : {
        LIBS += -lopencv_core331d \
                -lopencv_imgproc331d \
                -lopencv_imgcodecs331d \
                -lopencv_videoio331d \
                -lopencv_flann331d \
                -lopencv_highgui331d \
                -lopencv_features2d331d \
                -lopencv_photo331d \
                -lopencv_video331d \
                -lopencv_calib3d331d \
                -lopencv_objdetect331d \
                -lopencv_videostab331d \
                -lopencv_shape331d \
                -lopencv_stitching331d \
                -lopencv_superres331d \
                -lopencv_dnn331d \
                -lopencv_ml331d
}

Release: {
        LIBS += -lopencv_core331 \
                -lopencv_imgproc331 \
                -lopencv_imgcodecs331 \
                -lopencv_videoio331 \
                -lopencv_flann331 \
                -lopencv_highgui331 \
                -lopencv_features2d331 \
                -lopencv_photo331 \
                -lopencv_video331 \
                -lopencv_calib3d331 \
                -lopencv_objdetect331 \
                -lopencv_videostab331 \
                -lopencv_shape331 \
                -lopencv_stitching331 \
                -lopencv_superres331 \
                -lopencv_dnn331 \
                -lopencv_ml331
}

####################################################################################################

SOURCES += \
    Detect.cpp \
    Record.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    CameraFunction.h \
    Detect.h \
    Record.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
