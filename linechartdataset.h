#ifndef LINECHARTDATASET_H
#define LINECHARTDATASET_H
#include "record.h"
#include "listacontroller.h"
#include "model.h"

struct stateData : public ChartData {
//    QString nome;
    QList<double> values;
    QList<int> years;
};

class lineChartDataset : public model
{
private:
    QList<ChartData*> data; //oppure QList<stateData*> data;
public:
    lineChartDataset(const listaController&,const QList<int>&); //o anche QList<QData.year()>
    QList<ChartData*> getData() const override;
    double getMax() const override;
    double getMin() const override;
};

#endif // LINECHARTDATASET_H
