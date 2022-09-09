#include "record.h"

record::record() {}

record::record(QString NS,const QDate& d, unsigned int p,const MacroArea& c) : nomeStato(NS), data(d), PIL(p), continente(c) {}

QString record::getName() const
{
    return nomeStato;
}

const QDate& record::getData() const
{
    return data;
}

double record::getPIL() const
{
    return PIL;
}

const MacroArea& record::getContinente() const
{
    return continente;
}

void record::setName(const QString & n)
{
    nomeStato = n;
}

void record::setData(const QDate & d)
{
    data = d;
}

void record::setPIL(double i)
{
    PIL = i;
}

void record::setContinente(unsigned int i)
{
    switch(i) {
    case 0: continente = Europa; break;
    case 1: continente = Asia; break;
    case 2: continente = America; break;
    case 3: continente = Africa; break;
    case 4: continente = Oceania; break;
    default: qDebug() << "valore non valido\n";
    }
}
