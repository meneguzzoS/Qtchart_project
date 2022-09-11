#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "listadati.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include "table.h"
#include "QDebug"

class fileHandler : QObject
{
Q_OBJECT
private:
    table* vista;
public:
    fileHandler(table*,QObject* = nullptr);
public slots:
    void readFile();
    void saveFile();
};

#endif // FILEHANDLER_H
