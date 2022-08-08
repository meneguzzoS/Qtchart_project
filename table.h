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
    QDialogButtonBox *buttonBox;
    QLineEdit* Nome;
    QDoubleSpinBox* prezzo;
    QLineEdit* data;
    QComboBox* tipo;
public slots:
    void deleteLastRow();
    void addRow();
};

#endif // TABLE_H
