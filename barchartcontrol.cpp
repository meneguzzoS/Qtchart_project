#include "barchartcontrol.h"

barChartControl::barChartControl(barChartDataset *d, barChartView *v) : dati(d), view(v)
{
    for(const auto& l : d->getData())
        v->insertBar(l);
}
