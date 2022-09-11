#ifndef BARCHARTDATASET_H
#define BARCHARTDATASET_H
#include "record.h"
#include "model.h"

struct state : public ChartData {
    double pil;
};
class barChartDataset : public model
{
private:
    int year;
public:
    barChartDataset(const listaDati&, int);
    QList<ChartData*> getData() const override;
    int getYear() const override;
    double getMax() const override;
    double getMin() const override;
};

#endif // BARCHARTDATASET_H
