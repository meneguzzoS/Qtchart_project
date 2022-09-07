#include "table.h"
#include "listacontroller.h"
#include "listadati.h"

table::table(listaDati* LC) : dataController(LC)
{
        setWindowTitle("Tabella prodotti");
//        dataController = new listaController(&lista);

        //creazione tabella
        tabella = new QTableWidget;
        tabella->setColumnCount(4);
        tabella->setRowCount(dataController->listaSize());
        tabella->setMinimumSize(550,500);
        tabella->horizontalHeader()->setStretchLastSection(true);
//        tabella->verticalHeader()->setStretchLastSection(true);

        QStringList header;
        header<<"Nome Stato"<<"PIL (mld)"<<"Data"<<"Continente";
        tabella->setHorizontalHeaderLabels(header);

        //riempire tabella con record in lista
        QTableWidgetItem *item;
        for(int i=0; i<tabella->rowCount(); i++) {
            for(int j=0; j<tabella->columnCount(); j++) {
                item = new QTableWidgetItem;
                switch(j) {
                case 0: item->setText(QString(dataController->getName(i)));
                    break;
                case 1: item->setText(QString::number(dataController->getPIL(i)));
                    break;
                case 2: item->setText(QString(dataController->getData(i).toString("dd.MM.yyyy")));
                    break;
                case 3: switch(dataController->getContinente(i)) { //OTTIMIZZARE
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
        PIL->setRange(0, 1000000);
        PIL->setSuffix("  mld €");
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
        selectButton = new QPushButton(tr("Genere grafico"));

        buttonBox = new QDialogButtonBox(Qt::Horizontal);
        buttonBox->addButton(loadButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(printFileButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(removeButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);
        buttonBox->addButton(selectButton, QDialogButtonBox::ActionRole);

        //sistemazione layout
        QVBoxLayout *tab1 = new QVBoxLayout;
        tab1->addWidget(tabella);
        QVBoxLayout *tab2 = new QVBoxLayout;
        tab2->addLayout(FieldLayout);
        tab2->addWidget(buttonBox);

        QHBoxLayout *mainLayout = new QHBoxLayout;
        mainLayout->addLayout(tab1);
        mainLayout->addLayout(tab2);
        setLayout(mainLayout);
        tab2->setAlignment(FieldLayout,Qt::AlignTop);
        tab2->setSpacing(30);

        file = new fileHandler(this);
        controller = new listacontroller(dataController,this);

        connect(quitButton,&QPushButton::clicked,this,[this](){emit closeWindow();});
        connect(removeButton,&QPushButton::clicked,controller,[this](){emit deleteLastRow();});
        connect(submitButton,&QPushButton::clicked,controller,[this](){emit submitPressed();});
//        connect(removeButton,SIGNAL(clicked(bool)),this,SLOT(deleteLastRow()));
//        connect(submitButton,SIGNAL(clicked(bool)),this,SLOT(addRow()));
        connect(loadButton,&QPushButton::clicked,this,[this](){emit openFile();});
//        connect(printFileButton,SIGNAL(clicked(bool)),this,SLOT(exportFile()));
        connect(selectButton,SIGNAL(clicked(bool)),this,SLOT(SelectChart()));
        connect(printFileButton,&QPushButton::clicked,this,[this](){emit exportFile();});
        connect(tabella,&QTableWidget::cellChanged,this,[this](){emit setValue();});
        //        connect(parent,SIGNAL(openF()),this,[this](){emit openFile();});
}

QTableWidget *table::getTable()
{
    return tabella;
}

QString table::getName()
{
    return Nome->text();
}

double table::getPil()
{
    return PIL->value();
}

QDate table::getDate()
{
    return data->date();
}

int table::getContinent()
{
    return continente->currentIndex();
}

void table::addRow(QString nome,double pil,QDate data,MacroArea continente)
{
    int row = tabella->rowCount();
    tabella->insertRow(row);
    tabella->setItem(row, 0, new QTableWidgetItem(nome));
    tabella->setItem(row, 1, new QTableWidgetItem(QString::number(pil)));
    tabella->setItem(row, 2, new QTableWidgetItem(data.toString("dd.MM.yyyy")));
    switch(continente) {
    case Europa: tabella->setItem(row, 3, new QTableWidgetItem("Europa")); break;
    case Asia: tabella->setItem(row, 3, new QTableWidgetItem("Asia")); break;
    case America: tabella->setItem(row, 3, new QTableWidgetItem("America")); break;
    case Africa: tabella->setItem(row, 3, new QTableWidgetItem("Africa")); break;
    case Oceania: tabella->setItem(row, 3, new QTableWidgetItem("Oceania")); break;
    }
    tabella->setCurrentCell(row,3);
}

void table::importData(const QStringList& data)
{
    int row;
    row = tabella->rowCount();
    tabella->insertRow(row);
    tabella->setItem(row, 0, new QTableWidgetItem(data.at(0)));
    tabella->setItem(row, 1, new QTableWidgetItem(data.at(1)));
    tabella->setItem(row, 2, new QTableWidgetItem(data.at(2)));
    tabella->setItem(row, 3, new QTableWidgetItem(data.at(3)));
    tabella->setCurrentCell(row,3);

    //inserisco elementi appena presi dal file nella lista
    emit fileTable(data);

//    for(int i=0; i<dataController->listaSize();i++) {
//        qDebug() << dataController->getList()->at(i).getName() << dataController->getList()->at(i).getPIL() << dataController->getList()->at(i).getData() << dataController->getList()->at(i).getContinente();
//    }
}

void table::SelectChart()
{
//    while(!dataController->isListaEmpty()){
//        dataController->getList()->pop_back();
//    }
//    for(int r=0; r< tabella->rowCount(); r++) {
//        record nuovo;
//            for(int c=0;c<tabella->columnCount(); c++) {
//                tabella->setCurrentCell(r,c);
//                switch(c) {
//                case 0: nuovo.setName(tabella->currentItem()->text());
//                    break;
//                case 1: nuovo.setPIL(QString(tabella->currentItem()->text()).toInt());
//                    break;
//                case 2: nuovo.setData(QDate::fromString(QString(tabella->currentItem()->text()), "dd.MM.yyyy"));
//                    break;
//                case 3: if(tabella->currentItem()->text()=="Europa")
//                            nuovo.setContinente(0);
//                        if(tabella->currentItem()->text()=="Asia")
//                            nuovo.setContinente(1);
//                        if(tabella->currentItem()->text()=="America")
//                            nuovo.setContinente(2);
//                        if(tabella->currentItem()->text()=="Africa")
//                            nuovo.setContinente(3);
//                        if(tabella->currentItem()->text()=="Oceania")
//                            nuovo.setContinente(4);
//                    break;
//                }
//                tabella->setCurrentCell(r,c);
//            }
//            dataController->addToList(nuovo);
//            //qDebug() << nuovo.getName() << nuovo.getPIL() << nuovo.getData() << nuovo.getContinente();
//        }
//    for(QList<record>::const_iterator a = dataController->getList()->begin(); a != dataController->getList()->end(); a++)
//        qDebug() << "selectChart" <<(*a).getName() << (*a).getPIL() << (*a).getData() << (*a).getContinente();


//    newChart *select = new newChart(dataController);
//    select->show();
}
