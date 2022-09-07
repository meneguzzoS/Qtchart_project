#ifndef LISTADATI_H
#define LISTADATI_H

#include "record.h"
#include <QDebug>

class listaDati
{
public:
    listaDati(QList<record>* = nullptr);
    void addToList(const record&);
    void removeFromList(int);
    QList<QString> getNomiStati() const;
    int listaSize() const;
    QList<record> * getList();
    const QList<record> * getList() const;
    bool isListaEmpty() const;
    const record& getListData(int i);
    QString getName(int) const;
    QDate getData(int) const;
    double getPIL(int) const;
    MacroArea getContinente(int) const;
    void InsertRecord(QString, QDate, double, int);
    void fromTableToList(QStringList);
private:
    QList<record> *addressLista;
};

#endif // LISTADATI_H