TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIBS += -lcairo -lrsvg-2

INCLUDEPATH += /usr/lib/x86_64-linux-gnu/glib-2.0/include\
 /usr/include/gdk-pixbuf-2.0\
 /usr/include/librsvg-2.0/librsvg\
 /usr/include/cairo\
 /usr/include/glib-2.0\
