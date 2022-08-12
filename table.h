#ifndef TABLE_H
#define TABLE_H

#include <QDialogButtonBox>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include "record.h"
#include "listacontroller.h"
#include <QList>
#include <QTableWidget>
#include <QDateEdit>

class table : public QWidget
{
    Q_OBJECT
public:
    table();
private:
    QList<record> lista;
    QTableWidget *tabella;
    QPushButton *submitButton;
    QPushButton *removeButton;
    QPushButton *quitButton;
    QPushButton *loadButton;
    QPushButton *printFileButton;
    QDialogButtonBox *buttonBox;
    QLineEdit* Nome;
    QDoubleSpinBox* prezzo;
    QDateEdit* data;
    QComboBox* tipo;
    ListaController *dataController;
public slots:
    void deleteLastRow();
    void addRow();
    void importData();
    void exportFile();
};

#endif // TABLE_H
