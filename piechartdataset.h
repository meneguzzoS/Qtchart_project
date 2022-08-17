#ifndef PIECHARTDATASET_H
#define PIECHARTDATASET_H
#include "record.h"

struct AvgContinent {
    MacroArea nomeContinente;
    double media;
};

class pieChartDataset
{
private:
    QList<AvgContinent> data;
public:
    pieChartDataset();
};

#endif // PIECHARTDATASET_H
