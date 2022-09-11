#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QHBoxLayout>
#include "model.h"

QT_CHARTS_USE_NAMESPACE

class view : public QWidget
{
Q_OBJECT
protected:
    QChart* chart;
public:
    view();
    virtual ~view() = default;
    virtual void insertData(ChartData*) =0;
    void setDesign();
};

#endif // VIEW_H
