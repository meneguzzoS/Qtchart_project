#ifndef LINECHARTCONTROL_H
#define LINECHARTCONTROL_H
#include "linechartdataset.h"
#include "linechartview.h"

class lineChartControl
{
private:
    lineChartDataset* dati;
    lineChartView* view;
public:
    lineChartControl(lineChartDataset*,lineChartView*);
};

#endif // LINECHARTCONTROL_H
