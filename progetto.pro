#-------------------------------------------------
#
# Project created by QtCreator 2022-08-02T11:11:29
#
#-------------------------------------------------

QT       += core charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = progetto
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    record.cpp \
    table.cpp \
    listacontroller.cpp \
    piechartdataset.cpp \
    piechartview.cpp \
    piechartcontrol.cpp \
    barchartdataset.cpp \
    barchartview.cpp \
    barchartcontrol.cpp \
    home.cpp \
    linechartdataset.cpp \
    linechartview.cpp \
    linechartcontrol.cpp \
    newchart.cpp \
    model.cpp

HEADERS += \
        mainwindow.h \
    record.h \
    table.h \
    listacontroller.h \
    piechartdataset.h \
    piechartview.h \
    piechartcontrol.h \
    barchartdataset.h \
    barchartview.h \
    barchartcontrol.h \
    home.h \
    linechartdataset.h \
    linechartview.h \
    linechartcontrol.h \
    newchart.h \
    model.h
