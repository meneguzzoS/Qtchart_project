#include "model.h"

model::model()
{

}

model::~model()
{
    for(auto& a : data)
        delete a;

}

int model::getYear() const
{
    return 0;
}

double model::getMin() const
{
    return 0;
}

double model::getMax() const
{
    return 0;
}

bool model::isEmpty() const
{
    return data.isEmpty();
}
