#ifndef BARCHARTCONTROL_H
#define BARCHARTCONTROL_H

#include "barchartdataset.h"
#include "barchartview.h"

class barChartControl
{
private:
    barChartDataset* dati;
    barChartView* view;
public:
    barChartControl(barChartDataset*,barChartView*);
};

#endif // BARCHARTCONTROL_H
