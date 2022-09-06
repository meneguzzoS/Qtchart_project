#ifndef TABLE_H
#define TABLE_H

#include "newchart.h"
#include "listacontroller.h"
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

class fileHandler;

class table : public QWidget
{
    Q_OBJECT
public:
    table(listaController*);
    QTableWidget* getTable();
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
    listaController *dataController;
    fileHandler* file;
signals:
    void closeWindow();
    void openFile();
    void createTable();
    void exportFile();
public slots:
    void deleteLastRow();
    void addRow();
    void SelectChart();
    void importData(const QStringList&);
};

#endif // TABLE_H
