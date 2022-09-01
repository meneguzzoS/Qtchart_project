#include "chartcontroller.h"

ChartController::ChartController(model* m,view* v) : dati(m), vista(v)
{
    for(auto& l : m->getData())
            v->insertData(l);
        v->setDesign(m);
}
