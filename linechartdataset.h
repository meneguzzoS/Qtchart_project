#ifndef LINECHARTDATASET_H
#define LINECHARTDATASET_H
#include "record.h"
#include "listacontroller.h"

struct stateData {
    QString nome;
    QList<double> values;
    QList<int> years;
};

class lineChartDataset
{
private:
    QList<stateData> data; //oppure QList<stateData*> data;
public:
    lineChartDataset(const listaController&,const QList<int>&); //o anche QList<QData.year()>
    QList<stateData> getData() const;
};

#endif // LINECHARTDATASET_H
