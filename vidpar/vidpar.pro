TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp


LIBS+= -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio

INCLUDEPATH +=/usr/include/netiucv\
/usr/lib/x86_64-linux-gnu/perl/5.26/CORE\
/usr/include/opencv
