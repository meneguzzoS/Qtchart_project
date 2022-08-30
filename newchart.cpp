#include "newchart.h"
#include <QLabel>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include "QDebug"

newChart::newChart(listaController* LC) : list(LC)
{
    setWindowTitle("Crea un nuovo grafico");
        resize(500,200);
        setModal(true);
        QDialog::reject();//con il tasto esc esco dalla finestra
        QLabel* label=new QLabel("Inserisci l'anno/gli anni da prendere in considerazione");
        QSpinBox *years=new QSpinBox();
        years->setValue(2000);
        years->setRange(1950,2021);
//        ndati->setRange(0,99);
//        ndati->setValue(0);
//        ndati->setAccelerated(true);
        QHBoxLayout* inputlayout= new QHBoxLayout();
       inputlayout->addWidget(label);
        inputlayout->addWidget(years);
        QGroupBox* tipografico=new QGroupBox(tr("tipologie di Chart"));
        QLabel* grafico=new QLabel("Sciegli il tipo di grafico che vuoi creare");
        linechart=new QRadioButton("LineChart");
        piechart=new QRadioButton("PieChart");
        barchart=new QRadioButton("BarChart");
        barchart->setCheckable(true);
        linechart->setCheckable(true);
        piechart->setCheckable(true);
        barchart->setChecked(false);
        linechart->setChecked(true);
        piechart->setChecked(false);
        QVBoxLayout* buttongrafico=new QVBoxLayout();
        buttongrafico->addWidget(grafico);
        buttongrafico->addWidget(linechart);
        buttongrafico->addWidget(piechart);
        buttongrafico->addWidget(barchart);
        buttongrafico->addStretch();
        buttongrafico->setSpacing(20);
        ok=new QPushButton(tr("ok"));
        annulla=new QPushButton(tr("Annulla"));
        //ok->setFont(QFont("Times",18,QFont::Black));
        //annulla->setFont(QFont("Times",18,QFont::Black));
        tipografico->setLayout(buttongrafico);
        QDialogButtonBox* button=new QDialogButtonBox(Qt::Horizontal);
        button->addButton(ok,QDialogButtonBox::ActionRole);
        button->addButton(annulla,QDialogButtonBox::ActionRole);
        QVBoxLayout* container=new QVBoxLayout();
        container->addLayout(inputlayout);
        container->addWidget(tipografico);
        container->addWidget(button);
        setLayout(container);

        connect(annulla,SIGNAL(clicked(bool)),this,SLOT(close()));
        connect(linechart,SIGNAL(clicked(bool)),this,SLOT(lineChecked()));
        connect(piechart,SIGNAL(clicked(bool)),this,SLOT(pieChecked()));
        connect(barchart,SIGNAL(clicked(bool)),this,SLOT(barChecked()));
        connect(ok,SIGNAL(clicked(bool)),this,SLOT(createChart()));
        connect(ok,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void newChart::lineChecked()
{
    linechart->setChecked(true);
    piechart->setChecked(false);
    barchart->setChecked(false);
}

void newChart::pieChecked()
{
    linechart->setChecked(false);
    piechart->setChecked(true);
    barchart->setChecked(false);
}

void newChart::barChecked()
{
    linechart->setChecked(false);
    piechart->setChecked(false);
    barchart->setChecked(true);
}

void newChart::createChart()
{
//    QList<record> *q = new QList<record>;
//    list = new listaController(q);
    int b=2007,c=2008, d=2009, e=2010;
    year = new QList<int>;
    year->push_back(b);
    year->push_back(c);
    year->push_back(d);
    year->push_back(e);
    if(linechart->isChecked()) {
        lineChartDataset* t = new lineChartDataset(*list,*year);
        lineChartView* z = new lineChartView;
        lineChartControl o(t,z);
        z->show();
    }
    if(piechart->isChecked()) {
        pieChartDataset* nuovo = new pieChartDataset(*list,year->at(0));
        pieChartView* view = new pieChartView;
        pieChartControl ctr(nuovo, view);
        view->show();
    }
    if(barchart->isChecked()) {
        barChartDataset* nuovo = new barChartDataset(*list,year->at(0));
        barChartView* view = new barChartView;
        barChartControl ctr(nuovo, view);
        view->show();
    }
}
