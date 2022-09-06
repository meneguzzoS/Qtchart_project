#ifndef LISTACONTROLLER_H
#define LISTACONTROLLER_H

#include "record.h"
#include <QDebug>

class listaController
{
public:
    listaController(QList<record>* lista = nullptr);
    void addToList(const record&);
    void removeFromList(int);
    QList<QString> getNomiStati() const;
    int listaSize() const;
    QList<record>* getList() const;
    bool isListaEmpty() const;
    record getListData(int i) const;
    QString getName(int) const;
    QDate getData(int) const;
    double getPIL(int) const;
    MacroArea getContinente(int) const;
    void InsertRecord(QString, QDate, double, int);
    void fromTableToList(QStringList);
private:
    QList<record> *addressLista;
//    table* tabella;
};

#endif // LISTACONTROLLER_H
