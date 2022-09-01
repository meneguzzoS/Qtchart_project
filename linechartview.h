#ifndef LINECHARTVIEW_H
#define LINECHARTVIEW_H
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "linechartdataset.h"
#include "QValueAxis"
#include "view.h"

QT_CHARTS_USE_NAMESPACE

class lineChartView : public view
{
Q_OBJECT
private:
    QChart *chart;
    QLineSeries *series;
public:
    lineChartView();
    void insertData(ChartData*);
    void setDesign(model*);
};

#endif // LINECHARTVIEW_H
