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

        //creazione record
        record b("prodotto1", QDate(2010,11,11), 8, Usato);
        record c("prodotto2", QDate(2011,8,21), 9, Nuovo);
        record d("prodotto3", QDate(2009,3,2), 14, Ricondizionato);

        lista.push_back(b);
        lista.push_back(c);
        lista.push_back(d);

        //creazione tabella
        tabella = new QTableWidget;
        tabella->setColumnCount(4);
        tabella->setRowCount(lista.size());
        tabella->setMinimumSize(600,500);

        QStringList header;
        header<<"Nome Prodotto"<<"Prezzo"<<"Data"<<"Tipo prodotto";
        tabella->setHorizontalHeaderLabels(header);

        //riempire tabella con record in lista
        QTableWidgetItem *item;
        for(int i=0; i<tabella->rowCount(); i++) {

            for(int j=0; j<tabella->columnCount(); j++) {
                item = new QTableWidgetItem;

                switch(j) {
                case 0: item->setText(QString(lista.at(i).getName()));
                    break;
                case 1: item->setText(QString::number(lista.at(i).getPrezzo()));
                    break;
                case 2: item->setText(QString(lista.at(i).getData().toString("dd.MM.yyyy")));
                    break;
                case 3: switch(lista.at(i).getStato()) { //OTTIMIZZARE
                    case Usato: item->setText(QString("Usato")); break;
                    case Nuovo: item->setText(QString("Nuovo")); break;
                    case Ricondizionato : item->setText(QString("Ricondizionato"));
                    }
                    break;
                }

                tabella->setItem(i,j,item);
                tabella->setCurrentCell(i,j);
            }
        }

        //creazione campi dati editabili
        Nome = new QLineEdit();
        QLabel *NomeLabel = new QLabel("Nome prodotto: ");
        Nome->setPlaceholderText("iPhone 10");
        Nome->setToolTip("Inserisci il Nome");
        data = new QDateEdit();
        QLabel *DataLabel = new QLabel("Data: ");
        data->setToolTip("Inserisci la data");
        data->setDisplayFormat("dd.MM.yyyy");
        prezzo = new QDoubleSpinBox();
        QLabel *PrezzoLabel = new QLabel("Prezzo: ");
        prezzo->setRange(0, 10000);
        tipo = new QComboBox();
        QLabel *TipoLabel = new QLabel("Tipo prodotto: ");
        tipo->insertItem(1,"Nuovo");
        tipo->insertItem(2,"Usato");
        tipo->insertItem(3,"Ricondizionato");

        QGridLayout *FieldLayout = new QGridLayout;
        FieldLayout->addWidget(NomeLabel, 0, 0);
        FieldLayout->addWidget(Nome, 0, 1);
        FieldLayout->addWidget(PrezzoLabel,1,0);
        FieldLayout->addWidget(prezzo,1,1);
        FieldLayout->addWidget(DataLabel,2,0);
        FieldLayout->addWidget(data,2,1);
        FieldLayout->addWidget(TipoLabel,3,0);
        FieldLayout->addWidget(tipo,3,1);

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

        //qDebug() << tabella->currentRow();

        setLayout(mainLayout);
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
        lista.pop_back();
}

void table::addRow()
{
    record nuovo;
    nuovo.setName(Nome->text());
    nuovo.setData(data->date());
    nuovo.setPrezzo(prezzo->value());
    nuovo.setTipo(tipo->currentIndex());
    lista.push_back(nuovo);

    int row = tabella->rowCount();
    tabella->insertRow(row);
    tabella->setItem(row, 0, new QTableWidgetItem(nuovo.getName()));
    tabella->setItem(row, 1, new QTableWidgetItem(QString::number(nuovo.getPrezzo())));
    tabella->setItem(row, 2, new QTableWidgetItem(nuovo.getData().toString("dd.MM.yyyy")));
    switch(nuovo.getStato()) {
    case Nuovo: tabella->setItem(row, 3, new QTableWidgetItem("Nuovo")); break;
    case Usato: tabella->setItem(row, 3, new QTableWidgetItem("Usato")); break;
    case Ricondizionato: tabella->setItem(row, 3, new QTableWidgetItem("Ricondizionato")); break;
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
        nuovo.setPrezzo(QString(data.at(1)).toInt());
        nuovo.setData(QDate::fromString(QString(data.at(2)), "dd.MM.yyyy"));
        if(data.at(3)=="Nuovo")
            nuovo.setTipo(0);
        if(data.at(3)=="Usato")
            nuovo.setTipo(1);
        if(data.at(3)=="Ricondizionato")
            nuovo.setTipo(2);
        lista.push_back(nuovo);
    }
    for(int i=0; i<lista.size();i++) {
        qDebug() << lista.at(i).getName() << lista.at(i).getPrezzo() << lista.at(i).getData() << lista.at(i).getStato();
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
