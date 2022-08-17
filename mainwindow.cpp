#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *open = new QPushButton(tr("Apri tabella"));

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(open);
    setCentralWidget(open);

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

