#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H
#include "barchartdataset.h"
#include "view.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QHBoxLayout>

QT_CHARTS_USE_NAMESPACE

class barChartView : public view
{
private:
    //QChart* chart;
    QBarSeries *series;
public:
    barChartView();
    void insertData(ChartData*) override;
    void setDesign(model*) override;
};

#endif // BARCHARTVIEW_H
