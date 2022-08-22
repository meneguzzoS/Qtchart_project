#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *pieChart = new QPushButton(tr("Pie Chart"), this);


    QPushButton *open = new QPushButton(tr("Apri tabella"),this);


    //setLayout(layout);
    //setCentralWidget(wdg);


    //pieChart->setText("PieChart");
    //layout->addWidget(pieChart);
    //setCentralWidget(wdg);

    connect(open,SIGNAL(clicked(bool)),this,SLOT(showTable()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::showTable()
{
    window = new table;
    window->show();
}

