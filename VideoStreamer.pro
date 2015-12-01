#-------------------------------------------------
#
# Project created by QtCreator 2015-12-01T21:39:44
#
#-------------------------------------------------
QT              += core webchannel websockets

QT       -= gui

TARGET = VideoStreamer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

MOC_DIR         = output/moc
OBJECTS_DIR     = output/objects
DESTDIR         = output/binary

SOURCES += *.cpp            \
            libs/*.cpp

HEADERS += *.h              \
            libs/*.h
