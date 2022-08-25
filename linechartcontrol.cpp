#include "linechartcontrol.h"

lineChartControl::lineChartControl(lineChartDataset* d,lineChartView* v) : dati(d), view(v)
{
    for(const auto& l : d->getData())
        v->insertData(l);
}
