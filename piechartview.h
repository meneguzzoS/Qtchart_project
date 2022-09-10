#ifndef PIECHARTVIEW_H
#define PIECHARTVIEW_H

#include "piechartdataset.h"
#include <QWidget>
//#include <QtWidgets/QApplication>
//#include <QtWidgets/QMainWindow>
//#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QHBoxLayout>
#include "view.h"
#include <QDebug>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE
class pieChartView: public view
{
    Q_OBJECT
private:
    //pieChartDataset *dati;
//    QChart* chart;
    QPieSeries* series;
public:
    pieChartView();
    ~pieChartView();
    void insertData(ChartData*);
    void setDesign(QList<ChartData*>);
};

#endif // PIECHARTVIEW_H
