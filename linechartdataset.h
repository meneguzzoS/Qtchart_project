#ifndef LINECHARTDATASET_H
#define LINECHARTDATASET_H
#include "record.h"
#include "model.h"

struct stateData : public ChartData {
    QList<double> values;
    QList<int> years;
};

class lineChartDataset : public model
{
public:
    lineChartDataset(const listaDati&,const QList<int>&); //o anche QList<QData.year()>
    QList<ChartData*> getData() const override;
    double getMax() const override;
    double getMin() const override;
};

#endif // LINECHARTDATASET_H
