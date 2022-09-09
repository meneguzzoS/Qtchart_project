#include "newchart.h"

newChart::newChart(listaDati* LC, QWidget* parent) : list(LC), QDialog(parent)
{
    setWindowTitle("Crea un nuovo grafico");
        resize(500,200);
        setModal(true);
        QDialog::reject();//con il tasto esc esco dalla finestra
        QLabel* firstLabel=new QLabel("Inserisci l'anno/gli anni da prendere in considerazione");
        firstdate=new QSpinBox;
        firstdate->setValue(2000);
        firstdate->setRange(1950,2021);
        QLabel* secondLable = new QLabel("fino a: ");
        secondDate = new QSpinBox;
        secondDate->setRange(1950,2021);
        QHBoxLayout* inputlayout= new QHBoxLayout();
        inputlayout->addWidget(firstLabel);
        inputlayout->addWidget(firstdate);
        inputlayout->addWidget(secondLable);
        inputlayout->addWidget(secondDate);
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

int newChart::getFirstDate()
{
    return firstdate->value();
}

int newChart::getSecondDate()
{
    return secondDate->value();
}

void newChart::showWarning(QWidget *parent, const QString& title, const QString& text)
{
    QMessageBox::warning(parent, title, text, QMessageBox::Ok);
}

void newChart::barChecked()
{
    linechart->setChecked(false);
    piechart->setChecked(false);
    barchart->setChecked(true);
    secondDate->setDisabled(true);
}

void newChart::lineChecked()
{
    linechart->setChecked(true);
    piechart->setChecked(false);
    barchart->setChecked(false);
    secondDate->setDisabled(false);
}

void newChart::pieChecked()
{
    linechart->setChecked(false);
    piechart->setChecked(true);
    barchart->setChecked(false);
    secondDate->setDisabled(true);
}

void newChart::createChart()
{
        if(barchart->isChecked())
            emit bar();
        if(linechart->isChecked())
            emit line();
        if(piechart->isChecked())
            emit pie();
}
