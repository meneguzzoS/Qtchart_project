#include "filehandler.h"
#include "table.h"

fileHandler::fileHandler(table* t, QObject* parent) : tabella(t), QObject(parent)
{
    connect(tabella,SIGNAL(openFile()),this,SLOT(readFile()));
    connect(tabella,SIGNAL(exportFile()),this,SLOT(saveFile()));

}

void fileHandler::readFile()
{
    QString filename = QFileDialog::getOpenFileName(tabella, "Apri il tuo file", QDir::homePath(), "CSV File (*.csv)");
    qDebug()<<filename;

    QFile targetFile(filename);

    if(!targetFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Impossibile leggere il file";
        return;
    }

    QTextStream in(&targetFile);

    while(!in.atEnd()) {
        QString line = in.readLine(); // \n
        line = line.simplified();
        line.replace(" ",""); //rimuove gli spazi bianchi
        QStringList data = line.split(',');
        tabella->importData(data);
    }
}

void fileHandler::saveFile()
{

    // Creazione oggetto "destinazione"
    QString filename = QFileDialog::getOpenFileName(tabella, "Seleziona il tuo file di destinazione", QDir::homePath(), "CSV File (*.csv)");
    QFile targetFile(filename);

    // Apertura file in scrittura
    if(!targetFile.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "File impossibile da aprire";
        return;
    }

    // Creazione stream di dati VERSO il file
    QTextStream out(&targetFile);
    QStringList strList;

    for(int r=0; r< tabella->getTable()->rowCount(); r++) {
        strList.clear();
        for(int c=0;c<tabella->getTable()->columnCount(); c++) {
            tabella->getTable()->setCurrentCell(r,c);
            strList << tabella->getTable()->currentItem()->text();
        }
        out << strList.join(",")+"\n";
    }

    targetFile.flush();
    targetFile.close();

}
