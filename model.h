#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include "listadati.h"

struct ChartData {
    QString nome;
    virtual ~ChartData() {}
};

class model
{
protected:
    //struct ChartData;
    //QList<ChartData*> data;
public:
    model();
    virtual ~model() = default;
    virtual QList<ChartData*> getData() const =0;
    virtual int getYear() const;
    virtual double getMin() const; //forse questi due possono già essere implementati
    virtual double getMax() const;
};

#endif // MODEL_H
