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
        Model/movableelement.cpp \
    page.cpp \
    utils.cpp \
    pagethree.cpp \
    pagefour.cpp \
    pageeight.cpp \
    pagefive.cpp \
    pagesix.cpp \
    pageseven.cpp \
    Model/rocket.cpp \
    Model/treetrunk.cpp \
    Model/clickablelabel.cpp \
    Model/lemur.cpp \
    Model/element.cpp \
    Controller/hapticcontroller.cpp \
    Controller/scenecontroller.cpp \
    Controller/soundcontroller.cpp

HEADERS  += mainwindow.h \
        pageone.h \
        pagetwo.h \
        Model/movableelement.h \
    page.h \
    utils.h \
    pagethree.h \
    pagefour.h \
    pageeight.h \
    pagefive.h \
    pagesix.h \
    pageseven.h \
    Model/rocket.h \
    Model/treetrunk.h \
    Model/clickablelabel.h \
    Model/lemur.h \
    Model/element.h \
    Controller/hapticcontroller.h \
    Controller/scenecontroller.h \
    Controller/soundcontroller.h

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
