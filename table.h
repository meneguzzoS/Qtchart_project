#ifndef TABLE_H
#define TABLE_H

#include <QDialogButtonBox>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>

class table : public QWidget
{
    Q_OBJECT
public:
    table();
private:
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QLineEdit* Nome;
    QDoubleSpinBox* prezzo;
    QLineEdit* data;
    QComboBox* tipo;
};

#endif // TABLE_H
