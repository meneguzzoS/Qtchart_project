#ifndef PIECHARTDATASET_H
#define PIECHARTDATASET_H
#include "record.h"
#include "listacontroller.h"
#include "model.h"

struct AvgContinent {
    QString nomeContinente;
    double media;
};

class pieChartDataset : public model
{
private:
    QList<AvgContinent> data;
public:
    pieChartDataset(const listaController&,int);
    QList<AvgContinent> getData() const;
};

#endif // PIECHARTDATASET_H
