#include "piechartcontrol.h"

pieChartControl::pieChartControl(pieChartDataset* d, pieChartView* v) : dati(d), view(v)
{
    for(const auto& l : d->getData())
        v->insertData(l);
}
