#ifndef NEWCHART_H
#define NEWCHART_H

#include <QDialog>
#include <QRadioButton>
#include <QPushButton>
#include <QSpinBox>
#include "piechartdataset.h"
#include "piechartview.h"
#include "barchartdataset.h"
#include "barchartview.h"
#include "listadati.h"
#include "linechartdataset.h"
#include "linechartview.h"
#include <QLabel>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include "chartcontroller.h"

class newChart : public QDialog
{
Q_OBJECT
public:
    newChart(listaDati* = nullptr, QWidget* = nullptr);
    int getFirstDate();
    int getSecondDate();
    void showWarning(QWidget*,const QString&,const QString&);
private:
    listaDati *list;
    QList<int>* year;
    QSpinBox *firstdate;
    QSpinBox *secondDate;
     QPushButton* ok;
     QPushButton* annulla;
     QRadioButton* piechart;
     QRadioButton* linechart;
     QRadioButton* barchart;
signals:
     void bar();
     void line();
     void pie();
public slots:
     void lineChecked();
     void pieChecked();
     void barChecked();
     void createChart();
};

#endif // NEWCHART_H
