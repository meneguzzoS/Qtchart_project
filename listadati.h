#ifndef LISTADATI_H
#define LISTADATI_H

#include "record.h"

class listaDati
{
public:
    listaDati(QList<record>* = nullptr);
    ~listaDati();
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
private:
    QList<record> *addressLista;
};

#endif // LISTADATI_H
