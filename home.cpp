#include "home.h"
#include <QVBoxLayout>
#include <QDebug>

home::home(QList<record>* l = nullptr, QList<int>* y = nullptr) :list(new listaController(l)), year(y)
{
    QVBoxLayout* layout = new QVBoxLayout;
    QPushButton* open = new QPushButton(tr("Apri tabella"));
    QPushButton* pieChart = new QPushButton(tr("Pie Chart"));
    QPushButton* barChart = new QPushButton((tr("Bar Chart")));
    QPushButton* lineChart = new QPushButton(tr("Line Chart"));
    layout->addWidget(open);
    layout->addWidget(pieChart);
    layout->addWidget(barChart);
    layout->addWidget(lineChart);
    setLayout(layout);
    setMinimumSize(600,500);

    connect(open, SIGNAL(clicked(bool)),this, SLOT(showTable()));
    connect(pieChart,SIGNAL(clicked(bool)),this,SLOT(pieChart()));
    connect(barChart,SIGNAL(clicked(bool)),this,SLOT(barChart()));
    connect(lineChart,SIGNAL(clicked(bool)),this,SLOT(lineChart()));
}

void home::showTable()
{
//    window = new table;
//    window->show();
}

void home::pieChart()
{
    pieChartDataset* nuovo = new pieChartDataset(*list,year->at(0));
    pieChartView* view = new pieChartView;
    pieChartControl ctr(nuovo, view);
    view->show();
}

void home::barChart()
{
    barChartDataset* nuovo = new barChartDataset(*list,year->at(0));
    barChartView* view = new barChartView;
    barChartControl ctr(nuovo, view);
    view->show();
}

void home::lineChart()
{
    lineChartDataset* t = new lineChartDataset(*list,*year);
    lineChartView* z = new lineChartView;
    lineChartControl o(t,z);
    z->show();
}
