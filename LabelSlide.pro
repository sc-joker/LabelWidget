#-------------------------------------------------
#
# Project created by QtCreator 2019-03-28T16:30:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
lessThan(QT_MAJOR_VERSION, 5): DEFINES += ARM

TARGET = LabelSlide
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    LabelWidget.cpp \
    JPushButton.cpp

HEADERS  += MainWindow.h \
    LabelWidget.h \
    JPushButton.h

FORMS    += MainWindow.ui \
    LabelWidget.ui
