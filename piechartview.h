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

QT_CHARTS_USE_NAMESPACE
class pieChartView: public QWidget
{
    Q_OBJECT
private:
    //pieChartDataset *dati;
    QPieSeries* series;
public:
    pieChartView();
    void insertData(const AvgContinent&);
};

#endif // PIECHARTVIEW_H
