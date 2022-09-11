#ifndef PIECHARTDATASET_H
#define PIECHARTDATASET_H

#include "record.h"
#include "model.h"
#include "QDebug"


struct AvgContinent : public ChartData {
    double media;
};

class pieChartDataset : public model
{
private:
    int year;
public:
    pieChartDataset(const listaDati&,int);
    QList<ChartData*> getData() const override;
    int getYear() const override;
};

#endif // PIECHARTDATASET_H
