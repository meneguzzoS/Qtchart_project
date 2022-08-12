#ifndef STACKEDBARCHART_H
#define STACKEDBARCHART_H

#include "record.h"


struct AvgProduct {
    float avg;
    productType type;
};

struct ProductStackedChartDataset {
    QString nomeProdotto;
    AvgProduct nuovo;
    AvgProduct usato;
    AvgProduct ricondizionato;
};

class StackedBarChart
{
public:
    StackedBarChart();
};

#endif // STACKEDBARCHART_H
