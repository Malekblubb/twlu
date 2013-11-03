#-------------------------------------------------
#
# Project created by QtCreator 2013-10-25T18:02:59
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = twl_ui
TEMPLATE = app
QMAKE_CXXFLAGS +=   -std=c++11 \
		    -std=c++1y

# includes and external
INCLUDEPATH +=	./include/twlu\
		./external/mlk/include\
		./external/twl/include


client{
SOURCES	    += $$system("find ./src/twlu -name '*.cpp'")
HEADERS	    += $$system("find ./include/twlu -name '*.h'")
FORMS	    += $$system("find ./ui/twlu -name '*.ui'")
}

HEADERS += \
    include/twlu/global/errors.h
