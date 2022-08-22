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

class home : public QWidget
{
Q_OBJECT
private:
    table *window;
public:
    home();
public slots:
    void showTable();
    void pieChart();
    void barChart();
};

#endif // HOME_H
