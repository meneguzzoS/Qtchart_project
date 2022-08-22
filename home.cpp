#include "home.h"
#include <QVBoxLayout>
#include <QDebug>

home::home()
{
    QVBoxLayout* layout = new QVBoxLayout;
    QPushButton* open = new QPushButton(tr("Apri tabella"));
    QPushButton* pieChart = new QPushButton(tr("Pie Chart"));
    QPushButton* barChart = new QPushButton((tr("Bar Chart")));
    layout->addWidget(open);
    layout->addWidget(pieChart);
    layout->addWidget(barChart);
    setLayout(layout);

    connect(open, SIGNAL(clicked(bool)),this, SLOT(showTable()));
    connect(pieChart,SIGNAL(clicked(bool)),this,SLOT(pieChart()));
    connect(barChart,SIGNAL(clicked(bool)),this,SLOT(barChart()));
}

void home::showTable()
{
    window = new table;
    window->show();
}

void home::pieChart()
{
    record b("italia", QDate(2008,1,3), 3000, Europa);
    record c("francia", QDate(2008,2,1), 4000, Europa);
    record d("congo", QDate(2008,4,1), 2000, Africa);
    record e("zimbawe", QDate(2008,6,8), 1500, Asia);
    QList<record> lista;
    lista.push_back(b);
    lista.push_back(c);
    lista.push_back(d);
    lista.push_back(e);

    pieChartDataset* nuovo = new pieChartDataset(lista);
        /*for(int i=0; i<nuovo.getData().size(); i++)
            qDebug() << nuovo.getData().at(i).nomeContinente << nuovo.getData().at(i).media;*/
    pieChartView* view = new pieChartView;
    pieChartControl ctr(nuovo, view);
    view->show();
}

void home::barChart()
{
    record b("italia", QDate(2008,1,3), 3000, Europa);
    record c("francia", QDate(2008,2,1), 4000, Europa);
    record d("congo", QDate(2008,4,1), 2000, Africa);
    record e("zimbawe", QDate(2008,6,8), 1500, Asia);
    QList<record> lista;
    lista.push_back(b);
    lista.push_back(c);
    lista.push_back(d);
    lista.push_back(e);

    barChartDataset* nuovo = new barChartDataset(lista, 2008);
    barChartView* view = new barChartView;
    barChartControl ctr(nuovo, view);
    view->show();
}
