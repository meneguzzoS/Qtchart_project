#include "mainwindow.h"
#include <QApplication>
#include "record.h"
#include <QDebug>
#include <iostream>
#include "table.h"
#include "listacontroller.h"
#include "barchartview.h"
#include "barchartdataset.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QList<record> *p = new QList<record>;

    int b=2007,c=2008, d=2009, e=2010;
    QList<int> q;
    q.push_back(b);
    q.push_back(c);
    q.push_back(d);
    q.push_back(e);
    listaController *lista= new listaController(p);

    return a.exec();
}
