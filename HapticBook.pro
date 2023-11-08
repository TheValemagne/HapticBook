#-------------------------------------------------
#
# Project created by QtCreator 2023-10-25T11:45:17
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HapticBook
TEMPLATE = app

CONFIG += resources_big
INCLUDEPATH += "C:\Program Files\Immersion Corporation\IFC23\inc"
LIBS += "C:\Program Files\Immersion Corporation\IFC23\lib\IFC23.lib"

SOURCES += main.cpp\
        mainwindow.cpp \
        pageone.cpp \
        pagetwo.cpp \
    page.cpp \
    utils.cpp \
    pagethree.cpp \
    pagefour.cpp \
    pageeight.cpp \
    pagefive.cpp \
    pagesix.cpp \
    pageseven.cpp \
    Model/clickablelabel.cpp \
    Model/lemur.cpp \
    Controller/hapticcontroller.cpp \
    Controller/soundcontroller.cpp \
    Model/movablelabel.cpp

HEADERS  += mainwindow.h \
        pageone.h \
        pagetwo.h \
    page.h \
    utils.h \
    pagethree.h \
    pagefour.h \
    pageeight.h \
    pagefive.h \
    pagesix.h \
    pageseven.h \
    Model/clickablelabel.h \
    Model/lemur.h \
    Controller/hapticcontroller.h \
    Controller/soundcontroller.h \
    Model/movablelabel.h

FORMS += mainwindow.ui \
    pageone.ui \
    pagetwo.ui \
    pagethree.ui \
    pagefour.ui \
    pageeight.ui \
    pagefive.ui \
    pagesix.ui \
    pageseven.ui

RESOURCES += \
    resources/resources.qrc
