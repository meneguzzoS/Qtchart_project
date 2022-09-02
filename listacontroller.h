#ifndef LISTACONTROLLER_H
#define LISTACONTROLLER_H


#include <record.h>

class listaController
{
public:
    listaController(QList<record>*);
    void addToList(const record&);
    void removeFromList(int);
    QList<QString> getNomiStati() const;
    int listaSize() const;
    QList<record>* getList() const;
    bool isListaEmpty() const;
private:
    QList<record> *addressLista;
};

#endif // LISTACONTROLLER_H
