#ifndef LISTACONTROLLER_H
#define LISTACONTROLLER_H

#include <QObject>
#include "listadati.h"
#include "table.h"

class listacontroller
{
public:
    listacontroller();
private:
    listaDati* dati;
    table* tabella;
};

#endif // LISTACONTROLLER_H
