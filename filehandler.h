#ifndef FILEHANDLER_H
#define FILEHANDLER_H

//#include"record.h"
#include "listacontroller.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include "table.h"

class table;

class fileHandler : QObject
{
Q_OBJECT
private:
    table* tabella;
public:
    fileHandler(table*);
public slots:
    void readFile();
    void saveFile();
};

#endif // FILEHANDLER_H
