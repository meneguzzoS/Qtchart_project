#ifndef TABLE_H
#define TABLE_H

#include "listadati.h"
#include <QDialogButtonBox>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QDateEdit>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QtWidgets>
#include <QFileDialog>
#include <QDir>

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
    void showWarning(QWidget*,const QString&,const QString&);
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
    listaDati *datalist;
signals:
    void openFile();
    void createTable();
    void exportFile();
    void deleteLastRow();
    void submitPressed();
    void fileTable(QStringList);
    void setValue();
    void charts();
public slots:
    void addRow(QString,double,QDate,MacroArea);
    void importData(const QStringList&);
};

#endif // TABLE_H
