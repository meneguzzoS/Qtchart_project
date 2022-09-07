#ifndef TABLE_H
#define TABLE_H

#include "newchart.h"
#include "listadati.h"
#include <QDialogButtonBox>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QDateEdit>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QtWidgets>
#include <QFileDialog>
#include <QDir>
#include "filehandler.h"
//#include "listacontroller.h"

class listacontroller;

class table : public QWidget
{
    Q_OBJECT
public:
    table(listaDati*);
    QTableWidget* getTable();
    QString getName();
    double getPil();
    QDate getDate();
    int getContinent();
private:
    QTableWidget *tabella;
    QPushButton *submitButton;
    QPushButton *removeButton;
    QPushButton *quitButton;
    QPushButton *loadButton;
    QPushButton *printFileButton;
    QPushButton *selectButton;
    QDialogButtonBox *buttonBox;
    QLineEdit* Nome;
    QDoubleSpinBox* PIL;
    QDateEdit* data;
    QComboBox* continente;
    listaDati *dataController;
    listacontroller* controller;
    fileHandler* file;
signals:
    void closeWindow();
    void openFile();
    void createTable();
    void exportFile();
    void deleteLastRow();
    void submitPressed();
    void fileTable(QStringList);
    void setValue();
public slots:
    void addRow(QString,double,QDate,MacroArea);
    void SelectChart();
    void importData(const QStringList&);
};

#endif // TABLE_H
