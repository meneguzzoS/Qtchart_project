#include "barchartdataset.h"

barChartDataset::barChartDataset(const QList<record>& l, int i)
{
    for(QList<record>::const_iterator cit = l.begin(); cit != l.end(); cit++){
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
