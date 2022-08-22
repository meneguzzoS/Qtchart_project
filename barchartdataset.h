#ifndef BARCHARTDATASET_H
#define BARCHARTDATASET_H
#include "record.h"

struct state {
    QString nomeStato;
    double pil;
};

class barChartDataset
{
private:
    QList<state> data;
public:
    barChartDataset(const QList<record>&, int);
    QList<state> getData() const;
};

#endif // BARCHARTDATASET_H
