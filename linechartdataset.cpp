#include "linechartdataset.h"

lineChartDataset::lineChartDataset(const listaController& l,const QList<int>& y)
{
    stateData *aux;
    for(const auto& s : l.getNomiStati()) {
         aux = new stateData;
         for(QList<int>::const_iterator anno = y.cbegin(); anno!=y.cend(); ++anno) {
            for(QList<record>::const_iterator cit = l.getList()->cbegin(); cit != l.getList()->cend(); ++cit) {
                if(s == (*cit).getName()  && (*cit).getData().year() == *anno) {
                    aux->nome = (*cit).getName();
                    aux->values.push_back((*cit).getPIL());
                    aux->years.push_back(*anno);
                }
            }
        }
        if(aux->values.isEmpty())
            delete aux;
        else
            data.push_back(aux);
    }
}

QList<ChartData*> lineChartDataset::getData() const
{
    return data;
}

double lineChartDataset::getMax() const
{
    int i = 0;
    for(const auto& a : data) {
        stateData* p = dynamic_cast<stateData*>(a);
            if(p) {
                for(const auto& v : p->values) {
                    if(v > i)
                        i = v;
                }
    }

    }
    return i;
}

double lineChartDataset::getMin() const
{
    int i = INT_MAX;
    for(const auto& a : data) {
        stateData* p = dynamic_cast<stateData*>(a);
        if(p) {
            for(const auto& v : p->values) {
                if(v < i)
                    i = v;
            }
        }

    }
    return i;
}
