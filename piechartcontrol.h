#ifndef PIECHARTCONTROL_H
#define PIECHARTCONTROL_H

#include "piechartdataset.h"
#include "piechartview.h"

class pieChartControl
{
private:
    pieChartDataset* dati;
    pieChartView* view;
public:
    pieChartControl(pieChartDataset*,pieChartView*);
};

#endif // PIECHARTCONTROL_H
