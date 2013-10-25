#-------------------------------------------------
#
# Project created by QtCreator 2013-10-25T18:02:59
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = twl_ui
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

# includes and external
INCLUDEPATH += ./include

client{
SOURCES	    += $$system("find ./src -name '*.cpp'")
HEADERS	    += $$system("find ./include -name '*.h'")
FORMS	    += $$system("find ./ui -name '*.ui'")
}
