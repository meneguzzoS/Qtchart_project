#ifndef PIECHARTDATASET_H
#define PIECHARTDATASET_H
#include "record.h"
#include "listacontroller.h"

struct AvgContinent {
    QString nomeContinente;
    double media;
};

class pieChartDataset
{
private:
    QList<AvgContinent> data;
public:
    pieChartDataset(const listaController&);
    QList<AvgContinent> getData() const;
};

#endif // PIECHARTDATASET_H
