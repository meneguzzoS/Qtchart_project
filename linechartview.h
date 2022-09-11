#ifndef LINECHARTVIEW_H
#define LINECHARTVIEW_H
#include <QtCharts/QLineSeries>
#include "linechartdataset.h"
#include "QValueAxis"
#include "view.h"
#include "QChart"
#include "QVBoxLayout"
#include <QDebug>
#include <QXYSeries>

QT_CHARTS_USE_NAMESPACE

class lineChartView : public view
{
Q_OBJECT
private:
    QLineSeries *series;
public:
    lineChartView();
    ~lineChartView();
    void insertData(ChartData*);
    void setDesign(double,double);
};

#endif // LINECHARTVIEW_H
