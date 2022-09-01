#ifndef PIECHARTVIEW_H
#define PIECHARTVIEW_H

#include "piechartdataset.h"
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QHBoxLayout>
#include "view.h"

QT_CHARTS_USE_NAMESPACE
class pieChartView: public view
{
    Q_OBJECT
private:
    //pieChartDataset *dati;
    QChart* chart;
    QPieSeries* series;
public:
    pieChartView();
    void insertData(ChartData*);
    void setDesign(model*);
};

#endif // PIECHARTVIEW_H
