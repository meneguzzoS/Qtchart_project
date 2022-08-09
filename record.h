#ifndef RECORD_H
#define RECORD_H
#include<QString>
#include<QDate>

enum productType {Nuovo, Usato, Ricondizionato};

class record
{
private:
    QString productName;
    QDate data;
    double prezzo;
    productType statoProdotto;
public:
    record();
    record(QString, QDate, unsigned int, productType);
    QString getName() const;
    QDate getData() const;
    double getPrezzo() const;
    productType getStato() const;
    void setName(const QString&);
    void setData(const QDate&);
    void setPrezzo(double);
    void setTipo(unsigned int);
};

#endif // RECORD_H
