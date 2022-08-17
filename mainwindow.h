#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "table.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    table *window;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void showTable();
};

#endif // MAINWINDOW_H
