#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
//#include <QtWidgets/QApplication>
//#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QHBoxLayout>
#include "model.h"

QT_CHARTS_USE_NAMESPACE

//struct ChartData;

class view : public QWidget
{
Q_OBJECT
protected:
    QChart* chart;
    //QAbstractSeries *series; //verificare se ha senso ed è fattibile
public:
    view(QWidget* = nullptr);
    virtual void insertData(ChartData*) =0;
    void setDesign();
};

#endif // VIEW_H
