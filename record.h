#ifndef RECORD_H
#define RECORD_H
#include<QString>
#include<QDate>

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
    record(QString, QDate, unsigned int, MacroArea);
    QString getName() const;
    QDate getData() const;
    double getPIL() const;
    MacroArea getContinente() const;
    void setName(const QString&);
    void setData(const QDate&);
    void setPIL(double);
    void setContinente(unsigned int);
};

#endif // RECORD_H
