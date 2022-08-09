#include "record.h"
#include <QDebug>

record::record() {}

record::record(QString PN, QDate d, unsigned int p, productType SP) : productName(PN), data(d), prezzo(p), statoProdotto(SP) {}

QString record::getName() const
{
    return productName;
}

QDate record::getData() const
{
    return data;
}

double record::getPrezzo() const
{
    return prezzo;
}

productType record::getStato() const
{
    return statoProdotto;
}

void record::setName(const QString & n)
{
    productName = n;
}

void record::setData(const QDate & d)
{
    data = d;
}

void record::setPrezzo(double i)
{
    prezzo = i;
}

void record::setTipo(unsigned int i)
{
    switch(i) {
    case 0: statoProdotto = Nuovo; break;
    case 1: statoProdotto = Usato; break;
    case 2: statoProdotto = Ricondizionato; break;
    default: qDebug() << "valore non valido\n";
    }
}
