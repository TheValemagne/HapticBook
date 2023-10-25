#-------------------------------------------------
#
# Project created by QtCreator 2023-10-25T11:45:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HapticBook
TEMPLATE = app

INCLUDEPATH += "C:\Program Files\Immersion Corporation\IFC23\inc"
LIBS += "C:\Program Files\Immersion Corporation\IFC23\lib\IFC23.lib"

SOURCES += main.cpp\
        mainwindow.cpp \
        Controller/HapticController.cpp \
        Controller/SceneController.cpp \
        Controller/SoundController.cpp \
        Model/Element.cpp \
        Model/ImageElement.cpp \
        Model/TextElement.cpp \
        View/Book.cpp \
        View/MainWindow.cpp \
        View/Page.cpp \

HEADERS  += mainwindow.h \
        Controller/HapticController.h \
        Controller/SceneController.h \
        Controller/SoundController.h \
        Model/Element.h \
        Model/ImageElement.h \
        Model/TextElement.h \
        View/Book.h \
        View/MainWindow.h \
        View/Page.h \