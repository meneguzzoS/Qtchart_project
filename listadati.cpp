#include "listadati.h"
#include "table.h"

listaDati::listaDati(QList<record> *lista) : addressLista(lista ? lista : new QList<record>)
{

}

listaDati::~listaDati()
{
    if(addressLista)
    delete addressLista;
}

void listaDati::addToList(const record& newRecord)
{
    addressLista->push_back(newRecord);
}

void listaDati::removeFromList(int i)
{
    if(i>=0)
    addressLista->removeAt(i);
}

QList<QString> listaDati::getNomiStati() const
{
    QList<QString> aux;
    bool found;
    for(QList<record>::const_iterator cit = addressLista->begin(); cit!=addressLista->end(); ++cit) {
        found = true;
        for(QList<QString>::iterator it = aux.begin(); it!=aux.end(); ++it) {
            if((*cit).getName() == *it)
                found = false;
        }
        if(found)
            aux.push_back((*cit).getName());
    }
    return aux;
}

int listaDati::listaSize() const
{
    return addressLista->size();
}

QList<record>* listaDati::getList()
{
    return addressLista;
}

const QList<record>* listaDati::getList() const
{
    return addressLista;
}

bool listaDati::isListaEmpty() const
{
    return addressLista->isEmpty();
}

const record& listaDati::getListData(int i)
{
    if(i>=0)
    return addressLista->at(i);
}

QString listaDati::getName(int i) const
{
    if(i>=0)
    return addressLista->at(i).getName();
}

QDate listaDati::getData(int i) const
{
    if(i>=0)
    return addressLista->at(i).getData();
}

double listaDati::getPIL(int i) const
{
    if(i>=0)
    return addressLista->at(i).getPIL();
}

MacroArea listaDati::getContinente(int i) const
{
    if(i>=0)
    return addressLista->at(i).getContinente();
}
