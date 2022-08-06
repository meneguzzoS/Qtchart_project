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
    unsigned int prezzo;
    productType statoProdotto;
public:
    record(QString, QDate, unsigned int, productType);
    QString getName() const;
    QDate getData() const;
    unsigned int getPrezzo() const;
    productType getStato() const;
};

#endif // RECORD_H
