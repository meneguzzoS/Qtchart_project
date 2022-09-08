#ifndef BARCHARTDATASET_H
#define BARCHARTDATASET_H
#include "record.h"
#include "model.h"

struct state : public ChartData {
    double pil;
};
//class listaController;
class barChartDataset : public model
{
private:
    QList<ChartData*> data;
    int year;
public:
    barChartDataset(const listaDati&, int);
    ~barChartDataset();
    QList<ChartData*> getData() const;
    int getYear() const;
    double getMax() const;
    double getMin() const;
};

#endif // BARCHARTDATASET_H
