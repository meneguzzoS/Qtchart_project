#include "listacontroller.h"

listaController::listaController(QList<record> *lista) : addressLista(lista)
{}

void listaController::addToList(record newRecord)
{
    addressLista->push_back(newRecord);
}

void listaController::removeFromList()
{
    addressLista->pop_back();
}
