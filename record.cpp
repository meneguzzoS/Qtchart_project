#include "record.h"

record::record(QString PN, QDate d, unsigned int p, productType SP) : productName(PN), data(d), prezzo(p), statoProdotto(SP) {}

QString record::getName() const
{
    return productName;
}

QDate record::getData() const
{
    return data;
}

unsigned int record::getPrezzo() const
{
    return prezzo;
}

productType record::getStato() const
{
    return statoProdotto;
}
