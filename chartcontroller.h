#ifndef CHARTCONTROLLER_H
#define CHARTCONTROLLER_H

#include "model.h"
#include "view.h"
#include "piechartview.h"
#include "barchartview.h"
#include "linechartview.h"
#include "listacontroller.h"

class ChartController
{
private:
    model* dati;
    view* vista;
public:
    ChartController(model*,view*);
};

#endif // CHARTCONTROLLER_H
