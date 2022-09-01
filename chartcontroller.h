#ifndef CHARTCONTROLLER_H
#define CHARTCONTROLLER_H

#include "model.h"
#include "view.h"

class ChartController
{
private:
    model* dati;
    view* vista;
public:
    ChartController(model*,view*);
};

#endif // CHARTCONTROLLER_H
