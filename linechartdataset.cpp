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
            data.push_back(*aux);
    }
}

QList<stateData> lineChartDataset::getData() const
{
    return data;
}
