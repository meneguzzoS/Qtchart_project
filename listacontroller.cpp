#include "listacontroller.h"

ListaController::ListaController(QList<record> *lista)
{
    addressLista = lista;
}

void ListaController::addToList(record newRecord)
{
    addressLista->push_back(newRecord);
}

void ListaController::removeFromList()
{
    addressLista->pop_back();
}

ProductStackedChartDataset ListaController::createStackedChartDataset()
{

}
