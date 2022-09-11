#include "listacontroller.h"

listacontroller::listacontroller(listaDati* d,table* t) : dati(d), vista(t)
{
    fileHandler* file = new fileHandler(t,this);

    connect(vista,SIGNAL(deleteLastRow()),this,SLOT(deleteRow()));
    connect(vista,SIGNAL(submitPressed()),this,SLOT(newRow()));
    connect(vista,SIGNAL(fileTable(QStringList)),this,SLOT(fromFiletoTable(QStringList)));
    connect(vista,SIGNAL(setValue()),this,SLOT(changeRecord()));
    connect(vista,SIGNAL(charts()),this,SLOT(selectChart()));
}

listacontroller::~listacontroller()
{
    if(select)
        delete select;
}

void listacontroller::deleteRow()
{
    int row = vista->getTable()->currentRow();
        vista->getTable()->removeRow(row);
        if(dati->listaSize()>0)
            dati->removeFromList(row);
}

void listacontroller::newRow()
{
    bool found = false;
     for(QList<record>::const_iterator cit = dati->getList()->begin(); cit!=dati->getList()->end(); cit++) {
        if((*cit).getName() == vista->getName() && (*cit).getData().year() == vista->getDate().year()) {
            vista->showWarning(vista,"Record non valido","Il PIL dello stato inserito in quello specifico anno è già stato registrato");
            found = true;
        }
    }
    if(!found) {
        record nuovo;
        nuovo.setName(vista->getName());
        nuovo.setData(vista->getDate());
        nuovo.setPIL(vista->getPil());
        nuovo.setContinente(vista->getContinent());
        dati->addToList(nuovo);

        vista->addRow(nuovo.getName(),nuovo.getPIL(),nuovo.getData(),nuovo.getContinente());
    }

}

void listacontroller::fromFiletoTable(QStringList data)
{
    record nuovo;
    nuovo.setName(data.at(0));
    nuovo.setPIL(QString(data.at(1)).toInt());
    nuovo.setData(QDate::fromString(QString(data.at(2)), "dd.MM.yyyy"));
    if(data.at(3)=="Europa")
        nuovo.setContinente(0);
    if(data.at(3)=="Asia")
        nuovo.setContinente(1);
    if(data.at(3)=="America")
        nuovo.setContinente(2);
    if(data.at(3)=="Africa")
        nuovo.setContinente(3);
    if(data.at(3)=="Oceania")
        nuovo.setContinente(4);
    dati->addToList(nuovo);
}

void listacontroller::changeRecord()
{
    record& change = const_cast<record&>(dati->getListData(vista->getTable()->currentRow()));

    switch(vista->getTable()->currentColumn()) {
    case 0: change.setName(vista->getTable()->currentItem()->text()); break;
    case 1: change.setPIL((vista->getTable()->currentItem()->text()).toInt()); break;
    case 2: change.setData(QDate::fromString(QString(vista->getTable()->currentItem()->text()), "dd.MM.yyyy")); break;
    case 3: if(vista->getTable()->currentItem()->text()=="Europa")
            change.setContinente(0);
        if(vista->getTable()->currentItem()->text()=="Asia")
            change.setContinente(1);
        if(vista->getTable()->currentItem()->text()=="America")
            change.setContinente(2);
        if(vista->getTable()->currentItem()->text()=="Africa")
            change.setContinente(3);
        if(vista->getTable()->currentItem()->text()=="Oceania")
            change.setContinente(4);
    }
}

void listacontroller::selectChart()
{
    select = new newChart(dati,vista);
    select->show();
    connect(select,SIGNAL(bar()),this,SLOT(barChart()));
    connect(select,SIGNAL(line()),this,SLOT(lineChart()));
    connect(select,SIGNAL(pie()),this,SLOT(pieChart()));
}

void listacontroller::barChart()
{
    barChartDataset* m = new barChartDataset(*dati,select->getFirstDate());
    if(m->isEmpty()) {
        select->showWarning(select,"Errore data","Nella data inserita non sono presenti PIL da poter inserire nel grafico");
        delete m;
    }
    else {
        barChartView *v = new barChartView;
        ChartController c(m,v);
        v->show();
    }
}

void listacontroller::lineChart()
{
    if(select->getFirstDate() >= select->getSecondDate())
        select->showWarning(select,"Errore data","Data iniziale maggiore o uguale di data finale");
    else {
        QList<int> years;
        for(int i = select->getFirstDate(); i <= select->getSecondDate(); i++)
            years.push_back(i);
        lineChartDataset* m = new lineChartDataset(*dati,years);
            if(m->isEmpty()) {
                select->showWarning(select,"Nessun dati presente","Non sono presenti PIL di nessun paese nell'arco temporale indicato");
                delete m;
            }
            else {
                lineChartView* v = new lineChartView;
                ChartController c(m,v);
                v->show();
            }
    }
}

void listacontroller::pieChart()
{
    pieChartDataset* m = new pieChartDataset(*dati,select->getFirstDate());
    if(m->isEmpty()) {
        select->showWarning(select,"Errore data","Nella data inserita non sono presenti PIL da poter inserire nel grafico");
        delete m;
    }
    else {
        pieChartView* v = new pieChartView;
        ChartController c(m,v);
        v->show();
    }
}
