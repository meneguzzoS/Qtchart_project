#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H
#include "barchartdataset.h"
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QHBoxLayout>

QT_CHARTS_USE_NAMESPACE

class barChartView : public QWidget
{
    Q_OBJECT
private:
    QBarSeries *series;
public:
    barChartView();
    void insertBar(const state&);
};

#endif // BARCHARTVIEW_H
