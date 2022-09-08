#include "mainwindow.h"
#include <QApplication>
//#include "record.h"
//#include <QDebug>
//#include <iostream>
//#include "table.h"
#include "listadati.h"
//#include "barchartview.h"
//#include "barchartdataset.h"
#include "listacontroller.h"
#include "table.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    listaDati d;
    table t(&d);
    listacontroller c(&d,&t);
    t.show();
    return a.exec();
}
