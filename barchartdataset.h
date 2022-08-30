#ifndef BARCHARTDATASET_H
#define BARCHARTDATASET_H
#include "record.h"
#include "listacontroller.h"
#include "model.h"

struct state {
    QString nomeStato;
    double pil;
};

class barChartDataset : public model
{
private:
    QList<state> data;
    int year;
public:
    barChartDataset(const listaController&, int);
    QList<state> getData() const;
    int getYear() const;
    double getMax() const;
    double getMin() const;
};

#endif // BARCHARTDATASET_H
