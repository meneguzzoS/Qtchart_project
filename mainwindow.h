#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QMenu>
#include <QString>
#include <QCloseEvent>
#include <QAction>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include "listacontroller.h"

class MainWindow : public QMainWindow
{
Q_OBJECT
private:
    QString fileopen;           //il nome del file attualmeno aperto, se ce ne è uno.                  //il widget principale della mainwindow
    QAction *NewAction;
    QAction *OpenAction;
    QAction* SaveAction;
    QAction* SaveAsaction;
    QAction* CloseAction;
    QAction* QuitAction;
    QAction* barchart;
    QAction* linechart;
    QAction* pointchart;
    QAction* aggiungi;
    QAction* remove;
    QAction* inserimento;
    QMenu* FileMenu;
    QMenu* VisualizzaMenu;
    QMenu* ModificaMenu;
    QToolBar* File;
    QToolBar* Chart;
    QToolBar* Modifica;
    listaController* dataController;
public:
     MainWindow(QWidget *parent = 0);
};

#endif // MAINWINDOW_H
