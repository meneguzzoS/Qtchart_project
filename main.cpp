#include "mainwindow.h"
#include <QApplication>
//#include "record.h"
//#include <QDebug>
//#include <iostream>
//#include "table.h"
#include "listadati.h"
//#include "barchartview.h"
//#include "barchartdataset.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
