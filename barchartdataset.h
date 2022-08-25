#ifndef BARCHARTDATASET_H
#define BARCHARTDATASET_H
#include "record.h"
#include "listacontroller.h"

struct state {
    QString nomeStato;
    double pil;
};

class barChartDataset
{
private:
    QList<state> data;
public:
    barChartDataset(const listaController&, int);
    QList<state> getData() const;
};

#endif // BARCHARTDATASET_H
