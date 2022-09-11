#include "filehandler.h"
#include "table.h"

fileHandler::fileHandler(table* t, QObject* parent) : vista(t), QObject(parent)
{
    connect(vista,SIGNAL(openFile()),this,SLOT(readFile()));
    connect(vista,SIGNAL(exportFile()),this,SLOT(saveFile()));
}

void fileHandler::readFile()
{
    QString filename = QFileDialog::getOpenFileName(vista, "Apri il tuo file", QDir::homePath(), "CSV File (*.csv)");
    qDebug()<<filename;
    if(filename=="") {
        vista->showWarning(vista,"Errore file","Nessun file selezionato");
    }
    else {
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
            vista->importData(data);
        }
    }
}

void fileHandler::saveFile()
{

    // Creazione oggetto "destinazione"
    QString filename = QFileDialog::getSaveFileName(vista, "Seleziona il tuo file di destinazione", QDir::homePath(), "CSV File (*.csv)");
    if(filename=="") {
        vista->showWarning(vista,"Errore file","Nessun file selezionato");
    }
    else {
        int lastPoint = filename.lastIndexOf(".");
        QString fileNameNoExt = filename.left(lastPoint);
        fileNameNoExt.append(".csv");

        QFile targetFile(fileNameNoExt);

        // Apertura file in scrittura
        if(!targetFile.open(QFile::WriteOnly | QFile::Text)) {
            qDebug() << "File impossibile da aprire";
            return;
        }

        // Creazione stream di dati VERSO il file
        QTextStream out(&targetFile);
        QStringList strList;

        for(int r=0; r< vista->getTable()->rowCount(); r++) {
            strList.clear();
            for(int c=0;c<vista->getTable()->columnCount(); c++) {
                vista->getTable()->setCurrentCell(r,c);
                strList << vista->getTable()->currentItem()->text();
            }
            out << strList.join(",")+"\n";
        }

        targetFile.flush();
        targetFile.close();
    }
}
