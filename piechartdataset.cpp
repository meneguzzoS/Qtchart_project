#include "piechartdataset.h"

pieChartDataset::pieChartDataset(const listaController& lista)
{
    for(int cont = 0; cont<5 ; cont++) {
        int x=0;
        int n=0;
        for(QList<record>::const_iterator cit = lista.getList()->begin(); cit != lista.getList()->end(); ++cit) {
            if((*cit).getContinente() == cont) {
                x+=(*cit).getPIL();
                n++;
            }
        }
        if(cont==0 && n>0) {
            AvgContinent EU;
            EU.nomeContinente = "Europa";
            EU.media = x/n;
            data.push_back(EU);
        }
        if(cont == 1 && n>0) {
            AvgContinent AS;
            AS.nomeContinente = "Asia";
            AS.media = x/n;
            data.push_back(AS);
        }
        if(cont == 2 && n>0) {
            AvgContinent AM;
            AM.nomeContinente = "America";
            AM.media = x/n;
            data.push_back(AM);
        }
        if(cont == 3 && n>0) {
            AvgContinent AF;
            AF.nomeContinente = "Africa";
            AF.media = x/n;
            data.push_back(AF);
        }
        if(cont == 4 && n>0) {
            AvgContinent OC;
            OC.nomeContinente = "Oceania";
            OC.media = x/n;
            data.push_back(OC);
        }
    }
}

QList<AvgContinent> pieChartDataset::getData() const
{
    return data;
}
