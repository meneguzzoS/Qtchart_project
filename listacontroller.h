#ifndef LISTACONTROLLER_H
#define LISTACONTROLLER_H

#include <record.h>
#include <stackedbarchart.h>

class ListaController
{
public:
    ListaController(QList<record> *lista);
    void addToList(record newRecord);
    void removeFromList();
    ProductStackedChartDataset createStackedChartDataset();

private:
    QList<record> *addressLista;
};

#endif // LISTACONTROLLER_H
