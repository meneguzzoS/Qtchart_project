#include "filehandler.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

void fileHandler::readFile(const listaController& dataController)
{
//    QString filename = QFileDialog::getOpenFileName(/*this,*/ "Apri il tuo file", QDir::homePath(), "CSV File (*.csv)");
//        qDebug()<<filename;

//        QFile targetFile(filename);

//        if(!targetFile.open(QFile::ReadOnly | QFile::Text)) {
//            qDebug() << "Impossibile leggere il file";
//            return;
//        }

//    QTextStream in(&targetFile);

//    while(!in.atEnd()) {
//        QString line = in.readLine(); // \n
//        line = line.simplified();
//        line.replace(" ",""); //rimuove gli spazi bianchi
//        QStringList data = line.split(',');

//        //inserisco elementi appena presi dal file nella lista
//        record nuovo;
//        nuovo.setName(data.at(0));
//        nuovo.setPIL(QString(data.at(1)).toInt());
//        nuovo.setData(QDate::fromString(QString(data.at(2)), "dd.MM.yyyy"));
//        if(data.at(3)=="Europa")
//            nuovo.setContinente(0);
//        if(data.at(3)=="Asia")
//            nuovo.setContinente(1);
//        if(data.at(3)=="America")
//            nuovo.setContinente(2);
//        if(data.at(3)=="Africa")
//            nuovo.setContinente(3);
//        if(data.at(3)=="Oceania")
//            nuovo.setContinente(4);
//        dataController.addToList(nuovo);
//    }
//    for(int i=0; i<dataController.listaSize();i++) {
//        qDebug() << dataController.getList()->at(i).getName() << dataController.getList()->at(i).getPIL() << dataController.getList()->at(i).getData() << dataController.getList()->at(i).getContinente();
//    }
}
