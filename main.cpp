#include "mainwindow.h"
#include <QApplication>
#include "record.h"
#include <QDebug>
#include <iostream>
#include "table.h"
#include "piechartdataset.h"
#include "piechartview.h"
#include "piechartcontrol.h"
#include "barchartdataset.h"
#include "barchartcontrol.h"
#include "barchartview.h"
#include "home.h"


QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    home h;
    h.show();

    table q;
    //q.show();

    record b("italia", QDate(2008,1,3), 3000, Europa);
    record c("francia", QDate(2008,2,1), 4000, Europa);
    record d("congo", QDate(2008,4,1), 2000, Africa);
    record e("zimbawe", QDate(2008,6,8), 1500, Asia);
    QList<record> lista;
    lista.push_back(b);
    lista.push_back(c);
    lista.push_back(d);
    lista.push_back(e);
    barChartDataset nuovo(lista,2008);
    barChartView view;
    barChartControl ctr(&nuovo, &view);
    //view.show();





    return a.exec();
}
