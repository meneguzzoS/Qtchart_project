#include "chartcontroller.h"

ChartController::ChartController(model* m,view* v) : dati(m), vista(v)
{
    for(auto& l : m->getData())
            v->insertData(l);
    barChartView* bar = dynamic_cast<barChartView*>(v);
    if(bar) {
        bar->setDesign(m->getYear(),m->getMax());
    }
    lineChartView* line = dynamic_cast<lineChartView*>(v);
    if(line) {
        line->setDesign(m->getMin(),m->getMax());
    }
    pieChartView* pie = dynamic_cast<pieChartView*>(v);
    if(pie) {
        for(const auto& name : m->getData())
        pie->setDesign(name->nome);
    }
}
