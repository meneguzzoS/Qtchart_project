#ifndef LISTACONTROLLER_H
#define LISTACONTROLLER_H

#include <QObject>
#include "listadati.h"
#include "table.h"

class listacontroller : public QObject
{
Q_OBJECT
public:
    listacontroller(listaDati*,table*);
private:
    listaDati* dati;
    table* vista;
public slots:
    void deleteRow();
    void newRow();
    void fromFiletoTable(QStringList);
    void changeRecord();
};

#endif // LISTACONTROLLER_H
