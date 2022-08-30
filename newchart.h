#ifndef NEWCHART_H
#define NEWCHART_H
#include <QDialog>
#include <QRadioButton>
#include <QPushButton>
#include <QSpinBox>

#include "piechartcontrol.h"
#include "piechartdataset.h"
#include "piechartview.h"
#include "barchartcontrol.h"
#include "barchartdataset.h"
#include "barchartview.h"
#include "listacontroller.h"
#include "linechartcontrol.h"
#include "linechartdataset.h"
#include "linechartview.h"

class newChart : public QDialog
{
Q_OBJECT
public:
    newChart(listaController*);
private:
    listaController *list;
    QList<int>* year;
     //int n;
     //QSpinBox* ndati;
     QPushButton* ok;
     QPushButton* annulla;
     QRadioButton* piechart;
     QRadioButton* linechart;
     QRadioButton* barchart;
public slots:
     void lineChecked();
     void pieChecked();
     void barChecked();
     void createChart();
};

#endif // NEWCHART_H
