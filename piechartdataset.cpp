#include "piechartdataset.h"

pieChartDataset::pieChartDataset(const listaDati& lista, int i) : year(i)
{
    for(int cont = 0; cont<5 ; cont++) {
        int x=0;
        int n=0;
        for(QList<record>::const_iterator cit = lista.getList()->begin(); cit != lista.getList()->end(); ++cit) {
            qDebug() << (*cit).getName() << (*cit).getContinente();
            if((*cit).getContinente() == cont && (*cit).getData().year() == i) {
                x+=(*cit).getPIL();
                n++;
                qDebug() << "cit" << cont <<(*cit).getName() << x << n;
            }
        }
        if(cont==0 && n>0) {
            AvgContinent* EU = new AvgContinent;
            EU->nome = "Europa";
            EU->media = x/n;
            data.push_back(EU);
        }
        if(cont == 1 && n>0) {
            AvgContinent* AS = new AvgContinent;
            AS->nome = "Asia";
            AS->media = x/n;
            data.push_back(AS);
        }
        if(cont == 2 && n>0) {
            AvgContinent* AM = new AvgContinent;
            AM->nome = "America";
            AM->media = x/n;
            data.push_back(AM);
        }
        if(cont == 3 && n>0) {
            AvgContinent* AF = new AvgContinent;
            AF->nome = "Africa";
            AF->media = x/n;
            data.push_back(AF);
        }
        if(cont == 4 && n>0) {
            AvgContinent* OC = new AvgContinent;
            OC->nome = "Oceania";
            OC->media = x/n;
            data.push_back(OC);
        }
    }
}

QList<ChartData*> pieChartDataset::getData() const
{
    return data;
}

int pieChartDataset::getYear() const
{
    return year;
}
