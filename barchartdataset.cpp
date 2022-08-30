#include "barchartdataset.h"

barChartDataset::barChartDataset(const listaController& l, int i) : year(i)
{
    for(QList<record>::const_iterator cit = l.getList()->begin(); cit != l.getList()->end(); cit++){
        if((*cit).getData().year() == i) {
            state aux;
            aux.nomeStato = (*cit).getName();
            aux.pil = (*cit).getPIL();
            data.push_back(aux);
        }
    }
}

QList<state> barChartDataset::getData() const
{
    return data;
}

int barChartDataset::getYear() const
{
    return year;
}

double barChartDataset::getMax() const
{
    int i = 0;
    for(const auto& a : data) {
        if(a.pil > i)
            i = a.pil;
    }
    return i;
}

double barChartDataset::getMin() const
{
    int i = INT_MAX;
    for(const auto& a : data) {
        if(a.pil < i)
            i = a.pil;
    }
    return i;
}
