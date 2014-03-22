TEMPLATE = app
TARGET = duckrun
DEPENDPATH += .
QT += webkit

unix:DESTDIR = build
unix:INCLUDEPATH += include
unix:LIBS += -Llib -lQtSql -lQtWebKit -lQtNetwork
unix:OBJECTS_DIR = build/tmp
unix:MOC_DIR = build/moc

# Input
HEADERS += include/*.h
SOURCES += duckrun.cpp lib/*.cpp
