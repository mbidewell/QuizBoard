#-------------------------------------------------
#
# Project created by QtCreator 2015-07-04T20:46:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QuizCreator
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    editquestion.cpp \
    editcategory.cpp

HEADERS  += mainwindow.h \
    editquestion.h \
    editcategory.h

FORMS    += mainwindow.ui \
    editquestion.ui \
    editcategory.ui

LIBS += -L/Users/mbidewell/Homebrew/lib
INCLUDEPATH += /Users/mbidewell/Homebrew/include
