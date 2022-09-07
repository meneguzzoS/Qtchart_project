#include "listacontroller.h"

listacontroller::listacontroller(listaDati* d,table* t) : dati(d), vista(t)
{
//    dati = new listaDati;
//    tabella = new table(dati);

    connect(vista,SIGNAL(deleteLastRow()),this,SLOT(deleteRow()));
    connect(vista,SIGNAL(submitPressed()),this,SLOT(newRow()));
    connect(vista,SIGNAL(fileTable(QStringList)),this,SLOT(fromFiletoTable(QStringList)));
    connect(vista,SIGNAL(setValue()),this,SLOT(changeRecord()));
}

void listacontroller::deleteRow()
{
    int row = vista->getTable()->currentRow();
        vista->getTable()->removeRow(row);
        if(dati->listaSize()>0)
            dati->removeFromList(row);
}

void listacontroller::newRow()
{
    record nuovo;
    nuovo.setName(vista->getName());
    nuovo.setData(vista->getDate());
    nuovo.setPIL(vista->getPil());
    nuovo.setContinente(vista->getContinent());
    dati->addToList(nuovo);

    vista->addRow(nuovo.getName(),nuovo.getPIL(),nuovo.getData(),nuovo.getContinente());
}

void listacontroller::fromFiletoTable(QStringList data)
{
    record nuovo;
    nuovo.setName(data.at(0));
    nuovo.setPIL(QString(data.at(1)).toInt());
    nuovo.setData(QDate::fromString(QString(data.at(2)), "dd.MM.yyyy"));
    if(data.at(3)=="Europa")
        nuovo.setContinente(0);
    if(data.at(3)=="Asia")
        nuovo.setContinente(1);
    if(data.at(3)=="America")
        nuovo.setContinente(2);
    if(data.at(3)=="Africa")
        nuovo.setContinente(3);
    if(data.at(3)=="Oceania")
        nuovo.setContinente(4);
    dati->addToList(nuovo);
}

void listacontroller::changeRecord()
{
//    qDebug() << vista->getTable()->currentRow() << vista->getTable()->currentColumn();
    record& change = const_cast<record&>(dati->getListData(vista->getTable()->currentRow()));

    switch(vista->getTable()->currentColumn()) {
    case 0: change.setName(vista->getTable()->currentItem()->text()); break;
    case 1: change.setPIL((vista->getTable()->currentItem()->text()).toInt()); break;
    case 2: change.setData(QDate::fromString(QString(vista->getTable()->currentItem()->text()), "dd.MM.yyyy")); break;
    case 3: if(vista->getTable()->currentItem()->text()=="Europa")
            change.setContinente(0);
        if(vista->getTable()->currentItem()->text()=="Europa")
            change.setContinente(1);
        if(vista->getTable()->currentItem()->text()=="Europa")
            change.setContinente(2);
        if(vista->getTable()->currentItem()->text()=="Europa")
            change.setContinente(3);
        if(vista->getTable()->currentItem()->text()=="Europa")
            change.setContinente(4);

    }
//    (static_cast<record&>(dati->getListData(vista->getTable()->currentRow()))).setName("ciao");
//    for(record a : *(dati->getList()))
//        qDebug() << a.getName();
}
