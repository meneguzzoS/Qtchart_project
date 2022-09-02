#ifndef PIECHARTDATASET_H
#define PIECHARTDATASET_H
#include "record.h"
#include "listacontroller.h"
#include "model.h"

struct AvgContinent : public ChartData {
    double media;
};

class pieChartDataset : public model
{
private:
    QList<ChartData*> data;
    int year;
public:
    pieChartDataset(const listaController&,int);
    QList<ChartData*> getData() const override;
    int getYear() const override;
};

#endif // PIECHARTDATASET_H
