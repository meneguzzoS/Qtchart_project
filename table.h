#ifndef TABLE_H
#define TABLE_H

#include <QDialogButtonBox>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include "record.h"
#include <QList>
#include <QTableWidget>
#include <QDateEdit>
#include "listacontroller.h"
#include "newchart.h"

class table : public QWidget
{
    Q_OBJECT
public:
    table(listaController*);
private:
    QList<record> lista;
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
signals:
    void closeWindow();
public slots:
    void deleteLastRow();
    void addRow();
    void importData();
    void exportFile();
    void SelectChart();
};

#endif // TABLE_H
