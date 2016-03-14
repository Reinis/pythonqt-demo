TEMPLATE = app
TARGET = demo
INCLUDEPATH += /usr/include/python3.4m
INCLUDEPATH += /usr/include/PythonQt
INCLUDEPATH += .

LIBS += -lPythonQt -lPythonQt_QtAll

HEADERS += mainwindow.h

SOURCES += app.cpp

CONFIG += c++11

QT += widgets

