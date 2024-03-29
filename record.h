#ifndef RECORD_H
#define RECORD_H

#include<QString>
#include<QDate>
#include <QDebug>


enum MacroArea {Europa, Asia, America, Africa, Oceania};

class record
{
private:
    QString nomeStato;
    QDate data;
    double PIL;
    MacroArea continente;
public:
    record();
    record(QString,const QDate&, unsigned int,const MacroArea&);
    QString getName() const;
    const QDate& getData() const;
    double getPIL() const;
    const MacroArea& getContinente() const;
    void setName(const QString&);
    void setData(const QDate&);
    void setPIL(double);
    void setContinente(unsigned int);
};

#endif // RECORD_H
