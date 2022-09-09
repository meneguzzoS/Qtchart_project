#ifndef LISTACONTROLLER_H
#define LISTACONTROLLER_H

#include <QObject>
#include "listadati.h"
#include "table.h"
#include "filehandler.h"
#include "newchart.h"
#include "model.h"

#include "piechartdataset.h"
#include "piechartview.h"
#include "barchartdataset.h"
#include "barchartview.h"
#include "linechartdataset.h"
#include "linechartview.h"

class listacontroller : public QObject
{
Q_OBJECT
public:
    listacontroller(listaDati*,table*);
    ~listacontroller();
private:
    listaDati* dati;
    table* vista;

    newChart* select;
public slots:
    void deleteRow();
    void newRow();
    void fromFiletoTable(QStringList);
    void changeRecord();
    void selectChart();
    void barChart();
    void lineChart();
    void pieChart();
};

#endif // LISTACONTROLLER_H
