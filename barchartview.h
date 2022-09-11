#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H
#include "barchartdataset.h"
#include "view.h"
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QHBoxLayout>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include "QDebug"

QT_CHARTS_USE_NAMESPACE

class barChartView : public view
{
private:
    QBarSeries *series;
public:
    barChartView();
    ~barChartView();
    void insertData(ChartData*) override;
    void setDesign(int,double);
};

#endif // BARCHARTVIEW_H
