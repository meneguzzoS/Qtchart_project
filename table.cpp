#include "table.h"
#include<QTableWidget>
#include<QTableWidgetItem>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include "record.h"
#include <QList>
#include <QDebug>
#include <QtWidgets>

table::table()
{
        record b(QString("prodotto1"), QDate(2010,11,11), 8, Usato);
        record c("prodotto2", QDate(2011,8,21), 9, Nuovo);
        record d("prodotto3", QDate(2009,3,2), 14, Ricondizionato);

        QList<record> lista;
        lista.push_back(b);
        lista.push_back(c);
        lista.push_back(d);

        QTableWidget *table = new QTableWidget;
        table->setColumnCount(4);
        table->setRowCount(lista.size());

        QStringList header;
        header<<"Nome Prodotto"<<"Prezzo"<<"Data"<<"Tipo prodotto";
        table->setHorizontalHeaderLabels(header);
        table->setMinimumSize(600,500);

        //setRowCount(0);
        /*QLineEdit* nome = new QLineEdit();
        QDoubleSpinBox *prezzo = new QDoubleSpinBox();
        QDateEdit *data = new QDateEdit();
        QComboBox* tipo = new QComboBox();*/

        submitButton = new QPushButton(tr("Invia"));
        submitButton->setDefault(true);
        revertButton = new QPushButton(tr("Rimuovi"));
        quitButton = new QPushButton(tr("Annulla"));

        buttonBox = new QDialogButtonBox(Qt::Horizontal);
        buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

        Nome = new QLineEdit();
        QLabel *NomeLabel = new QLabel("Nome prodotto: ");
        Nome->setPlaceholderText("Nome");
        Nome->setToolTip("Inserisci il Nome");
        data = new QLineEdit();
        QLabel *DataLabel = new QLabel("Data: ");
        data->setPlaceholderText("Data");
        data->setToolTip("Inserisci la data");
        prezzo = new QDoubleSpinBox();
        QLabel *PrezzoLabel = new QLabel("Prezzo: ");
        tipo = new QComboBox();
        QLabel *TipoLabel = new QLabel("Tipo prodotto: ");
        tipo->insertItem(1,"Nuovo");
        tipo->insertItem(2,"Usato");
        tipo->insertItem(3,"Ricondizionato");

        QGridLayout *FieldLayout = new QGridLayout;
        FieldLayout->addWidget(NomeLabel, 0, 0);
        FieldLayout->addWidget(Nome, 0, 1);
        FieldLayout->addWidget(DataLabel,1,0);
        FieldLayout->addWidget(data,1,1);
        FieldLayout->addWidget(PrezzoLabel,2,0);
        FieldLayout->addWidget(prezzo,2,1);
        FieldLayout->addWidget(TipoLabel,3,0);
        FieldLayout->addWidget(tipo,3,1);

        QTableWidgetItem *item;
        for(int i=0; i<table->rowCount(); i++) {

            for(int j=0; j<table->columnCount(); j++) {
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

                table->setItem(i,j,item);
            }
        }

        //this->setCentralWidget(table);
        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(table);
        mainLayout->addLayout(FieldLayout);
        mainLayout->addWidget(buttonBox);

        setLayout(mainLayout);

}
