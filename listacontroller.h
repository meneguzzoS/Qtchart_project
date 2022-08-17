#ifndef LISTACONTROLLER_H
#define LISTACONTROLLER_H


#include <record.h>

class listaController
{
public:
    listaController(QList<record>*);
    void addToList(record);
    void removeFromList();

private:
    QList<record> *addressLista;
};

#endif // LISTACONTROLLER_H
