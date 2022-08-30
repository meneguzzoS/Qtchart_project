#include "listacontroller.h"
#include <QDebug>

listaController::listaController(QList<record> *lista = 0) : addressLista(lista)
{
    record b("italia", QDate(2008,1,3), 3000, Europa);
    record c("francia", QDate(2008,2,1), 4000, Europa);
    record d("congo", QDate(2008,4,1), 2000, Africa);
    record e("zimbawe", QDate(2008,6,8), 1500, Africa);
    record f("cina", QDate(2008,3,1), 4600, Asia);
        //record f("Zimbawe", QDate(2009,6,8), 1500, Asia);
            record b1("italia", QDate(2009,1,3), 3500, Europa);
            record c1("francia", QDate(2009,2,1), 3000, Europa);
            record d1("congo", QDate(2009,4,1), 1700, Africa);
            record e1("zimbawe", QDate(2009,6,8), 1200, Africa);
            record f1("cina", QDate(2009,3,1), 4800, Asia);
                record b2("italia", QDate(2007,1,3), 3650, Europa);
                record c2("francia", QDate(2007,2,1), 2800, Europa);
                record d2("congo", QDate(2007,4,1), 2450, Africa);
                record e2("zimbawe", QDate(2007,6,8), 2222.2, Africa);
                record f2("cina", QDate(2007,3,1), 4000, Asia);
                    record b3("italia", QDate(2010,1,3), 3870, Europa);
                addToList(b);
                    addToList(c);
                    addToList(d);
                    addToList(e);
                    addToList(f);
                        addToList(b1);
                        addToList(c1);
                        addToList(d1);
                        addToList(e1);
                        addToList(f1);
                            addToList(b2);
                            addToList(c2);
                            addToList(d2);
                            addToList(e2);
                            addToList(f2);
                                addToList(b3);
}

void listaController::addToList(const record& newRecord)
{
    addressLista->push_back(newRecord);
}

void listaController::removeFromList(int i)
{
    addressLista->removeAt(i);
}

QList<QString> listaController::getNomiStati() const
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

int listaController::listaSize() const
{
    return addressLista->size();
}

QList<record>* listaController::getList() const
{
    return addressLista;
}
