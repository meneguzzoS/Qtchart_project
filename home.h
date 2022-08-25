#ifndef HOME_H
#define HOME_H
#include <QWidget>
#include "table.h"
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

class home : public QWidget
{
Q_OBJECT
private:
    table *window;
    listaController *list;
    QList<int>* year;
public:
    home(QList<record>*,QList<int>*);
public slots:
    void showTable();
    void pieChart();
    void barChart();
    void lineChart();
};

#endif // HOME_H
