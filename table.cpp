#include "table.h"
#include<QTableWidget>
#include<QTableWidgetItem>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QDebug>
#include <QtWidgets>
#include <QFileDialog>
#include <QDir>

table::table()
{
        setWindowTitle("Tabella prodotti");
        dataController = new listaController(&lista);

        //creazione record
        record b("stato1", QDate(2010,11,11), 8000, Europa);
        record c("stato2", QDate(2011,8,21), 90000, Africa);
        record d("stato3", QDate(2009,3,2), 14000000, Oceania);

        dataController->addToList(b);
        dataController->addToList(c);
        dataController->addToList(d);

        //creazione tabella
        tabella = new QTableWidget;
        tabella->setColumnCount(4);
        tabella->setRowCount(lista.size());
        tabella->setMinimumSize(600,500);

        QStringList header;
        header<<"Nome Stato"<<"PIL"<<"Data"<<"Continente";
        tabella->setHorizontalHeaderLabels(header);

        //riempire tabella con record in lista
        QTableWidgetItem *item;
        for(int i=0; i<tabella->rowCount(); i++) {

            for(int j=0; j<tabella->columnCount(); j++) {
                item = new QTableWidgetItem;

                switch(j) {
                case 0: item->setText(QString(lista.at(i).getName()));
                    break;
                case 1: item->setText(QString::number(lista.at(i).getPIL()));
                    break;
                case 2: item->setText(QString(lista.at(i).getData().toString("dd.MM.yyyy")));
                    break;
                case 3: switch(lista.at(i).getContinente()) { //OTTIMIZZARE
                    case Europa: item->setText(QString("Europa")); break;
                    case Asia: item->setText(QString("Asia")); break;
                    case America : item->setText(QString("America")); break;
                    case Africa: item->setText(QString("Africa")); break;
                    case Oceania: item->setText(QString("Oceania")); break;
                    }
                    break;
                }

                tabella->setItem(i,j,item);
                tabella->setCurrentCell(i,j);
            }
        }

        //creazione campi dati editabili
        Nome = new QLineEdit();
        QLabel *NomeLabel = new QLabel("Nome stato: ");
        Nome->setPlaceholderText("Italia");
        Nome->setToolTip("Inserisci il Nome");
        data = new QDateEdit();
        QLabel *DataLabel = new QLabel("Data: ");
        data->setToolTip("Inserisci la data");
        data->setDisplayFormat("dd.MM.yyyy");
        PIL = new QDoubleSpinBox();
        QLabel *PILLabel = new QLabel("PIL: ");
        PIL->setRange(0, 1000000000000000);
        continente = new QComboBox();
        QLabel *ContinenteLabel = new QLabel("Continente: ");
        continente->insertItem(1,"Europa");
        continente->insertItem(2,"Asia");
        continente->insertItem(3,"America");
        continente->insertItem(4,"Africa");
        continente->insertItem(5,"Oceania");

        QGridLayout *FieldLayout = new QGridLayout;
        FieldLayout->addWidget(NomeLabel, 0, 0);
        FieldLayout->addWidget(Nome, 0, 1);
        FieldLayout->addWidget(PILLabel,1,0);
        FieldLayout->addWidget(PIL,1,1);
        FieldLayout->addWidget(DataLabel,2,0);
        FieldLayout->addWidget(data,2,1);
        FieldLayout->addWidget(ContinenteLabel,3,0);
        FieldLayout->addWidget(continente,3,1);

        //creazione pulsanti
        submitButton = new QPushButton(tr("Invia"));
        submitButton->setDefault(true);
        removeButton = new QPushButton(tr("Rimuovi"));
        quitButton = new QPushButton(tr("Annulla"));
        loadButton = new QPushButton(tr("Carica Dati"));
        printFileButton = new QPushButton(tr("Stampa su file"));

        buttonBox = new QDialogButtonBox(Qt::Horizontal);
        buttonBox->addButton(loadButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(printFileButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(removeButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

        //sistemazione layout
        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(tabella);
        mainLayout->addLayout(FieldLayout);
        mainLayout->addWidget(buttonBox);
        setLayout(mainLayout);

        //qDebug() << tabella->currentRow();

        connect(quitButton,SIGNAL(clicked(bool)),this,SLOT(close()));
        connect(removeButton,SIGNAL(clicked(bool)),this,SLOT(deleteLastRow()));
        connect(submitButton,SIGNAL(clicked(bool)),this,SLOT(addRow()));
        connect(loadButton,SIGNAL(clicked(bool)),this,SLOT(importData()));
        connect(printFileButton,SIGNAL(clicked(bool)),this,SLOT(exportFile()));
}

void table::deleteLastRow()
{
    int row = tabella->currentRow();
    tabella->removeRow(row);
    if(lista.size()>0)
        dataController->removeFromList();
}

void table::addRow()
{
    record nuovo;
    nuovo.setName(Nome->text());
    nuovo.setData(data->date());
    nuovo.setPIL(PIL->value());
    nuovo.setContinente(continente->currentIndex());
    dataController->addToList(nuovo);

    int row = tabella->rowCount();
    tabella->insertRow(row);
    tabella->setItem(row, 0, new QTableWidgetItem(nuovo.getName()));
    tabella->setItem(row, 1, new QTableWidgetItem(QString::number(nuovo.getPIL())));
    tabella->setItem(row, 2, new QTableWidgetItem(nuovo.getData().toString("dd.MM.yyyy")));
    switch(nuovo.getContinente()) {
    case Europa: tabella->setItem(row, 3, new QTableWidgetItem("Europa")); break;
    case Asia: tabella->setItem(row, 3, new QTableWidgetItem("Asia")); break;
    case America: tabella->setItem(row, 3, new QTableWidgetItem("America")); break;
    case Africa: tabella->setItem(row, 3, new QTableWidgetItem("Africa")); break;
    case Oceania: tabella->setItem(row, 3, new QTableWidgetItem("Oceania")); break;
    }
    tabella->setCurrentCell(row,3);
}

void table::importData()
{
    QString filename = QFileDialog::getOpenFileName(this, "Apri il tuo file", QDir::homePath(), "CSV File (*.csv)");
    qDebug()<<filename;

    QFile targetFile(filename);

    if(!targetFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Impossibile leggere il file";
        return;
    }

    QTextStream in(&targetFile);
    record nuovo;

    int row;
    while(!in.atEnd()) {
        QString line = in.readLine(); // \n
        line = line.simplified();
        line.replace(" ",""); //rimuove gli spazi bianchi
        QStringList data = line.split(',');

        row = tabella->rowCount();
        tabella->insertRow(row);
        tabella->setItem(row, 0, new QTableWidgetItem(data.at(0)));
        tabella->setItem(row, 1, new QTableWidgetItem(data.at(1)));
        tabella->setItem(row, 2, new QTableWidgetItem(data.at(2)));
        tabella->setItem(row, 3, new QTableWidgetItem(data.at(3)));
        tabella->setCurrentCell(row,3);

        //inserisco elementi appena presi dal file nella lista
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
        dataController->addToList(nuovo);
    }
    for(int i=0; i<lista.size();i++) {
        qDebug() << lista.at(i).getName() << lista.at(i).getPIL() << lista.at(i).getData() << lista.at(i).getContinente();
    }
}

void table::exportFile()
{
    // Creazione oggetto "destinazione"
    QString filename = QFileDialog::getOpenFileName(this, "Seleziona il tuo file di destinazione", QDir::homePath(), "CSV File (*.csv)");
    QFile targetFile(filename);

    // Apertura file in scrittura
    if(!targetFile.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "File impossibile da aprire";
        return;
    }

    // Creazione stream di dati VERSO il file
    QTextStream out(&targetFile);
    QStringList strList;

    for(int r=0; r< tabella->rowCount(); r++) {
        strList.clear();
        for(int c=0;c<tabella->columnCount(); c++) {
            tabella->setCurrentCell(r,c);
            strList << tabella->currentItem()->text();
        }
        out << strList.join(",")+"\n";
    }

    targetFile.flush();
    targetFile.close();
}
