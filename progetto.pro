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
    listacontroller.cpp \
    listadati.cpp \
        main.cpp \
        mainwindow.cpp \
    record.cpp \
    table.cpp \
    piechartdataset.cpp \
    piechartview.cpp \
    barchartdataset.cpp \
    barchartview.cpp \
    linechartdataset.cpp \
    linechartview.cpp \
    newchart.cpp \
    model.cpp \
    filehandler.cpp \
    view.cpp \
    chartcontroller.cpp

HEADERS += \
    listacontroller.h \
    listadati.h \
        mainwindow.h \
    record.h \
    table.h \
    piechartdataset.h \
    piechartview.h \
    barchartdataset.h \
    barchartview.h \
    linechartdataset.h \
    linechartview.h \
    newchart.h \
    model.h \
    filehandler.h \
    view.h \
    chartcontroller.h
