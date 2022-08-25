#ifndef LINECHARTVIEW_H
#define LINECHARTVIEW_H
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "linechartdataset.h"
#include "QValueAxis"

QT_CHARTS_USE_NAMESPACE

class lineChartView : public QWidget
{
Q_OBJECT
private:
    //QLineSeries *series;
    QChart *chart;
public:
    lineChartView();
    void insertData(const stateData&);
};

#endif // LINECHARTVIEW_H
