QT += network \
    sql \
    xml \
    xmlpatterns
QT -= gui
TARGET = CCLogger
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    serialport.cpp
HEADERS += serialport.h
